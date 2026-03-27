/* 

#void switcher (long a , long b, long c, long *dest) 

switcher:
    cmpq $7, %rdi # a - 7 
    ja .L2 # default case if a > 7 
    jmp *.L4(, %rdi, 8) # goto *(jtable[a])  // where a is quad word 8 byte aligned 
    .section .rodata
    .L7:
        xorq $15, %rsi # b ^= 15 ; 
        movq %rsi, %rdx # c = b ; 
    .L3: 
        leaq 112(%rdx) , %rdi # a = c + 112; 
        jmp .L6 #  goto L6;   
    .L5:
        leaq (%rdx, %rsi), %rdi # a = c+b; 
        salq $2, %rdi # a<<=2 ; 
        jmp .L6 # goto L6; 
    .L2; 
        movq %rsi, %rdi # a = b; 
    .L6: 
        movq %rdi ,  (%rcx) # *dest = a; 
        ret 
#jump table
    .L4: 
        .quad .L3 # a = 0 
        .quad .L2 # a = 1  // default 
        .quad .L5 # a = 2 
        .quad .L2 # a = 3  // default 
        .quad .L6 # a = 4  
        .quad .L7 # a = 5 
        .quad .L2 # a = 6  // default
        .quad .L5 # a = 7
*/



void switcher (long a , long b, long c, long *dest) {

    switch (a) {
        case 5:
            b ^= 15;
            c = b;
        case 0:
            a = c + 112; 
            break;
        case 7: 
        case 2: 
            a = c+b; 
            a<<=2 ; 
            break; 
        case 4:
            break;
        default:
             a = b;
    }
    //L6
    *dest = a;

}