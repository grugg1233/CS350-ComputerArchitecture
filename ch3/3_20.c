#define OP  / // unkown 

long arith(long x ){
    return x OP 8; 

}

// gcc generates

/*

    leaq 7(%rdi) , %rax
    testq %rdi, %rdi # x & x
    cmovns %rdi , %rax # cond move non-negative ~ if (x >= 0)
    sarq $3, %rax # 
    ret
*/

// long y = 7 + x; 
// if (x >= 0 ) y = x; 
// y >> 3 ;  
