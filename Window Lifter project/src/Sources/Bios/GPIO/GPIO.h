/*******************************************************************************/
/**

\file       GPIO.h
\brief      Macro definitions for registers access and I/O handling
\author     Abraham Tezmol
\version    0.2
\date       09/05/2013
*/
/*******************************************************************************/

#ifndef _GPIO_H        /*prevent duplicated includes*/
#define _GPIO_H

/*-- Includes ----------------------------------------------------------------*/

/** Core modules */
/** MCU derivative information */
#include "MCU_derivative.h"
/** Variable types and common definitions */
#include "typedefs.h"

/*-- Variables ---------------------------------------------------------------*/

/*-- Types Definitions -------------------------------------------------------*/

/*-- Defines -----------------------------------------------------------------*/

#define LED1      					68
#define LED2       					69
#define LED3       					70
#define LED4        				71
#define LED_Blue       				10
#define LED_Green      				11
#define Push_Down					64
#define Push_Up						65
#define Push_Pinch					66

#define Go_Down   (SIU.GPDI[Push_Down].B.PDI)
#define Go_Up     (SIU.GPDI[Push_Up].B.PDI)
#define Go_Pinch  (SIU.GPDI[Push_Pinch].B.PDI)

#define Pressed 1
#define No_Pressed 0

#define GPIO_INPUT					0
#define GPIO_OUTPUT					1

#define GPIO_OPEN_DRAIN_DISABLE		0
#define GPIO_OPEN_DRAIN_ENABLE		1

/*-- Macros ------------------------------------------------------------------*/
/* Indicator LEDs handling */

/** Set LED */ 
#define LED_ON(channel)                     (SIU.GPDO[channel].B.PDO =  1)
/** Clear LED */ 
#define LED_OFF(channel)                    (SIU.GPDO[channel].B.PDO =  0)
/** Toggle LED */ 
#define LED_TOGGLE(channel)                 (SIU.GPDO[channel].B.PDO ^= 1) 


/*-- Function Prototypes -----------------------------------------------------*/

void vfnGPIO_Init_channel(uint8_t channel, uint8_t input_output, uint8_t Open_drain);
void vfnGPIO_Output(uint8_t channel, uint8_t logical_value);
void vfnGPIO_FlashMainLED(void);
void vfnGPIO_LED_Init(void);
void vfnGPIO_Push_Init(void);

#endif /* _GPIO_H */

/*******************************************************************************/
