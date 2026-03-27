// long test (long x, long y)
/*
test:
    leaq 0(,%rdi, 8), %rax  # long t =  8 * x
    testq %rsi, %rsi # y & y
    jle .L2 # if ( y <= 0 ) goto L2;  
    movq %rsi, %rax #  t = y; 
    subq %rdi, %rax # t -= x ; 
    movq %rdi, %rdx # long z = x;  
    andq %rsi, %rdx # z &= y;
    cmpq %rsi, %rdi # x - y
    cmovge %rdx, %rax # if ( x >= y ) t = z; 
    ret
.L2:
    addq %rsi, %rdi # x += y; 
    cmpq $-2, %rsi # y - -2
    cmovle %rdi, %rax # if (y <= -2) ( t = x + y )
    ret  # return t;   
*/
long test (long x, long y) {
    long t = x << 3; 
    if ( y <= 0 ) goto L2; 
    t = y; 
    t-=x; 
    long z = x; 
    z &= y; 
    if ( x >= y) t = z; 
    return t; 
    L2:
        if (y <= -2) t = x + y ;   
        return t;
} // literal translation 



long test (long x, long y) {
    long val = x << 3; 
    if( y > 0 ) {
        if ( x < y ) 
            val = (y - x); 
        else 
            val = (x & y);         
    }
    else if (y <= -2 ) 
        val = x + y ;
    return val; 
    
} //structured translation

