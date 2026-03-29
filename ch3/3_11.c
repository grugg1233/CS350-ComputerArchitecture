/*

mystery:
    pushq   %rbx            # callee-saved
    movq    %rdi, %rbx      # unsigned long cp_x = x  
    movl    $0, %eax        # long ret = 0  
    testq   %rdi, %rdi      # x&x
    je      .L2             # if(x == 0) goto L2; 

    shrq    $2, %rdi        # x >>= 2; // x  = x / 4; 
    call    mystery         
    addq    %rbx, %rax      # long ret = cp_x + mystery(x); 
.L2:
    popq    %rbx            # pop rbx old value 
    ret                     # return ret

List the callee-saved registers.
    %rbx is the only one used in the example above 

    the full list is 
    %rbx
    %rbp ~
    %r12
    %r13 
    %r14
    %r15


All 64-bit platforms, except some embedded platforms, require that the stack is 16 byte 
aligned immediately before the call instruction is executed. 
In a sentence, clearly explain how the alignment requirement is met immediately before the call instruction is executed.
---------------------------------------
Explaining to my son (Krunchy )
call mystery() 

stack state 


16      -----------------
        0x20315123231212
        ----------------
rsp = 24

if  rsp % 16 == 0: 
    good_to_call = True
else: 
    raise ValueError()

subq $24, %rsp 
movl 


if I did not save %rbx onto the stack I would have to do :  
subq $8, %rsp  
---------------------------------------

A: 
%rsp % 16 = 8 because the return address of the preceeding call to mystery was at the top of the stack,
so the push %rbx instruction causes %rsp - 8 and (%rsp) = %rbx and therefore  %rsp % 16 = 0 


Consider the call mystery(210)

    What is its return value?
    iter 1: 
        return 210 + mystery(52) 
    iter 2 : 
        return 52 + mystery(13)
    iter 3:
        return 13 + mystery(3)
    iter 4: 
        return 3 + mystery(0)
    iter 5: 
        return  0

    3 + 13 + 52 + 210 = 278

    How many new stack frames will be constructed in total?

        4  new stack frames , 5 if you include where we first see the program , and possibly more total frames including those 
        that got us to where we began 

    List the size of each and every stack frame at its maximum in chronological order.

        8 B each , 16 if you include the return address of the caller as part of the frame 

*/

long mystery(unsigned long x);

