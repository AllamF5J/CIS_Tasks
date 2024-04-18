/* 
 * File   :  hal_gpio.h
 * Author :  Ahmed Allam
 *
 * Created on April 18, 2024, 5:36 PM
 */

#ifndef _HAL_GPIO_H_
#define	_HAL_GPIO_H_

/* ********************** Includes Section Start ********************** */
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "hal_gpio_cfg.h"
/************************  Includes Section End  ********************** */

/* ************************ Macro Section Start *********************** */
#define BIT_MASK  (uint8)1
#define PORT_PIN_MAX_NUMBER 8 
#define PORT_MAX_NUMBER     5 
#define PORTC_MASK          0xFF
/*************************** Macro Section End ************************ */

/* **************** Macro Functions Declarations Start **************** */
#define HWREG8(_X)     (*((volatile uint8 *)(_X)))

#define SET_BIT(REG, BIT_POS)  (REG |=  (BIT_MASK << BIT_POS))
#define CLR_BIT(REG, BIT_POS)  (REG &= ~(BIT_MASK << BIT_POS))
#define TOG_BIT(REG, BIT_POS)  (REG ^=  (BIT_MASK << BIT_POS))

#define READ_BIT(REG, BIT_POS) ((REG >> BIT_POS) & BIT_MASK)
/* ***************** Macro Functions Declarations End ***************** */

/* ***************** Global Declaration Section Start ***************** */
typedef union
{
    struct
    {
        unsigned SELF_LATC0 : 1;
        unsigned SELF_LATC1 : 1;
        unsigned SELF_LATC2 : 1;
        unsigned SELF_LATC3 : 1;
        unsigned SELF_LATC4 : 1;
        unsigned SELF_LATC5 : 1;
        unsigned SELF_LATC6 : 1;
        unsigned SELF_LATC7 : 1;
    };
    
    uint8_t LATC_REGISTER;
    
} SELF_LATC;

typedef enum 
{
    GPIO_PIN0 = 0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
            
} pin_index_t;

typedef enum 
{
    GPIO_LOW = 0,
    GPIO_HIGH
            
} logic_t;

typedef enum
{
    GPIO_DIRECTION_OUTPUT = 0,
    GPIO_DIRECTION_INPUT
            
} direction_t;

typedef enum
{
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
            
} port_index_t;

typedef struct 
{
    uint8_t port : 3;       /* @ref port_index_t */
    uint8_t pin : 3;        /* @ref pin_index_t */
    uint8_t direction : 1;  /* @ref direction_t */
    uint8_t logic : 1;      /* @ref logic_t */    
    
} pin_config_t;
/******************** Global Declaration Section End ****************** */

/* ************** Sub-Program Declarations Section Start ************** */
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status);
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config);
Std_ReturnType gpio_pin_intialize(const pin_config_t *_pin_config);

Std_ReturnType gpio_port_direction_intialize(port_index_t port, uint8 direction);
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status);
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic);
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic);
Std_ReturnType gpio_port_toggle_logic(port_index_t port);
/***************** Sub-Program Declarations Section End *************** */

#endif	//!_HAL_GPIO_H_