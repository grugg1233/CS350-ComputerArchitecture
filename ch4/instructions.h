#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <string.h> 

typedef enum {
    halt, 
    nop, 
    rrmovq, 
    irmovq, 
    rmmovq, 
    mrmovq, 
    addq, 
    subq, 
    andq, 
    xorq, 
    jmp, 
    jle, 
    jl, 
    je, 
    jne, 
    jge, 
    jg, 
    cmovle, 
    cmovl, 
    cmove, 
    cmovne, 
    cmovge, 
    cmovg,  
    call, 
    ret, 
    pushq, 
    popq, 
    INST_COUNT
} INST;

extern const unsigned char op_vals[INST_COUNT]; 
unsigned char switch_statement_inst(char *word); 

#endif