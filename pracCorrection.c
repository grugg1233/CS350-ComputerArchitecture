/*
 1) Write evenOnes(unsigned x): return 1 if even number of 1 bits. No loops/conditionals

*/

int evenOnes(unsigned x) {
    //assumes 32 bit integers
    x ^= x >> 16;
    x ^= x >> 8; 
    x ^= x >> 4; 
    x ^= x >> 2; 
    x ^= x >> 1; 
    return !(x & 1);  
}

/* 
2) Write addOK(int x, int y): return 1 if x+y does not overflow
*/

int addOK(int x , int y) {
    int s = x+y ; 
    int sx = x >> 31, sy = y >> 31, ss = s>>31; 
    return !((sx^ss)&(sy^ss));
}

/* 
3) Write getByte(int x, int n): return byte n (0 = LSB)

*/

int getByte(int x, int n) {
    return (x & (0xFF << (n*8))) >> (n*8);  
}

/*
4) Write isPowerOfTwo(unsigned x)
*/

int isPowerOfTwo(unsigned x) {
    return x && !(x & (x-1)); 
}

// 5) Write logicalShift(int x, int n): logical right shift

int logicalShift(int x, int n) {
    return (unsigned) x >> n; 
}

// 6) Write absVal(int x) using bit operations only

unsigned absVal(int x) {
    int m = x>>31 ; 
    return ( x ^ m ) - m ; 
} 

/*
7) Write isNegative(int x): return 1 if x < 0
*/

int isNegative (int x) {
    return (x>>31)& 1;
}

/*
8) Write rotateLeft(unsigned x, int n).
*/
unsigned rotateLeft(unsigned x, int n) {
    return (x<<n) | (x >> (32-n)); 
}

/*
9) Write greater(short x, short y): compare bits 4–7
*/

int greater(short x, short y){
// 0000 0000 0000 0000
//           ^^^^

    unsigned a = ((unsigned)x >> 4) & 0xF; 
    unsigned b = ((unsigned) y >> 4) & 0xF ; 
    return a > b; 
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
    x = x - ((x>>1) & 0x55555555); 
    x = (x & 0x33333333) + ((x>>2) & 0x33333333);
    x = (x+ (x>>4)) & 0x0F0F0F0F; 
    x = x + (x>>8); x = x + (x>>16) ; 
    return x & 0x3f;
}


//12) Write fitsBits(int x, int n): return 1 if x fits in n bits.
int fitsBits(int x, int n){
    int s = 32 -n; 
    return (x << s >> s ) == x; 
}


/* 
13) Write isDenormal(unsigned uf)
*/
int isDenormal(unsigned uf) {
// s eeeeeeee ffffffffffffffffffffff
// 31 30       23 22                     0

if ((((uf & (0xff << 23)) >> 23) == 0 )&& ((uf & (0x7FFFFF)) != 0)) return 1; 
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
isTmax(int x) {
    return !((x+1)^~x) & !!(x+1); 
}