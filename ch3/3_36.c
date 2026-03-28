short S[7];// sizeof(S[0]) ~ 2B

short *T[3];// sizeof(T[0]) ~ 8B

short **U[6]; // sizeof(U[0]) ~ 8B

int V[8]; // sizeof(V[0]) ~ 4B

double *W[4]; // sizeof(W[0]) ~ 8B 

/*
Array   El Size     Total Size   Start Add.     Element i 

S           2           14             x_S          x_S + i*2
T           8           24             x_T          x_T + i*8
U           8           48              x_U         x_U + i*8
V           4           32              x_V         x_V + i*4
W           8           32              x_W         x_W + i*8


*/
