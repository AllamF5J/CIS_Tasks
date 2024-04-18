/* 
 * File   :  Application.h
 * Author :  Ahmed Allam
 *
 * Created on April 18, 2024, 5:59 PM
 */

#ifndef _APPLICATION_H_
#define	_APPLICATION_H_

/* ********************** Includes Section Start ********************** */
#include "ECU_Layer/LED/ecu_led.h"
/************************  Includes Section End  ********************** */

/* ************************ Macro Section Start *********************** */
#define SELF_LATC_REG ((volatile SELF_LATC *)0xF8B)
#define __delay_ms(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000.0)))
/*************************** Macro Section End ************************ */

/* **************** Macro Functions Declarations Start **************** */
/* ***************** Macro Functions Declarations End ***************** */

/* ***************** Global Declaration Section Start ***************** */
/******************** Global Declaration Section End ****************** */

/* ************** Sub-Program Declarations Section Start ************** */
Std_ReturnType application_initalize();
/***************** Sub-Program Declarations Section End *************** */


#endif //!_APPLICATION_H_