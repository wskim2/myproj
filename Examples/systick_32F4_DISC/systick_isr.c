#include <stm32f4xx.h>                       /* STM32F103 definitions         */
#include <stm32f407xx.h> 

#if 1
/*----------------------------------------------------------*/
void wait (void)  {
  int  d;

  for (d = 0; d < 2000000; d++);             /* only to delay for LED flashes */
}


/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/


void delay(uint8_t *pdata, uint8_t bit)
{
	uint8_t mask = *pdata & bit;
	
	while(mask == (*pdata & bit))
	{
		wait();
	}
}
/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
int race_cond (void) {
  uint8_t data=10;                            /* LED variable                  */
  uint8_t *pdata = &data;
	
	delay(pdata, 1);
	
	return 1;
}
#endif

volatile uint32_t msTicks = 0;                              /* Variable to store millisecond ticks */
  
void SysTick_Handler(void)  {                               /* SysTick interrupt Handler. */
  msTicks++;    	/* See startup file startup_LPC17xx.s for SysTick vector */ 
  LED_On(0U);                                // Switch LED on
  wait();
  LED_Off(0U);                                // Switch LED on

	//led_onOff();
}
  
int main (void)  {
  uint32_t returnCode;
 
  LED_Initialize ();                    // Initialize LEDs

  returnCode = SysTick_Config(SystemCoreClock / 1000);      /* Configure SysTick to generate an interrupt every millisecond */
  
  if (returnCode != 0)  {                                   /* Check return code for errors */
    // Error Handling 
  }
  
  while(1);
}
