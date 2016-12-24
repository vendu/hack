#ifndef __HACK_MACH_H__
#define __HACK_MACH_H__

/* system parameters */
#define HACK_VERSION         0x0000
#define HACK_IO_PORTS        65536
#define HACK_PAGE_SIZE       1024

/* dummy no-operation; 1 16-bit parcel */
#define HACK_NOP_PARCEL      0xffff
/* system operations */
/* unit */
#define HACK_SYSTEM_UNIT     0x0
/* operations */
#define HACK_SYSTEM_RST      0x0        // reset
#define HACK_SYSTEM_HLT      0x1        // halt
/* arithmetic operations; 2 16-bit parcels */
/* units */
#define HACK_ARITH_ADD_UNIT  0x1
#define HACK_ARITH_MUL_UNIT  0x2
#define HACK_ARITH_DIV_UNIT  0x3
/* operations */
/* adder */
#define HACK_ADD             0x0 	// r1 += ri0
#define HACK_SUB             0x1 	// r1 -= ri0
/* multiplier */
#define HACK_MUL             0x0 	// r1 *= ri0
/* divider */
#define HACK_DIV             0x0 	// r1 /= ri0
#define HACK_REM             0x1 	// r1 %= ri0
/* logical operations */
/* unit */
#define HACK_LOGIC_UNIT      0x4
/* operations */
#define HACK_NOT             0x0 	// r0 = ~r0
#define HACK_AND             0x1 	// r1 &= ri0
#define HACK_OR              0x2 	// r1 |= ri0
#define HACK_XOR             0x3 	// r1 ^= ri0
/* shift and rotate operations */
/* unit */
#define HACK_SHIFT_ROT_UNIT  0x5
/* operations */
#define HACK_SHL             0x0 	// r1 <<= i0
#define HACK_SHR             0x1 	// r1 >>= i0
#define HACK_SAR             0x2 	// r1 >>>= i0
#define HACK_ROL             0x3 	// r1 <<.= i0
#define HACK_ROR             0x4 	// r1 >>.= i0
/* branch operations */
/* unit */
#define HACK_BRANCH_UNIT     0x6
/* operations */
#define HACK_JMP             0x0        // jump/branch unconditionally
#define HACK_BRA             HACK_JMP
#define HACK_BZ              0x1        // branch if zero/equal
#define HACK_BEQ             HACK_BZ
#define HACK_BNZ             0x2        // branch if not zero
#define HACK_BLT             0x3        // branch if less than
#define HACK_BLE             0x4        // branch if less than or equal
#define HACK_BGT             0x5        // branch if greater than
#define HACK_BGE             0x6        // branch if greater than or equal
#define HACK_BO              0x7        // branch if overflow
#define HACK_BNO             0x8        // branch if no overflow
#define HACK_BC              0x9        // branch if carry
#define HACK_BNC             0xa        // branch if no carry
/* subroutine operations */
/* unit */
#define HACK_SUBRT_UNIT      0x7
/* operations */
#define HACK_CAL             0x0        // call subroutine
#define HACK_NTR             0x1        // enter: psh %fp; mov %sp, %fp
#define HACK_LVE             0x2        // leave: mov %fp, %sp; pop %fp
#define HACK_RET             0x3        // return: add %nsa, %sp; mov %lnk, %pc
/* load-store operations */
/* unit */
#define HACK_LOAD_STORE_UNIT 0x8
/* operations */
#define HACK_LSR             0x0        // load system register
#define HACK_LDR             0x1        // load: r1 = *rim0
#define HACK_STR             0x2        // store: *rm1 = rim0
/* stack operations */
/* unit */
#define HACK_STACK_UNIT      0x9
/* operations */
#define HACK_PSH             0x0        // push register
#define HACK_POP             0x1        // pop register
#define HACK_PMR             0x2        // push many registers; bitmap-argument
#define HACK_PSR             0x3        // push system register
#define HACK_PMS             0x3        // push many system registers
/* atomic operations */
/* unit */
#define HACK_ATOMIC_UNIT     0xa
/* operations */
#define HACK_CAS             0x0        // compare and swap
#define HACK_DCS             0x1        // dual-word compare and swap
#define HACK_STC             0x2        // store conditional
#define HACK_LSC             0x3        // load-store conditional
/* I/O operations */
/* unit */
#define HACK_IO_UNIT         0xb
#define HACK_IN              0x0
#define HACK_OUT             0x1

/* TODO: float, audio, video units */

struct hackop {
    unsigned unit : 4;  // processor unit
    unsigned op   : 3;  // unit operation
    unsigned sign : 1;  // bit to denote signed operations
    unsigned lock : 1;  // lock memory bus flag
    unsigned reg  : 4;  // register ID
    unsigned asz  : 3;  // argument size
} PACK();

#define /* __HACK_MACH_H__ */

