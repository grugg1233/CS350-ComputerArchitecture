
// #define M... 
// #define N... 

// long P[M][N]
// long Q[N][M]

// long sum_element(long i, long j) {
//     return P[i][j] + Q[j][i]
// }

/*

# %rdi - i 
# %rsi - j

# rdx ~ 7i + j
# rax ~ 5j
# rdi ~ i+5j
sum_element:
    leaq 0(,%rdi, 8), %rdx      # rdx = 8*i
    subq %rdi, %rdx             # rdx -= i
    addq %rsi, %rdx             # rdx += j
    leaq (%rsi, %rsi, 4), %rax  # rax = j+(4*j)
    addq %rax, %rdi             # i += rax
    movq Q(,%rdi, 8), %rax      # rax = Q + 8*(i+5j)
    addq P(,%rdx, 8), %rax      # rax += P + 8*(7i + j)
    ret

For an Array A 

T A[R][C]
where sizeof(T) = L
the equation for referencing A[i][j] is L(i*C + j)

and &A[i][j] = x_A + L(i*C + j)

formula given : L(C*i + j)
P + 8*(7i + j) ~ P is at offset i*n 
       7         5
# P[M][N] + Q[N][M] 
M~5z N~7
*/