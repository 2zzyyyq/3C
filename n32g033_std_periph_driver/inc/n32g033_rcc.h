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
*\*\file n32g033_rcc.h
*\*\author Nsing
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
 */
#ifndef __N32G033_RCC_H__
#define __N32G033_RCC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "n32g033.h"


/** RCC_Exported_Types **/

typedef struct
{
    uint32_t SysclkFreq;    /*!< returns SYSCLK clock frequency expressed in Hz */
    uint32_t HclkFreq;      /*!< returns HCLK clock frequency expressed in Hz */
    uint32_t PclkFreq;     /*!< returns PCLK1 clock frequency expressed in Hz */
    uint32_t AdcHclkFreq;   /*!< returns ADCHCLK clock frequency expressed in Hz */
} RCC_ClocksType;


/** RCC RCC_REG_BIT_MASK **/
#define RCC_REG_BIT_MASK  ((uint32_t)0x00000000)

/* CTRL register bit mask */
#define CTRL_HSITRIM_MASK                 (~RCC_CTRL_HSITRIM)
#define RCC_HSI_ENABLE                    (RCC_CTRL_HSIEN)   
#define LSCTRL_LSITRIM_MASK               (~RCC_LSCTRL_LSITRIM)

/* CFG register bit mask */
#define CFG_APBPRES_MASK                 (~RCC_CFG_APBPRES)
#define CFG_HPRE_MASK                    (~RCC_CFG_AHBPRES)
#define CFG_SCLKSTS_MASK                 (RCC_CFG_SCLKSTS)
#define CFG_SCLKSW_MASK                  (~RCC_CFG_SCLKSW)
#define CFG_SYSPRES_MASK                 (~RCC_CFG_SYSPRES)
#define RCC_TIM_CLKSRC_MASK              (~RCC_CFG_TIMXCLKSEL) 
#define RCC_TIM_CLKSRC_SYSCLK            (RCC_REG_BIT_MASK)
#define RCC_TIM_CLKSRC_HCLK              (RCC_CFG_TIMXCLKSEL)
#define RCC_TIM6_CLKSRC_MASK             (~RCC_CFG_TIM6CLKSEL) 
#define RCC_TIM6_CLKSRC_SYSCLK           (RCC_REG_BIT_MASK)
#define RCC_TIM6_CLKSRC_HCLK             (RCC_CFG_TIM6CLKSEL)
#define RCC_UART3_CLKSRC_MASK            (~RCC_CFG_UART3CLKSEL) 
#define RCC_UART3_CLKSRC_PCLK            (RCC_REG_BIT_MASK)
#define RCC_UART3_CLKSRC_LSI             (RCC_CFG_UART3CLKSEL)
#define CTRL_LSICALLEN_MASK              (~RCC_CTRL_LSICALLEN)
#define LSCTRL_TRIMSEL_MASK              (~RCC_LSCTRL_TRIMSEL)

/* CFG2 register bit mask */
#define CFG2_ADCHPRE_MASK                 (~RCC_CFG2_ADCHPRE)

/* EMCCTRL register bit mask */
#define EMCCTRL_GVDETSEL_MASK             (~RCC_EMCCTRL_GVDETSEL)
#define EMCCTRL_GBDETSEL_MASK             (~RCC_EMCCTRL_GBDETSEL)
#define EMCCTRL_GBNDETSEL_MASK            (~RCC_EMCCTRL_GBNDETSEL)

/* TIMFILTCFG register bit mask */
#define TIMFILTCFG_IOFLITCLK_MASK         (~RCC_TIMFILTCFG_IOFLITCLK)
#define TIMFILTCFG_TIM4FLITCLK_MASK       (~RCC_TIMFILTCFG_TIM4FILTCLK)
#define TIMFILTCFG_TIM3FLITCLK_MASK       (~RCC_TIMFILTCFG_TIM3FILTCLK)
#define TIMFILTCFG_TIM1FLITCLK_MASK       (~RCC_TIMFILTCFG_TIM1FILTCLK)

/* System_clock_pres */
#define RCC_SYSCLK_PRES_DIV1    (RCC_REG_BIT_MASK)
#define RCC_SYSCLK_PRES_DIV2    (RCC_CFG_SYSPRES)

/* System_clock_source */
#define RCC_SYSCLK_SRC_HSI    (RCC_REG_BIT_MASK)
#define RCC_SYSCLK_SRC_LSI    (RCC_CFG_SCLKSW)


/* AHB_clock_source */
#define RCC_SYSCLK_DIV1   (RCC_REG_BIT_MASK)
#define RCC_SYSCLK_DIV2   (RCC_CFG_AHBPRES_2)
#define RCC_SYSCLK_DIV4   (RCC_CFG_AHBPRES_2|RCC_CFG_AHBPRES_0)
#define RCC_SYSCLK_DIV8   (RCC_CFG_AHBPRES_2|RCC_CFG_AHBPRES_1)
#define RCC_SYSCLK_DIV16  (RCC_CFG_AHBPRES_2|RCC_CFG_AHBPRES_1|RCC_CFG_AHBPRES_0)

/* APB1_APB2_clock_source */
#define RCC_HCLK_DIV1  (RCC_REG_BIT_MASK)
#define RCC_HCLK_DIV2   (RCC_CFG_APBPRES_2)
#define RCC_HCLK_DIV4   (RCC_CFG_APBPRES_2|RCC_CFG_APBPRES_0)
#define RCC_HCLK_DIV8   (RCC_CFG_APBPRES_2|RCC_CFG_APBPRES_1)
#define RCC_HCLK_DIV16  (RCC_CFG_APBPRES_2|RCC_CFG_APBPRES_1|RCC_CFG_APBPRES_0)


/* RCC_Interrupt_source */
#define RCC_INT_LSIRDIF        (RCC_CLKINT_LSIRDF)
#define RCC_INT_HSIRDIF        (RCC_CLKINT_HSIRDF)


#define RCC_CLR_LSIRDIF        (RCC_CLKINT_LSIRDCLR)
#define RCC_CLR_HSIRDIF        (RCC_CLKINT_HSIRDCLR)

#define RCC_ADCHCLK_DIV2       (RCC_CFG2_ADCHPRE_0)
#define RCC_ADCHCLK_DIV4       (RCC_CFG2_ADCHPRE_1|RCC_CFG2_ADCHPRE_0)
#define RCC_ADCHCLK_DIV8       (RCC_CFG2_ADCHPRE_2)
#define RCC_ADCHCLK_DIV16      (RCC_CFG2_ADCHPRE_2|RCC_CFG2_ADCHPRE_0)
#define RCC_ADCHCLK_DIV32      (RCC_CFG2_ADCHPRE_2|RCC_CFG2_ADCHPRE_1)
#define RCC_ADCHCLK_DIV_OTHERS (RCC_CFG2_ADCHPRE_2|RCC_CFG2_ADCHPRE_1)
		 
/* AHB_peripheral */
#define RCC_AHB_PERIPH_SQRT    (RCC_AHBPCLKEN_SQRTEN) 
#define RCC_AHB_PERIPH_HDIV    (RCC_AHBPCLKEN_HDIVEN) 
#define RCC_AHB_PERIPH_ADC     (RCC_AHBPCLKEN_ADCEN) 
#define RCC_AHB_PERIPH_DMA     (RCC_AHBPCLKEN_DMAEN)

/* APB_peripheral */
#define RCC_APB_PERIPH_GPIO       (RCC_APBPCLKEN_IOMEN)  
#define RCC_APB_PERIPH_I2C1       (RCC_APBPCLKEN_I2C1EN)  
#define RCC_APB_PERIPH_I2C2       (RCC_APBPCLKEN_I2C2EN)  
#define RCC_APB_PERIPH_PWR        (RCC_APBPCLKEN_PWREN)
#define RCC_APB_PERIPH_SPI1       (RCC_APBPCLKEN_SPI1EN)
#define RCC_APB_PERIPH_SPI2       (RCC_APBPCLKEN_SPI2EN)
#define RCC_APB_PERIPH_TIM1       (RCC_APBPCLKEN_TIM1EN)
#define RCC_APB_PERIPH_TIM3       (RCC_APBPCLKEN_TIM3EN)
#define RCC_APB_PERIPH_TIM4       (RCC_APBPCLKEN_TIM4EN)
#define RCC_APB_PERIPH_TIM6       (RCC_APBPCLKEN_TIM6EN)
#define RCC_APB_PERIPH_UART1      (RCC_APBPCLKEN_UART1EN)
#define RCC_APB_PERIPH_UART2      (RCC_APBPCLKEN_UART2EN)
#define RCC_APB_PERIPH_UART3      (RCC_APBPCLKEN_UART3EN)
#define RCC_APB_PERIPH_COMP       (RCC_APBPCLKEN_COMPEN)
#define RCC_APB_PERIPH_COMPFILT   (RCC_APBPCLKEN_COMPFILTEN)
#define RCC_APB_PERIPH_OPA        (RCC_APBPCLKEN_OPAEN)

#define RCC_MCO_DIV_MASK  (~RCC_CFG_MCOPRES)
#define RCC_MCO_CLK_DIV2  (RCC_CFG_MCOPRES_1)
#define RCC_MCO_CLK_DIV3  (RCC_CFG_MCOPRES_1|RCC_CFG_MCOPRES_0)
#define RCC_MCO_CLK_DIV4  (RCC_CFG_MCOPRES_2)
#define RCC_MCO_CLK_DIV5  (RCC_CFG_MCOPRES_2|RCC_CFG_MCOPRES_0)
#define RCC_MCO_CLK_DIV6  (RCC_CFG_MCOPRES_2|RCC_CFG_MCOPRES_1)
#define RCC_MCO_CLK_DIV7  (RCC_CFG_MCOPRES_2|RCC_CFG_MCOPRES_1|RCC_CFG_MCOPRES_0)

 /* RCC Flag Clock_source_to_output_on_MCO_pin */
#define RCC_MCO_MASK        (~RCC_CFG_MCO)
#define RCC_MCO_NOCLK       (RCC_REG_BIT_MASK)
#define RCC_MCO_LSI         (RCC_CFG_MCO_0)
#define RCC_MCO_SYSCLK      (RCC_CFG_MCO_1)
#define RCC_MCO_HSI         ((uint32_t)(RCC_CFG_MCO_0 | RCC_CFG_MCO_1))

/* RCC Flag Mask */
#define RCC_FLAG_MASK               ((uint8_t)0x1F)
#define RCC_CTRL_FLAG_HSIRDF        ((uint8_t)0x21)
#define RCC_CTRL_FLAG_LSICALCF      ((uint8_t)0x2B)
#define RCC_CLKINT_FLAG_LSIRDF      ((uint8_t)0x40)
#define RCC_CTRLSTS_FLAG_PINRSTF    ((uint8_t)0x83)
#define RCC_CTRLSTS_FLAG_PORRSTF    ((uint8_t)0x84)
#define RCC_CTRLSTS_FLAG_SFTRSTF    ((uint8_t)0x85)
#define RCC_CTRLSTS_FLAG_IWDGRSTF   ((uint8_t)0x86)
#define RCC_CTRLSTS_FLAG_GLITCHF    ((uint8_t)0x87)
#define RCC_CTRLSTS_FLAG_EMCGBRSTF  ((uint8_t)0x88)
#define RCC_CTRLSTS_FLAG_EMCGBNRSTF ((uint8_t)0x89)
#define RCC_CTRLSTS_FLAG_LKUPRSTF   ((uint8_t)0x8B)
#define RCC_REMOVE_RESET_FLAG       (RCC_CTRLSTS_RMRSTF)

#define RCC_EMC_GB      (RCC_EMCCTRL_GBDET)
#define RCC_EMC_GBN     (RCC_EMCCTRL_GBNDET)

/* RCC LSI CAL */
#define RCC_LSICAL_SRC_AFEC      (RCC_REG_BIT_MASK)
#define RCC_LSICAL_SRC_TRIM      (RCC_LSCTRL_TRIMSEL)

#define RCC_LSICAL_PERIOD_128      (RCC_REG_BIT_MASK)
#define RCC_LSICAL_PERIOD_256      (RCC_CTRL_LSICALLEN_0)
#define RCC_LSICAL_PERIOD_512      (RCC_CTRL_LSICALLEN_1)
#define RCC_LSICAL_PERIOD_1024     (RCC_CTRL_LSICALLEN_0|RCC_CTRL_LSICALLEN_1)

/*** RCC Macro Definition End ***/

/*** RCC Driving Functions Declaration ***/
void RCC_DeInit(void);
void RCC_EnableHsi(FunctionalState Cmd);
ErrorStatus RCC_WaitHsiStable(void);
void RCC_SetHsiCalibValue(uint16_t calibration_value);
void RCC_ConfigLsiCalibSource(uint32_t cal_src);
void RCC_SetLsiCalibValue(uint16_t calibration_value);
void RCC_ConfigSysclkPres(uint32_t sysclk_pres);
void RCC_ConfigSysclk(uint32_t sysclk_source);
uint32_t RCC_GetSysclkSrc(void);
void RCC_ConfigHclk(uint32_t sysclk_div);
void RCC_ConfigPclk(uint32_t hclk_div);
void RCC_ConfigAdcHclk(uint32_t hclk_prescaler);
void RCC_GetClocksFreqValue(RCC_ClocksType* RCC_Clocks);
void RCC_EnableAHBPeriphClk(uint32_t AHB_periph, FunctionalState Cmd);
void RCC_EnableAPBPeriphClk(uint32_t APB_periph, FunctionalState Cmd);
void RCC_EnableAHBPeriphReset(uint32_t AHB_periph);
void RCC_EnableAPBPeriphReset(uint32_t APB_periph);
void RCC_ConfigMcoClkPre(uint32_t MCO_PLL_prescaler);
void RCC_ConfigMco(uint32_t MCO_source);
FlagStatus RCC_GetFlagStatus(uint8_t RCC_FLAG);
void RCC_ClearResetFlag(void);
INTStatus RCC_GetIntStatus(uint8_t interrupt_flag);
void RCC_ClrIntPendingBit(uint32_t interrupt_clear);
void RCC_EnableEMCReset(uint32_t EMC_type, FunctionalState Cmd);
void RCC_EnableEMCDetect(uint32_t EMC_type, FunctionalState Cmd);
void RCC_EnableEMCSwitch(uint32_t EMC_type, FunctionalState Cmd);
void RCC_ConfigEMCDetectLevel(uint32_t EMC_type, uint8_t level);
void RCC_EnableGlitchDetect(FunctionalState Cmd);
void RCC_EnableGlitchReset(FunctionalState Cmd);
void RCC_EnableGlitchSwitch(FunctionalState Cmd);
void RCC_ConfigGlitchDetectLevel(uint8_t level);
void RCC_EnableM0LockupReset(FunctionalState Cmd);
void RCC_ConfigTimClk(uint32_t timer_clksrc);
void RCC_ConfigTim6Clk(uint32_t timer_clksrc);
void RCC_ConfigUart3Clk(uint32_t uart3_clksrc);
void RCC_ConfigIOFilter(uint32_t ioflitclk_div);
void RCC_ConfigTIM4Filter(uint32_t tim4flitclk_div);
void RCC_ConfigTIM3Filter(uint32_t tim3flitclk_div);
void RCC_ConfigTIM1Filter(uint32_t tim1flitclk_div);
void RCC_ConfigLSICalibPeriod(uint32_t lsi_period); 
void RCC_EnableLSICalibration(FunctionalState Cmd);
uint32_t RCC_GetHSICalibPeriod(void);
#ifdef __cplusplus
}
#endif

#endif /* __N32G033_RCC_H__ */
