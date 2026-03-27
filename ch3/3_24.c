//long loop_while(long a , long b) {

// }

/* 

loop_while: 
    movl $1, %eax # int t = 1; 
    jmp .L2 # goto L2; 

.L3
    leaq (%rdi, %rsi) , %rdx # long c  =a + b;
    imulq %rdx, %rax # t *= c; 
    addq $1, %rdi # a ++; 
.L2: 
    cmpq %rsi, %rdi # a - b
    jl .L3 # if( a < b) goto L3; 
    rep; ret # return

*/


long loop_while(long a , long b) {
    long t = 1;
    long c;  
    goto L2; 
    L3:
        c = a + b;
        t *= c ; 
        a++; 
    L2:
        if ( a < b ) goto L3; 
        return t; 

}

long loop_while(long a , long b) {
    long t = 1; 
    long c ;
    while (a < b) {
        c = a+b; 
        
        t *= c; 

        a++; 

    }
    return  t; 
}



// book expects
long loop_while(long a , long b) {
    long result = 1;  
    while (a < b) {
        result *= (a+b); 
        a = 1+a; 
    }
    return result; 
}

