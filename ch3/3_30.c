void switch2(long x, long * dest) {
    long val = 0 ; 
    switch (x) {
        default: 
            break;
    }
    *dest = val; 
}

/* 

switch2:
    addq $1, %rdi # x+= 1;
    cmpq %8, %rdi # x - 8 
    ja .L2 # if (x > 8u) goto L2;  // default 
    jmp *.L4(,%rdi, 8) # 8 + rdi *.L4 [x*8]

.L4 
    .quad .L9 #  x = -1 
    .quad .L5 #  x = 0   <------------------          |
    .quad .L6 #  x = 1                                |
    .quad .L7 #  x = 2    <------|                    |
    .quad .L2 #  x = 3 default   | - share behaiviour |   - share behaiviour
    .quad .L7 #  x = 4    <------|                    |
    .quad .L8 #  x = 5                                |
    .quad .L2 #  x = 6 default                        |
    .quad .L5 #  x = 7   <------------------          |

*/

// case 2 & 4 share behavior 
// as do 0 & 7
// the defualt is x > 7 and x= 3, and x= 6  