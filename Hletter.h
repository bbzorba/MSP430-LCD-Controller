/*
 * Hletter.h
 *
 *  Letter Version of the arrays
 *
 */
#include <msp430.h>

#ifndef HLETTER_H_
#define HLETTER_H_

#define A 0xEF
#define B 0xFF
#define CC 0x9C
#define D 0xFC
#define E 0x9F
#define F 0x8F
#define G 0xBF
#define H 0x6F
#define I 0x0C
#define J 0x70
#define K 0x00
#define L 0x1C
#define M 0x00
#define NN 0x2B
#define o 0x3B
#define P 0xCF
#define q 0xE7
#define r 0x0B
#define S 0xB7
#define t 0x1F
#define U 0x7C
#define VV 0x00
#define W 0x00
#define y 0x67
#define ZZ 0xDB
#define TT 0x03

const char letter[26] =
{
    A,  //---> 0
    B,  //---> 1
    CC,  //---> 2
    D,  //---> 3
    E,  //---> 4
    F,  //---> 5
    G,  //---> 6
    H,  //---> 7
    I,  //---> 8
    J,  //---> 9
    K,  //---> 10
    L,  //---> 11
    M,  //---> 12
    NN,  //---> 13
    o,  //---> 14
    P,  //---> 15
    q,  //---> 16
    r,  //---> 17
    S,  //---> 18
    t,  //---> 19
    U,  //---> 20
    VV,  //---> 21
    W,  //---> 22
    y,  //---> 23
    ZZ,  //---> 24
    TT

};

#endif /* HLETTER_H_ */
