
#include <stdio.h>

typedef unsigned char *byte_pointer; 

void show_B(byte_pointer B , size_t s) {
    for (int i = 0 ; i < s ; i++ ){
        printf("%.2x\n", B[i]);
    }
    printf("\n");
}

void show_int(int x ) {
    show_B((byte_pointer)&x, sizeof(int)); 
}

void show_float(float x ) {
    show_B((byte_pointer)&x, sizeof(int)); 
}

void show_p(void * x) {
    show_B((byte_pointer)&x, sizeof(int));
}

void test(unsigned val) {
    int ival = val; 
    float fval = (float) val;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_p(pval);
}

void main() {
    test(12345U);

    
}