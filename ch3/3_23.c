// A. Which registers are used to hold program values x, y, and n?

// Section 3.6 Control 223

// B. How has the compiler eliminated the need for pointer variable p and the
// pointer dereferencing implied by the expression (•p)++?

// C. Add an.notations to tlie assembly code describing the operation of the pro-
// gram, similar to those shown in Figure 3.19(c).

//  long dw_looop (long x)

/*




A )
x is held initially in %rdi and is copied to %rax

y is held in %rcx 

and n is held in %rdx

B ) 
the pointer p in the original program was used for one thing which is incrementing x via the dereference and so the compiler has simply translated 
it to a "+ 1" or 1(%rcx, %rax) where 1 is that whole operation within each iteration of the loop

C ) 
see  below

dw_loop: 
    movq %rdi , %rax  // long ret = x; 
    movq %rdi , %rcx // long y = x ; 
    imulq %rdi , %rcx  // y*= x; 
    leaq (%rdi, %rdi ) , %rdx // z = x<<1; 

.L2 : 
    leaq 1(%rcx, %rax) , %rax // ret = y + 1 + ret 
    subq $1 , %rdx  // z-- ; 
    testq %rdx, %rdx 
    jg // if (z > 0) goto L2; 
    rep; ret // return ret; 

*/
long dw_looop (long x) {

    long y = x*x; 
    long n = x <<1; 

    do {
        x += y + 1; 
        n--; 

    }  while( n > 0); 

    return x; 
}
