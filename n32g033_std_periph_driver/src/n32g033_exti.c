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
*\*\file n32g033_exti.c
*\*\author Nsing
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/
#include "n32g033_exti.h"

/**
*\*\name    EXTI_DeInit.
*\*\fun     Reset the EXTI registers.
*\*\return  none
**/
void EXTI_DeInit(void)
{
    EXTI->IMASK  &= ~EXTI_IMASK_MASK;
    EXTI->EMASK  &= ~EXTI_EMASK_MASK;
    EXTI->RT_CFG &= ~EXTI_RT_CFG_MASK;
    EXTI->FT_CFG &= ~EXTI_FT_CFG_MASK;
    EXTI->PEND   = EXTI_PEND_MASK;
}

/**
*\*\name    EXTI_InitPeripheral.
*\*\fun     Initializes the EXTI according to EXTI_InitStruct.
*\*\param   EXTI_InitStruct(The input parameters must be the following values) :
*\*\          - EXTI_Line
*\*\            - EXTI_LINENONE
*\*\            - EXTI_LINE0              
*\*\            - EXTI_LINE1            
*\*\            - EXTI_LINE2              
*\*\            - EXTI_LINE3             
*\*\            - EXTI_LINE4              
*\*\            - EXTI_LINE5 
*\*\            - EXTI_LINE6              
*\*\            - EXTI_LINE7                
*\*\            - EXTI_LINE8              
*\*\            - EXTI_LINE9              
*\*\            - EXTI_LINE10   
*\*\          - EXTI_Mode
*\*\            - EXTI_Mode_Interrupt  
*\*\            - EXTI_Mode_Event
*\*\          - EXTI_Trigger
*\*\            - EXTI_Trigger_Rising        
*\*\            - EXTI_Trigger_Falling       
*\*\            - EXTI_Trigger_Rising_Falling
*\*\          - EXTI_LineCmd:
*\*\            - ENABLE
*\*\            - DISABLE 
*\*\return  none
**/
void EXTI_InitPeripheral(const EXTI_InitType* EXTI_InitStruct)
{
    uint32_t tmp;

    tmp = (uint32_t)EXTI_BASE;

    if (EXTI_InitStruct->EXTI_LineCmd != DISABLE)
    {
        /* Clear EXTI line configuration */
        EXTI->IMASK &= ~EXTI_InitStruct->EXTI_Line;
        EXTI->EMASK &= ~EXTI_InitStruct->EXTI_Line;

        tmp += EXTI_InitStruct->EXTI_Mode;

        *(__IO uint32_t*)tmp |= EXTI_InitStruct->EXTI_Line;

        /* Clear Rising Falling edge configuration */
        EXTI->RT_CFG &= ~EXTI_InitStruct->EXTI_Line;
        EXTI->FT_CFG &= ~EXTI_InitStruct->EXTI_Line;

        /* Select the trigger for the selected external interrupts */
        if (EXTI_InitStruct->EXTI_Trigger == EXTI_Trigger_Rising_Falling)
        {
            /* Rising Falling edge */
            EXTI->RT_CFG |= EXTI_InitStruct->EXTI_Line;
            EXTI->FT_CFG |= EXTI_InitStruct->EXTI_Line;
        }
        else
        {
            tmp = (uint32_t)EXTI_BASE;
            tmp += EXTI_InitStruct->EXTI_Trigger;

            *(__IO uint32_t*)tmp |= EXTI_InitStruct->EXTI_Line;
        }
    }
    else
    {
        tmp += EXTI_InitStruct->EXTI_Mode;

        /* Disable the selected external lines */
        *(__IO uint32_t*)tmp &= ~EXTI_InitStruct->EXTI_Line;
    }
}

/**
*\*\name    EXTI_InitStruct.
*\*\fun     Fills each EXTI_InitStruct member with its default value.
*\*\param   EXTI_StructInit :   
*\*\            - - Pointer to the EXTI_InitType structure which will be initialized.
*\*\return  none
**/
void EXTI_InitStruct(EXTI_InitType* EXTI_StructInit)
{
    EXTI_StructInit->EXTI_Line    = EXTI_LINENONE;
    EXTI_StructInit->EXTI_Mode    = (uint8_t)EXTI_Mode_Interrupt;
    EXTI_StructInit->EXTI_Trigger = (uint8_t)EXTI_Trigger_Falling;
    EXTI_StructInit->EXTI_LineCmd = DISABLE;
}

/**
*\*\name    EXTI_TriggerSWInt.
*\*\fun     Generates a Software interrupt.
*\*\param   EXTI_Line(The input parameters must be the following values) :   
*\*\            - EXTI_LINE0              
*\*\            - EXTI_LINE1            
*\*\            - EXTI_LINE2              
*\*\            - EXTI_LINE3             
*\*\            - EXTI_LINE4              
*\*\            - EXTI_LINE5 
*\*\            - EXTI_LINE6              
*\*\            - EXTI_LINE7                
*\*\            - EXTI_LINE8              
*\*\            - EXTI_LINE9              
*\*\            - EXTI_LINE10    
*\*\return  none
**/
void EXTI_TriggerSWInt(uint32_t EXTI_Line)
{
    EXTI->SWIE |= EXTI_Line;
}

/**
*\*\name    EXTI_GetStatusFlag.
*\*\fun     Get EXTI line flag status.
*\*\param   EXTI_Line(The input parameters must be the following values) :   
*\*\            - EXTI_LINE0              
*\*\            - EXTI_LINE1            
*\*\            - EXTI_LINE2              
*\*\            - EXTI_LINE3             
*\*\            - EXTI_LINE4              
*\*\            - EXTI_LINE5 
*\*\            - EXTI_LINE6              
*\*\            - EXTI_LINE7                
*\*\            - EXTI_LINE8              
*\*\            - EXTI_LINE9              
*\*\            - EXTI_LINE10   
*\*\return  SET or RESET
**/
FlagStatus EXTI_GetStatusFlag(uint32_t EXTI_Line)
{
    FlagStatus bitstatus;

    if ((EXTI->PEND & EXTI_Line) != (uint32_t)RESET)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
    return bitstatus;
}


/**
*\*\name    EXTI_ClrStatusFlag.
*\*\fun     Clear EXTI line flag status.
*\*\param   EXTI_Line :   
*\*\            - EXTI_LINE0              
*\*\            - EXTI_LINE1            
*\*\            - EXTI_LINE2              
*\*\            - EXTI_LINE3             
*\*\            - EXTI_LINE4              
*\*\            - EXTI_LINE5 
*\*\            - EXTI_LINE6              
*\*\            - EXTI_LINE7                
*\*\            - EXTI_LINE8              
*\*\            - EXTI_LINE9              
*\*\            - EXTI_LINE10    
*\*\return  none
**/
void EXTI_ClrStatusFlag(uint32_t EXTI_Line)
{
    EXTI->PEND = EXTI_Line;
}

/**
*\*\name    EXTI_GetITStatus.
*\*\fun     GET EXTI line interrupt status.
*\*\param   exti_line :   
*\*\            - EXTI_LINE0              
*\*\            - EXTI_LINE1            
*\*\            - EXTI_LINE2              
*\*\            - EXTI_LINE3             
*\*\            - EXTI_LINE4              
*\*\            - EXTI_LINE5 
*\*\            - EXTI_LINE6              
*\*\            - EXTI_LINE7                
*\*\            - EXTI_LINE8              
*\*\            - EXTI_LINE9              
*\*\            - EXTI_LINE10   
*\*\return  SET or RESET
**/
INTStatus EXTI_GetITStatus(uint32_t EXTI_Line)
{
    INTStatus bitstatus;
    uint32_t enablestatus;

    enablestatus = EXTI->IMASK & EXTI_Line;
    if (((EXTI->PEND & EXTI_Line) != (uint32_t)RESET) && (enablestatus != (uint32_t)RESET))
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
    return bitstatus;
}

/**
*\*\name    EXTI_ClrITPendBit.
*\*\fun     Clear EXTI line interrupt pend bit.
*\*\param   exti_line :   
*\*\            - EXTI_LINE0              
*\*\            - EXTI_LINE1            
*\*\            - EXTI_LINE2              
*\*\            - EXTI_LINE3             
*\*\            - EXTI_LINE4              
*\*\            - EXTI_LINE5 
*\*\            - EXTI_LINE6              
*\*\            - EXTI_LINE7                
*\*\            - EXTI_LINE8              
*\*\            - EXTI_LINE9              
*\*\            - EXTI_LINE10   
*\*\return  none
**/
void EXTI_ClrITPendBit(uint32_t EXTI_Line)
{
    EXTI->PEND = EXTI_Line;
}
