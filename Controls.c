#include <stdint.h>
#include "inc//tm4c123gh6pm.h"

// **************Controls_Init*********************
// Initialize controls inputs, called once 
// Input: none 
// Output: none
void Controls_Init(void){
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOE; // activate port E
  int x =1;
	x= x+1; // allow time to finish activating
	x = x+1;
	x = x+1;
	
	
  GPIO_PORTE_DIR_R &=~ 0x3B;      // make PE4-0 out

  GPIO_PORTE_AFSEL_R &= ~0x3B;   // disable alt funct on PE4-0
	GPIO_PORTE_AMSEL_R &= ~0x3B;      // no analog on PE4-0
  GPIO_PORTE_PCTL_R &= ~0x0000FFFF; // regular function
  GPIO_PORTE_DEN_R |= 0x3B;      // enable digital I/O on PE4-0
}

void ControlsD_Init(void){unsigned long delay;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOD; // activate port E
  int x =1;
	x= x+1; // allow time to finish activating
	x = x+1;
	x = x+1;
	
	
  GPIO_PORTD_DIR_R &=~ 0x3B;      // make PE4-0 out
  GPIO_PORTD_AFSEL_R &= ~0x3B;   // disable alt funct on PE4-0
	GPIO_PORTD_AMSEL_R &= ~0x3B;      // no analog on PE4-0
  GPIO_PORTD_PCTL_R &= ~0x0000FFFF; // regular function
  GPIO_PORTD_DEN_R |= 0x3B;      // enable digital I/O on PE4-0
}

// **************Controls_In*********************
// Input from joystick key inputs 
// Input: none 
// Output: 0 to 7 depending on keys
// 0x01 is just Key0, 0x02 is just Key1, 0x04 is just Key2
uint32_t Controls(void){
	uint32_t inputs;
	inputs = (0x3B & GPIO_PORTE_DATA_R);		//get inputs of piano
  return inputs;
}

uint32_t ControlsD(void){
	uint32_t inputs;
	inputs = (0x3B & GPIO_PORTD_DATA_R);
	return inputs;
}

