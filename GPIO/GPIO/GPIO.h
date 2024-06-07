/*
************************************************************************************************************************************

*****************************   author: Ahmed Dewidar

*****************************   Date: 12/10/2023

*****************************   Module: GPIO

*****************************   Layer: Mcal

************************************************************************************************************************************
*/

/****************************************************************************************************************************************
***************************************************************      guard the file to be included one time in file .c     ********************
*****************************************************************************************************************************************/
#ifndef GPIO_H_
#define GPIO_H_

/*****************************************************************************************************************************************
***************************************************************   included service files    *******************************************************
*****************************************************************************************************************************************/
#include"common_macros.h"
#include"std_types.h"

/*****************************************************************************************************************************************
***************************************************************   error status    *******************************************************
*****************************************************************************************************************************************/
typedef enum
{
    GPIO_ok,
    GPIO_NULL_PTR_ERROR,
    GPIO_PORT_ID_ERROR,
    GPIO_PIN_ID_ERROR,
    GPIO_PIN_MODE_ERROR,
    GPIO_PIN_SPEED_ERROR,
    GPIO_PIN_STATUS_ERROR,
    GPIO_ALTERNATE_FUNCTION_ERROR,
	GPIO_ALTERNATE_FUNCTION_CONFIGURE_ERROR,
	GPIO_CAN_ALTERNATE_FUNCTION_ERROR
}GPIO_errorStatus;

/*****************************************************************************************************************************************
***************************************************************   GPIO  Ports    ***********************************************************
*****************************************************************************************************************************************/
typedef enum
{
	GPIO_PORTA,
	GPIO_PORTB,
	GPIO_PORTC
}GPIO_port;

/*****************************************************************************************************************************************
***************************************************************GPIO pins**************************************************************
*****************************************************************************************************************************************/
typedef enum
{
	GPIO_PIN_00,
	GPIO_PIN_01,
	GPIO_PIN_02,
	GPIO_PIN_03,
	GPIO_PIN_04,
	GPIO_PIN_05,
	GPIO_PIN_06,
	GPIO_PIN_07,
	GPIO_PIN_08,
	GPIO_PIN_09,
	GPIO_PIN_10,
	GPIO_PIN_11,
	GPIO_PIN_12,
	GPIO_PIN_13,
	GPIO_PIN_14,
	GPIO_PIN_15
}GPIO_pin;


/*****************************************************************************************************************************************
********************************************************  mode configurations  ***********************************************
*****************************************************************************************************************************************/
typedef enum
{
	GPIO_ANALOG_MODE = 0b0000,
	GPIO_FLOATING_INPUT = 0b0100,
	GPIO_INPUT_PULL_UP_DOWN = 0b1000,
	GPIO_OUTPUT_PUSH_PULL = 0b0001,
	GPIO_OUTPUT_OPEN_DRAIN = 0b0110,
	GPIO_AF_OUTPUT_PUSH_PULL = 0b1011,
	GPIO_AF_OUTPUT_OPEN_DRAIN = 0b1111
}GPIO_mode;


/*****************************************************************************************************************************************
********************************************************  speed configurations In output mode  ***********************************************
*****************************************************************************************************************************************/
typedef enum
{
GPIO_INPUT_MODE,
GPIO_OUTPUT_SPEED_10MHZ,
GPIO_OUTPUT_SPEED_2MHZ,
GPIO_OUTPUT_SPEED_50MHZ
}GPIO_speed;

/*****************************************************************************************************************************************
********************************************************  alternative function peripherals  ***********************************************
*****************************************************************************************************************************************/
typedef enum
{
	GPIO_AF_SPI1,
	GPIO_AF_I2C1,
	GPIO_AF_USART1,
	GPIO_AF_USART2,
//	GPIO_AF_TIM1 = 6,
//	GPIO_AF_TIM2 = 8,
//	GPIO_AF_TIM3 = 10,
//	GPIO_AF_TIM4 = 12,
	GPIO_AF_PD01 = 15,
	GPIO_AF_TIM5,
	GPIO_AF_ADC1EXTRIG,
	GPIO_AF_ADC1REG,
	GPIO_AF_ADC2EXTRIG,
	GPIO_AF_ADC2REG,
}GPIO_AF;

typedef enum
{
	GPIO_AF_CAN_RXPA11_TXPA12,
	GPIO_AF_CAN_NOREMAP,
	GPIO_AF_CAN_RXPB8_TXPB9 ,
	GPIO_AF_CAN_RXPD0_TXPD1
}GPIO_AF_CAN;
/*****************************************************************************************************************************************
********************************************************  alternative function cofigurations   ***********************************************
*****************************************************************************************************************************************/
typedef enum
{
	NOREMAP,
	REMAP
}GPIO_AFConfig;

/*****************************************************************************************************************************************
********************************************************  pin values  ***********************************************
*****************************************************************************************************************************************/
typedef enum
{
GPIO_PIN_LOW,
GPIO_PIN_HIGH,
}GPIO_pinStatus;

/*****************************************************************************************************************************************
********************************************************  GPIO pin configuration structure  ***********************************************
*****************************************************************************************************************************************/
typedef struct
{
	GPIO_port GPIO_portConfig;
	GPIO_pin GPIO_pinConfig;
	GPIO_mode GPIO_modeConfig;
	GPIO_speed GPIO_speedConfig;
}GPIO_Config;

/*****************************************************************************************************************************************
***************************************************************      functions prototypes      ************************************************
*****************************************************************************************************************************************/

/*
************************************************************************************************************************************
name                : GPIO_configPin
description         : configure GPIO pin with specific configuration
synch/asynch        : synch
parameters          : t_ptrToConfig
return              : GPIO_errorStatus:- No Errors.
 *                                     - Null Pointer Error.
 *                                     - Port ID Error.
 *                                     - Pin ID Error.
 *                                     - Speed Error.
 *                                     - Mode Error.
************************************************************************************************************************************
*/
GPIO_errorStatus GPIO_configPin(GPIO_Config* t_ptrToConfig);

/*
************************************************************************************************************************************
name                : GPIO_voidInitSysClock
description         : write a value on specific GPIO pin
synch/asynch        : synch
parameters          : [t_portID] -> the port that contains the pin ---- [t_pinID] -> pin number ---- [t_pinStatus] -> high or low
return              : GPIO_errorStatus:- No Errors.
 *                                     - Null Pointer Error.
 *                                     - Port ID Error.
 *                                     - Pin ID Error.
 *                                     - Speed Error.
 *                                     - Mode Error.
************************************************************************************************************************************
*/
GPIO_errorStatus GPIO_writePin(GPIO_port t_portID, GPIO_pin t_pinID, GPIO_pinStatus t_pinStatus);

/*
************************************************************************************************************************************
name                : GPIO_writePort
description         : write a value on specific GPIO port
synch/asynch        : synch
parameters          : [t_portID] -> the port required to be assigned with value ---- [t_portValue] -the value
return              : GPIO_errorStatus:- No Errors.
 *                                     - Null Pointer Error.
 *                                     - Port ID Error.
 *                                     - Pin ID Error.
 *                                     - Speed Error.
 *                                     - Mode Error.
************************************************************************************************************************************
*/
GPIO_errorStatus GPIO_writePort(GPIO_port t_portID, u16 t_portValue);

/*
************************************************************************************************************************************
name                : GPIO_readPin
description         : read a value of specific GPIO pin
synch/asynch        : synch
parameters          : [t_portID] -> the port that contains the pin ---- [t_pinID] -> pin number ---- [t_ptrToStatus] -> ptr points to variable to store the value
return              : GPIO_errorStatus:- No Errors.
 *                                     - Null Pointer Error.
 *                                     - Port ID Error.
 *                                     - Pin ID Error.
 *                                     - Speed Error.
 *                                     - Mode Error.
************************************************************************************************************************************
*/
GPIO_errorStatus GPIO_readPin(GPIO_port t_portID, GPIO_pin t_pinID, GPIO_pinStatus* t_ptrToStatus);

/*
************************************************************************************************************************************
name                : GPIO_readPort
description         : read the value of specific GPIO port
synch/asynch        : synch
parameters          : [t_portID] -> the port required to be read ---- [t_ptrToStatus] -> ptr points to variable to store the value
return              : GPIO_errorStatus:- No Errors.
 *                                     - Null Pointer Error.
 *                                     - Port ID Error.
 *                                     - Pin ID Error.
 *                                     - Speed Error.
 *                                     - Mode Error.
************************************************************************************************************************************
*/
GPIO_errorStatus GPIO_readPort(GPIO_port t_portID, u16* t_ptrToStatus);

/*
************************************************************************************************************************************
* name                : GPIO_enableOrDisablePinAlternativeFuction
* description         : enable specific pin as an alternative or disable it
* synch/asynch        : synch
* parameters          : [t_alternativeFun] -> AF peripheral number --- [AFconfig] -> choose to remap or no remap for AF pin
* return              : GPIO_errorStatus:- No Errors.
*                                        - GPIO_ALTERNATE_FUNCTION_ERROR.
*                                        - GPIO_ALTERNATE_FUNCTION_CONFIGURE_ERROR
************************************************************************************************************************************
*/
GPIO_errorStatus GPIO_enableOrDisablePinAlternativeFuction(GPIO_AF t_alternativeFun, GPIO_AFConfig AFconfig);

/*
************************************************************************************************************************************
* name                : GPIO_CANenableOrDisablePinAlternativeFuction
* description         : enable CAN pin as an alternative or disable it
* synch/asynch        : synch
* parameters          : [canAlternativePinsConfig] -> AF for can configuration
* return              : GPIO_errorStatus:- No Errors.
*                                        - GPIO_CAN_ALTERNATE_FUNCTION_ERROR.
************************************************************************************************************************************
*/
GPIO_errorStatus GPIO_CANenableOrDisablePinAlternativeFuction(GPIO_AF_CAN canAlternativePinsConfig);

#endif /* GPIO_H_ */
