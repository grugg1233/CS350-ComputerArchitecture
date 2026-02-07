//problem 2.5
#include <stdio.h>

typedef unsigned char *byte_pointer; 

void show_B(byte_pointer B , size_t s) {
    for (int i = 0; i < s ; i++ ){
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
    int val = 0x87654321;  
    byte_pointer valp = (byte_pointer) &val;
    show_B(valp, 1); 
    show_B(valp, 2); 
    show_B(valp, 3); 
    
}

//problem 2.6

/*
write 0x00359141 in binary 
0000 0000 0011 0101 1001 0001 0100 0001

write 0x4a564504 in binary
0100 1010 0101 0110 0100 0101 0000 0100

how many max bits match when shifted 

00000000001101011001000101000001
 01001010010101100100010100000100  

1 0101 1001 0001 0100 0001
Longest string of matching bits 41 / 64 bits

what parts of the strings dont match

First 2 B of float and last 2 bit

*/

//problem 2.7

/* 
what would be the result of the following 
#include <string.h> 
const char * s = "abcdef";
show_bytes((byte_pointer) s, strlen(s)) ; 

note that letters 'a' - 'z' have ascii codes 0x61 - 0x7a 

  a  b  c  d  e  f  

0x 61 62 63 64 65 66

if you pass strlen(s) + 1 it will include \0 

*/

//problem 2.8

/*
    01101001
    01010101

~a  10010110
~b  10101010
a&b 01000001
a|b 01111101
a^b 00111100

*/

//problem 2.9 

/*

R G B color
0 0 0 black 
0 0 1 blue 
0 1 0 green 
0 1 1 cyan 
1 0 0 red 
1 0 1 magenta 
1 1 0 yellow 
1 1 1 white 

a) what is the complement of each color 
~black = white 
~blue = yellow 
~green = magenta 
~cyan = red 

and this is reciprocal 

b)
blue | green = cyan (mixing)
yellow & cyan = green (common color)
red ^ magenta = blue (subtraction)
*/


//problem 2.10

/*

void inplace_swap(int* x, int* y) {
    *y ^= *x  
    *x ^= *y;
    *y ^= *x;
}

say x = a = 5 = 0101
    y = b = 9 = 1001
    
1. y = y ^ x : y = 1100
2. x = x ^ y : x = 1001 
3. y = y ^ x : y = 0101
after: 
y = 5, x = 9 
*/

//problem 2.11 

/*
    void swap(int *a, int *b) {
        *a^=*b;*b^=*a;*a^=*b;
    }
    void reverse(int a[], int c) {
        for (int i = 0, j = c-1 ; i <= j; i++ , j--) {
            swap(&a[i], &a[j]);
        }
    }

    void main() {
        int a[] = {1,2,3,4,5}; 
        int len = sizeof(a) / sizeof(a[0]);   
        reverse(a , len);
        for (int i = 0 ; i < 4; i++)
            printf("%d", a[i]);
    }
    behaves as expected for even array lengths however, when array len is odd: 
    => 5402 

    we can fix this behavior by doing the following : 
    void reverse(int a[], int c) {
    for (int i = 0, j = c-1 ; i <= j; i++ , j--) {
        if (i==j) continue;
        printf("swap\n");
        swap(&a[i], &a[j]);
    }
}
*/

//problem 2.12

/*
  a) write a c expression that 0's out all of x except its least significant Byte (w independent ):   x & 0xff 
  b) get the complement of all but the LSB of x : ~x ^ (x & 0xFF)
c) lsb set to all ones all other unchanged: x | 0xff
*/

// problem 2.13 skipped but I believe it involves nesting bis and bic calls to solve 

//Problem 2.14

/*

    assume x = 0x66 y = 0x39 fill in the following 

    x&y -> 0x20
    x| y -> 0x7f
    ~x | ~y ->0xcf
    x & !y ->  0x00 b/c y is initially non 0 so logical not ! will turn it to 0 and & on 0x00 will return 0x00     
    x && y -> 0x01
    x || y -> 0x01
    !x || !y -> 0x00
    x && ~y -> 0x01 
*/


// problem 2.15 
/*
write a c expr for x == y: 

!(x ^ y)


*/