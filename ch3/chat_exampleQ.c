/*
    # %rdi = p
    # %rsi = n
    # %rdx = k

    probe:
        movq    $0, %rax
        testq   %rsi, %rsi
        jle     .L4

    .L3:
        movq    (%rdi), %rcx
        cmpq    %rdx, %rcx
        jle     .L2
        addq    %rcx, %rax

    .L2:
        addq    $8, %rdi
        subq    $1, %rsi
        jne     .L3

    .L4:
        ret

*/