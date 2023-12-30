/*
************************************************************************************************************************************

*****************************   author: Ahmed Dewidar

*****************************   Date: 08/10/2023

*****************************   Module: RCC

*****************************   Layer: Mcal

************************************************************************************************************************************
*/

#ifndef RCC_PRV_H_
#define RCC_PRV_H_

/*****************************************************************************************************************************************
***************************************************************RCC base address**************************************************************
*****************************************************************************************************************************************/
#define RCC_BASE_ADDRESS                                  0x40021000

/*****************************************************************************************************************************************
***************************************************************RCC registers**************************************************************
*****************************************************************************************************************************************/
typedef struct
{
	volatile u32 RCC_CR;
	volatile u32 RCC_CFGR;
	volatile u32 RCC_CIR;
	volatile u32 RCC_APB2RSTR;
	volatile u32 RCC_APB1RSTR;
	volatile u32 RCC_AHBENR;
	volatile u32 RCC_APB2ENR;
	volatile u32 RCC_APB1ENR;
	volatile u32 RCC_BDCR;
	volatile u32 RCC_CSR;
	volatile u32 RCC_AHBSTR;
	volatile u32 RCC_CFGR2;

}RCC_T;

/*****************************************************************************************************************************************
***************************************************************control register bits**************************************************************
*****************************************************************************************************************************************/
#define RCC_PLL_RDY_FLAG             25
#define RCC_HSE_RDY_FLAG             17
#define RCC_HSI_RDY_FLAG             1
#define RCC_PLL_ENBL                 24
#define RCC_HSE_ENBL                 16
#define RCC_HSI_ENBL                 0

/*****************************************************************************************************************************************
***************************************************************cofigure register bits**************************************************************
*****************************************************************************************************************************************/
#define RCC_PLL_MUL_FAC             18
#define RCC_HSE_DIV_FOR_PLL         17
#define RCC_PLL_CLK_SRC             16
#define RCC_ADC_PRESC               14
#define RCC_APB2_PRESC              11
#define RCC_APB1_PRESC              8
#define RCC_AHB_PRESC               4

/*
lock trimming is crucial for applications where precise timing is necessary, such as real-time systems, communication protocols,
or any system where accurate synchronization is essential.
The specific method and level of precision required will determine which trimming technique is most suitable.
*/

#define RCC1 ((volatile RCC_T *) RCC_BASE_ADDRESS)

#endif /* RCC_PRV_H_ */