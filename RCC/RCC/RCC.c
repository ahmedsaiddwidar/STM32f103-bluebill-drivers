/*
************************************************************************************************************************************

*****************************   author: Ahmed Dewidar

*****************************   Date: 08/10/2023

*****************************   Module: RCC

*****************************   Layer: Mcal

************************************************************************************************************************************
*/
#include"RCC.h"
#include"RCC_cfg.h"
#include"RCC_prv.h"


/*
************************************************************************************************************************************
name                : RCC_voidInitSysClock
description         : exchange system clock system clock
synch/asynch        : synch
parameters          : void
return              : void
************************************************************************************************************************************
*/
RCC_errorStatus Rcc_enuSelectSysCLk(u8 Copy_u8SysClk , u8 Copy_u8OldSysClk)
{
	RCC_errorStatus RCC_returnStatus = RCC_OK;

	switch(Copy_u8SysClk)
	{
	case RCC_HSI:
		CLEAR_BIT(RCC->RCC_CFGR,0);
		CLEAR_BIT(RCC->RCC_CFGR,1);
		SET_BIT(RCC ->RCC_CR,0);
		break;
	case RCC_HSE:
		SET_BIT(RCC->RCC_CFGR,0);
		CLEAR_BIT(RCC->RCC_CFGR,1);
		SET_BIT(RCC ->RCC_CR,16);
		break;
	case RCC_PLL:
		CLEAR_BIT(RCC ->RCC_CFGR,0);
		SET_BIT(RCC ->RCC_CFGR,1);
		SET_BIT(RCC->RCC_CR,24);
		break;
	default :
		RCC_returnStatus = RCC_WRONGBUS;
		break;
	}
	switch(Copy_u8OldSysClk)
	{
	case RCC_HSI:
		CLEAR_BIT(RCC ->RCC_CR,0);
		break;
	case RCC_HSE:
		CLEAR_BIT(RCC ->RCC_CR,16);
		break;
	case RCC_PLL:
		CLEAR_BIT(RCC->RCC_CR,24);
		break;
	default :
		RCC_returnStatus = RCC_WRONGBUS;
		break;
	}

	return RCC_returnStatus;
}
/*
************************************************************************************************************************************
name                : RCC_voidInitSysClock
description         : initialize system clock
synch/asynch        : synch
parameters          : void
return              : void
************************************************************************************************************************************
*/
RCC_errorStatus RCC_enuEnablePerClock(u8 copy_u8BusId,u8 copy_u8perId)
{
	RCC_errorStatus RCC_returnStatus = RCC_OK;

	switch(copy_u8BusId)
	{
	case RCC_AHB:
		SET_BIT(RCC ->RCC_AHBENR,copy_u8perId);
		break;
	case RCC_APB1:
		SET_BIT(RCC ->RCC_APB1ENR,copy_u8perId);
		break;
	case RCC_APB2:
		SET_BIT(RCC ->RCC_APB2ENR,copy_u8perId);
		break;
	default :
		RCC_returnStatus = RCC_WRONGBUS;
		break;

	}
	return RCC_returnStatus;
}
/*
************************************************************************************************************************************
name                : RCC_voidInitSysClock
description         : initialize system clock
synch/asynch        : synch
parameters          : void
return              : void
************************************************************************************************************************************
*/
RCC_errorStatus RCC_enuDisablePerClock(u8 copy_u8BusId,u8 copy_u8perId)
{
	RCC_errorStatus RCC_returnStatus = RCC_OK;

	switch(copy_u8BusId)
	{
	case RCC_AHB:
		CLEAR_BIT(RCC ->RCC_AHBENR,copy_u8perId);
		break;
	case RCC_APB1:
		CLEAR_BIT(RCC ->RCC_APB1ENR,copy_u8perId);
		break;
	case RCC_APB2:
		CLEAR_BIT(RCC ->RCC_APB2ENR,copy_u8perId);
		break;
	default :
		RCC_returnStatus = RCC_WRONGBUS;
		break;

	}
	return RCC_returnStatus;
}
