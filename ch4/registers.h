#ifndef REGISTERS_H
#define REGISTERS_H

#include <string.h> 

typedef enum {
    rax,
    rcx,
    rdx,
    rbx,
    rsp,
    rbp,
    rsi,
    rdi,
    r8,
    r9,
    r10,
    r11,
    r12,
    r13,
    r14,
    // NOREG,
    REG_COUNT
} REG;

extern const unsigned char reg_vals[REG_COUNT]; 
unsigned char switch_statement_reg(char *word); 

#endif