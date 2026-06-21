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
*\*\file n32g033_adc.c
*\*\author Nsing 
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/


#include "n32g033_adc.h"
#include "n32g033_rcc.h"


/**
*\*\name    ADC_DeInit.
*\*\fun     Reset the ADC registers.
*\*\return  none
**/
void ADC_DeInit(void)
{
    RCC_EnableAHBPeriphReset(RCC_AHB_PERIPH_ADC);
}

/**
*\*\name    ADC_Init.
*\*\fun     Initializes the ADC according to ADC_initstruct.
*\*\param   ADC_initstruct :
*\*\          - ContinueConvEn
*\*\            - DISABLE
*\*\            - ENABLE
*\*\          - ExtTrigSelect1/ExtTrigSelect2/ExtTrigSelect3/ExtTrigSelect4
*\*\            - ADC_EXT_TRIGCONV_T1_CC1                
*\*\            - ADC_EXT_TRIGCONV_T1_CC2                
*\*\            - ADC_EXT_TRIGCONV_T1_CC3                
*\*\            - ADC_EXT_TRIGCONV_T1_CC4                
*\*\            - ADC_EXT_TRIGCONV_T1_CC5               
*\*\            - ADC_EXT_TRIGCONV_T1_CC6                
*\*\            - ADC_EXT_TRIGCONV_T1_CC7   
*\*\            - ADC_EXT_TRIGCONV_T1_TRGO  
*\*\            - ADC_EXT_TRIGCONV_T3_CC1                
*\*\            - ADC_EXT_TRIGCONV_T3_CC2  
*\*\            - ADC_EXT_TRIGCONV_T3_TRGO                
*\*\            - ADC_EXT_TRIGCONV_T4_CC1 
*\*\            - ADC_EXT_TRIGCONV_T4_CC2                
*\*\            - ADC_EXT_TRIGCONV_T4_TRGO  
*\*\            - ADC_EXT_TRIGCONV_EXT_LINE   
*\*\            - ADC_EXT_TRIGCONV_SWSTRRCH              
*\*\          - DatAlign
*\*\            - ADC_DAT_ALIGN_R
*\*\            - ADC_DAT_ALIGN_L
*\*\          - PhsMode
*\*\            - ADC_PHS_TRG_MODE_SINGLE
*\*\            - ADC_PHS_TRG_MODE_TWO
*\*\            - ADC_PHS_TRG_MODE_THREE
*\*\            - ADC_PHS_TRG_MODE_FOUR
*\*\          - Phs1ChNumber
*\*\            - 1-10
*\*\          - Phs2ChNumber
*\*\            - 1-10
*\*\          - Phs3ChNumber
*\*\            - 1-10
*\*\          - Phs4ChNumber
*\*\            - 1-10
*\*\return  none
**/
void ADC_Init(ADC_InitType* ADC_initstruct)
{
    __IO  uint32_t tmpreg1 = 0;
    /* Get the ADC CTRL2 value */
    tmpreg1 = ADC->CTRL2;
    /* Clear CTU and ALIGN bits */
    tmpreg1 &= ~(ADC_CTRL2_CTU | ADC_CTRL2_ALIG) ;
    tmpreg1 |= (uint32_t)(((uint32_t)ADC_initstruct->ContinueConvEn << 1) | ((uint32_t)ADC_initstruct->DatAlign));
    /* Write to ADC CTRL2 */
    ADC->CTRL2 = tmpreg1;
    /* Get the ADC TRIG value */
    tmpreg1 = ADC->TRIGSEL;
    /* Clear EXTSEL1,EXTSEL2,EXTSEL3,EXTSEL4, EXTRTRIG, and TimxEN bits */
    tmpreg1 &= ADC_EXT_TRIGCONV_MASK ;
    tmpreg1 |= (uint32_t)((ADC_initstruct->ExtTrigSelect1&ADC_EXT_TRIG_MASK)          | (ADC_initstruct->ExtTrigSelect1&ADC_EXT_TRIG_EN_MASK) | 
                          ((ADC_initstruct->ExtTrigSelect2&ADC_EXT_TRIG_MASK) << 4U)  | (ADC_initstruct->ExtTrigSelect2&ADC_EXT_TRIG_EN_MASK) | 
                          ((ADC_initstruct->ExtTrigSelect3&ADC_EXT_TRIG_MASK) << 8U)  | (ADC_initstruct->ExtTrigSelect3&ADC_EXT_TRIG_EN_MASK) |
                          ((ADC_initstruct->ExtTrigSelect4&ADC_EXT_TRIG_MASK) << 12U) | (ADC_initstruct->ExtTrigSelect4&ADC_EXT_TRIG_EN_MASK) );	
    /* Write to ADC TRIG */
    ADC->TRIGSEL = tmpreg1;	
    /* Get the ADC PHCFG value */
    tmpreg1 = ADC->PHCFG;	
    /* Clear EXTSEL1,EXTSEL2,EXTSEL3,EXTSEL4, EXTRTRIG, and TimxEN bits */
    tmpreg1 &= ADC_PHS_TRG_CONFIG_MASK ;
    tmpreg1 |= (uint32_t)( (ADC_initstruct->Phs1ChNumber - 1U )      | ((ADC_initstruct->Phs2ChNumber - 1U) << 4U) | 
                           ((ADC_initstruct->Phs3ChNumber - 1U)<< 8U)| ((ADC_initstruct->Phs4ChNumber - 1U) << 12U) |  
                           (ADC_initstruct->PhsMode) );	
    /* Write to ADC PHCFG */
    ADC->PHCFG = tmpreg1;
}


/**
*\*\name    ADC_InitStruct.
*\*\fun     Fills each ADC_initstruct member with its default value.
*\*\param   ADC_initstruct :
*\*\          - ContinueConvEn
*\*\          - ExtTrigSelect
*\*\          - DatAlign
*\*\return  none
**/
void ADC_InitStruct(ADC_InitType* ADC_initstruct)
{
    /* Reset ADC init structure parameters values */
    /* Initialize the ContinueConvEn member */
    ADC_initstruct->ContinueConvEn = DISABLE;
    /* Initialize the ExtTrigSelect4 member */
    ADC_initstruct->ExtTrigSelect4  = ADC_EXT_TRIGCONV_T1_TRGO;
    /* Initialize the ExtTrigSelect3 member */
    ADC_initstruct->ExtTrigSelect3  = ADC_EXT_TRIGCONV_T1_TRGO;	
    /* Initialize the ExtTrigSelect2 member */
    ADC_initstruct->ExtTrigSelect2  = ADC_EXT_TRIGCONV_T1_TRGO;		
    /* Initialize the ExtTrigSelect1 member */
    ADC_initstruct->ExtTrigSelect1  = ADC_EXT_TRIGCONV_T1_TRGO;		
    /* Initialize the DatAlign member */
    ADC_initstruct->DatAlign       = ADC_DAT_ALIGN_R;
    /* Initialize the phase mode member */
    ADC_initstruct->PhsMode        = ADC_PHS_TRG_MODE_SINGLE ;
    /* Initialize the phase 1 channel number member */
    ADC_initstruct->Phs1ChNumber      = 1U;
    /* Initialize the phase 2 channel number member */
    ADC_initstruct->Phs2ChNumber      = 1U;
    /* Initialize the phase 3 channel number member */
    ADC_initstruct->Phs3ChNumber      = 1U;
    /* Initialize the phase 4 channel number member */
    ADC_initstruct->Phs4ChNumber      = 1U;
}

/**
*\*\name    ADC_Enable.
*\*\fun     Enables or disables ADC peripheral.
*\*\param   Cmd : new state of the ADC peripheral.
*\*\          -ENABLE 
*\*\          -DISABLE
*\*\return  none
**/
void ADC_Enable(FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        /* Set the AD_ON bit to wake up the ADC from power down mode */
         ADC->CTRL2 |= ADC_ON;
    }
    else
    {
        /* Disable the selected ADC peripheral */
        ADC->CTRL2 &= (~ADC_ON);
    }
}

/**
*\*\name    ADC_ConfigInt.
*\*\fun     Config ADC interrupts.
*\*\param   ADC_IT:
*\*\          - ADC_INT_AWD      
*\*\          - ADC_INT_ENDCA  
*\*\          - ADC_INT_ENDC   
*\*\          - ADC_INT_PHS4   
*\*\          - ADC_INT_PHS3   
*\*\          - ADC_INT_PHS2   
*\*\          - ADC_INT_PHS1    
*\*\param   Cmd : new state of the ADC peripheral.
*\*\          -ENABLE 
*\*\          -DISABLE
*\*\return  none
**/
void ADC_ConfigInt(uint16_t ADC_IT, FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        ADC->CTRL1 |= ADC_IT;   
    }
    else
    {
        ADC->CTRL1 &= (~ADC_IT);
    }
}

/**
*\*\name    ADC_EnableSoftwareTrig.
*\*\fun     Enables or disables software trigger.
*\*\param   Cmd : new state of the ADC peripheral.
*\*\          -ENABLE 
*\*\          -DISABLE
*\*\return  none:
**/
void ADC_EnableSoftwareTrig(FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
         /* Enable the ADC software trigger conversion mode  */
        ADC->TRIGSEL |= ADC_SWTRIG_ENABLE;
    }
    else
    {
         /* Disable the ADC software trigger conversion mode  */
        ADC->TRIGSEL &= (~ADC_SWTRIG_ENABLE);
    }
}    
/**
*\*\name    ADC_EnableExternalLineTrig.
*\*\fun     Enables or disables exti line trigger.
*\*\param   Cmd : new state of the ADC peripheral.
*\*\          -ENABLE 
*\*\          -DISABLE
*\*\return  none:
**/
void ADC_EnableExternalLineTrig(FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
         /* Enable the ADC external trigger conversion mode  */
        ADC->TRIGSEL |= ADC_EXT_LINE_TRIGCONV_ENABLE;
    }
    else
    {
         /* Disable the ADC external trigger conversion mode  */
        ADC->TRIGSEL &= (~ADC_EXT_LINE_TRIGCONV_ENABLE);
    }
}    
/**
*\*\name    ADC_GetSoftwareTrigStatus.
*\*\fun     Get ADC software trigger conversion status.
*\*\param   none
*\*\return  FlagStatus:
*\*\          - SET
*\*\          - RESET
**/
FlagStatus ADC_GetSoftwareTrigStatus(void)
{
    FlagStatus bitstatus;

    /* Check the status of SOFT_START bit */
    if ((ADC->TRIGSEL & ADC_SWTRIG_ENABLE) != (uint32_t)RESET)
    {
        /* SOFT_START bit is set */
        bitstatus = SET;
    }
    else
    {
        /* SOFT_START bit is reset */
        bitstatus = RESET;
    }
    /* Return the SOFT_START bit status */
    return bitstatus;
}    

/**
*\*\name    ADC_GetExtiLineTrigStatus.
*\*\fun     Get ADC exti line trigger conversion status.
*\*\param   none
*\*\return  FlagStatus:
*\*\          - SET
*\*\          - RESET
**/
FlagStatus ADC_GetExtiLineTrigStatus(void)
{
    FlagStatus bitstatus;

    /* Check the status of exti line bit */
    if ((ADC->TRIGSEL & ADC_EXT_LINE_TRIGCONV_ENABLE) != (uint32_t)RESET)
    {
        /* exti line bit is set */
        bitstatus = SET;
    }
    else
    {
        /* exti line bit is reset */
        bitstatus = RESET;
    }
    /* Return the exti line bit status */
    return bitstatus;
}    


/**
*\*\name    ADC_GetDat.
*\*\fun     Get ADC conversion data.
*\*\return  ADC group conversion data.
**/
uint16_t ADC_GetDat(void)
{
    /* Return the conversion value */
    return (uint16_t)ADC->DAT0;
	
}
/**
*\*\name    ADC_GetGroupConvDat.
*\*\fun     Get ADC group conversion data.
*\*\param   number :
*\*\          - 0~9
*\*\return  ADC group conversion data.
**/
uint16_t ADC_GetGroupConvDat(uint8_t number)
{
    /* Return the conversion value */
    return (uint16_t)ADC_DATA_REG_READ(ADC->DAT0,(uint32_t)number);
}

/**
*\*\name    ADC_ConfigAnalogWatchdogModeChannel.
*\*\fun     Configures ADC analog watchdog monitor.
*\*\param   channel :
*\*\          - ADC_ANALOG_WTDG_DAT0
*\*\          - ADC_ANALOG_WTDG_DAT1
*\*\          - ADC_ANALOG_WTDG_DAT2
*\*\          - ADC_ANALOG_WTDG_DAT3
*\*\          - ADC_ANALOG_WTDG_DAT4
*\*\          - ADC_ANALOG_WTDG_DAT5
*\*\          - ADC_ANALOG_WTDG_DAT6
*\*\          - ADC_ANALOG_WTDG_DAT7
*\*\          - ADC_ANALOG_WTDG_DAT8
*\*\          - ADC_ANALOG_WTDG_DAT9
*\*\return  none
**/
void ADC_ConfigAnalogWatchdogModeChannel(uint16_t channel)
{
    uint32_t temp ;
    temp = ADC->AWDEN;
    /* Clear ADC analog watchdog single mode channel */
    temp &= ADC_ANALOG_WTDG_DAT_MASK;
    /* Select ADC analog watchdog single mode channel */
    temp |= (uint32_t)channel;
    ADC->AWDEN = temp;
}

/**
*\*\name    ADC_Analog_Watchdog_HighThresholds_Config.
*\*\fun     Configures the high thresholds of the analog watchdog.
*\*\param   HighThreshold : 12bit high thresholds value(0 ~ 0xFFF)
*\*\param   LowThreshold : 12bit low thresholds value(0 ~ 0xFFF)
*\*\return  none
**/
void ADC_ConfigAnalogWatchdogThresholds(uint16_t HighThreshold, uint16_t LowThreshold)
{
    /* Set the ADC high threshold */
    ADC->AWDHIGH = HighThreshold;
    /* Set the ADC low threshold */
    ADC->AWDLOW = LowThreshold;
}


/**
*\*\name    ADC_GetFlagStatus.
*\*\fun     Get ADC flag Status.
*\*\param   ADC_FLAG :
*\*\          - ADC_FLAG_RDY            : ADC ready flag
*\*\          - ADC_FLAG_PD_RDY           ADC powerdown ready flag
*\*\          - ADC_FLAG_BUF_RDY        : VREFBUF ready flag
*\*\          - ADC_FLAG_AWDG
*\*\          - ADC_FLAG_ENDC
*\*\          - ADC_FLAG_ENDCA
*\*\          - ADC_FLAG_STR  
*\*\          - ADC_FLAG_PHS4
*\*\          - ADC_FLAG_PHS3
*\*\          - ADC_FLAG_PHS2
*\*\          - ADC_FLAG_PHS1
*\*\return  SET or RESET
**/
FlagStatus ADC_GetFlagStatus(uint16_t ADC_FLAG)
{
    /* Check the status of ADC flag */
    if ((ADC->STS & ADC_FLAG) != (uint16_t)RESET)
    {
        /* ADC_FLAG is set */
        return SET;
    }
    else
    {
        /* ADC_FLAG is reset */
        return RESET;
    }
}

/**
*\*\name    ADC_ClearFlag.
*\*\fun     Clear ADC flag Status.
*\*\param   ADC_FLAG : 
*\*\          - ADC_FLAG_AWDG
*\*\          - ADC_FLAG_ENDC
*\*\          - ADC_FLAG_ENDCA
*\*\          - ADC_FLAG_STR
*\*\          - ADC_FLAG_PHS4
*\*\          - ADC_FLAG_PHS3
*\*\          - ADC_FLAG_PHS2
*\*\          - ADC_FLAG_PHS1
*\*\return  none
**/
void ADC_ClearFlag(uint16_t ADC_FLAG)
{
    /* Clear the selected ADC flags */
    ADC->STS = (uint32_t)(ADC_FLAG & (uint32_t)ADC_FLAG_ALL);
}

/**
*\*\name    ADC_GetIntStatus.
*\*\fun     Get ADC Interrupt Status.
*\*\param   ADC_IT :
*\*\          - ADC_INT_FLAG_AWDG
*\*\          - ADC_INT_FLAG_ENDC
*\*\          - ADC_INT_FLAG_ENDCA  
*\*\          - ADC_INT_FLAG_PHS4
*\*\          - ADC_INT_FLAG_PHS3
*\*\          - ADC_INT_FLAG_PHS2
*\*\          - ADC_INT_FLAG_PHS1
*\*\return  SET or RESET
**/
INTStatus ADC_GetIntStatus(uint16_t ADC_IT)
{
    FlagStatus bitstatus  ;
    if ((ADC->STS & ADC_IT) != (uint8_t)RESET)
    {
        /* ADC_INT_FLAG is set */
        bitstatus = SET;
    }
    else
    {
        /* ADC_INT_FLAG is reset */
        bitstatus = RESET;
    }
    return bitstatus;
}
/**
*\*\name    ADC_ClearFlag.
*\*\fun     Clear ADC flag Status.
*\*\param   ADC_IT :
*\*\          - ADC_INT_FLAG_AWDG
*\*\          - ADC_INT_FLAG_ENDC
*\*\          - ADC_INT_FLAG_ENDCA
*\*\          - ADC_INT_FLAG_PHS4
*\*\          - ADC_INT_FLAG_PHS3
*\*\          - ADC_INT_FLAG_PHS2
*\*\          - ADC_INT_FLAG_PHS1
*\*\return  none
**/
void ADC_ClearIntPendingBit(uint16_t ADC_IT)
{
    /* Clear the selected ADC interrupt pending bits */
    ADC->STS = (uint32_t)ADC_IT ;
}


/**
*\*\name    ADC_ConfigRegularChannel.
*\*\fun     Configures ADC channel its corresponding
*\*\        rank in the sequencer and its sample time.
*\*\param   ADC_Channel :
*\*\          - ADC_CH_0
*\*\          - ADC_CH_1
*\*\          - ADC_CH_2
*\*\          - ADC_CH_3
*\*\          - ADC_CH_4
*\*\          - ADC_CH_5
*\*\          - ADC_CH_6
*\*\          - ADC_CH_7
*\*\          - ADC_CH_8
*\*\          - ADC_CH_9
*\*\          - ADC_CH_10
*\*\          - ADC_CH_TS
*\*\          - ADC_CH_VREFINT
*\*\          - ADC_CH_OPA0OUT
*\*\          - ADC_CH_OPA1OUT
*\*\          - ADC_CH_OPA2OUT
*\*\param   Rank : The rank in the group sequencer. This parameter must be between 1 to 10.
*\*\param   ADC_SampleTime : The sample time value to be set for the selected channel.
*\*\          - ADC_SAMP_TIME_4CYCLES
*\*\          - ADC_SAMP_TIME_6CYCLES   
*\*\          - ADC_SAMP_TIME_14CYCLES
*\*\          - ADC_SAMP_TIME_20CYCLES  
*\*\          - ADC_SAMP_TIME_29CYCLES                
*\*\          - ADC_SAMP_TIME_42CYCLES                   
*\*\          - ADC_SAMP_TIME_56CYCLES                   
*\*\          - ADC_SAMP_TIME_72CYCLES                   
*\*\          - ADC_SAMP_TIME_88CYCLES                   
*\*\          - ADC_SAMP_TIME_120CYCLES                  
*\*\          - ADC_SAMP_TIME_182CYCLES                   
*\*\          - ADC_SAMP_TIME_240CYCLES                                
*\*\          - ADC_SAMP_TIME_300CYCLES                 
*\*\          - ADC_SAMP_TIME_400CYCLES                  
*\*\          - ADC_SAMP_TIME_480CYCLES                 
*\*\          - ADC_SAMP_TIME_600CYCLES 
*\*\return  none
**/
void ADC_ConfigRegularChannel(uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime)
{
    __IO uint32_t tempreg1;
    if (ADC_Channel > ADC_CH_7) /* if ADC_CH_8 ... ADC_CH_15 is selected */
    {
        /* Get the old register value */
        tempreg1 = ADC->SAMPT2;
         /* Clear the old channel sample time */
        tempreg1 &= (~ADC_SAMP_TIME_MASK << (4U * (ADC_Channel-8U)));
        /* Set the new channel sample time */
        tempreg1 |= ((uint32_t)ADC_SampleTime) << (4U * (ADC_Channel-8U));
        /* Store the new register value */
        ADC->SAMPT2 = tempreg1;
    }
    else /* if ADC_CH_0 ... ADC_CH_7 is selected */
    {
        /* Get the old register value */
        tempreg1 = ADC->SAMPT1;
         /* Clear the old channel sample time */
        tempreg1 &= (~ADC_SAMP_TIME_MASK << (4U * (ADC_Channel)));
        /* Set the new channel sample time */
        tempreg1 |= ((uint32_t)ADC_SampleTime) << (4U * (ADC_Channel));
        /* Store the new register value */
        ADC->SAMPT1 = tempreg1;
    }

    if (Rank < 9U)  /* For Rank 1 to 8 */
    {
        /* Get the old register value */
        tempreg1 = ADC->SEQ1;
        /* Clear the old SQx bits for the selected rank */
        tempreg1 &= (uint32_t)(~(ADC_DATA_MASK << (4U * (Rank - 1U))));
         /* Set the SQx bits for the selected rank */
        tempreg1 |= (uint32_t)ADC_Channel << (4U * (Rank - 1U));
        /* Store the new register value */
        ADC->SEQ1 = tempreg1;
    }
    else /* For Rank 9 to 10 */
    {
        /* Get the old register value */
        tempreg1 = ADC->SEQ2;
        /* Clear the old SQx bits for the selected rank */
        tempreg1 &= (uint32_t)(~(ADC_DATA_MASK << (4U * (Rank - 9U))));
         /* Set the SQx bits for the selected rank */
        tempreg1 |= (uint32_t)ADC_Channel << (4U * (Rank - 9U));
        /* Store the new register value */
        ADC->SEQ2 = tempreg1;
    }

}

/**
*\*\name    ADC_EnableInternalInputBuffer.
*\*\fun     Enable and disable ADC internal input buffer.
*\*\param   Cmd : new state of the ADC peripheral.
*\*\          -ENABLE 
*\*\          -DISABLE
*\*\return  none
**/
void ADC_EnableInternalInputBuffer(FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        /* Enable the ADC internal reference voltage */
        ADC->CTRL3 |= ADC_VREFINT_ENABLE;
    }
    else
    {
        /* Disable the ADC internal reference voltage */
        ADC->CTRL3 &= (~ADC_VREFINT_ENABLE);
    }
}


/**
*\*\name    ADC_EnableTempSensor.
*\*\fun     Enable and disable temperature sensor channel .
*\*\param   Cmd : new state of the ADC peripheral.
*\*\          -ENABLE 
*\*\          -DISABLE
*\*\return  none
**/
void ADC_EnableTempSensor(FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        /* Temperature sensor channel enabled */
        ADC->CTRL3 |= ADC_CTRL3_TEMPEN;
    }
    else
    {
        /* Temperature sensor channel disable */
        ADC->CTRL3 &= (~ADC_CTRL3_TEMPEN);
    }
}

/**
*\*\name    ADC_EnableVREFPAsReferenceVoltag.
*\*\fun     Select VREF+ as ADC reference voltage source or not.
*\*\param   Cmd : new state of the ADC peripheral.
*\*\          -ENABLE 
*\*\          -DISABLE
*\*\return  none
**/
void ADC_EnableVREFPAsReferenceVoltag(FunctionalState Cmd)
{
    if (Cmd != DISABLE)
    {
        /* Select VREF+ as ADC reference voltage source */
        ADC->CTRL3 |= ADC_CTRL3_REFSEL;
    }
    else
    {
        /* Select VDDA as ADC reference voltage source */
        ADC->CTRL3 &= (~ADC_CTRL3_REFSEL);
    }
}

/**
*\*\name    ADC_Clock_Mode_Config
*\*\fun     Configures the ADCHCLK prescaler.
*\*\param   RCC_ADCHCLKprescaler:
*\*\          - RCC_ADCHCLK_DIV2 
*\*\          - RCC_ADCHCLK_DIV4 
*\*\          - RCC_ADCHCLK_DIV8 
*\*\          - RCC_ADCHCLK_DIV16 
*\*\          - RCC_ADCHCLK_DIV32 
*\*\return  none
**/
void ADC_ClockModeConfig(uint32_t RCC_ADCHCLKprescaler)
{
    RCC_ConfigAdcHclk(RCC_ADCHCLKprescaler);
}


/**
*\*\name    ADC_SampleModeConfig.
*\*\fun     Configures the ADC sample mode.
*\*\param   mode : Trigger mode selection.
*\*\          -ADC_PHS_TRG_MODE_SINGLE 
*\*\          -ADC_PHS_TRG_MODE_TWO
*\*\          -ADC_PHS_TRG_MODE_THREE 
*\*\          -ADC_PHS_TRG_MODE_FOUR
*\*\param   PH1CHNUM,PH2CHNUM,PH3CHNUM,PH4CHNUM :
*\*\          - 0x0~0xf
*\*\return  none
**/
void ADC_SampleModeConfig(uint32_t mode,uint8_t PH1CHNUM, uint8_t PH2CHNUM, uint8_t PH3CHNUM, uint8_t PH4CHNUM)
{
    __IO uint32_t tempreg1;
    
    tempreg1 = ADC->PHCFG;
    tempreg1 &= ~ADC_PHS_TRG_CONFIG_MASK;
    tempreg1 |= mode;
    tempreg1 |= (uint32_t)((((uint32_t)PH4CHNUM - 1U) << 12U) | (((uint32_t)PH3CHNUM-1U) << 8U) | (((uint32_t)PH2CHNUM-1U) << 4U) | (((uint32_t)PH1CHNUM-1U)));	
    ADC->PHCFG = tempreg1;	  
}

/**
*\*\name    ADC_EnableChannelStartConv.
*\*\fun     Enables or disables software start conversion.
*\*\param   swstart:
*\*\          - ADC_SWSTRRCH_PHS1_START 
*\*\          - ADC_SWSTRRCH_PHS2_START 
*\*\          - ADC_SWSTRRCH_PHS3_START 
*\*\          - ADC_SWSTRRCH_PHS4_START 
*\*\return  none:
**/
void ADC_EnableChannelStartConv(uint32_t PHSWSTART)
{
    uint32_t temp ;

    temp = ADC->PHSWTRIG;
    temp &= (uint32_t)(ADC_SWSTRRCH_PHSx_START_MASK);
    temp |= (uint32_t)(PHSWSTART);
    /* Enable the ADC software trigger conversion mode  */
    ADC->PHSWTRIG = temp;	  
}

