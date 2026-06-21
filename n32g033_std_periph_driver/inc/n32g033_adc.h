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
*\*\file n32g033_adc.h
*\*\author Nsing 
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/


#ifndef __N32G033_ADC_H__
#define __N32G033_ADC_H__

#ifdef __cplusplus
extern "C" {
#endif
	
#include "n32g033.h"

/** ADC init structure definition **/
typedef struct
{
    FunctionalState ContinueConvEn; /* Specifies whether the conversion is performed in
                                       Continuous or Single mode */
    uint32_t PhsMode; 
    
    uint32_t ExtTrigSelect4;         /* Defines the external trigger used to start the analog
                                       to digital conversion of regular channels */
    uint32_t ExtTrigSelect3;         /* Defines the external trigger used to start the analog
                                       to digital conversion of regular channels */
    uint32_t ExtTrigSelect2;         /* Defines the external trigger used to start the analog
                                       to digital conversion of regular channels */	
    uint32_t ExtTrigSelect1;         /* Defines the external trigger used to start the analog
                                       to digital conversion of regular channels */	
	
    uint32_t DatAlign;              /* Specifies whether the ADC data alignment is left or right */

    uint32_t Phs1ChNumber;             /* Specifies the number of ADC channels that will be converted
                                       using the sequencer for regular channel group */
    uint32_t Phs2ChNumber;             /* Specifies the number of ADC channels that will be converted
                                       using the sequencer for regular channel group */
    uint32_t Phs3ChNumber;             /* Specifies the number of ADC channels that will be converted
                                       using the sequencer for regular channel group */
    uint32_t Phs4ChNumber;             /* Specifies the number of ADC channels that will be converted
                                       using the sequencer for regular channel group */
} ADC_InitType;

/** ADC clock mode define **/
typedef enum
{
    ADC_CKMOD_AHB = 0,
    ADC_CKMOD_PLL = 1,
    ADC_CKMOD_HSI = 2,
}ADC_CKMOD;

/** ADC external trigger sources for channels conversion define **/
#define ADC_EXT_TRIGCONV_MASK                ((uint32_t)(~(ADC_TRIGSEL_PH4EXTSEL|ADC_TRIGSEL_PH3EXTSEL|ADC_TRIGSEL_PH2EXTSEL|ADC_TRIGSEL_PH1EXTSEL| 0xFFFFU))) /* ADC_TRIG bits Mask */
#define ADC_EXT_TRIGCONV_T1_CC1              ((uint32_t)(0x00000000U | ADC_TRIGSEL_TIM1_CC1EN)) 
#define ADC_EXT_TRIGCONV_T1_CC2              ((uint32_t)(0x00010000U | ADC_TRIGSEL_TIM1_CC2EN))
#define ADC_EXT_TRIGCONV_T1_CC3              ((uint32_t)(0x00020000U | ADC_TRIGSEL_TIM1_CC3EN)) 
#define ADC_EXT_TRIGCONV_T1_CC4              ((uint32_t)(0x00030000U | ADC_TRIGSEL_TIM1_CC4EN))
#define ADC_EXT_TRIGCONV_T1_CC5              ((uint32_t)(0x00040000U | ADC_TRIGSEL_TIM1_CC5EN)) 
#define ADC_EXT_TRIGCONV_T1_CC6              ((uint32_t)(0x00050000U | ADC_TRIGSEL_TIM1_CC6EN))
#define ADC_EXT_TRIGCONV_T1_CC7              ((uint32_t)(0x00060000U | ADC_TRIGSEL_TIM1_CC7EN))
#define ADC_EXT_TRIGCONV_T1_TRGO             ((uint32_t)(0x00070000U | ADC_TRIGSEL_TIM1_TRGOEN)) 
#define ADC_EXT_TRIGCONV_T3_CC1              ((uint32_t)(0x00080000U | ADC_TRIGSEL_TIM3_CC1EN)) 
#define ADC_EXT_TRIGCONV_T3_CC2              ((uint32_t)(0x00090000U | ADC_TRIGSEL_TIM3_CC2EN))
#define ADC_EXT_TRIGCONV_T3_TRGO             ((uint32_t)(0x000A0000U | ADC_TRIGSEL_TIM3_TRGOEN))
#define ADC_EXT_TRIGCONV_T4_CC1              ((uint32_t)(0x000B0000U | ADC_TRIGSEL_TIM4_CC1EN))
#define ADC_EXT_TRIGCONV_T4_CC2              ((uint32_t)(0x000C0000U | ADC_TRIGSEL_TIM4_CC2EN))
#define ADC_EXT_TRIGCONV_T4_TRGO             ((uint32_t)(0x000D0000U | ADC_TRIGSEL_TIM4_TRGOEN))
#define ADC_EXT_TRIGCONV_EXT_LINE            ((uint32_t)(0x000E0000U | ADC_TRIGSEL_EXTILINEEN)) 
#define ADC_EXT_TRIGCONV_SWSTRRCH            ((uint32_t)(0x000F0000U | ADC_TRIGSEL_SWEN)) 

#define ADC_EXT_TRIG_MASK                    ((uint32_t)(ADC_TRIGSEL_PH1EXTSEL))
#define ADC_EXT_TRIG_EN_MASK                 ((uint32_t)0x0000FFFFU)
/** ADC data alignment define **/
#define ADC_DAT_ALIGN_R                      ((uint32_t)0x00000000U)        /* ADC_CTRL2 ALIG bits */
#define ADC_DAT_ALIGN_L                      ((uint32_t)ADC_CTRL2_ALIG)

/** ADC DMA mode define **/
#define ADC_DMA_ENABLE                       ((uint32_t)ADC_CTRL2_ENDMA)   /* ADC_CTRL2 DMA bits Mask */

/** ADC channels define **/
#define ADC_SQR_MASK                         ((uint32_t)~(ADC_DAT0_SEQ0))
#define ADC_SQR_OFFSET                       ((uint32_t)0x10U)
#define ADC_CH_0                             ((uint8_t)0x00U)
#define ADC_CH_1                             ((uint8_t)0x01U)
#define ADC_CH_2                             ((uint8_t)0x02U)
#define ADC_CH_3                             ((uint8_t)0x03U)
#define ADC_CH_4                             ((uint8_t)0x04U)
#define ADC_CH_5                             ((uint8_t)0x05U)
#define ADC_CH_6                             ((uint8_t)0x06U)
#define ADC_CH_7                             ((uint8_t)0x07U)
#define ADC_CH_8                             ((uint8_t)0x08U)
#define ADC_CH_9                             ((uint8_t)0x09U)
#define ADC_CH_10                            ((uint8_t)0x0AU)
#define ADC_CH_11                            ((uint8_t)0x0BU)
#define ADC_CH_12                            ((uint8_t)0x0CU)
#define ADC_CH_13                            ((uint8_t)0x0DU)
#define ADC_CH_14                            ((uint8_t)0x0EU)
#define ADC_CH_15                            ((uint8_t)0x0FU)
#define ADC_CH_TS                            ((uint8_t)ADC_CH_11)
#define ADC_CH_VREFINT                       ((uint8_t)ADC_CH_12)
#define ADC_CH_OPA1OUT                       ((uint8_t)ADC_CH_13)
#define ADC_CH_OPA2OUT                       ((uint8_t)ADC_CH_14)
#define ADC_CH_OPA3OUT                       ((uint8_t)ADC_CH_15)

#define ADC_Channel_00_PA0                   ((uint8_t)0x00U)
#define ADC_Channel_01_PA1                   ((uint8_t)0x01U)
#define ADC_Channel_02_PA2                   ((uint8_t)0x02U)
#define ADC_Channel_03_PA3                   ((uint8_t)0x03U)
#define ADC_Channel_04_PA4                   ((uint8_t)0x04U)
#define ADC_Channel_05_PA5                   ((uint8_t)0x05U)
#define ADC_Channel_06_PA6                   ((uint8_t)0x06U)
#define ADC_Channel_07_PA7                   ((uint8_t)0x07U)
#define ADC_Channel_08_PB0                   ((uint8_t)0x08U)
#define ADC_Channel_09_PB1                   ((uint8_t)0x09U)
#define ADC_Channel_10_PB2                   ((uint8_t)0x0AU)
#define ADC_Channel_11_TS                    ((uint8_t)0x0BU)
#define ADC_Channel_12_VREFINT               ((uint8_t)0x0CU)
#define ADC_Channel_13_OPA1OUT               ((uint8_t)0x0DU)
#define ADC_Channel_14_OPA2OUT               ((uint8_t)0x0EU)
#define ADC_Channel_15_OPA3OUT               ((uint8_t)0x0FU)

/** ADC converter operation define **/
#define ADC_ON                              ((uint32_t)ADC_CTRL2_ON)    /* A/D Converter ON / OFF */

/** ADC interrupts define **/
#define ADC_INT_ENDC                        ((uint32_t)ADC_CTRL1_ENDCIEN)   /* Interrupt enable for EOC */
#define ADC_INT_AWD                         ((uint32_t)ADC_CTRL1_AWDGIEN)   /* Analog Watchdog interrupt enable */
#define ADC_INT_ENDCA                       ((uint32_t)ADC_CTRL1_ENDCAIEN)  /* Interrupt enable for any EOC */
#define ADC_INT_PHS1                        ((uint32_t)ADC_CTRL1_PH1IEN)   /* Interrupt enable for PHS1 */
#define ADC_INT_PHS2                        ((uint32_t)ADC_CTRL1_PH2IEN)   /* Interrupt enable for PHS2 */
#define ADC_INT_PHS3                        ((uint32_t)ADC_CTRL1_PH3IEN)   /* Interrupt enable for PHS3 */
#define ADC_INT_PHS4                        ((uint32_t)ADC_CTRL1_PH4IEN)   /* Interrupt enable for PHS4 */

/** ADC external trigger conversion definition **/ 
#define ADC_EXT_LINE_TRIGCONV_ENABLE        (ADC_TRIGSEL_EXTILINEEN)
/** ADC software trigger start conversion definition **/ 
#define ADC_SWTRIG_ENABLE                   (ADC_TRIGSEL_SWEN)


/** ADC sampling time define **/
#define ADC_SAMP_TIME_MASK                  ((uint32_t)0x0000000FU)
#define ADC_SAMP_TIME_4CYCLES               ((uint32_t)0x00000000U)
#define ADC_SAMP_TIME_6CYCLES               ((uint32_t)0x00000001U)
#define ADC_SAMP_TIME_14CYCLES              ((uint32_t)0x00000002U)
#define ADC_SAMP_TIME_20CYCLES              ((uint32_t)0x00000003U)
#define ADC_SAMP_TIME_29CYCLES              ((uint32_t)0x00000004U)
#define ADC_SAMP_TIME_42CYCLES              ((uint32_t)0x00000005U)
#define ADC_SAMP_TIME_56CYCLES              ((uint32_t)0x00000006U)
#define ADC_SAMP_TIME_72CYCLES              ((uint32_t)0x00000007U)
#define ADC_SAMP_TIME_88CYCLES              ((uint32_t)0x00000008U)
#define ADC_SAMP_TIME_120CYCLES             ((uint32_t)0x00000009U)
#define ADC_SAMP_TIME_182CYCLES             ((uint32_t)0x0000000AU)
#define ADC_SAMP_TIME_240CYCLES             ((uint32_t)0x0000000BU)
#define ADC_SAMP_TIME_300CYCLES             ((uint32_t)0x0000000CU)
#define ADC_SAMP_TIME_400CYCLES             ((uint32_t)0x0000000DU)
#define ADC_SAMP_TIME_480CYCLES             ((uint32_t)0x0000000EU)
#define ADC_SAMP_TIME_600CYCLES             ((uint32_t)0x0000000FU)


/** ADC analog watchdog mode define **/
#define ADC_ANALOG_WTDG_MODE_MASK            ((uint32_t)(~ADC_CTRL1_AWDGSGLEN))
#define ADC_ANALOG_WTDG_SINGLE_MODE          ((uint32_t)ADC_CTRL1_AWDGSGLEN)/* Enable the watchdog on a single channel in scan mode */
#define ADC_ANALOG_WTDG_SCAN_MODE            ((uint32_t)0x00000000U)


/** ADC analog watchdog single mode channel define**/
#define ADC_ANALOG_WTDG_SINGLE_CH_MASK       ((uint32_t)(~ADC_CTRL1_AWDGCH))/* AWDG_CH[4:0] bits (Analog watchdog channel select bits) */
#define ADC_ANALOG_WTDG_SINGLE_CH0           ((uint8_t)0x00000000U)
#define ADC_ANALOG_WTDG_SINGLE_CH1           ((uint8_t)0x00000001U)
#define ADC_ANALOG_WTDG_SINGLE_CH2           ((uint8_t)0x00000002U)
#define ADC_ANALOG_WTDG_SINGLE_CH3           ((uint8_t)0x00000003U)
#define ADC_ANALOG_WTDG_SINGLE_CH4           ((uint8_t)0x00000004U)
#define ADC_ANALOG_WTDG_SINGLE_CH5           ((uint8_t)0x00000005U)
#define ADC_ANALOG_WTDG_SINGLE_CH6           ((uint8_t)0x00000006U)
#define ADC_ANALOG_WTDG_SINGLE_CH7           ((uint8_t)0x00000007U)
#define ADC_ANALOG_WTDG_SINGLE_CH8           ((uint8_t)0x00000008U)
#define ADC_ANALOG_WTDG_SINGLE_CH9           ((uint8_t)0x00000009U)
#define ADC_ANALOG_WTDG_SINGLE_CH10          ((uint8_t)0x0000000AU)
#define ADC_ANALOG_WTDG_SINGLE_CH11          ((uint8_t)0x0000000BU)
#define ADC_ANALOG_WTDG_SINGLE_CH12          ((uint8_t)0x0000000CU)
#define ADC_ANALOG_WTDG_SINGLE_CH13          ((uint8_t)0x0000000DU)
#define ADC_ANALOG_WTDG_SINGLE_CH14          ((uint8_t)0x0000000EU)
#define ADC_ANALOG_WTDG_SINGLE_CH15          ((uint8_t)0x0000000FU)
#define ADC_ANALOG_WTDG_SINGLE_CH16          ((uint8_t)0x00000010U)

/** ADC analog watchdog single mode channel define**/
#define ADC_ANALOG_WTDG_DAT_MASK             ((uint32_t)(~ADC_AWDEN_AWDENx))/* AWDG_GEN[9:0] bits (Analog watchdog channel select bits) */
#define ADC_ANALOG_WTDG_DAT0                 ((uint16_t)ADC_AWDEN_AWDENx_0)
#define ADC_ANALOG_WTDG_DAT1                 ((uint16_t)ADC_AWDEN_AWDENx_1)
#define ADC_ANALOG_WTDG_DAT2                 ((uint16_t)ADC_AWDEN_AWDENx_2)
#define ADC_ANALOG_WTDG_DAT3                 ((uint16_t)ADC_AWDEN_AWDENx_3)
#define ADC_ANALOG_WTDG_DAT4                 ((uint16_t)ADC_AWDEN_AWDENx_4)
#define ADC_ANALOG_WTDG_DAT5                 ((uint16_t)ADC_AWDEN_AWDENx_5)
#define ADC_ANALOG_WTDG_DAT6                 ((uint16_t)ADC_AWDEN_AWDENx_6)
#define ADC_ANALOG_WTDG_DAT7                 ((uint16_t)ADC_AWDEN_AWDENx_7)
#define ADC_ANALOG_WTDG_DAT8                 ((uint16_t)ADC_AWDEN_AWDENx_8)
#define ADC_ANALOG_WTDG_DAT9                 ((uint16_t)ADC_AWDEN_AWDENx_9)

/** ADC flags definition **/
#define ADC_INT_FLAG_AWDG                    ((uint16_t)ADC_STS_AWDG)
#define ADC_INT_FLAG_ENDC                    ((uint16_t)ADC_STS_ENDC)
#define ADC_INT_FLAG_ENDCA                   ((uint16_t)ADC_STS_ENDCA)
#define ADC_INT_FLAG_PHS4                    ((uint16_t)ADC_STS_PH4F)
#define ADC_INT_FLAG_PHS3                    ((uint16_t)ADC_STS_PH3F)
#define ADC_INT_FLAG_PHS2                    ((uint16_t)ADC_STS_PH2F)
#define ADC_INT_FLAG_PHS1                    ((uint16_t)ADC_STS_PH1F)

#define ADC_FLAG_ALL                         ((uint16_t)0xFFFU)
#define ADC_FLAG_BUF_RDY                     ((uint16_t)ADC_STS_VREFRDY)
#define ADC_FLAG_RDY                         ((uint16_t)ADC_STS_RDY)
#define ADC_FLAG_PD_RDY                      ((uint16_t)ADC_STS_PDRDY)
#define ADC_FLAG_AWDG                        ((uint16_t)ADC_STS_AWDG)
#define ADC_FLAG_ENDC                        ((uint16_t)ADC_STS_ENDC)
#define ADC_FLAG_STR                         ((uint16_t)ADC_STS_STR)
#define ADC_FLAG_ENDCA                       ((uint16_t)ADC_STS_ENDCA)
#define ADC_FLAG_PHS4                        ((uint16_t)ADC_STS_PH4F)
#define ADC_FLAG_PHS3                        ((uint16_t)ADC_STS_PH3F)
#define ADC_FLAG_PHS2                        ((uint16_t)ADC_STS_PH2F)
#define ADC_FLAG_PHS1                        ((uint16_t)ADC_STS_PH1F)



/** ADC regular data register define **/
#define ADC_DATA_MASK                         (ADC_SEQ1_SEQ1)

/** ADC sample register define **/
#define ADC_PHS_TRG_CONFIG_MASK               (ADC_PHCFG_TRIGMD | ADC_PHCFG_PH4CHNUM | ADC_PHCFG_PH3CHNUM| ADC_PHCFG_PH2CHNUM | ADC_PHCFG_PH1CHNUM)
#define ADC_PHS_TRG_MODE_SINGLE               ((uint32_t)0x00U)
#define ADC_PHS_TRG_MODE_TWO                  (ADC_PHCFG_TRIGMD_0)
#define ADC_PHS_TRG_MODE_THREE                (ADC_PHCFG_TRIGMD_1)
#define ADC_PHS_TRG_MODE_FOUR                 (ADC_PHCFG_TRIGMD_1 | ADC_PHCFG_TRIGMD_0)

/** ADC start conversin register define **/
#define ADC_SWSTRRCH_PHSx_START_MASK          ((uint32_t)(~ADC_PHSWTRIG_PHSWSTART))
#define ADC_SWSTRRCH_PHS1_START               ((uint16_t)0xA5A1U)
#define ADC_SWSTRRCH_PHS2_START               ((uint16_t)0xF0F2U)
#define ADC_SWSTRRCH_PHS3_START               ((uint16_t)0X5A53U)
#define ADC_SWSTRRCH_PHS4_START               ((uint16_t)0X0FA4U)

/** ADC VREFINT definition **/ 
#define ADC_VREFINT_ENABLE                    ((uint32_t)ADC_CTRL3_VREFEN)    /*ADC internal vrefint enable.*/

/** ADC Reference source select  definition **/ 
#define ADC_REF_SEL_VREF                      ((uint32_t)(ADC_CTRL1_REFSEL))

/* ADC data registers read define */
#define ADC_DATA_REG_READ(data, num)          (*(uint32_t*)((uint32_t)&data + 4*num))


/** ADC Driving Functions Declaration **/
void ADC_DeInit(void);
void ADC_Init(ADC_InitType* ADC_initstruct);
void ADC_InitStruct(ADC_InitType* ADC_initstruct);
void ADC_Enable(FunctionalState Cmd);
void ADC_ConfigInt(uint16_t ADC_IT, FunctionalState Cmd);

void ADC_EnableSoftwareTrig(FunctionalState Cmd);
void ADC_EnableExternalLineTrig(FunctionalState Cmd);
FlagStatus ADC_GetSoftwareTrigStatus(void);
FlagStatus ADC_GetExtiLineTrigStatus(void);


uint16_t ADC_GetDat(void);
uint16_t ADC_GetGroupConvDat(uint8_t number);
void ADC_ConfigAnalogWatchdogModeChannel(uint16_t channel);
void ADC_ConfigAnalogWatchdogThresholds(uint16_t HighThreshold, uint16_t LowThreshold);
FlagStatus ADC_GetFlagStatus(uint16_t ADC_FLAG);
void ADC_ClearFlag(uint16_t ADC_FLAG);
INTStatus ADC_GetIntStatus(uint16_t ADC_IT);
void ADC_ClearIntPendingBit(uint16_t ADC_IT);

void ADC_EnableInternalInputBuffer(FunctionalState Cmd);
void ADC_EnableTempSensor(FunctionalState Cmd);
void ADC_EnableVREFPAsReferenceVoltag(FunctionalState Cmd);
void ADC_ConfigRegularChannel(uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
void ADC_ClockModeConfig(uint32_t RCC_ADCHCLKprescaler);
void ADC_SampleModeConfig(uint32_t mode,uint8_t PH1CHNUM,uint8_t PH2CHNUM,uint8_t PH3CHNUM,uint8_t PH4CHNUM);
void ADC_EnableChannelStartConv(uint32_t PHSWSTART);
#ifdef __cplusplus
}
#endif

#endif /*__N32G033_ADC_H__ */

