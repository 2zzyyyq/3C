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
*\*\file n32g033_flash.h
*\*\author Nsing
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/
#ifndef __N32G033_FLASH_H__
#define __N32G033_FLASH_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "n32g033.h"

/** FLASH Status **/
typedef enum
{ 
    FLASH_BUSY = 1,
    FLASH_ERR_PG,
    FLASH_ERR_WRP,
    FLASH_EOP,
    FLASH_ERR_RDP2,
    FLASH_ERR_ADD,
    FLASH_TIMEOUT
}FLASH_STS;

/** Flash_Latency **/
#define FLASH_LATENCY_0     ((uint32_t)FLASH_AC_LATENCY_0) /* FLASH Zero Latency cycle */
#define FLASH_LATENCY_1     ((uint32_t)FLASH_AC_LATENCY_1) /* FLASH One Latency cycle */
#define FLASH_LATENCY_MASK  ((uint32_t)FLASH_AC_LATENCY)

/** FLASH Keys **/
#define FLASH_KEY1   ((uint32_t)0x45670123U)
#define FLASH_KEY2   ((uint32_t)0xCDEF89ABU)

/** Flash Control Register bits **/
#define CTRL_Set_PG             ((uint32_t)FLASH_CTRL_PG)
#define CTRL_Reset_PG           (~((uint32_t)FLASH_CTRL_PG))
#define CTRL_Set_PER            ((uint32_t)FLASH_CTRL_PER)
#define CTRL_Reset_PER          (~((uint32_t)FLASH_CTRL_PER))
#define CTRL_Set_MER            ((uint32_t)FLASH_CTRL_MER)
#define CTRL_Reset_MER          (~((uint32_t)FLASH_CTRL_MER))
#define CTRL_Set_OPTPG          ((uint32_t)FLASH_CTRL_OPTPG)
#define CTRL_Reset_OPTPG        (~((uint32_t)FLASH_CTRL_OPTPG))
#define CTRL_Set_OPTER          ((uint32_t)FLASH_CTRL_OPTER)
#define CTRL_Reset_OPTER        (~((uint32_t)FLASH_CTRL_OPTER))
#define CTRL_Set_START          ((uint32_t)FLASH_CTRL_START)
#define CTRL_Set_LOCK           ((uint32_t)FLASH_CTRL_LOCK)
#define FLASH_CTRL_SET_OPTWE    ((uint32_t)FLASH_CTRL_OPTWE)

/** Option byte **/   
#define L1_RDP_Key              ((uint32_t)0xFFFF00A5U)  
#define FLASH_L2_RDP_KEY        ((uint32_t)0xFFFF33CCU)
#define FLASH_OB2_DATA0_MASK    (FLASH_OB2_Data0)
#define FLASH_OB2_DATA1_MASK    (FLASH_OB2_Data1)
#define FLASH_OB_BOOTSEL_MASK   (FLASH_OB_BOOT_SEL)

/** FLASH Mask **/
#define FLASH_RDPRTL1_MSK           ((uint32_t)FLASH_OB_RDPRT1)
#define FLASH_RDPRTL2_MSK           ((uint32_t)FLASH_OB_RDPRT2)

/** Option_Bytes_BOOTSEL **/   
#define BOOT_UARTPIN_PA9PA10            ((uint32_t)0x00030000U) /* BOOT uart pins are PA9 and PA10 */
#define BOOT_UARTPIN_PA13PA14           ((uint32_t)0x00000000U) /* BOOT uart pins are PA13 and PA14 */
#define BOOT_UARTPIN_PF0PF1             ((uint32_t)0x00010000U) /* BOOT uart pins are PF0 and PF1 */
#define BOOT_UARTPIN_PA2PA3             ((uint32_t)0x00020000U) /* BOOT uart pins are PA2 and PA3 */

/** Option_Bytes_RDPx **/
#define FLASH_OB_RDP1_ENABLE            ((uint8_t)0x00U) /* Enable RDP1 */
#define FLASH_OB_RDP1_DISABLE           ((uint8_t)0xA5U) /* DISABLE RDP1 */

#define FLASH_OB_RDP2_ENABLE            ((uint8_t)0xCCU) /* Enable RDP2 */
#define FLASH_OB_RDP2_DISABLE           ((uint8_t)0x00U) /* Disable RDP2 */

/** Option_Bytes_IWatchdog **/
#define FLASH_OB_IWDG_SOFTWARE          ((uint32_t)0x00000001U) /* Software IWDG selected */
#define FLASH_OB_IWDG_HARDWARE          ((uint32_t)0xA55A5AA5U) /* Hardware IWDG selected */

/** Option_Bytes_PF3 **/
#define FLASH_OB_PF3_GPIO               ((uint32_t)0xA55A5AA5U) /* PF3 set GPIO */
#define FLASH_OB_PF3_NRST               ((uint32_t)0x00000002U) /* PF3 set NRST */

#define FLASH_OB_NBOOT0_SET             ((uint32_t)0x00010000U) /* Set nBOOT0 */
#define FLASH_OB_NBOOT0_CLR             ((uint32_t)0x00000000U) /* Clear nBOOT0 */

#define FLASH_OB_NBOOT1_SET             ((uint32_t)0x00020000U) /* Set nBOOT1 */
#define FLASH_OB_NBOOT1_CLR             ((uint32_t)0x00000000U) /* Clear nBOOT1 */

#define FLASH_OB_NSWBOOT0_SET           ((uint32_t)0x00040000U) /* Set nSWBOOT0 */
#define FLASH_OB_NSWBOOT0_CLR           ((uint32_t)0x00000000U) /* Clear nSWBOOT0 */

#define FLASH_OB_BOOT0_CFG_HIGH         ((uint32_t)0x00080000U) /* Boot0 high active */
#define FLASH_OB_BOOT0_CFG_LOW          ((uint32_t)0x00000000U) /* Boot0 low active */

/** Option Bytes MASK **/
#define FLASH_OB_MASK                   ((uint32_t)0xFFFFFFFFU)
#define FLASH_OB_RDP1_MASK              ((uint32_t)0x0000FFFFU)
#define FLASH_OB_USER4_MASK             ((uint32_t)0xFFFF0000U)

/** FLASH USER Mask **/
#define FLASH_USER_POR_DELAY_MSK        ((uint32_t)FLASH_OB_POR_DELAY)
#define FLASH_OB_DATA1_MASK             ((uint32_t)0x0000FF00U)
#define FLASH_OB_DATA0_MASK             ((uint32_t)0x000000FFU)


#define FLASH_DATA0_DATA1_OFFSET        (REG_BIT16_OFFSET)
#define FLASH_USER2_USER3_OFFSET        (REG_BIT16_OFFSET)
#define FLASH_OB_DATA0_OFFSET           (REG_BIT0_OFFSET)
#define FLASH_OB_DATA1_OFFSET           (REG_BIT8_OFFSET)
#define FLASH_OB_BOOTSEL_OFFSET         (REG_BIT4_OFFSET)
#define FLASH_USER2_OFFSET              (REG_BIT4_OFFSET)
#define FLASH_OB_USER2_MASK             ((uint32_t)0x000000FFU)


/** Delay definition **/
#define EraseTimeout                    ((uint32_t)0x000B0000U)
#define ProgramTimeout                  ((uint32_t)0x00002000U) 
#define FLASH_WORD_LENGTH               ((uint32_t)0x00000003U)


/**  FLASH_Interrupts **/
#define FLASH_INT_ERR      ((uint32_t)FLASH_CTRL_ERRITE) /* PGERR WRPERR ERROR error interrupt source */
#define FLASH_INT_EOP      ((uint32_t)FLASH_CTRL_EOPITE) /* End of FLASH Operation Interrupt source */

/** FLASH_Flags **/
#define FLASH_FLAG_BUSY     ((uint32_t)FLASH_STS_BUSY) /* FLASH Busy flag */
#define FLASH_FLAG_PGERR    ((uint32_t)FLASH_STS_PGERR) /* FLASH Program error flag */
#define FLASH_FLAG_WRPERR   ((uint32_t)FLASH_STS_WRPERR) /* FLASH Write protected error flag */
#define FLASH_FLAG_EOP      ((uint32_t)FLASH_STS_EOP) /* FLASH End of Operation flag */
#define FLASH_FLAG_OBERR    ((uint32_t)FLASH_OB_OBERR) /* Option Byte Error flag */

/** FLASH_STS_CLRFLAG **/
#define FLASH_STS_CLRFLAG   (FLASH_FLAG_PGERR | FLASH_FLAG_WRPERR | FLASH_FLAG_EOP)


/** FLASH_VTOR_CLRFLAG **/
#define FLASH_VTOR_ENABLE   ((uint32_t)FLASH_VTOR_EN) /* FLASH Vtor enable */
#define FLASH_VTOR_DISABLE  ((uint32_t)0x00000000U) /* FLASH Vtor disable */

/** Option byte offset **/
#define FLASH_OB_TO_USER_OFFSET     (REG_BIT2_OFFSET)
#define FLASH_USER3_OFFSET          (REG_BIT4_OFFSET)
#define FLASH_USER4_OFFSET          (REG_BIT16_OFFSET)

/** FLASH Mask **/   
#define FLASH_WRP0_MSK              (FLASH_WRP0_WRP0)
#define FLASH_WRP1_MSK              (FLASH_WRP1_WRP1)


#define FLASH_WRP_Pages0to7      ((uint32_t)FLASH_WRP_WRPT_0)  /* N32G033 devices: Write protection of page 0 to 7 */
#define FLASH_WRP_Pages8to15     ((uint32_t)FLASH_WRP_WRPT_1)  /* N32G033 devices: Write protection of page 8 to 15 */
#define FLASH_WRP_Pages16to23    ((uint32_t)FLASH_WRP_WRPT_2)  /* N32G033 devices: Write protection of page 16 to 23 */
#define FLASH_WRP_Pages24to31    ((uint32_t)FLASH_WRP_WRPT_3)  /* N32G033 devices: Write protection of page 24 to 31 */
#define FLASH_WRP_Pages32to39    ((uint32_t)FLASH_WRP_WRPT_4)  /* N32G033 devices: Write protection of page 32 to 39 */
#define FLASH_WRP_Pages40to47    ((uint32_t)FLASH_WRP_WRPT_5)  /* N32G033 devices: Write protection of page 40 to 47 */
#define FLASH_WRP_Pages48to55    ((uint32_t)FLASH_WRP_WRPT_6)  /* N32G033 devices: Write protection of page 48 to 55 */
#define FLASH_WRP_Pages56to63    ((uint32_t)FLASH_WRP_WRPT_7)  /* N32G033 devices: Write protection of page 56 to 63 */
#define FLASH_WRP_Pages64to71    ((uint32_t)FLASH_WRP_WRPT_8)  /* N32G033 devices: Write protection of page 64 to 71 */
#define FLASH_WRP_Pages72to79    ((uint32_t)FLASH_WRP_WRPT_9)  /* N32G033 devices: Write protection of page 72 to 79 */
#define FLASH_WRP_Pages80to87    ((uint32_t)FLASH_WRP_WRPT_10) /* N32G033 devices: Write protection of page 80 to 87 */
#define FLASH_WRP_Pages88to95    ((uint32_t)FLASH_WRP_WRPT_11) /* N32G033 devices: Write protection of page 88 to 95 */
#define FLASH_WRP_Pages96to103   ((uint32_t)FLASH_WRP_WRPT_12) /* N32G033 devices: Write protection of page 96 to 103 */
#define FLASH_WRP_Pages104to111  ((uint32_t)FLASH_WRP_WRPT_13) /* N32G033 devices: Write protection of page 104 to 111 */
#define FLASH_WRP_Pages112to119  ((uint32_t)FLASH_WRP_WRPT_14) /* N32G033 devices: Write protection of page 112 to 119 */
#define FLASH_WRP_Pages120to127  ((uint32_t)FLASH_WRP_WRPT_15) /* N32G033 devices: Write protection of page 120 to 127 */
#define FLASH_WRP_AllPages       ((uint32_t)0x00FF00FF)       /* Write protection of all Pages */


/*------------ Functions used for N32G033 devices -----*/
void FLASH_SetLatency(uint32_t FLASH_Latency);
uint8_t FLASH_GetLatency(void);
void FLASH_Unlock(void);
void FLASH_Lock(void);
FlagStatus Flash_GetLockStatus(void);
void Option_Bytes_Unlock(void);
void Option_Bytes_Lock(void);
FlagStatus OB_GetLockStatus(void);
FLASH_STS FLASH_EraseOnePage(uint32_t Page_Address);
FLASH_STS FLASH_MassErase(void);
FLASH_STS FLASH_ProgramWord(uint32_t address, uint32_t data);

FLASH_STS FLASH_EraseOB(void);
FLASH_STS FLASH_ProgramOptionBytes_USER4_RDP1(uint32_t option_byte_user4, uint8_t option_byte_rpd1);
FLASH_STS FLASH_ProgramOptionBytes_USER0(uint32_t option_byte_iwdg);
FLASH_STS FLASH_ProgramOptionBytes_USER1(uint32_t option_byte_PF3);
FLASH_STS FLASH_ProgramOptionBytes_USER3_USER2(uint32_t option_byte_nBOOT0, uint32_t option_byte_nBOOT1, uint32_t option_byte_nSWBOOT0, uint32_t option_byte_BOOT0_CFG, uint32_t option_byte_user2);
FLASH_STS FLASH_ProgramOptionBytes_DATA1_DATA0(uint8_t option_byte_data1, uint8_t option_byte_data0);
FLASH_STS FLASH_EnWriteProtection(uint32_t FLASH_Pages);
FLASH_STS FLASH_ProgramOptionBytes_RDP2(uint8_t option_byte_rpd2);
FLASH_STS FLASH_ReadOutProtectionL1(FunctionalState Cmd);
FLASH_STS FLASH_ReadOutProtectionL2_ENABLE(void);
FlagStatus FLASH_GetOptionBytes_User0(void);
FlagStatus FLASH_GetOptionBytes_User1(void);
uint32_t FLASH_GetOptionBytes_User2(void);
FlagStatus FLASH_GetOptionBytes_User3(uint32_t option_byte_bit);
uint32_t FLASH_GetBOOTUartPIN(void);
uint32_t FLASH_GetOptionBytes_Data0(void);
uint32_t FLASH_GetOptionBytes_Data1(void);
FlagStatus FLASH_GetReadOutProtectionSTS(void);
FlagStatus FLASH_GetReadOutProtectionL2STS(void);
uint32_t FLASH_GetWriteProtectionSTS(void);

void FLASH_INTConfig(uint32_t FLASH_INT, FunctionalState Cmd);
FlagStatus FLASH_GetFlagSTS(uint32_t FLASH_FLAG);
FlagStatus FLASH_GetOBFlagSTS(uint32_t FLASH_FLAG);
void FLASH_ClearFlag(uint32_t FLASH_FLAG);
FLASH_STS FLASH_GetSTS(void);
FLASH_STS FLASH_WaitForLastOpt(uint32_t Timeout);
void FLASH_SetVTORAddress(uint32_t VTOR_address, uint32_t VTOR_cmd);

#ifdef __cplusplus
}
#endif

#endif /* __N32G033_FLASH_H__ */
