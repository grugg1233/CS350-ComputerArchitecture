/*
AC function procprob !Jas four arguments u, a, v·, and b. Each is either a signed
number or a pointer to a signed number, where the numbers have different sizes.
The function has the following body:
*/
            //  %rdi    %rsi    %rdx     %rcx
long procprob(int a, short b, long *u, char *v) {
    *u += a; 
    *v += b; 
    return sizeof(a) + sizeof(b) ;    
}

/*
procprob: 
    movslq %edi, %rdi # 
    addq %rdi ,(%rdx) # *u ~ 3rd arg, a ~ 1st arg   
    addb %sil, %(rcx) # *v ~ 4th arg, b ~ 2nd arg
    movl $6, %eax     # sizeof(a) + sizeof(b) = 6
    ret
*/
