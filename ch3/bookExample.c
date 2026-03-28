long swap_add(long * xp,long * yp) {
    long x=  *xp ;
    long y = *yp;
    *xp = y; 
    *yp =  x; 
    return x+y; 
}


long caller () {

    long arg1 = 534 ; 
    long arg2  = 1057 ; 
    long sum = swap_add (&arg1, &arg2); 
    long diff = arg1 - arg2 ; 
    return  sum * diff; 
}

/* 
long caller()
caller: 
    subq $16, %rsp # grow the stack by 16 B
    movq %543, (%rsp ) # copying arg1 to the stack
    movq $1057, 8(%rsp) # copying arg 2 to M[rsp + 8]  
    movq %rsp, %rdi   # &arg1
    leaq 8(%rsp), %rsi # &arg2
    call swap_add # swap_add(&arg1, &arg2)
    movq (%rsp), %rdx # get  arg1
    subq 8(%rsp), %rdx # long diff = arg1 - arg2 
    addq $16, %rsp 
    imulq %rdx , %rax 
    ret 
*/


long call_proc() {

    long x1 = 1 ;
    int x2 =2 ; 
    short x3 = 3 ;
    char x4 = 4; 
    proc(x1, &x1, x2, &x2, x3 , &x3 , x4 , & x4 ); 
    return (x1+x2) * (x3-x4) ; 

}
/*

// args : %rdi, rsi, rdx, rcx, r8 , r9 
// then get vals from the stack 
call_proc: 
    subq $32, %rsp # decrement the stack pointer by 32 B 
    #memory allocation
    movq $1, 24(%rsp) #  put x1 on the stack *(&x1) = 1
    movl $2, 20(%rsp) #  put x2 on the stack *(&x2) = 2
    movw $3, 18(%rsp) # put x3 on the stack  *(&x3) = 3
    movb $4, 17(%rsp) # put x4 on the stack *(&x4) = 4
    #argument handling 
    leaq 17(%rsp) , %rax # create &x4
    movq %rax , 8(%rsp) #ARG 8:  put &x4 on the stack 
    movq $4, ($rsp) # ARG 7:put x4 (4) on the stack 
    
    #arg 6 - %r9
    leaq 18(%rsp), %r9
    #arg 5 - %r8
    movl $3, $r8d
    #arg 4 - %rcx
    leaq 20(%rsp), %rcx
    #arg 3 - %rdx
    movl $2, %edx
    #arg 2 - %rsi
    leaq 24(%rsp), rsi
    #arg 1 - %rdi
    movq $1, %rdi

    call proc
    #    return (long x1+ int x2) * (short x3- char x4) ; 
    #x1
    movslq 20(%rsp), %rax
    addq 24(%rsp), %rax
    movswl 18(%rsp), %edx
    movsbl 17(%rsp), %ecx
    subl %ecx, %edx
    cltq %edx
    imulq %rdx, %rax
    addq $32, %rsp
    ret  

*/

