/*
 * main.c
 */
#include "DIO.h"
gGPIOObj_t PIN;
#include "SysTick.h"
#define ON_Time         2000    //Set ON time in ms
#define OFF_Time        1000    //Set OFF time in ms
uint8 data;

//uint32 DIMMING=100*ON_Time;
uint32 cnt=0;  
int main(void) {
	PIN.base = BASE_F;
	PIN.dir = OUTPUT;
	PIN.pin_num=3;
	initPin(&PIN);
	SysTick_Init();

 while(1);	
	

	return 0;
}


void SysTick_Handler(void)
{
	if(cnt<=ON_Time)
	{
	 digitalPinWrite(&PIN ,HIGH);
		cnt ++;
	}
	else if(cnt<=(ON_Time+OFF_Time))
	{
	 digitalPinWrite(&PIN ,LOW);
		cnt ++;
	}
	else if(cnt>(ON_Time+OFF_Time))
	cnt=0;

}
