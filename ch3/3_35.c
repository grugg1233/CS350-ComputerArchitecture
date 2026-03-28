long rfun(unsigned long x ) 
{
    if(x == 0) 
        return x; 
    unsigned long nx = x>>2; 
    long rv = rfun (nx); 
    return  rv + x ;

}

/*
rfun: 
    pushq %rbx # save x to the stack  - callee saves
    movq %rdi , %rbx# put x in the register saved on the stackx 
    movl $0, %eax # clear out %rax

    testq %rdi, %rdi  # x & x 
    je .L2 # if (x&x == 0) goto L2

    shrq $2, %rdi # x>>=2  : logical >> 
    call rfun # rfun(x>>=2)

    addq %rbx, %rax

.L2:
    popq %rbx
    ret

*/

//What value does rfun store in the callee-saveo register %rbx?

//x 