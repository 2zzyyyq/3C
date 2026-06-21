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
*\*\file n32g033_rcc.c
*\*\author Nsing
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/

#include "n32g033_rcc.h"

/**
*\*\name    RCC_DeInit.
*\*\fun     Reset the RCC registers.
*\*\param   none 
*\*\return  none 
**/
void RCC_DeInit(void)
{
    /* Set HSIEN bit */
    RCC->CTRL |= (uint32_t)0x00000001U;

    /* Reset SYSPRES, SCLKSW, MCO and MCOPRES bits */
    RCC->CFG &= (uint32_t)0x83FEFFFEU;

    /* Reset CFG2 register */
    RCC->CFG2 = 0x00000000U;

    /* Reset TIMFILTCFG register */
    RCC->TIMFILTCFG &= ~((uint32_t)0x001F1F1FU);	
}

/**
*\*\name    RCC_EnableHsi.
*\*\fun     Enables the Internal High Speed oscillator (HSI).
*\*\param   Cmd: 
*\*\          - ENABLE  
*\*\          - DISABLE  
*\*\return  none
*\*\note   HSI can not be stopped if it is used directly or through the PLL as system clock.
**/ 
void RCC_EnableHsi(FunctionalState Cmd)
{
    if(Cmd == ENABLE)
   {
       /* Set HSIEN bit */
       RCC->CTRL |= RCC_HSI_ENABLE;
   }
   else
   {
       /* Reset HSIEN bit */
       RCC->CTRL &= (~RCC_HSI_ENABLE);
   }
}

/**
*\*\name    RCC_WaitHsiStable.
*\*\fun     Waits for HSI start-up.
*\*\param   none
*\*\return  ErrorStatus:
 *\*\         - SUCCESS    HSI oscillator is stable and ready to use
 *\*\         - ERROR      HSI oscillator not yet ready
**/
ErrorStatus RCC_WaitHsiStable(void)
{
    __IO uint32_t StartUpCounter = 0;
    ErrorStatus status;
    FlagStatus HSIStatus;

    /* Wait till HSI is ready and if Time out is reached exit */
    do
    {
        HSIStatus = RCC_GetFlagStatus(RCC_CTRL_FLAG_HSIRDF);
        StartUpCounter++;
    } while ((StartUpCounter != HSI_STARTUP_TIMEOUT) && (HSIStatus == RESET));

    if (RCC_GetFlagStatus(RCC_CTRL_FLAG_HSIRDF) != RESET)
    {
        status = SUCCESS;
    }
    else
    {
        status = ERROR;
    }
    return (status);
}

/**
*\*\name    RCC_SetHsiCalibValue.
*\*\fun     Adjusts the Internal High Speed oscillator (HSI) calibration value.
*\*\param   calibration_value(the calibration trimming value):
*\*\        This parameter must be a number between 0 and 0x3FF
*\*\return  none
**/ 
void RCC_SetHsiCalibValue(uint16_t calibration_value)
{
    uint32_t tmpregister;

    tmpregister = RCC->CTRL;
    /* Clear HSITRIM[22:13] bits */
    tmpregister &= CTRL_HSITRIM_MASK;
    /* Set the HSITRIM[22:13] bits according to calibration_value value */
    tmpregister |= (uint32_t)calibration_value << 13;
    /* Store the new value */
    RCC->CTRL = tmpregister;
}

/**
*\*\name    RCC_ConfigLsiCalibSource.
*\*\fun     Configures LSI calibration values source.
*\*\param   cal_src:
*\*\	     - RCC_LSICAL_SRC_AFEC       LSI calibration values are sourced from AFEC
*\*\	     - RCC_LSICAL_SRC_TRIM       LSI calibration values are sourced from LSITRIM
*\*\return  none
**/
void RCC_ConfigLsiCalibSource(uint32_t cal_src)
{
    uint32_t tmpregister;
	
    tmpregister = RCC->LSCTRL;
    /* Clear TRIMSEL bits */
    tmpregister &= LSCTRL_TRIMSEL_MASK;
    /* Set TRIMSEL bits according to cal_src value */
    tmpregister |= cal_src;
    /* Store the new value */
    RCC->LSCTRL = tmpregister;
}

/**
*\*\name    RCC_SetLsiCalibValue.
*\*\fun     Adjusts the Internal Low Speed oscillator (LSI) calibration value.
*\*\param   calibration_value(the calibration trimming value):
*\*\        This parameter must be a number between 0 and 0x1FF
*\*\return  none
**/ 
void RCC_SetLsiCalibValue(uint16_t calibration_value)
{
    uint32_t tmpregister;

    tmpregister = RCC->LSCTRL;
    /* Clear LSITRIM[8:0] bits */
    tmpregister &= LSCTRL_LSITRIM_MASK;
    /* Set the LSITRIM[8:0] bits according to calibration_value value */
    tmpregister |= (uint32_t)calibration_value;
    /* Store the new value */
    RCC->LSCTRL = tmpregister;
}

/**
*\*\name    RCC_ConfigSysclkPres.
*\*\fun     Configures the system clock (SYSCLK) prescaler.
*\*\param   sysclk_pres(HSI divider used as system clock):
*\*\	     - RCC_SYSCLK_PRES_DIV1       HSI divide 1 used as system clock
*\*\	     - RCC_SYSCLK_PRES_DIV2       HSI divide 2 used as system clock
*\*\return  none
**/
void RCC_ConfigSysclkPres(uint32_t sysclk_pres)
{
    uint32_t tmpregister;
	
    tmpregister = RCC->CFG;
    /* Clear SYSPRES bits */
    tmpregister &= CFG_SYSPRES_MASK;
    /* Set SYSPRES bits according to sysclk_pres value */
    tmpregister |= sysclk_pres;
    /* Store the new value */
    RCC->CFG = tmpregister;
}

/**
*\*\name    RCC_ConfigSysclk.
*\*\fun     Configures the system clock (SYSCLK).
*\*\param   sysclk_source(clock source used as system clock):
*\*\	     - RCC_SYSCLK_SRC_HSI       HSI(or divide 2) selected as system clock
*\*\	     - RCC_SYSCLK_SRC_LSI       LSI selected as system clock
*\*\return  none
**/
void RCC_ConfigSysclk(uint32_t sysclk_source)
{
    uint32_t tmpregister;
	
    tmpregister = RCC->CFG;
    /* Clear SW[0] bits */
    tmpregister &= CFG_SCLKSW_MASK;
    /* Set SW[0] bits according to sysclk_source value */
    tmpregister |= sysclk_source;
    /* Store the new value */
    RCC->CFG = tmpregister;
}

/**
*\*\name    RCC_GetSysclkSrc.
*\*\fun     Returns the clock source used as system clock.
*\*\param   none
*\*\return  (The clock source used as system clock):
*\*\         - RCC_CFG_SCLKSTS_HSI    HSI used as system clock  
*\*\         - RCC_CFG_SCLKSTS_LSI    LSI used as system clock
**/
uint32_t RCC_GetSysclkSrc(void)
{
    return ((uint32_t)(RCC->CFG & CFG_SCLKSTS_MASK));
}

/**
*\*\name    RCC_ConfigHclk.
*\*\fun     Configures the AHB clock (HCLK).
*\*\param   sysclk_div(AHB clock is derived from the system clock (SYSCLK)):
*\*\         - RCC_SYSCLK_DIV1      AHB clock = SYSCLK
*\*\         - RCC_SYSCLK_DIV2      AHB clock = SYSCLK/2
*\*\         - RCC_SYSCLK_DIV4      AHB clock = SYSCLK/4
*\*\         - RCC_SYSCLK_DIV8      AHB clock = SYSCLK/8
*\*\         - RCC_SYSCLK_DIV16     AHB clock = SYSCLK/16
*\*\return  none
**/
void RCC_ConfigHclk(uint32_t sysclk_div)
{
    uint32_t tmpregister;
	
    tmpregister = RCC->CFG;
    /* Clear HPRE[6:4] bits */
    tmpregister &= CFG_HPRE_MASK;
    /* Set HPRE[2:0] bits according to sysclk_div value */
    tmpregister |= sysclk_div;
    /* Store the new value */
    RCC->CFG = tmpregister;
}

/**
*\*\name    RCC_ConfigPclk.
*\*\fun     Configures the Low Speed APB clock (PCLK).
*\*\param   hclk_div(APB clock is derived from the AHB clock (HCLK)):
*\*\         - RCC_HCLK_DIV1     APB clock = HCLK
*\*\         - RCC_HCLK_DIV2     APB clock = HCLK/2
*\*\         - RCC_HCLK_DIV4     APB clock = HCLK/4
*\*\         - RCC_HCLK_DIV8     APB clock = HCLK/8
*\*\         - RCC_HCLK_DIV16    APB clock = HCLK/16
*\*\return  none
**/
void RCC_ConfigPclk(uint32_t hclk_div)
{
    uint32_t tmpregister;

    tmpregister = RCC->CFG;
    /* Clear APBPRES[10:8] bits */
    tmpregister &= CFG_APBPRES_MASK;
    /* Set APBPRES[2:0] bits according to RCC_HCLK value */
    tmpregister |= hclk_div;
    /* Store the new value */
    RCC->CFG = tmpregister;
}

/**
*\*\name    RCC_ConfigAdcHclk.
*\*\fun     Configures the ADCHCLK prescaler.
*\*\param   hclk_prescaler(ADCHCLK prescaler):
*\*\         - RCC_ADCHCLK_DIV2        ADCHPRE[2:0] = 000,  HCLK Clock Divided By 2
*\*\         - RCC_ADCHCLK_DIV4        ADCHPRE[2:0] = 011,  HCLK Clock Divided By 4
*\*\         - RCC_ADCHCLK_DIV16       ADCHPRE[2:0] = 101, HCLK Clock Divided By 16
*\*\         - RCC_ADCHCLK_DIV32       ADCHPRE[2:0] = 110, HCLK Clock Divided By 32
*\*\         - RCC_ADCHCLK_DIV_OTHERS  ADCHPRE[2:0] = others, HCLK Clock Divided By 32
*\*\return  none
**/
void RCC_ConfigAdcHclk(uint32_t hclk_prescaler)
{
    uint32_t tmpregister;

    tmpregister = RCC->CFG2;
    /* Clear ADCHPRE[2:0] bits */
    tmpregister &= CFG2_ADCHPRE_MASK;
    /* Set ADCHPRE[2:0] bits according to hclk_prescaler value */
    tmpregister |= hclk_prescaler;

    /* Store the new value */
    RCC->CFG2 = tmpregister;
}

/**
*\*\name    RCC_GetClocksFreqValue.
*\*\fun     Returns the frequencies of different on chip clocks.
*\*\param   RCC_clocks pointer to a RCC_ClocksType structure which will hold
*\*\        the clocks frequencies.
*\*\return  none
**/
void RCC_GetClocksFreqValue(RCC_ClocksType* RCC_Clocks)
{
    uint32_t tmp, presc;
    const uint8_t s_ApbAhbPresTable[16]     = {0, 0, 0, 0, 1, 2, 3, 4, 1, 2, 3, 4, 6, 7, 8, 9};
    const uint8_t s_AdcHclkPresTable[16]    = {1, 2, 3, 4, 6, 8, 10, 12, 16, 32, 32, 32, 32, 32, 32, 32};

    /* Get SYSCLK source -------------------------------------------------------*/
    tmp = RCC->CFG & CFG_SCLKSTS_MASK;

    switch (tmp)
    {
        case RCC_CFG_SCLKSTS_HSI: /* HSI used as system clock */
            RCC_Clocks->SysclkFreq = HSI_VALUE;
            break;
        case RCC_CFG_SCLKSTS_LSI: /* LSI used as system clock */
            RCC_Clocks->SysclkFreq = LSI_VALUE;
            break;

        default:
            RCC_Clocks->SysclkFreq = HSI_VALUE;
            break;
    }
    
    if((RCC->CFG & RCC_CFG_SYSPRES) == RCC_CFG_SYSPRES)
    {
        RCC_Clocks->SysclkFreq = (HSI_VALUE/2);
    }
    else 
    {
        /* No processing */
    }

    /* Compute HCLK, PCLK1, PCLK2 and ADCCLK clocks frequencies ----------------*/
    /* Get HCLK prescaler */
    tmp   = RCC->CFG & RCC_CFG_AHBPRES;
    tmp   = tmp >> 4;
    presc = s_ApbAhbPresTable[tmp];
    /* HCLK clock frequency */
    RCC_Clocks->HclkFreq = RCC_Clocks->SysclkFreq >> presc;
    
    /* Get PCLK prescaler */
    tmp   = RCC->CFG & RCC_CFG_APBPRES;
    tmp   = tmp >> 8;
    presc = s_ApbAhbPresTable[tmp];
    /* PCLK clock frequency */
    RCC_Clocks->PclkFreq = RCC_Clocks->HclkFreq >> presc;

    /* Get ADCHCLK prescaler */
    tmp   = RCC->CFG2 & RCC_CFG2_ADCHPRE;
    presc = s_AdcHclkPresTable[tmp];
    /* ADCHCLK clock frequency */
    RCC_Clocks->AdcHclkFreq = RCC_Clocks->HclkFreq / presc;
				
}

/**
*\*\name    RCC_EnableAHBPeriphClk.
*\*\fun     Enables the AHB peripheral clock.
*\*\param   AHB_periph (AHB peripheral to gates its clock):
*\*\        - RCC_AHB_PERIPH_SQRT  
*\*\        - RCC_AHB_PERIPH_HDIV 
*\*\        - RCC_AHB_PERIPH_ADC    
*\*\        - RCC_AHB_PERIPH_DMA 
*\*\param   Cmd: 
*\*\          - ENABLE  
*\*\          - DISABLE    
*\*\return  none
**/
void RCC_EnableAHBPeriphClk(uint32_t AHB_periph, FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        RCC->AHBPCLKEN |= AHB_periph;
    }
    else
    {
        RCC->AHBPCLKEN &= ~AHB_periph;
    }
}

/**
*\*\name    RCC_EnableAPBPeriphClk.
*\*\fun     Enables the High Speed APB peripheral clock.
*\*\param   APB_periph (APB peripheral to gates its clock):
*\*\        - RCC_APB_PERIPH_GPIO    
*\*\        - RCC_APB_PERIPH_I2C1    
*\*\        - RCC_APB_PERIPH_I2C2    
*\*\        - RCC_APB_PERIPH_PWR
*\*\        - RCC_APB_PERIPH_SPI1     
*\*\        - RCC_APB_PERIPH_SPI2   
*\*\        - RCC_APB_PERIPH_TIM1   
*\*\        - RCC_APB_PERIPH_TIM3   
*\*\        - RCC_APB_PERIPH_TIM4   
*\*\        - RCC_APB_PERIPH_TIM6    
*\*\        - RCC_APB_PERIPH_UART1    
*\*\        - RCC_APB_PERIPH_UART2     
*\*\        - RCC_APB_PERIPH_UART3     
*\*\        - RCC_APB_PERIPH_COMP  
*\*\        - RCC_APB_PERIPH_COMPFILT  
*\*\        - RCC_APB_PERIPH_OPA 
*\*\param   Cmd: 
*\*\          - ENABLE  
*\*\          - DISABLE       
*\*\return none. 
**/
void RCC_EnableAPBPeriphClk(uint32_t APB_periph, FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        RCC->APBPCLKEN |= APB_periph;
    }
    else
    {
        RCC->APBPCLKEN &= ~APB_periph;
    }
}

/**
*\*\name    RCC_EnableAHBPeriphReset.
*\*\fun     AHB peripheral reset.
*\*\param   AHB_periph specifies the AHB peripheral to reset.    
*\*\        - RCC_AHB_PERIPH_SQRT  
*\*\        - RCC_AHB_PERIPH_HDIV 
*\*\        - RCC_AHB_PERIPH_ADC 
*\*\return none.
**/
void RCC_EnableAHBPeriphReset(uint32_t AHB_periph)
{
    RCC->AHBPRST |= AHB_periph;
    RCC->AHBPRST &= ~AHB_periph;   
}

/**
*\*\name    RCC_EnableAPB1PeriphReset.
*\*\fun     Low Speed APB (APB1) peripheral reset.
*\*\param   APB1_periph specifies the APB1 peripheral to reset.
*\*\        - RCC_APB_PERIPH_GPIO    
*\*\        - RCC_APB_PERIPH_I2C1    
*\*\        - RCC_APB_PERIPH_I2C2     
*\*\        - RCC_APB_PERIPH_SPI1   
*\*\        - RCC_APB_PERIPH_SPI2   
*\*\        - RCC_APB_PERIPH_TIM1   
*\*\        - RCC_APB_PERIPH_TIM3   
*\*\        - RCC_APB_PERIPH_TIM4    
*\*\        - RCC_APB_PERIPH_TIM6    
*\*\        - RCC_APB_PERIPH_UART1     
*\*\        - RCC_APB_PERIPH_UART2     
*\*\        - RCC_APB_PERIPH_UART3 
*\*\        - RCC_APB_PERIPH_COMP
*\*\        - RCC_APB_PERIPH_OPA
*\*\return none. 
**/
void RCC_EnableAPBPeriphReset(uint32_t APB_periph)
{
    
    RCC->APBPRST |= APB_periph;
    RCC->APBPRST &= ~APB_periph;
    
}

/**
*\*\name    RCC_ConfigMcoClkPre.
*\*\fun         Configures the MCO System and HSI clock prescaler.
*\*\param   MCO_PLL_prescaler specifies the MCO PLL clock prescaler.
*\*\      This parameter can be on of the following values:
*\*\        - RCC_MCO_CLK_DIV2    MCOPRE[2:0] = 010, System and HSI Clock Divided By 2
*\*\        - RCC_MCO_CLK_DIV3    MCOPRE[2:0] = 011, System and HSI Clock Divided By 3
*\*\        - RCC_MCO_CLK_DIV4    MCOPRE[2:0] = 100, System and HSI Clock Divided By 4
*\*\        - RCC_MCO_CLK_DIV5    MCOPRE[2:0] = 101, System and HSI Clock Divided By 5
*\*\        - RCC_MCO_CLK_DIV6    MCOPRE[2:0] = 110, System and HSI Clock Divided By 6
*\*\        - RCC_MCO_CLK_DIV7    MCOPRE[2:0] = 111, System and HSI Clock Divided By 7
*\*\return  none. 
 */
void RCC_ConfigMcoClkPre(uint32_t MCO_PLL_prescaler)
{
    uint32_t tmpregister;

    tmpregister = RCC->CFG;
    /* Clear MCOPRE[30:28] bits */
    tmpregister &= RCC_MCO_DIV_MASK;
    /* Set MCOPRE[30:28] bits according to MCO_PLL_prescaler value */
    tmpregister |= MCO_PLL_prescaler;

    /* Store the new value */
    RCC->CFG = tmpregister;
}

/**
*\*\name   RCC_ConfigMco.
*\*\fun    Selects the clock source to output on MCO pin.
*\*\param  MCO_source(clock source to output): 
*\*\        - RCC_MCO_NOCLK       No clock selected
*\*\        - RCC_MCO_LSI         LSI oscillator clock selected
*\*\        - RCC_MCO_SYSCLK      System clock selected
*\*\        - RCC_MCO_HSI         HSI oscillator clock selected
*\*\return  none. 
**/
void RCC_ConfigMco(uint32_t MCO_source)
{
    uint32_t tmpregister;

    tmpregister = RCC->CFG;
    /* Clear MCO[27:26] bits */
    tmpregister &= RCC_MCO_MASK;
    /* Set MCO[27:26] bits according to RCC_MCO value */
    tmpregister |= MCO_source;

    /* Store the new value */
    RCC->CFG = tmpregister;
}

/**
*\*\name    RCC_GetFlagStatus.
*\*\fun     Checks whether the specified RCC flag is set or not.
*\*\param   RCC_flag:
*\*\	      - RCC_CTRL_FLAG_HSIRDF           HSI oscillator clock ready
*\*\	      - RCC_CTRL_FLAG_LSICALCF         LSI Calibration finish 
*\*\	      - RCC_CLKINT_FLAG_LSIRDF         LSI oscillator clock ready
*\*\	      - RCC_CTRLSTS_FLAG_PINRSTF       Pin reset
*\*\	      - RCC_CTRLSTS_FLAG_PORRSTF       POR/PDR reset
*\*\	      - RCC_CTRLSTS_FLAG_SFTRSTF       Software reset
*\*\	      - RCC_CTRLSTS_FLAG_IWDGRSTF      Independent Watchdog reset
*\*\	      - RCC_CTRLSTS_FLAG_GLITCHF       Glitch reset
*\*\	      - RCC_CTRLSTS_FLAG_EMCGBNRSTF    EMCGBN reset
*\*\	      - RCC_CTRLSTS_FLAG_EMCGBRSTF     EMCGB reset
*\*\	      - RCC_CTRLSTS_FLAG_LKUPRSTF      M0 lock up reset
*\*\	      - RCC_CTRLSTS_FLAG_HSILOSEF      HSI lose reset
*\*\return  FlagStatus:    
*\*\      	  - SET 
*\*\  	      - RESET
 */
FlagStatus RCC_GetFlagStatus(uint8_t RCC_FLAG)
{
    uint32_t tmp, statusreg;
    FlagStatus bitstatus;

    /* Get the RCC register index */
    tmp = (uint32_t)RCC_FLAG >> 5;
    if (tmp == 1) /* The flag to check is in CTRL register */
    {
        statusreg = RCC->CTRL;
    }
    else if (tmp == 2) /* The flag to check is in CLKINT register */
    {
        statusreg = RCC->CLKINT;
    }
    else /* The flag to check is in CTRLSTS register */
    {
        statusreg = RCC->CTRLSTS;
    }

    /* Get the flag position */
    tmp = (uint32_t)RCC_FLAG & RCC_FLAG_MASK;
    if ((statusreg & ((uint32_t)1 << tmp)) != (uint32_t)RESET)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }

    /* Return the flag status */
    return bitstatus;
}

/**
*\*\name    RCC_ClearResetFlag.
*\*\fun     Clears the RCC reset flags.
*\*\param   none
*\*\return  none
*\*\note  Clear the following flags:
*\*\	      - RCC_CTRLSTS_FLAG_PINRSTF       Pin reset
*\*\	      - RCC_CTRLSTS_FLAG_PORRSTF       POR/PDR reset
*\*\	      - RCC_CTRLSTS_FLAG_SFTRSTF       Software reset
*\*\	      - RCC_CTRLSTS_FLAG_IWDGRSTF      Independent Watchdog reset
*\*\	      - RCC_CTRLSTS_FLAG_GLITCHF       Glitch reset
*\*\	      - RCC_CTRLSTS_FLAG_EMCGBNRSTF    EMCGBN reset
*\*\	      - RCC_CTRLSTS_FLAG_EMCGBRSTF     EMCGB reset
*\*\	      - RCC_CTRLSTS_FLAG_LKUPRSTF      M0 lock up reset
*\*\	      - RCC_CTRLSTS_FLAG_HSILOSEF      HSI lose reset
**/
void RCC_ClearResetFlag(void)
{
    /* Set RMVF bit to clear the reset flags */
    RCC->CTRLSTS |= RCC_REMOVE_RESET_FLAG;
    /* RMVF bit should be reset */
    RCC->CTRLSTS &= ~RCC_REMOVE_RESET_FLAG;
}

/**
*\*\name    RCC_GetIntStatus.
*\*\fun     Checks whether the specified RCC interrupt has occurred or not.
*\*\param   interrupt_flag(RCC interrupt source to check):
*\*\	    -  RCC_INT_LSIRDIF    LSI ready interrupt
*\*\	    -  RCC_INT_HSIRDIF    HSI ready interrupt
*\*\return  The new state of RccInt 
*\*\         - SET
*\*\         - RESET
**/
INTStatus RCC_GetIntStatus(uint8_t interrupt_flag)
{
    INTStatus bitstatus;

    /* Check the status of the specified RCC interrupt */
    if ((RCC->CLKINT & interrupt_flag) != (uint32_t)RESET)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }

    /* Return the RccInt status */
    return bitstatus;
}

/**
*\*\name    RCC_ClrIntPendingBit.
*\*\fun     Clears the RCC's interrupt pending bits.
*\*\param   RccInt specifies the interrupt pending bit to clear.
*\*\	      -  RCC_CLR_LSIRDIF    Clear LSI ready interrupt flag
*\*\	      -  RCC_CLR_HSIRDIF    Clear HSI ready interrupt flag
*\*\return  none. 
 */
void RCC_ClrIntPendingBit(uint32_t interrupt_clear)
{
   /* Software set this bit to clear INT flag. */
    RCC->CLKINT |= interrupt_clear;
}

/**
*\*\name    RCC_EnableEMCReset.
*\*\fun     Configure whether to generate a reset request when an EMC error occurs.
*\*\param   EMC_type:
*\*\          - RCC_EMC_GB
*\*\          - RCC_EMC_GBN
*\*\param   Cmd: 
*\*\          - ENABLE  
*\*\          - DISABLE   
*\*\return  none. 
**/
void RCC_EnableEMCReset(uint32_t EMC_type, FunctionalState Cmd)
{ 
   if (Cmd != DISABLE)
    {
        RCC->EMCCTRL |= (EMC_type<<1);
    }
    else
    {
        RCC->EMCCTRL &= (~(EMC_type<<1));
    }   
}

/**
*\*\name    RCC_EnableEMCDetect.
*\*\fun     Configure whether to enable EMC detection.
*\*\param   EMC_type:
*\*\          - RCC_EMC_GB
*\*\          - RCC_EMC_GBN
*\*\param   Cmd: 
*\*\          - ENABLE  
*\*\          - DISABLE   
*\*\return  none. 
**/
void RCC_EnableEMCDetect(uint32_t EMC_type, FunctionalState Cmd)
{ 
   if (Cmd != DISABLE)
    {
        RCC->EMCCTRL |= EMC_type;
    }
    else
    {
        RCC->EMCCTRL &= ~EMC_type;
    }   
}

/**
*\*\name    RCC_EnableEMCSwitch.
*\*\fun     Configure whether to enable EMC switch.
*\*\param   EMC_type:
*\*\          - RCC_EMC_GB
*\*\          - RCC_EMC_GBN
*\*\param   Cmd: 
*\*\          - ENABLE  
*\*\          - DISABLE   
*\*\return  none. 
**/
void RCC_EnableEMCSwitch(uint32_t EMC_type, FunctionalState Cmd)
{ 
   if (Cmd != DISABLE)
    {
        RCC->EMCCTRL |= (EMC_type<<2);
    }
    else
    {
        RCC->EMCCTRL &= (~(EMC_type<<2));
    }    
}

/**
*\*\name    RCC_ConfigEMCDetectLevel.
*\*\fun     Configures the voltage threshold detected by the EMC.
*\*\param   EMC_type:
*\*\          - RCC_EMC_GB
*\*\          - RCC_EMC_GBN
*\*\param   level (The input parameters must be the following values):
*\*\          - 0x0 ~ 0x3
*\*\return  none
**/
void RCC_ConfigEMCDetectLevel(uint32_t EMC_type, uint8_t level)
{
    uint32_t temp_value;
    
    temp_value = RCC->EMCCTRL;
    if(EMC_type == RCC_EMC_GB)
    {
        /* Clear GBDETSEL[9:8] bits bit */
        temp_value &= EMCCTRL_GBDETSEL_MASK;
        /* Set GBDETSEL[9:8] bits according to level value */
        temp_value |= ((uint32_t)level<<8);
    }
    else
    {
        /* Clear GBNDETSEL[17:16] bits bit */
        temp_value &= EMCCTRL_GBNDETSEL_MASK;
        /* Set GBNDETSEL[17:16] bits according to level value */
        temp_value |= ((uint32_t)level<<16);
        
    }
    /* Store the new value */
    RCC->EMCCTRL = temp_value;
}


/**
*\*\name    RCC_EnableGlitchDetect.
*\*\fun     Configure whether to enable Glitch.
*\*\param   Cmd: 
*\*\          - ENABLE  
*\*\          - DISABLE   
*\*\return  none. 
**/
void RCC_EnableGlitchDetect(FunctionalState Cmd)
{ 
   if (Cmd != DISABLE)
    {
        RCC->EMCCTRL |= (RCC_EMCCTRL_GVDET);
    }
    else
    {
        RCC->EMCCTRL &= (~RCC_EMCCTRL_GVDET);
    }    
}

/**
*\*\name    RCC_EnableGlitchReset.
*\*\fun     Configure whether to enable Glitch reset.
*\*\param   Cmd: 
*\*\          - ENABLE  
*\*\          - DISABLE   
*\*\return  none. 
**/
void RCC_EnableGlitchReset(FunctionalState Cmd)
{ 
   if (Cmd != DISABLE)
    {
        RCC->EMCCTRL |= (RCC_EMCCTRL_GVRST);
    }
    else
    {
        RCC->EMCCTRL &= (~RCC_EMCCTRL_GVRST);
    }    
}

/**
*\*\name    RCC_EnableGlitchSwitch.
*\*\fun     Configure whether to enable Glitch switch.
*\*\param   Cmd: 
*\*\          - ENABLE  
*\*\          - DISABLE   
*\*\return  none. 
**/
void RCC_EnableGlitchSwitch(FunctionalState Cmd)
{ 
   if (Cmd != DISABLE)
    {
        RCC->EMCCTRL |= (RCC_EMCCTRL_GVSW);
    }
    else
    {
        RCC->EMCCTRL &= (~RCC_EMCCTRL_GVSW);
    }    
}


/**
*\*\name    RCC_ConfigGlitchDetectLevel.
*\*\fun     Configures the voltage threshold detected by the Glitch.
*\*\param   level (The input parameters must be the following values):
*\*\        - 0x0 ~ 0x1F
*\*\return  none
**/
void RCC_ConfigGlitchDetectLevel(uint8_t level)
{
    uint32_t temp_value;
    
    temp_value = RCC->EMCCTRL;
	/* Clear GVDETSEL[4:0] bits bit */
	temp_value &= EMCCTRL_GVDETSEL_MASK;
	/* Set GVDETSEL[4:0] bits according to level value */
	temp_value |= (uint32_t)level ;
    /* Store the new value */
    RCC->EMCCTRL = temp_value;
}

/**
*\*\name    RCC_EnableM0LockupReset.
*\*\fun     Configure whether to enable M0 lockup reset.
*\*\param   Cmd: 
*\*\          - ENABLE  
*\*\          - DISABLE   
*\*\return  none. 
**/
void RCC_EnableM0LockupReset(FunctionalState Cmd)
{ 
   if (Cmd != DISABLE)
    {
        RCC->EMCCTRL |= (RCC_EMCCTRL_LKUPRSTEN);
    }
    else
    {
        RCC->EMCCTRL &= (~RCC_EMCCTRL_LKUPRSTEN);
    }    
}

/**
*\*\name    RCC_ConfigTimClk.
*\*\fun     Configures the TIM1/3/4 clock source(TIMCLK).
*\*\param   timer_clksrc(TIM clock source):
*\*\         - RCC_TIM_CLKSRC_SYSCLK
*\*\         - RCC_TIM_CLKSRC_HCLK  
*\*\return  none
**/
void RCC_ConfigTimClk(uint32_t timer_clksrc)  
{
    uint32_t temp_value;

    temp_value = RCC->CFG;
    /* Clear TIMXCLK_SEL bits */
    temp_value &= RCC_TIM_CLKSRC_MASK;
    /* Set TIMXCLK_SEL bits according to timer_clksrc value */
    temp_value |= timer_clksrc;

    /* Store the new value */
    RCC->CFG = temp_value;
}

/**
*\*\name    RCC_ConfigTim6Clk.
*\*\fun     Configures the TIM6 clock source(TIM6CLK).
*\*\param   timer_clksrc(TIM6 clock source):
*\*\         - RCC_TIM6_CLKSRC_SYSCLK
*\*\         - RCC_TIM6_CLKSRC_HCLK  
*\*\return  none
**/
void RCC_ConfigTim6Clk(uint32_t timer_clksrc)  
{
    uint32_t temp_value;

    temp_value = RCC->CFG;
    /* Clear TIM6CLK_SEL bits */
    temp_value &= RCC_TIM6_CLKSRC_MASK;
    /* Set TIM6CLK_SEL bits according to timer_clksrc value */
    temp_value |= timer_clksrc;

    /* Store the new value */
    RCC->CFG = temp_value;
}

/**
*\*\name    RCC_ConfigUart3Clk.
*\*\fun     Configures the UART3 clock source(UART3CLK).
*\*\param   uart3_clksrc(UART3 clock source):
*\*\         - RCC_UART3_CLKSRC_PCLK
*\*\         - RCC_UART3_CLKSRC_LSI  
*\*\return  none
**/
void RCC_ConfigUart3Clk(uint32_t uart3_clksrc)  
{
    uint32_t temp_value;

    temp_value = RCC->CFG;
    /* Clear UART3CLK_SEL bits */
    temp_value &= RCC_UART3_CLKSRC_MASK;
    /* Set UART3CLK_SEL bits according to timer_clksrc value */
    temp_value |= uart3_clksrc;

    /* Store the new value */
    RCC->CFG = temp_value;
}

/**
*\*\name    RCC_ConfigIOFilter.
*\*\fun     Configures the Speed of GPIO fliter.
*\*\param   ioflitclk_div value(IO Fliter clock is derived from the AHB clock (HCLK)):
*\*\        -0 ~ 0xF
*\*\return  none
**/
void RCC_ConfigIOFilter(uint32_t ioflitclk_div)
{
    uint32_t tmpregister;

    tmpregister = RCC->TIMFILTCFG;
    /* Clear IOFLITCLK[31:28] bits */
    tmpregister &= TIMFILTCFG_IOFLITCLK_MASK;
    /* Set IOFLITCLK[31:28] bits according to RCC_HCLK value */
    tmpregister |= ioflitclk_div;
    /* Store the new value */
    RCC->TIMFILTCFG = tmpregister;
}

/**
*\*\name    RCC_ConfigTIM4Filter.
*\*\fun     Configures the Speed of TIM4 fliter.
*\*\param   tim4flitclk_div value(TIM4 Fliter clock is derived from the AHB clock (HCLK)):
*\*\        -0 ~ 0x1F
*\*\return  none
**/
void RCC_ConfigTIM4Filter(uint32_t tim4flitclk_div)
{
    uint32_t tmpregister;

    tmpregister = RCC->TIMFILTCFG;
    /* Clear TIM4FILTCLK[20:16] bits */
    tmpregister &= TIMFILTCFG_TIM4FLITCLK_MASK;
    /* Set TIM4FILTCLK[20:16] bits according to RCC_HCLK value */
    tmpregister |= tim4flitclk_div;
    /* Store the new value */
    RCC->TIMFILTCFG = tmpregister;
}

/**
*\*\name    RCC_ConfigTIM3Filter.
*\*\fun     Configures the Speed of TIM3 fliter.
*\*\param   tim3flitclk_div value(TIM3 Fliter clock is derived from the AHB clock (HCLK)):
*\*\        -0 ~ 0x1F
*\*\return  none
**/
void RCC_ConfigTIM3Filter(uint32_t tim3flitclk_div)
{
    uint32_t tmpregister;

    tmpregister = RCC->TIMFILTCFG;
    /* Clear TIM3FILTCLK[12:8] bits */
    tmpregister &= TIMFILTCFG_TIM3FLITCLK_MASK;
    /* Set TIM3FILTCLK[12:8] bits according to RCC_HCLK value */
    tmpregister |= tim3flitclk_div;
    /* Store the new value */
    RCC->TIMFILTCFG = tmpregister;
}

/**
*\*\name    RCC_ConfigTIM1Filter.
*\*\fun     Configures the Speed of TIM1 fliter.
*\*\param   tim1flitclk_div value(TIM1 Fliter clock is derived from the AHB clock (HCLK)):
*\*\        -0 ~ 0x1F
*\*\return  none
**/
void RCC_ConfigTIM1Filter(uint32_t tim1flitclk_div)
{
    uint32_t tmpregister;

    tmpregister = RCC->TIMFILTCFG;
    /* Clear TIM1FILTCLK[4:0] bits */
    tmpregister &= TIMFILTCFG_TIM1FLITCLK_MASK;
    /* Set TIM1FILTCLK[4:0] bits according to RCC_HCLK value */
    tmpregister |= tim1flitclk_div;
    /* Store the new value */
    RCC->TIMFILTCFG = tmpregister;
}

/**
*\*\name    RCC_ConfigLSICalibPeriod.
*\*\fun     Configure LSI Calibration Period.
*\*\param   lsi_period:
*\*\	     - RCC_LSICAL_PERIOD_128   Count the HSI clock within 128 LSI cycles     
*\*\	     - RCC_LSICAL_PERIOD_256   Count the HSI clock within 256 LSI cycles
*\*\	     - RCC_LSICAL_PERIOD_512   Count the HSI clock within 512 LSI cycles
*\*\	     - RCC_LSICAL_PERIOD_1024  Count the HSI clock within 1024 LSI cycles
*\*\return  none
**/
void RCC_ConfigLSICalibPeriod(uint32_t lsi_period)  
{
    uint32_t temp_value;

    temp_value = RCC->CTRL;
    /* Clear LSICALLEN bits */
    temp_value &= CTRL_LSICALLEN_MASK;
    /* Set LSICALLEN bits according to lsi_period value */
    temp_value |= (lsi_period << 9);

    /* Store the new value */
    RCC->CTRL = temp_value;
}

/**
*\*\name    RCC_EnableLSICalibration.
*\*\fun     Configure whether to start LSI Calibration calculation.
*\*\param   Cmd: 
*\*\          - ENABLE  
*\*\          - DISABLE   
*\*\return  none. 
**/
void RCC_EnableLSICalibration(FunctionalState Cmd)
{ 
   if (Cmd != DISABLE)
    {
        RCC->CTRL |= (RCC_CTRL_LSICALEN);
    }
    else
    {
        RCC->CTRL &= (~RCC_CTRL_LSICALEN);
    }    
}

/**
*\*\name    RCC_GetHSICalibPeriod
*\*\fun     Gets the HSI(64MHz) captures the number of LSI cycles within the clock calibration period.
*\*\param   none
*\*\return  HSI captures value.
**/
uint32_t RCC_GetHSICalibPeriod(void)
{   
    /* Get the LSICAL value */
    return (uint32_t)(RCC->LSICAL);
    
}


