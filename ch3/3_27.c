/*
 GCC 

fact_for: 
    movl $1, %eax # long result = 1; 
    movl $2 ,%edx # long x = 2; 
    jmp .L8 # goto L8 

.L9: 
    imulq %rdx, %rax # result*=x ;
    addq $1, %rdx # x++ ; 

.L8: 
    cmpq %rdi , %rdx # x - n ; 
    jle .L9 # if ( x <=  n ) goto L9 ; 
    rep ; ret
*/

long fact_for(long n) {
    long result = 1; 
    long x = 2; 
    while ( x <= n ) { 
        result *=  x;
        x++; 
    }
    return result; 

} // while loop translation 

long fact_for ( long n ) {
    long result = 1; 
    long x = 2 ; 
    goto L8; 
    L9:
        result*=x; 
        x++; 
    L8: 
        if ( x <= n ) goto L9; 
        return result ; 

} //jump to middle goto 


long fact_for ( long n ) {
    long result = 1; 
    long x = 2 ;
    check: 
        if (x > n) goto b; 
     
    L9:
        result*=x; 
        x++;  
        if (x <= n)
            goto L9 ;
    b: 
        return result ; 

} //gaurded do 


long fact_for (long n ) {
    long r = 1; 
    for (long x = 2; x <= n ; x++) {
        r *= x; 
    }
    return r; 

}
