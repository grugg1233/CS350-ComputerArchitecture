#include <stdio.h> 

int div16(int x) {
    //divide by 16 === right shift  ln2(16) = 4
    x >>= 4; 
    return x; 
}

void main() {
    printf("32/16: %d , -32/16: %d, 4/16: %d", div16(32), div16(-32), div16(4));
}