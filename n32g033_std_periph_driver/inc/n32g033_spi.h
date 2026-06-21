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
*\*\file      n32g033_spi.h
*\*\author    Nsing
*\*\version   v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved. 
**/
#ifndef __N32G033_SPI_H__
#define __N32G033_SPI_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "n32g033.h"

/** SPI Init structure definition **/
typedef struct
{
    uint32_t DataDirection; /* Specifies the SPI unidirectional or bidirectional data mode */

    uint32_t SpiMode;          /* Specifies the SPI operating mode */
                            
    uint32_t DataLen;       /* Specifies the SPI data size */

    uint32_t CLKPOL;        /* Specifies the serial clock steady state */
                             
    uint32_t CLKPHA;        /* Specifies the clock active edge for the bit capture */


    uint32_t NSS;           /* Specifies whether the NSS signal is managed by
                               hardware (NSS pin) or by software using the SSI bit */


    uint32_t BaudRatePres;  /* Specifies the Baud Rate prescaler value which will be
                               used to configure the transmit and receive SCK clock */

    uint32_t FirstBit;      /* Specifies whether data transfers start from MSB or LSB bit */
	
    uint32_t CRCPoly;       /* Specifies the polynomial used for the CRC calculation */
} SPI_InitType;

#define SPI_CTRL1_CLR_MASK   ((uint32_t)0x00000600U)

/** SPI_data_direction **/
#define SPI_DIR_DOUBLELINE_FULLDUPLEX ((uint32_t)0x00000000U)
#define SPI_DIR_DOUBLELINE_RONLY      ((uint32_t)SPI_CTRL1_RONLY)
#define SPI_DIR_SINGLELINE_RX         ((uint32_t)SPI_CTRL1_BIDIRMODE)
#define SPI_DIR_SINGLELINE_TX         ((uint32_t)(SPI_CTRL1_BIDIRMODE | SPI_CTRL1_BIDIROEN))
#define SPI_BIDIRECTION_RX            ((uint32_t)(~SPI_CTRL1_BIDIROEN))
#define SPI_BIDIRECTION_TX            ((uint32_t)SPI_CTRL1_BIDIROEN)
/** SPI mode **/
#define SPI_MODE_MASTER               ((uint32_t)(SPI_CTRL1_MSEL | SPI_CTRL1_SSEL))
#define SPI_MODE_SLAVE                ((uint32_t)0x00000000U)

/** SPI_data_size **/
#define SPI_DATALEN_MASK              ((uint32_t)(~SPI_CTRL1_DATFF)) /* DATFF bit Mask */
#define SPI_DATA_SIZE_16BITS          ((uint32_t)SPI_CTRL1_DATFF)
#define SPI_DATA_SIZE_8BITS           ((uint32_t)0x0000U)

#define SPI_CRCNEXT_ENABLE            (SPI_CTRL1_CRCNEXT)
#define CTRL2_CRCEN_ENABLE            (SPI_CTRL2_CRCEN)
#define CTRL2_CRCEN_DISABLE           (~SPI_CTRL2_CRCEN)

/** SPI_Clock_Polarity **/
#define SPI_CLKPOL_LOW                ((uint32_t)0x0000U)
#define SPI_CLKPOL_HIGH               ((uint32_t)SPI_CTRL1_CLKPOL)

/** SPI_Clock_Phase **/
#define SPI_CLKPHA_FIRST_EDGE         ((uint32_t)0x0000U)
#define SPI_CLKPHA_SECOND_EDGE        ((uint32_t)SPI_CTRL1_CLKPHA)

/** SPI_Slave_Select_management **/
#define SPI_NSS_SOFT                  ((uint32_t)SPI_CTRL1_SSMEN)
#define SPI_NSS_HARD                  ((uint32_t)0x0000U)

#define CTRL1_SSOEN_ENABLE            ((uint32_t)SPI_CTRL1_SSOEN)
#define CTRL1_SSOEN_DISABLE           ((uint32_t)(~SPI_CTRL1_SSOEN))

/** SPI_BaudRate_Prescaler **/
#define SPI_BR_PRESCALER_2            ((uint32_t)0x0000U)
#define SPI_BR_PRESCALER_4            ((uint32_t)SPI_CTRL1_BR0)
#define SPI_BR_PRESCALER_8            ((uint32_t)SPI_CTRL1_BR1)
#define SPI_BR_PRESCALER_16           ((uint32_t)(SPI_CTRL1_BR1 | SPI_CTRL1_BR0))
#define SPI_BR_PRESCALER_32           ((uint32_t)SPI_CTRL1_BR2)
#define SPI_BR_PRESCALER_64           ((uint32_t)(SPI_CTRL1_BR2 | SPI_CTRL1_BR0))
#define SPI_BR_PRESCALER_128          ((uint32_t)(SPI_CTRL1_BR2 | SPI_CTRL1_BR1))
#define SPI_BR_PRESCALER_256          ((uint32_t)(SPI_CTRL1_BR2 | SPI_CTRL1_BR1 | SPI_CTRL1_BR0))

/** SPI_MSB_LSB_transmission **/
#define SPI_FB_MSB                    ((uint32_t)0x0000U)
#define SPI_FB_LSB                    ((uint32_t)SPI_CTRL1_LSBFF)

/** SPI Converter **/
#define CTRL1_SPIEN_ENABLE                   ((uint32_t)SPI_CTRL2_SPIEN)  /* SPIEN ON bit */
#define CTRL1_SPIEN_DISABLE                  ((uint32_t)(~SPI_CTRL2_SPIEN)) /* SPIEN ON bit Mask */

/** SPI_DMA_transfer_requests **/
#define SPI_DMA_TX                    ((uint32_t)SPI_CTRL2_TDMAEN)
#define SPI_DMA_RX                    ((uint32_t)SPI_CTRL2_RDMAEN)

/** SPI_NSS_internal_software_management **/
#define SPI_NSS_HIGH                  ((uint32_t)SPI_CTRL1_SSEL)
#define SPI_NSS_LOW                   ((uint32_t)(~SPI_CTRL1_SSEL))

/** SPI_CRC_Transmit_Receive **/
#define SPI_CRC_TX                    ((uint8_t)0x00U)
#define SPI_CRC_RX                    ((uint8_t)0x01U)

/** SPI_flags_definition **/
#define SPI_STS_RESERVED_MASK         ((uint32_t)0x0000107FU)
#define SPI_TE_FLAG                   ((uint32_t)SPI_STS_TE)
#define SPI_RNE_FLAG                  ((uint32_t)SPI_STS_RNE)
#define SPI_CRCERR_FLAG               ((uint32_t)SPI_STS_CRCERR)
#define SPI_MODERR_FLAG               ((uint32_t)SPI_STS_MODERR)
#define SPI_OVER_FLAG                 ((uint32_t)SPI_STS_OVER)
#define SPI_BUSY_FLAG                 ((uint32_t)SPI_STS_BUSY)

#define SPI_INT_RNE                   ((uint32_t)SPI_CTRL2_RNEINTEN)  /* Rx buffer not empty interrupt mask */
#define SPI_INT_TE                    ((uint32_t)SPI_CTRL2_TEINTEN)   /* Tx buffer empty interrupt mask */
#define SPI_INT_ERR                   ((uint32_t)SPI_CTRL2_ERRINTEN)  /* Error interrupt mask */

#define SPI_INT_FLAG_RNE              (SPI_STS_RNE)
#define SPI_INT_FLAG_TE               (SPI_STS_TE)
#define SPI_INT_FLAG_CRCERR           (SPI_STS_CRCERR)
#define SPI_INT_FLAG_MODERR           (SPI_STS_MODERR)
#define SPI_INT_FLAG_OVER             (SPI_STS_OVER)
#define SPI_INT_FLAG_ERR              (SPI_STS_MODERR | SPI_STS_OVER)

/** SPI Macro Definition End **/

/** SPI Driving Functions Declaration **/
void SPI_DeInit(SPI_Module* SPIx);
void SPI_Init(SPI_Module* SPIx, SPI_InitType* SPI_InitStruct);
void SPI_InitStruct(SPI_InitType* SPI_StructInit);
void SPI_Enable(SPI_Module* SPIx, FunctionalState Cmd);
void SPI_EnableInt(SPI_Module* SPIx, uint32_t SPI_IT, FunctionalState Cmd);
void SPI_EnableDma(SPI_Module* SPIx, uint32_t SPI_DMAReq, FunctionalState Cmd);
void SPI_TransmitData(SPI_Module* SPIx, uint16_t Data);
uint16_t SPI_ReceiveData(SPI_Module* SPIx);
void SPI_SetNssLevel(SPI_Module* SPIx, uint32_t SPI_NSSInternalSoft);
void SPI_SSOutputEnable(SPI_Module* SPIx, FunctionalState Cmd);
void SPI_ConfigDataLen(SPI_Module* SPIx, uint32_t DataLen);
void SPI_TransmitCrcNext(SPI_Module* SPIx);
void SPI_EnableCalculateCrc(SPI_Module* SPIx, FunctionalState Cmd);
uint32_t SPI_GetCRCDat(SPI_Module* SPIx, uint8_t SPI_CRC);
uint32_t SPI_GetCRCPoly(SPI_Module* SPIx);
void SPI_ConfigBidirectionalMode(SPI_Module* SPIx, uint32_t DataDirection);
FlagStatus SPI_GetStatus(SPI_Module* SPIx, uint32_t SPI_FLAG);
void SPI_ClrCRCErrFlag(SPI_Module* SPIx, uint32_t SPI_FLAG);
INTStatus SPI_GetIntStatus(SPI_Module* SPIx, uint32_t SPI_IT);
void SPI_ClrITPendingBit(SPI_Module* SPIx, uint32_t SPI_FLAG);
void SPI_Configdelaytime(SPI_Module* SPIx,uint32_t DelayTime);
void SPI_NSSFailCRCEnable(SPI_Module* SPIx,FunctionalState Cmd);

#ifdef __cplusplus
}
#endif

#endif /*__N32G033_SPI_H__ */

