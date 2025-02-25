#include <xc.h>
#include "timer0.h"
#include "pps.h"

/* Config Timer0 */
void TIMER0_Initialize(void)
{
   
	/* Timer0 disabled; 16-bit; no postscaler */
	T0CON0 = 0x10;
    
    /* HFINTOSC; counter not synchronized; prescaler 1:256 */
	T0CON1 = 0x78;   
}

void TIMER0_Delay(void)
{
	
	/* Load TMR0 with initial value 0BDB(hex) = 3035(dec) */
    /* TIMER0_time = (1/TMR0_clock_source) x (end_value - initial_value) x prescaler */
    /*             = (1/64MHz ) x (65535-3035) x 256 = 250 ms */
	TMR0H = 0x0B;
	TMR0L = 0xDB;

    /* Timer0 enabled */
	T0CON0 |= 0x80; 
                 
    /* Wait for TMR0IF = 1 */
    while ((PIR3 & 0x80) != 0x80)
          ;
        
    /* Clear TMR0IF bit */
    PIR3 &= 0x7F;
             
    /* Timer0 disabled */
	T0CON0 &= 0x7F;
}

void TIMER0_Delay_1s(void)
{
	PPS_unlock();
    RC7PPS = 0x39;
    PPS_lock();
    
	/* Load TMR0 with initial value 0BDB(hex) = 3035(dec) */
    /* TIMER0_time = (1/TMR0_clock_source) x (end_value - initial_value) x prescaler */
    /*             = (1/64MHz ) x (65535-3035) x 1024 = 1000 ms */
	TMR0H = 0x0B;
	TMR0L = 0xDB;

    /* Timer0 enabled, Timer0 as 16-bit */
	T0CON0 |= 0x90; 
    
    /* HFINTOSC; counter not synchronized; prescaler 1:1024 */
	T0CON1 = 0x7A;   
                 
    /* Wait for TMR0IF = 1 */
    while ((PIR3 & 0x80) != 0x80)
          ;
        
    /* Clear TMR0IF bit */
    PIR3 &= 0x7F;
             
    /* Timer0 disabled */
	//T0CON0 &= 0x7F;
}