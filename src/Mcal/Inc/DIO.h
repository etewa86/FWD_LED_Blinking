/**
 *  \file   DIO.h
 *  \brief  This file contains the function declarations and data structures
 *          corresponding to the gpio.
 *   \date   Nov 17, 2022
 *
 *   \author Mohammed Etewa
 */


#ifndef DIO_H_
#define DIO_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "Port.h"
#include "sysctrl.h"
/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */
/** \brief  values for the RGB led on portF.*/
#define RGB_RED      0x02
#define RGB_BLUE     0x04
#define RGB_GREEN    0x08
#define RGB_YELLOW   0x0A
#define RGB_SKYBLUE  0x0C
#define RGB_WHITE    0x0E
#define RGB_PINk     0x06
/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Structure holding interrupt configurations.*/
typedef struct gIntCfg{
	gInterrSenseControl_t interruptSense;
	uint8 priority;
	uint8 pendingFlag;
	g_ISRVirIdx_t interruptIndex;
	uint8 enableInterrupt;

}gIntCfg_t;

/** \brief structure holding the GPIO pin object.*/
typedef struct gpioIns{
	uint8 pin_num;
	/**< GPIO pin number.*/
	uint32 base;
	/**< GPIO port :
	 *        -# BASE_A
	 *        -# BASE_B
	 *        -# BASE_C
	 *        -# BASE_D
	 *        -# BASE_E
	 *        -# BASE_F          */
	uint8 dir;
	/**< Pin direction :
	 *          -# INPUT
	 *          -# OUTPUT
	 *          */
	gConfigPad_t configPadObj;
	/**< GPIO pin configuration structure.*/

	gIntCfg_t interruptObj;

}gGPIOObj_t;
/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \name   initPin
 *
 *  \brief  perform GPIO pin digital initializations.
 *
 *  \param  obj Pointer to the GPIO object.
 *
 *  \retVal Value of the enumeration gGPIOError_t
 * */
void initPin(gGPIOObj_t *obj);



/**
 *  \name   digitalPinWrite
 *
 *  \brief  write values to a GPIO pin.
 *
 *  \param  obj Pointer to the GPIO object.
 *  \param  val the value to be written to the GPIO pin.
 *          val can take one of two values :
 *              -# HIGH
 *              -# LOW
 *
 *  \retVal Value of the enumeration gGPIOError_t
 * */
void digitalPinWrite(gGPIOObj_t *obj , uint8 val);


/**
 *  \name   digitalPinRead
 *
 *  \brief  Reads the value of a GPIO pin.
 *
 *  \param  obj Pointer to the GPIO object.
 *  \param  data a pointer that holds the pin value.

 *  \retVal Value of the enumeration gGPIOError_t
 * */
void digitalPinRead(gGPIOObj_t *obj , uint8 *data);





#endif /*DIO_H_ */
