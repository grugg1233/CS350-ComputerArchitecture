/*
# long test(long x , long y, long z)
test: 
    leaq (%rdi, %rsi) , %rax # long t = x + y ;
    addq %rdx, %rax # t += z ;
    cmpq $-3, %rdi # x - - 3 ;
    jge .L2  # if (x >= -3) goto L2;  
    cmpq %rdx, %rsi # y - z
    jge .L3 # if ( y >= z ) goto L3; 
    movq %rdi, %rax # t = x ;
    imulq %rsi , %rax # t*=y ;
    ret 

.L3: 
    movq %rsi, %rax # t = y;
    imulq %rdx, %rax # t*= z; 
    ret
.L2: 
    cmpq $2, %rdi #  x - 2 
    jle .L4 # if ( (x - 2 )<= 0 ) goto L4 === if (x <= 2 )
    movq %rdi, %rax # t = x; 
    imulq %rdx , %rax # t*=z; 
.L4:
    rep; ret

*/

long test(long x , long y, long z) {
    long t = x + y + z; 
    if ( x >= -3 ) {
        goto L2; 
    }

    if ( y >= z) {
        goto L3; 
    }
    t = x;
    t*= y;  
    return t; 
    L3:
        t = y; 
        t*=z;
        return t ; 

    L2:
        if ( x <= 2 ) {
            goto L4 ; 
        }
        t = x*z;
    
    L4: 
        return t;
} // literal translation



long test(long x, long y, long z) {
    long val = x + y + z; 
    if ( x < -3 ) {
        if ( y >= z )
            val = y * z; 
        else
            val = x*y; 
    } else if ( x > 2) 
        val= x*z ;
    return val;
}