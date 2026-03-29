#define N 16
typedef int fix_matrix[N][N]; 
void set_diag(fix_matrix A, int val) {
    long i; 
    for(i=0; i < N; i++) {
        A[i][i] = val; 
    }
}


/*
# A %rdi , val %rsi
set_diag: 
    movl $0, %eax
.L13: 
    movl %esi, (%rdi, %rax)
    addq $68, %rax 
    cmpq $1088, %rax 
    jne .L13 
    rep ; ret

*/

void set_diag_opt(fix_matrix A, int val ){
    int* Aptr = &A[0][0];
    long  i = 0; 
    long end = N*(N+1);
    do {
        Aptr[i] = val; 
        i+= (N+1);

    }
    while (i != end);
}