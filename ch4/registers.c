#include "registers.h"

    /*
        
        Number      Register name       Number      Register name
    ---------------------------------------------------------------
    0     |      %rax         |       8     |      %r8
    1     |      %rcx         |       9     |      %r9
    2     |      %rdx         |       A     |      %r10
    3     |      %rbx         |       B     |      %r11
    4     |      %rsp         |       C     |      %r12
    5     |      %rbp         |       D     |      %r13
    6     |      %rsi         |       E     |      %r14
    7     |      %rdi         |       F     |      Noregister

    */  

const unsigned char reg_vals[REG_COUNT]  = { 
    [rax] = 0x00,
    [rcx] = 0x01,
    [rdx] = 0x02,
    [rbx] = 0x03,
    [rsp] = 0x04,
    [rbp] = 0x05,
    [rsi] = 0x06,
    [rdi] = 0x07,
    [r8] = 0x08,
    [r9] = 0x09,
    [r10] = 0x0a,
    [r11] = 0x0b,
    [r12] = 0x0c,
    [r13] = 0x0d,
    [r14] = 0x0e


}; 


unsigned char switch_statement_reg( char * word) {


    unsigned char reg; 

    if (strcmp(word,"rax")  == 0)        reg = reg_vals[rax];
    else if (strcmp(word, "rcx")  == 0)  reg = reg_vals[rcx];
    else if (strcmp(word, "rdx")  == 0)  reg = reg_vals[rdx];
    else if (strcmp(word, "rbx")  == 0)  reg = reg_vals[rbx];
    else if (strcmp(word, "rsp")  == 0)  reg = reg_vals[rsp];
    else if (strcmp(word, "rbp")  == 0)  reg = reg_vals[rbp];
    else if (strcmp(word, "rsi")  == 0)  reg = reg_vals[rsi];
    else if (strcmp(word, "rdi")  == 0)  reg = reg_vals[rdi];
    else if (strcmp(word, "r8")  == 0)   reg = reg_vals[r8];
    else if (strcmp(word, "r9")  == 0)   reg = reg_vals[r9];
    else if (strcmp(word, "r10")  == 0)  reg = reg_vals[r10];
    else if (strcmp(word, "r11")  == 0)  reg = reg_vals[r11];
    else if (strcmp(word, "r12")  == 0)  reg = reg_vals[r12];
    else if (strcmp(word, "r13")  == 0)  reg = reg_vals[r13];
    else if (strcmp(word, "r14")  == 0)  reg = reg_vals[r14];
    else reg = 0xF; 
}