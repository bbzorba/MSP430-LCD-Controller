//******************************************************************************
//  ELE 417 - EMBEDDED SYSTEM DESIGN
//  TERM PROJECT - 2018/2019
//
//  BARIS BERK ZORBA
//  ENGIN GURHAN
//
//******************************************************************************
#include <msp430.h>
#include "Hposition.h"
#include "Hletter.h"
#include "Hnumbers.h"

void LcdFrst(void);
void LcdReset(void);


int main( void )
{
    WDTCTL = WDTPW | WDTHOLD;                                  // Stop watchdog timer

    // Configure XT1 oscillator
    P4SEL0 |= BIT1 | BIT2;                                     // P4.2~P4.1: crystal pins

    // Calibration of a inputs
    P2OUT &= ~BIT7;
    P2REN |= BIT7;

    P2OUT &= ~BIT5;
    P2REN |= BIT5;

    P1OUT &= ~BIT5;
    P1REN |= BIT5;

    P4DIR |= LED_Accept;
    P4OUT &= ~LED_Accept;

    P1DIR |= LED_Denied;
    P1OUT &= ~LED_Denied;

    do
    {
        CSCTL7 &= ~(XT1OFFG | DCOFFG);                         // Clear XT1 and DCO fault flag
        SFRIFG1 &= ~OFIFG;
    }while (SFRIFG1 & OFIFG);                                  // Test oscillator fault flag
    CSCTL6 = (CSCTL6 & ~(XT1DRIVE_3)) | XT1DRIVE_2;            // Higher drive strength and current consumption for XT1 oscillator


    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;

    // Configure LCD pins
    SYSCFG2 |= LCDPCTL;                                        // R13/R23/R33/LCDCAP0/LCDCAP1 pins selected

    LCDPCTL0 = 0xFFFF;
    LCDPCTL1 = 0x07FF;
    LCDPCTL2 = 0x00F0;                                         // L0~L26 & L36~L39 pins selected

    LCDCTL0 = LCDSSEL_0 | LCDDIV_7;                            // flcd ref freq is xtclk

    // LCD Operation - Mode 3, internal 3.08v, charge pump 256Hz
    LCDVCTL = LCDCPEN | LCDREFEN | VLCD_6 | (LCDCPFSEL0 | LCDCPFSEL1 | LCDCPFSEL2 | LCDCPFSEL3);

    LCDMEMCTL |= LCDCLRM;                                      // Clear LCD memory

    LCDCSSEL0 = 0x000F;                                        // Configure COMs and SEGs
    LCDCSSEL1 = 0x000F;                                        // L0, L1, L2, L3: COM pins
    LCDCSSEL2 = 0x0000;

    LCDM0 = 0x21;                                              // L0 = COM0, L1 = COM1
    LCDM1 = 0x84;                                              // L2 = COM2, L3 = COM3

while(1){
    __delay_cycles(10000);
    LcdFrst();

    if((P2IN & BIT7) != 0)
    {

        LCDMEM[pos1] = letter[1];
        LCDMEM[pos2] = letter[1];
        LCDMEM[pos3] = 0x0C;
        LCDMEM[pos4] = numbers[1];
        LCDMEM[pos5] = numbers[0];
        LCDMEM[pos6] = numbers[1];
        P4OUT ^= LED_Accept;
        __delay_cycles(10000);
        P4OUT ^= LED_Accept;

    }

    if((P2IN&BIT5) != 0)
    {
        LCDMEM[pos1] = letter[4];
        LCDMEM[pos2] = letter[4];
        LCDMEM[pos3] = 0x0C;
        LCDMEM[pos4] = numbers[1];
        LCDMEM[pos5] = numbers[0];
        LCDMEM[pos6] = numbers[1];
        P4OUT ^= LED_Accept;
        __delay_cycles(10000);
        P4OUT ^= LED_Accept;
    }

    if((P1IN & BIT5) != 0)
      {
          LCDMEM[pos1] = letter[25];
          LCDMEM[pos2] = letter[25];
          LCDMEM[pos3] = 0x0C;
          LCDMEM[pos4] = letter[25];
          LCDMEM[pos5] = letter[25];
          LCDMEM[pos6] = letter[25];
          P1OUT ^= LED_Denied;
          __delay_cycles(10000);
          P1OUT ^= LED_Denied;
      }


    LCDCTL0 |= LCD4MUX | LCDON;                                // Turn on LCD, 4-mux selected

    PMMCTL0_H = PMMPW_H;                                       // Open PMM Registers for write
    PMMCTL0_L |= PMMREGOFF_L;                                  // and set PMMREGOFF

}
    __bis_SR_register(LPM3_bits | GIE);                        // Enter LPM3.5
    __no_operation();                                          // For debugger

}

void LcdFrst(void){

       LCDMEM[pos1] = letter[4];
       LCDMEM[pos2] = letter[11];
       LCDMEM[pos3] = 0x6F;
       LCDMEM[pos4] = numbers[4];
       LCDMEM[pos5] = numbers[1];
       LCDMEM[pos6] = numbers[7];

}
void LcdReset(void){

       LCDMEM[pos1] = 0x00;
       LCDMEM[pos2] = 0x00;
       LCDMEM[pos3] = 0x00;
       LCDMEM[pos4] = 0x00;
       LCDMEM[pos5] = 0x00;
       LCDMEM[pos6] = 0x00;

}
