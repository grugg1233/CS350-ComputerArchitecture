#include <math.h>
#include <stdio.h> 
#include <string.h> 

//def: B2T(x) = -xsub(w-1) * 2 ^(w-1) + SUM(i= 0 -> w-2) [xsub(i)* 2^(i)] 

int B2T(char* x) {
    int y;
    return y; 
}

unsigned B2U(char* x) {
    unsigned y = 0; 
    int len = strlen(x);
    for(int i = 0; i < len; i++) {
        y = (y << 1) | (x[i] - '0');
    }
    return y;
}

T2B(int x) {
    char* y; 
    return y;
}

char* U2B(unsigned x ) {
    char * y;
    return y;
}

char* T2B(int x) {
    char* y; 
    return y;
}

unsigned T2U(int x){
    unsigned y; 
    return y;
}

void main( ) {

    char* x = "00000000000000000000000000000001";
    unsigned y = B2U(x);
    printf("%u", y);

}