#ifndef __HACK_OP_H__
#define __HACK_OP_H__

#include <stdint.h>

/* little-endian byte/bit order */

#define HACK_OP_NOP   0xffff
#define HACK_IO_PORTS 65536

#define HACK_UNIT_SYS   0x00    // system operations
#define HACK_UNIT_LOGIC 0x01    // boolean algebra
#define HACK_UNIT_SHIFT 0x02    // barrel-shifter
#define HACK_UNIT_ADD   0x03    // integer adder
#define HACK_UNIT_MUL   0x04    // integer multiplier
#define HACK_UNIT_DIV   0x05    // integer divider; remainder-bit

#define HACK_SHIFT_ROT  0x08
#define HACK_SHIFT_SHL  0x01
#define HACK_SHIFT_SHR  0x02
#define HACK_SHIFT_SAR  0x03
#define HACK_DIV_REM    0x08
#define HACK_DIV        0x01

/* flag-bits
 * ---------
 * sys          - require system privilege [ring 0] for exection
 * buslk        - lock [memory] bus for an atomic operation
 * coproc       - dispatch instruction to coprocessor
 * branch       - this is a branch instruction
 * regmap       - followed by a [32-bit] register bitmap/list
 * immed        - immediate argument of 1 << argsz bytes
 */
struct ophdr {
    unsigned sys    : 1;
    unsigned buslk  : 1;
    unsigned coproc : 1;
    unsigned branch : 1;
    unsigned regmap : 1;
    unsigned immed  : 1;
    unsigned argsz  : 2;        // immediate argument of 1 << argsz bytes
    unsigned unit   : 4;        // ALU-unit or coprocessor ID
    unsigned op     : 4;        // operation
} /* TODO: ensure bit-packing */ ;

union oparg {
    uint32_t regs;              // register bitmap for multi-register operations
    float    flt;               // single-precision IEEE floation-point value
    int32_t  u32;               // unsigned 32-bit integer value
    int32_t  i32;               // signed 32-bit integer value
    int16_t  u16;               // unsigned 16-bit integer value
    int16_t  i16;               // signed 16-bit integer value
    int8_t   u8;                // unsigned 8-bit integer value
    int8_t   i8;                // signed 8-bit integer value
};

struct opcode {
    struct ophdr hdr;
    union oparg  arg;
};

#endif /* __HACK_OP_H__ */

