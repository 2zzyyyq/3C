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
*\*\file n32g033_uart.c
*\*\author Nsing
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/

#include "n32g033_uart.h"
#include "n32g033_rcc.h"

/** N32G033_StdPeriph_Driver **/

/**
*\*\name    UART_DeInit
*\*\fun     Deinitializes the UARTx peripheral registers to their default reset values.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\return  none
**/
void UART_DeInit(UART_Module* UARTx)
{
    if (UARTx == UART1)
    {
        RCC_EnableAPBPeriphReset(RCC_APB_PERIPH_UART1);
    }
    else if (UARTx == UART2)
    {
        RCC_EnableAPBPeriphReset(RCC_APB_PERIPH_UART2);
    }
    else if (UARTx == UART3)
    {
        RCC_EnableAPBPeriphReset(RCC_APB_PERIPH_UART3);
    }
    else
    {
        /* nothing */
    }
}


/**
*\*\name    UART_Init
*\*\fun     Initializes the UARTx peripheral according to UART_InitStruct.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param   UART_InitStruct (The input parameters must be the following values):
*\*\          - buad_rate :
*\*\            - (((buad_rate) > 0) && ((buad_rate) < 0x003D0900))
*\*\          - WordLength
*\*\            - UART_WL_8B
*\*\            - UART_WL_9B
*\*\          - StopBits
*\*\            - UART_STPB_1
*\*\            - UART_STPB_0_5
*\*\            - UART_STPB_2
*\*\            - UART_STPB_1_5
*\*\          - Parity
*\*\            - UART_PE_NO
*\*\            - UART_PE_EVEN
*\*\            - UART_PE_ODD
*\*\          - Mode 
*\*\            - UART_MODE_RX
*\*\            - UART_MODE_TX
*\*\          - OverSampling 
*\*\            - UART_8OVER
*\*\            - UART_16OVER
*\*\return  none
**/
void UART_Init(UART_Module* UARTx, UART_InitType* UART_InitStruct)
{
    uint32_t tmpregister;
    uint32_t apbclock;
    uint32_t integerdivider;
    uint32_t fractionaldivider;
    RCC_ClocksType RCC_ClocksStatus;

    /* UART CTRL2 Configuration */
    tmpregister = UARTx->CTRL2;
    /* Clear STOP[1:0] bits */
    tmpregister &= CTRL2_STPB_CLR_MASK;
    /* Configure the UART Stop Bits */
    /* Set STOP[1:0] bits according to StopBits value */
    tmpregister |= (uint32_t)UART_InitStruct->StopBits;
    /* Write to UART CTRL2 */
    UARTx->CTRL2 = (uint32_t)tmpregister;

    
    /* UART CTRL1 Configuration */
    tmpregister = UARTx->CTRL1;
    /* Clear RXEN, TXEN, PSEL, PCEN, WL and OSPM bits */
    tmpregister &= UART_CTRL1_CLR_MASK;
    /* Configure the UART Word Length, Parity, OverSampling and mode */
    /* Set the WL bits according to WordLength value */
    /* Set PSEL and PCEN bits according to Parity value */
    /* Set RXEN and TXEN bits according to Mode value */
    /* Set OSPM bits according to OverSampling value */
    tmpregister |= (uint32_t)UART_InitStruct->WordLength | UART_InitStruct->Parity \
                | UART_InitStruct->OverSampling | UART_InitStruct->Mode;
    /* Write to UART CTRL1 */
    UARTx->CTRL1 = (uint32_t)tmpregister;

    /* UART PBC Configuration */
    /* Configure the UART Baud Rate */
    RCC_GetClocksFreqValue(&RCC_ClocksStatus);

    apbclock = RCC_ClocksStatus.PclkFreq;

    /* Determine the integer part */
    if((UARTx->CTRL1 & UART_8OVER) == 0U)
    {
        /* Integer part computing in case Oversampling mode is 16 Samples */
        integerdivider = ((25U * (apbclock / 4U)) / (UART_InitStruct->BaudRate));
    }
    else
    {
        /* Integer part computing in case Oversampling mode is 8 Samples */
        integerdivider = ((25U * (apbclock / 2U)) / (UART_InitStruct->BaudRate));
    }
    tmpregister = (integerdivider / 100U) << 4U;

    /* Determine the fractional part */
    fractionaldivider = integerdivider - (100U * (tmpregister >> 4U));

    /*Determine whether the fractional part needs to carried*/
    if((UARTx->CTRL1 & UART_8OVER) != 0U)
    {
        /* Oversampling mode is 8 Samples */
        fractionaldivider = ((((fractionaldivider * 8U) + 50U) / 100U)) & ((uint8_t)0x0FU);
        if((fractionaldivider >> 3U) == 1U)
        {
            tmpregister = tmpregister+0x10U; 
        }
        else
        {
            tmpregister |= fractionaldivider;
        }
    }
    else
    {
        /* Oversampling mode is 16 Samples */
        tmpregister |= ((((fractionaldivider * 16U) + 50U) / 100U)) & ((uint8_t)0x1FU);
    }

    /* Write to UART PBC */
    UARTx->BRCF = (uint32_t)tmpregister;
}

/**
*\*\name    UART_StructInit.
*\*\fun     Fills each UART_InitStruct member with its default value.
*\*\param   UART_InitStruct (The input parameters must be the following values):
*\*\          - BaudRate
*\*\          - WordLength
*\*\          - StopBits
*\*\          - Parity
*\*\          - Mode
*\*\          - OverSampling
*\*\return  none
**/
void UART_StructInit(UART_InitType* UART_InitStruct)
{
    /* UART_InitStruct members default value */
    UART_InitStruct->BaudRate            = 9600;
    UART_InitStruct->WordLength          = UART_WL_8B;
    UART_InitStruct->StopBits            = UART_STPB_1;
    UART_InitStruct->Parity              = UART_PE_NO;
    UART_InitStruct->Mode                = UART_MODE_RX | UART_MODE_TX;
    UART_InitStruct->OverSampling        = UART_16OVER;
}


/**
*\*\name    UART_Enable
*\*\fun     Enables or disables the specified UART peripheral.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param   Cmd (The input parameters must be the following values):
*\*\          - ENABLE
*\*\          - DISABLE
*\*\return  none
**/
void UART_Enable(UART_Module* UARTx, FunctionalState Cmd)
{
   if (Cmd != DISABLE)
    {
        /* Enable the selected UART by setting the UE bit in the CTRL1 register */
        UARTx->CTRL1 |= CTRL1_UEN_SET;
    }
    else
    {
        /* Disable the selected UART by clearing the UE bit in the CTRL1 register */
        UARTx->CTRL1 &= CTRL1_UEN_RESET;
    }
}


/**
*\*\name    UART_ConfigInt
*\*\fun     Enables or disables the specified UART interrupts.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param   UART_INT (The input parameters must be the following values):
*\*\          - UART_INT_PEF   Parity Error interrupt
*\*\          - UART_INT_TXC   Transmission complete interrupt
*\*\          - UART_INT_TXDE  Transmit Data Register empty interrupt
*\*\          - UART_INT_RXDNE Receive Data register not empty interrupt
*\*\          - UART_INT_IDLEF Idle line detection interrupt
*\*\          - UART_INT_RTOE  Receiver timeout interrupt
*\*\          - UART_INT_LINBD LIN Break detection interrupt
*\*\          - UART_INT_ERRF  Error interrupt(Frame error, noise error, overrun error)
*\*\param   Cmd (The input parameters must be the following values):
*\*\          - ENABLE
*\*\          - DISABLE
*\*\return  none
**/
void UART_ConfigInt(UART_Module* UARTx, uint32_t UART_INT, FunctionalState Cmd)
{
    uint32_t itmask;
    uint32_t usartxbase;

    usartxbase = (uint32_t)UARTx;

    /* Get the interrupt position */
    itmask = UART_INT & UART_INT_MASK;

    if((UART_INT & UART_CTRL1_INTMASK) != (uint32_t)0x00U) /* The IT is in CTRL1 register */
    {
        usartxbase += 0x00U;
    }
    else if((UART_INT & UART_CTRL2_INTMASK) != (uint32_t)0x00U) /* The IT is in CTRL2 register */
    {
        usartxbase += 0x04U;
    }
    else/* The IT is in CTRL3 register */
    {
        usartxbase += 0x08U;
    }
    
    if (Cmd != DISABLE)
    {
        *(__IO uint32_t*)usartxbase |= itmask;
    }
    else
    {
        *(__IO uint32_t*)usartxbase &= ~itmask;
    }
}


/**
*\*\name    UART_EnableDMA
*\*\fun     Enables or disables the UART's DMA interface.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param   UART_DMAReq (The input parameters must be the following values):
*\*\          - UART_DMAREQ_TX UART DMA transmit request
*\*\          - UART_DMAREQ_RX UART DMA receive request
*\*\param   Cmd (The input parameters must be the following values):
*\*\          - ENABLE
*\*\          - DISABLE
*\*\return  none
**/
void UART_EnableDMA(UART_Module* UARTx, uint32_t UART_DMAReq, FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        /* Enable the DMA transfer for selected requests by setting the DMAT and/or
           DADDR bits in the UART CTRL3 register */
        UARTx->CTRL3 |= UART_DMAReq;
    }
    else
    {
        /* Disable the DMA transfer for selected requests by clearing the DMAT and/or
           DADDR bits in the UART CTRL3 register */
        UARTx->CTRL3 &= (uint32_t)~UART_DMAReq;
    }
}

/**
*\*\name    UART_SetAddr
*\*\fun     Sets the address of the UART node.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param   UART_Addr (The input parameters must be the following values):
*\*\          - (((UART_Addr)>=0x00)&&((UART_Addr)<0x10))
*\*\return  none
**/
void UART_SetAddr(UART_Module* UARTx, uint8_t UART_Addr)
{
    /* Clear the UART address */
    UARTx->CTRL2 &= CTRL2_ADDR_MASK;
    /* Set the UART address node */
    UARTx->CTRL2 |= UART_Addr;
}


/**
*\*\name    UART_ConfigWakeUpMode
*\*\fun     Selects the UART WakeUp method.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param   UART_WakeUpMode (The input parameters must be the following values):
*\*\          - UART_WUM_IDLELINE WakeUp by an idle line detection
*\*\          - UART_WUM_ADDRMASK WakeUp by an address mark
*\*\return  none
**/
void UART_ConfigWakeUpMode(UART_Module* UARTx, uint32_t UART_WakeUpMode)
{
    UARTx->CTRL1 &= CTRL1_WUM_MASK;
    UARTx->CTRL1 |= UART_WakeUpMode;
}


/**
*\*\name    UART_EnableRcvWakeUp
*\*\fun     Determines if the UART is in mute mode or not.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param   Cmd (The input parameters must be the following values):
*\*\          - ENABLE
*\*\          - DISABLE
*\*\return  none
**/
void UART_EnableRcvWakeUp(UART_Module* UARTx, FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        /* Enable the UART mute mode  by setting the RWU bit in the CTRL1 register */
        UARTx->CTRL1 |= CTRL1_RCVWU_SET;
    }
    else
    {
        /* Disable the UART mute mode by clearing the RWU bit in the CTRL1 register */
        UARTx->CTRL1 &= CTRL1_RCVWU_RESET;
    }
}


/**
*\*\name    UART_ConfigLINBreakDetectLength
*\*\fun     Sets the UART LIN Break detection length.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param   UART_LINBreakDetectLength (The input parameters must be the following values):
*\*\          - UART_LINBDL_10B 10-bit break detection
*\*\          - UART_LINBDL_11B 11-bit break detection
*\*\return  none
**/
void UART_ConfigLINBreakDetectLength(UART_Module* UARTx, uint32_t UART_LINBreakDetectLength)
{
    UARTx->CTRL2 &= CTRL2_LINBDL_MASK;
    UARTx->CTRL2 |= UART_LINBreakDetectLength;
}


/**
*\*\name    UART_EnableLIN
*\*\fun     Enables or disables the UART's LIN mode.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param   Cmd (The input parameters must be the following values):
*\*\          - ENABLE
*\*\          - DISABLE
*\*\return  none
**/
void UART_EnableLIN(UART_Module* UARTx, FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        /* Enable the LIN mode by setting the LINEN bit in the CTRL2 register */
        UARTx->CTRL2 |= CTRL2_LINMEN_SET;
    }
    else
    {
        /* Disable the LIN mode by clearing the LINEN bit in the CTRL2 register */
        UARTx->CTRL2 &= CTRL2_LINMEN_RESET;
    }
}

/**
*\*\name    UART_SendData
*\*\fun     Transmits single data through the UARTx peripheral.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param   Data :
*\*\          - the data to transmit
*\*\return  none
**/
void UART_SendData(UART_Module* UARTx, uint32_t Data)
{
    /* Transmit Data */
    UARTx->DAT = (Data & 0x000001FFU);
}

/**
*\*\name    UART_ReceiveData
*\*\fun     Returns the most recent received data by the UARTx peripheral.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\return  none
**/
uint32_t UART_ReceiveData(UART_Module* UARTx)
{
    /* Receive Data */
    return (uint32_t)(UARTx->DAT & (uint32_t)0x01FF);
}

/**
*\*\name    UART_SendBreak
*\*\fun     Transmits break characters.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\return  none
**/
void UART_SendBreak(UART_Module* UARTx)
{
    /* Send break characters */
    UARTx->CTRL1 |= CTRL1_SDBRK_SET;
}


/**
*\*\name    UART_SetPrescaler
*\*\fun     Sets the system clock prescaler.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param   UART_Prescaler:
*\*\          - specifies the prescaler clock
*\*\return  none
**/
void UART_SetPrescaler(UART_Module* UARTx, uint8_t UART_Prescaler)
{
    /* Clear the UART prescaler */
    UARTx->GTP &= GTP_MSB_MASK;
    /* Set the UART prescaler */
    UARTx->GTP |= UART_Prescaler;
}


/**
*\*\name    UART_EnableHalfDuplex
*\*\fun     Enables or disables the UART's Half Duplex communication.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param   Cmd (The input parameters must be the following values):
*\*\          - ENABLE
*\*\          - DISABLE
*\*\return  none
**/
void UART_EnableHalfDuplex(UART_Module* UARTx, FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        /* Enable the Half-Duplex mode by setting the HDSEL bit in the CTRL3 register */
        UARTx->CTRL3 |= CTRL3_HDMEN_SET;
    }
    else
    {
        /* Disable the Half-Duplex mode by clearing the HDSEL bit in the CTRL3 register */
        UARTx->CTRL3 &= CTRL3_HDMEN_RESET;
    }
}


/**
*\*\name    UART_ConfigIrDAMode
*\*\fun     Configures the UART's IrDA interface.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param   UART_IrDAMode (The input parameters must be the following values):
*\*\          - UART_IRDAMODE_LOWPPWER
*\*\          - UART_IRDAMODE_NORMAL
*\*\return  none
**/
void UART_ConfigIrDAMode(UART_Module* UARTx, uint32_t UART_IrDAMode)
{
    UARTx->CTRL3 &= CTRL3_IRDALP_MASK;
    UARTx->CTRL3 |= UART_IrDAMode;
}


/**
*\*\name    UART_EnableIrDA
*\*\fun     Enables or disables the UART's IrDA interface.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param   Cmd (The input parameters must be the following values):
*\*\          - ENABLE
*\*\          - DISABLE
*\*\return  none
**/
void UART_EnableIrDA(UART_Module* UARTx, FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        /* Enable the IrDA mode by setting the IREN bit in the CTRL3 register */
        UARTx->CTRL3 |= CTRL3_IRDAMEN_SET;
    }
    else
    {
        /* Disable the IrDA mode by clearing the IREN bit in the CTRL3 register */
        UARTx->CTRL3 &= CTRL3_IRDAMEN_RESET;
    }
}


/**
*\*\name    UART_GetFlagStatus
*\*\fun     Checks whether the specified UART flag is set or not.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param   UART_FLAG (The input   parameters must be the following values):
*\*\          - UART_FLAG_RTO      recevier timeout Flag
*\*\          - UART_FLAG_FEF      Framing error Flag
*\*\          - UART_FLAG_NEF      Noise error flag Flag
*\*\          - UART_FLAG_OREF     Overrun error
*\*\          - UART_FLAG_PEF      Parity error
*\*\          - UART_FLAG_LINBD    LIN break detection flag
*\*\          - UART_FLAG_RXDNE    Receive data register not empty flag
*\*\          - UART_FLAG_TXC      Transmission Complete flag
*\*\          - UART_FLAG_TXDE     Transmit data register empty flag
*\*\          - UART_FLAG_IDLEF    Idle Line detection flag
*\*\return  UART_FLAG
*\*\          - SET   
*\*\          - RESET 
**/
FlagStatus UART_GetFlagStatus(UART_Module* UARTx, uint32_t UART_FLAG)
{
    FlagStatus bitstatus;

    if ((UARTx->STS & UART_FLAG) != (uint32_t)RESET)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
    return bitstatus;
}

/**
*\*\name    UART_ClrFlag
*\*\fun     Clears the UARTx's pending flags.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param   UART_FLAG (The input   parameters must be the following values):
*\*\          - UART_FLAG_LINBD    LIN break detection flag
*\*\          - UART_FLAG_RXDNE    Receive data register not empty flag
*\*\          - UART_FLAG_TXC      Transmission Complete flag
*\*\return  none 
*\*\note
*\*\          - PE (Parity error), FE (Framing error), NE (Noise error), ORE (OverRun
*\*\            error) and IDLE (Idle line detected) flags are cleared by software
*\*\            sequence: a read operation to UART_STS register (UART_GetFlagStatus())
*\*\            followed by a read operation to UART_DAT register (UART_ReceiveData()).
*\*\          - RXNE flag can be also cleared by a read to the UART_DAT register
*\*\            (UART_ReceiveData()).
*\*\          - TC flag can be also cleared by software sequence: a read operation to
*\*\            UART_SR register (UART_GetFlagStatus()) followed by a write operation
*\*\            to UART_DAT register (UART_SendData()).
*\*\          - TXE flag is cleared only by a write to the UART_DAT register
*\*\            (UART_SendData()).
*\*\          - RTO flag is cleared only by a write 1 to the UART_CTRL2.RTOCF bit.
*\*\            (UART_ClrRTOFlag()).
**/
void UART_ClrFlag(UART_Module* UARTx, uint32_t UART_FLAG)
{
    UARTx->STS = (~UART_FLAG);
}


/**
*\*\name    UART_ClrRTOFlag
*\*\fun     Clears the UARTx's RTO pending flag.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\return  none
**/
void UART_ClrRTOFlag(UART_Module* UARTx)
{
    uint32_t time_out;
    UARTx->CTRL2 |= UART_FLAG_RTO;
    time_out = 0xFFFFU;
    while(UART_GetFlagStatus(UARTx,UART_FLAG_RTO) == SET)
    {
         time_out--;
         if(time_out <= 1U)
         {
             break;
         }
    }
    UARTx->CTRL2 &= (~UART_FLAG_RTO);
}

/**
*\*\name    UART_GetIntStatus
*\*\fun     Checks whether the specified UART interrupt has set or not.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param   UART_INT (The input parameters must be the following values):
*\*\          - UART_INT_PEF   Parity Error interrupt
*\*\          - UART_INT_TXC   Transmission complete interrupt
*\*\          - UART_INT_TXDE  Transmit Data Register empty interrupt
*\*\          - UART_INT_RXDNE Receive Data register not empty interrupt
*\*\          - UART_INT_IDLEF Idle line detection interrupt
*\*\          - UART_INT_RTOE  Receiver timeout interrupt
*\*\          - UART_INT_LINBD LIN Break detection interrupt
*\*\          - UART_INT_ERRF  Error interrupt(Frame error, noise error, overrun error)
*\*\return  bitstatus
*\*\          - SET   
*\*\          - RESET 
**/
INTStatus UART_GetIntStatus(UART_Module* UARTx, uint32_t UART_INT)
{
    uint32_t itmask;
    INTStatus bitstatus;

    /* Get the interrupt position */
    itmask = UART_INT & UART_INT_MASK;

    if ((UART_INT & UART_CTRL1_INTMASK) != 0x00U) /* The IT  is in CTRL1 register */
    {
        itmask &= UARTx->CTRL1;
    }
    else if ((UART_INT & UART_CTRL2_INTMASK) != 0x00U) /* The IT  is in CTRL2 register */
    {
        itmask &= UARTx->CTRL2;
    }
    else /* The IT  is in CTRL3 register */
    {
        itmask &= UARTx->CTRL3;
    }

    if (itmask != (uint32_t)RESET)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }

    return bitstatus;
}

/**
*\*\name    UART_PinSwapSet
*\*\fun     Swap TX/RX pins enable or disable.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param  Cmd:(The input parameters must be the following values)
*\*\          - ENABLE
*\*\          - DISABLE 
*\*\return  none
**/
void UART_PinSwapSet(UART_Module* UARTx,FunctionalState Cmd)
{
    if(Cmd == ENABLE)
    {
        UARTx->CTRL1 |= CTRL1_SWAP_ENABLE;
    }
    else
    {
        UARTx->CTRL1 &= CTRL1_SWAP_DISABLE;
    }
}


/**
*\*\name    UART_CfgDriverAssertTime
*\*\fun     Set Driver Enable assertion time.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param  Time:(The input parameters must be the following values)
*\*\          - 0x01 ~ 0x1F
*\*\return  none
**/
void UART_CfgDriverAssertTime(UART_Module* UARTx,uint32_t Time)
{
    UARTx->CTRL1 &= (~UART_CTRL1_DEAT_MASK);
    UARTx->CTRL1 |= (Time << 21U);
}


/**
*\*\name    UART_CfgDriverdeassertTime
*\*\fun     Set Driver Enable deassertion time.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param  Time:(The input parameters must be the following values)
*\*\          - 0x01 ~ 0x1F
*\*\return  none
**/
void UART_CfgDriverdeassertTime(UART_Module* UARTx,uint32_t Time)
{
    UARTx->CTRL1 &= (~UART_CTRL1_DEDT_MASK);
    UARTx->CTRL1 |= (Time << 16U);
}


/**
*\*\name    UART_DriverPolaritySet
*\*\fun     Driver enable polarity selection.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param  Cmd:(The input parameters must be the following values)
*\*\          - ENABLE
*\*\          - DISABLE 
*\*\return  none
**/
void UART_DriverPolaritySet(UART_Module* UARTx,FunctionalState Cmd)
{
    if(Cmd == ENABLE)
    {
        UARTx->CTRL1 |= CTRL1_DEP_ENABLE;
    }
    else
    {
        UARTx->CTRL1 &= CTRL1_DEP_DISABLE;
    }
}


/**
*\*\name    UART_DriverModeSet
*\*\fun     Driver enable mode selection.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param  Cmd:(The input parameters must be the following values)
*\*\          - ENABLE
*\*\          - DISABLE 
*\*\return  none
**/
void UART_DriverModeSet(UART_Module* UARTx,FunctionalState Cmd)
{
    if(Cmd == ENABLE)
    {
        UARTx->CTRL1 |= CTRL1_DEM_ENABLE;
    }
    else
    {
        UARTx->CTRL1 &= CTRL1_DEM_DISABLE;
    }
}


/**
*\*\name    UART_RTOSet
*\*\fun     Receiver timeout enable or disable.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param  Cmd:(The input parameters must be the following values)
*\*\          - ENABLE
*\*\          - DISABLE 
*\*\return  none
**/
void UART_RTOSet(UART_Module* UARTx,FunctionalState Cmd)
{
    if(Cmd == ENABLE)
    {
        UARTx->CTRL2 |= CTRL2_RTO_ENABLE;
    }
    else
    {
        UARTx->CTRL2 &= CTRL2_RTO_DISABLE;
    }
}


/**
*\*\name    UART_CfgRTOWidth
*\*\fun     configure receive timeout width.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART1
*\*\          - UART2
*\*\          - UART3
*\*\param  Width:(The input parameters must be the following values)
*\*\          - 0x00000000 ~ 0x0FFFFFFF
*\*\return  none
**/
void UART_CfgRTOWidth(UART_Module* UARTx,uint32_t Width)
{
    UARTx->RTO = Width;
}


/**
*\*\name    UART_CfgWakeupMode
*\*\fun     configure wakeup mode.
*\*\param   UARTx (The input parameters must be the following values):
*\*\          - UART3
*\*\param  WakeupEn:(The input parameters must be the following values)
*\*\          - UART_WAKEUP_DATACLR
*\*\          - UART_WAKEUP_DATANCLR
*\*\param  WakeupMode:(The input parameters must be the following values)
*\*\          - UART_WAKEUP_ENABLE
*\*\          - UART_WAKEUP_DISABLE
*\*\return  none
**/
void UART_CfgWakeupMode(UART_Module* UARTx,uint32_t WakeupEn,uint32_t WakeupMode)
{
    UARTx->WKUP = (WakeupEn | WakeupMode);
}

