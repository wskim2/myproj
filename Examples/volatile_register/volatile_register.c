/*----------------------------------------------------------------------------
 * Name:    Blinky.c
 * Purpose: LED Flasher
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2012 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <stm32f10x.h>                       /* STM32F103 definitions         */

/*----------------------------------------------------------------------------
  wait function
 *----------------------------------------------------------------------------*/
void wait (void)  {
  int  d;

  for (d = 0; d < 2000000; d++);             /* only to delay for LED flashes */
}


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
int main (void) {
  uint8_t data=10;                            /* LED variable                  */
  uint8_t *pdata = &data;
	
	delay(pdata, 1);
}
