//  pg 226 - pg 276 Must Read

                // %rdi, %rsi
// long loop_while2(long a, long b) 

/*
loop_while2: 
    testq %rsi, %rsi # b & b
    jle .L8 # if ( b <= 0 ) goto L8;
    movq %rsi, %rax # long ret = b; 
.L7: 
    imulq %rdi, %rax # 
    subq %rdi , %rsi 
    testq %rsi, %rsi
    jg .L7 
    rep; ret
.L8: 
    movq %rsi, %rax # 
    ret

*/

long loop_while2(long a, long b)  {
     
    if (b <= 0) return b; 
    long t = b;
    do { 
        t *= a; 
        b -= a ; 
    } while ( b > 0 ); 
    return t ; 

} // honest translation 


long loop_while2(long a , long b) {
    long result = b; 
    while( b > 0 )  {
        result = result * a; 
        b = b - a; 
    }
    return result;
}