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
*\*\file n32g033_iwdg.h
*\*\author Nsing
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/
#ifndef __N32G033_IWDG_H__
#define __N32G033_IWDG_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "n32g033.h"

typedef enum 
{
    IWDG_PVU_FLAG  = IWDG_STS_PVU,
    IWDG_CRVU_FLAG = IWDG_STS_CRVU,
}IWDG_STATUS_FLAG;

/** KEY register bit mask **/
#define KEY_ReloadKey                      ((uint16_t)0xAAAA)
#define KEY_EnableKey                      ((uint16_t)0xCCCC)


/** PREDIV and RELV register write permission **/
typedef enum 
{
    IWDG_WRITE_ENABLE  = 0x5555,
    IWDG_WRITE_DISABLE = 0x0000
}IWDOG_WRITE_CONFIG;

#define IWDG_PRESCALER_DIV4    ((uint8_t)0x00)
#define IWDG_PRESCALER_DIV8    (IWDG_PREDIV_PD0)
#define IWDG_PRESCALER_DIV16   (IWDG_PREDIV_PD1)
#define IWDG_PRESCALER_DIV32   (IWDG_PREDIV_PD1 | IWDG_PREDIV_PD0)
#define IWDG_PRESCALER_DIV64   (IWDG_PREDIV_PD2)
#define IWDG_PRESCALER_DIV128  (IWDG_PREDIV_PD2 | IWDG_PREDIV_PD0)
#define IWDG_PRESCALER_DIV256  (IWDG_PREDIV_PD2 | IWDG_PREDIV_PD1 | IWDG_PREDIV_PD0)


void IWDG_WriteConfig(IWDOG_WRITE_CONFIG IWDG_WriteAccess);
void IWDG_SetPrescalerDiv(uint8_t IWDG_Prescaler);
void IWDG_CntReload(uint16_t Reload);
void IWDG_ReloadKey(void);
void IWDG_Enable(void);
FlagStatus IWDG_GetStatus(IWDG_STATUS_FLAG IWDG_FLAG);
void IWDG_INT_Enable(FunctionalState Cmd);
void IWDG_Feed(void);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
}
#endif

#endif /* __N32G033_IWDG_H__ */
