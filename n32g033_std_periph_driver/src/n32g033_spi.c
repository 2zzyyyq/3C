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
*\*\file      n32g033_spi.c
*\*\author    Nsing
*\*\version   v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved. 
**/

#include "n32g033_spi.h"
#include "n32g033_rcc.h"

/* SPI Driving Functions Declaration */

/**
*\*\name    SPI_DeInit.
*\*\fun     Reset the SPI registers.
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2
*\*\return  none
**/
void SPI_DeInit(SPI_Module* SPIx)
{
	if (SPIx == SPI1)
	{
		/* SPI1 Reset */
		RCC_EnableAPBPeriphReset(RCC_APB_PERIPH_SPI1);
	}
	else if (SPIx == SPI2)
	{
		/* SPI2 Reset */
		RCC_EnableAPBPeriphReset(RCC_APB_PERIPH_SPI2);
	}
    else
    {
      /* no process */
    }
}

/**
*\*\name    SPI_Init.
*\*\fun     Initializes the SPI according to SPI_InitStruct.
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1
*\*\          - SPI2
*\*\param   SPI_InitStruct (The input parameters must be the following values):
*\*\          - DataDirection
*\*\            - SPI_DIR_DOUBLELINE_FULLDUPLEX
*\*\            - SPI_DIR_DOUBLELINE_RONLY
*\*\            - SPI_DIR_SINGLELINE_RX
*\*\            - SPI_DIR_SINGLELINE_TX
*\*\          - SpiMode
*\*\            - SPI_MODE_MASTER
*\*\            - SPI_MODE_SLAVE
*\*\          - DataLen
*\*\            - SPI_DATA_SIZE_16BITS
*\*\            - SPI_DATA_SIZE_8BITS
*\*\          - CLKPOL
*\*\            - SPI_CLKPOL_LOW
*\*\            - SPI_CLKPOL_HIGH
*\*\          - CLKPHA
*\*\            - SPI_CLKPHA_FIRST_EDGE
*\*\            - SPI_CLKPHA_SECOND_EDGE
*\*\          - NSS
*\*\            - SPI_NSS_SOFT
*\*\            - SPI_NSS_HARD
*\*\          - BaudRatePres
*\*\            - SPI_BR_PRESCALER_2
*\*\            - SPI_BR_PRESCALER_4
*\*\            - SPI_BR_PRESCALER_8
*\*\            - SPI_BR_PRESCALER_16
*\*\            - SPI_BR_PRESCALER_32
*\*\            - SPI_BR_PRESCALER_64
*\*\            - SPI_BR_PRESCALER_128
*\*\            - SPI_BR_PRESCALER_256
*\*\          - FirstBit
*\*\            - SPI_FB_MSB
*\*\            - SPI_FB_LSB
*\*\          - CRCPoly
*\*\            - 0x01 ~ 0xffff
*\*\return  none
**/
void SPI_Init(SPI_Module* SPIx, SPI_InitType* SPI_InitStruct)
{
    uint32_t tmpregister;

    /* Get the SPIx CTRL1 value */
    tmpregister = SPIx->CTRL1;
    tmpregister &= SPI_CTRL1_CLR_MASK;
    tmpregister |= (uint32_t)(SPI_InitStruct->DataDirection | SPI_InitStruct->SpiMode
                             | SPI_InitStruct->DataLen | SPI_InitStruct->CLKPOL | SPI_InitStruct->CLKPHA
                             | SPI_InitStruct->NSS | SPI_InitStruct->BaudRatePres | SPI_InitStruct->FirstBit);
    /* Write to SPIx CTRL1 */
    SPIx->CTRL1 = tmpregister;

    /* Write to SPIx CRCPOLY */
    SPIx->CRCPOLY = SPI_InitStruct->CRCPoly;
}


/**
*\*\name    SPI_InitStruct.
*\*\fun     Fills each SPI_InitStruct member with its default value.
*\*\param   SPI_InitStruct (The input parameters must be the following values):
*\*\          - DataDirection
*\*\          - SpiMode
*\*\          - DataLen
*\*\          - CLKPOL
*\*\          - CLKPHA
*\*\          - NSS      
*\*\          - BaudRatePres     
*\*\          - FirstBit      
*\*\return  none
**/
void SPI_InitStruct(SPI_InitType* SPI_StructInit)
{
    /* Initialize the DataDirection member */
    SPI_StructInit->DataDirection = SPI_DIR_DOUBLELINE_FULLDUPLEX;
    /* initialize the Mode member */
    SPI_StructInit->SpiMode       = SPI_MODE_SLAVE;
    /* initialize the DataLen member */
    SPI_StructInit->DataLen       = SPI_DATA_SIZE_8BITS;
    /* Initialize the CLKPOL member */
    SPI_StructInit->CLKPOL        = SPI_CLKPOL_LOW;
    /* Initialize the CLKPHA member */
    SPI_StructInit->CLKPHA        = SPI_CLKPHA_FIRST_EDGE;
    /* Initialize the NSS member */
    SPI_StructInit->NSS           = SPI_NSS_HARD;
    /* Initialize the BaudRatePres member */
    SPI_StructInit->BaudRatePres  = SPI_BR_PRESCALER_2;
    /* Initialize the FirstBit member */
    SPI_StructInit->FirstBit      = SPI_FB_MSB;
    /* Initialize the CRCPoly member */
    SPI_StructInit->CRCPoly = 7;
}

/**
*\*\name    SPI_Enable.
*\*\fun     Enables or disables the specified SPI peripheral.
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2    
*\*\param   Cmd (The input parameters must be the following values):
*\*\          - ENABLE
*\*\          - DISABLE
*\*\return  none
**/
void SPI_Enable(SPI_Module* SPIx, FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        /* Enable the selected SPI peripheral */
        SPIx->CTRL2 |= CTRL1_SPIEN_ENABLE;
    }
    else
    {
        /* Disable the selected SPI peripheral */
        SPIx->CTRL2 &= CTRL1_SPIEN_DISABLE;
    }
}


/**
*\*\name    SPI_EnableInt.
*\*\fun     Enable/disable SPI interrupts.  
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2      
*\*\param   SPI_IT (The input parameters must be the following values):
*\*\          - SPI_INT_TE  
*\*\          - SPI_INT_RNE 
*\*\          - SPI_INT_ERR  
*\*\param   Cmd (The input parameters must be the following values):
*\*\          - ENABLE
*\*\          - DISABLE
*\*\return  none
**/
void SPI_EnableInt(SPI_Module* SPIx, uint32_t SPI_IT, FunctionalState Cmd)
{
    if(Cmd != DISABLE)
    {
        /* Set the SPI_CTRL2 TEINTEN/RNEINTEN/ERRINTEN bits to enable SPI interrupts */
        SPIx->CTRL2 |= SPI_IT;
    }
    else
    {
        /* Clear the SPI_CTRL2 TEINTEN/RNEINTEN/ERRINTEN bits to disable SPI interrupts */
        SPIx->CTRL2 &= (~SPI_IT);
    }
}


/**
*\*\name    SPI_EnableDma.
*\*\fun     Enable SPI DMA transfer.
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2  
*\*\param   SPI_DMAReq (The input parameters must be the following values):
*\*\          - SPI_DMA_TX   
*\*\          - SPI_DMA_RX 
*\*\param   Cmd (The input parameters must be the following values):
*\*\          - ENABLE
*\*\          - DISABLE
*\*\return  none
**/
void SPI_EnableDma(SPI_Module* SPIx, uint32_t SPI_DMAReq, FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        /* Enable the selected SPI DMA requests */
        SPIx->CTRL2 |= SPI_DMAReq;
    }
    else
    {
        /* Disable the selected SPI DMA requests */
        SPIx->CTRL2 &= (~SPI_DMAReq);
    }
}


/**
*\*\name    SPI_TransmitData.
*\*\fun     Transmits a Data through the SPI peripheral.  
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2      
*\*\param   Data: data to be transmitted 
*\*\return  none
**/
void SPI_TransmitData(SPI_Module* SPIx, uint16_t Data)
{
    /* Write in the SPI_DAT register the data to be sent */
    SPIx->DAT = (uint32_t)Data;
}

/**
*\*\name    SPI_ReceiveData.
*\*\fun     Get SPI data from SPI_DAT register.
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2      
*\*\return  The data in the SPI_DAT register
**/
uint16_t SPI_ReceiveData(SPI_Module* SPIx)
{
    /* Return the data in the SPI_DAT register */
    return ((uint16_t)SPIx->DAT);
}


/**
*\*\name    SPI_SetNssLevel.
*\*\fun     Configures internally by software the NSS pin for the selected SPI.
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2    
*\*\param   SPI_NSSInternalSoft (The input parameters must be the following values):
*\*\          - SPI_NSS_HIGH Set NSS pin internally
*\*\          - SPI_NSS_LOW  Reset NSS pin internally
*\*\return  none
**/
void SPI_SetNssLevel(SPI_Module* SPIx, uint32_t SPI_NSSInternalSoft)
{
    if (SPI_NSSInternalSoft != SPI_NSS_LOW)
    {
        /* Set NSS pin internally by software */
        SPIx->CTRL1 |= SPI_NSS_HIGH;
    }
    else
    {
        /* Reset NSS pin internally by software */
        SPIx->CTRL1 &= SPI_NSS_LOW;
    }
}

/**
*\*\name    SPI_SSOutputEnable.
*\*\fun     Configures internally by software the NSS pin for the selected SPI.
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2   
*\*\param   Cmd (The input parameters must be the following values):
*\*\          - ENABLE
*\*\          - DISABLE
*\*\return  none
**/
void SPI_SSOutputEnable(SPI_Module* SPIx, FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        /* Enable the selected SPI SS output */
        SPIx->CTRL1 |= CTRL1_SSOEN_ENABLE;
    }
    else
    {
        /* Disable the selected SPI SS output */
        SPIx->CTRL1 &= CTRL1_SSOEN_DISABLE;
    }
}


/**
*\*\name    SPI_ConfigDataLen.
*\*\fun     Configures the data size for the selected SPI.
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2   
*\*\param   DataLen (The input parameters must be the following values):
*\*\          - SPI_DATA_SIZE_16BITS
*\*\          - SPI_DATA_SIZE_8BITS
*\*\return  none
**/
void SPI_ConfigDataLen(SPI_Module* SPIx, uint32_t DataLen)
{
    /* Clear DFF bit */
    SPIx->CTRL1 &= SPI_DATALEN_MASK;
    /* Set new DFF bit value */
    SPIx->CTRL1 |= DataLen;
}


/**
*\*\name    SPI_TransmitCrcNext.
*\*\fun     Transmit the SPIx CRC value.
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2
*\*\return  none
**/
void SPI_TransmitCrcNext(SPI_Module* SPIx)
{
    /* Set the SPI_CTRL1 CRCNEXT bit */
    SPIx->CTRL1 |= SPI_CRCNEXT_ENABLE;
}

/**
*\*\name    SPI_EnableCalculateCrc.
*\*\fun     Enables or disables the CRC value calculation of the transferred bytes.
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2
*\*\param   Cmd (The input parameters must be the following values):
*\*\          - ENABLE
*\*\          - DISABLE
*\*\return  none
**/
void SPI_EnableCalculateCrc(SPI_Module* SPIx, FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        /* Enable the selected SPI CRC calculation */
        SPIx->CTRL2 |= CTRL2_CRCEN_ENABLE;
    }
    else
    {
        /* Disable the selected SPI CRC calculation */
        SPIx->CTRL2 &= CTRL2_CRCEN_DISABLE;
    }
}


/**
*\*\name    SPI_GetCRCDat.
*\*\fun     Get SPI CRC data from SPI_CRCTDAT/SPI_CRCRDAT register.
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2     
*\*\param   SPI_CRC (The input parameters must be the following values):
*\*\          - SPI_CRC_TX       
*\*\          - SPI_CRC_RX        
*\*\return  Tx/Rx CRC register value.
**/
uint32_t SPI_GetCRCDat(SPI_Module* SPIx, uint8_t SPI_CRC)
{
    uint32_t value_temp;
    if (SPI_CRC != SPI_CRC_RX)
    {
        /* return Tx CRC register value */
        value_temp = SPIx->CRCTDAT;
    }
    else
    {
        /* return Rx CRC register value */
        value_temp = SPIx->CRCRDAT;
    }
    return value_temp;
}

/**
*\*\name    SPI_GetCRCPoly.
*\*\fun     Get CRC Polynomial from SPI_CRC_POLY register.
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2       
*\*\return  The CRC Polynomial register value.
**/
uint32_t SPI_GetCRCPoly(SPI_Module* SPIx)
{
    /* Return the CRC polynomial register value */
    return SPIx->CRCPOLY;
}


/**
*\*\name    SPI_ConfigBidirectionalMode.
*\*\fun     Selects the data transfer direction in bi-directional mode for the specified SPI.
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2   
*\*\param   DataDirection (The input parameters must be the following values):
*\*\          - SPI_BIDIRECTION_RX   
*\*\          - SPI_BIDIRECTION_TX
*\*\return  none
**/
void SPI_ConfigBidirectionalMode(SPI_Module* SPIx, uint32_t DataDirection)
{
    if (DataDirection == SPI_BIDIRECTION_TX)
    {
        /* Set the Tx only mode */
        SPIx->CTRL1 |= SPI_BIDIRECTION_TX;
    }
    else
    {
        /* Set the Rx only mode */
        SPIx->CTRL1 &= SPI_BIDIRECTION_RX;
    }
}


/**
*\*\name    SPI_GetStatus.
*\*\fun     Get SPI flag status. 
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2      
*\*\param   SPI_FLAG (The input parameters must be the following values):
*\*\          - SPI_TE_FLAG
*\*\          - SPI_RNE_FLAG
*\*\          - SPI_CRCERR_FLAG
*\*\          - SPI_MODERR_FLAG
*\*\          - SPI_OVER_FLAG
*\*\          - SPI_BUSY_FLAG
*\*\return  SET or RESET
**/
FlagStatus SPI_GetStatus(SPI_Module* SPIx, uint32_t SPI_FLAG)
{
    FlagStatus bitstatus;
    /* Check the status of the specified SPI flag */
    if ((SPIx->STS & SPI_FLAG) != (uint32_t)RESET)
    {
        /* SPI_FLAG is set */
        bitstatus = SET;
    }
    else
    {
        /* SPI_FLAG is reset */
        bitstatus = RESET;
    }
    /* Return the SPI_FLAG status */
    return bitstatus;
}

/**
*\*\name    SPI_ClrCRCErrFlag.
*\*\fun     Clear SPI flag status.           
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2
*\*\param   SPI_FLAG (The input parameters must be the following values):
*\*\          - SPI_CRCERR_FLAG
*\*\return  none
*\*\note
*\*\        - OVER (OverRun error) flag is cleared by software sequence: a read
*\*\          operation to SPI_DAT register (SPI_ReceiveData()) followed by a read
*\*\          operation to SPI_STS register (SPI_GetStatus()).
*\*\        - UNDER (UnderRun error) flag is cleared by a read operation to
*\*\          SPI_STS register (SPI_GetStatus()).
*\*\        - MODERR (Mode Fault) flag is cleared by software sequence: a read/write
*\*\          operation to SPI_STS register (SPI_GetStatus()) followed by a
*\*\          write operation to SPI_CTRL1 register (SPI_Enable() to enable the SPI).
**/
void SPI_ClrCRCErrFlag(SPI_Module* SPIx, uint32_t SPI_FLAG)
{
    /* Clear the selected SPI CRC Error (CRCERR) flag */
    SPIx->STS = (~SPI_FLAG) & SPI_STS_RESERVED_MASK;
}


/**
*\*\name    SPI_GetIntStatus.
*\*\fun     Get SPI interrupt flag status.  
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2      
*\*\param   SPI_IT (The input parameters must be the following values):
*\*\          - SPI_INT_FLAG_RNE 
*\*\          - SPI_INT_FLAG_TE 
*\*\          - SPI_INT_FLAG_CRCERR
*\*\          - SPI_INT_FLAG_MODERR  
*\*\          - SPI_INT_FLAG_OVER
*\*\          - SPI_INT_FLAG_ERR
*\*\return  SET or RESET
**/
INTStatus SPI_GetIntStatus(SPI_Module* SPIx, uint32_t SPI_IT)
{
    INTStatus bitstatus;
    /* Interrupt flag */
    switch (SPI_IT)
    {
        case SPI_INT_FLAG_TE:
            if(((SPIx->CTRL2 & SPI_INT_TE) == SPI_INT_TE) && ((SPIx->STS & SPI_INT_FLAG_TE) == SPI_INT_FLAG_TE))
            {
                bitstatus = SET;
            }
            else
            {
                bitstatus = RESET;
            }
            break;
        case SPI_INT_FLAG_RNE:
            if(((SPIx->CTRL2 & SPI_INT_RNE) != (uint32_t)RESET) && ((SPIx->STS & SPI_INT_FLAG_RNE) != (uint32_t)RESET))
            {
                bitstatus = SET;
            }
            else
            {
                bitstatus = RESET;
            }
            break;
        case SPI_INT_FLAG_ERR:
        case SPI_INT_FLAG_CRCERR: 					
        case SPI_INT_FLAG_MODERR:   
        case SPI_INT_FLAG_OVER:
            if(((SPIx->CTRL2 & SPI_INT_ERR) != (uint32_t)RESET) && ((SPIx->STS & SPI_IT) != (uint32_t)RESET))
            {
                bitstatus = SET;
            }
            else
            {
                bitstatus = RESET;
            }
			break;
        default:
            bitstatus = RESET;;
            break;
    }
    return bitstatus;
}


/**
*\*\name    SPI_ClrITPendingBit.
*\*\fun     Clear SPI flag status.           
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2
*\*\param   SPI_FLAG (The input parameters must be the following values):
*\*\          - SPI_INT_FLAG_CRCERR
*\*\return  none
*\*\note
*\*\        - OVER (OverRun error) flag is cleared by software sequence: a read
*\*\          operation to SPI_DAT register (SPI_ReceiveData()) followed by a read
*\*\          operation to SPI_STS register (SPI_GetStatus()).
*\*\        - UNDER (UnderRun error) flag is cleared by a read operation to
*\*\          SPI_STS register (SPI_GetStatus()).
*\*\        - MODERR (Mode Fault) flag is cleared by software sequence: a read/write
*\*\          operation to SPI_STS register (SPI_GetStatus()) followed by a
*\*\          write operation to SPI_CTRL1 register (SPI_Enable() to enable the SPI).
**/
void SPI_ClrITPendingBit(SPI_Module* SPIx, uint32_t SPI_FLAG)
{
    /* Clear the selected SPI CRC Error (CRCERR) flag */
    SPIx->STS = (~SPI_FLAG) & SPI_STS_RESERVED_MASK;
}


/**
*\*\name    SPI_Configdelaytime.
*\*\fun     SPI Host Clock Delay Time Configuration.
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2   
*\*\param   DelayTime (The input parameters must be the following values):
*\*\          - 0x00 ~ 0x0f  delay DelayTime/2 PCLK2
*\*\return  The CRC Polynomial register value.
**/
void SPI_Configdelaytime(SPI_Module* SPIx,uint32_t DelayTime)
{
    SPIx->CTRL3 = DelayTime;
}

/**
*\*\name    SPI_NSSFailCRCEnable.
*\*\fun     NSS failure, CRC calculation stops or continues.
*\*\param   SPIx (The input parameters must be the following values):
*\*\          - SPI1   
*\*\          - SPI2   
*\*\param   Cmd (The input parameters must be the following values):
*\*\          - ENABLE
*\*\          - DISABLE
*\*\return  none
**/
void SPI_NSSFailCRCEnable(SPI_Module* SPIx,FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        /* NSS failure, CRC calculation continues. */
        SPIx->CTRL2 |= SPI_CTRL2_CRCSTP;
    }
    else
    {
        /* NSS failure, CRC calculation stops. */
        SPIx->CTRL2 &= ~SPI_CTRL2_CRCSTP;
    }
}

