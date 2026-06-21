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
*\*\file n32g033_opamp.h
*\*\author Nsing
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/

#ifndef __N32G033_OPAMPMP_H__
#define __N32G033_OPAMPMP_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "n32g033.h"
#include <stdbool.h>

/** N32G033_StdPeriph_Driver    */

/**  OPAMP      */

/** OPAMP_Exported_Constants  */
typedef enum
{
    OPAMP1 = 0,
    OPAMP2 = 1,
    OPAMP3 = 2
} OPAMPX;

/**    OPAMP Init structure definition  */
typedef struct
{
    uint32_t Gain;   
    uint32_t Mode; 
    uint32_t OPAMP1_Vpsel;
    uint32_t OPAMP1_Vmsel;
} OPAMP_InitType;

/*  OPAMP1_CS_VPSEL bit:16:14  */
#define OPAMP1_CS_VPSEL_MASK            ((uint32_t)OPAMP1_CS_VPSEL)
#define OPAMP1_CS_VPSEL_PF0             ((uint32_t)0x00000000U)
#define OPAMP1_CS_VPSEL_PA0             ((uint32_t)OPAMP1_CS_VPSEL_0)
#define OPAMP1_CS_VPSEL_PA1             ((uint32_t)OPAMP1_CS_VPSEL_1)
#define OPAMP1_CS_VPSEL_PA4             ((uint32_t)(OPAMP1_CS_VPSEL_1 | OPAMP1_CS_VPSEL_0)) 
#define OPAMP1_CS_VPSEL_PA7             ((uint32_t)OPAMP1_CS_VPSEL_2)
#define OPAMP1_CS_VPSEL_PB0             ((uint32_t)(OPAMP1_CS_VPSEL_2 | OPAMP1_CS_VPSEL_0))


/*  OPAMP1_CS_VMSEL bit:14:12  */
#define OPAMP1_CS_VMSEL_MASK            ((uint32_t)OPAMP1_CS_VMSEL)
#define OPAMP1_CS_VMSEL_PF1             ((uint32_t)0x00000000U)
#define OPAMP1_CS_VMSEL_PA2             ((uint32_t)OPAMP1_CS_VMSEL_0)
#define OPAMP1_CS_VMSEL_PA5             ((uint32_t)OPAMP1_CS_VMSEL_1)
#define OPAMP1_CS_VMSEL_PB1             ((uint32_t)(OPAMP1_CS_VMSEL_1 | OPAMP1_CS_VMSEL_0))

/*  OPAMP1_CS_GAIN bit:5:3 for OPAMP1 */
#define OPAMP1_CS_PGA_GAIN_MASK         ((uint32_t)OPAMP1_CS_GAIN) 
#define OPAMP1_CS_PGA_GAIN_2_DIFF_1     ((uint32_t)0x00000000U)
#define OPAMP1_CS_PGA_GAIN_4_DIFF_2     ((uint32_t)OPAMP1_CS_GAIN_0)
#define OPAMP1_CS_PGA_GAIN_8_DIFF_4     ((uint32_t)OPAMP1_CS_GAIN_1)
#define OPAMP1_CS_PGA_GAIN_16_DIFF_8    ((uint32_t)(OPAMP1_CS_GAIN_1 | OPAMP1_CS_GAIN_0))
#define OPAMP1_CS_PGA_GAIN_32_DIFF_16   ((uint32_t)OPAMP1_CS_GAIN_2)
#define OPAMP1_CS_PGA_GAIN_xx_DIFF_32   ((uint32_t)(OPAMP1_CS_GAIN_2 | OPAMP1_CS_GAIN_0) )

/*  OPAMP1_CS_MODE bit:2:1  */
#define OPAMP_CS_MODE_MASK              ((uint32_t)0x00000006U)
#define OPAMP1_CS_MODE_EXT_OPA          ((uint32_t)0x00000000U)
#define OPAMP1_CS_MODE_DIFF_PGA         ((uint32_t)0x00000002U)
#define OPAMP1_CS_MODE_INTER_PGA        ((uint32_t)0x00000004U)
#define OPAMP1_CS_MODE_BUFF_EN          ((uint32_t)0x00000006U)
/*  OPAMP2/3_CS_MODE bit:1  */
#define OPAMP23_CS_MODE_DISBALE         ((uint32_t)0x00000000U)
#define OPAMP23_CS_MODE_BUFF_EN         ((uint32_t)OPAMP2_CS_MOD)

/*OPA enable mask */
#define OPAMP_EN_MASK                  (OPAMP1_CS_EN)

/*  OPAMP23_CS_GAIN bit:5:3 for OPAMP2/3 */
#define OPAMP23_CS_PGA_GAIN_MASK       ((uint32_t)OPAMP2_CS_GAIN) 
#define OPAMP23_CS_PGA_GAIN_DIFF_1     ((uint32_t)0x00000000U)
#define OPAMP23_CS_PGA_GAIN_DIFF_2     ((uint32_t)OPAMP2_CS_GAIN_0)
#define OPAMP23_CS_PGA_GAIN_DIFF_4     ((uint32_t)OPAMP2_CS_GAIN_1)
#define OPAMP23_CS_PGA_GAIN_DIFF_8     ((uint32_t)(OPAMP2_CS_GAIN_1 | OPAMP2_CS_GAIN_0))
#define OPAMP23_CS_PGA_GAIN_DIFF_16    ((uint32_t)OPAMP2_CS_GAIN_2)
/*OPAMP1_LOCK */
#define OPAMP1_LOCK_EN                 (OPAMP_LOCK)

/*OPA2/3 internal buffer mode enanle mask */
#define OPAMP23_MODE_EN_MASK           (OPAMP2_CS_MOD)

/*OPAMPx_VREFSEL */
#define OPAMP_VREFP_SEL_MASK           (OPAMP1_VREFSEL_SEL)
#define OPAMP_VREFP_SEL_0_9V           (0x00U)                     //0.9V
#define OPAMP_VREFP_SEL_1_8VDD         (OPAMP1_VREFSEL_SEL_0)      //1/8 VDDA
#define OPAMP_VREFP_SEL_1_4VDD         (OPAMP1_VREFSEL_SEL_1)      //1/4 VDDA






void OPAMP_DeInit(void);
void OPAMP_StructInit(OPAMP_InitType* OPAMP_InitStruct);
void OPAMP_Init(OPAMPX OPAMPx, OPAMP_InitType* OPAMP_InitStruct);
void OPAMP_Enable(OPAMPX OPAMPx, FunctionalState Cmd);
void OPAMP_EnableInterBufferMode(OPAMPX OPAMPx, FunctionalState Cmd);
void OPAMP_SetPgaGain(OPAMPX OPAMPx, uint32_t Gain);
void OPAMP1_SetVpSel(uint32_t VpSel);
void OPAMP1_SetVmSel(uint32_t VmSel);
void OPAMP_SetLock(uint32_t Lock); 

void OPAMP_VREFPSel(OPAMPX OPAMPx, uint32_t VrefSel);


#ifdef __cplusplus
}
#endif

#endif /*__N32G033_OPAMPMP_H__ */

