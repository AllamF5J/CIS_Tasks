/* 
 * File   :  mcal_std_types.h
 * Author :  Ahmed Allam
 *
 * Created on April 18, 2024, 5:44 PM
 */

#ifndef _MCAL_STD_TYPES_H_
#define	_MCAL_STD_TYPES_H_

/* ********************** Includes Section Start ********************** */
#include "std_libraries.h"
#include "compiler.h"
/************************  Includes Section End  ********************** */

/* ************************ Macro Section Start *********************** */
#define STD_HIGH   0x01
#define STD_LOW    0x00

#define CONFIG_ENABLE 0x01
#define CONFIG_DISABLE 0x00

#define STD_ON     0x01
#define STD_OFF    0x00

#define STD_ACTIVE 0x01
#define STD_IDLE   0x00

#define E_OK      (Std_ReturnType)0x01
#define E_NOT_OK  (Std_ReturnType)0x00
/*************************** Macro Section End ************************ */

/* **************** Macro Functions Declarations Start **************** */
/******************* Macro Functions Declarations End ***************** */

/* ***************** Global Declaration Section Start ***************** */
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;

typedef uint8 Std_ReturnType;
/******************** Global Declaration Section End ****************** */

/* ************** Sub-Program Declarations Section Start ************** */
/***************** Sub-Program Declarations Section End *************** */

#endif	//!_MCAL_STD_TYPES_H_