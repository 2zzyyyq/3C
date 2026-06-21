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
*\*\file n32g033_opamp.c
*\*\author Nsing
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/

#include "n32g033_opamp.h"
#include "n32g033_rcc.h"


/**
*\*\name    OPAMP_DeInit.
*\*\fun     Reset the OPAMP registers.
*\*\return  none
**/
void OPAMP_DeInit(void)
{
    RCC_EnableAPBPeriphReset(RCC_APB_PERIPH_OPA);
}
/**
*\*\name    OPAMP_StructInit.
*\*\fun     Fills each OPAMP_initstruct member with its default value.
*\*\param   OPAMP_initstruct :
*\*\          - Gain
*\*\          - Mode
*\*\          - OPAMP1_Vpsel
*\*\          - OPAMP1_Vmsel
*\*\return  none
**/
void OPAMP_StructInit(OPAMP_InitType* OPAMP_InitStruct)
{
    OPAMP_InitStruct->Gain             = OPAMP1_CS_PGA_GAIN_2_DIFF_1;
    OPAMP_InitStruct->Mode             = OPAMP_CS_MODE_MASK;
    OPAMP_InitStruct->OPAMP1_Vpsel     = OPAMP1_CS_VPSEL_PF0;
    OPAMP_InitStruct->OPAMP1_Vmsel     = OPAMP1_CS_VMSEL_PF1;
}
/**
*\*\name    OPAMP_Init.
*\*\fun     Initializes the OPAMP according to OPAMP_InitStruct.
*\*\param   OPAMPX :
*\*\          - OPAMP1
*\*\          - OPAMP2
*\*\          - OPAMP3
*\*\param   OPAMP_InitStruct :
*\*\          - Mode :just vailed For OPAMP1
*\*\            - OPAMP1_CS_MODE_EXT_OPA
*\*\            - OPAMP1_CS_MODE_DIFF_PGA
*\*\            - OPAMP1_CS_MODE_INTER_PGA
*\*\            - OPAMP1_CS_MODE_BUFF_EN
*\*\          - Mode :just vailed For OPAMP2/3
*\*\            - OPAMP23_CS_MODE_DISBALE
*\*\            - OPAMP23_CS_MODE_BUFF_EN
*\*\param     - VpSel : just vailed For OPA1
*\*\            - OPAMP1_CS_VPSEL_PF0
*\*\            - OPAMP1_CS_VPSEL_PA0
*\*\            - OPAMP1_CS_VPSEL_PA1
*\*\            - OPAMP1_CS_VPSEL_PA4
*\*\            - OPAMP1_CS_VPSEL_PA7
*\*\            - OPAMP1_CS_VPSEL_PB0
*\*\          - VmSel : just vailed For OPA1
*\*\            - OPAMP1_CS_VMSEL_PF1
*\*\            - OPAMP1_CS_VMSEL_PA2
*\*\            - OPAMP1_CS_VMSEL_PA5
*\*\            - OPAMP1_CS_VMSEL_PB1
*\*\          - Gain : just vailed For OPAMP1
*\*\            - OPAMP1_CS_PGA_GAIN_2_DIFF_1
*\*\            - OPAMP1_CS_PGA_GAIN_4_DIFF_2
*\*\            - OPAMP1_CS_PGA_GAIN_8_DIFF_4
*\*\            - OPAMP1_CS_PGA_GAIN_16_DIFF_8
*\*\            - OPAMP1_CS_PGA_GAIN_32_DIFF_16
*\*\            - OPAMP1_CS_PGA_GAIN_xx_DIFF_32
*\*\          - Gain : just vailed For OPAMP2/3
*\*\            - OPAMP23_CS_PGA_GAIN_DIFF_1
*\*\            - OPAMP23_CS_PGA_GAIN_DIFF_2
*\*\            - OPAMP23_CS_PGA_GAIN_DIFF_4
*\*\            - OPAMP23_CS_PGA_GAIN_DIFF_8
*\*\            - OPAMP23_CS_PGA_GAIN_DIFF_16
*\*\return  none
**/
void OPAMP_Init(OPAMPX OPAMPx, OPAMP_InitType* OPAMP_InitStruct)
{
    __IO uint32_t* pCs = &OPAMP->OPAMP1_CS + (uint32_t)OPAMPx;
    __IO uint32_t tmp  = *pCs;

    tmp &= ~(OPAMP_EN_MASK | OPAMP_CS_MODE_MASK | OPAMP1_CS_PGA_GAIN_MASK |OPAMP1_CS_VPSEL_MASK | OPAMP1_CS_VMSEL_MASK );  
    tmp |= (OPAMP_InitStruct->Gain | OPAMP_InitStruct->OPAMP1_Vpsel | OPAMP_InitStruct->OPAMP1_Vmsel | OPAMP_InitStruct->Mode );

    *pCs = tmp;
}
/**
*\*\name    OPAMP_Enable.
*\*\fun     Enable or disable opampx .
*\*\param   OPAMPX :
*\*\          - OPAMP1
*\*\          - OPAMP2
*\*\          - OPAMP3
*\*\param   Cmd :
*\*\          - ENABLE
*\*\          - DISABLE
*\*\return  none
**/
void OPAMP_Enable(OPAMPX OPAMPx, FunctionalState Cmd)
{
    __IO uint32_t* pCs = &OPAMP->OPAMP1_CS + (uint32_t)OPAMPx;
    
    if (Cmd != DISABLE)
    {
        *pCs |= OPAMP_EN_MASK;
    }
    else
    {
        *pCs &= (~OPAMP_EN_MASK);
    }
}

/**
*\*\name    OPAMP_EnableInterBufferMode.
*\*\fun     Enable or disable opampx internal buffer mode .
*\*\param   OPAMPX :
*\*\          - OPAMP2
*\*\          - OPAMP3
*\*\param   Cmd :
*\*\          - ENABLE
*\*\          - DISABLE
*\*\return  none
*\*\note  OPA2 and OPA3 support this function.
**/
void OPAMP_EnableInterBufferMode(OPAMPX OPAMPx, FunctionalState Cmd)
{
    __IO uint32_t* pCs = &OPAMP->OPAMP1_CS + (uint32_t)OPAMPx;
    if (Cmd != DISABLE)
    {
        *pCs |= OPAMP23_MODE_EN_MASK;
    }
    else
    {
        *pCs &= (~OPAMP23_MODE_EN_MASK);
    }
}
/**
*\*\name    OPAMP_SetPgaGain.
*\*\fun     Set opampx gain value selection
*\*\param   OPAMPX :
*\*\          - OPAMP1
*\*\          - OPAMP2
*\*\          - OPAMP3
*\*\param   Gain :
*\*\        - OPAMP1
*\*\          - OPAMP1_CS_PGA_GAIN_2_DIFF_1
*\*\          - OPAMP1_CS_PGA_GAIN_4_DIFF_2
*\*\          - OPAMP1_CS_PGA_GAIN_8_DIFF_4
*\*\          - OPAMP1_CS_PGA_GAIN_16_DIFF_8
*\*\          - OPAMP1_CS_PGA_GAIN_32_DIFF_16
*\*\          - OPAMP1_CS_PGA_GAIN_xx_DIFF_32
*\*\        - OPAMP2/3
*\*\          - OPAMP23_CS_PGA_GAIN_DIFF_1
*\*\          - OPAMP23_CS_PGA_GAIN_DIFF_2
*\*\          - OPAMP23_CS_PGA_GAIN_DIFF_4
*\*\          - OPAMP23_CS_PGA_GAIN_DIFF_8
*\*\          - OPAMP23_CS_PGA_GAIN_DIFF_16
*\*\return  none
**/
void OPAMP_SetPgaGain(OPAMPX OPAMPx, uint32_t Gain)
{
    uint32_t temp;
    __IO uint32_t* pCs = &OPAMP->OPAMP1_CS + (uint32_t)OPAMPx;

    temp  = *pCs;
    temp &= (~OPAMP1_CS_PGA_GAIN_MASK);
    temp |= Gain;

    *pCs = temp;
}
/**
*\*\name    OPAMP1_SetVpSel.
*\*\fun     Set opamp1 VP selection
*\*\param   VpSel :
*\*\          - OPAMP1_CS_VPSEL_PF0
*\*\          - OPAMP1_CS_VPSEL_PA0
*\*\          - OPAMP1_CS_VPSEL_PA1
*\*\          - OPAMP1_CS_VPSEL_PA4
*\*\          - OPAMP1_CS_VPSEL_PA7
*\*\          - OPAMP1_CS_VPSEL_PB0
*\*\return  none
**/
void OPAMP1_SetVpSel(uint32_t VpSel)
{
    __IO uint32_t temp;
    
    temp  = OPAMP->OPAMP1_CS;
    temp &= (~OPAMP1_CS_VPSEL_MASK);
    temp |= VpSel;
    OPAMP->OPAMP1_CS = temp;
}
/**
*\*\name    OPAMP1_SetVmSel.
*\*\fun     Set opamp1 VP selection
*\*\param   VmSel :
*\*\          - OPAMP1_CS_VMSEL_PF1
*\*\          - OPAMP1_CS_VMSEL_PA2
*\*\          - OPAMP1_CS_VMSEL_PA5
*\*\          - OPAMP1_CS_VMSEL_PB1
*\*\return  none
**/
void OPAMP1_SetVmSel(uint32_t VmSel)
{
    uint32_t temp;
    
    temp = OPAMP->OPAMP1_CS;
    temp &= (~OPAMP1_CS_VMSEL_MASK);
    temp |= VmSel;
    OPAMP->OPAMP1_CS = temp;
}

/**
*\*\name    OPAMP_SetLock.
*\*\fun     Set opamp lock
*\*\param   Lock :
*\*\          - OPAMP_LOCK
*\*\return  none
**/
void OPAMP_SetLock(uint32_t Lock)
{
    OPAMP->LOCK = Lock;
}


/**
*\*\name    OPAMP_VREFPSel.
*\*\fun     Set opampx vrefp selection
*\*\param   OPAMPX :
*\*\          - OPAMP1
*\*\          - OPAMP2
*\*\          - OPAMP3
*\*\param   Gain :
*\*\          - OPAMP_VREFP_SEL_0_9V
*\*\          - OPAMP_VREFP_SEL_1_8VDD
*\*\          - OPAMP_VREFP_SEL_1_4VDD
*\*\return  none
**/
void OPAMP_VREFPSel(OPAMPX OPAMPx, uint32_t VrefSel)
{
    __IO uint32_t temp;
    uint8_t offset;
    
    offset = (uint8_t)OPAMPx *2U;
    temp  = OPAMP->VREFSEL;
    temp &= ~(OPAMP_VREFP_SEL_MASK<< offset);
    temp |= (VrefSel << offset);

    OPAMP->VREFSEL = temp;
}


