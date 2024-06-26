/*
************************************************************************************************************************************

*****************************   author: Ahmed Dewidar

*****************************   Date: 08/10/2023

*****************************   Module: RCC

*****************************   Layer: Mcal

************************************************************************************************************************************
*/

#ifndef RCC_CFG_H_
#define RCC_CFG_H_

#include"RCC.h"
#include"RCC_prv.h"

/*
	NO_CLK,
	HSI_CLK = 4
	HSE_CLK = 5
	PLL_CLK = 6
*/
#define RCC_MICROCONTROLLER_CLOCK_OUTPUT             HSI_CLK
/*
	DIV_ONEHALF
	NODIV
*/
#define RCC_USP_PRESCALER                            NODIV
/*
	PLLMUL_0
	PLLMUL_1
	PLLMUL_2
	PLLMUL_3
	PLLMUL_4
	PLLMUL_5
	PLLMUL_6
	PLLMUL_7
	PLLMUL_8
	PLLMUL_9
	PLLMUL_10
	PLLMUL_11
	PLLMUL_12
	PLLMUL_13
	PLLMUL_14
	PLLMUL_15
*/
#define RCC_PLL_MULTIPLICATION_FACTOR                PLLMUL_4
/*
	PLLSRC_HSI
	PLLSRC_HSE
*/
#define RCC_PLL_ENTRY_CLK_SRC                        PLLSRC_HSI
/*
	HSE_NODIV
	HSE_DIVBY_2
*/
#define RCC_PLL_HSE_DIVIDER                          HSE_NODIV
/*
	PCLK2_2
	PCLK2_4
	PCLK2_6
	PCLK2_8
*/
#define RCC_ADC_PRESCALER                            PCLK2_4
/*
	NO_CLK,
	HCLK2_2 = 4
	HCLK2_4 = 5
	HCLK2_8 = 6
	HCLK2_16 = 7
*/
#define RCC_APB2_PRESCALER                           HCLK2_2
/*
	NO_CLK,
	HCLK1_2 = 4
	HCLK1_4 = 5
	HCLK1_8 = 6
	HCLK1_16 = 7
*/
#define RCC_APB1_PRESCALER                           HCLK1_2
/*
	NO_CLK,
	SYSCLK_2 = 8
	SYSCLK_4 = 9
	SYSCLK_8 = 10
	SYSCLK_16 = 11
	SYSCLK_64 = 12
	SYSCLK_128 = 13
	SYSCLK_256 = 14
	SYSCLK_512 = 15
*/
#define RCC_AHB_PRESCALER                           SYSCLK_2
/*
	SW_HSI
	SW_HSE
	SW_PLL
	NOT_ALLOWED
*/
#define RCC_SYS_CLK_SWITCH                          SW_HSI

#endif /* RCC_CFG_H_ */
