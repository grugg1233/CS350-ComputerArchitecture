/*
2.57 ◆
Write procedures show_short, show_long, and show_double that print the byte
representations of C objects of types short int, long int, and double, respec
tively. Try these out on several machines

*/
#include <stdio.h> 

typedef unsigned char *byte_pointer; 

void show_bytes(byte_pointer start,int len) {
        for (int i = 0 ; i < len ; i++) {
            printf("%.2x" , start[i]);
        }
        printf("\n"); 
}

void show_short(short x) {
    show_bytes((byte_pointer) &x, sizeof(short));
}

void show_long(long x) {
    show_bytes((byte_pointer) &x, sizeof(long));
}

void show_double(double x) {
    show_bytes((byte_pointer) &x, sizeof(double));
}

/*
2.58 ◆◆
Write a procedure is_little_endian that will return 1 when compiled and run
on a little-endian machine, and will return 0 when compiled and run on a big
endian machine. This program should run on any machine, regardless of its word
size 
*/


int is_little_endian() {
    unsigned x = 1U; 
    return *((unsigned char*) &x); 
}


int is_big_endian() {   
    unsigned x = 1U; 
    return !(*((unsigned char*) &x)); 
}

/*
2.59 ◆◆
Write a C expression that will yield a word consisting of the least significant
byte of x, and the remaining bytes of y. For operands x = 0x89ABCDEF and y =
0x76543210, this would give 0x765432EF
*/

//  (LSB_x) | (MSB_y)
int f(int x, int y){int r = (x & 0xFF) | (y & 0xFFFFFF00);
return r;}

/*
2.60 ◆◆
Suppose we number the bytes in a w-bit word from 0 (least significant) to w/8−1
(most significant). Write code for the following C function, which will return an
unsigned value in which byte i of argument x has been replaced by byte b:
unsigned replace_byte (unsigned x, int i, unsigned char b);
Here are some examples showing how the function should work:
replace_byte(0x12345678, 2, 0xAB)--> 0x12AB5678
replace_byte(0x12345678, 0, 0xAB)--> 0x123456AB
*/

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    // byte i of x replaced by b 
    x &= ~(0xFF << (i<<3));          
    return x | ((unsigned) b << (i<<3));
}


/*

2.61 ◆◆
WriteCexpressionsthatevaluateto1 when thefollowingconditionsaretrue, and
to 0 when they are false. Assume x is of type int.
A. Anybit of x equals 1.
B. Anybit of x equals 0.
C. Anybit in the least significant byte of x equals 1.
D. Anybit in the most significant byte of x equals 0.
Your code should follow the bit-level integer coding rules (page 120), with the
additional restriction that you may not use equality (==) or inequality (!=) tests
*/

int function(int x){
    int lsbContainsOne = !(!((x & 0xFF) ^ 0));  //-> all zeros in the LSB this will give 0 otherwise it will return 1
    int msbContainsZero = !(!((((unsigned) x >> (3<<3)) & 0xFF) ^ 0xFF)); // returns 0 if MSB of x is all 1's  and 0 otherwise
    int anyBitOne = !(!(x ^ 0)) ; // returns 0 if x is all 0s and 1 otherwise 
    int anyBitZero = !(!(x ^ (-1U))) ; // returns 0 if x is all 1s and 1 otherwise 

    return lsbContainsOne && anyBitOne && anyBitZero && msbContainsZero; 
}

//4 expressions in c as the question actually asked 
void c( int x ) {
    int any1bits =  !!(x);  //if x is 0 this returns 0 if x is not 0 this returns 1
    // x = 0011 
    // ~x= 1100
    // ! ~x = 0 
    // ! 0 = 1 
    // x = 1111 
    // ~x = 0000 
    // ! 0 = 1 
    // !1 =0  
    int any0bits = !!(~x); // if x is all ones return 0 else return 1 
    
    int lsbhas1 = !!((x & 0xFF) ^ 0); 
    int shift = ((sizeof(int) << 3) - 8);
    // this first masks all but the msb of x 
    // x: 1100 1010 000...0
    // 11111.1 1100 1010 
    // 00....0 1111 1111  & 
    // 000...0 1100 1010 
    //         1111 1111 ^ 


    
    // then we take 
    int msbhas0 = !!((((x & (0xFF << shift)) >> shift) & 0xFF) ^ 0xFF) ;
}

/* 
2.62 ◆◆◆
Write a function int_shifts_are_arithmetic() that yields 1 when run on a
machine that uses arithmetic right shifts for int’s, and 0 otherwise. Your code
shouldworkonamachinewithanywordsize.Testyourcodeonseveralmachines.
*/

int int_shifts_are_arithmetic() {
    int check = -1;

    return !((check >> 2) ^ check); 

}



// 2.64 ◆
// Write code to implement the following function:
// /* Return 1 when any odd bit of x equals 1; 0 otherwise.
// Assume w=32. */
// int any_odd_one(unsigned x);
// Your function should follow the bit-level integer coding rules (page 120), except
// that you may assume that data type int has w =32 bits.


int any_odd_one(unsigned x) { 
    // this is ugly but ... 
    // position 1, 3, 5 , 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31
    int y = 0;
    y |= (((x & (1 << 1))) | ((x & (1 << 3))) | ((x & (1 << 5)) ) | ((x & (1 << 7)) )| 
((x & (1 << 9)) ) | ((x & (1 << 11)) ) | ((x & (1 << 13)) ) | ((x & (1 << 15)) ) |((x & (1 << 17)) )
| ((x & (1 << 19)) ) | ((x & (1 << 21)) ) | ((x & (1 << 23)) ) | ((x & (1 << 25)) ) | ((x & (1 << 27)) ) | 
((x & (1 << 29)) ) | ((x & (1u << 31)) ) );  
    return !!(y) ;

}

int any_odd_one(unsigned x) { 
    return !!(x & 0xAAAAAAAA);
}

// 2.65 ◆◆◆◆
// Write code to implement the following function:
// /* Return 1 when x contains an odd number of 1s; 0 otherwise.
// Assume w=32. */
// int odd_ones(unsigned x);
// Your function should follow the bit-level integer coding rules (page 120), except
// that you may assume that data type int has w =32 bits.
// Yourcodeshouldcontainatotalofatmost12arithmetic, bit-wise, andlogical
// operations


int odd_ones(unsigned x) {
    x ^= x >> 16; 
    x ^= x >> 8; 
    x ^= x >> 4; 
    x ^= x >> 2; 
    x ^= x >> 1; 
    return x & 1; 
}


// 2.66 ◆◆◆
// Write code to implement the following function:
// /*
// * Generate mask indicating leftmost 1 in x. Assume w=32.
// * For example 0xFF00-> 0x8000, and 0x6600--> 0x4000.
// *Ifx=0, then return 0.
// */
// int leftmost_one(unsigned x);
// Your function should follow the bit-level integer coding rules (page 120), except
// that you may assume that data type int has w =32 bits.
// Yourcodeshouldcontainatotalofatmost15arithmetic, bit-wise, andlogical
// operations.
// Hint: First transform x into a bit vector of the form [0 ...011...1].

int leftmost_one(unsigned x) {

    // I will use the property that highest order byte can be found via highest order number of necessary bits 
    // I can then shift that down to the bottom to get the hexadecimal value for it and using that I can figure 
    // out the bit pattern at the top 

    // 0000 0000 0010 1100 -> 32+12 =46 
    //m: 0x0020
    // max representable in 1B : 2^8 -1 = 0xFF 
    // max representable in 2B : 2^16 -1 = 0xFFFF
    //etc... 
    // so I need to figure out that we are in a specific range then filter that B 

    // I can't use comparison or conditionals. 
    // But I can create boolean statements : x ^ 0xFF == x 
    //                                       x ^ 0xFFFF == x ...  then figure out when this breaks and go back one level 
    // figure out the shift by testing this dynamically 

    // check if the msb has a 1 - if so we can skip all the following and find the mask 
    unsigned msbhas1 = x & (0xFF << 24u); // return 0 if MSB is all 0 otherwise it returns the pattern we want
    msbhas1 |= msbhas1>>1;
    msbhas1 |= msbhas1>>2;
    msbhas1 |= msbhas1>>4;
    msbhas1 -= (msbhas1 >> 1); 
    unsigned msbhas1CompNext = !msbhas1; // need to fix : but this should be 0 if msbhas1 != 0 
    unsigned b3has1 = x & (0xFF << 16u) ;  
    b3has1 |= b3has1>>1;
    b3has1 |= b3has1>>2;
    b3has1 |= b3has1>>4;
    b3has1 -= (b3has1 >> 1); 
    unsigned b3has1CompNext = !b3has1; 
    unsigned b2has1 = x & (0xFF << 8u);
    b2has1 |= b2has1>>1;
    b2has1 |= b2has1>>2;
    b2has1 |= b2has1>>4; 
    b2has1 -= (b2has1 >> 1); 
    unsigned b2has1CompNext = !b2has1; 
    unsigned b1has1 = x & (0xFF); 
    b1has1 |= b1has1>>1;
    b1has1 |= b1has1>>2;
    b1has1 |= b1has1>>4;
    b1has1 -= (b1has1 >> 1); 
    unsigned b1has1CompNext = !b1has1; 
    int y = 0;
    y |= ( msbhas1 |( b3has1 & msbhas1CompNext) | ( b2has1 & b3has1CompNext) | ( b1has1 & b2has1CompNext));
    return y; 

}

int leftmost_one(unsigned x) { 
    x |= x >>1; 
    x |= x >>2;
    x |= x >>4;
    x |= x >>8;
    x |= x >>16;    
    return x - (x>>1); 
}