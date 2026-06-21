/**
*     Copyright (c) 2025, Nsing Technologies Inc.
* 
*     All rights reserved.
*
*     This software is the exclusive property of Nsing Technologies Inc. (Hereinafter 
* referred to as Nsing). This software, and the product of Nsing described herein 
* (Hereinafter referred to as the Product) are owned by Nsing under the laws and treaties
* of the People's Republic of China and other applicable jurisdictions worldwide.
*
*     Nsing does not grant any license under its patents, copyrights, trademarks, or other 
* intellectual property rights. Names and brands of third party may be mentioned or referred 
* thereto (if any) for identification purposes only.
*
*     Nsing reserves the right to make changes, corrections, enhancements, modifications, and 
* improvements to this software at any time without notice. Please contact Nsing and obtain 
* the latest version of this software before placing orders.

*     Although Nsing has attempted to provide accurate and reliable information, Nsing assumes 
* no responsibility for the accuracy and reliability of this software.
* 
*     It is the responsibility of the user of this software to properly design, program, and test 
* the functionality and safety of any application made of this information and any resulting product. 
* In no event shall Nsing be liable for any direct, indirect, incidental, special,exemplary, or 
* consequential damages arising in any way out of the use of this software or the Product.
*
*     Nsing Products are neither intended nor warranted for usage in systems or equipment, any
* malfunction or failure of which may cause loss of human life, bodily injury or severe property 
* damage. Such applications are deemed, "Insecure Usage".
*
*     All Insecure Usage shall be made at user's risk. User shall indemnify Nsing and hold Nsing 
* harmless from and against all claims, costs, damages, and other liabilities, arising from or related 
* to any customer's Insecure Usage.

*     Any express or implied warranty with regard to this software or the Product, including,but not 
* limited to, the warranties of merchantability, fitness for a particular purpose and non-infringement
* are disclaimed to the fullest extent permitted by law.

*     Unless otherwise explicitly permitted by Nsing, anyone may not duplicate, modify, transcribe
* or otherwise distribute this software for any purposes, in whole or in part.
*
*     Nsing products and technologies shall not be used for or incorporated into any products or systems
* whose manufacture, use, or sale is prohibited under any applicable domestic or foreign laws or regulations. 
* User shall comply with any applicable export control laws and regulations promulgated and administered by 
* the governments of any countries asserting jurisdiction over the parties or transactions.
**/

/**
*\*\file system_n32g033.c
*\*\author Nsing
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/

#include "n32g033.h"

/* Uncomment the line corresponding to the desired System clock (SYSCLK)
   frequency (after reset the HSI is used as SYSCLK source)

   IMPORTANT NOTE:
   ==============
   1. After each device reset the HSI is used as System clock source.

   2. Please make sure that the selected System clock doesn't exceed your
   device's maximum frequency.

   3. If none of the define below is enabled, the HSI is used as System clock
    source.

   4. The System clock configuration functions provided within this file assume
   that:
        - For Low and High density Value line devices an external 8MHz
          crystal is used to drive the System clock.
        - For Low and High density devices an external 8MHz crystal is
          used to drive the System clock.
        - For Connectivity line devices an external 25MHz crystal is used to
   drive the System clock. If you are using different crystal you have to adapt
   those functions accordingly.
    */



#ifndef SYSCLK_FREQ
#define SYSCLK_FREQ 64000000
#endif


#ifndef HSI_VALUE
    #error HSI_VALUE must be defined!
#endif

#ifndef LSI_VALUE
    #error LSI_VALUE must be defined!
#endif

#if (SYSCLK_FREQ != HSI_VALUE)&&(SYSCLK_FREQ != HSI_VALUE/2)&&(SYSCLK_FREQ != LSI_VALUE)
    #error SYSCL_FREQ must be set to 64M, 32M or 32K
#endif



/* #define VECT_TAB_SRAM */
#define VECT_TAB_OFFSET 0x0 /*!< Vector Table base offset field. This value must be a multiple of 0x200. */

/*******************************************************************************
 *  Clock Definitions
 *******************************************************************************/
uint32_t SystemCoreClock = SYSCLK_FREQ; /*!< System Clock Frequency (Core Clock) */

const uint8_t AHBPrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};

static void SetSysClock(void);

#ifdef DATA_IN_ExtSRAM
static void SystemInit_ExtMemCtl(void);
#endif /* DATA_IN_ExtSRAM */
void Delay_ms(uint32_t ms)
{
    uint32_t i, j;
    for (i = 0; i < ms; i++)
    {
        // 循环次数需根据实际时钟频率校准，可通过逻辑分析仪/示波器微调
        for (j = 0; j < 9000; j++)
        {
            __NOP();  // 空操作，避免编译器优化掉循环
        }
    }
}
/**
*\*\name SystemInit
*\*\fun  Setup the microcontroller system
*\*\         Initialize the Embedded Flash Interface and update the
*\*\         SystemCoreClock variable.
*\*\param  none
*\*\return  none
*\*\note   This function should be used only after reset.
 */
void SystemInit(void)
{
	 
    /* Flash wait state 1: HCLK <= 64M */
    FLASH->AC = (uint32_t)0x00000001;

    /* Reset the RCC clock configuration to the default reset state(for debug purpose) */
    /* Set HSIEN bit */
    RCC->CTRL |= (uint32_t)0x00000001;

    /* Reset SYSPRES, SCLKSW, MCO and MCOPRES bits */
    RCC->CFG &= (uint32_t)0x83FEFFFE;

    /* Reset CFG2 register */
    RCC->CFG2 = 0x00000000;

    /* Configure the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers */
    /* Configure the Flash Latency cycles and enable prefetch buffer */
    SetSysClock();
	  Delay_ms(100);
}

/**
*\*\name    RCC_ClrIntPendingBit.
*\*\fun  Update SystemCoreClock variable according to Clock Register Values.
*\*\        The SystemCoreClock variable contains the core clock (HCLK), it can
*\*\        be used by the user application to setup the SysTick timer or configure other parameters.
*\*\param  none
*\*\return  none
*\*\note   Each time the core clock (HCLK) changes, this function must be called
*\*\        to update SystemCoreClock variable value. Otherwise, any configuration based on this variable will be incorrect.
*\*\note   - The system frequency computed by this function is not the real
*\*\          frequency in the chip. It is calculated based on the predefined constant and the selected clock source:
*\*\          - If SYSCLK source is HSI, SystemCoreClock will contain the HSI_VALUE(*)
*\*\          - If SYSCLK source is LSI, SystemCoreClock will contain the LSI_VALUE(***)
*\*\        (*) HSI_VALUE is a constant defined in n32g033.h file (default value
*\*\            64 MHz) but the real value may vary depending on the variations
*\*\            in voltage and temperature.
*\*\        (***) LSI_VALUE is a constant defined in n32g033.h file (default value
*\*\            32KHz) but the real value may vary depending on the variations
*\*\            in voltage and temperature.
*\*\        - The result of this function could be not correct when using
*\*\fractional value for HSE crystal.
 */
void SystemCoreClockUpdate(void)
{
    uint32_t tmp = 0;

    /* Get SYSCLK source
     * -------------------------------------------------------*/
    tmp = RCC->CFG & RCC_CFG_SCLKSTS;

    switch (tmp)
    {
        case RCC_CFG_SCLKSTS_HSI: /* HSI used as system clock */
            SystemCoreClock = HSI_VALUE;
            break;
        case RCC_CFG_SCLKSTS_LSI: /* LSI used as system clock */
            SystemCoreClock = LSI_VALUE;
            break;

        default:
            SystemCoreClock = HSI_VALUE;
            break;
    }

    /* Compute HCLK clock frequency ----------------*/
    /* Get HCLK prescaler */
    tmp = AHBPrescTable[((RCC->CFG & RCC_CFG_AHBPRES) >> 4)];
    /* HCLK clock frequency */
    SystemCoreClock >>= tmp;
}

/**
*\*\name  SetSysClock.
*\*\fun   Configures the System clock frequency, HCLK, PCLK prescalers.
*\*\param  none
*\*\return  none
**/
static void SetSysClock(void)
{
    uint32_t StartUpCounter = 0;
  	uint32_t temp           = 0;

#if (SYSCLK_FREQ == HSI_VALUE)||(SYSCLK_FREQ == HSI_VALUE/2)

    bool HSIStatus = 0;
    /* Enable HSI */
    RCC->CTRL |= ((uint32_t)RCC_CTRL_HSIEN);

    /* Wait till HSI is ready and if Time out is reached exit */
    do
    {
        HSIStatus = RCC->CTRL & RCC_CTRL_HSIRDF;
        StartUpCounter++;
    } while ((HSIStatus == 0) && (StartUpCounter != HSI_STARTUP_TIMEOUT));

    HSIStatus = ((RCC->CTRL & RCC_CTRL_HSIRDF) != RESET);
    if (!HSIStatus)
    {
        /* If HSI fails to start-up, the application will have wrong clock
         * configuration. User can add here some code to deal with this error */
        while(1);
    }

#elif (SYSCLK_FREQ == LSI_VALUE)

    bool LSIStatus = 0;

    /* Wait till LSI is ready and if Time out is reached exit */
    do
    {
        LSIStatus = RCC->CLKINT & RCC_CLKINT_LSIRDF;
        StartUpCounter++;
    } while ((LSIStatus == 0) && (StartUpCounter != LSI_STARTUP_TIMEOUT));

    LSIStatus = ((RCC->CLKINT & RCC_CLKINT_LSIRDF) != RESET);
    if (!LSIStatus)
    {
        /* If LSI fails to start-up, the application will have wrong clock
         * configuration. User can add here some code to deal with this error */
        SystemCoreClock = HSI_VALUE;
        return;
    }

#endif
    /* HCLK = SYSCLK */
    temp  = RCC->CFG ;
    temp &= ~RCC_CFG_AHBPRES;
    RCC->CFG = temp ;
    
#if (SYSCLK_FREQ == HSI_VALUE)
    /* PCLK = HCLK/2 */
    temp  = RCC->CFG ;
    temp &= ~RCC_CFG_APBPRES;
    temp |= RCC_CFG_APBPRES_2;
    RCC->CFG = temp ;
#else
    /* PCLK = HCLK */
    temp  = RCC->CFG ;
    temp &= ~RCC_CFG_APBPRES;
    RCC->CFG = temp ;
#endif

   
#if (SYSCLK_FREQ == HSI_VALUE/2)
    RCC->CFG |= RCC_CFG_SYSPRES;
#endif

#if (SYSCLK_FREQ == HSI_VALUE)||(SYSCLK_FREQ == HSI_VALUE/2)
    /* Select HSI as system clock source */
    RCC->CFG &= (uint32_t)((uint32_t) ~(RCC_CFG_SCLKSW));

    /* Wait till HSI is used as system clock source */
    /* if system clock switch fail, User can add here some code to deal with this error */
    while ((RCC->CFG & (uint32_t)RCC_CFG_SCLKSTS) != RCC_CFG_SCLKSTS_HSI)
    {
    }
#elif (SYSCLK_FREQ == LSI_VALUE)
    /* Select LSI as system clock source */
    RCC->CFG |= RCC_CFG_SCLKSW;

    /* Wait till LSI is used as system clock source */
    /* if system clock switch fail, User can add here some code to deal with this error */
    while ((RCC->CFG & (uint32_t)RCC_CFG_SCLKSTS) != RCC_CFG_SCLKSTS_LSI)
    {
    }
#endif
    /* Flash wait state
        0: HCLK <= 32M
        1: HCLK <= 64M
     */
    temp = FLASH->AC;
    temp &= (uint32_t)((uint32_t)~FLASH_AC_LATENCY);
    temp |= (uint32_t)((SYSCLK_FREQ - 1) / 32000000);
    FLASH->AC = temp;
}
