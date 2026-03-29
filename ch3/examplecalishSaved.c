long P (long x , long y ) {
    long u = Q(y); 
    long v = Q(x); 
    return u+v; 
}
/*
P:
    pushq %rbp          # save rbp onto the stack 
    pushq %rbx          # save rbx onto the stack
    subq $8, %rsp       # make room for 8 B on the stack - (16B alignment as P is a called funciton and top of the stack prior to the 2 push instructions would have held the return address)  
    movq %rdi, %rbp     # save x to rbp
    movq %rsi, %rdi     # move y to %rdi first arg of Q
    call Q              # call Q(%rdi)
    movq %rax, %rbx     # move the return of q into %rbx 
    movq %rbp, %rdi     # grab rbp and put into the first arg register
    call Q
    addq %rbx, %rax     # %rax = Q(x) + Q(y)
    addq $8, %rsp       # deallocate the padding on the stack 
    popq %rbx           # restore %rbx 
    popq %rbp           # restore %rbp 
    ret
*/

