/* 
 * File   :  ecu_led.h
 * Author :  Ahmed Allam
 *
 * Created on April 18, 2024, 5:54 PM
 */

#ifndef _ECU_LED_H_
#define	_ECU_LED_H_

/* ********************** Includes Section Start ********************** */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_led_cfg.h"
/************************  Includes Section End  ********************** */

/* ************************ Macro Section Start *********************** */
/*************************** Macro Section End ************************ */

/* **************** Macro Functions Declarations Start **************** */
/* ***************** Macro Functions Declarations End ***************** */

/* ***************** Global Declaration Section Start ***************** */
typedef enum
{
    LED_OFF,
    LED_ON
            
} led_status_t;

typedef struct
{
    uint8 port_name : 4;
    uint8 pin : 3;
    uint8 led_status : 1;
    
} led_t;
/******************** Global Declaration Section End ****************** */

/* ************** Sub-Program Declarations Section Start ************** */
Std_ReturnType led_initialize(const led_t *led);
Std_ReturnType led_turn_on(const led_t *led);
Std_ReturnType led_turn_off(const led_t *led);
Std_ReturnType led_turn_toggle(const led_t *led);
/***************** Sub-Program Declarations Section End *************** */

#endif	//!_ECU_LED_H_