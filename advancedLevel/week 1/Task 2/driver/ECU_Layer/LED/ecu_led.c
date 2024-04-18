/* 
 * File   :  ecu_led.c
 * Author :  Ahmed Allam
 *
 * Created on April 18, 2024, 5:54 PM
 */

#include "ecu_led.h"

/**
 * Initializes an LED by configuring its corresponding GPIO pin.
 * 
 * @param led: Pointer to the LED configuration structure.
 * 
 * @return: Status of the LED initialization operation (E_OK if successful, E_NOT_OK otherwise).
 */
Std_ReturnType led_initialize(const led_t *led)
{
    Std_ReturnType retVal = E_OK;
    
    if(NULL != led)
    {
        pin_config_t pin_obj = 
        { 
            .port = led->port_name, 
            .pin = led->pin,                   
            .direction = GPIO_DIRECTION_OUTPUT,
            .logic = led->led_status 
        };
        
        gpio_pin_intialize(&pin_obj);
    }
    else
    {
        retVal = E_NOT_OK;
    }
    
    return retVal;
}

/**
 * Turns on an LED by setting its logic level to HIGH.
 * 
 * @param led: Pointer to the LED configuration structure.
 * 
 * @return: Status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
Std_ReturnType led_turn_on(const led_t *led)
{
    Std_ReturnType retVal = E_OK;
    
    if(NULL != led)
    {
        pin_config_t pin_obj = 
        { 
            .port = led->port_name, 
            .pin = led->pin,                    
            .direction = GPIO_DIRECTION_OUTPUT,
            .logic = led->led_status 
        };
        
        gpio_pin_write_logic(&pin_obj, GPIO_HIGH);
    }
    else
    {
        retVal = E_NOT_OK;
    }
    
    return retVal;
}

/**
 * Turns off an LED by setting its logic level to LOW.
 * 
 * @param led: Pointer to the LED configuration structure.
 * 
 * @return: Status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
Std_ReturnType led_turn_off(const led_t *led)
{
    Std_ReturnType retVal = E_OK;
    
    if(NULL != led)
    {
        pin_config_t pin_obj = 
        { 
            .port = led->port_name, 
            .pin = led->pin,                  
            .direction = GPIO_DIRECTION_OUTPUT,
            .logic = led->led_status 
        };
        
        gpio_pin_write_logic(&pin_obj, GPIO_LOW);   
    }
    else
    {
        retVal = E_NOT_OK;
    }
    
    return retVal;
}

/**
 * Toggles the logic level of an LED (from HIGH to LOW or vice versa).
 * 
 * @param led: Pointer to the LED configuration structure.
 * 
 * @return: Status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
Std_ReturnType led_turn_toggle(const led_t *led)
{
    Std_ReturnType retVal = E_OK;
    
    if(NULL == led)
    {
        pin_config_t pin_obj = 
        { 
            .port = led->port_name, 
            .pin = led->pin, 
            .direction = GPIO_DIRECTION_OUTPUT,
            .logic = led->led_status 
        };
        
        gpio_pin_toggle_logic(&pin_obj);  
    }
    else
    {
        retVal = E_NOT_OK;
    }
    
    return retVal;
}