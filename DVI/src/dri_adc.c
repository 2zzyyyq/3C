#include "main.h"
ADC_InitType ADC_InitStructure;
__IO uint16_t ADCConvertedValue[3];
void RCC_Configuration(void);
void GPIO_Configuration(void);
void ADC_StartConversion(void);
// 定义位掩码（和手册对应，代码可读性更高）
#define ADC_CTRL3_REFSEL_POS    (3U)
#define ADC_CTRL3_VREFEN_POS    (2U)
#define ADC_CTRL3_REFSEL_MASK   (1U << ADC_CTRL3_REFSEL_POS)
#define ADC_CTRL3_VREFEN_MASK   (1U << ADC_CTRL3_VREFEN_POS)
/**
*\*\name    ADC_Initial.
*\*\fun     ADC_Initial program.
*\*\return  none
**/
void ADC_Initial(void)
{
			ADC_InitType ADC_InitStructure;

			/* Enable peripheral clocks ------------------------------------------------*/

			/* Enable GPIO clocks */
			RCC_EnableAPBPeriphClk(RCC_APB_PERIPH_GPIO, ENABLE);
			/* Enable ADC clocks */


			GPIO_InitType GPIO_InitStructure;

			GPIO_InitStruct(&GPIO_InitStructure);
			/* Configure PA0 as analog input -----------------------*/
			GPIO_InitStructure.Pin       = GPIO_PIN_0 ;
			GPIO_InitStructure.GPIO_Mode = GPIO_MODE_ANALOG;
			GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
			GPIO_InitStruct(&GPIO_InitStructure);
//			/* Configure PB2 as analog input -----------------------*/
//			GPIO_InitStructure.Pin       = GPIO_PIN_2 ;
//			GPIO_InitStructure.GPIO_Mode = GPIO_MODE_ANALOG;
//			GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);
			// 4. 配置ADC参数
			ADC_InitStructure.ContinueConvEn = DISABLE;      // 单次转换模式
			ADC_InitStructure.DatAlign = ADC_DAT_ALIGN_R;    // 数据右对齐
			ADC_InitStructure.PhsMode = ADC_PHS_TRG_MODE_SINGLE;  // 单相模式
		 
	    ADC->CTRL3 |= ADC_CTRL3_REFSEL_MASK | ADC_CTRL3_VREFEN_MASK;
 
			/* Initialize the phase 1 channel number member */
			ADC_InitStructure.Phs1ChNumber   = 1U;
			/* Initialize the phase 2 channel number member */
			ADC_InitStructure.Phs2ChNumber   = 1U;
			/* Initialize the phase 3 channel number member */
			ADC_InitStructure.Phs3ChNumber   = 1U;
			/* Initialize the phase 4 channel number member */
			ADC_InitStructure.Phs4ChNumber   = 1U;
			// 配置触发源（使用软件触发）
	
		  /* Initialize the ExtTrigSelect1 member */
       ADC_InitStructure.ExtTrigSelect1 = ADC_EXT_TRIGCONV_SWSTRRCH;
      /* Initialize the ExtTrigSelect2 member */
       ADC_InitStructure.ExtTrigSelect2 = ADC_EXT_TRIGCONV_SWSTRRCH;
			// 5. 初始化ADC
			ADC_Init(&ADC_InitStructure);
 
			// 参数：通道号，转换序列（1-10），采样时间
	    ADC_ConfigRegularChannel(ADC_Channel_00_PA0, 1, ADC_SAMP_TIME_182CYCLES);
     // ADC_ConfigRegularChannel(ADC_Channel_10_PB2, 1, ADC_SAMP_TIME_182CYCLES);
			// 7. 配置ADC中断
			// 使能转换完成中断 
	    ADC_ConfigInt(ADC_INT_PHS2, ENABLE);
	    ADC_ConfigInt(ADC_INT_PHS1, ENABLE);
			// 8. 配置NVIC中断
			NVIC_InitType NVIC_InitStructure;
			NVIC_InitStructure.NVIC_IRQChannel = ADC_IRQn;      // ADC中断通道
			NVIC_InitStructure.NVIC_IRQChannelPriority = 1;     // 中断优先级
			NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;     // 使能中断
			NVIC_Init(&NVIC_InitStructure);
      ADC_EnableSoftwareTrig(ENABLE);
			// 9. 使能ADC
			ADC_Enable(ENABLE);

			// 10. 等待ADC准备好
			while(ADC_GetFlagStatus(ADC_FLAG_RDY) == RESET);
}


/**
 * @brief 开始ADC转换
 */
void ADC_StartConversion(void)
{
    // 清除之前的标志位
    ADC_ClearFlag(ADC_FLAG_STR | ADC_FLAG_ENDC);
    
    // 软件启动转换
    ADC_EnableChannelStartConv(ADC_SWSTRRCH_PHS1_START);
      /* Start ADC Software Conversion */
    ADC_EnableChannelStartConv(ADC_SWSTRRCH_PHS2_START);
    // 或者使用通用软件触发
    ADC_EnableSoftwareTrig(ENABLE);
}















































