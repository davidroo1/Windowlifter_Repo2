/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %dummy.c%
* Instance:         RPL_1
* %version:         1 %
* %created_by:      uid734144 %
* %date_created:    Tue Jun  30 10:38:03 2015 %
*=============================================================================*/
/* DESCRIPTION : dummy c contains the required functions for all processes    */
/*============================================================================*/
/* FUNCTION COMMENT : dummy_1ms function is called every 1 ms by the PIT      */
/* and runs the main state machine for the window lifter . Opening and        */
/* closing functions contain the process to be emulated.                      */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  |                               | Mr. Template     */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Core modules */
/** Variable types and common definitions */
#include "typedefs.h"

/** Own headers */
#include "dummy.h"

/* GPIO routines prototypes */ 
#include "GPIO.h"

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */
#define Leds_Count0 0
#define Leds_Count10 10
#define Leds_Count9 9
#define Button_Validation 10
#define Time_Count0 0
#define Pace_Restart 0

/* WORD constants */
#define Pace_Count400 400
#define Pace_Count401 401
#define Time_Count500 500
#define AntiPinch_TimeLimit 5000

/* LONG and STRUCTURE constants */

	enum e_STATE 
{
	None,
	Window_Up_Manual,
	Window_Up_Auto,
	Window_Down_Manual,
	Window_Down_Auto,
	Pinch
	
	
};

/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */
T_UBYTE rub_Read_State =None;
T_SBYTE rsb_Led_Counter = Leds_Count9;



/* WORD RAM variables */
T_UWORD ruw_Time_Counter=Time_Count0;
T_UWORD ruw_Pace_Counter=Pace_Count400;
T_UWORD x;
/* LONG and STRUCTURE RAM variables */

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */



/* Exported functions prototypes */
/* ----------------------------- */

/* Inline functions */
/* ---------------- */ 
 

/**************************************************************
 *  Name                 : opening_func
 *  Description          : Fuction emulates opening window by turning off leds
 *  Parameters           :  None
 *  Return               :   None
 *  Critical/explanation :     No
 **************************************************************/



void opening_func ()  /*Fuction emulates opening window by turning off leds*/
{
	
	LED_OFF (rsb_Led_Counter);
	rsb_Led_Counter--;
	ruw_Pace_Counter=Pace_Restart;
	
}

/**************************************************************
 *  Name                 : closing_func
 *  Description          : Fuction emulates closing window by turning on leds
 *  Parameters           :  None
 *  Return               :   None
 *  Critical/explanation :     No
 **************************************************************/

void closing_func ()    /*Fuction emulates closing window by turning on leds*/
{
	
	LED_ON (rsb_Led_Counter);
	rsb_Led_Counter++;
	ruw_Pace_Counter=Pace_Restart;
	
}

/**************************************************************
 *  Name                 : dummy_1ms
 *  Description          : Fuction is called every 1ms and contains our main state machine
 *  Parameters           :  None
 *  Return               :   None
 *  Critical/explanation :     No
 **************************************************************/
 
/*main function called every 1ms, contains all processes of the state machine*/
void dummy_1ms(void)  
{


switch (rub_Read_State)
{
	case None : 
	LED_OFF (LED_Green);
	LED_OFF (LED_Blue);
	ruw_Pace_Counter=Pace_Count401;
		if ((Go_Down==Pressed ) &&(rsb_Led_Counter>=Leds_Count0)) 
		{
			if ((ruw_Time_Counter>Button_Validation) && (Go_Down==Pressed)) 
			{
				rub_Read_State = Window_Down_Auto;
					LED_ON (LED_Green);
			}
			else ruw_Time_Counter++;
		}
		if ((Go_Up==Pressed ) &&(rsb_Led_Counter<Leds_Count9)) 
		{
			if ((ruw_Time_Counter>Button_Validation) && (Go_Up==Pressed)) 
			{
				rub_Read_State = Window_Up_Auto;
				LED_ON (LED_Blue);
			}
			else ruw_Time_Counter++;
		}
			
			if ((Go_Down==No_Pressed)&&(Go_Up==No_Pressed))
			{
			ruw_Time_Counter=Time_Count0;
			rub_Read_State=None;
			}
	
        break;

	case Window_Down_Auto : 
	
		
				if ((Go_Down==No_Pressed)&&(ruw_Time_Counter<Time_Count500))
				{
					
					if (ruw_Pace_Counter>Pace_Count400)
					{
					opening_func();
					}
					else ruw_Pace_Counter++;
					rub_Read_State=Window_Down_Auto;
				}
			
	if(Go_Down==Pressed)
	{
		
		ruw_Time_Counter++;
		if ((Go_Down==Pressed ) &&(ruw_Time_Counter>Time_Count500))
		{
			rub_Read_State = Window_Down_Manual;
			
		}
	}
		if(rsb_Led_Counter<Leds_Count0) 
		{
		rub_Read_State=None;
		rsb_Led_Counter=Leds_Count0;
		}
		break;
	
	
	case Window_Down_Manual :
        if (Go_Down==Pressed )
        {
	        if ((ruw_Pace_Counter>Pace_Count400)&&(rsb_Led_Counter>=Leds_Count0))
			{
				opening_func();
			}
	        else ruw_Pace_Counter++;
        }
        if (Go_Down==No_Pressed)
        {
        	rub_Read_State = None;
        	rsb_Led_Counter++;
        }
        
	    break;
	    
   case Window_Up_Auto : 
	
		
				if ((Go_Up==No_Pressed)&&(ruw_Time_Counter<Time_Count500))
				{
						
					if (ruw_Pace_Counter>Pace_Count400)
					{
					closing_func();
					}
					else ruw_Pace_Counter++;
				rub_Read_State=Window_Up_Auto;
					 
					             if(Go_Pinch == Pressed)
								{
										rub_Read_State=Pinch;
										
								}
				}
				
					
	
		
			
	if(Go_Up==Pressed)
	{
		ruw_Time_Counter++;
		if ((Go_Up==Pressed ) &&(ruw_Time_Counter>Time_Count500))
		{
			rub_Read_State = Window_Up_Manual;
			
		}
	}
		if(rsb_Led_Counter>Leds_Count9) 
		{
			rub_Read_State=None;
			rsb_Led_Counter=Leds_Count9;
		}
		
	
		break;
	
	case Window_Up_Manual :
		if (Go_Up==Pressed )
        {
	        if ((ruw_Pace_Counter>Pace_Count400)&&(rsb_Led_Counter<Leds_Count10))
			{
			closing_func();
			}
	        else ruw_Pace_Counter++;
        }
        if (Go_Up==No_Pressed)
        {
        	  rub_Read_State=None;
        	  rsb_Led_Counter--;
        }
       
        
	    break;
	 
	case Pinch :
	LED_OFF(LED_Blue);
	LED_OFF(LED_Green);
	

    if ((ruw_Pace_Counter>Pace_Count400)&&(rsb_Led_Counter>=Leds_Count0))
			{
				opening_func();
			}
	        else ruw_Pace_Counter++;
   if (rsb_Led_Counter <Leds_Count0)
   {
   	 if(x>AntiPinch_TimeLimit)   	 
   	 rub_Read_State= None;
   	 else 
   	 {
   	 	rub_Read_State = Pinch;
   	 	x++;
  	 }
   }
   
}
}



