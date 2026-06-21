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
*\*\file n32g033_uart.h
*\*\author Nsing
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/
#ifndef __N32G033_UART_H__
#define __N32G033_UART_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "n32g033.h"

/** UART Init Structure definition **/

typedef struct
{
    uint32_t BaudRate;   /* This member configures the UART communication baud rate.
                                  The baud rate is computed using the following formula:
                                   - IntegerDivider = ((PCLKx) / (16 * (UART_InitStruct->BaudRate)))
                                   - FractionalDivider = ((IntegerDivider - ((u32) IntegerDivider)) * 16) + 0.5 */

    uint32_t WordLength; /* Specifies the number of data bits transmitted or received in a frame. */

    uint32_t StopBits;   /* Specifies the number of stop bits transmitted. */

    uint32_t Parity;     /* Specifies the parity mode. */

    uint32_t Mode;       /* Specifies wether the Receive or Transmit mode is enabled or disabled. */
    
    uint32_t OverSampling;        /* Specifies whether UART oversampling mode is 16 or 8. */
} UART_InitType;


/*** UART Structure Definition End ***/

/*** UART Macro Definition Start ***/

#define UART_REG_BIT_MASK        (uint32_t)0x00000000U

/* UART CTRL1 Mask */
#define UART_CTRL1_CLR_MASK           ((uint32_t)(~(UART_CTRL1_RXEN \
                                              |UART_CTRL1_TXEN \
                                              |UART_CTRL1_PSEL \
                                              |UART_CTRL1_PCEN \
                                              |UART_8OVER     \
                                              |UART_CTRL1_WL))) 

/** Configures the word length of UART **/
#define UART_WL_8B               ((uint32_t)UART_REG_BIT_MASK)  /* 8 bits */
#define UART_WL_9B               ((uint32_t)UART_CTRL1_WL)      /* 9 bits */

/** UART STOP bits **/
#define CTRL2_STPB_CLR_MASK      ((uint32_t)(~UART_CTRL2_STPB)) /* UART CTRL2 STOP Bits Mask */
#define UART_STPB_1              ((uint32_t)UART_REG_BIT_MASK)   /* 1 STOP bit */
#define UART_STPB_0_5            ((uint32_t)UART_CTRL2_STPB_0)   /* 0.5 STOP bit */
#define UART_STPB_2              ((uint32_t)UART_CTRL2_STPB_1)   /* 2 STOP bits */
#define UART_STPB_1_5            ((uint32_t)(UART_CTRL2_STPB_1|UART_CTRL2_STPB_0))   /* 1.5 STOP bits */

/** UART parity selection **/
#define UART_PE_NO               (UART_REG_BIT_MASK) /* UART parity disable */
#define UART_PE_EVEN             ((uint32_t)UART_CTRL1_PCEN)   /* Even parity */
#define UART_PE_ODD              ((uint32_t)(UART_CTRL1_PCEN | UART_CTRL1_PSEL))   /* Odd parity */

/** UART is configured as RX or TX **/
#define UART_MODE_RX             ((uint32_t)UART_CTRL1_RXEN)  /* Transmitter enable */
#define UART_MODE_TX             ((uint32_t)UART_CTRL1_TXEN)  /* Receiver enable */

/** UART oversampling configure **/
#define UART_8OVER              ((uint32_t)UART_CTRL1_OSPM)
#define UART_16OVER             ((uint32_t)UART_REG_BIT_MASK)

/** UART_Clock_Polarity **/
#define UART_CLKPOL_LOW          ((uint32_t)UART_REG_BIT_MASK)
#define UART_CLKPOL_HIGH         ((uint32_t)UART_CTRL2_CLKPOL)

/** UART_Clock_Phase **/
#define UART_CLKPHA_1EDGE        ((uint32_t)UART_REG_BIT_MASK)
#define UART_CLKPHA_2EDGE        ((uint32_t)UART_CTRL2_CLKPHA)

/** UART_Last_Bit **/
#define UART_CLKLB_DISABLE       ((uint32_t)UART_REG_BIT_MASK)
#define UART_CLKLB_ENABLE        ((uint32_t)UART_CTRL2_LBCLK)


#define CTRL1_UEN_SET             ((uint32_t)UART_CTRL1_UEN)    /* UART Enable Mask */
#define CTRL1_UEN_RESET           ((uint32_t)(~UART_CTRL1_UEN)) /* UART Disable Mask */

#define CTRL1_SWAP_ENABLE        ((uint32_t)UART_CTRL1_SWAP)    /* UART Idle frame Enable */
#define CTRL1_SWAP_DISABLE       ((uint32_t)(~UART_CTRL1_SWAP)) /* UART Idle frame Disable */

#define CTRL1_DEP_ENABLE         ((uint32_t)UART_CTRL1_DEP)    /* UART DE signal active low  */
#define CTRL1_DEP_DISABLE        ((uint32_t)(~UART_CTRL1_DEP)) /* UART DE signal active high */

/* UART Driver enable mode  */
#define CTRL1_DEM_ENABLE         ((uint32_t)UART_CTRL1_DEM)  
#define CTRL1_DEM_DISABLE        ((uint32_t)(~UART_CTRL1_DEM))

/* Receiver timeout enable  */
#define CTRL2_RTO_ENABLE         ((uint32_t)UART_CTRL2_RTOEN)  
#define CTRL2_RTO_DISABLE        ((uint32_t)(~UART_CTRL2_RTOEN))


/** UART_Interrupt_definition **/
#define UART_INT_MASK              ((uint32_t)0x0FFFFFFFU) /* UART Interrupt Mask */
#define UART_CTRL1_INTMASK         ((uint32_t)0x10000000U)
#define UART_CTRL2_INTMASK         ((uint32_t)0x20000000U)
#define UART_CTRL3_INTMASK         ((uint32_t)0x40000000U)

#define UART_INT_PEF               ((uint32_t)(UART_CTRL1_INTMASK | UART_CTRL1_PEIEN))
#define UART_INT_TXC               ((uint32_t)(UART_CTRL1_INTMASK | UART_CTRL1_TXCIEN))
#define UART_INT_TXDE              ((uint32_t)(UART_CTRL1_INTMASK | UART_CTRL1_TXDEIEN))
#define UART_INT_RXDNE             ((uint32_t)(UART_CTRL1_INTMASK | UART_CTRL1_RXDNEIEN))
#define UART_INT_IDLEF             ((uint32_t)(UART_CTRL1_INTMASK | UART_CTRL1_IDLEIEN))
#define UART_INT_RTOE              ((uint32_t)(UART_CTRL2_INTMASK | UART_CTRL2_RTOITE))
#define UART_INT_LINBD             ((uint32_t)(UART_CTRL2_INTMASK | UART_CTRL2_LINBDIEN))
#define UART_INT_ERRF              ((uint32_t)(UART_CTRL3_INTMASK | UART_CTRL3_ERRIEN))

#define CTRL2_ADDR_MASK             ((uint32_t)(~UART_CTRL2_ADDR)) 

/** UART_DMA_Requests **/
#define UART_DMAREQ_TX             ((uint32_t)UART_CTRL3_DMATXEN)
#define UART_DMAREQ_RX             ((uint32_t)UART_CTRL3_DMARXEN)

/** UART_WakeUp_methods **/
#define CTRL1_WUM_MASK              ((uint32_t)(~UART_CTRL1_WUM)) 
#define UART_WUM_IDLELINE          ((uint32_t)UART_REG_BIT_MASK)
#define UART_WUM_ADDRMASK          ((uint32_t)UART_CTRL1_WUM)

/* UART mute mode */
#define CTRL1_RCVWU_SET             ((uint32_t)UART_CTRL1_RCVWU) 
#define CTRL1_RCVWU_RESET           ((uint32_t)(~UART_CTRL1_RCVWU))

/** UART_LIN_Break_Detection_Length **/
#define CTRL2_LINBDL_MASK           ((uint32_t)(~UART_CTRL2_LINBDL)) 
#define UART_LINBDL_10B            ((uint32_t)UART_REG_BIT_MASK)
#define UART_LINBDL_11B            ((uint32_t)UART_CTRL2_LINBDL)

/* UART LIN */
#define CTRL2_LINMEN_SET            ((uint32_t)UART_CTRL2_LINMEN) 
#define CTRL2_LINMEN_RESET          ((uint32_t)(~UART_CTRL2_LINMEN))

/* UART Break Character send Mask */
#define CTRL1_SDBRK_SET             ((uint32_t)UART_CTRL1_SDBRK) 

/* Guard Time Register */
#define GTP_LSB_MASK                ((uint32_t)(~UART_GTP_GTV)) 
#define GTP_MSB_MASK                ((uint32_t)(~UART_GTP_PSCV)) 

/* UART SCMEN Mask */
#define CTRL3_SCMEN_SET             ((uint32_t)UART_CTRL3_SCMEN) 
#define CTRL3_SCMEN_RESET           ((uint32_t)(~UART_CTRL3_SCMEN)) 

/* UART SC NACK Mask */
#define CTRL3_SCNACK_SET            ((uint32_t)UART_CTRL3_SCNACK) 
#define CTRL3_SCNACK_RESET          ((uint32_t)(~UART_CTRL3_SCNACK))

/* UART Half-Duplex Mask */
#define CTRL3_HDMEN_SET             ((uint32_t)UART_CTRL3_HDMEN) 
#define CTRL3_HDMEN_RESET           ((uint32_t)(~UART_CTRL3_HDMEN))

/** UART_IrDA_Low_Power **/
#define CTRL3_IRDALP_MASK           ((uint32_t)(~UART_CTRL3_IRDALP)) 
#define UART_IRDAMODE_LOWPPWER     ((uint32_t)UART_CTRL3_IRDALP)
#define UART_IRDAMODE_NORMAL       ((uint32_t)UART_REG_BIT_MASK)

 /* UART IrDA Mask */
#define CTRL3_IRDAMEN_SET           ((uint32_t)UART_CTRL3_IRDAMEN)
#define CTRL3_IRDAMEN_RESET         ((uint32_t)(~UART_CTRL3_IRDAMEN)) 

/** UART_Flags **/
#define UART_FLAG_RTO              ((uint32_t)UART_STS_RTOF)
#define UART_FLAG_FEF              ((uint32_t)UART_STS_FEF)
#define UART_FLAG_NEF              ((uint32_t)UART_STS_NEF)
#define UART_FLAG_OREF             ((uint32_t)UART_STS_OREF)
#define UART_FLAG_PEF              ((uint32_t)UART_STS_PEF)
#define UART_FLAG_LINBD            ((uint32_t)UART_STS_LINBDF)
#define UART_FLAG_RXDNE            ((uint32_t)UART_STS_RXDNE)
#define UART_FLAG_TXC              ((uint32_t)UART_STS_TXC)
#define UART_FLAG_TXDE             ((uint32_t)UART_STS_TXDE)
#define UART_FLAG_IDLEF            ((uint32_t)UART_STS_IDLEF)

/** UART_WKUP **/
#define UART_WAKEUP_DATACLR              ((uint32_t)UART_WAKEUP_DATCLR_MASK)
#define UART_WAKEUP_DATANCLR             ((uint32_t)UART_REG_BIT_MASK)

#define UART_WAKEUP_ENABLE              ((uint32_t)UART_WAKEUP_EN_MASK)
#define UART_WAKEUP_DISABLE             ((uint32_t)UART_REG_BIT_MASK)

void UART_DeInit(UART_Module* UARTx);
void UART_Init(UART_Module* UARTx, UART_InitType* UART_InitStruct);
void UART_StructInit(UART_InitType* UART_InitStruct);
void UART_Enable(UART_Module* UARTx, FunctionalState Cmd);
void UART_ConfigInt(UART_Module* UARTx, uint32_t UART_INT, FunctionalState Cmd);
void UART_EnableDMA(UART_Module* UARTx, uint32_t UART_DMAReq, FunctionalState Cmd);
void UART_SetAddr(UART_Module* UARTx, uint8_t UART_Addr);
void UART_ConfigWakeUpMode(UART_Module* UARTx, uint32_t UART_WakeUpMode);
void UART_EnableRcvWakeUp(UART_Module* UARTx, FunctionalState Cmd);
void UART_ConfigLINBreakDetectLength(UART_Module* UARTx, uint32_t UART_LINBreakDetectLength);
void UART_EnableLIN(UART_Module* UARTx, FunctionalState Cmd);
void UART_SendData(UART_Module* UARTx, uint32_t Data);
uint32_t UART_ReceiveData(UART_Module* UARTx);
void UART_SendBreak(UART_Module* UARTx);
void UART_SetPrescaler(UART_Module* UARTx, uint8_t UART_Prescaler);
void UART_EnableHalfDuplex(UART_Module* UARTx, FunctionalState Cmd);
void UART_ConfigIrDAMode(UART_Module* UARTx, uint32_t UART_IrDAMode);
void UART_EnableIrDA(UART_Module* UARTx, FunctionalState Cmd);
FlagStatus UART_GetFlagStatus(UART_Module* UARTx, uint32_t UART_FLAG);
void UART_ClrFlag(UART_Module* UARTx, uint32_t UART_FLAG);
void UART_ClrRTOFlag(UART_Module* UARTx);
INTStatus UART_GetIntStatus(UART_Module* UARTx, uint32_t UART_INT);
void UART_PinSwapSet(UART_Module* UARTx,FunctionalState Cmd);
void UART_CfgDriverAssertTime(UART_Module* UARTx,uint32_t Time);
void UART_CfgDriverdeassertTime(UART_Module* UARTx,uint32_t Time);
void UART_DriverPolaritySet(UART_Module* UARTx,FunctionalState Cmd);
void UART_DriverModeSet(UART_Module* UARTx,FunctionalState Cmd);
void UART_FEFDiscardSet(UART_Module* UARTx,FunctionalState Cmd);
void UART_NEFDiscardSet(UART_Module* UARTx,FunctionalState Cmd);
void UART_PEFDiscardSet(UART_Module* UARTx,FunctionalState Cmd);
void UART_RTOSet(UART_Module* UARTx,FunctionalState Cmd);
void UART_CfgRTOWidth(UART_Module* UARTx,uint32_t Width);
void UART_CfgWakeupMode(UART_Module* UARTx,uint32_t WakeupEn,uint32_t WakeupMode);


#ifdef __cplusplus
}
#endif

#endif /* __N32G033_UART_H__ */

