// loop:
//     movl    $0, %eax      
//     jmp     .L2          
// .L4:
//     cmpl    %esi, %edi   # a - e 
//     jle     .L3          # if (a <= e ) goto L3 (break) 
//     addl    $1, %eax     # else f ++
//     addl    %ecx, %esi   #  
// .L2:
//     cmpl    %edx, %esi    
//     jl      .L4          
// .L3:
//     cmpl    %esi, %edi   
//     sete    %cl            
//     cmpl    %edx, %esi   
//     setl    %dl            
//     testb   %dl, %cl      
//     jne     .L5           
//     movl    $-1, %eax     
// .L5:
//     ret                  


//         rdi   rsi    rdx     rcx
int loop(int a, int b, int c, int d) { 
    int ret = 0;
    goto L2; 
    L4:
        if (a <= b) goto L3; 
        ret += 1 ;
        b += d ; 
    L2:
        if (b < c) goto L4; 
    L3: 
        int lowd = (d & ~(0xFF));
        int lowc = (c & ~(0xFF));
        d = lowd | (a==b);
        c = lowc | (b < c); 
        lowd = (d & ~(0xFF));
        lowc = (c & ~(0xFF));
        if ((lowd & lowc)) goto L5; 
        ret = -1; 
    L5: 
        return ret; 
} // literal translation 


int loop(int a, int b, int c, int d) {
    int e;
    int f = 0;
    for (e = b; e < c ; e += d ) {
        if (a <= e)
            break;
        f++;
    }
    return ((a==e) & (e < c)) ? f : -1;
}