/*****************************************************************************
 * Copyright (c) 2025, Nsing Technologies Inc.
 *
 * All rights reserved.
 * ****************************************************************************
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Nsing' name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY Nsing "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL Nsing BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ****************************************************************************/

/**
 * @file n32g033_comp.h
 * @author Nsing 
 * @version v1.0.0
 *
 * @copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
 */
#ifndef __N32G033_COMP_H__
#define __N32G033_COMP_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "n32g033.h"
#include <stdbool.h> 
	
/** @addtogroup N32G033_StdPeriph_Driver
 * @{
 */

/** @addtogroup COMP
 * @{
 */

// COMPx_CTRL
#define COMP_CTRL_CLKSEL_MASK             ((uint32_t)(~COMP_CTRL_CLKSEL))
#define COMP_CTRL_PWRMODE_MASK            ((uint32_t)(~COMP_CTRL_PWRMD))
#define COMP_CTRL_HYST_MASK               ((uint32_t)(~COMP_CTRL_HYST))
#define COMP_CTRL_POL_MASK                ((uint32_t)(~COMP_CTRL_POL))
#define COMP_CTRL_INPSEL_MASK             ((uint32_t)(~COMP_CTRL_INPSEL))
#define COMP_CTRL_INMSEL_MASK             ((uint32_t)(~COMP_CTRL_INMSEL))
#define COMP_CTRL_EN_MASK                 ((uint32_t)(~COMP_CTRL_EN))


/** COMP switch definition **/
#define COMP_ENABLE                       ((uint32_t)COMP_CTRL_EN)

/** COMP Out mask definition **/
#define COMP_OUT_MASK                ((uint32_t)COMP_CTRL_OUT)

/** COMP clock mask definition **/
#define COMP_CLKSEL_SYSTEMCLK             ((uint32_t)0x00000000U) 
#define COMP_CLKSEL_LSX                   ((uint32_t)COMP_CTRL_CLKSEL)

/** COMP operation mode definition **/
#define COMP_CTRL_PWRMD_LOWPWR            ((uint32_t)0x00000000U) 
#define COMP_CTRL_PWRMD_NORMAL            ((uint32_t)COMP_CTRL_PWRMD)

/** COMP lock definition **/
#define COMP_LOCK_MASK                    ((uint32_t)COMP_LOCK_CMPLK) 

/** COMP output polarity definition **/
#define COMP_OUTPOL_MASK                  ((uint32_t)(~COMP_CTRL_POL))
#define COMP_OUTPOL_REV                   ((uint32_t)COMP_CTRL_POL)
#define COMP_OUTPOL_NREV                  ((uint32_t)0x00000000U)

/** COMP non inverting input definition **/
#define COMP_INPSEL_MASK                  ((uint32_t)(~COMP_CTRL_INPSEL))
#define COMP_INPSEL_RES                   ((uint32_t)0x00000000U) 
 /** COMP1 inp sel **/  
#define COMP_INPSEL_OPA0                  ((uint32_t)0x00000000U)
#define COMP_INPSEL_OPA1                  ((uint32_t)COMP_CTRL_INPSEL_0)
#define COMP_INPSEL_OPA2                  ((uint32_t)COMP_CTRL_INPSEL_1)
#define COMP_INPSEL_PA1                   ((uint32_t)(COMP_CTRL_INPSEL_1 | COMP_CTRL_INPSEL_0))
#define COMP_INPSEL_PA3                   ((uint32_t)COMP_CTRL_INPSEL_2)
#define COMP_INPSEL_PA7                   ((uint32_t)(COMP_CTRL_INPSEL_2 | COMP_CTRL_INPSEL_0))
#define COMP_INPSEL_PA8                   ((uint32_t)(COMP_CTRL_INPSEL_2 | COMP_CTRL_INPSEL_1))
#define COMP_INPSEL_PA9                   ((uint32_t)(COMP_CTRL_INPSEL_2 | COMP_CTRL_INPSEL_1 | COMP_CTRL_INPSEL_0))
#define COMP_INPSEL_PA10                  ((uint32_t)COMP_CTRL_INPSEL_3)
#define COMP_INPSEL_PA12                  ((uint32_t)(COMP_CTRL_INPSEL_3 | COMP_CTRL_INPSEL_0))

/** COMP inverting input definition **/
#define COMP_INMSEL_MASK                  ((uint32_t)(~COMP_CTRL_INMSEL))
#define COMP_INMSEL_RES                   ((uint32_t)0x00000000U)
/** COMP inm sel **/
#define COMP_INMSEL_VREF_DAC             ((uint32_t)0x00000000U)
#define COMP_INMSEL_PA0                  ((uint32_t)COMP_CTRL_INMSEL_0)
#define COMP_INMSEL_PA4                  ((uint32_t)COMP_CTRL_INMSEL_1)
#define COMP_INMSEL_PA5                  ((uint32_t)(COMP_CTRL_INMSEL_1 | COMP_CTRL_INMSEL_0))
#define COMP_INMSEL_PA11                 ((uint32_t)COMP_CTRL_INMSEL_2)

/** COMP filter prescale definition **/
#define COMP_FILTER_CLKPSC_MASK           ((uint16_t)(~COMP_FILP_CLKPSC)) /* Low filter sample clock prescale mask*/

/** COMP blanking definition **/
#define COMP_BLANKING_MASK                ((uint32_t)(~COMP_CTRL_BLKING))
#define COMP_BLANKING_NO                  ((uint32_t)0x00000000)
#define COMP_BLANKING_TIM1_OC5            ((uint32_t)COMP_CTRL_BLKING)

/** COMP hysteresis mask definition **/
#define COMP_HYST_MASK                    ((uint32_t)(~COMP_CTRL_HYST))


#define COMP_CTRL_HYST_NO    ((uint32_t)(0x00000000U))
#define COMP_CTRL_HYST_LOW   ((uint32_t)COMP_CTRL_HYST_0)
#define COMP_CTRL_HYST_MID   ((uint32_t)COMP_CTRL_HYST_1)
#define COMP_CTRL_HYST_HIGH  ((uint32_t)(COMP_CTRL_HYST_1 | COMP_CTRL_HYST_0))

/**
 * @}
 */

/** COMP init structure definition **/
typedef struct
{
    /* ctrl define */   
    uint32_t ClockSelect;        /* Specifies the comp clock select during STOP and lowpower run mode */	
    uint32_t LowPoweMode;        /* Specifies the comp operation mode switch bit */		
    uint32_t Blking;             /* Specifies which timer can control the comp output blanking with its capture event */
    uint32_t Hyst;               /* Specifies the comp hysteresis level with low/medium/high level */
    uint32_t PolRev;             /* Specifies the comp output polarity */
    uint32_t InpSel;             /* Specifies the comp inpsel */
    uint32_t InmSel;             /* Specifies the comp inmsel */
    FunctionalState En;          /* enable or disable the comp */

    /* filter define */
    uint8_t SampWindow;          /* Initializes comp sampwindow value ~5bit */
    uint8_t Threshold;           /* ~5bit ,need > SampWindow/2 */
    FunctionalState FilterEn;    /* enable or disable the comp filter */

    /* filter prescale */
    uint16_t ClkPsc;             /* Initializes comp clkpsc value ~5bit */
}COMP_InitType;

/** COMP Driving Functions Declaration **/
void COMP_DeInit(void);
void COMP_StructInit(COMP_InitType* COMP_InitStruct);
void COMP_Init( COMP_InitType* COMP_InitStruct);
void COMP_SetFilterControl(uint8_t FilEn, uint8_t TheresNum, uint8_t SampPW);
void COMP_SetFilterPrescaler(uint16_t FilPreVal);
void COMP_SetHyst(uint32_t HYST);
void COMP_OutputPolarityConfig(uint32_t POL);
void COMP_SetInpSel(uint32_t VpSel);
void COMP_SetInmSel(uint32_t VmSel);
void COMP_Enable(FunctionalState Cmd);
void COMP_SetIntEn(FunctionalState Cmd);
FlagStatus COMP_GetIntStatus(void);                       
FlagStatus COMP_GetOutStatus(void);
void COMP_IntStatusClear(void);
void COMP_SetLock(void);
void COMP_SetRefScl(uint8_t Vv1Trim, bool Vv1En);
void COMP_SetBlking(uint32_t blking_mode);
void COMP_VREF_Enable(FunctionalState Cmd);

#ifdef __cplusplus
}
#endif

#endif /*__N32G033_COMP_H */
/**
 * @}
 */
/**
 * @}
 */
