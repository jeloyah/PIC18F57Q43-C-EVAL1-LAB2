
#include <xc.h>
#include "main.h"
#include "clock.h"
#include "gpio.h"
#include "timer0.h"
#include "pps.h"

void main(void) {
    
    /* System Clock Initialization */
	CLOCK_Initialize();
    
    /* Config PortA */
    PortA_Initialize();
    
    /* Config PortB */
    PortB_Initialize();

    /* Config PortC */
    PortC_Initialize();
    
    /* Config PortD */
    PortD_Initialize();
    
    /* Config PortE */
    PortE_Initialize();
    
    /* Config PortF */
    PortF_Initialize();
    
    /* Config TIMER0 */
    TIMER0_Initialize();
    
    TIMER0_Delay_1s();
       
    /* infinite loop */
    while(1)
    {
         /* Is SW0 opened? */
        if (PORTB== 0x10)
        {
            
            /* Turn off LED0 */
            /* PORTFbits.RF3 = 1; */
            LATF = 0x0F;
        }
        
        /* else SW0 is closed */
        else
        {
            userLED();
                    
        }    
        
        
     } /* while */
        
    
    return;
} /* main*/


void userLED(void)
{
            LATF = 0x08;      
            TIMER0_Delay();        
            LATF = 0x00;        
            TIMER0_Delay();
            
            LATF = 0x08;      
            TIMER0_Delay();        
            LATF = 0x00;        
            TIMER0_Delay();
            
            LATF = 0x08;      
            TIMER0_Delay();        
            LATF = 0x00;        
            TIMER0_Delay();
}