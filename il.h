#pragma once

#include "binaryninjaapi.h"
#include "disassembler/operations.h"
#include "disassembler/encodings_dec.h"
#include "disassembler/encodings_fmt.h"
#include "disassembler/arm64dis.h"

#define IL_FLAG_N 31
#define IL_FLAG_Z 30
#define IL_FLAG_C 29
#define IL_FLAG_V 28

#define IL_FLAGWRITE_NONE       0
#define IL_FLAGWRITE_ALL        1

enum Arm64Intrinsic : uint32_t
{
	ARM64_INTRIN_AUTDA,
	ARM64_INTRIN_AUTDB,
	ARM64_INTRIN_AUTIA,
	ARM64_INTRIN_AUTIB,
	ARM64_INTRIN_AUTIB1716,
	ARM64_INTRIN_AUTIBSP,
	ARM64_INTRIN_AUTIBZ,
	ARM64_INTRIN_AUTDZA,
	ARM64_INTRIN_AUTDZB,
	ARM64_INTRIN_AUTIZA,
	ARM64_INTRIN_AUTIZB,
	ARM64_INTRIN_DC,
	ARM64_INTRIN_DMB,
	ARM64_INTRIN_DSB,
	ARM64_INTRIN_ESB,
	ARM64_INTRIN_HINT_BTI,
	ARM64_INTRIN_HINT_CSDB,
	ARM64_INTRIN_HINT_DGH,
	ARM64_INTRIN_HINT_TSB,
	ARM64_INTRIN_ISB,
	ARM64_INTRIN_MRS,
	ARM64_INTRIN_MSR,
	ARM64_INTRIN_PACDA,
	ARM64_INTRIN_PACDB,
	ARM64_INTRIN_PACDZA,
	ARM64_INTRIN_PACDZB,
	ARM64_INTRIN_PACGA,
	ARM64_INTRIN_PACIA,
	ARM64_INTRIN_PACIA1716,
	ARM64_INTRIN_PACIASP,
	ARM64_INTRIN_PACIAZ,
	ARM64_INTRIN_PACIB,
	ARM64_INTRIN_PACIB1716,
	ARM64_INTRIN_PACIBSP,
	ARM64_INTRIN_PACIBZ,
	ARM64_INTRIN_PACIZA,
	ARM64_INTRIN_PACIZB,
	ARM64_INTRIN_PRFM,
	ARM64_INTRIN_PSBCSYNC,
	ARM64_INTRIN_SEV,
	ARM64_INTRIN_SEVL,
	ARM64_INTRIN_WFE,
	ARM64_INTRIN_WFI,
	ARM64_INTRIN_XPACD,
	ARM64_INTRIN_XPACI,
	ARM64_INTRIN_XPACLRI,
	ARM64_INTRIN_YIELD,
	ARM64_INTRIN_ERET,
	ARM64_INTRIN_CLZ,
	ARM64_INTRIN_CLREX,
	ARM64_INTRIN_REV,
	ARM64_INTRIN_RBIT,
	ARM64_INTRIN_AESD,
	ARM64_INTRIN_AESE,
	ARM64_INTRIN_NORMAL_END, /* needed so intrinsics can be extended by other lists, like neon intrinsics */
	ARM64_INTRIN_INVALID=0xFFFFFFFF,
};

enum Arm64FakeRegister: uint32_t
{
	FAKEREG_SYSCALL_INFO = SYSREG_END+1
};

bool GetLowLevelILForInstruction(
		BinaryNinja::Architecture* arch,
		uint64_t addr,
		BinaryNinja::LowLevelILFunction& il,
		Instruction& instr,
		size_t addrSize);

BinaryNinja::ExprId ExtractRegister(BinaryNinja::LowLevelILFunction& il, InstructionOperand& operand, size_t regNum, size_t extractSize, bool signExtend, size_t resultSize);

