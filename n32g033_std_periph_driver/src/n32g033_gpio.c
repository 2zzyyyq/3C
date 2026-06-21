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
*\*\file n32g033_gpio.c
*\*\author Nsing
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/
#include "n32g033_gpio.h"
#include "n32g033_rcc.h"

      
#define GPIO_MODE                       ((uint32_t)0x00000003)
#define EXTI_MODE                       ((uint32_t)0x10000000)
#define GPIO_MODE_IT                    ((uint32_t)0x00010000)
#define GPIO_MODE_EVT                   ((uint32_t)0x00020000)
#define RISING_EDGE                     ((uint32_t)0x00100000) 
#define FALLING_EDGE                    ((uint32_t)0x00200000)
#define GPIO_OUTPUT_TYPE                ((uint32_t)0x00000010)

/**
 *\*\name   GPIO_DeInit.
 *\*\fun    Reset the GPIOx peripheral registers to their default reset values.
 *\*\param  none
 *\*\return none
 */
void GPIO_DeInit(void)
{
    RCC_EnableAPBPeriphReset(RCC_APB_PERIPH_GPIO);
}

/**
 *\*\name   GPIO_DeInitPin.
 *\*\fun    Deinitializes the GPIOx peripheral registers to their default reset values.
 *\*\param  GPIOx :
 *\*\          - GPIOA
 *\*\          - GPIOB
 *\*\          - GPIOF
 *\*\param  Pin :
 *\*\          - GPIO_PIN_0
 *\*\          - GPIO_PIN_1
 *\*\          - GPIO_PIN_2
 *\*\          - GPIO_PIN_3
 *\*\          - GPIO_PIN_4
 *\*\          - GPIO_PIN_5
 *\*\          - GPIO_PIN_6
 *\*\          - GPIO_PIN_7
 *\*\          - GPIO_PIN_8
 *\*\          - GPIO_PIN_9
 *\*\          - GPIO_PIN_10
 *\*\          - GPIO_PIN_11
 *\*\          - GPIO_PIN_12
 *\*\          - GPIO_PIN_13
 *\*\          - GPIO_PIN_14
 *\*\          - GPIO_PIN_15
 *\*\          - GPIO_PIN_ALL
 *\*\return none
 *\*\note   If IO involves EXTI configuration, the corresponding EXTI line needs to be reset.
 */
void GPIO_DeInitPin(GPIO_Module* GPIOx, uint32_t Pin)
{
    uint32_t pos = 0x00U, currentpin;

    while((Pin >> pos) != 0U)
    {
        /* Get the IO position */
        currentpin = (Pin) & ((uint32_t)1U << pos);

        if(currentpin > 0U)
        {
            /*------------------------- GPIO Mode Configuration --------------------*/
            /* Configure IO Direction in Analog Mode */
            GPIOx->PMODE |= (GPIO_PMODE0 << (pos * 2U));

            /* Configure the default value IO Output Type */
            GPIOx->POTYPE &= ~(GPIO_POTYPE_POT0 << pos);

            /* Deactivate the Pull-up and Pull-down resistor for the current IO */
            GPIOx->PUPD &= ~(GPIO_PUPD0 << (pos * 2U));
            
            /* Configure the default value IO Output */
            GPIOx->POD &= ~(GPIO_POD_POD0 << pos);

             /* Configure the default Alternate Function in current IO */ 
            if((pos & (uint8_t)0x08U) > 0U)
            {
                if((GPIOx == GPIOA) && ((pos == 13U) || (pos == 14U)))
                {
                    /* Configure IO Direction in Alternate Mode */
                    GPIOx->PMODE &= ~(GPIO_PMODE0_3 << (pos * 2U));
                    GPIOx->PMODE |= (GPIO_AF_MODE << (pos * 2U));
                    if(pos==13U)
                    {
                        /* Deactivate the Pull-up and Pull-down resistor for the current IO */
                        GPIOx->PUPD |= (GPIO_PU_MODE << (pos * 2U));
                    }
                    else
                    {
                        /* Deactivate the Pull-up and Pull-down resistor for the current IO */
                        GPIOx->PUPD |= (GPIO_PD_MODE << (pos * 2U));
                    }

                    GPIOx->AFH &= ~((0x0FUL) << ((pos & 0x07U) * 4U)); 
                }
                else
                {
                    GPIOx->AFH |= ((0x0FUL) << ((pos & 0x07U) * 4U));
                } 
            }
            else
            {
                GPIOx->AFL |= ((0x0FUL) << ((pos & 0x07U) * 4U));
            }

            /* Configure the default DS in current IO */
            if((GPIOx == GPIOB) && ((Pin == GPIO_PIN_3) || (Pin == GPIO_PIN_4) || (Pin == GPIO_PIN_5)) )
            {
                if(Pin == GPIO_PIN_3)
                {
                    GPIOx->DS |= 0x108U;    //bit3,bit8
                }
                if(Pin == GPIO_PIN_4)
                {
                    GPIOx->DS |= 0x210U;    //bit4,bit9
                }
                if(Pin == GPIO_PIN_5)
                {
                    GPIOx->DS |= 0x420U;    //bit5,bit10
                }
            
            }
        } 
        pos++;
    }
}


/**
 *\*\name   GPIO_InitPeripheral.
 *\*\fun    Initialize the GPIOx peripheral with the value of the GPIO_InitStruct structure.
 *\*\param  GPIOx :
 *\*\          - GPIOA
 *\*\          - GPIOB
 *\*\          - GPIOF
 *\*\param  GPIO_InitStructure :
 *\*\            - pin
 *\*\               - GPIO_PIN_0
 *\*\               - GPIO_PIN_1
 *\*\               - GPIO_PIN_2
 *\*\               - GPIO_PIN_3
 *\*\               - GPIO_PIN_4
 *\*\               - GPIO_PIN_5
 *\*\               - GPIO_PIN_6
 *\*\               - GPIO_PIN_7
 *\*\               - GPIO_PIN_8
 *\*\               - GPIO_PIN_9
 *\*\               - GPIO_PIN_10
 *\*\               - GPIO_PIN_11
 *\*\               - GPIO_PIN_12
 *\*\               - GPIO_PIN_13
 *\*\               - GPIO_PIN_14
 *\*\               - GPIO_PIN_15
 *\*\               - GPIO_PIN_ALL
 *\*\            - GPIO_Mode
 *\*\               - GPIO_MODE_INPUT
 *\*\               - GPIO_MODE_OUTPUT_PP
 *\*\               - GPIO_MODE_OUTPUT_OD
 *\*\               - GPIO_MODE_AF_PP
 *\*\               - GPIO_MODE_AF_OD
 *\*\               - GPIO_MODE_ANALOG
 *\*\            - GPIO_Pull
 *\*\               - GPIO_NO_PULL
 *\*\               - GPIO_PULL_UP
 *\*\               - GPIO_PULL_DOWN
 *\*\            - GPIO_Alternate
 *\*\               - GPIO_AF0    
 *\*\               - GPIO_AF1 
 *\*\               - GPIO_AF2
 *\*\               - GPIO_AF3
 *\*\               - GPIO_AF4
 *\*\               - GPIO_AF5
 *\*\               - GPIO_AF6
 *\*\               - GPIO_AF7
 *\*\               - GPIO_AF8
 *\*\               - GPIO_AF9
 *\*\               - GPIO_AF10
 *\*\               - GPIO_AF11
 *\*\               - GPIO_AF12
 *\*\               - GPIO_NO_AF            NO alternate Function mapping
 *\*\return none
 *\*\note   PB3/PB4/PB5 can be configured with IO toggle rate and drive capability, 
 *\*\       requiring the call of GPIOB_Driver_Set and GPIOB_SlewRate_Set function.
 */
void GPIO_InitPeripheral(GPIO_Module* GPIOx, GPIO_InitType * GPIO_InitStruct)
{
    uint32_t pos = 0x00U, currentpin;
    uint32_t tmpregister; 

    while(((GPIO_InitStruct->Pin) >> pos) != 0U)
    {
        /* Get the IO position */
        currentpin = (GPIO_InitStruct->Pin) & ((uint32_t)1U << pos);

        if(currentpin > 0U)
        {
            /*--------------------- GPIO Mode Configuration ------------------------*/
            /* In case of Alternate function mode selection */
            if((GPIO_InitStruct->GPIO_Mode == GPIO_MODE_AF_PP) || (GPIO_InitStruct->GPIO_Mode == GPIO_MODE_AF_OD) || ((GPIO_InitStruct->GPIO_Mode == GPIO_MODE_ANALOG) && (GPIO_InitStruct->GPIO_Alternate != GPIO_NO_AF)))
            {
                /* Configure Alternate function mapped with the current IO */
                if((pos & (uint8_t)0x08U) > 0U)
                {
                    tmpregister = GPIOx->AFH;
                    tmpregister &= ~((uint32_t)0xFU << ((uint32_t)(pos & (uint32_t)0x07U) * 4U));
                    tmpregister |= ((uint32_t)(GPIO_InitStruct->GPIO_Alternate) << ((uint32_t)(pos & (uint32_t)0x07U) * 4U)) ;
                    GPIOx->AFH = tmpregister;
                }
                else
                {
                    tmpregister = GPIOx->AFL;
                    tmpregister &= ~((uint32_t)0xFU << ((uint32_t)(pos & (uint32_t)0x07U) * 4U)) ;
                    tmpregister |= ((uint32_t)(GPIO_InitStruct->GPIO_Alternate) << ((uint32_t)(pos & (uint32_t)0x07U) * 4U)) ;
                    GPIOx->AFL = tmpregister;
                }
            }

            /* In case of Output or Alternate function mode selection */
            if ((GPIO_InitStruct->GPIO_Mode == GPIO_MODE_OUTPUT_PP) || (GPIO_InitStruct->GPIO_Mode == GPIO_MODE_OUTPUT_OD)
                 ||(GPIO_InitStruct->GPIO_Mode == GPIO_MODE_AF_PP) || (GPIO_InitStruct->GPIO_Mode == GPIO_MODE_AF_OD))
            {
                /* Configure the IO Output Type */
                tmpregister = GPIOx->POTYPE;
                tmpregister &= ~(GPIO_POTYPE_POT0 << pos);
                tmpregister |= (((GPIO_InitStruct->GPIO_Mode >> 4U) & 0x01U) << pos);
                GPIOx->POTYPE = tmpregister;
            }

            /*---------------------------- GPIO Mode Configuration -----------------------*/
            /* Configure IO Direction mode (Input, Output, Alternate or Analog) */
            tmpregister = GPIOx->PMODE;
            tmpregister &= ~(GPIO_PMODE0 << (pos * 2U));
            tmpregister |= (((GPIO_InitStruct->GPIO_Mode & 0x03U) << (pos * 2U)));
            GPIOx->PMODE = tmpregister;

            /* Configure pull-down mode */
            tmpregister = GPIOx->PUPD;
            tmpregister &= ~(GPIO_PUPD0 << (pos * 2U));
            tmpregister |= (GPIO_InitStruct->GPIO_Pull << (pos * 2U));
            GPIOx->PUPD = tmpregister;
        }
        pos++;      
    }
}


/**
 *\*\name   GPIO_InitStruct.
 *\*\fun    Assign default values to each GPIO_InitType member.
 *\*\param  GPIO_InitStructure :
 *\*\           pointer to GPIO_InitType structure.
 *\*\return none
 */
void GPIO_InitStruct(GPIO_InitType* GPIO_InitStructure)
{
    /* Reset GPIO init structure parameters values */
    GPIO_InitStructure->Pin            = GPIO_PIN_ALL;
    GPIO_InitStructure->GPIO_Alternate = GPIO_NO_AF;
    GPIO_InitStructure->GPIO_Mode      = GPIO_MODE_INPUT;
    GPIO_InitStructure->GPIO_Pull      = GPIO_NO_PULL;
}


/**
 *\*\name   GPIO_ReadInputDataBit.
 *\*\fun    Get the pin status on the specified input port.
 *\*\param  GPIOx :
 *\*\          - GPIOA
 *\*\          - GPIOB
 *\*\          - GPIOF
 *\*\param  Pin :
 *\*\          - GPIO_PIN_0
 *\*\          - GPIO_PIN_1
 *\*\          - GPIO_PIN_2
 *\*\          - GPIO_PIN_3
 *\*\          - GPIO_PIN_4
 *\*\          - GPIO_PIN_5
 *\*\          - GPIO_PIN_6
 *\*\          - GPIO_PIN_7
 *\*\          - GPIO_PIN_8
 *\*\          - GPIO_PIN_9
 *\*\          - GPIO_PIN_10
 *\*\          - GPIO_PIN_11
 *\*\          - GPIO_PIN_12
 *\*\          - GPIO_PIN_13
 *\*\          - GPIO_PIN_14
 *\*\          - GPIO_PIN_15
 *\*\return the pin state on the input port.
 */
uint8_t GPIO_ReadInputDataBit(GPIO_Module* GPIOx, uint16_t Pin)
{
    uint8_t bitstatus;

    if ((GPIOx->PID & Pin) != (uint32_t)Bit_RESET)
    {
        bitstatus = (uint8_t)Bit_SET;
    }
    else
    {
        bitstatus = (uint8_t)Bit_RESET;
    }
    return bitstatus;
}


/**
 *\*\name   GPIO_ReadInputData.
 *\*\fun    Get the input data on the designated GPIO port.
 *\*\param  GPIOx :
 *\*\          - GPIOA
 *\*\          - GPIOB
 *\*\          - GPIOF
 *\*\return the data value on the GPIO input port.
 */
uint16_t GPIO_ReadInputData(GPIO_Module* GPIOx)
{
    return ((uint16_t)GPIOx->PID);
}

/**
 *\*\name   GPIO_ReadOutputDataBit.
 *\*\fun    Get the pin status on the specified output port.
 *\*\param  GPIOx :
 *\*\          - GPIOA
 *\*\          - GPIOB
 *\*\          - GPIOF
 *\*\param  Pin :
 *\*\          - GPIO_PIN_0
 *\*\          - GPIO_PIN_1
 *\*\          - GPIO_PIN_2
 *\*\          - GPIO_PIN_3
 *\*\          - GPIO_PIN_4
 *\*\          - GPIO_PIN_5
 *\*\          - GPIO_PIN_6
 *\*\          - GPIO_PIN_7
 *\*\          - GPIO_PIN_8
 *\*\          - GPIO_PIN_9
 *\*\          - GPIO_PIN_10
 *\*\          - GPIO_PIN_11
 *\*\          - GPIO_PIN_12
 *\*\          - GPIO_PIN_13
 *\*\          - GPIO_PIN_14
 *\*\          - GPIO_PIN_15
 *\*\return the pin state on the output port.
 */
uint8_t GPIO_ReadOutputDataBit(GPIO_Module* GPIOx, uint16_t Pin)
{
    uint8_t bitstatus;

    if ((GPIOx->POD & Pin) != (uint32_t)Bit_RESET)
    {
        bitstatus = (uint8_t)Bit_SET;
    }
    else
    {
        bitstatus = (uint8_t)Bit_RESET;
    }
    return bitstatus;
}

/**
 *\*\name   GPIO_ReadOutputData.
 *\*\fun    Get the output data on the designated GPIO port.
 *\*\param  GPIOx :
 *\*\          - GPIOA
 *\*\          - GPIOB
 *\*\          - GPIOF
 *\*\return the data value on the GPIO output port.
 */
uint16_t GPIO_ReadOutputData(GPIO_Module* GPIOx)
{
    return ((uint16_t)GPIOx->POD);
}

/**
 *\*\name   GPIO_SetBits.
 *\*\fun    Sets the selected data port bits.
 *\*\param  GPIOx :
 *\*\          - GPIOA
 *\*\          - GPIOB
 *\*\          - GPIOF
 *\*\param  Pin :
 *\*\          - GPIO_PIN_0
 *\*\          - GPIO_PIN_1
 *\*\          - GPIO_PIN_2
 *\*\          - GPIO_PIN_3
 *\*\          - GPIO_PIN_4
 *\*\          - GPIO_PIN_5
 *\*\          - GPIO_PIN_6
 *\*\          - GPIO_PIN_7
 *\*\          - GPIO_PIN_8
 *\*\          - GPIO_PIN_9
 *\*\          - GPIO_PIN_10
 *\*\          - GPIO_PIN_11
 *\*\          - GPIO_PIN_12
 *\*\          - GPIO_PIN_13
 *\*\          - GPIO_PIN_14
 *\*\          - GPIO_PIN_15
 *\*\return none
 */
void GPIO_SetBits(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIOx->PBSC = Pin;
}


/**
 *\*\name   GPIO_WritePBSC.
 *\*\fun    Sets the selected data port bits using PBSC.
 *\*\param  GPIOx :
 *\*\          - GPIOA
 *\*\          - GPIOB
 *\*\          - GPIOF
 *\*\param  Pin :
 *\*\          - GPIO_PIN_0
 *\*\          - GPIO_PIN_1
 *\*\          - GPIO_PIN_2
 *\*\          - GPIO_PIN_3
 *\*\          - GPIO_PIN_4
 *\*\          - GPIO_PIN_5
 *\*\          - GPIO_PIN_6
 *\*\          - GPIO_PIN_7
 *\*\          - GPIO_PIN_8
 *\*\          - GPIO_PIN_9
 *\*\          - GPIO_PIN_10
 *\*\          - GPIO_PIN_11
 *\*\          - GPIO_PIN_12
 *\*\          - GPIO_PIN_13
 *\*\          - GPIO_PIN_14
 *\*\          - GPIO_PIN_15
 *\*\param  bitstatus :
 *\*\             - Bit_SET
 *\*\             - Bit_RESET
 *\*\return none
 */
void GPIO_WritePBSC(GPIO_Module* GPIOx, uint16_t Pin,uint8_t bitstatus)
{
    
    if (bitstatus == (uint8_t)Bit_SET)
    {
       GPIOx->PBSC = (uint32_t)Pin;
    }
    else
    {
       GPIOx->PBSC = (((uint32_t)Pin) << 16U);
    }
    
}




/**
 *\*\name   GPIO_ResetBits.
 *\*\fun    Reset the selected data port bits.
 *\*\param  GPIOx :
 *\*\          - GPIOA
 *\*\          - GPIOB
 *\*\          - GPIOF
 *\*\param  Pin :
 *\*\          - GPIO_PIN_0
 *\*\          - GPIO_PIN_1
 *\*\          - GPIO_PIN_2
 *\*\          - GPIO_PIN_3
 *\*\          - GPIO_PIN_4
 *\*\          - GPIO_PIN_5
 *\*\          - GPIO_PIN_6
 *\*\          - GPIO_PIN_7
 *\*\          - GPIO_PIN_8
 *\*\          - GPIO_PIN_9
 *\*\          - GPIO_PIN_10
 *\*\          - GPIO_PIN_11
 *\*\          - GPIO_PIN_12
 *\*\          - GPIO_PIN_13
 *\*\          - GPIO_PIN_14
 *\*\          - GPIO_PIN_15
 *\*\return none
 */
void GPIO_ResetBits(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIOx->PBC = Pin;
}

/**
 *\*\name   GPIO_WriteBit.
 *\*\fun    Reset the selected data port bits.
 *\*\param  GPIOx :
 *\*\          - GPIOA
 *\*\          - GPIOB
 *\*\          - GPIOF
 *\*\param  Pin :
 *\*\          - GPIO_PIN_0
 *\*\          - GPIO_PIN_1
 *\*\          - GPIO_PIN_2
 *\*\          - GPIO_PIN_3
 *\*\          - GPIO_PIN_4
 *\*\          - GPIO_PIN_5
 *\*\          - GPIO_PIN_6
 *\*\          - GPIO_PIN_7
 *\*\          - GPIO_PIN_8
 *\*\          - GPIO_PIN_9
 *\*\          - GPIO_PIN_10
 *\*\          - GPIO_PIN_11
 *\*\          - GPIO_PIN_12
 *\*\          - GPIO_PIN_13
 *\*\          - GPIO_PIN_14
 *\*\          - GPIO_PIN_15
  *\*\param  BitCmd :
 *\*\          - Bit_RESET
 *\*\          - Bit_SET
 *\*\return none
 */
void GPIO_WriteBit(GPIO_Module* GPIOx, uint16_t Pin, Bit_OperateType BitCmd)
{
    if (BitCmd != Bit_RESET)
    {
        GPIOx->PBSC = Pin;
    }
    else
    {
        GPIOx->PBC = Pin;
    }
}

/**
 *\*\name   GPIO_Write.
 *\*\fun    Write data on the designated GPIO data port.
 *\*\param  GPIOx :
 *\*\          - GPIOA
 *\*\          - GPIOB
 *\*\          - GPIOF
 *\*\param  data_value :
 *\*\          the value to be written to the port output data register.
 *\*\          - 0~0xFFFF
 *\*\return none
 */
void GPIO_Write(GPIO_Module* GPIOx, uint16_t data_value)
{
    GPIOx->POD = data_value;
}

/**
 *\*\name   GPIO_TogglePin.
 *\*\fun    Toggle the specified port pin level.
 *\*\param  GPIOx :
 *\*\          - GPIOA
 *\*\          - GPIOB
 *\*\          - GPIOF
 *\*\param  Pin :
 *\*\          - GPIO_PIN_0
 *\*\          - GPIO_PIN_1
 *\*\          - GPIO_PIN_2
 *\*\          - GPIO_PIN_3
 *\*\          - GPIO_PIN_4
 *\*\          - GPIO_PIN_5
 *\*\          - GPIO_PIN_6
 *\*\          - GPIO_PIN_7
 *\*\          - GPIO_PIN_8
 *\*\          - GPIO_PIN_9
 *\*\          - GPIO_PIN_10
 *\*\          - GPIO_PIN_11
 *\*\          - GPIO_PIN_12
 *\*\          - GPIO_PIN_13
 *\*\          - GPIO_PIN_14
 *\*\          - GPIO_PIN_15
 *\*\return none
 */
void GPIO_TogglePin(GPIO_Module *GPIOx, uint16_t Pin)
{
    GPIOx->POD ^= Pin;
}

/**
 *\*\name   GPIO_ConfigPinLock.
 *\*\fun    GPIO port lock register configuration.
 *\*\param  GPIOx :
 *\*\          - GPIOA
 *\*\          - GPIOB
 *\*\          - GPIOF
 *\*\param  Pin :
 *\*\          - GPIO_PIN_0
 *\*\          - GPIO_PIN_1
 *\*\          - GPIO_PIN_2
 *\*\          - GPIO_PIN_3
 *\*\          - GPIO_PIN_4
 *\*\          - GPIO_PIN_5
 *\*\          - GPIO_PIN_6
 *\*\          - GPIO_PIN_7
 *\*\          - GPIO_PIN_8
 *\*\          - GPIO_PIN_9
 *\*\          - GPIO_PIN_10
 *\*\          - GPIO_PIN_11
 *\*\          - GPIO_PIN_12
 *\*\          - GPIO_PIN_13
 *\*\          - GPIO_PIN_14
 *\*\          - GPIO_PIN_15
 *\*\return none
 */
void GPIO_ConfigPinLock(GPIO_Module* GPIOx, uint16_t Pin)
{
    uint32_t tmp = 0x00010000;

    tmp |= Pin;
    /* Set LCKK bit */
    GPIOx->PLOCK = tmp;
    /* Reset LCKK bit */
    GPIOx->PLOCK = Pin;
    /* Set LCKK bit */
    GPIOx->PLOCK = tmp;
    /* Read LCKK bit*/
    GPIOx->PLOCK;
    /* Read LCKK bit*/
    GPIOx->PLOCK;
}


/**
 *\*\name   GPIO_ConfigEXTILine.
 *\*\fun    Selects the GPIO pin used as EXTI Line. A single EXTI line can only be configured with a single pin.
 *\*\param  PortSource :
 *\*\          - GPIOA_PORT_SOURCE
 *\*\          - GPIOB_PORT_SOURCE
 *\*\          - GPIOF_PORT_SOURCE
 *\*\param  PinSource :
 *\*\          - GPIO_PIN_SOURCE0
 *\*\          - GPIO_PIN_SOURCE1
 *\*\          - GPIO_PIN_SOURCE2
 *\*\          - GPIO_PIN_SOURCE3
 *\*\          - GPIO_PIN_SOURCE4
 *\*\          - GPIO_PIN_SOURCE5
 *\*\          - GPIO_PIN_SOURCE6
 *\*\          - GPIO_PIN_SOURCE7
 *\*\          - GPIO_PIN_SOURCE8
 *\*\          - GPIO_PIN_SOURCE9
 *\*\          - GPIO_PIN_SOURCE10
 *\*\          - GPIO_PIN_SOURCE11
 *\*\          - GPIO_PIN_SOURCE12
 *\*\          - GPIO_PIN_SOURCE13
 *\*\          - GPIO_PIN_SOURCE14
 *\*\          - GPIO_PIN_SOURCE15
 *\*\return none
 */
void GPIO_ConfigEXTILine(uint8_t PortSource, uint8_t PinSource)
{
    uint32_t Port_value; 
    uint32_t Pin_value; 
    GPIO_Module *GPIOx;

    /*Get Peripheral point*/
    GPIOx = GPIO_GET_PERIPH(PortSource);
    
    Port_value = PinSource/(AFIO_EXTI_CFGBITWIDTH);
    Pin_value = PinSource%(AFIO_EXTI_CFGBITWIDTH);
    if(GPIOx == GPIOA)
    {
        AFIO->EXTI_CFG[PortSource] &= (~(AFIO_EXTI_CFGAMASK<<(Port_value*AFIO_EXTI_CFGBITWIDTH)));
        AFIO->EXTI_CFG[PortSource] |= (Pin_value<<(Port_value*AFIO_EXTI_CFGBITWIDTH));
    }
    else if(GPIOx == GPIOB)
    {
        if(PinSource<AFIO_EXTI_CFGBITWIDTH)
        {
            AFIO->EXTI_CFG[PortSource] &= (~AFIO_EXTI_CFGAMASK);
            AFIO->EXTI_CFG[PortSource] |= Pin_value;
        }
        else
        {
            AFIO->EXTI_CFG[PortSource] &= (~AFIO_EXTI_CFGBMASK);
            AFIO->EXTI_CFG[PortSource] |= (Pin_value << AFIO_EXTI_CFGBITWIDTH);
        }
        if(PinSource == GPIO_PIN_SOURCE8)
        {
            AFIO->EXTI_CFG[PortSource] &= (~AFIO_EXTI_CFGBMASK);
            AFIO->EXTI_CFG[PortSource] |=  0x40U;
        }
    }
    else if(GPIOx == GPIOF)
    {
        AFIO->EXTI_CFG[1] &= (~AFIO_EXTI_CFG2_EXTI6);
        AFIO->EXTI_CFG[1] |= (Pin_value << AFIO_EXTI6_OFFSET);
    }
    else
    {
        /* nothing */
    }
}

/**
 *\*\name   GPIO_ClearEXTILine.
 *\*\fun    Clear the GPIO pin used as EXTI Line.
 *\*\param  LineSource :
 *\*\          - GPIO_EXTILINE_SOURCE0
 *\*\          - GPIO_EXTILINE_SOURCE1
 *\*\          - GPIO_EXTILINE_SOURCE2
 *\*\          - GPIO_EXTILINE_SOURCE3
 *\*\          - GPIO_EXTILINE_SOURCE4
 *\*\          - GPIO_EXTILINE_SOURCE5
 *\*\          - GPIO_EXTILINE_SOURCE6
 *\*\return none
 */
void GPIO_ClearEXTILine( uint8_t LineSource)
{
    AFIO->EXTI_CFG[(LineSource >> 0x02)] |= (AFIO_EXTI_CFGAMASK << ((LineSource & 0x03U) * 4U));
}

/**
 *\*\name   AFIO_ConfigIOFlitNum.
 *\*\fun    Configure IO filter number in APB clock.
 *\*\param  Cmd :
 *\*\          - ENABLE
 *\*\          - DISABLE
 *\*\return none
 */
void AFIO_ConfigEXTIFlitEN(FunctionalState Cmd)
{
    if(Cmd == ENABLE)
    {
        AFIO->CFG |= AFIO_EXTI_FILTEN;
    }
    else
    {
        AFIO->CFG &= (~AFIO_EXTI_FILTEN);
    }
}

/**
 *\*\name   GPIO_ConfigPinRemap.
 *\*\fun    Pin remapping configuration.
 *\*\param  PortSource :
 *\*\          - GPIOA_PORT_SOURCE
 *\*\          - GPIOB_PORT_SOURCE
 *\*\          - GPIOF_PORT_SOURCE
 *\*\param  PinSource :
 *\*\          - GPIO_PIN_SOURCE0
 *\*\          - GPIO_PIN_SOURCE1
 *\*\          - GPIO_PIN_SOURCE2
 *\*\          - GPIO_PIN_SOURCE3
 *\*\          - GPIO_PIN_SOURCE4
 *\*\          - GPIO_PIN_SOURCE5
 *\*\          - GPIO_PIN_SOURCE6
 *\*\          - GPIO_PIN_SOURCE7
 *\*\          - GPIO_PIN_SOURCE8
 *\*\          - GPIO_PIN_SOURCE9
 *\*\          - GPIO_PIN_SOURCE10
 *\*\          - GPIO_PIN_SOURCE11
 *\*\          - GPIO_PIN_SOURCE12
 *\*\          - GPIO_PIN_SOURCE13
 *\*\          - GPIO_PIN_SOURCE14
 *\*\          - GPIO_PIN_SOURCE15
 *\*\param  AlternateFunction :
 *\*\          - GPIO_AF0    
 *\*\          - GPIO_AF1 
 *\*\          - GPIO_AF2
 *\*\          - GPIO_AF3
 *\*\          - GPIO_AF4
 *\*\          - GPIO_AF5
 *\*\          - GPIO_AF6
 *\*\          - GPIO_AF7
 *\*\          - GPIO_AF8
 *\*\          - GPIO_AF9
 *\*\          - GPIO_AF10
 *\*\          - GPIO_AF11
 *\*\          - GPIO_AF12
 *\*\          - GPIO_NO_AF            NO alternate Function mapping
 *\*\return none
 */
void GPIO_ConfigPinRemap(uint8_t PortSource, uint8_t PinSource, uint32_t AlternateFunction)
{
    uint8_t temp_value; 
    uint32_t tmpregister;
    GPIO_Module *GPIOx;

    /*Get Peripheral point*/
    GPIOx = GPIO_GET_PERIPH(PortSource);
    /*  */
     if((PinSource & (uint8_t)0x08) > 0)
    {
        temp_value = (PinSource & (uint8_t)0x07);
        /*Read GPIO_AFH register*/
        tmpregister  = GPIOx->AFH;
        /*Reset corresponding bits*/
        tmpregister &=~((uint32_t)0x0F <<(temp_value*4U));
        /*Set corresponding bits*/
        tmpregister |= ((uint32_t)(AlternateFunction) << (temp_value * 4U));
        /*Write to the GPIO_AFH register*/
        GPIOx->AFH = tmpregister;
    }
    else
    {
        temp_value = (PinSource & (uint8_t)0x07);
        /*Read GPIO_AFL register*/
        tmpregister  = GPIOx->AFL;
        /*Reset corresponding bits*/
        tmpregister &=~((uint32_t)0x0F <<(temp_value*4U));
        /*Set corresponding bits*/
        tmpregister |= ((uint32_t)(AlternateFunction) << (temp_value * 4U));
        /*Write to the GPIO_AFL register*/
        GPIOx->AFL = tmpregister;
    }
}


/**
 *\*\name   AFIO_ConfigADCExternalTrigRemap.
 *\*\fun    Configurate ADC external trigger.
 *\*\param  ADC_trigger : 
 *\*\          specifies the external trigger line be configured.
 *\*\          - AFIO_ADC_TRIG_EXTI_0
 *\*\          - AFIO_ADC_TRIG_EXTI_1
 *\*\          - AFIO_ADC_TRIG_EXTI_2
 *\*\          - AFIO_ADC_TRIG_EXTI_3
 *\*\          - AFIO_ADC_TRIG_EXTI_4
 *\*\          - AFIO_ADC_TRIG_EXTI_5
 *\*\          - AFIO_ADC_TRIG_EXTI_6
 *\*\return none
 */
void AFIO_ConfigADCExternalTrigRemap(AFIO_ADC_Trig_RemapType ADC_trigger)
{
    uint32_t tmpregister;
    uint32_t temp_value = (uint32_t)ADC_trigger;

    tmpregister = AFIO->CFG;
    
    /* clear AFIO_CFG register ETRR bit */
    tmpregister &= (~(AFIO_CFG_EXTI_ETRR));

    /* select which external line is connected*/
    tmpregister |= (temp_value << REG_BIT11_OFFSET);
    
    AFIO->CFG = tmpregister;
}


/**
 *\*\name   AFIO_ConfigSPINSSMode.
 *\*\fun    Selects the alternate function SPIx NSS mode.
 *\*\param  AFIO_SPIx_NSS : 
 *\*\          choose which SPI configuration.
 *\*\          - AFIO_SPI1_NSS
 *\*\          - AFIO_SPI2_NSS
 *\*\param  SpiNssMode : 
 *\*\          specifies the SPI_NSS mode to be configured.
 *\*\          - AFIO_SPI_NSS_HIGH_IMPEDANCE
 *\*\          - AFIO_SPI_NSS_High_LEVEL
 *\*\return none
 */
void AFIO_ConfigSPINSSMode(uint32_t AFIO_SPIx_NSS, uint32_t SpiNssMode)
{
    uint32_t tmpregister;

    tmpregister = AFIO->CFG;
    if(SpiNssMode != AFIO_SPI_NSS_HIGH_IMPEDANCE)
    {
        tmpregister |= AFIO_SPIx_NSS;
    }
    else 
    {
        tmpregister &= ~AFIO_SPIx_NSS;
    }
    AFIO->CFG = tmpregister;
}


/**
 *\*\name   AFIO_ConfigIOFlitNum.
 *\*\fun    Configure IO filter number in APB clock.
 *\*\param  Flit_Num : 
 *\*\        - 0~7
 *\*\return none
 */
void AFIO_ConfigIOFlitNum(uint8_t Flit_Num)
{
    uint32_t temp_value;

    temp_value = AFIO->CFG;
    
    temp_value &= ~AFIO_CFG_IOFILTCFG;

    AFIO->CFG = (temp_value | Flit_Num);
}



/**
 *\*\name   AFIO_DIGEFTEnable.
 *\*\fun    Enables or disable digital EFT of port pins.
 *\*\param  PortSource :
 *\*\          - GPIOA_PORT_SOURCE
 *\*\          - GPIOB_PORT_SOURCE
 *\*\          - GPIOF_PORT_SOURCE
 *\*\param  Pin :
 *\*\          - GPIO_PIN_0
 *\*\          - GPIO_PIN_1
 *\*\          - GPIO_PIN_2
 *\*\          - GPIO_PIN_3
 *\*\          - GPIO_PIN_4
 *\*\          - GPIO_PIN_5
 *\*\          - GPIO_PIN_6
 *\*\          - GPIO_PIN_7
 *\*\          - GPIO_PIN_8
 *\*\          - GPIO_PIN_9
 *\*\          - GPIO_PIN_10
 *\*\          - GPIO_PIN_11
 *\*\          - GPIO_PIN_12
 *\*\          - GPIO_PIN_13
 *\*\          - GPIO_PIN_14
 *\*\          - GPIO_PIN_15
 *\*\          - GPIO_PIN_ALL
 *\*\param  Cmd :
 *\*\          - ENABLE
 *\*\          - DISABLE
 *\*\return none
 */
void AFIO_DIGEFTEnable(uint8_t PortSource, uint16_t Pin, FunctionalState Cmd)
{
    if(PortSource == GPIOA_PORT_SOURCE)
    {
        if(Cmd == ENABLE)
        {
            AFIO->DIGEFT_CFG1 |= Pin;
        }
        else
        {
            AFIO->DIGEFT_CFG1 &= (~Pin);
        }
    }
    else if(PortSource == GPIOB_PORT_SOURCE)
    {
        if(Cmd == ENABLE)
        {
            AFIO->DIGEFT_CFG2 |= Pin;
        }
        else
        {
            AFIO->DIGEFT_CFG2 &= (~Pin);
        }
    }
    else if(PortSource == GPIOF_PORT_SOURCE)
    {
        if(Cmd == ENABLE)
        {
            AFIO->DIGEFT_CFG3 |= Pin;
        }
        else
        {
            AFIO->DIGEFT_CFG3 &= (~Pin);
        }
    }
    else
    {
        /* nothing */
    }
}

/**
 *\*\name   GPIOB_Driver_Set.
 *\*\fun    GPIOB driver configuration.
 *\*\param  current 
 *\*\          - GPIOB_HIGH_DREIVE
 *\*\          - GPIOB_LOW_DREIVE
 *\*\param  GPIO_Pin
 *\*\          - GPIO_PIN_3
 *\*\          - GPIO_PIN_4
 *\*\          - GPIO_PIN_5 
 *\*\return none
 */ 
void GPIOB_Driver_Set(uint32_t current, uint32_t GPIO_Pin)
{
    uint32_t temp_value;
    temp_value = GPIOB->DS;
    temp_value &= (~GPIO_Pin);
    if(current == GPIOB_LOW_DREIVE)
    {
        temp_value |= GPIO_Pin;
    }
    else
    {
        /* no process */
    }
    GPIOB->DS = temp_value;
}

/**
 *\*\name   GPIOB_SlewRate_Set.
 *\*\fun    GPIOB slew rate configuration.
 *\*\param  slew_rate
 *\*\          - GPIOB_SLEW_RATE_FAST
 *\*\          - GPIOB_SLEW_RATE_SLOW
 *\*\param  GPIO_Pin
 *\*\          - GPIO_PIN_3
 *\*\          - GPIO_PIN_4
 *\*\          - GPIO_PIN_5 
 *\*\return none
 */
void GPIOB_SlewRate_Set(uint32_t slew_rate, uint32_t GPIO_Pin)
{
    uint32_t temp_value;
    temp_value = GPIOB->DS;
    temp_value &= (~(GPIO_Pin << REG_BIT5_OFFSET));
    if(slew_rate == GPIOB_SLEW_RATE_SLOW)
    {
        temp_value |= (GPIO_Pin << REG_BIT5_OFFSET);
    }
    else
    {
        /* no process */
    }
    GPIOB->DS = temp_value;
}

