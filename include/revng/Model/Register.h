#pragma once

//
// This file is distributed under the MIT License. See LICENSE.md for details.
//

#include "llvm/ADT/Triple.h"

#include "revng/ADT/KeyedObjectTraits.h"
#include "revng/Support/Assert.h"
#include "revng/Support/YAMLTraits.h"

namespace model::Register {
enum Values {
  Invalid,
  // x86 registers
  eax_x86,
  ebx_x86,
  ecx_x86,
  edx_x86,
  esi_x86,
  edi_x86,
  ebp_x86,
  esp_x86,
  // x86-64 registers
  rax_x86_64,
  rbx_x86_64,
  rcx_x86_64,
  rdx_x86_64,
  rbp_x86_64,
  rsp_x86_64,
  rsi_x86_64,
  rdi_x86_64,
  r8_x86_64,
  r9_x86_64,
  r10_x86_64,
  r11_x86_64,
  r12_x86_64,
  r13_x86_64,
  r14_x86_64,
  r15_x86_64,
  xmm0_x86_64,
  xmm1_x86_64,
  xmm2_x86_64,
  xmm3_x86_64,
  xmm4_x86_64,
  xmm5_x86_64,
  xmm6_x86_64,
  xmm7_x86_64,
  // ARM registers
  r0_arm,
  r1_arm,
  r2_arm,
  r3_arm,
  r4_arm,
  r5_arm,
  r6_arm,
  r7_arm,
  r8_arm,
  r9_arm,
  r10_arm,
  r11_arm,
  r12_arm,
  r13_arm,
  r14_arm,
  // AArch64 registers
  x0_aarch64,
  x1_aarch64,
  x2_aarch64,
  x3_aarch64,
  x4_aarch64,
  x5_aarch64,
  x6_aarch64,
  x7_aarch64,
  x8_aarch64,
  x9_aarch64,
  x10_aarch64,
  x11_aarch64,
  x12_aarch64,
  x13_aarch64,
  x14_aarch64,
  x15_aarch64,
  x16_aarch64,
  x17_aarch64,
  x18_aarch64,
  x19_aarch64,
  x20_aarch64,
  x21_aarch64,
  x22_aarch64,
  x23_aarch64,
  x24_aarch64,
  x25_aarch64,
  x26_aarch64,
  x27_aarch64,
  x28_aarch64,
  x29_aarch64,
  lr_aarch64,
  sp_aarch64,
  // MIPS registers
  v0_mips,
  v1_mips,
  a0_mips,
  a1_mips,
  a2_mips,
  a3_mips,
  s0_mips,
  s1_mips,
  s2_mips,
  s3_mips,
  s4_mips,
  s5_mips,
  s6_mips,
  s7_mips,
  gp_mips,
  sp_mips,
  fp_mips,
  ra_mips,
  // SystemZ registers
  r0_systemz,
  r1_systemz,
  r2_systemz,
  r3_systemz,
  r4_systemz,
  r5_systemz,
  r6_systemz,
  r7_systemz,
  r8_systemz,
  r9_systemz,
  r10_systemz,
  r11_systemz,
  r12_systemz,
  r13_systemz,
  r14_systemz,
  r15_systemz,
  f0_systemz,
  f1_systemz,
  f2_systemz,
  f3_systemz,
  f4_systemz,
  f5_systemz,
  f6_systemz,
  f7_systemz,
  f8_systemz,
  f9_systemz,
  f10_systemz,
  f11_systemz,
  f12_systemz,
  f13_systemz,
  f14_systemz,
  f15_systemz
};
} // end namespace model::Register

namespace llvm::yaml {
template<>
struct ScalarEnumerationTraits<model::Register::Values> {
  template<typename T>
  static void enumeration(T &io, model::Register::Values &V) {
    using namespace model::Register;
    io.enumCase(V, "Invalid", Invalid);
    io.enumCase(V, "eax_x86", eax_x86);
    io.enumCase(V, "ebx_x86", ebx_x86);
    io.enumCase(V, "ecx_x86", ecx_x86);
    io.enumCase(V, "edx_x86", edx_x86);
    io.enumCase(V, "esi_x86", esi_x86);
    io.enumCase(V, "edi_x86", edi_x86);
    io.enumCase(V, "ebp_x86", ebp_x86);
    io.enumCase(V, "esp_x86", esp_x86);
    io.enumCase(V, "rax_x86_64", rax_x86_64);
    io.enumCase(V, "rbx_x86_64", rbx_x86_64);
    io.enumCase(V, "rcx_x86_64", rcx_x86_64);
    io.enumCase(V, "rdx_x86_64", rdx_x86_64);
    io.enumCase(V, "rbp_x86_64", rbp_x86_64);
    io.enumCase(V, "rsp_x86_64", rsp_x86_64);
    io.enumCase(V, "rsi_x86_64", rsi_x86_64);
    io.enumCase(V, "rdi_x86_64", rdi_x86_64);
    io.enumCase(V, "r8_x86_64", r8_x86_64);
    io.enumCase(V, "r9_x86_64", r9_x86_64);
    io.enumCase(V, "r10_x86_64", r10_x86_64);
    io.enumCase(V, "r11_x86_64", r11_x86_64);
    io.enumCase(V, "r12_x86_64", r12_x86_64);
    io.enumCase(V, "r13_x86_64", r13_x86_64);
    io.enumCase(V, "r14_x86_64", r14_x86_64);
    io.enumCase(V, "r15_x86_64", r15_x86_64);
    io.enumCase(V, "xmm0_x86_64", xmm0_x86_64);
    io.enumCase(V, "xmm1_x86_64", xmm1_x86_64);
    io.enumCase(V, "xmm2_x86_64", xmm2_x86_64);
    io.enumCase(V, "xmm3_x86_64", xmm3_x86_64);
    io.enumCase(V, "xmm4_x86_64", xmm4_x86_64);
    io.enumCase(V, "xmm5_x86_64", xmm5_x86_64);
    io.enumCase(V, "xmm6_x86_64", xmm6_x86_64);
    io.enumCase(V, "xmm7_x86_64", xmm7_x86_64);
    io.enumCase(V, "r0_arm", r0_arm);
    io.enumCase(V, "r1_arm", r1_arm);
    io.enumCase(V, "r2_arm", r2_arm);
    io.enumCase(V, "r3_arm", r3_arm);
    io.enumCase(V, "r4_arm", r4_arm);
    io.enumCase(V, "r5_arm", r5_arm);
    io.enumCase(V, "r6_arm", r6_arm);
    io.enumCase(V, "r7_arm", r7_arm);
    io.enumCase(V, "r8_arm", r8_arm);
    io.enumCase(V, "r9_arm", r9_arm);
    io.enumCase(V, "r10_arm", r10_arm);
    io.enumCase(V, "r11_arm", r11_arm);
    io.enumCase(V, "r12_arm", r12_arm);
    io.enumCase(V, "r13_arm", r13_arm);
    io.enumCase(V, "r14_arm", r14_arm);
    io.enumCase(V, "x0_aarch64", x0_aarch64);
    io.enumCase(V, "x1_aarch64", x1_aarch64);
    io.enumCase(V, "x2_aarch64", x2_aarch64);
    io.enumCase(V, "x3_aarch64", x3_aarch64);
    io.enumCase(V, "x4_aarch64", x4_aarch64);
    io.enumCase(V, "x5_aarch64", x5_aarch64);
    io.enumCase(V, "x6_aarch64", x6_aarch64);
    io.enumCase(V, "x7_aarch64", x7_aarch64);
    io.enumCase(V, "x8_aarch64", x8_aarch64);
    io.enumCase(V, "x9_aarch64", x9_aarch64);
    io.enumCase(V, "x10_aarch64", x10_aarch64);
    io.enumCase(V, "x11_aarch64", x11_aarch64);
    io.enumCase(V, "x12_aarch64", x12_aarch64);
    io.enumCase(V, "x13_aarch64", x13_aarch64);
    io.enumCase(V, "x14_aarch64", x14_aarch64);
    io.enumCase(V, "x15_aarch64", x15_aarch64);
    io.enumCase(V, "x16_aarch64", x16_aarch64);
    io.enumCase(V, "x17_aarch64", x17_aarch64);
    io.enumCase(V, "x18_aarch64", x18_aarch64);
    io.enumCase(V, "x19_aarch64", x19_aarch64);
    io.enumCase(V, "x20_aarch64", x20_aarch64);
    io.enumCase(V, "x21_aarch64", x21_aarch64);
    io.enumCase(V, "x22_aarch64", x22_aarch64);
    io.enumCase(V, "x23_aarch64", x23_aarch64);
    io.enumCase(V, "x24_aarch64", x24_aarch64);
    io.enumCase(V, "x25_aarch64", x25_aarch64);
    io.enumCase(V, "x26_aarch64", x26_aarch64);
    io.enumCase(V, "x27_aarch64", x27_aarch64);
    io.enumCase(V, "x28_aarch64", x28_aarch64);
    io.enumCase(V, "x29_aarch64", x29_aarch64);
    io.enumCase(V, "lr_aarch64", lr_aarch64);
    io.enumCase(V, "sp_aarch64", sp_aarch64);
    io.enumCase(V, "v0_mips", v0_mips);
    io.enumCase(V, "v1_mips", v1_mips);
    io.enumCase(V, "a0_mips", a0_mips);
    io.enumCase(V, "a1_mips", a1_mips);
    io.enumCase(V, "a2_mips", a2_mips);
    io.enumCase(V, "a3_mips", a3_mips);
    io.enumCase(V, "s0_mips", s0_mips);
    io.enumCase(V, "s1_mips", s1_mips);
    io.enumCase(V, "s2_mips", s2_mips);
    io.enumCase(V, "s3_mips", s3_mips);
    io.enumCase(V, "s4_mips", s4_mips);
    io.enumCase(V, "s5_mips", s5_mips);
    io.enumCase(V, "s6_mips", s6_mips);
    io.enumCase(V, "s7_mips", s7_mips);
    io.enumCase(V, "gp_mips", gp_mips);
    io.enumCase(V, "sp_mips", sp_mips);
    io.enumCase(V, "fp_mips", fp_mips);
    io.enumCase(V, "ra_mips", ra_mips);
    io.enumCase(V, "r0_systemz", r0_systemz);
    io.enumCase(V, "r1_systemz", r1_systemz);
    io.enumCase(V, "r2_systemz", r2_systemz);
    io.enumCase(V, "r3_systemz", r3_systemz);
    io.enumCase(V, "r4_systemz", r4_systemz);
    io.enumCase(V, "r5_systemz", r5_systemz);
    io.enumCase(V, "r6_systemz", r6_systemz);
    io.enumCase(V, "r7_systemz", r7_systemz);
    io.enumCase(V, "r8_systemz", r8_systemz);
    io.enumCase(V, "r9_systemz", r9_systemz);
    io.enumCase(V, "r10_systemz", r10_systemz);
    io.enumCase(V, "r11_systemz", r11_systemz);
    io.enumCase(V, "r12_systemz", r12_systemz);
    io.enumCase(V, "r13_systemz", r13_systemz);
    io.enumCase(V, "r14_systemz", r14_systemz);
    io.enumCase(V, "r15_systemz", r15_systemz);
    io.enumCase(V, "f0_systemz", f0_systemz);
    io.enumCase(V, "f1_systemz", f1_systemz);
    io.enumCase(V, "f2_systemz", f2_systemz);
    io.enumCase(V, "f3_systemz", f3_systemz);
    io.enumCase(V, "f4_systemz", f4_systemz);
    io.enumCase(V, "f5_systemz", f5_systemz);
    io.enumCase(V, "f6_systemz", f6_systemz);
    io.enumCase(V, "f7_systemz", f7_systemz);
    io.enumCase(V, "f8_systemz", f8_systemz);
    io.enumCase(V, "f9_systemz", f9_systemz);
    io.enumCase(V, "f10_systemz", f10_systemz);
    io.enumCase(V, "f11_systemz", f11_systemz);
    io.enumCase(V, "f12_systemz", f12_systemz);
    io.enumCase(V, "f13_systemz", f13_systemz);
    io.enumCase(V, "f14_systemz", f14_systemz);
    io.enumCase(V, "f15_systemz", f15_systemz);
  }
};
} // namespace llvm::yaml

template<>
struct KeyedObjectTraits<model::Register::Values>
  : public IdentityKeyedObjectTraits<model::Register::Values> {};

namespace model::Register {

inline llvm::StringRef getName(Values V) {
  return getNameFromYAMLEnumScalar(V);
}

inline llvm::StringRef getRegisterName(Values V) {
  llvm::StringRef FullName = getName(V);
  switch (V) {
  case Invalid:
    revng_abort();
  case eax_x86:
  case ebx_x86:
  case ecx_x86:
  case edx_x86:
  case esi_x86:
  case edi_x86:
  case ebp_x86:
  case esp_x86:
    return FullName.substr(0, FullName.size() - sizeof("_x86") + 1);
  case rax_x86_64:
  case rbx_x86_64:
  case rcx_x86_64:
  case rdx_x86_64:
  case rbp_x86_64:
  case rsp_x86_64:
  case rsi_x86_64:
  case rdi_x86_64:
  case r8_x86_64:
  case r9_x86_64:
  case r10_x86_64:
  case r11_x86_64:
  case r12_x86_64:
  case r13_x86_64:
  case r14_x86_64:
  case r15_x86_64:
  case xmm0_x86_64:
  case xmm1_x86_64:
  case xmm2_x86_64:
  case xmm3_x86_64:
  case xmm4_x86_64:
  case xmm5_x86_64:
  case xmm6_x86_64:
  case xmm7_x86_64:
    return FullName.substr(0, FullName.size() - sizeof("_x86_64") + 1);
  case r0_arm:
  case r1_arm:
  case r2_arm:
  case r3_arm:
  case r4_arm:
  case r5_arm:
  case r6_arm:
  case r7_arm:
  case r8_arm:
  case r9_arm:
  case r10_arm:
  case r11_arm:
  case r12_arm:
  case r13_arm:
  case r14_arm:
    return FullName.substr(0, FullName.size() - sizeof("_arm") + 1);
  case x0_aarch64:
  case x1_aarch64:
  case x2_aarch64:
  case x3_aarch64:
  case x4_aarch64:
  case x5_aarch64:
  case x6_aarch64:
  case x7_aarch64:
  case x8_aarch64:
  case x9_aarch64:
  case x10_aarch64:
  case x11_aarch64:
  case x12_aarch64:
  case x13_aarch64:
  case x14_aarch64:
  case x15_aarch64:
  case x16_aarch64:
  case x17_aarch64:
  case x18_aarch64:
  case x19_aarch64:
  case x20_aarch64:
  case x21_aarch64:
  case x22_aarch64:
  case x23_aarch64:
  case x24_aarch64:
  case x25_aarch64:
  case x26_aarch64:
  case x27_aarch64:
  case x28_aarch64:
  case x29_aarch64:
  case lr_aarch64:
  case sp_aarch64:
    return FullName.substr(0, FullName.size() - sizeof("_aarch64") + 1);
  case v0_mips:
  case v1_mips:
  case a0_mips:
  case a1_mips:
  case a2_mips:
  case a3_mips:
  case s0_mips:
  case s1_mips:
  case s2_mips:
  case s3_mips:
  case s4_mips:
  case s5_mips:
  case s6_mips:
  case s7_mips:
  case gp_mips:
  case sp_mips:
  case fp_mips:
  case ra_mips:
    return FullName.substr(0, FullName.size() - sizeof("_mips") + 1);
  case r0_systemz:
  case r1_systemz:
  case r2_systemz:
  case r3_systemz:
  case r4_systemz:
  case r5_systemz:
  case r6_systemz:
  case r7_systemz:
  case r8_systemz:
  case r9_systemz:
  case r10_systemz:
  case r11_systemz:
  case r12_systemz:
  case r13_systemz:
  case r14_systemz:
  case r15_systemz:
  case f0_systemz:
  case f1_systemz:
  case f2_systemz:
  case f3_systemz:
  case f4_systemz:
  case f5_systemz:
  case f6_systemz:
  case f7_systemz:
  case f8_systemz:
  case f9_systemz:
  case f10_systemz:
  case f11_systemz:
  case f12_systemz:
  case f13_systemz:
  case f14_systemz:
  case f15_systemz:
    return FullName.substr(0, FullName.size() - sizeof("_systemz") + 1);
  }
}

/// Return the size of the register in bytes
inline size_t getSize(Values V) {
  switch (V) {
  case Invalid:
    revng_abort();
  case eax_x86:
  case ebx_x86:
  case ecx_x86:
  case edx_x86:
  case esi_x86:
  case edi_x86:
  case ebp_x86:
  case esp_x86:
    return 4;
  case rax_x86_64:
  case rbx_x86_64:
  case rcx_x86_64:
  case rdx_x86_64:
  case rbp_x86_64:
  case rsp_x86_64:
  case rsi_x86_64:
  case rdi_x86_64:
  case r8_x86_64:
  case r9_x86_64:
  case r10_x86_64:
  case r11_x86_64:
  case r12_x86_64:
  case r13_x86_64:
  case r14_x86_64:
  case r15_x86_64:
  case xmm0_x86_64:
  case xmm1_x86_64:
  case xmm2_x86_64:
  case xmm3_x86_64:
  case xmm4_x86_64:
  case xmm5_x86_64:
  case xmm6_x86_64:
  case xmm7_x86_64:
    return 8;
  case r0_arm:
  case r1_arm:
  case r2_arm:
  case r3_arm:
  case r4_arm:
  case r5_arm:
  case r6_arm:
  case r7_arm:
  case r8_arm:
  case r9_arm:
  case r10_arm:
  case r11_arm:
  case r12_arm:
  case r13_arm:
  case r14_arm:
    return 4;
  case x0_aarch64:
  case x1_aarch64:
  case x2_aarch64:
  case x3_aarch64:
  case x4_aarch64:
  case x5_aarch64:
  case x6_aarch64:
  case x7_aarch64:
  case x8_aarch64:
  case x9_aarch64:
  case x10_aarch64:
  case x11_aarch64:
  case x12_aarch64:
  case x13_aarch64:
  case x14_aarch64:
  case x15_aarch64:
  case x16_aarch64:
  case x17_aarch64:
  case x18_aarch64:
  case x19_aarch64:
  case x20_aarch64:
  case x21_aarch64:
  case x22_aarch64:
  case x23_aarch64:
  case x24_aarch64:
  case x25_aarch64:
  case x26_aarch64:
  case x27_aarch64:
  case x28_aarch64:
  case x29_aarch64:
  case lr_aarch64:
  case sp_aarch64:
    return 8;
  case v0_mips:
  case v1_mips:
  case a0_mips:
  case a1_mips:
  case a2_mips:
  case a3_mips:
  case s0_mips:
  case s1_mips:
  case s2_mips:
  case s3_mips:
  case s4_mips:
  case s5_mips:
  case s6_mips:
  case s7_mips:
  case gp_mips:
  case sp_mips:
  case fp_mips:
  case ra_mips:
    return 4;
  case r0_systemz:
  case r1_systemz:
  case r2_systemz:
  case r3_systemz:
  case r4_systemz:
  case r5_systemz:
  case r6_systemz:
  case r7_systemz:
  case r8_systemz:
  case r9_systemz:
  case r10_systemz:
  case r11_systemz:
  case r12_systemz:
  case r13_systemz:
  case r14_systemz:
  case r15_systemz:
  case f0_systemz:
  case f1_systemz:
  case f2_systemz:
  case f3_systemz:
  case f4_systemz:
  case f5_systemz:
  case f6_systemz:
  case f7_systemz:
  case f8_systemz:
  case f9_systemz:
  case f10_systemz:
  case f11_systemz:
  case f12_systemz:
  case f13_systemz:
  case f14_systemz:
  case f15_systemz:
    return 8;
  }
}

inline Values fromName(llvm::StringRef Name) {
  return getValueFromYAMLScalar<Values>(Name);
}

inline Values
fromRegisterName(llvm::StringRef Name, llvm::Triple::ArchType Arch) {
  std::string FullName = Name.str();

  switch (Arch) {
  case llvm::Triple::x86:
    FullName += "_x86";
    break;
  case llvm::Triple::x86_64:
    FullName += "_x86_64";
    break;
  case llvm::Triple::arm:
    FullName += "_arm";
    break;
  case llvm::Triple::aarch64:
    FullName += "_aarch64";
    break;
  case llvm::Triple::mips:
  case llvm::Triple::mipsel:
    FullName += "_mips";
    break;
  case llvm::Triple::systemz:
    FullName += "_systemz";
    break;

  default:
    return Invalid;
  }

  return getValueFromYAMLScalar<Values>(FullName);
}

} // namespace model::Register

template<>
inline model::Register::Values
getInvalidValueFromYAMLScalar<model::Register::Values>() {
  return model::Register::Invalid;
}

namespace model::RegisterState {

enum Values {
  Invalid,
  No,
  NoOrDead,
  Dead,
  Yes,
  YesOrDead,
  Maybe,
  Contradiction
};

} // namespace model::RegisterState

namespace llvm::yaml {
template<>
struct ScalarEnumerationTraits<model::RegisterState::Values> {
  template<typename T>
  static void enumeration(T &io, model::RegisterState::Values &V) {
    using namespace model::RegisterState;
    io.enumCase(V, "Invalid", Invalid);
    io.enumCase(V, "No", No, QuotingType::Double);
    io.enumCase(V, "NoOrDead", NoOrDead);
    io.enumCase(V, "Dead", Dead);
    io.enumCase(V, "Yes", Yes, QuotingType::Double);
    io.enumCase(V, "YesOrDead", YesOrDead);
    io.enumCase(V, "Maybe", Maybe);
    io.enumCase(V, "Contradiction", Contradiction);
  }
};
} // namespace llvm::yaml

namespace model::RegisterState {

inline llvm::StringRef getName(Values V) {
  return getNameFromYAMLEnumScalar(V);
}

inline Values fromName(llvm::StringRef Name) {
  return getValueFromYAMLScalar<Values>(Name);
}

inline bool isYesOrDead(model::RegisterState::Values V) {
  return (V == model::RegisterState::Yes or V == model::RegisterState::YesOrDead
          or V == model::RegisterState::Dead);
}

inline bool shouldEmit(model::RegisterState::Values V) {
  return isYesOrDead(V);
}

} // namespace model::RegisterState
