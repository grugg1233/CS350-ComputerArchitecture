/*
 1) Write evenOnes(unsigned x): return 1 if even number of 1 bits. No loops/conditionals

*/

int evenOnes(unsigned x) {
    //assumes 32 bit integers
    int p = sizeof(unsigned) * 8;
    x ^= (x>>(p/2)); 
    x ^= (x>>(p/4)); 
    x ^= (x>>(p/8)); 
    x ^= (x>>(p/16)); 
    return x & 1; 
}

/* 
2) Write addOK(int x, int y): return 1 if x+y does not overflow
*/

int addOK(int x , int y) {
    long z = (long) x + (long) y; 
    int o = x + y; 
    if (z == (long) o) {
        return 1; 
    }
    return 0;
}

/* 
3) Write getByte(int x, int n): return byte n (0 = LSB)

*/

int getByte(int x, int n) {
    return x & (0xFF << n); 
}

/*
4) Write isPowerOfTwo(unsigned x)
*/

int isPowerOfTwo(unsigned x) {
    int moreThanOne = 0;
    if (x == 0) return 0; 
    for (int i = 0 ; i < 32; i++) {
        if ( ((x & (1<<i)) >> i) == 1)  moreThanOne+=1;
    }
    if (moreThanOne == 1) return 1; 
    return 0;
}

// 5) Write logicalShift(int x, int n): logical right shift

int logicalShift(int x, int n) {
    return (unsigned) x >> n; 
}

// 6) Write absVal(int x) using bit operations only
#include <limits.h>
unsigned absVal(int x) {
// 1000 -> -8 I need it to be 8 so 
unsigned r;
if (x > 0) return x;
if (x == INT_MIN) {
    return  (unsigned) x; 

}

// 1001 -> -7 : 0111 -> 7
// 0010  
// 1011 -> -5 : 0101 -> 5 
// 1011 -> 11 - 6 0110  
// 
return (unsigned) x - (x << 1);
} 

/*
7) Write isNegative(int x): return 1 if x < 0
*/

int isNegative (int x) {
    if (x < 0) return 1; 
    return 0;
}

/*
8) Write rotateLeft(unsigned x, int n).
*/
unsigned rotateLeft(unsigned x, int n) {
    // 1111 1010 << n : apply a "rotation" so maintain all the bits but shift the order 
    // bind to max rot val
    int rot = n % 32 ;
    // 1111 1010 << 2 -> 1110 1011
    // i: 0->2, 1->3, 2->4 , ... 6-> 0 ,7-> 1 
    //     0 + rot % 8 = 2 % 8 = 2                             7+rot % 8 =  9 % 8 = 1 
    unsigned a = 0; 
    for(int i = 0; i < 32; i++) {
        int idx = (i+rot) % 32;
        a |= ((x & (1<<i)) >> idx); 
    }
    return a;
}

/*
9) Write greater(short x, short y): compare bits 4–7
*/

int greater(short x, short y){
// 0000 0000 0000 0000
//           ^^^^

    return ((x & 0x00f0) > (y & 0x00f0)); 

}

/*
10) Write sign(int x): return -1, 0, or 1
*/
int sign(int x) {
    if (x==0) return 0; 
    else if (x<0) return -1;
    return 1; 
}

/*
11) Write bitCount(unsigned x): count 1 bits (no loops)
*/

int bitCount(unsigned x) {
    
}


//12) Write fitsBits(int x, int n): return 1 if x fits in n bits.
int fitsBits(int x, int n){
    //111 -> max = 7 if 8 you need 4 bits 
    //max representable value by n bits is 2^n - 1
    int max;
    for (int i = 1; i <=n ; i++) max*=2;
    max -= 1; 
    if (x > max) return 0; 
    return 1; 
}


/* 
13) Write isDenormal(unsigned uf)
*/
int isDenormal(unsigned uf) {
// s eeeeeeee ffffffffffffffffffffff
// 31 30       23 22                     0

if (((uf & (0xff << 23)) >> 23) == 0 ) return 1; 
return 0;

}

/*
14) Write floatSign(unsigned uf): return 1 if negative float
*/
int floatSign(unsigned uf) {
// s eeeeeeee ffffffffffffffffffffff
// 31 30       23 22                     0

if ((uf & (1 << 31)) != 0 ) return 1; 
return 0;

}

/*
15) Write isTmax(int x).
*/
#include <limits.h>
isTmax(int x) {
    if (x == INT_MAX) return 1; 
    return 0;
}