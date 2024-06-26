/*
************************************************************************************************************************************

*****************************   author: Ahmed Dewidar

*****************************   Date: 08/10/2023

*****************************   Module: RCC

*****************************   Layer: Mcal

************************************************************************************************************************************
*/

/****************************************************************************************************************************************
***************************************************************      guard the file not to be included one time in file .c     ********************
*****************************************************************************************************************************************/
#ifndef RCC_H_
#define RCC_H_

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
	RCC_OK,
	RCC_WRONGBUS = 2
}RCC_errorStatus;

/*****************************************************************************************************************************************
***************************************************************   bus configurations    ***********************************************************
*****************************************************************************************************************************************/
/*copy_u8BusId*/
#define RCC_AHB                               0
#define RCC_APB1                              1
#define RCC_APB2                              2

/*****************************************************************************************************************************************
***************************************************************   clock configurations    ***********************************************************
*****************************************************************************************************************************************/
/*Copy_u8SysClk or Copy_u8OldSysClk*/
#define RCC_HSI                              0
#define RCC_HSE                              1
#define RCC_PLL                              2

/*****************************************************************************************************************************************
***************************************************************    perephirals IDs     *********************************************************
*****************************************************************************************************************************************/
/*copy_u8perId->AHB*/
#define RCC_DMA1                              0
#define RCC_DMA2                              1
#define RCC_SRAM                              2
#define RCC_FLITFEN                           4
#define RCC_CRCEN                             6
#define RCC_FSMCEN                            8
#define RCC_SDIOEN                            10

/*copy_u8perId->APB2*/
#define RCC_AFIOEN                            0
#define RCC_IOPAEN                            1
#define RCC_IOPBEN                            3
#define RCC_IOPCEN                            4
#define RCC_IOPDEN                            5
#define RCC_IOPEEN                            6
#define RCC_IOPFEN                            7
#define RCC_IOPGEN                            8
#define RCC_ADC1EN                            9
#define RCC_ADC2EN                            10
#define RCC_TIM1EN                            11
#define RCC_SPI1EN                            12
#define RCC_TIM8EN                            13
#define RCC_USART1EN                          14
#define RCC_ADC3EN                            15
#define RCC_TIM9EN                            19
#define RCC_TIM10EN                           20
#define RCC_TIM11EN                           21

/*copy_u8perId->APB1*/
#define RCC_TIM2EN                            0
#define RCC_TIM3EN                            1
#define RCC_TIM4EN                            2
#define RCC_TIM5EN                            3
#define RCC_TIM6EN                            4
#define RCC_TIM7EN                            5
#define RCC_TIM12EN                           6
#define RCC_TIM13EN                           7
#define RCC_TIM14EN                           8
#define RCC_WWDGEN                            11
#define RCC_SPI2EN                            14
#define RCC_SPI3EN                            15
#define RCC_USART2EN                          17
#define RCC_USART3EN                          18
#define RCC_UART4EN                           19
#define RCC_UART5EN                           20
#define RCC_I2C1EN                            21
#define RCC_I2C2EN                            22
#define RCC_USBEN                             23
#define RCC_CANEN                             25
#define RCC_BKPEN                             27
#define RCC_PWREN                             28
#define RCC_DACEN                             29

/*****************************************************************************************************************************************
***************************************************************     RCC control register configurations    ************************************************
*****************************************************************************************************************************************/

/*enable the clock bits*/
typedef enum //HSIEN
{
	HSI_OFF,
	HSI_on
}HSIEN_t;
typedef enum //HSEEN
{
	HSE_OFF,
	HSE_on
}HSEEN_t;
typedef enum //PLLEN
{
	PLL_OFF,
	PLL_on
}PLLEN_t;

/*read the clock availability*/
typedef enum //HSIRDY
{
	HSI_NRDY,
	HSI_RDY
}HSIRDY_t;
typedef enum //HSERDY
{
	HSE_NRDY,
	HSE_RDY
}HSERDY_t;
typedef enum //PLLRDY
{
	PLL_NRDY,
	PLL_RDY
}PLLRDY_t;
typedef enum //CLK_SECURITY SYS EN
{
	CLKSEC_DTECTOR_OFF,
	CLKSEC_DTECTOR_ON // if HSE is ready(available)
}CLK_SECURITY_t;

/*****************************************************************************************************************************************
***************************************************************     RCC configure register configurations     **************************************
*****************************************************************************************************************************************/
typedef enum //MCO
{
	NO_CLOCK_MCO,
	HSI_CLK = 4,
	HSE_CLK = 5,
	PLL_CLK = 6
}CLK_t;
typedef enum //USBPRE (PLL)
{
	DIV_ONEHALF,
	NODIV
}USP_t;
typedef enum //PLLMUL
{
	PLLMUL_0,
	PLLMUL_1,
	PLLMUL_2,
	PLLMUL_3,
	PLLMUL_4,
	PLLMUL_5,
	PLLMUL_6,
	PLLMUL_7,
	PLLMUL_8,
	PLLMUL_9,
	PLLMUL_10,
	PLLMUL_11,
	PLLMUL_12,
	PLLMUL_13,
	PLLMUL_14,
	PLLMUL_15
}PLLMUL_t;
typedef enum //PLLXTPRE
{
	HSE_NODIV,
	HSE_DIVBY_2
}PLLXTPRE_t;
typedef enum //PLLSRC
{
	PLLSRC_HSI,
	PLLSRC_HSE
}PLLSRC_t;
typedef enum //ADCPRE
{
	PCLK2_2,
	PCLK2_4,
	PCLK2_6,
	PCLK2_8
}ADCPRE_t;
typedef enum //PPRE2(APB2) || PPRE1(APB1)
{
	NO_CLK,
	HCLK2_2 = 4,
	HCLK2_4 = 5,
	HCLK2_8 = 6,
	HCLK2_16 = 7
}APB2_t;
typedef enum //HPRE(AHB)
{
	NO_CLOCK,
	SYSCLK_2 = 8,
	SYSCLK_4 = 9,
	SYSCLK_8 = 10,
	SYSCLK_16 = 11,
	SYSCLK_64 = 12,
	SYSCLK_128 = 13,
	SYSCLK_256 = 14,
	SYSCLK_512 = 15
}SYSCLK_t;
typedef enum //SWS(SYSCLK STATUS)
{
	SWS_HSI,
	SWS_HSE,
	SWS_PLL,
	NOT_APPLICABLE
}SWS_t;
typedef enum //SW(SYSCLK SWTCH) clk source after stand by orstop mode
{
	SW_HSI,
	SW_HSE,
	SW_PLL,
	NOT_ALLOWED
}SW_t;
/*****************************************************************************************************************************************
***************************************************************      functions prototypes      ************************************************
*****************************************************************************************************************************************/
RCC_errorStatus Rcc_enuSelectSysCLk(u8 Copy_u8SysClk , u8 Copy_u8OldSysClk);
RCC_errorStatus RCC_enuEnablePerClock(u8 copy_u8BusId,u8 copy_u8perId);
RCC_errorStatus RCC_enuDisablePerClock(u8 copy_u8BusId,u8 copy_u8perId);

#endif /* RCC_H_ */
