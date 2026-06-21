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
*\*\file n32g033_hdiv.c
*\*\author Nsing
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/
#include "n32g033_hdiv.h"

/** N32G033_StdPeriph_Driver **/

/**
*\*\name    HDIV_ConfigBusHold.
*\*\fun     Enable or disable the bus hold if read the result when calculating.
*\*\param   Cmd 
*\*\          - ENABLE  
*\*\          - DISABLE 
*\*\return  none 
**/
void HDIV_ConfigBusHold(FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        HDIV->CTRLSTS |= HDIV_BUSHOLDEN;
    }
    else
    {
        HDIV->CTRLSTS &= (~HDIV_BUSHOLDEN);
    }
}


/**
*\*\name    HDIV_ConfigAutoStart.
*\*\fun     Enable or disable the auto start of HDIV calculating.
*\*\param   Cmd 
*\*\          - ENABLE  
*\*\          - DISABLE 
*\*\return  none 
**/
void HDIV_ConfigAutoStart(FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        HDIV->CTRLSTS |= HDIV_AUTOSTARTCAL;
    }
    else
    {
        HDIV->CTRLSTS &= (~HDIV_AUTOSTARTCAL);
    }
}


/**
*\*\name    HDIV_ConfigDataType.
*\*\fun     Is the data type of dividend defined as signed or unsigned.
*\*\param   Cmd 
*\*\          - ENABLE    signed data
*\*\          - DISABLE   unsigned data
*\*\return  none 
**/
void HDIV_ConfigDataType(FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        HDIV->CTRLSTS |= HDIV_SIGNDATAEN;
    }
    else
    {
        HDIV->CTRLSTS &= (~HDIV_SIGNDATAEN);
    }
}


/**
*\*\name    HDIV_GetFlagStatus.
*\*\fun     Check whether the specified HDIV flag is set or not.
*\*\param   HDIV_FLAG: (This parameter can be one of the following values)
*\*\          - HDIV_FLAG_DF        HDIV done flag  
*\*\          - HDIV_FLAG_DIVBY0    The divisor is 0 flag 
*\*\return  The SQRT calculation status (SET or RESET). 
**/
FlagStatus HDIV_GetFlagStatus(uint32_t HDIV_FLAG)
{
    FlagStatus bitstatus;

    if(HDIV_FLAG==HDIV_FLAG_DIVBY0)
    {
        if ((HDIV->DIVBY0 & HDIV_FLAG) != (uint32_t)RESET)
        {
                bitstatus = SET;
        }
        else
        {
                bitstatus = RESET;
        }
    }
    else
    {
        if ((HDIV->CTRLSTS & HDIV_FLAG) != (uint32_t)RESET)
        {
            bitstatus = SET;
        }
        else
        {
            bitstatus = RESET;
        }
    }
    return bitstatus;
}


/**
*\*\name    HDIV_SetUnsignedDIVIDEND_Data.
*\*\fun     Set 32 bit unsigned interger dividend data through the HDIV peripheral.
*\*\param   data 
*\*\          - 32 bit unsigned interger data 
*\*\return  none 
**/
void HDIV_SetUnsignedDIVIDEND_Data(uint32_t data)
{
    /* 32 bit unsigned interger dividend Data */
    HDIV->DIVIDEND = data;
}


/**
*\*\name    HDIV_GetUnsignedDIVIDEND_Data.
*\*\fun     Get 32 bit unsigned interger dividend data through the HDIV peripheral.
*\*\param   none 
*\*\return  32 bit unsigned interger dividend data 
**/
uint32_t HDIV_GetUnsignedDIVIDEND_Data(void)
{
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    /* 32 bit unsigned interger dividend Data */
    return HDIV->DIVIDEND;
}

/**
*\*\name    HDIV_SetUnsignedDIVISOR_Data.
*\*\fun     Set 32 bit unsigned interger divisor data through the HDIV peripheral.
*\*\param   data 
*\*\          - 32 bit unsigned interger data 
*\*\return  none 
**/
void HDIV_SetUnsignedDIVISOR_Data(uint32_t data)
{
    /* 32 bit unsigned interger divisor Data */
    HDIV->DIVISOR = data;
}


/**
*\*\name    HDIV_GetUnsignedDIVISOR_Data.
*\*\fun     Get 32 bit unsigned interger divisor data through the HDIV peripheral.
*\*\param   none 
*\*\return  32 bit unsigned interger divisor data 
**/
uint32_t HDIV_GetUnsignedDIVISOR_Data(void)
{
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    /* 32 bit unsigned interger divisor Data */
    return HDIV->DIVISOR;
}

/**
*\*\name    HDIV_GetUnsignedQUOTIENT_Data.
*\*\fun     Get Unsigned Quotient calculated by the divider data through the HDIV peripheral.
*\*\param   none 
*\*\return  Unsigned Quotient 
**/
uint32_t HDIV_GetUnsignedQUOTIENT_Data(void)
{
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    /* Quotient calculated by the divider Data */
    return HDIV->QUOTIENT;
}


/**
*\*\name    HDIV_GetUnsignedREMAINDER_Data.
*\*\fun     Get Unsigned Remainder calculated by the divider data through the HDIV peripheral.
*\*\param   none 
*\*\return  Unsigned Remainder 
**/
uint32_t HDIV_GetUnsignedREMAINDER_Data(void)
{
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    /* Remainder calculated by the divider */
    return HDIV->REMAINDER;
}


/**
*\*\name    HDIV_Start.
*\*\fun     Start the HDIV Single Calculation.
*\*\param   none 
*\*\return  none 
**/
void HDIV_ConfigSingleStart(void)
{
    /* Start HDIV Calculation */
    HDIV->CTRLSTS |= HDIV_START_ENABLE;
}


/**
*\*\name    HDIV_Enable.
*\*\fun     Enable or Disable the HDIV module.
*\*\param   Cmd 
*\*\          - ENABLE  
*\*\          - DISABLE 
*\*\return  none 
**/
void HDIV_Enable(FunctionalState Cmd)
{    
    if (Cmd != DISABLE)
    {
        HDIV->CTRLSTS |= HDIV_CTRLSTS_HDIVEN;
    }
    else
    {
        HDIV->CTRLSTS &= (~HDIV_CTRLSTS_HDIVEN);
    }
}


/**
*\*\name    HDIV_SetSignedDIVIDEND_Data.
*\*\fun     Set 32 bit signed interger dividend data through the HDIV peripheral.
*\*\param   data 
*\*\          - 32 bit signed interger data 
*\*\return  none 
**/
void HDIV_SetSignedDIVIDEND_Data(int32_t data)
{
    /* 32 bit signed interger dividend Data */
    HDIV->DIVIDEND = (uint32_t)data;
}


/**
*\*\name    HDIV_GetSignedDIVIDEND_Data.
*\*\fun     Get 32 bit signed interger dividend data through the HDIV peripheral.
*\*\param   None 
*\*\return  32 bit signed interger dividend data 
**/
int32_t HDIV_GetSignedDIVIDEND_Data(void)
{
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    /* 32 bit signed interger dividend Data */
    return (int32_t)HDIV->DIVIDEND;
}


/**
*\*\name    HDIV_SetSignedDIVISOR_Data.
*\*\fun     Set 32 bit signed interger divisor data through the HDIV peripheral.
*\*\param   data 
*\*\          - 32 bit signed interger data 
*\*\return  none 
**/
void HDIV_SetSignedDIVISOR_Data(int32_t data)
{
    /* 32 bit signed interger divisor Data */
    HDIV->DIVISOR = (uint32_t)data;
}


/**
*\*\name    HDIV_GetSignedDIVISOR_Data.
*\*\fun     Get 32 bit Signed interger divisor data through the HDIV peripheral.
*\*\param   None 
*\*\return  32 bit signed interger divisor data 
**/
int32_t HDIV_GetSignedDIVISOR_Data(void)
{
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    /* 32 bit signed interger divisor Data */
    return (int32_t)HDIV->DIVISOR;
}


/**
*\*\name    HDIV_GetSignedQUOTIENT_Data.
*\*\fun     Get Signed Quotient calculated by the divider data through the HDIV peripheral.
*\*\param   None 
*\*\return  Signed Quotient 
**/
int32_t HDIV_GetSignedQUOTIENT_Data(void)
{
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    /* Quotient calculated by the divider Data */
    return (int32_t)HDIV->QUOTIENT;
}

/**
*\*\name    HDIV_GetSignedQUOTIENT_Data.
*\*\fun     Get Signed Remainder calculated by the divider data through the HDIV peripheral.
*\*\param   None 
*\*\return  Signed Remainder 
**/
int32_t HDIV_GetSignedREMAINDER_Data(void)
{
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    /* Remainder calculated by the divider */
    return (int32_t)HDIV->REMAINDER;
}

