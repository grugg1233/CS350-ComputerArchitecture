#include <stdio.h> 


int div16(int x) {
    //divide by 16 === right shift  ln2(16) = 4
    x >>= 4; 
    return x; 
}


void main() {
    printf("32/16: %d , -32/16: %d, 4/16: %d", div16(32), div16(-32), div16(4));
}

/*
#define M 
#define N

int arith(int x, int y) {
    int result =0 ; 
    result = x*M + y/N; 
    return result; 
}


int optarith(int x, int y) {
    //what are the values of M and N if arith(x,y) = optimarith(x,y)
    // take y = 1111 1000 
    int t = x;  // 0000 0010 
    // 0000 0010 << 5 == 0100 0000 = 64 = 2^5 * 2
    x <<= 5 ; //Multiplication by 2^5
    // - x
    //011011 = 31
    x-=t; 
    if (y < 0) y+=7; // -8 + 7 = -1
    // y / 2^3 = y / 8 : 1111 1000 >> 3 -->  1111 1111 = -1
    y >>= 3; //arithmetic 
    return x+y;  // 64
//M =  31
// N = 8 

}

*/

