#ifndef __HACK_OP_H__
#define __HACK_OP_H__

#include <stdint.h>

/* little-endian byte/bit order */

#define HACK_OP_NOP     0xffff
#define HACK_IO_PORTS   65536

/* system instructions */
#define HACK_SYS_HLT    0x00
#define HACK_SYS_LDF    0x01
#define HACK_SYS_STF    0x02
#define HACK_SYS_DDF    0x03
#define HACK_SYS_LDS    0x04
#define HACK_SYS_STS    0x05
#define HACK_SYS_BNOT   0x06
#define HACK_SYS_BAND   0x07
#define HACK_SYS_BOR    0x08
#define HACK_SYS_BXOR   0x09
#define HACK_SYS_BCLR   0x0a
#define HACK_SYS_BSET   0x0b
#define HACK_SYS_LL     0x0c
#define HACK_SYS_SC     0x0d
#define HACK_SYS_CAS    0x0e
#define HACK_SYS_CAS2   0x0f
#define HACK_SYS_FADD   0x10
#define HACK_SYS_THR    0x11
/* Boolean logic operations */
#define HACK_UNIT_LOGIC 0x01    // boolean algebra
#define HACK_LOGIC_NOT  0x00
#define HACK_LOGIC_AND  0x01
#define HACK_LOGIC_OR   0x02
#define HACK_LOGIC_XOR  0x03
/* shift and rotate operations */
#define HACK_UNIT_SHIFT 0x02    // barrel-shifter
#define HACK_SHIFT_SHL  0x00    // shift/rotate left
#define HACK_SHIFT_SHR  0x01    // shift/rotate right
#define HACK_SHIFT_SAR  0x02    // shift right arithmetic
#define HACK_SHIFT_ROT  0x04    // rotate-bit (ROL, ROR)
#define HACK_SHIFT_SIGN 0x08    // sign-fill bit (SAR)
/* adder operations */
#define HACK_UNIT_ADD   0x03    // integer adder
#define HACK_ADD_DEC    0x00
#define HACK_ADD_INC    0x01
#define HACK_ADD_SUB    0x02
#define HACK_ADD_ADD    0x03

#define HACK_UNIT_MUL   0x04    // integer multiplier
/* divider */
#define HACK_UNIT_DIV   0x05    // integer divider; remainder-bit
#define HACK_DIV        0x01
#define HACK_DIV_REM    0x08


/* flag-bits
 * ---------
 * sys          - system instruction
 * priv         - require system privileges [ring 0] for exection
 * buslk        - lock [memory] bus for an atomic operation
 * regmap       - followed by a [32-bit] register bitmap/list
 * coproc       - dispatch instruction to coprocessor
 * branch       - this is a branch instruction
 */

struct opflg6 {
    unsigned sys    : 1;
    unsigned priv   : 1;
    unsigned buslk  : 1;
    unsigned regmap : 1;
    unsigned coproc : 1;
    unsigned branch : 1;
};

struct sysop {
    struct opflg6 flg;
    unsigned      op  : 5;
    unsigned      reg : 5;
};

%struct ophdr {
    struct opflg6 flg;
    unsigned      unit : 5;     // ALU-unit or coprocessor ID
    unsigned      op   : 5;     // operation
} /* TODO: ensure bit-packing */ ;

union oparg {
    uint32_t regs;              // register bitmap for multi-register operations
    float    flt32;             // single-precision IEEE floation-point value
    uint32_t u32;               // unsigned 32-bit integer value
    int32_t  i32;               // signed 32-bit integer value
    uint16_t u16;               // unsigned 16-bit integer value
    int16_t  i16;               // signed 16-bit integer value
    uint8_t  u8;                // unsigned 8-bit integer value
    int8_t   i8;                // signed 8-bit integer value
};

struct opadr {
};

struct opcode {
    struct ophdr hdr;
    union oparg  arg;
};

#endif /* __HACK_OP_H__ */

