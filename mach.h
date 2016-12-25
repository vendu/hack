#ifndef __HACK_MACH_H__
#define __HACK_MACH_H__

/* system parameters */
#define HACK_VERSION             0x0000
#define HACK_IO_PORTS            65536
#define HACK_PAGE_SIZE           1024

/* SYSTEM OPERATIONS */

/* dummy no-operation; 1 16-bit parcel */
#define HACK_NOP_PARCEL          0xffff
/* system operations */
/* unit */
#define HACK_CPU_SYS_UNIT        0x00
/* operations */
#define HACK_CPU_SYS_RST         0x00   // reset
#define HACK_CPU_SYS_HLT         0x01   // halt

/* ARITHMETIC-LOGICAL OPERATIONS */

/* arithmetic operations; 2 16-bit parcels */
/* units */
#define HACK_CPU_ADD_UNIT        0x01
#define HACK_CPU_MUL_UNIT        0x02
#define HACK_CPU_DIV_UNIT        0x03
/* operations */
/* adder */
#define HACK_ADD                 0x00 	// r1 += ri0
#define HACK_SUB                 0x01 	// r1 -= ri0
/* multiplier */
#define HACK_MUL                 0x00 	// r1 *= ri0
/* divider */
#define HACK_DIV                 0x00 	// r1 /= ri0
#define HACK_REM                 0x01 	// r1 %= ri0
/* logical operations */
/* unit */
#define HACK_CPU_LOGIC_UNIT      0x04
/* operations */
#define HACK_NOT                 0x00 	// r0 = ~r0
#define HACK_AND                 0x01 	// r1 &= ri0
#define HACK_OR                  0x02 	// r1 |= ri0
#define HACK_XOR                 0x03 	// r1 ^= ri0
/* shift and rotate operations */
/* unit */
#define HACK_CPU_SHIFT_UNIT      0x05
/* operations */
#define HACK_SHL                 0x00 	// r1 <<= i0
#define HACK_SHR                 0x01 	// r1 >>= i0
#define HACK_SAR                 0x02 	// r1 >>>= i0
#define HACK_ROL                 0x03 	// r1 <<.= i0
#define HACK_ROR                 0x04 	// r1 >>.= i0
/* branch operations */

/* CONTROL FLOW */

/* unit */
#define HACK_CPU_BRANCH_UNIT     0x06
/* operations */
#define HACK_JMP                 0x00   // jump/branch unconditionally
#define HACK_BRA                 HACK_JMP
#define HACK_BZ                  0x01   // branch if zero/equal
#define HACK_BEQ                 HACK_BZ
#define HACK_BNZ                 0x02   // branch if not zero
#define HACK_BLT                 0x03   // branch if less than
#define HACK_BLE                 0x04   // branch if less than or equal
#define HACK_BGT                 0x05   // branch if greater than
#define HACK_BGE                 0x06   // branch if greater than or equal
#define HACK_BO                  0x07   // branch if overflow
#define HACK_BNO                 0x08   // branch if no overflow
#define HACK_BC                  0x09   // branch if carry
#define HACK_BNC                 0x0a   // branch if no carry
/* subroutine operations */
#define HACK_CAL                 0x0b   // call subroutine
#define HACK_NTR                 0x0c   // enter: psh %fp; mov %sp, %fp
#define HACK_LVE                 0x0d   // leave: mov %fp, %sp; pop %fp
#define HACK_RET                 0x0e   // return: add %nsa, %sp; mov %lnk, %pc
#define HACK_IRT                 0x0f   // return from interrupt handler

/* MEMORY OPERATIONS */

/* load-store operations */
/* unit */
#define HACK_CPU_LOAD_STORE_UNIT 0x07
/* operations */
#define HACK_LSR                 0x00   // load system register
#define HACK_LDR                 0x01   // load: r1 = *rim0
#define HACK_STR                 0x02   // store: *rm1 = rim0
/* stack operations */
/* unit */
#define HACK_CPU_STACK_UNIT      0x08
/* operations */
#define HACK_PSH                 0x00   // push register
#define HACK_POP                 0x01   // pop register
#define HACK_PMR                 0x02   // push many registers; bitmap-argument
#define HACK_PSR                 0x03   // push system register
#define HACK_PMS                 0x03   // push many system registers

/* I/O OPERATIONS */

/* unit */
#define HACK_CPU_IO_UNIT         0x09
#define HACK_IN                  0x00
#define HACK_OUT                 0x01

/* OPTIONAL UNITS */

/* atomic operations */
/* unit */
#define HACK_CPU_ATOMIC_UNIT     0x0a
/* operations */
#define HACK_CAS                 0x00   // compare and swap
#define HACK_DCS                 0x01   // dual-word compare and swap
#define HACK_STC                 0x02   // store conditional
#define HACK_LSC                 0x03   // load-store conditional

#define HACK_CPU_MAX_UNIT        0x0f

/* FPU OPERATIONS */

/* unit */
#define HACK_FPU_ADD_UNIT        0x10
#define HACK_FADD                0x00   // addition
#define HACK_FSUB                0x01   // subtraction
#define HACK_FPU_MUL_UNIT        0x11   // multiplication
#define HACK_FMUL                0x00
#define HACK_FPU_DIV_UNIT        0x12   // division
#define HACK_FDIV                0x00
#define HACK_FPU_LIM_UNIT        0x13
#define HACK_FFLO                0x00   // floor
#define HACK_FCEI                0x01   // ceiling
#define HACK_FPU_POW_UNIT        0x14
#define HACK_FPOW                0x00   // power
#define HACK_FPU_LOG_UNIT        0x15
#define HACK_FLG2                0x00   // base-2 logarithm
#define HACK_FLGN                0x01   // natural logarithm
#define HACK_FLOG                0x02   // base-10 logarithm
#define HACK_FPU_TRIG_UNIT       0x16   // fsin, fcos, ftan, arc, hyp
#define HACK_FSIN                0x00
#define HACK_FCOS                0x01
#define HACK_FTAN                0x02
#define HACK_FASIN               0x03
#define HACK_FACOS               0x04
#define HACK_FATAN               0x05
#define HACK_FSINH               0x06
#define HACK_FCOSH               0x07
#define HACK_FTANH               0x08
#define HACK_FPU_CONV_UNIT       0x17   // floating-point/integer conversions
#define HACK_FITOF               0x00   // 16-bit int to 32-bit float
#define HACK_FITOD               0x01   // 16-bit int to 64-bit double
#define HACK_FITOQ               0x02   // 16-bit int to 128-bit quad
#define HACK_FLTOF               0x03   // 32-bit long to 32-bit float
#define HACK_FLTOD               0x04   // 32-bit long to 64-bit double
#define HACK_FLTOQ               0x05   // 32-bit long to 128-bit quad
#define HACK_FQTOF               0x06   // 64-bit quad to 32-bit float
#define HACK_FQTOD               0x07   // 64-bit quad to 64-bit double
#define HACK_FQTOQ               0x08   // 64-bit quad to 128-bit quad
#define HACK_FPU_LOAD_STORE_UNIT 0x18
#define HACK_FLDF                0x00   // load 32-bit float to register
#define HACK_FLDD                0x01   // load 64-bit double to register
#define HACK_FLDQ                0x02   // load 128-bit quad to register
#define HACK_FSTF                0x03   // store 32-bit float from register
#define HACK_FSTD                0x04   // store 64-bit double from register
#define HACK_FSTQ                0x05   // store 128-bit quad from register

#define HACK_FPU_MAX_UNIT        0x1f

/* instructions are composed of 16-bit parcels */

struct hackop {
    unsigned unit : 5;  // processor unit
    unsigned op   : 4;  // unit operation
    unsigned lock : 1;  // lock memory bus flag
    unsigned vec  : 1;  // vector operation bit
    unsigned arg  : 5;  // IMM-bit, register ID
    unsigned asz  : 2;  // argument size
} PACK();

#define /* __HACK_MACH_H__ */

