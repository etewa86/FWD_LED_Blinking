/**
 *  \file   app_gpio.c
 *
 *  \param  Source file containing the GPIO IP related configuration functions.
 *         These functions will be called by example application.
 *
 *   \date   Nov 17, 2022
 *
 *   \author Mohammed Etewa
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "DIO.h"

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void initPin(gGPIOObj_t *obj){
	/**< Enable GPIO Clock*/
	if(obj->base == BASE_A){
		clockGating(GPIOA);
	}else if(obj->base == BASE_B){
		clockGating(GPIOB);
	}else if(obj->base == BASE_C){
		clockGating(GPIOC);
	}else if(obj->base == BASE_D){
		clockGating(GPIOD);
	}else if(obj->base == BASE_E){
		clockGating(GPIOE);
	}else if(obj->base == BASE_F){
		clockGating(GPIOF);
	}
	 portUnLock(obj->base,TRUE);
	pinCommit(obj->base,obj->pin_num,TRUE);
	setPinDir(obj->base,obj->pin_num,obj->dir);

	pinAlternateFunctionSel(obj->base,obj->pin_num,FALSE);
	pinAnalogModeSelect(obj->base,obj->pin_num,FALSE);
    pinAdcTrigger(obj->base,obj->pin_num,FALSE);
    pinSetPadConfig(obj->base,obj->pin_num,&(obj->configPadObj));
    pinDigitalEnable(obj->base,obj->pin_num,TRUE);
    pinAnalogModeSelect(obj->base,obj->pin_num,FALSE);
    GPIOPinControl(obj->base,obj->pin_num,0);
}



void digitalPinWrite(gGPIOObj_t *obj , uint8 val){
	gGPIOError_t state = PASS;
	state = writePin(obj->base,obj->pin_num,val);
}



void digitalPinRead(gGPIOObj_t *obj , uint8 *data){
	gGPIOError_t state = PASS;
	state = readPin(obj->base,obj->pin_num,data);
 }


