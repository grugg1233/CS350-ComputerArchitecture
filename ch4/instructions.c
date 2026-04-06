#include "instructions.h"

/*
Y86-64 ASM -> Byte Code

Byte                      1      2      3       4       5       6       7       8       9       10

halt                | 0 0 | 
nop                 | 1 0 |  
rrmovq rA rB        | 2 0 | rA rB          
irmovq V  rB        | 3 0 | F  rB | V (8B) ---------------------------------------------------------|
rmmovq rA D(rB)     | 4 0 | rA rB | D (8B) ---------------------------------------------------------|
mrmovq D(rB) rA     | 5 0 | rA rB | D (8B) ---------------------------------------------------------|
OPq    rA rB        | 6 fn| rA rB
jxx    Dest         | 7 fn| Dest ---------------------------------------------------------|                    
cmovXX rA rB        | 2 fn| rA rB | 
call   Dest         | 8 0 | Dest ---------------------------------------------------------|
ret                 | 9 0 |
pushq  rA           | A 0 | rA F  |
popq  rA            | B 0 | rA F  |


OPERATIONS   |   Branches       | Moves
---------------------------------------------------
addq - 6 0   |   jmp - 7 0      |   rrmovq  - 2 0 
subq - 6 1   |   jle - 7 1      |   cmovle  - 2 1
andq - 6 2   |   jl  - 7 2      |   cmovl   - 2 2
xorq - 6 3   |   je  - 7 3      |   cmove   - 2 3
             |   jne - 7 4      |   cmovne  - 2 4
             |   jge - 7 5      |   cmovge  - 2 5
             |   jg  - 7 6      |   cmovg   - 2 6

*/

const unsigned char op_vals[INST_COUNT] = {
    [halt]      =   0x00,
    [nop]       =   0x10,
    [rrmovq]    =   0x20,
    [irmovq]    =   0x30,
    [rmmovq]    =   0x40,
    [mrmovq]    =   0x50,
    [addq]      =   0x60,
    [subq]      =   0x61,
    [andq]      =   0x62,
    [xorq]      =   0x63,
    [jmp]       =   0x70,
    [jle]       =   0x71,
    [jl]        =   0x72,
    [je]        =   0x73,
    [jne]       =   0x74,
    [jge]       =   0x75,
    [jg]        =   0x76,
    [cmovle]    =   0x21,
    [cmovl]     =   0x22,
    [cmove]     =   0x23,
    [cmovne]    =   0x24,
    [cmovge]    =   0x25,
    [cmovg]     =   0x26,
    [call]      =   0x80,
    [ret]       =   0x90,
    [pushq]     =   0xA0,
    [popq]      =   0xB0

}; 

unsigned char switch_statement_inst( char * word) {
    unsigned char op; 
    if (strcmp(word,"halt") == 0) op = op_vals[halt]; 
    else if (strcmp(word,"nop") == 0) op = op_vals[nop]; 
    else if (strcmp(word,"rrmovq") == 0) op = op_vals[rrmovq]; 
    else if (strcmp(word,"irmovq") == 0) op = op_vals[irmovq]; 
    else if (strcmp(word,"rmmovq") == 0) op = op_vals[rmmovq]; 
    else if (strcmp(word,"mrmovq") == 0) op = op_vals[mrmovq]; 
    else if (strcmp(word,"addq") == 0) op = op_vals[addq]; 
    else if (strcmp(word,"subq") == 0) op = op_vals[subq]; 
    else if (strcmp(word,"andq") == 0) op = op_vals[andq]; 
    else if (strcmp(word,"xorq") == 0) op = op_vals[xorq]; 
    else if (strcmp(word,"jmp") == 0) op = op_vals[jmp]; 
    else if (strcmp(word,"jle") == 0) op = op_vals[jle]; 
    else if (strcmp(word,"jl") == 0) op = op_vals[jl]; 
    else if (strcmp(word,"je") == 0) op = op_vals[je]; 
    else if (strcmp(word,"jne") == 0) op = op_vals[jne]; 
    else if (strcmp(word,"jge") == 0) op = op_vals[jge]; 
    else if (strcmp(word,"jg") == 0) op = op_vals[jg]; 
    else if (strcmp(word,"cmovle") == 0) op = op_vals[cmovle]; 
    else if (strcmp(word,"cmovl") == 0) op = op_vals[cmovl]; 
    else if (strcmp(word,"cmove") == 0) op = op_vals[cmove]; 
    else if (strcmp(word,"cmovne") == 0) op = op_vals[cmovne]; 
    else if (strcmp(word,"cmovge") == 0) op = op_vals[cmovge]; 
    else if (strcmp(word,"cmovg") == 0) op = op_vals[cmovg]; 
    else if (strcmp(word,"call") == 0) op = op_vals[call]; 
    else if (strcmp(word,"ret") == 0) op = op_vals[ret]; 
    else if (strcmp(word,"pushq") == 0) op = op_vals[pushq]; 
    else if (strcmp(word,"popq") == 0) op = op_vals[popq]; 
    else op = 0xFF; 
    return op; 
}