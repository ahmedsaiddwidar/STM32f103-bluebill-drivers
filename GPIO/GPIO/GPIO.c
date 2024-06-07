/*
************************************************************************************************************************************

*****************************   author: Ahmed Dewidar

*****************************   Date: 12/10/2023

*****************************   Module: GPIO

*****************************   Layer: Mcal

************************************************************************************************************************************
*/

#include "GPIO.h"

#include "GPIO_cfg.h"
#include "GPIO_prv.h"

/*
************************************************************************************************************************************
* name                : GPIO_configPin
* description         : configure GPIO pin with specific configuration
* synch/asynch        : synch
* parameters          : t_ptrToConfig
* return              : GPIO_errorStatus:- No Errors.
*                                     - Null Pointer Error.
*                                     - Port ID Error.
*                                     - Pin ID Error.
*                                     - Speed Error.
*                                     - Mode Error.
************************************************************************************************************************************
*/
GPIO_errorStatus GPIO_configPin(GPIO_Config* t_ptrToConfig)
{
	GPIO_errorStatus returnError_status = GPIO_ok;

	GPIO_registersMap *LOC_arrOfPtrsToRegMap[3] = {GPIOA,GPIOB,GPIOC};

	u8 loc_pin;
	u32 loc_port;

	if(t_ptrToConfig == NULL)
	{
		returnError_status = GPIO_NULL_PTR_ERROR;
	}
	else if(t_ptrToConfig->GPIO_portConfig > GPIO_NUM_OF_PORTS)
	{
		returnError_status = GPIO_PORT_ID_ERROR;
	}
	else if(t_ptrToConfig->GPIO_pinConfig > GPIO_NUM_OF_PINS_PER_PORT)
	{
		returnError_status = GPIO_PIN_ID_ERROR;
	}
	else if(t_ptrToConfig->GPIO_modeConfig > GPIO_AF_OUTPUT_OPEN_DRAIN)
	{
		returnError_status = GPIO_PIN_MODE_ERROR;
	}
	else if(t_ptrToConfig->GPIO_speedConfig > GPIO_OUTPUT_SPEED_50MHZ)
	{
		returnError_status = GPIO_PIN_SPEED_ERROR;
	}
	else
	{
		loc_port = t_ptrToConfig->GPIO_portConfig;
		loc_pin = t_ptrToConfig->GPIO_pinConfig;

		switch(loc_port)
		{
		case GPIO_PORTA:
			if(loc_pin <= GPIO_PIN_07)
			{
				LOC_arrOfPtrsToRegMap[0]->GPIO_CRL |=(t_ptrToConfig->GPIO_modeConfig<< (loc_pin*4) );
			}
			else
			{
				LOC_arrOfPtrsToRegMap[0]->GPIO_CRH |=(t_ptrToConfig->GPIO_modeConfig<< (loc_pin*4) );
			}
			break;

		case GPIO_PORTB:
			if(loc_pin <= GPIO_PIN_07)
			{
				LOC_arrOfPtrsToRegMap[1]->GPIO_CRL |=(t_ptrToConfig->GPIO_modeConfig<< (loc_pin*4) );
			}
			else
			{
				LOC_arrOfPtrsToRegMap[1]->GPIO_CRH |=(t_ptrToConfig->GPIO_modeConfig<< (loc_pin*4) );
			}
			break;

		case GPIO_PORTC:
			if(loc_pin <= GPIO_PIN_07)
			{
				LOC_arrOfPtrsToRegMap[2]->GPIO_CRL |=(t_ptrToConfig->GPIO_modeConfig<< (loc_pin*4) );
			}
			else
			{
				LOC_arrOfPtrsToRegMap[2]->GPIO_CRH |=(t_ptrToConfig->GPIO_modeConfig<< (loc_pin*4) );
			}
			break;
		}

	}
	return returnError_status;
}

/*
************************************************************************************************************************************
* name                : GPIO_voidInitSysClock
* description         : write a value on specific GPIO pin
* synch/asynch        : synch
* parameters          : [t_portID] -> the port that contains the pin ---- [t_pinID] -> pin number ---- [t_pinStatus] -> high or low
* return              : GPIO_errorStatus:- No Errors.
*                                     - Null Pointer Error.
*                                     - Port ID Error.
*                                     - Pin ID Error.
*                                     - Speed Error.
*                                     - Mode Error.
************************************************************************************************************************************
*/
GPIO_errorStatus GPIO_writePin(GPIO_port t_portID, GPIO_pin t_pinID, GPIO_pinStatus t_pinStatus)
{
	GPIO_errorStatus returnError_status = GPIO_ok;

	if(t_portID > GPIO_NUM_OF_PORTS)
	{
		returnError_status = GPIO_PORT_ID_ERROR;
	}
	else if(t_pinID > GPIO_NUM_OF_PINS_PER_PORT)
	{
		returnError_status = GPIO_PIN_ID_ERROR;
	}
	else if(t_pinStatus != GPIO_PIN_HIGH || t_pinStatus != GPIO_PIN_LOW)
	{
		returnError_status = GPIO_PIN_STATUS_ERROR;
	}
	else
	{
		switch(t_portID)
		{
		case GPIO_PORTA:
			if(t_pinStatus == GPIO_PIN_HIGH)
			{
				SET_BIT(GPIOA->GPIO_ODR,t_pinID);
			}
			else
			{
				CLEAR_BIT(GPIOA->GPIO_ODR,t_pinID);
			}
			break;

		case GPIO_PORTB:
			if(t_pinStatus == GPIO_PIN_HIGH)
			{
				SET_BIT(GPIOB->GPIO_ODR,t_pinID);
			}
			else
			{
				CLEAR_BIT(GPIOB->GPIO_ODR,t_pinID);
			}
			break;

		case GPIO_PORTC:
			if(t_pinStatus == GPIO_PIN_HIGH)
			{
				SET_BIT(GPIOC->GPIO_ODR,t_pinID);
			}
			else
			{
				CLEAR_BIT(GPIOC->GPIO_ODR,t_pinID);
			}
			break;
		}

	}
	return returnError_status;
}

/*
************************************************************************************************************************************
* name                : GPIO_writePort
* description         : write a value on specific GPIO port
* synch/asynch        : synch
* parameters          : [t_portID] -> the port required to be assigned with value ---- [t_portValue] -the value
* return              : GPIO_errorStatus:- No Errors.
*                                     - Null Pointer Error.
*                                     - Port ID Error.
*                                     - Pin ID Error.
*                                     - Speed Error.
*                                     - Mode Error.
************************************************************************************************************************************
*/
GPIO_errorStatus GPIO_writePort(GPIO_port t_portID, u16 t_portValue)
{
	GPIO_errorStatus returnError_status = GPIO_ok;

	if(t_portID > GPIO_NUM_OF_PORTS)
	{
		returnError_status = GPIO_PORT_ID_ERROR;
	}
	else
	{
		switch(t_portID)
		{
		case GPIO_PORTA:
			ASSIGN_REG(GPIOA->GPIO_ODR,t_portValue);
			break;

		case GPIO_PORTB:
			ASSIGN_REG(GPIOB->GPIO_ODR,t_portValue);
			break;

		case GPIO_PORTC:
			ASSIGN_REG(GPIOC->GPIO_ODR,t_portValue);
			break;
		}

	}
	return returnError_status;
}

/*
************************************************************************************************************************************
* name                : GPIO_readPin
* description         : read a value of specific GPIO pin
* synch/asynch        : synch
* parameters          : [t_portID] -> the port that contains the pin ---- [t_pinID] -> pin number ---- [t_ptrToStatus] -> ptr points to variable to store the value
* return              : GPIO_errorStatus:- No Errors.
*                                     - Null Pointer Error.
*                                     - Port ID Error.
*                                     - Pin ID Error.
*                                     - Speed Error.
*                                     - Mode Error.
************************************************************************************************************************************
*/
GPIO_errorStatus GPIO_readPin(GPIO_port t_portID, GPIO_pin t_pinID, GPIO_pinStatus* t_ptrToStatus)
{
	GPIO_errorStatus returnError_status = GPIO_ok;

	if(t_ptrToStatus == NULL)
	{
		returnError_status = GPIO_NULL_PTR_ERROR;
	}
	else if(t_portID > GPIO_NUM_OF_PORTS)
	{
		returnError_status = GPIO_PORT_ID_ERROR;
	}
	else if(t_pinID > GPIO_NUM_OF_PINS_PER_PORT)
	{
		returnError_status = GPIO_PIN_ID_ERROR;
	}
	else
	{
		switch(t_portID)
		{
		case GPIO_PORTA:
			*t_ptrToStatus = GET_BIT(GPIOA->GPIO_IDR,t_pinID);
			break;

		case GPIO_PORTB:
			*t_ptrToStatus = GET_BIT(GPIOB->GPIO_IDR,t_pinID);
			break;

			*t_ptrToStatus = GET_BIT(GPIOC->GPIO_IDR,t_pinID);
		case GPIO_PORTC:

			break;
		}

	}
	return returnError_status;
}

/*
************************************************************************************************************************************
* name                : GPIO_readPort
* description         : read the value of specific GPIO port
* synch/asynch        : synch
* parameters          : [t_portID] -> the port required to be read ---- [t_ptrToStatus] -> ptr points to variable to store the value
* return              : GPIO_errorStatus:- No Errors.
*                                     - Null Pointer Error.
*                                     - Port ID Error.
*                                     - Pin ID Error.
*                                     - Speed Error.
*                                     - Mode Error.
************************************************************************************************************************************
*/
GPIO_errorStatus GPIO_readPort(GPIO_port t_portID, u16* t_ptrToStatus)
{
	GPIO_errorStatus returnError_status = GPIO_ok;

	if(t_ptrToStatus == NULL)
	{
		returnError_status = GPIO_NULL_PTR_ERROR;
	}
	else if(t_portID > GPIO_NUM_OF_PORTS)
	{
		returnError_status = GPIO_PORT_ID_ERROR;
	}

	else
	{
		switch(t_portID)
		{
		case GPIO_PORTA:
			*t_ptrToStatus = GPIOA->GPIO_IDR;
			break;

		case GPIO_PORTB:
			*t_ptrToStatus = GPIOB->GPIO_IDR;
			break;

			*t_ptrToStatus = GPIOC->GPIO_IDR;
		case GPIO_PORTC:

			break;
		}

	}
	return returnError_status;
}
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
GPIO_errorStatus GPIO_enableOrDisablePinAlternativeFuction(GPIO_AF t_alternativeFun, GPIO_AFConfig AFconfig)
{
	GPIO_errorStatus returnError_status = GPIO_ok;


	if(t_alternativeFun > GPIO_AF_ADC1REG)
	{
		returnError_status = GPIO_ALTERNATE_FUNCTION_ERROR;
	}
	else if(AFconfig > REMAP)
	{
		returnError_status = GPIO_ALTERNATE_FUNCTION_CONFIGURE_ERROR;
	}
	else
	{
		switch(t_alternativeFun)
		{
		case GPIO_AF_SPI1:
			if(AFconfig == REMAP)
			{
				SET_BIT(AFIO->AFIO_MAPR,GPIO_AF_SPI1);
			}

			else
			{
				CLEAR_BIT(AFIO->AFIO_MAPR,GPIO_AF_SPI1);
			}
			break;

		case GPIO_AF_I2C1:
			if(AFconfig == REMAP)
			{
				SET_BIT(AFIO->AFIO_MAPR,GPIO_AF_I2C1);
			}

			else
			{
				CLEAR_BIT(AFIO->AFIO_MAPR,GPIO_AF_I2C1);
			}
			break;

		case GPIO_AF_USART1:
			if(AFconfig == REMAP)
			{
				SET_BIT(AFIO->AFIO_MAPR,GPIO_AF_USART1);
			}

			else
			{
				CLEAR_BIT(AFIO->AFIO_MAPR,GPIO_AF_USART1);
			}
			break;

		case GPIO_AF_USART2:
			if(AFconfig == REMAP)
			{
				SET_BIT(AFIO->AFIO_MAPR,GPIO_AF_USART2);
			}

			else
			{
				CLEAR_BIT(AFIO->AFIO_MAPR,GPIO_AF_USART2);
			}
			break;

		case GPIO_AF_PD01:
			if(AFconfig == REMAP)
			{
				SET_BIT(AFIO->AFIO_MAPR,GPIO_AF_PD01);
			}

			else
			{
				CLEAR_BIT(AFIO->AFIO_MAPR,GPIO_AF_PD01);
			}
			break;

		case GPIO_AF_TIM5:
			if(AFconfig == REMAP)
			{
				SET_BIT(AFIO->AFIO_MAPR,GPIO_AF_TIM5);
			}

			else
			{
				CLEAR_BIT(AFIO->AFIO_MAPR,GPIO_AF_TIM5);
			}
			break;

		case GPIO_AF_ADC1EXTRIG:
			if(AFconfig == REMAP)
			{
				SET_BIT(AFIO->AFIO_MAPR,GPIO_AF_ADC1EXTRIG);
			}

			else
			{
				CLEAR_BIT(AFIO->AFIO_MAPR,GPIO_AF_ADC1EXTRIG);
			}
			break;

		case GPIO_AF_ADC1REG:
			if(AFconfig == REMAP)
			{
				SET_BIT(AFIO->AFIO_MAPR,GPIO_AF_ADC1REG);
			}

			else
			{
				CLEAR_BIT(AFIO->AFIO_MAPR,GPIO_AF_ADC1REG);
			}
			break;

		case GPIO_AF_ADC2EXTRIG:
			if(AFconfig == REMAP)
			{
				SET_BIT(AFIO->AFIO_MAPR,GPIO_AF_ADC2EXTRIG);
			}

			else
			{
				CLEAR_BIT(AFIO->AFIO_MAPR,GPIO_AF_ADC2EXTRIG);
			}
			break;

		case GPIO_AF_ADC2REG:
			if(AFconfig == REMAP)
			{
				SET_BIT(AFIO->AFIO_MAPR,GPIO_AF_ADC2REG);
			}

			else
			{
				CLEAR_BIT(AFIO->AFIO_MAPR,GPIO_AF_ADC2REG);
			}
			break;

		}

	}
	return returnError_status;
}
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
GPIO_errorStatus GPIO_CANenableOrDisablePinAlternativeFuction(GPIO_AF_CAN canAlternativePinsConfig)
{
	GPIO_errorStatus returnError_status = GPIO_ok;


	if(canAlternativePinsConfig > GPIO_AF_CAN_RXPD0_TXPD1)
	{
		returnError_status = GPIO_CAN_ALTERNATE_FUNCTION_ERROR;
	}
	else
	{
		GPIO_WRITE_TWO_BITS (AFIO ->AFIO_MAPR,13,canAlternativePinsConfig);
	}
	return returnError_status;
}
