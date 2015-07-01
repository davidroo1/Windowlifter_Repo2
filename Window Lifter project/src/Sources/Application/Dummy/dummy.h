/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %template.h%
* Instance:         RPL_1
* %version:         1 %
* %created_by:      uid02495 %
* %date_created:    Tue Jun 30 13:41:01 2015 %
*=============================================================================*/
/* DESCRIPTION : Header dummy file                                            */
/*============================================================================*/
/* FUNCTION COMMENT : contains only symbols which are exported to internal    */
/* platform modules. This will not be delivered with the library              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  | SAR/SIF/SCN_xxx               | Mr. Template     */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/*#ifndef TEMPLATE_H                               /* To avoid double inclusion */
#define TEMPLATE_H


#ifndef _DUMMY_H        /*prevent duplicated includes*/
#define _DUMMY_H

/*-- Includes ----------------------------------------------------------------*/

/** Core modules */
/** Variable types and common definitions */

#include "typedefs.h"

/*-- Variables ---------------------------------------------------------------*/


/*-- Types Definitions -------------------------------------------------------*/


/*-- Defines -----------------------------------------------------------------*/


/*-- Function Prototypes -----------------------------------------------------*/

void Test(void);
void dummy_1ms (void);
void dummmy_endless_loop (void);
void Task_5ms (void);
void Task_10ms (void);
void Task_50ms (void);
void Task_100ms (void);


#endif /* _DUMMY_H */

/*******************************************************************************/
