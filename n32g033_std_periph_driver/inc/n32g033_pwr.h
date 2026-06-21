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
*\*\file n32g033_pwr.h
*\*\author Nsing
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/

#ifndef __N32G033_PWR_H__
#define __N32G033_PWR_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "n32g033.h"

#define PWR_REG_BIT_MASK         ((uint32_t)0x00000000)	
	
/** PWR CTRL register bit mask definition **/
#define PWR_CTRL_NRSTCNT_MASK    (~(PWR_CTRL_NRSTCNT))	
#define PWR_CTRL_PLS_MASK        (~(PWR_CTRL_PLS))	
#define PWR_CTRL_PVDCNT_MASK     (~(PWR_CTRL_PVDCNT))
	
/** PWR IWDR reset enable definition **/
#define PWR_IWDGRST_ENABLE         (PWR_CTRL_IWDGRSTEN)	
	
	
/** PWR PVD threshold level definition **/
#define PWR_PVD_LEVEL_2V0 ((uint32_t)(PWR_CTRL_PLS_0))    /* 2.0v PWR_CTRL bit[8:5]:0001 */
#define PWR_PVD_LEVEL_2V2 ((uint32_t)(PWR_CTRL_PLS_1))    /* 2.2v PWR_CTRL bit[8:5]:0010 */
#define PWR_PVD_LEVEL_2V4 ((uint32_t)(PWR_CTRL_PLS_0 \
                                    | PWR_CTRL_PLS_1))    /* 2.4v PWR_CTRL bit[8:5]:0011 */
#define PWR_PVD_LEVEL_2V6 ((uint32_t)(PWR_CTRL_PLS_2))    /* 2.6v PWR_CTRL bit[8:5]:0100 */
#define PWR_PVD_LEVEL_2V8 ((uint32_t)(PWR_CTRL_PLS_0 \
                                    | PWR_CTRL_PLS_2))    /* 2.8v PWR_CTRL bit[8:5]:0101 */
#define PWR_PVD_LEVEL_3V0 ((uint32_t)(PWR_CTRL_PLS_1 \
                                    | PWR_CTRL_PLS_2))    /* 3.0v PWR_CTRL bit[8:5]:0110 */
#define PWR_PVD_LEVEL_3V2 ((uint32_t)(PWR_CTRL_PLS_0 \
                                    | PWR_CTRL_PLS_1 \
                                    | PWR_CTRL_PLS_2))    /* 3.2v PWR_CTRL bit[8:5]:0111 */
#define PWR_PVD_LEVEL_3V4 ((uint32_t)(PWR_CTRL_PLS_3))    /* 3.4v PWR_CTRL bit[8:5]:1000 */
#define PWR_PVD_LEVEL_3V6 ((uint32_t)(PWR_CTRL_PLS_0 \
                                    | PWR_CTRL_PLS_3))    /* 3.6v PWR_CTRL bit[8:5]:1001 */
#define PWR_PVD_LEVEL_3V8 ((uint32_t)(PWR_CTRL_PLS_1 \
                                    | PWR_CTRL_PLS_3))    /* 3.8v PWR_CTRL bit[8:5]:1010 */
#define PWR_PVD_LEVEL_4V0 ((uint32_t)(PWR_CTRL_PLS_0 \
                                    | PWR_CTRL_PLS_1 \
                                    | PWR_CTRL_PLS_3))    /* 4.0v PWR_CTRL bit[8:5]:1011 */
#define PWR_PVD_LEVEL_4V2 ((uint32_t)(PWR_CTRL_PLS_2 \
                                    | PWR_CTRL_PLS_3))    /* 4.2v PWR_CTRL bit[8:5]:1100 */
#define PWR_PVD_LEVEL_4V4 ((uint32_t)(PWR_CTRL_PLS_0 \
                                    | PWR_CTRL_PLS_2 \
                                    | PWR_CTRL_PLS_3))    /* 4.4v PWR_CTRL bit[8:5]:1101 */
#define PWR_PVD_LEVEL_4V6 ((uint32_t)(PWR_CTRL_PLS_1 \
                                    | PWR_CTRL_PLS_2 \
                                    | PWR_CTRL_PLS_3))    /* 4.6v PWR_CTRL bit[8:5]:1110 */
#define PWR_PVD_LEVEL_4V8 ((uint32_t)(PWR_CTRL_PLS_0 \
                                    | PWR_CTRL_PLS_1 \
                                    | PWR_CTRL_PLS_2 \
                                    | PWR_CTRL_PLS_3))    /* 4.8v PWR_CTRL bit[8:5]:1111 */	 
            
						
/** PWR registers write protection keys definition **/
#define PWR_CTRL2_KEYS      ((uint32_t)0x57103616U)
#define PWR_CTRL2_KEY      ((uint32_t)0xFFFFFFFFU) 
#define PWR_CTRL2_KEYS_MASK (~PWR_CTRL2_KEY)

/** PWR DBG_CTRL definition **/
#define PWR_DBG_IWDG         (DBG_CTRL_IWDGSTP)
#define PWR_DBG_TIM1         (DBG_CTRL_TIM1STP)
#define PWR_DBG_TIM3         (DBG_CTRL_TIM3STP)
#define PWR_DBG_TIM4         (DBG_CTRL_TIM4STP)
#define PWR_DBG_I2C1         (DBG_CTRL_I2C1TIMOUT)
#define PWR_DBG_I2C2         (DBG_CTRL_I2C2TIMOUT)
#define PWR_DBG_TIM6         (DBG_CTRL_TIM6STP)


/** PWR sleep status definition **/
#define PWR_SLEEP_NOW              ((uint8_t)0x00)
#define PWR_SLEEP_ON_EXIT          ((uint8_t)0x01)

/** PWR SLEEP mode entry definition **/
#define PWR_SLEEPENTRY_WFI         ((uint8_t)0x01) /* enter SLEEP mode with WFI instruction */
#define PWR_SLEEPENTRY_WFE         ((uint8_t)0x02) /* enter SLEEP mode with WFE instruction */

/** PWR STOP mode entry definition **/
#define PWR_STOPENTRY_WFI          ((uint8_t)0x01) /* enter STOP mode with WFI instruction */
#define PWR_STOPENTRY_WFE          ((uint8_t)0x02) /* enter STOP mode with WFE instruction */


/** PWR PVD output Flag definition **/
#define PWR_PVDO_FLAG          ((uint32_t)0x00000004)

/*** PWR Macro Definition End ***/

/*** PWR Driving Functions Declaration ***/
void PWR_PvdEnable(FunctionalState Cmd);
void PWR_PVDFilterWidthSet(uint8_t filter_value);
void PWR_PVDLevelConfig(uint32_t level);
void PWR_NRSTFilterWidthSet(uint16_t filter_value);
void PWR_EnterSLEEPMode(uint8_t SLEEPONEXIT, uint8_t PWR_SLEEPEntry);
void PWR_EnterSTOPMode(uint8_t enter_mode);
void PWR_CTRL2WriteProtectionEnable(void);
FlagStatus PWR_GetFlagStatus(uint32_t PWR_FLAG);
void DBG_ConfigPeriph(uint32_t DBG_Periph, FunctionalState Cmd);
void PWR_EnableIWDGReset(FunctionalState Cmd);

#ifdef __cplusplus
}
#endif

#endif /* __N32G033_PWR_H__ */
