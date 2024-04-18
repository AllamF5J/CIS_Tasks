/*
 * File   :  Application.c
 * Author :  Ahmed Allam
 *
 * Created on April 18, 2024, 5:21 PM
 */

#include "Application.h"

pin_config_t red_led = 
{
    .port = PORTC_INDEX,
    .pin = GPIO_PIN0,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_HIGH
};

pin_config_t yellow_led = 
{
    .port = PORTC_INDEX,
    .pin = GPIO_PIN1,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_HIGH
};

pin_config_t green_led = 
{
    .port = PORTC_INDEX,
    .pin = GPIO_PIN2,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_HIGH
};

Std_ReturnType retVal = E_NOT_OK;
direction_t led_st;

int main() 
{   
    retVal = application_initalize();
    
    while(1)
    {
        retVal = gpio_pin_write_logic(&green_led, GPIO_LOW);
        retVal = gpio_pin_write_logic(&red_led, GPIO_HIGH);
        __delay_ms(1000);
        //______________________________________________
        
        retVal = gpio_pin_write_logic(&red_led, GPIO_LOW);
        retVal = gpio_pin_write_logic(&yellow_led, GPIO_HIGH);
        __delay_ms(1000);
        //______________________________________________
        
        retVal = gpio_pin_write_logic(&yellow_led, GPIO_LOW);
        retVal = gpio_pin_write_logic(&green_led, GPIO_HIGH);
        __delay_ms(1000);
    }
     
    return (EXIT_SUCCESS);
}

Std_ReturnType application_initalize()
{
    Std_ReturnType retVal = E_OK;
    
    retVal = gpio_pin_direction_intialize(&red_led);
    retVal = gpio_pin_direction_intialize(&yellow_led);
    retVal = gpio_pin_direction_intialize(&green_led);
    
    return retVal;
}