/// \file InvokeIsolatedFunctions.cpp
/// \brief

//
// This file is distributed under the MIT License. See LICENSE.md for details.
//

#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

#include "revng/FunctionIsolation/InvokeIsolatedFunctions.h"

using namespace llvm;

using std::tuple;

char InvokeIsolatedFunctionsPass::ID = 0;
using Register = RegisterPass<InvokeIsolatedFunctionsPass>;
static Register
  X("invoke-isolated-functions", "Invoke Isolated Functions Pass", true, true);

class InvokeIsolatedFunctions {
private:
  using FunctionInfo = tuple<const model::Function *, BasicBlock *, Function *>;
  using FunctionMap = std::map<MetaAddress, FunctionInfo>;

private:
  Function *RootFunction;
  Module *M;
  LLVMContext &Context;
  GeneratedCodeBasicInfo &GCBI;
  FunctionMap Map;

public:
  InvokeIsolatedFunctions(const model::Binary &Binary,
                          Function *RootFunction,
                          GeneratedCodeBasicInfo &GCBI) :
    RootFunction(RootFunction),
    M(RootFunction->getParent()),
    Context(M->getContext()),
    GCBI(GCBI) {

    for (const model::Function &Function : Binary.Functions) {
      if (Function.Type == model::FunctionType::Fake)
        continue;

      // TODO: this temporary
      Map[Function.Entry] = { &Function,
                              nullptr,
                              M->getFunction(Function.name()) };
    }

    for (BasicBlock &BB : *RootFunction) {
      revng_assert(not BB.empty());

      MetaAddress JumpTarget = getBasicBlockJumpTarget(&BB);
      auto It = Map.find(JumpTarget);
      if (It != Map.end()) {
        get<1>(It->second) = &BB;
      }
    }
  }

  /// Create the basic blocks that are hit on exit after an invoke instruction
  BasicBlock *createInvokeReturnBlock() {
    // Create the first block
    BasicBlock *InvokeReturnBlock = BasicBlock::Create(Context,
                                                       "invoke_return",
                                                       RootFunction,
                                                       nullptr);

    BranchInst::Create(GCBI.dispatcher(), InvokeReturnBlock);

    return InvokeReturnBlock;
  }

  /// Create the basic blocks that represent the catch of the invoke instruction
  BasicBlock *createCatchBlock(BasicBlock *UnexpectedPC) {
    // Create a basic block that represents the catch part of the exception
    BasicBlock *CatchBB = BasicBlock::Create(Context,
                                             "catchblock",
                                             RootFunction,
                                             nullptr);

    // Create a builder object
    IRBuilder<> Builder(Context);
    Builder.SetInsertPoint(CatchBB);

    // Create the StructType necessary for the landingpad
    PointerType *RetTyPointerType = Type::getInt8PtrTy(Context);
    IntegerType *RetTyIntegerType = Type::getInt32Ty(Context);
    std::vector<Type *> InArgsType{ RetTyPointerType, RetTyIntegerType };
    StructType *RetTyStruct = StructType::create(Context,
                                                 ArrayRef<Type *>(InArgsType),
                                                 "",
                                                 false);

    // Create the landingpad instruction
    LandingPadInst *LandingPad = Builder.CreateLandingPad(RetTyStruct, 0);

    // Add a catch all (constructed with the null value as clause)
    auto *NullPtr = ConstantPointerNull::get(Type::getInt8PtrTy(Context));
    LandingPad->addClause(NullPtr);

    Builder.CreateBr(UnexpectedPC);

    return CatchBB;
  }

  void run() {
    // Get the unexpectedpc block of the root function
    BasicBlock *UnexpectedPC = GCBI.unexpectedPC();

    // Instantiate the basic block structure that handles the control flow after
    // an invoke
    BasicBlock *InvokeReturnBlock = createInvokeReturnBlock();

    // Instantiate the basic block structure that represents the catch of the
    // invoke, please remember that this is not used at the moment (exceptions
    // are handled in a customary way from the standard exit control flow path)
    BasicBlock *CatchBB = createCatchBlock(UnexpectedPC);

    // Declaration of an ad-hoc personality function that is implemented in the
    // support.c source file
    auto *PersonalityFT = FunctionType::get(Type::getInt32Ty(Context), true);

    Function *PersonalityFunction = Function::Create(PersonalityFT,
                                                     Function::ExternalLinkage,
                                                     "__gxx_personality_v0",
                                                     M);

    // Add the personality to the root function
    RootFunction->setPersonalityFn(PersonalityFunction);

    for (auto [_, T] : Map) {
      auto [ModelFunction, BB, F] = T;

      // Create a new trampoline entry block and substitute it to the old entry
      // block
      BasicBlock *NewBB = BasicBlock::Create(Context, "", BB->getParent(), BB);
      BB->replaceAllUsesWith(NewBB);
      NewBB->takeName(BB);

      IRBuilder<> Builder(NewBB);

      // In case the isolated functions has arguments, provide them
      SmallVector<Value *, 4> Arguments;
      if (F->getFunctionType()->getNumParams() > 0) {
        using model::RawFunctionType;
        auto PrototypePath = ModelFunction->Prototype;
        const auto &Prototype = *cast<RawFunctionType>(PrototypePath.get());
        for (const model::NamedTypedRegister &TR : Prototype.Arguments) {
          auto Name = ABIRegister::toCSVName(TR.Location);
          GlobalVariable *CSV = M->getGlobalVariable(Name, true);
          revng_assert(CSV != nullptr);
          Arguments.push_back(Builder.CreateLoad(CSV));
        }
      }

      // Emit the invoke instruction, propagating debug info
      auto *NewInvoke = Builder.CreateInvoke(F,
                                             InvokeReturnBlock,
                                             CatchBB,
                                             Arguments);
      NewInvoke->setDebugLoc(BB->front().getDebugLoc());
    }

    // Remove all the orphan basic blocks from the root function (e.g., the
    // blocks that have been substitued by the trampoline)
    EliminateUnreachableBlocks(*RootFunction, nullptr, false);
  }
};

bool InvokeIsolatedFunctionsPass::runOnModule(Module &M) {
  auto &GCBI = getAnalysis<GeneratedCodeBasicInfoWrapperPass>().getGCBI();
  const auto &ModelWrapper = getAnalysis<LoadModelWrapperPass>().get();
  const model::Binary &Binary = ModelWrapper.getReadOnlyModel();
  InvokeIsolatedFunctions IIF(Binary, M.getFunction("root"), GCBI);
  IIF.run();
  return true;
}
