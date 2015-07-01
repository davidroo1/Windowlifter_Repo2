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

T_UBYTE Function1(T_UBYTE *rpub_U8Ptr)
{
	return (*rpub_U8Ptr);
}   

/*****************************************************************************************************
* Definition of global wide MACROs / #DEFINE-CONSTANTs
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/
    
T_UBYTE (*rpfu_PtrToFctn)(T_UBYTE *); /* Our pointer to function */ 

/******************************************************************************************************
* Definition of module wide VARIABLEs 
******************************************************************************************************/

 T_UBYTE rub_Var1 = 0xFA; 
 T_UBYTE rub_Var2; 
 T_UBYTE * rpub_PtrToU8;
 
/******************************************************************************************************
* Code of module wide FUNCTIONS
******************************************************************************************************/

void BackgroundSubsystemTasks(void);

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
	
        BackgroundSubsystemTasks();
	}
}

/*~~~~~~~ End of Main Code ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/* Background tasks related to Subsystem control */
void BackgroundSubsystemTasks(void) 
{
	rpub_PtrToU8 = &rub_Var1; /* We need to initialize the pointer to be used by our function invocation */

    rpfu_PtrToFctn = &Function1; /* Let's perform our deferencing procedure (initialization) */

    /* Let's first call our function through direct invocation */
    rub_Var2 = Function1(rpub_PtrToU8);
    
    /* Clear var2 in preparation to next invocation */
    rub_Var2 = 0;

    /* Now, perform invocation through our pointer */
    rub_Var2 = rpfu_PtrToFctn(rpub_PtrToU8);

    /* See, I told you, pointers to functions are FUN !! */;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


