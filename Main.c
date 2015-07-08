#include <stdint.h>
#include "..//inc//tm4c123gh6pm.h"
#include "Nokia5110.h"
#include "Random.h"
#include "TExaS.h"
#include "ADC.h"
/*

Buttons
UP: PE0
RIGHT: PE1
DOWN: PE2
LEFT: PE3
FIX: PE4

*/






void SysTick_Init(unsigned long period){
	NVIC_ST_CTRL_R = 0;         // disable SysTick during setup
  NVIC_ST_RELOAD_R = period-1;// reload value
  NVIC_ST_CURRENT_R = 0;      // any write to current clears it
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x40000000;           
  NVIC_ST_CTRL_R = 0x07; // enable SysTick with core clock and interrupts
}

