#include "main.h"
  //TIM3->CCDAT1=1600;脉冲设置
TIM_TimeBaseInitType TIM_TimeBaseStructure;
OCInitType TIM_OCInitStructure;
uint32_t CCR1_Val       = 800;
uint32_t CCR2_Val       = 800;
uint32_t CCR3_Val       = 800;
uint32_t CCR4_Val       = 400;
uint32_t PrescalerValue = 0;
TIM_ICInitType TIM_ICInitStructure;
void TIM_PWM_OUT(TIM_Module* TIMPWM , uint16_t TIM_CH);
void TIM_PWM_OUT(TIM_Module* TIMPWM, uint16_t TIM_CH)
{
 
    PrescalerValue = 1;  
    /* Time base configuration */
    TIM_InitTimBaseStruct(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.Period        = 1600-1;
    TIM_TimeBaseStructure.Prescaler     = 1;
    TIM_TimeBaseStructure.ClkDiv        = TIM_CLK_DIV1;
    TIM_TimeBaseStructure.CounterMode   = TIM_CNT_MODE_UP;

    TIM_InitTimeBase(TIMPWM, &TIM_TimeBaseStructure);

    /* PWM1 Mode configuration: Channel1 */
    TIM_InitOcStruct(&TIM_OCInitStructure);
    TIM_OCInitStructure.OCMode      = TIM_OCMODE_PWM1;
    TIM_OCInitStructure.OutputState = TIM_OUTPUT_STATE_ENABLE;
    TIM_OCInitStructure.OCPolarity  = TIM_OC_POLARITY_HIGH;


  switch(TIM_CH) {
        case 1:
            TIM_OCInitStructure.Pulse = CCR1_Val;  // 确保 CCR1_Val 已初始化
            TIM_InitOc1(TIM_OUTPWM, &TIM_OCInitStructure);
            TIM_ConfigOc1Preload(TIM_OUTPWM, TIM_OC_PRE_LOAD_ENABLE);
            TIM_SetCmp1(TIM_OUTPWM, 0);
            break;
            
        case 2:
            TIM_OCInitStructure.Pulse = CCR2_Val;  // 确保 CCR2_Val 已初始化
            TIM_InitOc2(TIM_OUTPWM, &TIM_OCInitStructure);
            TIM_ConfigOc2Preload(TIM_OUTPWM, TIM_OC_PRE_LOAD_ENABLE);
            TIM_SetCmp2(TIM_OUTPWM, 0);
            break;
            
        // 可以添加更多通道...
            
        default:
            // 错误处理
            return;
    }
	
			TIM_EnableCtrlPwmOutputs(TIMPWM,ENABLE);
		
			TIM_ConfigArPreload(TIMPWM, ENABLE);
			/* TIM_OUTPWM enable counter */
			TIM_Enable(TIMPWM, ENABLE);
 
}

	
	
void TIM3_PWM_LED(void)
{
 
    PrescalerValue = 1;  
    /* Time base configuration */
    TIM_InitTimBaseStruct(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.Period        = 1600 ;
    TIM_TimeBaseStructure.Prescaler     = 1;
    TIM_TimeBaseStructure.ClkDiv        = TIM_CLK_DIV1;
    TIM_TimeBaseStructure.CounterMode   = TIM_CNT_MODE_UP;

    TIM_InitTimeBase(TIM_OUTPWM, &TIM_TimeBaseStructure);

    /* PWM1 Mode configuration: Channel1 */
    TIM_InitOcStruct(&TIM_OCInitStructure);
    TIM_OCInitStructure.OCMode      = TIM_OCMODE_PWM1;
    TIM_OCInitStructure.OutputState = TIM_OUTPUT_STATE_ENABLE;
    TIM_OCInitStructure.Pulse       = 0;
    TIM_OCInitStructure.OCPolarity  = TIM_OC_POLARITY_HIGH;

    TIM_InitOc1(TIM_OUTPWM, &TIM_OCInitStructure);

    TIM_ConfigOc1Preload(TIM_OUTPWM, TIM_OC_PRE_LOAD_ENABLE);

		/* PWM1 Mode configuration: Channel2 */
		TIM_InitOcStruct(&TIM_OCInitStructure);
		TIM_OCInitStructure.OCMode      = TIM_OCMODE_PWM1;
		TIM_OCInitStructure.OutputState = TIM_OUTPUT_STATE_ENABLE;
		TIM_OCInitStructure.Pulse       = 0;
		TIM_OCInitStructure.OCPolarity  = TIM_OC_POLARITY_HIGH;
		TIM_InitOc2(TIM_OUTPWM, &TIM_OCInitStructure);

    TIM_ConfigOc2Preload(TIM_OUTPWM, TIM_OC_PRE_LOAD_ENABLE);
 
    TIM_ConfigArPreload(TIM_OUTPWM, ENABLE);
 
    TIM_EnableCtrlPwmOutputs(TIM_OUTPWM,ENABLE);
		
    TIM_SetCmp1(TIM_OUTPWM,0); 
		
		TIM_SetCmp2(TIM_OUTPWM,0);
    /* TIM_OUTPWM enable counter */
    TIM_Enable(TIM_OUTPWM, DISABLE);
    LED_LIGHT_OFF;
}
 
void TIM3_PWM_MOTOR(void)
{
 
//    PrescalerValue = 1;  
//    /* Time base configuration */
//    TIM_InitTimBaseStruct(&TIM_TimeBaseStructure);
//    TIM_TimeBaseStructure.Period        = 3200-1;
//    TIM_TimeBaseStructure.Prescaler     = PrescalerValue;
//    TIM_TimeBaseStructure.ClkDiv        = TIM_CLK_DIV1;
//    TIM_TimeBaseStructure.CounterMode   = TIM_CNT_MODE_UP;

//    TIM_InitTimeBase(TIM_OUTPWM, &TIM_TimeBaseStructure);

    /* PWM1 Mode configuration: Channel1 */
    TIM_InitOcStruct(&TIM_OCInitStructure);
    TIM_OCInitStructure.OCMode      = TIM_OCMODE_PWM1;
    TIM_OCInitStructure.OutputState = TIM_OUTPUT_STATE_ENABLE;
    TIM_OCInitStructure.Pulse       = 0;
    TIM_OCInitStructure.OCPolarity  = TIM_OC_POLARITY_LOW;

    TIM_InitOc3(TIM_OUTPWM, &TIM_OCInitStructure);

    TIM_ConfigOc3Preload(TIM_OUTPWM, TIM_OC_PRE_LOAD_ENABLE);
		
		
    TIM_InitOcStruct(&TIM_OCInitStructure);
    TIM_OCInitStructure.OCMode      = TIM_OCMODE_PWM1;
    TIM_OCInitStructure.OutputState = TIM_OUTPUT_STATE_ENABLE;
    TIM_OCInitStructure.Pulse       = 0;
    TIM_OCInitStructure.OCPolarity  = TIM_OC_POLARITY_LOW;

    TIM_InitOc4(TIM_OUTPWM, &TIM_OCInitStructure);

    TIM_ConfigOc4Preload(TIM_OUTPWM, TIM_OC_PRE_LOAD_ENABLE);
    TIM_ConfigArPreload(TIM_OUTPWM, ENABLE);

    TIM_EnableCtrlPwmOutputs(TIM_OUTPWM,ENABLE);

    /* TIM_OUTPWM enable counter */
    TIM_Enable(TIM_OUTPWM, ENABLE);
 
}
void TIM4_PWM_BUZZ(void)
{
 
    PrescalerValue = 1;  
    /* Time base configuration */
    TIM_InitTimBaseStruct(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.Period        = 0;
    TIM_TimeBaseStructure.Prescaler     = 1;
    TIM_TimeBaseStructure.ClkDiv        = TIM_CLK_DIV4;
    TIM_TimeBaseStructure.CounterMode   = TIM_CNT_MODE_UP;

    TIM_InitTimeBase(TIM_BUZZ, &TIM_TimeBaseStructure);

    /* PWM1 Mode configuration: Channel1 */
    TIM_InitOcStruct(&TIM_OCInitStructure);
    TIM_OCInitStructure.OCMode      = TIM_OCMODE_PWM1;
    TIM_OCInitStructure.OutputState = TIM_OUTPUT_STATE_ENABLE;
    TIM_OCInitStructure.Pulse       = 0;
    TIM_OCInitStructure.OCPolarity  = TIM_OC_POLARITY_LOW;

    TIM_InitOc3(TIM_BUZZ, &TIM_OCInitStructure);

    TIM_ConfigOc3Preload(TIM_BUZZ, TIM_OC_PRE_LOAD_ENABLE);
    TIM_EnableCtrlPwmOutputs(TIM_BUZZ,ENABLE);
    TIM_ConfigArPreload(TIM_BUZZ, ENABLE);
  
    /* Prescaler configuration */
    TIM_ConfigPrescaler(TIM_BUZZ, PrescalerValue, TIM_PSC_RELOAD_MODE_IMMEDIATE);  //开立即不能开二次蜂鸣器
	   /* TIM_OUTPWM enable counter */
	  TIM_Enable(TIM_BUZZ, ENABLE);

}




#ifdef D_433
void TIM1_Input_433(void)
{
 /* 时基配置 */
    TIM_InitTimBaseStruct(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.Period        = 0xFFFF;       
    TIM_TimeBaseStructure.Prescaler     = 64;
    TIM_TimeBaseStructure.ClkDiv        = TIM_CLK_DIV1;
    TIM_TimeBaseStructure.CounterMode   = TIM_CNT_MODE_UP;

    TIM_InitTimeBase(TIMx_433, &TIM_TimeBaseStructure);
    TIM_InitIcStruct(&TIM_ICInitStructure);
    TIM_ICInitStructure.Channel     = TIM_CH_2;
    TIM_ICInitStructure.ICPolarity  = TIM_IC_POLARITY_RISING;  
    TIM_ICInitStructure.ICSelection = TIM_IC_SELECTION_DIRECTTI;  
    TIM_ICInitStructure.ICPrescaler = TIM_IC_PSC_DIV1;  
    TIM_ICInitStructure.ICFilter    = 0x4;

    /*PWM Dual-channel opposite polarity input capture initialization*/
    TIM_ConfigPwmIc(TIMx_433, &TIM_ICInitStructure);  

    /* Select the TIM3 Input Trigger: TI2FP2 */
    TIM_SelectInputTrig(TIMx_433, TIM_TRIG_SEL_TI2FP2);  

    /* Select the slave Mode: Reset Mode */
    TIM_SelectSlaveMode(TIMx_433, TIM_SLAVE_MODE_RESET); 

    /* Enable the Master/Slave Mode */
    TIM_SelectMasterSlaveMode(TIMx_433, TIM_MASTER_SLAVE_MODE_ENABLE); 
 
    /* Enable the CC2 Interrupt Request */
    TIM_ConfigInt(TIMx_433, TIM_INT_CC2, ENABLE); 

	 /* TIM enable counter */
    TIM_Enable(TIMx_433, ENABLE); 
 
    
//    TIM_InitOcStruct(&TIM_OCInitStructure);
//    TIM_OCInitStructure.OCMode      = TIM_OCMODE_PWM1;
//    TIM_OCInitStructure.OutputState = TIM_OUTPUT_STATE_ENABLE;
//    TIM_OCInitStructure.Pulse       = CCR3_Val;
//    TIM_OCInitStructure.OCPolarity  = TIM_OC_POLARITY_HIGH;

//    TIM_InitOc3(TIM1_PWM, &TIM_OCInitStructure);

//    TIM_ConfigOc3Preload(TIM1_PWM, TIM_OC_PRE_LOAD_ENABLE);
// 
//    TIM_ConfigArPreload(TIM1_PWM, ENABLE);

//    TIM_EnableCtrlPwmOutputs(TIM1_PWM,ENABLE);

//    /* TIM_OUTPWM enable counter */
//    TIM_Enable(TIM1_PWM, ENABLE);
}
#else
void TIM1_Input_433(void)
{
    /* 假设系统时钟为64MHz，计算预分频器 */
    /* 目标：1us计数 = 1MHz计数频率 */
    /* 预分频器 = 系统时钟/目标频率 - 1 */
    /* 64MHz / 1MHz - 1 = 64 - 1 = 63 */
    uint32_t system_clock = 64000000;  // 假设64MHz
    uint32_t target_freq = 1000000;    // 1MHz = 1us
    uint32_t prescaler = (system_clock / target_freq) - 1;
    
    /* 时基配置 */
    TIM_InitTimBaseStruct(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.Period        = 0xFFFF;       // 最大计数值
    TIM_TimeBaseStructure.Prescaler     = prescaler;    // 63对应1us
    TIM_TimeBaseStructure.ClkDiv        = TIM_CLK_DIV1;
    TIM_TimeBaseStructure.CounterMode   = TIM_CNT_MODE_UP;
    TIM_TimeBaseStructure.RepetCnt      = 0;           // 重复计数器（TIM1需要）
    TIM_TimeBaseStructure.CapCh1Sel     = TIM_CAPCH1SEL_IOM;
    TIM_TimeBaseStructure.EtrOrClr      = TIM_ETRSEL;
    
    TIM_InitTimeBase(TIMx_433, &TIM_TimeBaseStructure);
    
    /* 输入捕获配置 */
    TIM_InitIcStruct(&TIM_ICInitStructure);
    TIM_ICInitStructure.Channel     = TIM_CH_2;
    TIM_ICInitStructure.ICPolarity  = TIM_IC_POLARITY_RISING;  // 初始上升沿
    TIM_ICInitStructure.ICSelection = TIM_IC_SELECTION_DIRECTTI;
    TIM_ICInitStructure.ICPrescaler = TIM_IC_PSC_DIV1;  // 每个边沿都捕获
    TIM_ICInitStructure.ICFilter    = 0x12C;              // 适当滤波，减少噪声
    
    TIM_ICInit(TIMx_433, &TIM_ICInitStructure);
    
    /* 清空中断标志 */
    TIM_ClearFlag(TIMx_433, TIM_FLAG_UPDATE);
    TIM_ClearFlag(TIMx_433, TIM_FLAG_CC2);
    TIM_ClrIntPendingBit(TIMx_433, TIM_INT_UPDATE);
    TIM_ClrIntPendingBit(TIMx_433, TIM_INT_CC2);
    
    /* 使能中断 */
    TIM_ConfigInt(TIMx_433, TIM_INT_UPDATE, ENABLE);  // 必须使能溢出中断！
    TIM_ConfigInt(TIMx_433, TIM_INT_CC2, ENABLE);
    
    /* 配置NVIC（如果使用中断）*/
    NVIC_SetPriority(TIM1_CC_IRQn, 1);  // 设置中断优先级
    NVIC_EnableIRQ(TIM1_CC_IRQn);       // 使能中断
    
    /* 预清空PWM结果结构体 */
  //  memset(&pwm_result, 0, sizeof(pwm_result));
    
    /* 使能定时器 */
    TIM_Enable(TIMx_433, ENABLE);
}
#endif
/**
*\*\name    TIM_Configuration.
*\*\fun     Configures the TIM6.
*\*\param   none
*\*\return  none 
**/
void TIM_Configuration(void)
{
    /* Compute the prescaler value */
    /* Compute the prescaler value */
    uint32_t PrescalerValue = 0;
    uint32_t PeriodValue = 0;
    
    /* 计算方法：
       系统时钟：64MHz
       目标中断周期：1ms = 0.001s
       
       方案1（推荐）：64分频，计数1000次
       64MHz ÷ 64 = 1MHz (每个计数1us)
       1MHz × 0.001s = 1000次计数
    */
    PrescalerValue = 64 - 1;     // 预分频寄存器值 = 分频数 - 1
    PeriodValue = 1000 - 1;      // 自动重装载寄存器值 = 计数次数 - 1

    /* Time base configuration */
    TIM_InitTimBaseStruct(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.Period        = PeriodValue;
    TIM_TimeBaseStructure.Prescaler     = PrescalerValue;
    TIM_TimeBaseStructure.ClkDiv        = TIM_CLK_DIV1;
    TIM_TimeBaseStructure.CounterMode   = TIM_CNT_MODE_UP;

    TIM_InitTimeBase(TIM6, &TIM_TimeBaseStructure);

    /* Prescaler configuration */
    TIM_ConfigPrescaler(TIM6, PrescalerValue, TIM_PSC_RELOAD_MODE_UPDATE);

    /* TIM6 enable update irq */
    TIM_ConfigInt(TIM6, TIM_INT_UPDATE, ENABLE);

    /* TIM6 enable counter */
    TIM_Enable(TIM6, ENABLE);
		
		
	  TIM1_Input_433();
}



void Set_PWM_Frequency(uint32_t target_freq)
{
    /* 选择要输出的频率 */
    //uint32_t target_freq = 2600;   // 2.6kHz
    //uint32_t target_freq = 2300;   // 2.3kHz  
    //uint32_t target_freq = 2900;   // 2.9kHz
    //uint32_t target_freq = 1288;   // 1.288kHz

    /* 计算对应频率的Period值 - 这是唯一需要修改的参数 */
    uint32_t PeriodValue = (64000000 / (2 * target_freq)) - 1;
    
    /* 保持其他参数不变 */
  
    uint32_t CCR_Val = (PeriodValue + 1) / 2;  // 50%占空比
 
/* Set the Autoreload value */
    TIM4->AR = PeriodValue;

    TIM_SetCmp3(TIM4, CCR_Val);
}



/* void EncodeTimeInit(void)
{

   TIM_TimeBaseInitType TIM_TimeBaseStructure;
   TIM_ICInitType TIM_ICInitStructure;
 
    
    TIM_InitTimBaseStruct(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.Period        = 3200-1;
    TIM_TimeBaseStructure.Prescaler     = PrescalerValue;
    TIM_TimeBaseStructure.ClkDiv        = TIM_CLK_DIV1;
    TIM_TimeBaseStructure.CounterMode   = TIM_CNT_MODE_UP;
 
    TIM_ConfigEncoderInterface2(TIM4, TIM_ENCODE2_QUA_MODE_TI12, TIM_IC_POLARITY_RISING,TIM_IC_POLARITY_RISING);
    TIM_InitIcStruct(&TIM_ICInitStructure);
    TIM_ICInitStructure.Channel     = TIM_CH_2;
    TIM_ICInitStructure.ICPolarity  = TIM_IC_POLARITY_RISING;  
    TIM_ICInitStructure.ICSelection = TIM_IC_SELECTION_DIRECTTI;  
    TIM_ICInitStructure.ICPrescaler = TIM_IC_PSC_DIV1;  
    TIM_ICInitStructure.ICFilter    = 0x0;
    TIM_ICInitStructure.Channel = TIM_CH_1;
    TIM_ICInit(TIM4, &TIM_ICInitStructure);
    TIM_ICInitStructure.Channel = TIM_CH_2;
    TIM_ICInit(TIM4, &TIM_ICInitStructure);
 
    TIM_ConfigArPreload(TIM4, ENABLE);
    TIM_SetCnt(TIM4, 0);
    TIM_Enable(TIM4, ENABLE);
 
    TIM_ClearFlag(TIM4, TIM_FLAG_UPDATE);
    TIM_ConfigInt(TIM4, TIM_INT_UPDATE, ENABLE);
 
}*/

/* 动态切换通道2的捕获边沿 */
void TIM_Switch_Capture_Edge( uint32_t edge_type)
{
    uint32_t tmpccen;
    
    // 读取当前的CCEN寄存器值
    tmpccen = TIMx_433->CCEN;
    
    // 先清除通道2的相关位（CC2P和CC2EN）
    tmpccen &= ~(TIM_CCEN_CC2P | TIM_CCEN_CC2EN);
    
    if (edge_type == TIM_IC_POLARITY_RISING)
    {
        // 上升沿捕获：CC2P=0, CC2EN=1
        tmpccen |= TIM_CCEN_CC2EN;  // 使能通道2
        // CC2P保持0（默认上升沿）
    }
    else  // TIM_IC_POLARITY_FALLING
    {
        // 下降沿捕获：CC2P=1, CC2EN=1
        tmpccen |= (TIM_CCEN_CC2P | TIM_CCEN_CC2EN);
    }
    
    // 写回寄存器
    TIMx_433->CCEN = tmpccen;
}




















