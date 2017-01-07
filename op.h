#ifndef __HACK_OP_H__
#define __HACK_OP_H__

/* little-endian byte/bit order */

/*
 * LOCK         - lock [memory] bus for an atomic operation
 * SYSMODE      - require system privilege [ring 0] for exection
 * COPROC       - dispatch instruction to coprocessor
 * BRANCH       - this is a branch instruction
 * REGMAP       - followed by a [32-bit] register bitmap/list
 */
struct ophdr {
    unsigned flg    : 6;        // BUSLK, SYSMODE, COPROC, BRANCH, REGMAP
    unsigned argsz  : 2;        // immediate argument of 8 << argsz bytes
    unsigned unit   : 4;        // ALU-unit or coprocessor ID
    unsigned op     : 4;        // operation
};

#endif /* __HACK_OP_H__ */

