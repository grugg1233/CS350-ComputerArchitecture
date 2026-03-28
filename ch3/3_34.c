//long P(long x )
/*
P:
    pushq %r15 // callee saved and manipulated in P
    pushq %r14 // callee saved and manipulated in P
    pushq %r13 // callee saved and manipulated in P
    pushq %r12 // callee saved and manipulated in P
    pushq %rbp // callee saved and manipulated in P
    pushq %rbx // callee saved and manipulated in P 
    
    subq $24, %rsp // expand stack 24 B 

    movq %rdi , %rbx // store x into %rbx

    leaq 1(%rdi) , %r15 // %r15 = x + 1
    leaq 2(%rdi) , %r14 // %r14 = x + 2
    leaq 3(%rdi) , %r13 // %r13 = x + 3
    leaq 4(%rdi) , %r12 // %r12 = x + 4
    leaq 5(%rdi) , %rbp // %rbp = x + 5
    leaq 6(%rdi) , %rax // %rax = x + 6


    // %rax is a local variable stored on the stack 
    movq %rax, (%rsp) // put into the stack x+6 on the stack 


    //%rdx is a local variable stored on the stack 
    leaq 7(%rdi), %rdx

    movq %rdx, 8(%rsp) // put 7+x 8B below the top of the stack 

    movl $0, %eax //clear out %rax

    call Q


    //... 
*/
/*
callee-saved registers    local-variables stored on the stack   
    %rbx                    %rdx
    %rbp                    %rax
    %r12
    %r13
    %r14
    %r15

because it exhausted the total number of callee-saved registers
*/