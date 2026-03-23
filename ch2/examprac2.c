/*
 1) Write evenOnes(unsigned x): return 1 if even number of 1 bits. No loops/conditionals

*/

int evenOnes(unsigned x) {
    // x is even num 1s 
    // 1111 1010 1010 1010 1111 1010 1010 1010 
    // 0000 0000 0000 0000 1111 1010 1010 1010  : x>>16  
//^=   1111 1010 1010 1010 0000 0000 0000 0000 : x 
//     0000 0000 1111 1010 1010 1010 0000 0000 : x >> 8 
//^=   1111 1010 0101 0000 1010 1010 0000 0000 : x 
//     0000 1111 1010 0101 0000 1010 1010 0000  : x >> 4
//^=   1111 0101 1111 0101 1010 0000 1010 0000 : x 
//     0011 1101 0111 1101 0110 1000 0010 1000 : x >> 2
//^=   1100 1000 1000 1000 1100 1000 1000 1000 : x 
//     0110 0100 0100 0100 0110 0100 0100 0100 : x >> 1
//^=   1010 1100 1100 1100 1010 1100 1100 1100 : x 
// &   0000 0000 0000 0000 0000 0000 0000 0001 : 1
// !   (0000 0000 0000 0000 0000 0000 0000 0000) : !0 : 1 


    // x is odd num 1s
    // 1111 1010 1010 1010 1111 1010 1010 1011 
    // 0000 0000 0000 0000 1111 1010 1010 1010  : x>>16  
//^=   1111 1010 1010 1010 0000 0000 0000 0001 : x 
//     0000 0000 1111 1010 1010 1010 0000 0000 : x >> 8 
//^=   1111 1010 0101 0000 1010 1010 0000 0001 : x 
//     0000 1111 1010 0101 0000 1010 1010 0000  : x >> 4
//^=   1111 0101 1111 0101 1010 0000 1010 0001 : x 
//     0011 1101 0111 1101 0110 1000 0010 1000 : x >> 2
//^=   1100 1000 1000 1000 1100 1000 1000 1001 : x 
//     0110 0100 0100 0100 0110 0100 0100 0100 : x >> 1
//^=   1010 1100 1100 1100 1010 1100 1100 1101 : x 
// &   0000 0000 0000 0000 0000 0000 0000 0001 : 1
// !   (0000 0000 0000 0000 0000 0000 0000 0001) : !1 : 0 



    x ^= x >> 16; 
    x ^= x >> 8; 
    x ^= x >> 4; 
    x ^= x >> 2; 
    x ^= x >> 1; 
    //x & 1 -> 0 if even 
    return !(x & 1); 
}

/* 
2) Write addOK(int x, int y): return 1 if x+y does not overflow
*/

int addOK(int x , int y) {
    int s = x+y;
    int sx = x >> 31 , sy = y >> 31 , ss = s >> 31;
    // return 0 if sx -, sy - , ss + 
    //             1      1     0 
    //         1    &    1 
    //          if sx +, sy +, ss -
    //              0    0      1
    //         1    &    1
    // return 1 if sx 0, sy 0, ss 0 
    //        0   0     0   0 
    //          0 & 0 
    return !((sx^ss) & (sy ss)); 

}

/* 
3) Write getByte(int x, int n): return byte n (0 = LSB)

*/

int getByte(int x, int n) {
    // 00000000 0000000 0000000 1111111 : n = 0 
    // 00000000 0000000 1111111 0000000 : n = 1
    int s = n * 8;  
    int m = 0xFF<<s; 
    return (x&m) >> s

}

/*
4) Write isPowerOfTwo(unsigned x)
*/

int isPowerOfTwo(unsigned x) {
    // we need to check if exactly one bit is active

    // ~1010 = 0101 : 10 -> 5 
    // ~0011 = 1100 : 3 -> 12  
    // ~1111 = 0000 : 15 -> 0 

    // d = 12 / 3 = 4 : x * d = ~x
    int d = (~x) / x;
    
    // Powers of 2
    // d  = 7/8 = 0 : x*d = 8*0 = 0 
    // ~1000 = 0111 : 8 -> 7 
    // ~0100 = 1011 : 4 -> 11  
    // ~0010 = 1101 : 2 -> 13 
    // ~0001  = 1110 : 1-> 14 

    return x == 0 ? 0 : ((d*x) == (~x));


}

// 5) Write logicalShift(int x, int n): logical right shift

int logicalShift(int x, int n) {
    return ((unsigned) x >> n) ;
}

// 6) Write absVal(int x) using bit operations only

unsigned absVal(int x) {
    // -x = ~x + 1
    // 0001 = 1110 + 1
    unsigned y;  
    // 1111 -> 0000 + 1
    // 1110 -> 0001 + 1 -> 0010
    // 1000 -> 0111 + 1 
    x < 0 ? y = (unsigned) ~x + 1: y = (unsigned) x; 
    return y; 
} 

/*
7) Write isNegative(int x): return 1 if x < 0
*/

int isNegative (int x) {
    int s = x >> 31 ; 
    return s & 1; 
}

/*
8) Write rotateLeft(unsigned x, int n).
*/
unsigned rotateLeft(unsigned x, int n) {
    // 5 : n 
    // 1111 1111 : x
    // x << 5 =       1110 0000 
    // x >> 8-5 = 3 : 0001 1111 
    //              |=1111 1111  
    return x << n | x >> ((sizeof(unsigned)*8) - n);
}

/*
9) Write greater(short x, short y): compare bits 4–7
*/

int greater(short x, short y){
    // bits 4-7 of 2 B 
    // 0000 0000 0000 0000
    //           7  4    0
    unsigned short m = 0xF << 4;
    unsigned short a = (( unsigned short )x & m) >> 4; 
    unsigned short b = (( unsigned short )y & m) >> 4; 
    return a > b;
}

/*
10) Write sign(int x): return -1, 0, or 1
*/
int sign(int x) {
    if (x == 0) return 0; 
    else if ( x < 0 ) return -1; 
    return 1; 
}

/*
11) Write bitCount(unsigned x): count 1 bits (no loops)
*/

int bitCount(unsigned x) {



}


//12) Write fitsBits(int x, int n): return 1 if x fits in n bits.
int fitsBits(int x, int n){
    //  n bits can fit values up to 2^n - 1
    // say n = 3 : max value is 7 
    // 1 << 3
    // 1000 - 1 = 0111 
    int m = (1 << n) - 1;
    return x <= m;
}


/* 
13) Write isDenormal(unsigned uf)
*/
int isDenormal(unsigned uf) {
    // 0/1 0000 0000 non-zero/zero
//    s=31 30  exp 23  22 frac   0
    // if the exp part is 0 then the number is denormalized

    int m = 0xFF << 23 ;
    int exp = ((uf & m) >> 23); 
    // if exp == 0 return 1 , else return 0 
    return !exp; 
}

/*
14) Write floatSign(unsigned uf): return 1 if negative float
*/
int floatSign(unsigned uf) {
    //not checking for nan 
    // 1 if neg 0 if pos 
    // return (uf >> 31) & 1; 

    int m = 0xFF << 23 ;
    int exp = ((uf & m) >> 23);
        // 0 if nan / inf 
    return (exp ^ 0xFF) & ((uf >> 31) & 1); 

}

/*
15) Write isTmax(int x).
*/
int isTmax(int x) {
    int neg = (x >> 31) & 1; 
    int max = ~(1 << 31); 
    // if neg 1 return 0 
        //  1   &    
    return !neg & !(x ^ max); 

}