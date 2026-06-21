/*****************************************************************************
 * Copyright (c) 2025, Nsing Technologies Inc.
 *
 * All rights reserved.
 * ****************************************************************************
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Nsing' name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY Nsing "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL Nsing BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ****************************************************************************/

/**
*\*\file n32g033_comp.c
*\*\author Nsing 
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/

#include "n32g033_comp.h"
#include "n32g033_rcc.h"

#define COMP_FILTCR_MASK        ((uint32_t)0x000007FFU)


/**
*\*\name    COMP_DeInit.
*\*\fun     Reset the COMP registers.
*\*\return  none
**/
void COMP_DeInit(void)
{
    RCC_EnableAPBPeriphReset(RCC_APB_PERIPH_COMP);
}

/**
*\*\name    COMP_Init.
*\*\fun     Initializes the COMP peripheral according to the specified parameters in the COMP_InitStruct
*\*\param   COMP_initstruct :
*\*\param   Clksel :
*\*\          - COMP_CLKSEL_SYSTEMCLK                           
*\*\          - COMP_CLKSEL_LSX                    
*\*\param   Pwrmd :
*\*\          - COMP_CTRL_PWRMD_NORMAL                   
*\*\          - COMP_CTRL_PWRMD_LOWPWR      
*\*\param   Blking :
*\*\            - COMP_BLANKING_NO
*\*\            - COMP_BLANKING_TIM1_OC5
*\*\param   Hyst :
*\*\          - COMP_CTRL_HYST_NO   
*\*\          - COMP_CTRL_HYST_LOW  
*\*\          - COMP_CTRL_HYST_MID     
*\*\          - COMP_CTRL_HYST_HIGH 
*\*\param   PolRev :
*\*\          - COMP_OUTPOL_REV   
*\*\          - COMP_OUTPOL_NREV
*\*\param   InpSel :
*\*\            - COMP_INPSEL_PA1                   
*\*\            - COMP_INPSEL_PA3 
*\*\            - COMP_INPSEL_PA7  
*\*\            - COMP_INPSEL_PA8  
*\*\            - COMP_INPSEL_PA9
*\*\            - COMP_INPSEL_PA10
*\*\            - COMP_INPSEL_PA12
*\*\            - COMP_INPSEL_OPA0 
*\*\            - COMP_INPSEL_OPA1
*\*\            - COMP_INPSEL_OPA2                 
*\*\param   InmSel :
*\*\          - COMP                
*\*\            - COMP_INMSEL_PA0       
*\*\            - COMP_INMSEL_PA4  
*\*\            - COMP_INMSEL_PA5  
*\*\            - COMP_INMSEL_PA11 
*\*\            - COMP_INMSEL_VREF_DAC                                    
*\*\param   ClkPsc:
*\*\          Value can be set from 0 to 65535.
*\*\param   FilterEn:
*\*\          - ENABLE 
*\*\          - DISABLE
*\*\param   Threshold:
*\*\          - this value must be greater than SAMPW / 2 .
*\*\param   SampWindow:
*\*\          - from 0 to 31.
*\*\param   En
*\*\          - ENABLE
*\*\          - DISABLE
*\*\return  none
**/
void COMP_Init( COMP_InitType* COMP_InitStruct)
{
    __IO uint32_t tmp = 0;

    // filter
    tmp = COMP->FILC;
    tmp &= COMP_FILTCR_MASK;
    tmp |= (((uint32_t)COMP_InitStruct->SampWindow << 6) | ((uint32_t)COMP_InitStruct->Threshold << 1) | (uint32_t)(COMP_InitStruct->FilterEn));
    COMP->FILC = tmp;

    // filter psc
    COMP->FILP = COMP_InitStruct->ClkPsc;

    // ctr
    tmp = COMP->CTRL;
    tmp &=(COMP_CTRL_CLKSEL_MASK & COMP_CTRL_PWRMODE_MASK & COMP_CTRL_HYST_MASK & COMP_CTRL_POL_MASK & COMP_CTRL_INPSEL_MASK & COMP_CTRL_INMSEL_MASK & COMP_CTRL_EN_MASK);
    tmp |=((uint32_t)(COMP_InitStruct->ClockSelect) | (uint32_t)(COMP_InitStruct->LowPoweMode) | (uint32_t)(COMP_InitStruct->Blking) | (uint32_t)(COMP_InitStruct->Hyst) 
	      | (uint32_t)(COMP_InitStruct->PolRev)| (uint32_t)(COMP_InitStruct->InpSel) | (uint32_t)(COMP_InitStruct->InmSel));

    /*COMP enable or disable select*/
    if(COMP_InitStruct->En != DISABLE)
    {
        tmp |= COMP_ENABLE;
    }
    else
    {
        tmp &= (~COMP_ENABLE);
    }	
	
	  COMP->CTRL = tmp;
		
}


/**
*\*\name    COMP_StructInit.
*\*\fun     Fills all COMP_initstruct member with default value.
*\*\param   COMP_initstruct :
*\*\          - ClockSelect
*\*\          - LowPoweMode
*\*\          - Blking
*\*\          - Hyst
*\*\          - PolRev
*\*\          - InpSel
*\*\          - InmSel
*\*\          - FilterEn
*\*\          - SampWindow
*\*\          - Threshold
*\*\          - ClkPsc
*\*\          - En
*\*\return  none
**/
void COMP_StructInit(COMP_InitType* COMP_InitStruct)
{
	  /* Reset COMP init structure parameters values */ 
    /* Initialize the clock select during STOP and low power run mode*/
    COMP_InitStruct->ClockSelect   = COMP_CLKSEL_SYSTEMCLK;
	  /* Initialize the comp operation mode*/
    COMP_InitStruct->LowPoweMode   = COMP_CTRL_PWRMD_LOWPWR;   
	  /* Initialize the Blking */
    COMP_InitStruct->Blking        = COMP_BLANKING_NO;
    /* Initialize the Hyst */  
    COMP_InitStruct->Hyst          = (uint32_t)COMP_CTRL_HYST_NO;  
	  /* Initialize the PolRev */
    COMP_InitStruct->PolRev        = COMP_OUTPOL_NREV; 
	  /* Initialize the InpSel */
    COMP_InitStruct->InpSel        = COMP_INPSEL_RES;
    /* Initialize the InmSel */	
    COMP_InitStruct->InmSel        = COMP_INMSEL_RES;   
	  /* Initialize the FilterEn */
    COMP_InitStruct->FilterEn      = DISABLE;
	  /* Initialize the SampWindow */
    COMP_InitStruct->SampWindow    = 0;
	  /* Initialize the Threshold */
    COMP_InitStruct->Threshold     = 0;
    /* Initialize the ClkPsc */
    COMP_InitStruct->ClkPsc        = 0;
    /* Initialize the En */
    COMP_InitStruct->En            = DISABLE;	
}


/**
*\*\name    COMP_SetFilterControl.
*\*\fun     Configure the COMP filter value. 
*\*\param   FilEn:
*\*\          - ENABLE.
*\*\          - DISABLE.
*\*\param   TheresNum:
*\*\          - this value must be greater than SAMPW / 2 .
*\*\param   SampPW:
*\*\          - from 0 to 31.
*\*\return  none
**/
void COMP_SetFilterControl(uint8_t FilEn, uint8_t TheresNum, uint8_t SampPW)
{
	/* Clear COMP_FILC SAMPW[4:0],THRESH[4:0] Filt_EN bits */
	COMP->FILC &= COMP_FILTCR_MASK;
	/* Set COMP_FILC SAMPW[4:0],THRESH[4:0] Filt_EN bits bits */
	COMP->FILC = (((uint32_t)SampPW << 6)|((uint32_t)TheresNum << 1)|((uint32_t)FilEn));

}


/**
*\*\name    COMP_Filter_Clock_Prescale_Config.
*\*\fun     Configure The COMP low filter prescale.
*\*\param   FilPreVal:
*\*\        Value can be set from 0 to 65535.
*\*\return  none
**/
void COMP_SetFilterPrescaler(uint16_t FilPreVal)
{
	/* Clear COMP_FILP CLKPSC[15:0] bits */
	COMP->FILP &= COMP_FILTER_CLKPSC_MASK;
	/* Set COMP_FILP CLKPSC[15:0] bits */
	COMP->FILP |= FilPreVal;
}

/**
*\*\name    COMP_SetHyst.
*\*\fun     Configure COMP hysteresis level.
*\*\param   HYST :
*\*\          - COMP_CTRL_HYST_NO   
*\*\          - COMP_CTRL_HYST_LOW  
*\*\          - COMP_CTRL_HYST_MID     
*\*\          - COMP_CTRL_HYST_HIGH 
*\*\return  none
**/
void COMP_SetHyst(uint32_t HYST)
{
    __IO uint32_t temp;
	/* Clear COMP_CTRL HYST[1:0] bits */
	temp  = COMP->CTRL;
	temp &= COMP_HYST_MASK;
	/* Set COMP_CTRL HYST[1:0] bits */
	temp |= (uint32_t)HYST;

	COMP->CTRL = temp;
}

/**
*\*\name    COMP_OutputPolarityConfig.
*\*\fun     Configures COMP output signal polarity overturn or not.
*\*\param   POL :
*\*\          - COMP_OUTPOL_REV   
*\*\          - COMP_OUTPOL_NREV   
*\*\return  none
**/
void COMP_OutputPolarityConfig(uint32_t POL)
{
	/* Clear COMP_CTRL POL bits */
	COMP->CTRL &= COMP_OUTPOL_MASK;
	/* Set COMP_CTRL POL bits */
	COMP->CTRL |= POL;
}

/**
*\*\name    COMP_SetInpSel.
*\*\fun     Configures COMP inpsel input selection.
*\*\param   vpsel :
*\*\            - COMP_INPSEL_OPA0                   
*\*\            - COMP_INPSEL_OPA1                   
*\*\            - COMP_INPSEL_OPA2                   
*\*\            - COMP_INPSEL_PA1                  
*\*\            - COMP_INPSEL_PA3                   
*\*\            - COMP_INPSEL_PA7                   
*\*\            - COMP_INPSEL_PA8                   
*\*\            - COMP_INPSEL_PA9        
*\*\            - COMP_INPSEL_PA10                   
*\*\            - COMP_INPSEL_PA12   
*\*\return  none
**/
void COMP_SetInpSel(uint32_t VpSel)
{
    __IO uint32_t temp;
	/* Clear COMP_CTRL INPSEL bits */
	temp  = COMP->CTRL;
	temp &= COMP_INPSEL_MASK;
	/* Set COMP_CTRL INPSEL bits */
	temp |= (uint32_t)VpSel;

	COMP->CTRL = temp;
}

/**
*\*\name    COMP_SetInmSel.
*\*\fun     Configures COMP inmsel input selection..
*\*\param   VmSel :
*\*\            - COMP_INMSEL_VREF_DAC                   
*\*\            - COMP_INMSEL_PA0         
*\*\            - COMP_INMSEL_PA4                   
*\*\            - COMP_INMSEL_PA5                    
*\*\            - COMP_INMSEL_PA11                  
*\*\return  none
**/
void COMP_SetInmSel(uint32_t VmSel)
{
    __IO uint32_t temp;
	/* Clear COMP_CTRL INMSEL bits */
	temp  = COMP->CTRL;
	temp &= COMP_INMSEL_MASK;
	/* Set COMP_CTRL INMSEL bits */
	temp |= (uint32_t)VmSel;

	COMP->CTRL = temp;
}

/**
*\*\name    COMP_Enable.
*\*\fun     Enable Oor disable COMP peripheral.
*\*\param   Cmd new state of the COMP peripheral.
*\*\          -ENABLE 
*\*\          -DISABLE
*\*\return  none
**/
void COMP_Enable(FunctionalState Cmd)
{
	/* Set or reset the COMP1_CTRL EN bit */
	if(Cmd != DISABLE)
	{
		COMP->CTRL |= COMP_ENABLE;
	}
	else
	{
		COMP->CTRL &= (~COMP_ENABLE);
	}
}

/**
*\*\name    COMP_SetIntEn.
*\*\fun     Enable or disable COMP interrupt .
*\*\param   Cmd new state of the COMP peripheral.
*\*\          -ENABLE 
*\*\          -DISABLE
*\*\return  none
**/
void COMP_SetIntEn(FunctionalState Cmd)
{
    if(Cmd != DISABLE)
    {
        COMP->INTEN |= COMP_CTRL_EN ;
    }
    else
    {
        COMP->INTEN &= (~COMP_CTRL_EN) ;
    }
}

/**
*\*\name    COMP_GetIntStsOneComp.
*\*\fun     Get COMPx interrupt flag .
*\*\return  FlagStatus:
*\*\          - SET
*\*\          - RESET
**/
FlagStatus COMP_GetIntStatus(void)
{
    return (((COMP->INTSTS & COMP_INTSTS_CMPIS) != RESET) ? SET :RESET);
}

/**
*\*\name    COMP_GetOutStatus.
*\*\fun     Get COMP result Status before filtering .
*\*\return  FlagStatus:
*\*\          - SET
*\*\          - RESET
**/
FlagStatus COMP_GetOutStatus(void)
{
    FlagStatus status ;

    status =((COMP->CTRL & COMP_OUT_MASK) == COMP_OUT_MASK) ? SET : RESET;
    return status;
}

/**
*\*\name    COMP_IntStatusClear.
*\*\fun     Clear COMP interrupt flag.
*\*\return  none
**/
void COMP_IntStatusClear(void)
{
    COMP->INTSTS |= COMP_INTSTS_CMPIS;	
}

/**
*\*\name    COMP_SetIntEn.
*\*\fun     Enable COMP Lock .
*\*\return  none
**/
void COMP_SetLock(void)
{
    COMP->LOCK = COMP_LOCK_MASK ;
}

/**
*\*\name    COMP_VREF_Enable.
*\*\fun     Enable or disable COMP internal voltage dac.
*\*\param   Cmd new state of the COMP peripheral.
*\*\          -ENABLE 
*\*\          -DISABLE
*\*\return  none
**/
void COMP_VREF_Enable(FunctionalState Cmd)
{
    /* Set or reset the COMP1_CTRL EN bit */
    if(Cmd != DISABLE)
    {
        COMP->INVREF |= COMP_INVREF_VREFEN;		
    }
    else
    {
        COMP->INVREF &= (~COMP_INVREF_VREFEN);
    }
}


/**
*\*\name    COMP_SetRefScl.
*\*\fun     Set Reference Volatge Scale of Vv1 .
*\*\param   Vv1Trim :
*\*\          - this data range of 0-0xff 
*\*\param   Vv1En :
*\*\          - false
*\*\          - true  
*\*\return  none
**/
void COMP_SetRefScl(uint8_t Vv1Trim, bool Vv1En)
{
    __IO uint32_t temp;
    /* Clear COMP_CTRL INVREF bits */
    temp  = COMP->INVREF;
    temp &= COMP_INMSEL_MASK;
    /* Set COMP_CTRL INVREF bits */
    temp |= ((((uint32_t )Vv1Trim) << 1) | (uint32_t )(Vv1En ? 0x01 : 0));

    COMP->INVREF = temp;
}

/**
*\*\name    COMP_SetBlking.
*\*\fun     Configures TIM1 output signal to control COMP Blking. 
*\*\param   blking_mode :
*\*\          - COMP_BLANKING_NO
*\*\          - COMP_BLANKING_TIM1_OC5
*\*\return  none
**/
void COMP_SetBlking(uint32_t blking_mode)
{
    /* Clear COMP_CTRL BLKING bit */
    COMP->CTRL &= COMP_BLANKING_MASK;
    /* Set COMP_CTRL BLKING bit */
    COMP->CTRL |= blking_mode;

}

