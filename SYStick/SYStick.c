/*
 * SYStick.c
 *
 *  Created on: Nov 7, 2023
 *      Author: Ahmed Dwidar
 */

#include"SYStick.h"

#define CPU_FREQUENCY        16000000

Systick_Cbf cbk_ptr = NULL;

Systick_tenuErrorStatus Systick_Init(u32 Copy_TimeMs, u8 sysTick_prescaler)
{

	Systick_tenuErrorStatus  sysTickReturn_error = Systick_enuOk;
	if(Copy_TimeMs == 0)
	{
		sysTickReturn_error = Systick_enuErrorTimeMs;
	}
	else
	{
		STK_LOAD = ( ( (Copy_TimeMs / 1000) + CPU_FREQUENCY) - 1);

		if(sysTick_prescaler == SYSTICK_PRESCALER_DIV1)
		{
			SET_BIT(STK_CTRL,2);
		}
		else if(sysTick_prescaler == SYSTICK_PRESCALER_DIV8)
		{
			CLEAR_BIT(STK_CTRL,2);
		}


	}
	return sysTickReturn_error;

}
Systick_tenuErrorStatus Systick_RegisterCbf(Systick_Cbf Add_pfCbf)
{
	Systick_tenuErrorStatus sysTickReturn_error = Systick_enuOk;

		cbk_ptr = Add_pfCbf;
}
void Systick_Start(void)
{
	SET_BIT(STK_CTRL,0);
}
void Systick_Stop(void)
{
	CLEAR_BIT(STK_CTRL,0);
}
int main()
{

}
