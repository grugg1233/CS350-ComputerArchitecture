/* 
For a function with prototype

long reverse_engineer(long a, long b, long c);
GCC generates the following assembly code:

reverse_engineer:
    cmpq    %rsi, %rdi
    jge     .L1
    cmpq    %rdx, %rdi
    jle     .L2
    movq    %rdx, %rax
    subq    %rdi, %rax
    ret
.L2:
    leaq    (%rdi,%rdx), %rax
    ret
.L1:
    cmpq    %rdx, %rsi
    jle     .L3
    movq    %rdx, %rax
    subq    %rsi, %rax
    ret
.L3:
    leaq    (%rsi,%rdx), %rax
    ret
Write idiomatic C code (i.e., without goto statements) for the function reverse_engineer that will have an effect equivalent to the assembly code shown.


*/

long rev_eng (long a , long b , long c) {
    if (a >= b) {
        if (b<=c) {
            return b+c; 
        } //L3
        return c-b; 
    } // L1
    if (a <= c ) return c + a; // L2  
    return c -a; 
}