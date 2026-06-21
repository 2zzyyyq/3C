#include "main.h"

 /* Initialize  output pushpull mode*/
/**
*\*\name    GPIO_Init.
*\*\fun     Configures  GPIO.
*\*\param   GPIOx x can be A/B/F to select the GPIO port.
*\*\param   Pin This parameter can be GPIO_PIN_0~GPIO_PIN_15?
*\*\return  none 
**/
void GPIO_Init(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIO_InitType GPIO_InitStructure;

    /* Enable the GPIO Clock */
    RCC_EnableAPBPeriphClk(RCC_APB_PERIPH_GPIO, ENABLE);

    /* Configure the GPIO pin */
    if (Pin <= GPIO_PIN_ALL)
    {
        GPIO_InitStruct(&GPIO_InitStructure);
        GPIO_InitStructure.Pin = Pin;
        GPIO_InitStructure.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitPeripheral(GPIOx, &GPIO_InitStructure);
    }
}


/**
*\*\name    LedOn.
*\*\fun     Turns selected Led on.
*\*\param   GPIOx x can be A/B/F to select the GPIO port.
*\*\param   Pin This parameter can be GPIO_PIN_0~GPIO_PIN_15?
*\*\return  none 
**/
void LedOn(GPIO_Module *GPIOx, uint16_t Pin)
{
    GPIO_SetBits(GPIOx, Pin);
}


/**
*\*\name    LedOff.
*\*\fun     Turns selected Led Off.
*\*\param   GPIOx x can be A/B/F to select the GPIO port.
*\*\param   Pin This parameter can be GPIO_PIN_0~GPIO_PIN_15?
*\*\return  none 
**/
void LedOff(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIO_ResetBits(GPIOx, Pin);
}


/**
*\*\name    LedBlink.
*\*\fun     Toggles the selected Led.
*\*\param   GPIOx x can be A/B/F to select the GPIO port.
*\*\param   Pin This parameter can be GPIO_PIN_0~GPIO_PIN_15?
*\*\return  none 
**/
void LedBlink(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIO_TogglePin(GPIOx, Pin);
}



/**
*\*\name    GPIO_Configuration.
*\*\fun     Configures the GPIO pins.
*\*\param   none
*\*\return  none 
**/
void GPIO_Configuration(void)
{
    GPIO_InitType GPIO_InitStructure;

    GPIO_InitStruct(&GPIO_InitStructure);    
    
    /* GPIOx Configuration: Pin of TIM_OUTPWM */
    GPIO_InitStructure.Pin        = LED1_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Alternate = LED1_GPIO_AF;
    GPIO_InitPeripheral(LED1_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.Pin        = LED2_GPIO_PIN;
    GPIO_InitStructure.GPIO_Alternate = LED2_GPIO_AF;
    GPIO_InitPeripheral(LED2_GPIO_PORT, &GPIO_InitStructure);
    
    GPIO_InitStructure.Pin        = TIMx_CH3_GPIO_PIN;
    GPIO_InitStructure.GPIO_Alternate = TIMx_CH3_GPIO_AF;
    GPIO_InitPeripheral(TIMx_CH3_GPIO_PORT, &GPIO_InitStructure);
    
    GPIO_InitStructure.Pin        = TIMx_CH4_GPIO_PIN_BUZZ;
    GPIO_InitStructure.GPIO_Alternate = TIMx_CH4_GPIO_AF_BUZZ;
    GPIO_InitPeripheral(TIM4_CH1_GPIO_PORT_BUZZ, &GPIO_InitStructure);

 
		GPIO_InitStructure.Pin        = GPIO_PIN_0;
		GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF11;
    GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);
 
  /* GPIOx Configuration: Pin of TIM_OUTPWM */
    GPIO_InitStructure.Pin        = MOTOR_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Alternate = MOTOR_GPIO_AF;
    GPIO_InitPeripheral(MOTOR_GPIO_PORT, &GPIO_InitStructure);
		  /* GPIOx Configuration: Pin of TIM_OUTPWM */
    GPIO_InitStructure.Pin        = MOTOR2_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Alternate = MOTOR_GPIO_AF;
    GPIO_InitPeripheral(MOTOR_GPIO_PORT, &GPIO_InitStructure);

    			    /* GPIOx 设置推挽模式 */
    GPIO_InitStructure.Pin        = GPIO_PIN_15;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
			    /* GPIOx 设置推挽模式 */
    GPIO_InitStructure.Pin        = GPIO_PIN_7;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);
			    /* GPIOx 设置推挽模式 */
    GPIO_InitStructure.Pin        = BUZZ_PIN;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitPeripheral(BUZZ, &GPIO_InitStructure);
 		//    		    /* GPIOx 设置输入 模式 */
    GPIO_InitStructure.Pin        = DOWN_LIMIT_PIN;
	  GPIO_InitStructure.GPIO_Pull    = GPIO_PULL_UP;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_INPUT;
    GPIO_InitPeripheral(DOWN_LIMIT_PORT, &GPIO_InitStructure);

 
    GPIO_InitStructure.Pin        = UP_LIMIT_PIN;
	  GPIO_InitStructure.GPIO_Pull    = GPIO_PULL_UP;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_INPUT;
    GPIO_InitPeripheral(UP_LIMIT_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.Pin        = HOLL_DIR_PIN;
	  GPIO_InitStructure.GPIO_Pull    = GPIO_PULL_UP;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_INPUT;
    GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);
		
		GPIO_InitStructure.Pin        = YZ_PIN;
	  GPIO_InitStructure.GPIO_Pull    = GPIO_PULL_UP;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_INPUT;
    GPIO_InitPeripheral(YZ_PORT, &GPIO_InitStructure);

}


/**
*\*\name    KeyInputExtiInit.
*\*\fun     Configures key port.
*\*\param   GPIOx x can be A to G to select the GPIO port
*\*\param   Pin This parameter can be GPIO_PIN_0~GPIO_PIN_15
*\*\return  none 
**/
void KeyInputExtiInit(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIO_InitType GPIO_InitStructure;
    EXTI_InitType EXTI_InitStructure;
    NVIC_InitType NVIC_InitStructure;

    /* Enable the GPIO Clock */
    RCC_EnableAPBPeriphClk(RCC_APB_PERIPH_GPIO,ENABLE);

    /*Configure the GPIO pin as input floating*/
    if (Pin <= GPIO_PIN_ALL)
    {
        GPIO_InitStruct(&GPIO_InitStructure);
        GPIO_InitStructure.Pin          = Pin;
        GPIO_InitStructure.GPIO_Pull    = GPIO_PULL_UP;
        GPIO_InitPeripheral(GPIOx, &GPIO_InitStructure);
    }

    /*Configure key EXTI Line to key input Pin*/
    GPIO_ConfigEXTILine(AC_INPUT_PORT_SOURCE, AC_INPUT_PIN_SOURCE);

    /*Configure key EXTI line*/
    EXTI_InitStructure.EXTI_Line    = AC_INPUT_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling; // EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_InitPeripheral(&EXTI_InitStructure);

    /*Set key input interrupt priority*/
    NVIC_InitStructure.NVIC_IRQChannel                   = AC_INPUT_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority           = NVIC_PRIORITY_3;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}




void HOLLInputExtiInit(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIO_InitType GPIO_InitStructure;
    EXTI_InitType EXTI_InitStructure;
    NVIC_InitType NVIC_InitStructure;

    /* Enable the GPIO Clock */
    RCC_EnableAPBPeriphClk(RCC_APB_PERIPH_GPIO,ENABLE);

    /*Configure the GPIO pin as input floating*/
    if (Pin <= GPIO_PIN_ALL)
    {
        GPIO_InitStruct(&GPIO_InitStructure);
        GPIO_InitStructure.Pin          = Pin;
        GPIO_InitStructure.GPIO_Pull    = GPIO_PULL_UP;
        GPIO_InitPeripheral(GPIOx, &GPIO_InitStructure);
    }

    /*Configure key EXTI Line to key input Pin*/
    GPIO_ConfigEXTILine(HOLL_INPUT_PORT_SOURCE, HOLL_INPUT_PIN_SOURCE);

    /*Configure key EXTI line*/
    EXTI_InitStructure.EXTI_Line    = HOLL_INPUT_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling; // EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_InitPeripheral(&EXTI_InitStructure);

    /*Set key input interrupt priority*/
    NVIC_InitStructure.NVIC_IRQChannel                   = HOLL_INPUT_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority           = NVIC_PRIORITY_1;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}










