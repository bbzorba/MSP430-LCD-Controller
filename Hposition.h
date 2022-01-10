/*
 * Hposition.h
 *
 *  General defines for main program.
 *
 */
#include <msp430.h>

#ifndef HPOSITION_H_
#define HPOSITION_H_

#define pos1 4                                                 // Digit A1 - L4
#define pos2 6                                                 // Digit A2 - L6
#define pos3 8                                                 // Digit A3 - L8
#define pos4 10                                                // Digit A4 - L10
#define pos5 2                                                 // Digit A5 - L2
#define pos6 18

extern const char letter[26];
extern const char numbers[10];

#define LED_Accept BIT0
#define LED_Denied BIT0

#endif /* HPOSITION_H_ */
