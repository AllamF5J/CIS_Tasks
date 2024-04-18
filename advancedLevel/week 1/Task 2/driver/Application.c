/*
 * File   :  Application.c
 * Author :  Ahmed Allam
 *
 * Created on April 18, 2024, 5:21 PM
 */

#include "Application.h"

pin_config_t led_1 = 
{
    .port = PORTC_INDEX,
    .pin = GPIO_PIN0,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_HIGH
};

pin_config_t led_2 = 
{
    .port = PORTC_INDEX,
    .pin = GPIO_PIN1,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_HIGH
};

pin_config_t led_3 = 
{
    .port = PORTC_INDEX,
    .pin = GPIO_PIN2,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_HIGH
};

pin_config_t led_4 = 
{
    .port = PORTC_INDEX,
    .pin = GPIO_PIN3,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_HIGH
};

pin_config_t led_5 = 
{
    .port = PORTC_INDEX,
    .pin = GPIO_PIN4,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_HIGH
};

pin_config_t led_6 = 
{
    .port = PORTC_INDEX,
    .pin = GPIO_PIN5,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_HIGH
};

pin_config_t led_7 = 
{
    .port = PORTC_INDEX,
    .pin = GPIO_PIN6,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_HIGH
};

pin_config_t led_8 = 
{
    .port = PORTC_INDEX,
    .pin = GPIO_PIN7,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_HIGH
};

Std_ReturnType retVal = E_NOT_OK;
direction_t led_st;

pin_config_t *array[] = { &led_1, &led_2, &led_3, &led_4, &led_5, &led_6, &led_7, &led_8 };

int main() 
{   
    retVal = application_initalize();
    
    while(1)
    {
        for(uint8_t i = 1; i <= 8; i++)
        {
            if(i <= 5)
            {
                retVal = gpio_pin_write_logic(array[i - 1], GPIO_HIGH);
                retVal = gpio_pin_write_logic(array[i + 2], GPIO_LOW);
            }
            else
            {
                retVal = gpio_pin_write_logic(array[i - 1], GPIO_HIGH);
                retVal = gpio_pin_write_logic(array[i - 6], GPIO_LOW);
            }
            __delay_ms(250);
        }
    }
   
    return (EXIT_SUCCESS);
}

Std_ReturnType application_initalize()
{
    Std_ReturnType retVal = E_OK;
    
    retVal = gpio_pin_direction_intialize(&led_1);
    retVal = gpio_pin_direction_intialize(&led_2);
    retVal = gpio_pin_direction_intialize(&led_3);
    retVal = gpio_pin_direction_intialize(&led_4);
    retVal = gpio_pin_direction_intialize(&led_5);
    retVal = gpio_pin_direction_intialize(&led_6);
    retVal = gpio_pin_direction_intialize(&led_7);
    retVal = gpio_pin_direction_intialize(&led_8);
    
    return retVal;
}