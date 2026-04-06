#include <stdlib.h> 
#include <stdio.h> 
#include "instructions.h"
#include "registers.h"
#define MAX_INST_LEN 7 


// const assoc reg_map[] = {
//     {}
// }


// typedef struct  {
//     unsigned long memory;
//     unsigned char inst; 
//     unsigned char registers; 
// } Instruction; 





void assembly(FILE *fp) 
{

    char ch;
    
    unsigned char reg_flag = 0, jmp_call_flag = 0;
    
    while (fscanf(fp, "%c", &ch) == 1)
    {

        if (ch == '\n' || ch == ' ' || ch == ':' || ch == ','|| ch == '\r' || ch == '\t' ) continue;

        char * word = malloc(sizeof(char) * MAX_INST_LEN);  
        int i = 0; 
        int runningLen = MAX_INST_LEN; 

        while (
               ch != '\n' && 
               ch != ' ' && 
               ch != ':' &&
               ch != ',' && 
               ch != '%'
            ) 
        {


            if ( i >= (runningLen - 1) ) {
                runningLen <<= 1; 
                word = realloc(word, runningLen);
            }
            
            word[i++] = ch; 

            if (fscanf(fp, "%c", &ch) != 1) break; 

        } // end word loop
        
        word[i] = '\0';

        if( jmp_call_flag )
        {

            // unsigned char expand = 0x0;
            // int z = 0;
            // for (; z < i ; z++) 
            // {
            //     if (word[z] == '(') 
            //     {
            //         expand = 0x1; 
            //     }
            // }
            // // TODO: check this expansion
            // if (expand) 
            // {
            //     unsigned char outer[z]; 
            //     unsigned char inner[i-z];
            //     for(int l = 0; l < z; l++) outer[l] = word[l]; 
            //     for( int l = z ; l < i ; l++) inner[l] = word[l]; 
            //     outer[z] = '\0'; 
            //     inner[i-z] = '\0';
            // }

            //not expanding then it is a label 
            printf("%s%c", word,ch);
            free(word); 
            jmp_call_flag = 0x0; 
            continue; 
        } 



        // preceeding word is a label 
        if ( ch == ':' ) 
        {
            printf("<%s>%c\n", word,ch);
            free(word); 
            continue; 
        }


        // word is instruction 
        unsigned char op = switch_statement_inst(word); 

        // instruction is jxx or call and thus we can replace the following value with 
        // label if it is a label or with expansion 
        if( 
                (op >> 4) == 0x7 || 
                (op >> 4) == 0x8
        ) 
        {
            jmp_call_flag = 1; 
            printf("%02x%c", op, ch); 
            free(word); 
            continue; 

        }


        if ( ch == '%' ) 
        {
            reg_flag = 0x1;
            free(word); 
            continue;  
            
        }
        // word is register
        if (op == 0xff) 
        {
            if (reg_flag) 
            {
                op = switch_statement_reg(word);
            //word is either grabage bin register or not a register
                if (op == 0xf) 
                {
                    printf("%s%c", word, ch);
                    free(word); 
                    reg_flag = 0x0; 
                    continue; 
                }

            }

        }


        printf("%02x%c", op, ch);
        
        //word is memory requires expansion but since we are not "linking" just do (expand D)(expand Reg)

        free(word); 

    } // end file loop
}


int main (int argc, char ** argv) 
{
    
    char* filename; 
    FILE *asm_file;


    /*
        Opening the file
    */
    if (argc < 3)
    {
        printf("Insufficient arguments \
            [correct usage- ./(prog name) (assembly/obj code file) (mode)] \
            ");
        return 1; 
    } 

    printf("Attempting to open : %s\n", argv[1]);

    filename = argv[1]; 
    asm_file = fopen(filename, "r");

    if (asm_file == NULL) 
    {
        printf("Error Opening %s", filename); 
        return 1;
    }


    printf("File %s opened successfully\n", filename);
    
    if (*argv[2] == '1') 
    {
        printf("_________\nASSEMBLY MODE\n_________\n");
        assembly(asm_file);
    }
    else if (*argv[2] == '2') 
    {
        printf("_________\nDISASSEMBLY MODE\n_________\n");
        // disassembly(asm_file); 
    }
    else 
    {
        printf("Insufficient mode argument \
        correct usage- mode is 1 ~ asm -> byte code or 2 ~ byte code -> asm \
        ");
        return 1; 
    }
    printf("\n"); 
    fclose(asm_file); 

    return 0;
}


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
