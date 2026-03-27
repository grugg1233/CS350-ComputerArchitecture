// long fun_a (unsigned long x)  {
//     long val = 0 ; 

//     while (...) {
//         .
//         .
//         .

//     }
//     return ...; 

// }

/* GIVEN GCC ASM
fun_a: 
    movl $0 , %eax # b/c we return long :  long val = 0; 
    jmp .L5 # goto L5 

.L6: 
    xorq %rdi, %rax # val ^= x; 
    shrq %rdi # b/c x unsigned : x >> 1
.L5: 
    testq %rdi, %rdi # x & x 
    jne .L6 # if ( x != 0 ) goto L6; 
    andl $1 , %eax # 
    ret


A. Determine what loop translation method was used.


Jump to middle

B. Use the assembly-code version to fill in the missing parts of the C code.

view below

C. Describe in English what this function computes.

parity of x , returns 0 if even number of 1 bits in x and 1 if there is an odd number of 1 bits in x 

*/

long fun_a (unsigned long x)  {
    long val = 0 ; 
    goto L5; 
    L6: 
        val^=x; 
        x >>= 1; 
    L5: 
        if ( x != 0) goto L6; 
        val &= 1 ;
        return val;  
 
} // literal translation

long fun_a (unsigned long x)  {
    long val = 0 ; 

    while (x) {
       val ^= x ; 
       x >>= 1; 
    }
    
    return val & 1 ; 
} 