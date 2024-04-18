/* 
 * File:    hal_gpio.c
 * Author:  Ahmed Allam
 *
 * Created on April 18, 2024, 5:36 PM
 */

#include "hal_gpio.h"

volatile uint8 *tris_registers[] = { &TRISA, &TRISB, &TRISC, &TRISD, &TRISE };
volatile uint8 *lat_registers[] = { &LATA, &LATB, &LATC, &LATD, &LATE };
volatile uint8 *port_registers[] = { &PORTA, &PORTB, &PORTC, &PORTD, &PORTE };

/**
 * Initializes the direction of a GPIO pin.
 * 
 * @param _pin_config: Pointer to the pin configuration structure.
 * 
 * @return: Status of the operation (E_OK or E_NOT_OK).
 */
#if GPIO_PORT_PIN_CONFIGRATIONS == CONFIG_ENABLE
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config)
{
    Std_ReturnType retVal = E_OK;
    
    if((NULL != _pin_config) || (_pin_config->pin < PORT_PIN_MAX_NUMBER))
    {
        switch(_pin_config->direction)
        {
            case GPIO_DIRECTION_OUTPUT:
                CLR_BIT(*tris_registers[_pin_config->port], _pin_config->pin);
                break;
            case GPIO_DIRECTION_INPUT:
                SET_BIT(*tris_registers[_pin_config->port], _pin_config->pin);
                break;

            default:
                retVal = E_NOT_OK;
                break;
        }  
    }
    else
    {
        retVal = E_NOT_OK;
    }

    return retVal;
}
#endif

/**
 * Retrieves the direction status of a GPIO pin.
 * 
 * @param _pin_config: Pointer to the pin configuration structure.
 * @param direction_status: Pointer to store the direction status.
 * 
 * @return: Status of the operation (E_OK or E_NOT_OK).
 */
#if GPIO_PORT_PIN_CONFIGRATIONS == CONFIG_ENABLE
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status)
{
    Std_ReturnType retVal = E_OK;
    
    if(NULL != _pin_config || NULL != direction_status || (_pin_config->pin < PORT_PIN_MAX_NUMBER))
    {
        *direction_status = READ_BIT(*tris_registers[_pin_config->port], _pin_config->pin);
    }
    else
    {
       retVal = E_NOT_OK; 
    }
    
    return retVal; 
}
#endif

/**
 * Writes logic to a GPIO pin.
 * 
 * @param _pin_config: Pointer to the pin configuration structure.
 * @param logic: The logic value to write (GPIO_LOW or GPIO_HIGH).
 * 
 * @return: Status of the operation (E_OK or E_NOT_OK).
 */
#if GPIO_PORT_PIN_CONFIGRATIONS == CONFIG_ENABLE
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic)
{
    Std_ReturnType retVal = E_OK;
    
    if(NULL != _pin_config || (_pin_config->pin < PORT_PIN_MAX_NUMBER))
    {
     switch(logic)
        {
            case GPIO_LOW:
                CLR_BIT(*lat_registers[_pin_config->port], _pin_config->pin);
                break;
            case GPIO_HIGH:
                SET_BIT(*lat_registers[_pin_config->port], _pin_config->pin);
                break;

            default:
                retVal = E_NOT_OK;
                break;
        }   
    }
    else
    {
       retVal = E_NOT_OK; 
    }
    
    return retVal;   
}
#endif

/**
 * Reads logic from a GPIO pin.
 * 
 * @param _pin_config: Pointer to the pin configuration structure.
 * @param logic: Pointer to store the read logic value.
 * 
 * @return: Status of the operation (E_OK or E_NOT_OK).
 */
#if GPIO_PORT_PIN_CONFIGRATIONS == CONFIG_ENABLE
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic)
{
    Std_ReturnType retVal = E_OK;
    
    if(NULL != _pin_config || NULL != logic || (_pin_config->pin < PORT_PIN_MAX_NUMBER))
    {
        *logic = READ_BIT(*port_registers[_pin_config->port], _pin_config->pin);
    }
    else
    {
       retVal = E_NOT_OK; 
    }
    
    return retVal;   
}
#endif

/**
 * Toggles logic of a GPIO pin.
 * 
 * @param _pin_config: Pointer to the pin configuration structure.
 * 
 * @return: Status of the operation (E_OK or E_NOT_OK).
 */
#if GPIO_PORT_PIN_CONFIGRATIONS == CONFIG_ENABLE
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config)
{
    Std_ReturnType retVal = E_OK;
    
    if(NULL != _pin_config || (_pin_config->pin < PORT_PIN_MAX_NUMBER))
    {
        TOG_BIT(*lat_registers[_pin_config->port], _pin_config->pin);
    }
    else
    {
       retVal = E_NOT_OK; 
    }
    
    return retVal;  
}
#endif

/**
 * Initializes a GPIO pin based on the provided pin configuration.
 * 
 * @param _pin_config: Pointer to the pin configuration structure.
 * 
 * @return: Status of the pin initialization operation (E_OK if successful, E_NOT_OK otherwise).
 */
#if GPIO_PORT_PIN_CONFIGRATIONS == CONFIG_ENABLE
Std_ReturnType gpio_pin_intialize(const pin_config_t *_pin_config)
{
    Std_ReturnType retVal = E_OK;
    
    if(NULL != _pin_config || (_pin_config->pin < PORT_PIN_MAX_NUMBER))
    {
        retVal = gpio_pin_direction_intialize(_pin_config);
        retVal = gpio_pin_write_logic(_pin_config, _pin_config->logic);
    }
    else
    {
        retVal = E_NOT_OK; 
    }
    
    return retVal;
}
#endif

/**
 * Initializes the direction of a GPIO port.
 * 
 * @param port: Index of the port.
 * @param direction: Direction to set for the port (GPIO_DIRECTION_OUTPUT or GPIO_DIRECTION_INPUT).
 * 
 * @return: Status of the operation (E_OK or E_NOT_OK).
 */
#if GPIO_PORT_CONFIGRATIONS == CONFIG_ENABLE
Std_ReturnType gpio_port_direction_intialize(port_index_t port, uint8 direction)
{
    Std_ReturnType retVal = E_OK;

    if(port < PORT_MAX_NUMBER)
    {
        *tris_registers[port] = direction;
    }
    else
    {
        retVal = E_NOT_OK;
    }
    
    return retVal;  
}
#endif

/**
 * Retrieves the direction status of a GPIO port.
 * 
 * @param port: Index of the port.
 * @param direction_status: Pointer to store the direction status.
 * 
 * @return: Status of the operation (E_OK or E_NOT_OK).
 */
#if GPIO_PORT_CONFIGRATIONS == CONFIG_ENABLE
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status)
{
    Std_ReturnType retVal = E_OK;

    if(NULL != direction_status || port < PORT_MAX_NUMBER)
    {
        *direction_status = *tris_registers[port];
    }
    else
    {
        retVal = E_NOT_OK;
    }
    
    return retVal; 
}
#endif

/**
 * Writes logic to a GPIO port.
 * 
 * @param port: Index of the port.
 * @param logic: The logic value to write (0 or 1).
 * 
 * @return: Status of the operation (E_OK or E_NOT_OK).
 */
#if GPIO_PORT_CONFIGRATIONS == CONFIG_ENABLE
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic)
{
    Std_ReturnType retVal = E_OK;

    if(port < PORT_MAX_NUMBER)
    {
        *lat_registers[port] = logic;
    }
    else
    {
        retVal = E_NOT_OK;
    }
    
    return retVal; 
}
#endif

/**
 * Reads logic from a GPIO port.
 * 
 * @param port: Index of the port.
 * @param logic: Pointer to store the read logic value.
 * 
 * @return: Status of the operation (E_OK or E_NOT_OK).
 */
#if GPIO_PORT_CONFIGRATIONS == CONFIG_ENABLE
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic)
{
    Std_ReturnType retVal = E_OK;
    
    if(NULL != logic || port < PORT_MAX_NUMBER)
    {
        *logic = *lat_registers[port];
    }
    else
    {
       retVal = E_NOT_OK; 
    }
    
    return retVal;   
}
#endif

/**
 * Toggles logic of a GPIO port.
 * 
 * @param port: Index of the port.
 * 
 * @return: Status of the operation (E_OK or E_NOT_OK).
 */
#if GPIO_PORT_CONFIGRATIONS == CONFIG_ENABLE
Std_ReturnType gpio_port_toggle_logic(port_index_t port)
{
    Std_ReturnType retVal = E_OK;
    
    if(port < PORT_MAX_NUMBER)
    {
        *lat_registers[port] ^= PORTC_MASK;
    }
    else
    {
       retVal = E_NOT_OK; 
    }
    
    return retVal;   
}
#endif