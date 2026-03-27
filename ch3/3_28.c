long fun_b (unsigned long x ) {
    long val = 0 ; 
    long i ; 
    for (i=64 ; i!=0 ; i--) {
        val <<= 1; 
        val |= (x & 0x1);
        x >>= 1;
    }
    return val ;

}

/*

fun_b: 
    movl $64 , %edx # long i = 64 ; 
    movl $0 , %eax; # long val = 0 ; 
.L10: 
    movq %rdi, %rcx # long y = x; 
    andl $1, %rcx # y & 0x1;
    addq %rax , %rax # val += val ; // val <<= 1; 
    orq %rcx, %rax # val |= y;
    shrq %rdi # x >>= 1 ; // by default logical b/c x is unsigned 
    subq $1, %rdx # i --; 
    jne .L10 # if (i != 0)
    rep; ret 

A. Use the assembly-code version to fill in the missing parts of the.C code. ' ' t

see above

B. Explain why there is neither an initial test before the loop nor an initial jump
to the test portion of the loop.

because the program initializes x in the for loop to a non - 1 number (64) and thus is gauranteed that the first iteration 
will be legal... so the compiler optimizes out one check 

C. Describe in English what this function computes.

bit reversal
*/