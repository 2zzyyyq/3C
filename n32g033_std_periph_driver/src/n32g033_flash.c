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
*\*\file      n32g033_flash.c
*\*\author    Nsing
*\*\version   v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved. 
**/
#include "n32g033_flash.h"


/**
*\*\name    FLASH_SetLatency
*\*\fun     Sets the code latency value.
*\*\param   FLASH_Latency :(The input parameters must be the following values)
*\*\            - FLASH_LATENCY_0    FLASH Zero Latency cycle, 0 < HCLK <= 32MHz      
*\*\            - FLASH_LATENCY_1    FLASH One Latency cycle, 32MHz < HCLK<= 64MHz
*\*\return  none
*\*\note    The larger the latency, the longer the flash read operation will take. 
*\*\        If not necessary, it is recommended to use a smaller latency.
**/
void FLASH_SetLatency(uint32_t FLASH_Latency)
{
    uint32_t tmpregister;

    /* Read the AC register */
    tmpregister = FLASH->AC;

    /* Sets the Latency value */
    tmpregister &= (~FLASH_LATENCY_MASK);
    tmpregister |= FLASH_Latency;

    /* Write the AC register */
    FLASH->AC = tmpregister;
}


/**
*\*\name    FLASH_GetLatency
*\*\fun     Get the code latency value.
*\*\param   none
*\*\return  FLASH_LATENCY :(The input parameters must be the following values)
*\*\            - FLASH_LATENCY_0    FLASH Zero Latency cycle, 0 < HCLK <= 32MHz      
*\*\            - FLASH_LATENCY_1    FLASH One Latency cycle, 32MHz < HCLK<= 64MHz
**/
uint8_t FLASH_GetLatency(void)
{
    /* Read the AC register */
    return (uint8_t)(FLASH->AC & FLASH_LATENCY_MASK);
}


/**
*\*\name   FLASH_Unlock
*\*\fun    Unlocks the FLASH Program Erase Controller.
*\*\param  none
*\*\return none
*\*\note   Before operating the FLASH_CTRL register, you need to call the FLASH_Unlock function to unlock the LOCK bit.
**/
void FLASH_Unlock(void)
{
    FLASH->KEY = FLASH_KEY1;
    FLASH->KEY = FLASH_KEY2;
}


/**
*\*\name   FLASH_Lock
*\*\fun    Locks the FLASH Program Erase Controller.
*\*\param  none
*\*\return none
**/
void FLASH_Lock(void)
{
    FLASH->CTRL |= CTRL_Set_LOCK;
}


/**
*\*\name   Flash_GetLockStatus
*\*\fun    Get the Flash lock status.
*\*\param  none
*\*\return FlagStatus :
*\*\            - SET     FLASH is in Lock state
*\*\            - RESET   FLASH is in Unlock state
**/
FlagStatus Flash_GetLockStatus(void)
{
    FlagStatus bit_status;
    if ((FLASH->CTRL & CTRL_Set_LOCK) != (uint32_t)RESET)
    {
        bit_status = SET;
    }
    else
    {
        bit_status =  RESET;
    }
    return bit_status;
}


/**
*\*\name   Option_Bytes_Unlock
*\*\fun    Unlocks the Option_Bytes Program Erase Controller.
*\*\param  none
*\*\return none
**/
void Option_Bytes_Unlock(void)
{
    FLASH->OPTKEY = FLASH_KEY1;
    FLASH->OPTKEY = FLASH_KEY2;
}


/**
*\*\name   Option_Bytes_Lock
*\*\fun    Locks the Option_Bytes Program Erase Controller.
*\*\param  none
*\*\return none
**/
void Option_Bytes_Lock(void)
{
    /* Set the FLASH_CTRL_SET_OPTWE Bit to lock */
    FLASH->CTRL &= (~FLASH_CTRL_SET_OPTWE);
}


/**
*\*\name   OB_GetLockStatus
*\*\fun    Get the Option Bytes lock status.
*\*\param  none
*\*\return FlagStatus :
*\*\            - SET     Option byte is in Unlock state
*\*\            - RESET   Option byte is in Lock state
**/
FlagStatus OB_GetLockStatus(void)
{
    FlagStatus bit_status;
    if ((FLASH->CTRL & FLASH_CTRL_SET_OPTWE) != (uint32_t)RESET)
    {
        bit_status = SET;
    }
    else
    {
        bit_status =  RESET;
    }
    return bit_status;
}


/**
*\*\name   FLASH_EraseOnePage
*\*\fun    Erases a specified main FLASH page.
*\*\param  Page_Address :(The input parameters must be the following values)
*\*\            - main flash, it ranges from 0x08000000 to 0x0800FFFF, it must be a multiple of 0x200
*\*\return FLASH_STS : 
*\*\            - FLASH_BUSY     FLASH is busy
*\*\            - FLASH_ERR_PG   FLASH programming error
*\*\            - FLASH_ERR_WRP  FLASH Write protected error
*\*\            - FLASH_EOP      FLASH End of Operation
*\*\            - FLASH_TIMEOUT  FLASH operation timeout
*\*\            - FLASH_ERR_ADD  FLASH address error
**/
FLASH_STS FLASH_EraseOnePage(uint32_t Page_Address)
{
    FLASH_STS status;
    FLASH_Unlock();
    /* Check  Page Address */
    if((Page_Address < 0x8000000U) || (Page_Address >= 0x8010000U))
    {
        status = FLASH_ERR_ADD;
        return status;
    }
    
    /* Clears the FLASH's pending flags */
    FLASH_ClearFlag(FLASH_STS_CLRFLAG);
    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOpt(EraseTimeout);

    if (status == FLASH_EOP)
    {
        /* if the previous operation is completed, proceed to erase the page */
        FLASH->CTRL |= CTRL_Set_PER;
        FLASH->ADD = Page_Address;
        FLASH->CTRL |= CTRL_Set_START;

        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOpt(EraseTimeout);

        /* Disable the PER Bit */
        FLASH->CTRL &= CTRL_Reset_PER;
    }
  FLASH_Lock();
    /* Return the Erase Status */
    return status;
}


/**
*\*\name   FLASH_MassErase
*\*\fun    Erases all main FLASH pages.
*\*\param  none
*\*\return FLASH_STS : 
*\*\            - FLASH_BUSY     FLASH is busy
*\*\            - FLASH_ERR_PG   FLASH programming error
*\*\            - FLASH_ERR_WRP  FLASH Write protected error
*\*\            - FLASH_EOP      FLASH End of Operation
*\*\            - FLASH_TIMEOUT  FLASH operation timeout
**/
FLASH_STS FLASH_MassErase(void)
{
    FLASH_STS status;

    /* Clears the FLASH's pending flags */
    FLASH_ClearFlag(FLASH_STS_CLRFLAG);
    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOpt(EraseTimeout);

    if (status == FLASH_EOP)
    {
        /* if the previous operation is completed, proceed to erase all pages */
        FLASH->CTRL |= CTRL_Set_MER;
        FLASH->CTRL |= CTRL_Set_START;

        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOpt(EraseTimeout);

        /* Disable the MER Bit */
        FLASH->CTRL &= CTRL_Reset_MER;
    }

    /* Return the Erase Status */
    return status;
}


/**
*\*\name   FLASH_ProgramWord
*\*\fun    Programs one word at a specified address.
*\*\param  address :(The input parameters must be the following values)
*\*\            - it ranges from 0x08000000 to 0x0800FFFF, it must be a multiple of 0x04
*\*\param  data :(The input parameters must be the following values)
*\*\            - It ranges from 0x00000000 to 0xFFFFFFFF
*\*\return FLASH_STS : 
*\*\            - FLASH_BUSY     FLASH is busy
*\*\            - FLASH_ERR_PG   FLASH programming error
*\*\            - FLASH_ERR_WRP  FLASH Write protected error
*\*\            - FLASH_EOP      FLASH End of Operation
*\*\            - FLASH_ERR_ADD  FLASH address error
*\*\            - FLASH_TIMEOUT  FLASH operation timeout
**/
FLASH_STS FLASH_ProgramWord(uint32_t address, uint32_t data)
{
    FLASH_STS status_value = FLASH_EOP;

    if((address & FLASH_WORD_LENGTH) != (uint32_t)0x00)
    {
        /* The programming address is not a multiple of 4 */
        status_value = FLASH_ERR_ADD;
    }
    else
    {
        /*No process*/
    }

    if(status_value == FLASH_ERR_ADD)
    {
    
    }
    else
    {
        /* Clears the FLASH's pending flags */
        FLASH_ClearFlag(FLASH_STS_CLRFLAG);
        /* Wait for last operation to be completed */
        status_value = FLASH_WaitForLastOpt(ProgramTimeout);
    }

    if (status_value == FLASH_EOP)
    {
        /* if the previous operation is completed, proceed to program the new word */
        FLASH->CTRL |= CTRL_Set_PG;

        *(__IO uint32_t*)address = (uint32_t)data;

        /* Wait for last operation to be completed */
        status_value = FLASH_WaitForLastOpt(ProgramTimeout);

        /* Disable the PG Bit */
        FLASH->CTRL &= CTRL_Reset_PG;
    }
    else
    {
        /*No process*/
    }
    
    /* Return the Program status_value */
    return status_value;
}


/**
*\*\name   FLASH_EraseOB
*\*\fun    Erases the FLASH option bytes.
*\*\param  none
*\*\return FLASH_STS : 
*\*\            - FLASH_BUSY     FLASH is busy
*\*\            - FLASH_ERR_PG   FLASH programming error
*\*\            - FLASH_ERR_WRP  FLASH Write protected error
*\*\            - FLASH_EOP      FLASH End of Operation
*\*\            - FLASH_ERR_RDP2 FLASH is in read protection L2 status
*\*\            - FLASH_TIMEOUT  FLASH operation timeout
**/
FLASH_STS FLASH_EraseOB(void)
{
    FLASH_STS status_value = FLASH_EOP;

    /* Get the actual read protection L2 Option Byte value */
    if (FLASH_GetReadOutProtectionL2STS() != RESET)
    {
        status_value = FLASH_ERR_RDP2;
    }
    else
    {
        /*No process*/
    }
    
    if(status_value == FLASH_ERR_RDP2)
    {
    
    }
    else
    {
        /* Clears the FLASH's pending flags */
        FLASH_ClearFlag(FLASH_STS_CLRFLAG);
        /* Wait for last operation to be completed */
        status_value = FLASH_WaitForLastOpt(EraseTimeout);
    }

    if (status_value == FLASH_EOP)
    {
        Option_Bytes_Unlock();

        /* if the previous operation is completed, proceed to erase the option bytes */
        FLASH->CTRL |= CTRL_Set_OPTER;
        FLASH->CTRL |= CTRL_Set_START;
        /* Wait for last operation to be completed */
        status_value = FLASH_WaitForLastOpt(EraseTimeout);

        if (status_value == FLASH_EOP)
        {
            /* Clears the FLASH's pending flags */
            FLASH_ClearFlag(FLASH_STS_CLRFLAG);

            /* if the erase operation is completed, disable the OPTER Bit */
            FLASH->CTRL &= CTRL_Reset_OPTER;
        }
        else
        {
            if (status_value != FLASH_TIMEOUT)
            {
                /* Disable the OPTER Bit */
                FLASH->CTRL &= CTRL_Reset_OPTER;
            }
            else
            {
                /*No process*/
            }
        }
    }
    else
    {
        /*No process*/
    }
    /* Return the erase status_value */
    return status_value;
}


/**
*\*\name   FLASH_ProgramOptionBytes_USER4_RDP1
*\*\fun    Programs the Option Byte: USER4 and RDP1.
*\*\param  option_byte_user4 :(The input parameters must be the following values)
*\*\        - BOOT_UARTPIN_PA9PA10   BOOT uart pins are PA9 and PA10
*\*\        - BOOT_UARTPIN_PA13PA14  BOOT uart pins are PA13 and PA14
*\*\        - BOOT_UARTPIN_PF0PF1    BOOT uart pins are PF0 and PF1
*\*\        - BOOT_UARTPIN_PA2PA3    BOOT uart pins are PA2 and PA3
*\*\param  option_byte_rpd1 :(The input parameters must be the following values)
*\*\        - FLASH_OB_RDP1_ENABLE   Enable read protection L1
*\*\        - FLASH_OB_RDP1_DISABLE  Disable read protection L1
*\*\return FLASH_STS : 
*\*\        - FLASH_BUSY     FLASH is busy
*\*\        - FLASH_ERR_PG   FLASH programming error
*\*\        - FLASH_ERR_WRP  FLASH Write protected error
*\*\        - FLASH_EOP      FLASH End of Operation
*\*\        - FLASH_ERR_RDP2 FLASH is in read protection L2 status
*\*\        - FLASH_TIMEOUT  FLASH operation timeout
**/
FLASH_STS FLASH_ProgramOptionBytes_USER4_RDP1(uint32_t option_byte_user4, uint8_t option_byte_rpd1)
{
    FLASH_STS status_value = FLASH_EOP;

    /* Get the actual read protection L2 Option Byte value */
    if (FLASH_GetReadOutProtectionL2STS() != RESET)
    {
        status_value = FLASH_ERR_RDP2;
    }
    else
    {
        /*No process*/
    }
    
    if(status_value == FLASH_ERR_RDP2)
    {
    
    }
    else
    {
        Option_Bytes_Unlock();
      
        /* Clears the FLASH's pending flags */
        FLASH_ClearFlag(FLASH_STS_CLRFLAG);
        /* Wait for last operation to be completed */
        status_value = FLASH_WaitForLastOpt(ProgramTimeout);
    }

    if (status_value == FLASH_EOP)
    {
        /* Enable the Option Bytes Programming operation */
        FLASH->CTRL |= CTRL_Set_OPTPG;
        /* Restore the last read protection Option Byte value */
        OBT->USER4_RDP1 = (option_byte_user4 | (uint32_t)option_byte_rpd1);
        
        /* Wait for last operation to be completed */
        status_value = FLASH_WaitForLastOpt(ProgramTimeout);
        if (status_value != FLASH_TIMEOUT)
        {
            /* if the program operation is completed, disable the OPTPG Bit */
            FLASH->CTRL &= CTRL_Reset_OPTPG;
        }
        else
        {
            /*No process*/
        }
    }
    else
    {
        /*No process*/
    }

    /* Return the Option Byte program status_value */
    return status_value;
}


/**
*\*\name   FLASH_ProgramOptionBytes_USER0
*\*\fun    Programs the Option Byte: IWDG_SW.
*\*\param  option_byte_iwdg :(The input parameters must be the following values)
*\*\        - FLASH_OB_IWDG_SOFTWARE Software IWDG selected
*\*\        - FLASH_OB_IWDG_HARDWARE Hardware IWDG selected
*\*\return FLASH_STS : 
*\*\        - FLASH_BUSY     FLASH is busy
*\*\        - FLASH_ERR_PG   FLASH programming error
*\*\        - FLASH_ERR_WRP  FLASH Write protected error
*\*\        - FLASH_EOP      FLASH End of Operation
*\*\        - FLASH_ERR_RDP2 FLASH is in read protection L2 status
*\*\        - FLASH_TIMEOUT  FLASH operation timeout
**/
FLASH_STS FLASH_ProgramOptionBytes_USER0(uint32_t option_byte_iwdg)
{
    FLASH_STS status_value = FLASH_EOP;

    /* Get the actual read protection L2 Option Byte value */
    if (FLASH_GetReadOutProtectionL2STS() != RESET)
    {
        status_value = FLASH_ERR_RDP2;
    }
    else
    {
        /*No process*/
    }
    
    if(status_value == FLASH_ERR_RDP2)
    {
    
    }
    else
    {
        Option_Bytes_Unlock();
      
        /* Clears the FLASH's pending flags */
        FLASH_ClearFlag(FLASH_STS_CLRFLAG);
        /* Wait for last operation to be completed */
        status_value = FLASH_WaitForLastOpt(ProgramTimeout);
    }

    if (status_value == FLASH_EOP)
    {
        /* Enable the Option Bytes Programming operation */
        FLASH->CTRL |= CTRL_Set_OPTPG;
        /* Restore the last read protection Option Byte value */
        OBT->USER0 = ((uint32_t)(option_byte_iwdg));     
        /* Wait for last operation to be completed */
        status_value = FLASH_WaitForLastOpt(ProgramTimeout);
        if (status_value != FLASH_TIMEOUT)
        {
            /* if the program operation is completed, disable the OPTPG Bit */
            FLASH->CTRL &= CTRL_Reset_OPTPG;
        }
        else
        {
            /*No process*/
        }
    }
    else
    {
        /*No process*/
    }

    /* Return the Option Byte program status_value */
    return status_value;

}


/**
*\*\name   FLASH_ProgramOptionBytes_USER1
*\*\fun    Programs the Option Byte: NRST_PF3.
*\*\param  option_byte_iwdg :(The input parameters must be the following values)
*\*\            - FLASH_OB_PF3_GPIO PF3 set GPIO
*\*\            - FLASH_OB_PF3_NRST PF3 set NRST
*\*\return FLASH_STS : 
*\*\        - FLASH_BUSY     FLASH is busy
*\*\        - FLASH_ERR_PG   FLASH programming error
*\*\        - FLASH_ERR_WRP  FLASH Write protected error
*\*\        - FLASH_EOP      FLASH End of Operation
*\*\        - FLASH_ERR_RDP2 FLASH is in read protection L2 status
*\*\        - FLASH_TIMEOUT  FLASH operation timeout
**/
FLASH_STS FLASH_ProgramOptionBytes_USER1(uint32_t option_byte_PF3)
{
    FLASH_STS status_value = FLASH_EOP;

    /* Get the actual read protection L2 Option Byte value */
    if (FLASH_GetReadOutProtectionL2STS() != RESET)
    {
        status_value = FLASH_ERR_RDP2;
    }
    else
    {
        /*No process*/
    }
    
    if(status_value == FLASH_ERR_RDP2)
    {
    
    }
    else
    {
        Option_Bytes_Unlock();
      
        /* Clears the FLASH's pending flags */
        FLASH_ClearFlag(FLASH_STS_CLRFLAG);
        /* Wait for last operation to be completed */
        status_value = FLASH_WaitForLastOpt(ProgramTimeout);
    }
    if (status_value == FLASH_EOP)
    {
        /* Enable the Option Bytes Programming operation */
        FLASH->CTRL |= CTRL_Set_OPTPG;
        /* Restore the last read protection Option Byte value */
        OBT->USER1 = ((uint32_t)(option_byte_PF3));       
        /* Wait for last operation to be completed */
        status_value = FLASH_WaitForLastOpt(ProgramTimeout);
        if (status_value != FLASH_TIMEOUT)
        {
            /* if the program operation is completed, disable the OPTPG Bit */
            FLASH->CTRL &= CTRL_Reset_OPTPG;
        }
        else
        {
            /*No process*/
        }
    }
    else
    {
        /*No process*/
    }

    /* Return the Option Byte program status_value */
    return status_value;
	
}


/**
*\*\name   FLASH_ProgramOptionBytes_USER3_USER2
*\*\fun    Programs the Option Byte: USER3 and USER2.
*\*\param   option_byte_nBOOT0 :(The input parameters must be the following values)
*\*\            - FLASH_OB_NBOOT0_SET Set nBOOT0
*\*\            - FLASH_OB_NBOOT0_CLR Clear nBOOT0
*\*\param   option_byte_nBOOT1 :(The input parameters must be the following values)
*\*\            - FLASH_OB_NBOOT1_SET Set nBOOT1
*\*\            - FLASH_OB_NBOOT1_CLR Clear nBOOT1
*\*\param   option_byte_nSWBOOT0 :(The input parameters must be the following values)
*\*\            - FLASH_OB_NSWBOOT0_SET Set nSWBOOT0
*\*\            - FLASH_OB_NSWBOOT0_CLR Clear nSWBOOT0
*\*\param   option_byte_BOOT0_CFG :(The input parameters must be the following values)
*\*\            - FLASH_OB_BOOT0_CFG_HIGH Boot0 high active
*\*\            - FLASH_OB_BOOT0_CFG_LOW  Boot0 low active
*\*\param   option_byte_user2:(The input parameters must be the following values)
*\*\            - 0x00 to 0xFF  PDR/POR filter control count value,8192~30us
*\*\return FLASH_STS : 
*\*\        - FLASH_BUSY     FLASH is busy
*\*\        - FLASH_ERR_PG   FLASH programming error
*\*\        - FLASH_ERR_WRP  FLASH Write protected error
*\*\        - FLASH_EOP      FLASH End of Operation
*\*\        - FLASH_ERR_RDP2 FLASH is in read protection L2 status
*\*\        - FLASH_TIMEOUT  FLASH operation timeout
**/
FLASH_STS FLASH_ProgramOptionBytes_USER3_USER2(uint32_t option_byte_nBOOT0, uint32_t option_byte_nBOOT1, uint32_t option_byte_nSWBOOT0, uint32_t option_byte_BOOT0_CFG, uint32_t option_byte_user2)
{
    FLASH_STS status_value = FLASH_EOP;

    /* Get the actual read protection L2 Option Byte value */
    if (FLASH_GetReadOutProtectionL2STS() != RESET)
    {
        status_value = FLASH_ERR_RDP2;
    }
    else
    {
        /*No process*/
    }
    
    if(status_value == FLASH_ERR_RDP2)
    {
    
    }
    else
    {
        Option_Bytes_Unlock();
      
        /* Clears the FLASH's pending flags */
        FLASH_ClearFlag(FLASH_STS_CLRFLAG);
        /* Wait for last operation to be completed */
        status_value = FLASH_WaitForLastOpt(ProgramTimeout);
    }

    if (status_value == FLASH_EOP)
    {
        /* Enable the Option Bytes Programming operation */
        FLASH->CTRL |= CTRL_Set_OPTPG;
        /* Restore the last read protection Option Byte value */
        OBT->USER3_USER2 = (((uint32_t)(option_byte_nBOOT0 | option_byte_nBOOT1 | option_byte_nSWBOOT0 | option_byte_BOOT0_CFG)) | ((uint32_t)option_byte_user2));      
        /* Wait for last operation to be completed */
        status_value = FLASH_WaitForLastOpt(ProgramTimeout);
        if (status_value != FLASH_TIMEOUT)
        {
            /* if the program operation is completed, disable the OPTPG Bit */
            FLASH->CTRL &= CTRL_Reset_OPTPG;
        }
        else
        {
            /*No process*/
        }
    }
    else
    {
        /*No process*/
    }

    /* Return the Option Byte program status_value */
    return status_value;
}


/**
*\*\name   FLASH_ProgramOptionBytes_DATA1_DATA0
*\*\fun    Programs 2 half words at a specified Option Byte Data1 and Data0.
*\*\param  option_byte_data1:(The input parameters must be the following values)
*\*\                - 0x00 to 0xFF
*\*\param  option_byte_data0:(The input parameters must be the following values)
*\*\                - 0x00 to 0xFF
*\*\return FLASH_STS: The returned value can be: 
*\*\        - FLASH_BUSY     FLASH is busy
*\*\        - FLASH_ERR_PG   FLASH programming error
*\*\        - FLASH_ERR_WRP  FLASH Write protected error
*\*\        - FLASH_EOP      FLASH End of Operation
*\*\        - FLASH_ERR_RDP2 FLASH is in read protection L2 status
*\*\        - FLASH_TIMEOUT  FLASH operation timeout
**/
FLASH_STS FLASH_ProgramOptionBytes_DATA1_DATA0(uint8_t option_byte_data1, uint8_t option_byte_data0)
{
    FLASH_STS status_value = FLASH_EOP;

    /* Get the actual read protection L2 Option Byte value */
    if (FLASH_GetReadOutProtectionL2STS() != RESET)
    {
        status_value = FLASH_ERR_RDP2;
    }
    else
    {
        /*No process*/
    }
    
    if(status_value == FLASH_ERR_RDP2)
    {
    
    }
    else
    {
        Option_Bytes_Unlock();
      
        /* Clears the FLASH's pending flags */
        FLASH_ClearFlag(FLASH_STS_CLRFLAG);
        /* Wait for last operation to be completed */
        status_value = FLASH_WaitForLastOpt(ProgramTimeout);
    }

    if (status_value == FLASH_EOP)
    {
        /* Enable the Option Bytes Programming operation */
        FLASH->CTRL |= CTRL_Set_OPTPG;
        /* Restore the last read protection Option Byte value */
        OBT->Data1_Data0 = ((((uint32_t)option_byte_data1) << FLASH_DATA0_DATA1_OFFSET) | ((uint32_t)option_byte_data0));        
        /* Wait for last operation to be completed */
        status_value = FLASH_WaitForLastOpt(ProgramTimeout);
        if (status_value != FLASH_TIMEOUT)
        {
            /* if the program operation is completed, disable the OPTPG Bit */
            FLASH->CTRL &= CTRL_Reset_OPTPG;
        }
        else
        {
            /*No process*/
        }
    }
    else
    {
        /*No process*/
    }

    /* Return the Option Byte program status_value */
    return status_value;
}


/**
*\*\name   FLASH_EnWriteProtection
*\*\fun    Write protects the desired pages
*\*\param  FLASH_Pages :(The input parameters must be the following values)
*\*\        - FLASH_WRP_Pages0to7      Enable Write protection of page 0 to 7
*\*\        - FLASH_WRP_Pages8to15     Enable Write protection of page 8 to 15
*\*\        - FLASH_WRP_Pages16to23    Enable Write protection of page 16 to 23
*\*\        - FLASH_WRP_Pages24to31    Enable Write protection of page 24 to 31
*\*\        - FLASH_WRP_Pages32to39    Enable Write protection of page 32 to 39
*\*\        - FLASH_WRP_Pages40to47    Enable Write protection of page 40 to 47
*\*\        - FLASH_WRP_Pages48to55    Enable Write protection of page 48 to 55
*\*\        - FLASH_WRP_Pages56to63    Enable Write protection of page 56 to 63
*\*\        - FLASH_WRP_Pages64to71    Enable Write protection of page 64 to 71
*\*\        - FLASH_WRP_Pages72to79    Enable Write protection of page 72 to 79
*\*\        - FLASH_WRP_Pages80to87    Enable Write protection of page 80 to 87
*\*\        - FLASH_WRP_Pages88to95    Enable Write protection of page 88 to 95
*\*\        - FLASH_WRP_Pages96to103   Enable Write protection of page 96 to 103
*\*\        - FLASH_WRP_Pages104to111  Enable Write protection of page 104 to 111
*\*\        - FLASH_WRP_Pages112to119  Enable Write protection of page 112 to 119
*\*\        - FLASH_WRP_Pages120to127  Enable Write protection of page 120 to 127
*\*\        - FLASH_WRP_AllPages       Enable Write protection of all Pages
*\*\        - ~FLASH_WRP_AllPages      Disable Write protection of all Pages
*\*\return FLASH_STS : 
*\*\        - FLASH_BUSY     FLASH is busy
*\*\        - FLASH_ERR_PG   FLASH programming error
*\*\        - FLASH_ERR_WRP  FLASH Write protected error
*\*\        - FLASH_EOP      FLASH End of Operation
*\*\        - FLASH_ERR_RDP2 FLASH is in read protection L2 status
*\*\        - FLASH_TIMEOUT  FLASH operation timeout
**/
FLASH_STS FLASH_EnWriteProtection(uint32_t FLASH_Pages)
{
    uint32_t WRP0_Data, WRP1_Data;

    FLASH_STS status_value = FLASH_EOP;
    
    uint32_t FLASH_Pages_temp;

    /* Get the actual read protection L2 Option Byte value */
    if (FLASH_GetReadOutProtectionL2STS() != RESET)
    {
        status_value = FLASH_ERR_RDP2;
    }
    else
    {
        /*No process*/
    }
    
    FLASH_Pages_temp = (uint32_t)(~FLASH_Pages);
    WRP0_Data   = (uint32_t)(FLASH_Pages_temp & FLASH_WRP0_MSK);
    WRP1_Data   = (uint32_t)(FLASH_Pages_temp & FLASH_WRP1_MSK);
    
    if(status_value == FLASH_ERR_RDP2)
    {
    
    }
    else
    {
        /* Clears the FLASH's pending flags */
        FLASH_ClearFlag(FLASH_STS_CLRFLAG);
        /* Wait for last operation to be completed */
        status_value = FLASH_WaitForLastOpt(ProgramTimeout);
    }

    if (status_value == FLASH_EOP)
    {
        Option_Bytes_Unlock();
        FLASH->CTRL |= CTRL_Set_OPTPG;

        if ((WRP0_Data != FLASH_WRP0_MSK) || (WRP1_Data != FLASH_WRP1_MSK))
        {
            OBT->WRP1_WRP0 = (WRP1_Data | WRP0_Data);

            /* Wait for last operation to be completed */
            status_value = FLASH_WaitForLastOpt(ProgramTimeout);
        }
        else
        {
            /*No process*/
        }
                
        if (status_value != FLASH_TIMEOUT)
        {
            /* if the program operation is completed, disable the OPTPG Bit */
            FLASH->CTRL &= CTRL_Reset_OPTPG;
        }
        else
        {
            /*No process*/
        }
    }
    else
    {
        /*No process*/
    }
    /* Return the write protection operation Status */
    return status_value;
}


/**
*\*\name   FLASH_ProgramOptionBytes_RDP2
*\*\fun    Programs the Option Byte: RDP2.
*\*\param  option_byte_rpd2 :(The input parameters must be the following values)
*\*\            - FLASH_OB_RDP2_ENABLE   Enable read protection L2
*\*\            - FLASH_OB_RDP2_DISABLE  Disable read protection L2
*\*\return FLASH_STS : 
*\*\        - FLASH_BUSY     FLASH is busy
*\*\        - FLASH_ERR_PG   FLASH programming error
*\*\        - FLASH_ERR_WRP  FLASH Write protected error
*\*\        - FLASH_EOP      FLASH End of Operation
*\*\        - FLASH_ERR_RDP2 FLASH is in read protection L2 status
*\*\        - FLASH_TIMEOUT  FLASH operation timeout
**/
FLASH_STS FLASH_ProgramOptionBytes_RDP2(uint8_t option_byte_rpd2)
{
    FLASH_STS status_value = FLASH_EOP;

    /* Get the actual read protection L2 Option Byte value */
    if (FLASH_GetReadOutProtectionL2STS() != RESET)
    {
        status_value = FLASH_ERR_RDP2;
    }
    else
    {
        /*No process*/
    }
    
    if(status_value == FLASH_ERR_RDP2)
    {
    
    }
    else
    {
        Option_Bytes_Unlock();
      
        /* Clears the FLASH's pending flags */
        FLASH_ClearFlag(FLASH_STS_CLRFLAG);
        /* Wait for last operation to be completed */
        status_value = FLASH_WaitForLastOpt(ProgramTimeout);
    }

    if (status_value == FLASH_EOP)
    {
        /* Enable the Option Bytes Programming operation */
        FLASH->CTRL |= CTRL_Set_OPTPG;
        /* Restore the last read protection Option Byte value */
        OBT->RDP2 = (uint32_t)option_byte_rpd2;
        
        /* Wait for last operation to be completed */
        status_value = FLASH_WaitForLastOpt(ProgramTimeout);
        if (status_value != FLASH_TIMEOUT)
        {
            /* if the program operation is completed, disable the OPTPG Bit */
            FLASH->CTRL &= CTRL_Reset_OPTPG;
        }
        else
        {
            /*No process*/
        }
    }
    else
    {
        /*No process*/
    }

    /* Return the Option Byte program status_value */
    return status_value;
}


/**
*\*\name   FLASH_ReadOutProtectionL1
*\*\fun    Enables the read out protection.
*\*\param  Cmd:(The input parameters must be the following values)
*\*\            - ENABLE   Enable read protection L1
*\*\            - DISABLE  Disable read protection L1
*\*\return FLASH_STS : 
*\*\        - FLASH_BUSY     FLASH is busy
*\*\        - FLASH_ERR_PG   FLASH programming error
*\*\        - FLASH_ERR_WRP  FLASH Write protected error
*\*\        - FLASH_EOP      FLASH End of Operation
*\*\        - FLASH_ERR_RDP2 FLASH is in read protection L2 status
*\*\        - FLASH_TIMEOUT  FLASH operation timeout
**/
FLASH_STS FLASH_ReadOutProtectionL1(FunctionalState Cmd)
{
    uint32_t user3_nBOOT0, user3_nBOOT1, user3_nSWBOOT0, user3_BOOT0_CFG; 
    uint32_t user0_temp, user1_temp, user2_temp, user4_temp;
    uint32_t data0_temp, data1_temp;
    uint32_t WP_temp;
    FLASH_STS status_value = FLASH_EOP;

    /* Get the actual read protection L2 Option Byte value */
    if (FLASH_GetReadOutProtectionL2STS() != RESET)
    {
        status_value = FLASH_ERR_RDP2;
    }
    else
    {
        /*No process*/
    }
    
    if(FLASH_GetOptionBytes_User3(FLASH_OB_NBOOT0_SET) == SET)
    {
        user3_nBOOT0 = FLASH_OB_NBOOT0_SET;
    }
    else
    {
        user3_nBOOT0 = FLASH_OB_NBOOT0_CLR;
    }
    
    if(FLASH_GetOptionBytes_User3(FLASH_OB_NBOOT1_SET) == SET)
    {
        user3_nBOOT1 = FLASH_OB_NBOOT1_SET;
    }
    else
    {
        user3_nBOOT1 = FLASH_OB_NBOOT1_CLR;
    }
    
    if(FLASH_GetOptionBytes_User3(FLASH_OB_NSWBOOT0_SET) == SET)
    {
        user3_nSWBOOT0 = FLASH_OB_NSWBOOT0_SET;
    }    
    else
    {
        user3_nSWBOOT0 = FLASH_OB_NSWBOOT0_CLR;
    }
    
    if(FLASH_GetOptionBytes_User3(FLASH_OB_BOOT0_CFG_HIGH) == SET)
    {
        user3_BOOT0_CFG = FLASH_OB_BOOT0_CFG_HIGH;
    }
    else
    {
        user3_BOOT0_CFG = FLASH_OB_BOOT0_CFG_LOW;
    }    
        
    user0_temp = OBT->USER0;
    user1_temp = OBT->USER1;
    user2_temp = OBT->USER3_USER2 & FLASH_OB_USER2_MASK;
    user4_temp = OBT->USER4_RDP1 & FLASH_OB_USER4_MASK;
    data0_temp = OBT->Data1_Data0 & FLASH_OB_DATA0_MASK;
    data1_temp = (OBT->Data1_Data0 & (FLASH_OB_DATA1_MASK << FLASH_OB_DATA1_OFFSET)) >> FLASH_DATA0_DATA1_OFFSET;
    WP_temp = OBT->WRP1_WRP0;
    
    if(status_value == FLASH_EOP)
    {       
        FLASH_Unlock();
        status_value = FLASH_EraseOB();
    }
    else
    {
        /*No process*/
    }

    /* USER0 value write back*/
    if(status_value == FLASH_EOP)
    {
        status_value = FLASH_ProgramOptionBytes_USER0(user0_temp);
    }
    else
    {
        /* no process*/
    }
    
    /* USER1 value write back*/
    if(status_value == FLASH_EOP)
    {
        status_value = FLASH_ProgramOptionBytes_USER1(user1_temp);
    }
    else
    {
        /* no process*/
    }
    
    /* USER2 and USER3 value write back*/
    if(status_value == FLASH_EOP)
    {
        status_value = FLASH_ProgramOptionBytes_USER3_USER2(user3_nBOOT0, user3_nBOOT1, user3_nSWBOOT0, user3_BOOT0_CFG, user2_temp);
    }
    else
    {
        /* no process*/
    }
    
  
    /* DATA0 and DATA1 value write back */
    if(status_value == FLASH_EOP)
    {
        status_value = FLASH_ProgramOptionBytes_DATA1_DATA0((uint8_t)data1_temp, (uint8_t)data0_temp);
    }
    else
    {
        /* no process*/
    }
      
    if(status_value == FLASH_EOP)
    {
        status_value = FLASH_EnWriteProtection(~WP_temp);
    }
    else
    {
        /* no process*/
    }
    
    if(status_value == FLASH_EOP)
    {
        if (Cmd != DISABLE)
        {
            /* Enables the read out protection L1 */
            status_value = FLASH_ProgramOptionBytes_USER4_RDP1(user4_temp,FLASH_OB_RDP1_ENABLE);
        }
        else
        {
            /* Disables the read out protection L1 */
            status_value = FLASH_ProgramOptionBytes_USER4_RDP1(user4_temp,FLASH_OB_RDP1_DISABLE);
        }    
    }
    else
    {
        /* no process*/
    }
  
    /* Return the protection operation status_value */
    return status_value;
}


/**
*\*\name   FLASH_ReadOutProtectionL2_ENABLE
*\*\fun    Enables the read out protection L2.
*\*\param  none
*\*\return FLASH_STS : 
*\*\        - FLASH_BUSY     FLASH is busy
*\*\        - FLASH_ERR_PG   FLASH programming error
*\*\        - FLASH_ERR_WRP  FLASH Write protected error
*\*\        - FLASH_EOP      FLASH End of Operation
*\*\        - FLASH_ERR_RDP2 FLASH is in read protection L2 status
*\*\        - FLASH_TIMEOUT  FLASH operation timeout
**/
FLASH_STS FLASH_ReadOutProtectionL2_ENABLE(void)
{
    uint32_t user3_nBOOT0, user3_nBOOT1, user3_nSWBOOT0, user3_BOOT0_CFG; 
    uint32_t user0_temp, user1_temp, user2_temp, user4_temp, rdp1_temp;	
    uint32_t data0_temp, data1_temp;
    uint32_t WP_temp;
    FLASH_STS status_value = FLASH_EOP;

    /* Get the actual read protection L2 Option Byte value */
    if (FLASH_GetReadOutProtectionL2STS() != RESET)
    {
        status_value = FLASH_ERR_RDP2;
    }
    else
    {
        /*No process*/
    }
    
    if(FLASH_GetOptionBytes_User3(FLASH_OB_NBOOT0_SET) == SET)
    {
        user3_nBOOT0 = FLASH_OB_NBOOT0_SET;
    }
    else
    {
        user3_nBOOT0 = FLASH_OB_NBOOT0_CLR;
    }
    
    if(FLASH_GetOptionBytes_User3(FLASH_OB_NBOOT1_SET) == SET)
    {
        user3_nBOOT1 = FLASH_OB_NBOOT1_SET;
    }
    else
    {
        user3_nBOOT1 = FLASH_OB_NBOOT1_CLR;
    }
    
    if(FLASH_GetOptionBytes_User3(FLASH_OB_NSWBOOT0_SET) == SET)
    {
        user3_nSWBOOT0 = FLASH_OB_NSWBOOT0_SET;
    }    
    else
    {
        user3_nSWBOOT0 = FLASH_OB_NSWBOOT0_CLR;
    }
    
    if(FLASH_GetOptionBytes_User3(FLASH_OB_BOOT0_CFG_HIGH) == SET)
    {
        user3_BOOT0_CFG = FLASH_OB_BOOT0_CFG_HIGH;
    }
    else
    {
        user3_BOOT0_CFG = FLASH_OB_BOOT0_CFG_LOW;
    }    
        
    user4_temp = OBT->USER4_RDP1 & FLASH_OB_USER4_MASK;
    rdp1_temp = OBT->USER4_RDP1 & FLASH_OB_RDP1_MASK;
    
    user0_temp = OBT->USER0;
    user1_temp = OBT->USER1;
    user2_temp = OBT->USER3_USER2 & FLASH_OB_USER2_MASK;
    data0_temp = OBT->Data1_Data0 & FLASH_OB_DATA0_MASK;
    data1_temp = (OBT->Data1_Data0 & (FLASH_OB_DATA1_MASK << FLASH_OB_DATA1_OFFSET)) >> FLASH_DATA0_DATA1_OFFSET;
    WP_temp = OBT->WRP1_WRP0;
    
    if(status_value == FLASH_EOP)
    {       
        FLASH_Unlock();
        status_value = FLASH_EraseOB();
    }
    else
    {
        /*No process*/
    }

    /* USER4 value and RDP1 value write back*/
    if(status_value == FLASH_EOP)
    {
        status_value = FLASH_ProgramOptionBytes_USER4_RDP1(user4_temp, (uint8_t)rdp1_temp);
    }
        
    /* USER0 value write back*/
    if(status_value == FLASH_EOP)
    {
        status_value = FLASH_ProgramOptionBytes_USER0(user0_temp);
    }
    else
    {
    	/* no process*/
    }
    
    /* USER1 value write back*/
    if(status_value == FLASH_EOP)
    {
        status_value = FLASH_ProgramOptionBytes_USER1(user1_temp);
    }
    else
    {
    	/* no process*/
    }
	
    /* USER2 and USER3 value write back*/
    if(status_value == FLASH_EOP)
    {
        status_value = FLASH_ProgramOptionBytes_USER3_USER2(user3_nBOOT0, user3_nBOOT1, user3_nSWBOOT0, user3_BOOT0_CFG, user2_temp);
    }
    else
    {
    	/* no process*/
    }
    
  
    /* DATA0 and DATA1 value write back */
    if(status_value == FLASH_EOP)
    {
        status_value = FLASH_ProgramOptionBytes_DATA1_DATA0((uint8_t)data1_temp, (uint8_t)data0_temp);
    }
    else
    {
    	/* no process*/
    }
    
    
    if(status_value == FLASH_EOP)
    {
        status_value = FLASH_EnWriteProtection(~WP_temp);
    }
    else
    {
    	/* no process*/
    }
    
    if(status_value == FLASH_EOP)
    {
        status_value = FLASH_ProgramOptionBytes_RDP2(FLASH_OB_RDP2_ENABLE);
    }
    else
    {
    	/* no process*/
    }
  
    /* Return the protection operation status_value */
    return status_value;
}


/**
*\*\name   FLASH_GetOptionBytes_User0
*\*\fun    Returns the FLASH User Option Bytes values.
*\*\param  none
*\*\return FlagStatus :
*\*\            - SET      Software watchdog
*\*\            - RESET    Hardware watchdog
**/
FlagStatus FLASH_GetOptionBytes_User0(void)
{
    FlagStatus bit_status;
    if((FLASH->OB  & FLASH_OB_IWDG_SW) != (uint32_t)RESET)
    {
        bit_status = SET;
    }
    else
    {
        bit_status = RESET;
    }
    return bit_status;
}


/**
*\*\name   FLASH_GetOptionBytes_User1
*\*\fun    Returns the FLASH User Option Bytes values.
*\*\param  none
*\*\return FlagStatus :
*\*\            - SET      PF3 used as NRST
*\*\            - RESET    PF3 used as GPIO
**/
FlagStatus FLASH_GetOptionBytes_User1(void)
{
    FlagStatus bit_status;
    if((FLASH->OB & FLASH_OB_NRST_PF3) != (uint32_t)RESET)
    {
        bit_status = SET;
    }
    else
    {
        bit_status = RESET;
    }
    return bit_status;
}


/**
*\*\name   FLASH_GetOptionBytes_User2
*\*\fun    Returns the FLASH Option Bytes PORCNT values.
*\*\param  none
*\*\return PORCNT:
*\*\            - 0x00 to 0xFF.
**/
uint32_t FLASH_GetOptionBytes_User2(void)
{
    /* Return the User Option Byte2 */
    return (uint32_t)((FLASH->OB & FLASH_USER_POR_DELAY_MSK) >> FLASH_USER2_OFFSET);
}


/**
*\*\name   FLASH_GetOptionBytes_User3
*\*\fun    Returns the FLASH User Option Bytes values.
*\*\param  option_byte_bit: (The input parameters must be the following values)
*\*\            - FLASH_OB_NBOOT0_SET          nBOOT0 configuration bit
*\*\            - FLASH_OB_NBOOT1_SET          nBOOT1 configuration bit
*\*\            - FLASH_OB_NSWBOOT0_SET        nSWBOOT0 configuration bit
*\*\            - FLASH_OB_BOOT0_CFG_HIGH      BOOT0_CFG configuration bit
*\*\return FlagStatus :
*\*\            - SET      Enter this mode without resetting
*\*\            - RESET    Enter this mode reset
**/
FlagStatus FLASH_GetOptionBytes_User3(uint32_t option_byte_bit)
{
    FlagStatus bit_status;
    if(((FLASH->OB ) & (option_byte_bit >> FLASH_USER3_OFFSET)) != (uint32_t)RESET)
    {
        bit_status = SET;
    }
    else
    {
        bit_status = RESET;
    }
    return bit_status;
}


/**
*\*\name   FLASH_GetBOOTUartPIN
*\*\fun    Returns the serial communication pins for boot code.
*\*\param  none
*\*\return option_byte_user4:
*\*\         - BOOT_UARTPIN_PA9PA10    BOOT uart pins are PA9 and PA10
*\*\         - BOOT_UARTPIN_PB10PB11   BOOT uart pins are PB10 and PB11
*\*\         - BOOT_UARTPIN_PD10PD11   BOOT uart pins are PD10 and PD11
*\*\         - BOOT_UARTPIN_PA2PA3     BOOT uart pins are PA2 and PA3
**/
uint32_t FLASH_GetBOOTUartPIN(void)
{
    /* Return the User Option Byte6 */
    return (uint32_t)((FLASH->OB & FLASH_OB_BOOTSEL_MASK) >> FLASH_OB_BOOTSEL_OFFSET);
}


/**
*\*\name   FLASH_GetOptionBytes_Data0
*\*\fun    Returns the FLASH User Option Bytes values.
*\*\param  none
*\*\return data0:
*\*\            - 0x00 to 0xFF.
**/
uint32_t FLASH_GetOptionBytes_Data0(void)
{
    /* Return the User Option Byte2 */
    return (uint32_t)((FLASH->OB2 & FLASH_OB_DATA0_MASK));
}


/**
*\*\name   FLASH_GetOptionBytes_Data1
*\*\fun    Returns the FLASH User Option Bytes values.
*\*\param  none
*\*\return data1:
*\*\            - 0x00 to 0xFF.
**/
uint32_t FLASH_GetOptionBytes_Data1(void)
{
    /* Return the User Option Byte2 */
    return (uint32_t)((FLASH->OB2 & FLASH_OB_DATA1_MASK) >> FLASH_OB_DATA1_OFFSET);
}


/**
*\*\name   FLASH_GetReadOutProtectionSTS
*\*\fun    Checks whether the FLASH Read Out Protection L1 status_value is set or not.
*\*\param  none
*\*\return FlagStatus :
*\*\        - SET    Read protection L1 enable
*\*\        - RESET  Read protection L1 disable
**/
FlagStatus FLASH_GetReadOutProtectionSTS(void)
{
    FlagStatus bit_status;
    if ((FLASH->OB & FLASH_RDPRTL1_MSK) != (uint32_t)RESET)
    {
        bit_status = SET;
    }
    else
    {
        bit_status = RESET;
    }
    return bit_status;
}


/**
*\*\name   FLASH_GetReadOutProtectionL2STS
*\*\fun    Checks whether the FLASH Read Out Protection L2 status_value is set or not.
*\*\param  none
*\*\return FlagStatus :
*\*\        - SET    Read protection L2 enable
*\*\        - RESET  Read protection L2 disable
**/
FlagStatus FLASH_GetReadOutProtectionL2STS(void)
{
    FlagStatus readoutstatus;
    if ((FLASH->OB & FLASH_RDPRTL2_MSK) != (uint32_t)RESET)
    {
        readoutstatus = SET;
    }
    else
    {
        readoutstatus = RESET;
    }
    return readoutstatus;
}


/**
*\*\name   FLASH_GetWriteProtectionSTS
*\*\fun    Returns the FLASH Write Protection Option Bytes Register value.
*\*\param  none
*\*\return The FLASH Write Protection  Option Bytes Register value :
*\*\            - Bit15 - Bit0 write-protects pages (120~127) - page (0~7) 
**/
uint32_t FLASH_GetWriteProtectionSTS(void)
{
    /* Return the Flash write protection Register value */
    return (uint32_t)(FLASH->WRP);
}


/**
*\*\name   FLASH_INTConfig
*\*\fun    Enables the specified FLASH interrupts.
*\*\param  FLASH_INT :
*\*\            - FLASH_INT_ERR      FLASH Error Interrupt
*\*\            - FLASH_INT_EOP      FLASH end of operation Interrupt
*\*\param  Cmd:(The input parameters must be the following values)
*\*\            - ENABLE
*\*\            - DISABLE 
*\*\return none
**/
void FLASH_INTConfig(uint32_t FLASH_INT, FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        /* Enable the interrupt sources */
        FLASH->CTRL |= FLASH_INT;
    }
    else
    {
        /* Disable the interrupt sources */
        FLASH->CTRL &= ~(uint32_t)FLASH_INT;
    }
}


/**
*\*\name   FLASH_GetFlagSTS
*\*\fun    Checks whether the specified FLASH flag is set or not.
*\*\param  FLASH_FLAG :(The input parameters must be the following values)
*\*\        - FLASH_FLAG_BUSY      FLASH Busy flag
*\*\        - FLASH_FLAG_PGERR     FLASH Program error flag
*\*\        - FLASH_FLAG_WRPERR    FLASH Write protected error flag
*\*\        - FLASH_FLAG_EOP       FLASH End of Operation flag
*\*\return FlagStatus :
*\*\        - SET      Flag status is set
*\*\        - RESET    Flag status is reset
**/
FlagStatus FLASH_GetFlagSTS(uint32_t FLASH_FLAG)
{
    FlagStatus bit_status;
    if ((FLASH->STS & FLASH_FLAG) != (uint32_t)RESET)
    {
        bit_status = SET;
    }
    else
    {
        bit_status = RESET;
    }
    return bit_status;
}


/**
*\*\name   FLASH_GetOBFlagSTS
*\*\fun    Checks whether the specified FLASH flag is set or not.
*\*\param  FLASH_FLAG :(The input parameters must be the following values)
*\*\        - FLASH_FLAG_OBERR FLASH Option Byte error flag
*\*\return FlagStatus :
*\*\        - SET      Flag status is set
*\*\        - RESET    Flag status is reset
**/
FlagStatus FLASH_GetOBFlagSTS(uint32_t FLASH_FLAG)
{
    FlagStatus bit_status;
    if ((FLASH->OB & FLASH_FLAG) != (uint32_t)RESET)
    {
        bit_status = SET;
    }
    else
    {
        bit_status = RESET;
    }
    return bit_status;
}


/**
*\*\name   FLASH_ClearFlag
*\*\fun    Clears the FLASH's status flags.
*\*\param  FLASH_FLAG :(The input parameters must be the following values)
*\*\        - FLASH_FLAG_PGERR     FLASH Program error flag
*\*\        - FLASH_FLAG_WRPERR    FLASH Write protected error flag
*\*\        - FLASH_FLAG_EOP       FLASH End of Operation flag
*\*\return none
**/
void FLASH_ClearFlag(uint32_t FLASH_FLAG)
{
    /* Clear the flags */
    FLASH->STS = FLASH_FLAG;
}


/**
*\*\name   FLASH_GetSTS
*\*\fun    Returns the FLASH_STS.
*\*\param  none
*\*\return FLASH_STS :
*\*\        - FLASH_BUSY     FLASH is busy
*\*\        - FLASH_ERR_PG   FLASH programming error
*\*\        - FLASH_ERR_WRP  FLASH Write protected error
*\*\        - FLASH_EOP      FLASH End of Operation
**/
FLASH_STS FLASH_GetSTS(void)
{
    FLASH_STS flashstatus;

    if ((FLASH->STS & FLASH_FLAG_BUSY) == FLASH_FLAG_BUSY)
    {
        flashstatus = FLASH_BUSY;
    }
    else
    {
        if ((FLASH->STS & FLASH_FLAG_PGERR) != 0)
        {
            flashstatus = FLASH_ERR_PG;
        }
        else
        {
            if ((FLASH->STS & FLASH_FLAG_WRPERR) != 0)
            {
                flashstatus = FLASH_ERR_WRP;
            }
            else
            {
                flashstatus = FLASH_EOP;
            }
        }
    }

    /* Return the Flash Status */
    return flashstatus;
}


/**
*\*\name   FLASH_WaitForLastOpt
*\*\fun    Waits for a Flash operation to complete or a timeout to occur.
*\*\param  timeout :(The input parameters must be the following values)
*\*\            - EraseTimeout
*\*\            - ProgramTimeout
*\*\return FLASH_STS: The returned value can be: 
*\*\            - FLASH_BUSY     FLASH is busy
*\*\            - FLASH_ERR_PG   FLASH programming error
*\*\            - FLASH_ERR_WRP  FLASH Write protected error
*\*\            - FLASH_EOP      FLASH End of Operation
*\*\            - FLASH_TIMEOUT  FLASH operation timeout
**/
FLASH_STS FLASH_WaitForLastOpt(uint32_t Timeout)
{
    FLASH_STS status;
    uint32_t Timeout_temp;
    Timeout_temp = Timeout;
 
    /* Check for the Flash Status */
    status = FLASH_GetSTS();
    /* Wait for a Flash operation to complete or a TIMEOUT to occur */
    while ((status == FLASH_BUSY) && (Timeout_temp != 0x00))
    {
        status = FLASH_GetSTS();
        Timeout_temp--;
    }
    if (Timeout_temp == 0x00)
    {
        status = FLASH_TIMEOUT;
    }
    /* Return the operation status */
    return status;
}


/**
*\*\name   FLASH_SetVTORAddress
*\*\fun    Set interrupt vector offset address.
*\*\param  VTOR_address :(The input parameters must be the following values)
*\*\            - 0x00000000~0x7FFFFFFF
*\*\param  VTOR_cmd :(The input parameters must be the following values)
*\*\            - FLASH_VTOR_ENABLE
*\*\            - FLASH_VTOR_DISABLE
*\*\return none
**/
void FLASH_SetVTORAddress(uint32_t VTOR_address, uint32_t VTOR_cmd)
{
    /* Set VTOR address */
    FLASH->VTOR = (VTOR_cmd | VTOR_address);
}
