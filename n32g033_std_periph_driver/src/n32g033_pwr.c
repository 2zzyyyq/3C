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
*\*\file n32g033_pwr.c
*\*\author Nsing
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/
#include "n32g033_rcc.h"
#include "n32g033_pwr.h"

/** PWR Driving Functions Declaration **/

/**
*\*\name    PWR_PvdEnable.
*\*\fun     Enables or disables the Power Voltage Detector(PVD).
*\*\param   Cmd: 
*\*\          - ENABLE  
*\*\          - DISABLE 
*\*\return  none
**/
void PWR_PvdEnable(FunctionalState Cmd)
{
    if(Cmd == ENABLE)
    {
        PWR->CTRL |= PWR_CTRL_PVDEN;
    }else
    {
        PWR->CTRL &= (~PWR_CTRL_PVDEN);
    }
}

/**
*\*\name    PWR_PVDFilterWidthSet.
*\*\fun     Adjusting the PVD Filter Control Count value.
*\*\param   filter_value(Filter Width = (1/fLSI) * filter_value):
*\*\        -0 ~ 0x1F
*\*\return  none
**/ 
void PWR_PVDFilterWidthSet(uint8_t filter_value) 
{
    uint32_t temp_value;

    temp_value = PWR->CTRL;
    /* Clear PVD_FILTER_LENGTH[18:14] bits */
    temp_value &= PWR_CTRL_PVDCNT_MASK;
    /* Set the PVD_FILTER_LENGTH[18:14] bits according to filter_value */
    temp_value |= (uint32_t)filter_value << 14; 
    /* Store the new value */
    PWR->CTRL = temp_value;
}

/**
*\*\name    PWR_PVDLevelConfig.
*\*\fun     Configures the voltage threshold detected by the Power Voltage Detector(PVD).
*\*\param   level (The input parameters must be the following values):
*\*\          - PWR_PVD_LEVEL_2V
*\*\          - PWR_PVD_LEVEL_2V2
*\*\          - PWR_PVD_LEVEL_2V4
*\*\          - PWR_PVD_LEVEL_2V8
*\*\          - PWR_PVD_LEVEL_3V2
*\*\          - PWR_PVD_LEVEL_3V6
*\*\          - PWR_PVD_LEVEL_4V0
*\*\          - PWR_PVD_LEVEL_4V4
*\*\return  none
**/
void PWR_PVDLevelConfig(uint32_t level)
{
    uint32_t temp_value;
    
    temp_value = PWR->CTRL;
    /* Clear PLS[8:5] bits bit */
    temp_value &= PWR_CTRL_PLS_MASK;
    /* Set PLS[8:5] bits according to level value */
    temp_value |= level;
    /* Store the new value */
    PWR->CTRL = temp_value;
}

/**
*\*\name    PWR_NRSTFilterWidthSet.
*\*\fun     Adjusting the NRST Filter Control Count value.
*\*\param   filter_value(Filter Width = (1/fSYSCLK) * filter_value):
*\*\        -0 ~ 0xF
*\*\return  none
**/ 
void PWR_NRSTFilterWidthSet(uint16_t filter_value) 
{
    uint32_t temp_value;

    temp_value = PWR->CTRL;
    /* Clear NRSTCNT[22:19] bits */
    temp_value &= PWR_CTRL_NRSTCNT_MASK;
    /* Set the NRSTCNT[22:19] bits according to filter_value */
    temp_value |= (uint32_t)filter_value << 19; 
    /* Store the new value */
    PWR->CTRL = temp_value;
}

/**
*\*\name    PWR_EnterSLEEPMode.
*\*\fun     Enters SLEEP mode.
*\*\param   status (The input parameters must be the following values):
*\*\          - PWR_SLEEP_ON_EXIT
*\*\          - PWR_SLEEP_NOW
*\*\param   enter_mode (The input parameters must be the following values):
*\*\          - PWR_SLEEPENTRY_WFI enter SLEEP mode with WFI instruction
*\*\          - PWR_SLEEPENTRY_WFE enter SLEEP mode with WFE instruction
*\*\return  none
**/
void PWR_EnterSLEEPMode(uint8_t status, uint8_t enter_mode)
{
    /* CLEAR SLEEPDEEP bit of Cortex System Control Register */
    SCB->SCR &= (uint32_t)~((uint32_t)SCB_SCR_SLEEPDEEP);
    
    /* Select SLEEPONEXIT mode entry */
    if (status == PWR_SLEEP_ON_EXIT)
    {
        /* the MCU enters Sleep mode as soon as it exits the lowest priority INTSTS */
        SCB->SCR |= SCB_SCR_SLEEPONEXIT;
    }
    else 
    {
        /* Sleep-now */
        SCB->SCR &= (uint32_t)~((uint32_t)SCB_SCR_SLEEPONEXIT);
    }

    /* Select SLEEP mode entry */
    if (enter_mode == PWR_SLEEPENTRY_WFI)
    {
        /* Request Wait For Interrupt */
        __WFI();
    }
    else
    {
        /* Request Wait For Event */
        __SEV();
        __WFE();
        __WFE();
    }
}

/**
*\*\name    PWR_EnterSTOPMode.
*\*\fun     Enters STOP mode.
*\*\param   enter_mode (The input parameters must be the following values):
*\*\          - PWR_STOPENTRY_WFI (enter STOP mode with WFI instruction)
*\*\          - PWR_STOPENTRY_WFE (enter STOP mode with WFE instruction)
*\*\return  none
**/
void PWR_EnterSTOPMode(uint8_t enter_mode)
{
    /* Set SLEEPDEEP bit of Cortex System Control Register */
    SCB->SCR |= SCB_SCR_SLEEPDEEP;

    /* Select STOP mode entry */
    if (enter_mode == PWR_STOPENTRY_WFI)
    {
        /* Request Wait For Interrupt */
        __WFI();
    }
    else
    {
        /* Request Wait For Event */
        __SEV();
        __WFE();
        __WFE();
    }
    /* Reset SLEEPDEEP bit of Cortex System Control Register */
    SCB->SCR &= (uint32_t)~((uint32_t)SCB_SCR_SLEEPDEEP);
}

/**
*\*\name    PWR_CTRL2WriteProtectionEnable.
*\*\fun     Enable the PWR_CTRL2 registers write protection.
*\*\param   none
*\*\return  none
*\*\note    This register has write protection.Before writing PWR_CTRL2, PWR_CTRL2WriteProtectionEnable()
*\*\        function must be called, and then write real value to PWR_CTRL2
**/
void PWR_CTRL2WriteProtectionEnable(void) 
{
    uint32_t temp_value;

    temp_value = PWR->CTRL2;
    
    /* Clear KEY bits*/
    temp_value &= PWR_CTRL2_KEYS_MASK;
    /* Set KEY bits*/
    temp_value |= PWR_CTRL2_KEYS;
    /* Store the new value */
    PWR->CTRL2 = temp_value;
}

/**
*\*\name    PWR_GetFlagStatus.
*\*\fun     Checks whether the specified PWR flag is set or not.
*\*\param   flag (The input parameters must be the following values):
*\*\          - PWR_PVDO_FLAG       PVD Output flag
*\*\return  SET or RESET.
**/
FlagStatus PWR_GetFlagStatus(uint32_t PWR_FLAG)
{
    FlagStatus bitstatus;
	
    if ((PWR->CTRLSTS & PWR_FLAG) != (uint32_t)RESET)
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
*\*\name    DBG_ConfigPeriph.
*\*\fun     Configures the specified peripheral run when the MCU under Debug mode.
*\*\param   DBG_Periph (The input parameters must be the following values):
*\*\          - PWR_DBG_IWDG    IWDG stopped when Core is halted
*\*\          - PWR_DBG_TIM1    TIM1 counter stopped when Core is halted
*\*\          - PWR_DBG_TIM3    TIM3 counter stopped when Core is halted
*\*\          - PWR_DBG_TIM4    TIM4 counter stopped when Core is halted
*\*\          - PWR_DBG_I2C1    I2C1 SMBUS timeout mode stopped stopped when Core is halted
*\*\          - PWR_DBG_I2C2    I2C2 SMBUS timeout mode stopped stopped when Core is halted
*\*\          - PWR_DBG_TIM6    TIM6 counter stopped when Core is halted
*\*\param   Cmd: 
*\*\          - ENABLE  
*\*\          - DISABLE 
*\*\return  none
**/
void DBG_ConfigPeriph(uint32_t DBG_Periph, FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        PWR->DBG_CTRL |= DBG_Periph;
    }
    else
    {
        PWR->DBG_CTRL &= ~DBG_Periph;
    }
}

/**
*\*\name    PWR_EnableIWDGReset.
*\*\fun     Configure whether to generate a reset request when the IWDG counter reaches 0.
*\*\param   Cmd: 
*\*\          - ENABLE  
*\*\          - DISABLE   
*\*\return  none. 
**/
void PWR_EnableIWDGReset(FunctionalState Cmd)
{ 
   if(Cmd == ENABLE)
   {
       /* Set IWDGRSTEN bit */
       PWR->CTRL |= PWR_IWDGRST_ENABLE;
   }
   else
   {
       /* Reset IWDGRSTEN bit */
       PWR->CTRL &= (~PWR_IWDGRST_ENABLE);
   }
    
}
