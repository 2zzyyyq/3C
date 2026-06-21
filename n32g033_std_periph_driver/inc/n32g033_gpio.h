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
*\*\file n32g033_gpio.h
*\*\author Nsing
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/

#ifndef __N32G033_GPIO_H__
#define __N32G033_GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "n32g033.h"

typedef struct
{
    uint32_t Pin; /* Specifies the GPIO pins to be configured. */
    
    uint32_t GPIO_Mode; /* Specifies the operating mode for the selected pins. */

    uint32_t GPIO_Pull;  /* Specifies the Pull-up or Pull-Down activation for the selected pins. */
    
    uint32_t GPIO_Alternate; /* Specifies the alternate function for the selected pins */ 
} GPIO_InitType;

/** Bit_SET and Bit_RESET enumeration **/

typedef enum
{
    Bit_RESET = 0,
    Bit_SET
} Bit_OperateType;

#define GPIO_AF_MODE                    ((uint32_t)GPIO_PMODE0_2)
#define GPIO_PU_MODE                    ((uint32_t)GPIO_PUPD0_1)
#define GPIO_PD_MODE                    ((uint32_t)GPIO_PUPD0_2)


#define GPIO_GET_INDEX(PERIPH) (((PERIPH) == (GPIOA))? 0U :\
                                ((PERIPH) == (GPIOB))? 1U : \
                                ((PERIPH) == (GPIOF))? 2U :4U)

#define GPIO_GET_PERIPH(INDEX) (((INDEX)==((uint8_t)0x00U))? GPIOA :\
                                ((INDEX)==((uint8_t)0x01U))? GPIOB :GPIOF)
                           


/** GPIO_pins_define **/
#define GPIO_PIN_0           ((uint16_t)0x0001U) /* Pin 0 selected    */
#define GPIO_PIN_1           ((uint16_t)0x0002U) /* Pin 1 selected    */
#define GPIO_PIN_2           ((uint16_t)0x0004U) /* Pin 2 selected    */
#define GPIO_PIN_3           ((uint16_t)0x0008U) /* Pin 3 selected    */
#define GPIO_PIN_4           ((uint16_t)0x0010U) /* Pin 4 selected    */
#define GPIO_PIN_5           ((uint16_t)0x0020U) /* Pin 5 selected    */
#define GPIO_PIN_6           ((uint16_t)0x0040U) /* Pin 6 selected    */
#define GPIO_PIN_7           ((uint16_t)0x0080U) /* Pin 7 selected    */
#define GPIO_PIN_8           ((uint16_t)0x0100U) /* Pin 8 selected    */
#define GPIO_PIN_9           ((uint16_t)0x0200U) /* Pin 9 selected    */
#define GPIO_PIN_10          ((uint16_t)0x0400U) /* Pin 10 selected   */
#define GPIO_PIN_11          ((uint16_t)0x0800U) /* Pin 11 selected   */
#define GPIO_PIN_12          ((uint16_t)0x1000U) /* Pin 12 selected   */
#define GPIO_PIN_13          ((uint16_t)0x2000U) /* Pin 13 selected   */
#define GPIO_PIN_14          ((uint16_t)0x4000U) /* Pin 14 selected   */
#define GPIO_PIN_15          ((uint16_t)0x8000U) /* Pin 15 selected   */
#define GPIO_PIN_ALL         ((uint16_t)0xFFFFU) /* All pins selected */

#define GPIOA_PIN_AVAILABLE   GPIO_PIN_ALL
#define GPIOB_PIN_AVAILABLE  (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 )
#define GPIOF_PIN_AVAILABLE  (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3)


/** GPIO_mode_define **/
#define GPIO_MODE_INPUT         ((uint32_t)0x00000000U)  /* Input Floating Mode */
#define GPIO_MODE_OUTPUT_PP     ((uint32_t)0x00000001U)  /* Output Push Pull Mode */
#define GPIO_MODE_OUTPUT_OD     ((uint32_t)0x00000011U)  /* Output Open Drain Mode */
#define GPIO_MODE_AF_PP         ((uint32_t)0x00000002U)  /* Alternate Function Push Pull Mode  */
#define GPIO_MODE_AF_OD         ((uint32_t)0x00000012U)  /* Alternate Function Open Drain Mode */
#define GPIO_MODE_ANALOG        ((uint32_t)0x00000003U)  /* Analog Mode */

/** GPIO Pull-Up or Pull-Down Activation **/
#define GPIO_NO_PULL         ((uint32_t)GPIO_PUPD0_0) /* No Pull-up or Pull-down activation */
#define GPIO_PULL_UP         ((uint32_t)GPIO_PUPD0_1) /* Pull-up activation */
#define GPIO_PULL_DOWN       ((uint32_t)GPIO_PUPD0_2) /* Pull-down activation */


#define GPIOA_PORT_SOURCE ((uint8_t)0x00U)
#define GPIOB_PORT_SOURCE ((uint8_t)0x01U)
#define GPIOF_PORT_SOURCE ((uint8_t)0x05U)

/* GPIO_Pin_sources */
#define GPIO_PIN_SOURCE0  ((uint8_t)0x00U)
#define GPIO_PIN_SOURCE1  ((uint8_t)0x01U)
#define GPIO_PIN_SOURCE2  ((uint8_t)0x02U)
#define GPIO_PIN_SOURCE3  ((uint8_t)0x03U)
#define GPIO_PIN_SOURCE4  ((uint8_t)0x04U)
#define GPIO_PIN_SOURCE5  ((uint8_t)0x05U)
#define GPIO_PIN_SOURCE6  ((uint8_t)0x06U)
#define GPIO_PIN_SOURCE7  ((uint8_t)0x07U)
#define GPIO_PIN_SOURCE8  ((uint8_t)0x08U)
#define GPIO_PIN_SOURCE9  ((uint8_t)0x09U)
#define GPIO_PIN_SOURCE10 ((uint8_t)0x0AU)
#define GPIO_PIN_SOURCE11 ((uint8_t)0x0BU)
#define GPIO_PIN_SOURCE12 ((uint8_t)0x0CU)
#define GPIO_PIN_SOURCE13 ((uint8_t)0x0DU)
#define GPIO_PIN_SOURCE14 ((uint8_t)0x0EU)
#define GPIO_PIN_SOURCE15 ((uint8_t)0x0FU)

typedef enum
{
    AFIO_ADC_TRIG_EXTI_0 = 0x00U,
    AFIO_ADC_TRIG_EXTI_1 = 0x01U,
    AFIO_ADC_TRIG_EXTI_2,
    AFIO_ADC_TRIG_EXTI_3,
    AFIO_ADC_TRIG_EXTI_4,
    AFIO_ADC_TRIG_EXTI_5,
    AFIO_ADC_TRIG_EXTI_6,
}AFIO_ADC_Trig_RemapType;

/* GPIO_EXTILINE_sources */
#define GPIO_EXTILINE_SOURCE0  ((uint8_t)0x00U)
#define GPIO_EXTILINE_SOURCE1  ((uint8_t)0x01U)
#define GPIO_EXTILINE_SOURCE2  ((uint8_t)0x02U)
#define GPIO_EXTILINE_SOURCE3  ((uint8_t)0x03U)
#define GPIO_EXTILINE_SOURCE4  ((uint8_t)0x04U)
#define GPIO_EXTILINE_SOURCE5  ((uint8_t)0x05U)
#define GPIO_EXTILINE_SOURCE6  ((uint8_t)0x06U)



/** GPIOx_Alternate_function_selection Alternate function selection **/
#define GPIO_AF0        ((uint8_t)0x00U)
#define GPIO_AF1        ((uint8_t)0x01U)
#define GPIO_AF2        ((uint8_t)0x02U)
#define GPIO_AF3        ((uint8_t)0x03U)
#define GPIO_AF4        ((uint8_t)0x04U)
#define GPIO_AF5        ((uint8_t)0x05U)
#define GPIO_AF6        ((uint8_t)0x06U)
#define GPIO_AF7        ((uint8_t)0x07U) 
#define GPIO_AF8        ((uint8_t)0x08U)
#define GPIO_AF9        ((uint8_t)0x09U)
#define GPIO_AF10       ((uint8_t)0x0AU)
#define GPIO_AF11       ((uint8_t)0x0BU)
#define GPIO_AF12       ((uint8_t)0x0CU)
#define GPIO_NO_AF      ((uint8_t)0x0FU)  /* NON Alternate Function mapping */

/** SPI mode definition in AFIO register  **/
#define AFIO_SPI1_NSS   (AFIO_CFG_SPI1_NSS)
#define AFIO_SPI2_NSS   (AFIO_CFG_SPI2_NSS)

#define AFIO_SPI_NSS_HIGH_IMPEDANCE (0x0UL)
#define AFIO_SPI_NSS_High_LEVEL     (0x1UL)

#define AFIO_EXTI_CFGAMASK               ((uint32_t)AFIO_EXTI_CFG1_EXTI0)
#define AFIO_EXTI_CFGBMASK               ((uint32_t)AFIO_EXTI_CFG2_EXTI5)
#define AFIO_EXTI_CFGFMASK               ((uint32_t)AFIO_EXTI_CFG2_EXTI6)
#define AFIO_EXTI_CFGBITWIDTH            ((uint32_t)0x00000004U)
#define AFIO_EXTI6_OFFSET                (REG_BIT8_OFFSET)
#define AFIO_EXTI_FILTEN                 (AFIO_CFG_EXTIFILTEN)

/** slew rate config **/
#define GPIOB_SLEW_RATE_FAST             ((uint32_t)0x00000000U)
#define GPIOB_SLEW_RATE_SLOW             ((uint32_t)0x00000001U)

/** driver strength config **/
#define GPIOB_HIGH_DREIVE                ((uint32_t)0x00000000U)
#define GPIOB_LOW_DREIVE                 ((uint32_t)0x00000001U)

#define GPIOB_DS_MASK                    ((uint32_t)0xFFFFFFC7U)
#define GPIOB_SR_MASK                    ((uint32_t)0xFFFFF8FFU)

#define GPIO_PB3                         ((uint32_t)0x00000003U)
#define GPIO_PB4                         ((uint32_t)0x00000004U)
#define GPIO_PB5                         ((uint32_t)0x00000005U)

/** GPIO_Exported_Functions **/
void GPIO_DeInit(void);
void GPIO_DeInitPin(GPIO_Module* GPIOx, uint32_t GPIO_Pin);
void GPIO_InitPeripheral(GPIO_Module* GPIOx, GPIO_InitType* GPIO_InitStruct);
void GPIO_InitStruct(GPIO_InitType* GPIO_InitStruct);
uint8_t GPIO_ReadInputDataBit(GPIO_Module* GPIOx, uint16_t Pin);
uint16_t GPIO_ReadInputData(GPIO_Module* GPIOx);
uint8_t GPIO_ReadOutputDataBit(GPIO_Module* GPIOx, uint16_t Pin);
uint16_t GPIO_ReadOutputData(GPIO_Module* GPIOx);
void GPIO_SetBits(GPIO_Module* GPIOx, uint16_t Pin);
void GPIO_WritePBSC(GPIO_Module* GPIOx, uint16_t Pin,uint8_t bitstatus);
void GPIO_ResetBits(GPIO_Module* GPIOx, uint16_t Pin);
void GPIO_WriteBit(GPIO_Module* GPIOx, uint16_t Pin, Bit_OperateType BitCmd);
void GPIO_Write(GPIO_Module* GPIOx, uint16_t PortVal);
void GPIO_TogglePin(GPIO_Module* GPIOx, uint16_t Pin);
void GPIO_ConfigPinLock(GPIO_Module* GPIOx, uint16_t Pin);
void GPIO_ConfigEXTILine(uint8_t PortSource, uint8_t PinSource);
void GPIO_ClearEXTILine( uint8_t LineSource);
void AFIO_ConfigEXTIFlitEN(FunctionalState Cmd);
void GPIO_ConfigPinRemap(uint8_t PortSource, uint8_t PinSource, uint32_t AlternateFunction);
void AFIO_ConfigADCExternalTrigRemap(AFIO_ADC_Trig_RemapType ADC_trigger);
void AFIO_ConfigSPINSSMode(uint32_t AFIO_SPIx_NSS, uint32_t SpiNssMode);
void AFIO_ConfigIOFlitNum(uint8_t Flit_Num);
void AFIO_DIGEFTEnable(uint8_t PortSource, uint16_t Pin, FunctionalState Cmd);
void GPIOB_Driver_Set(uint32_t current, uint32_t GPIO_Pin);
void GPIOB_SlewRate_Set(uint32_t slew_rate, uint32_t GPIO_Pin);



#ifdef __cplusplus
}
#endif

#endif /* __N32G033_GPIO_H__ */

