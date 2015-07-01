/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %main.c%
* Instance:         RPL_1
* %version:         1 %
* %created_by:      uid02495 %
* %date_created:    Jun 30 14:38:03 2014 %
*=============================================================================*/
/* DESCRIPTION : main C file                                                  */
/*============================================================================*/
/* FUNCTION COMMENT : This file sontains the main functions of ths system     */
/* and it calls periodically our dummy function                               */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  |                               | Mr. Template     */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */	

#include "MCU_derivative.h"


/** GPIO funtion prototypes  */
#include    "GPIO.h"
#include    "PIT.h"
#include    "dummy.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */
/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */

/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/


/****************************************************************************************************
* Declaration of module wide FUNCTIONs 
*****************************************************************************************************/

void disableWatchdog(void) 
{
  SWT.SR.R = 0x0000c520;     /* Write keys to clear soft lock bit */
  SWT.SR.R = 0x0000d928; 
  SWT.CR.R = 0x8000010A;     /* Clear watchdog enable (WEN) */
}


/*****************************************************************************************************
* Definition of global wide MACROs / #DEFINE-CONSTANTs
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/


/******************************************************************************************************
* Definition of module wide VARIABLEs 
******************************************************************************************************/


 
/******************************************************************************************************
* Code of module wide FUNCTIONS
******************************************************************************************************/



/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : main
 *  Description          : Main function with PIT to call our interrupt function every 1ms
 *  Parameters           : 
 *  Return               :
 *  Critical/explanation :    Yes. Main Function
 **************************************************************/
 
 /**************************************************************
 *  Name                 : BackgroundSubsystemTasks
 *  Description          : Background subsystem 
 *  Parameters           : 
 *  Return               :
 *  Critical/explanation :    No
 **************************************************************/


/*~~~~~~~ Main Code ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/



int main(void) 

{
T_UBYTE j;



   
	initModesAndClock();
	/* Disable Watchdog */
	disableWatchdog();
	/*Initialize LEDs on TRK-MPC560xB board */
 		vfnGPIO_LED_Init();	
 		 vfnGPIO_Push_Init();
	/*Initialize Interrupts */
	INTC_InitINTCInterrupts();
	/*Initialize Exception Handlers */
	EXCEP_InitExceptionHandlers();
	
	/*turning on led bar */
	for (j =0; j<10;j++)
	{
		LED_ON (j);
	}
	

	/*turning off green and blue leds*/
	LED_OFF (LED_Green);
	LED_OFF (LED_Blue);
	
	PIT_device_init();
    PIT_channel_configure(PIT_CHANNEL_0 , dummy_1ms);	
    PIT_channel_start(PIT_CHANNEL_0);
    
    
    
    
    /* Enable External Interrupts*/
    enableIrq();
	/* Infinite loop */
	
	for (;;) 
	{
	
       
	}
}

/*~~~~~~~ End of Main Code ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


