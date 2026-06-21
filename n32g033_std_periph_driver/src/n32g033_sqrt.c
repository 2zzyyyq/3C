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
*\*\file n32g033_sqrt.c
*\*\author Nsing
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/
#include "n32g033_sqrt.h"

/** N32G033_StdPeriph_Driver **/


/**
*\*\name    SQRT_ConfigBusHold.
*\*\fun     Enable or disable the bus hold if read the result when calculating of SQRT module.
*\*\param   Cmd 
*\*\          - ENABLE  
*\*\          - DISABLE 
*\*\return  none 
**/
void SQRT_ConfigBusHold(FunctionalState Cmd)
{
    if(Cmd != DISABLE)
    {
        SQRT->CTRLSTS |= SQRT_CTRLSTS_BUSHOLD;
    }
    else
    {
        SQRT->CTRLSTS &= (~SQRT_CTRLSTS_BUSHOLD);
    }
}


/**
*\*\name    SQRT_ConfigAutoStart.
*\*\fun     Enable or disable the auto start of SQRT calculating.
*\*\param   Cmd 
*\*\          - ENABLE  
*\*\          - DISABLE 
*\*\return  none 
**/
void SQRT_ConfigAutoStart(FunctionalState Cmd)
{
    if(Cmd != DISABLE)
    {
        SQRT->CTRLSTS |= SQRT_CTRLSTS_AUTOSTART;
    }
    else
    {
        SQRT->CTRLSTS &= (~SQRT_CTRLSTS_AUTOSTART);
    }
}


/**
*\*\name    SQRT_GetFlagStatus.
*\*\fun     Check whether the SQRT calculation is finished or not.
*\*\param   None 
*\*\return  The SQRT calculation status (SET or RESET). 
**/
FlagStatus SQRT_GetFlagStatus(void)
{
    FlagStatus bitstatus;

    if((SQRT->CTRLSTS & SQRT_CTRLSTS_SQRTDF) != (uint32_t)RESET)
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
*\*\name    SQRT_SetRADICAND_Data.
*\*\fun     Set the radicand of square root calculation.
*\*\param   data 
*\*\          - 32 bit unsigned interger data 
*\*\return  none. 
**/
void SQRT_SetRADICAND_Data(uint32_t data)
{
    SQRT->RADICAND = data;
}


/**
*\*\name    SQRT_GetRADICAND_Data.
*\*\fun     Get the radicand of square root calculation.
*\*\param   none
*\*\return  32 bit unsigned interger data. 
**/
uint32_t SQRT_GetRADICAND_Data(void)
{
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    return SQRT->RADICAND;
}


/**
*\*\name    SQRT_GetROOT_Data.
*\*\fun     Get the square root of radicand.
*\*\param   none
*\*\return  32 bit unsigned interger data. 
**/
uint32_t SQRT_GetROOT_Data(void)
{
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    return SQRT->ROOT;
}

/**
*\*\name    SQRT_Start.
*\*\fun     Start the SQRT Calculation.
*\*\param   none
*\*\return  none. 
**/
void SQRT_ConfigSingleStart(void)
{
    /* Start SQRT Calculation */
    SQRT->CTRLSTS |= SQRT_CTRLSTS_SQRTSTART;
}


/**
*\*\name    SQRT_Enable.
*\*\fun     Enable or Disable the SQRT module.
*\*\param   Cmd 
*\*\          - ENABLE  
*\*\          - DISABLE 
*\*\return  none. 
**/
void SQRT_Enable(FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        SQRT->CTRLSTS |= SQRT_CTRLSTS_SQRTEN;
    }
    else
    {
        SQRT->CTRLSTS &= (~SQRT_CTRLSTS_SQRTEN);
    }
}
