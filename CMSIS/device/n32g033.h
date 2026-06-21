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
*\*\file n32g033.h
*\*\author Nsing
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/

#ifndef __N32G033_H__
#define __N32G033_H__

#ifdef __cplusplus
extern "C" {
#endif

/** N32G033_Library_Basic **/

/** In the following line adjust the External High Speed oscillator (HSE) Startup
    Timeout value **/
#define HSI_STARTUP_TIMEOUT ((uint16_t)0x0500U) /* Time out for HSI start up */
#define LSI_STARTUP_TIMEOUT ((uint16_t)0x1000U) /* Time out for LSI start up */

#define HSI_VALUE (64000000U) /* Value of the Internal oscillator in Hz*/

#define LSI_VALUE (32000U) /* Value of the Internal Low Speed oscillator in Hz*/

#define __N32G033_STDPERIPH_VERSION_MAIN (0x01) /* [31:24] main version */
#define __N32G033_STDPERIPH_VERSION_SUB1 (0x00) /* [23:16] sub1 version */
#define __N32G033_STDPERIPH_VERSION_SUB2 (0x00) /* [15:8]  sub2 version */
#define __N32G033_STDPERIPH_VERSION_RC   (0x00) /* [7:0]  release candidate */

/**  N32G033 Standard Peripheral Library version number **/
#define __N32G033_STDPERIPH_VERSION     ((__N32G033_STDPERIPH_VERSION_MAIN << 24)\
                                        |(__N32G033_STDPERIPH_VERSION_SUB1 << 16)\
                                        |(__N32G033_STDPERIPH_VERSION_SUB2 << 8)\
                                        |(__N32G033_STDPERIPH_VERSION_RC))

/** Configuration of the Cortex-M0 Processor and Core Peripherals **/
#define __NVIC_PRIO_BITS       2 /* N32G033 uses 4 Bits for the Priority Levels    */
#define __Vendor_SysTickConfig 0 /* Set to 1 if different SysTick Config is used */

/** N32G033 Interrupt Number Definition **/
typedef enum IRQn
{
    /******  Cortex-M0 Processor Exceptions Numbers **/
    NonMaskableInt_IRQn      = -14, /* 2 Non Maskable Interrupt                            */
    HardFault_IRQn           = -13, /* 3 Hard Fault Interrupt                              */
    SVCall_IRQn              = -5,  /* 11 Cortex-M0 SV Call Interrupt                      */
    PendSV_IRQn              = -2,  /* 14 Cortex-M0 Pend SV Interrupt                      */
    SysTick_IRQn             = -1,  /* 15 Cortex-M0 System Tick Interrupt                  */

    /******  N32G033 specific Interrupt Numbers **/
    PVD_IRQn                 = 0,  /* PVD through EXTI Line 16 detection Interrupt         */
    FLASH_IRQn               = 1,  /* FLASH global Interrupt                               */
    EXTI0_6_IRQn             = 2,  /* EXTI Line0/6 Interrupt                               */
    COMP_IRQn                = 3,  /* COMP(through EXTI line 18) Interrupt                 */
    UART1_IRQn               = 4,  /* UART1 global Interrupt                               */	
    UART2_IRQn               = 5,  /* UART2 global Interrupt                               */
    TIM1_BRK_UP_TRG_COM_IRQn = 6,  /* TIM1 Break Update Trigger and Commutation Interrupt  */	
    TIM1_CC_IRQn             = 7,  /* TIM1 Capture Compare Interrupt                       */	
    ADC_IRQn                 = 8,  /* ADC global Interrupts                                */	
    SPI1_IRQn                = 9,  /* SPI1 global Interrupts                               */	
    IWDG_IRQn                = 10, /* IWDG global Interrupts                               */	
    TIM4_IRQn                = 11, /* TIM4 global Interrupt                                */	
    TIM3_IRQn                = 12, /* TIM3 global Interrupt                                */
    TIM6_IRQn                = 13, /* TIM6 global Interrupt                                */
    UART3_IRQn               = 14, /* UART3 global Interrupt                               */
    SPI2_IRQn                = 15, /* SPI2 global Interrupts                               */
    I2C1_EV_IRQn             = 16, /* I2C1 event Interrupts                                */
    I2C1_ER_IRQn             = 17, /* I2C1 error Interrupts                                */
    I2C2_EV_IRQn             = 18, /* I2C2 event Interrupts                                */
    I2C2_ER_IRQn             = 19, /* I2C2 error Interrupts                                */
    DMA_IRQn                 = 20, /* DMA global Interrupt                                 */
} IRQn_Type;

#include "core_cm0.h"
#include "system_n32g033.h"
#include <stdint.h>
#include <stdbool.h>

typedef int32_t s32;
typedef int16_t s16;
typedef int8_t s8;

typedef const int32_t sc32; /* Read Only */
typedef const int16_t sc16; /* Read Only */
typedef const int8_t sc8;   /* Read Only */

typedef __IO int32_t vs32;
typedef __IO int16_t vs16;
typedef __IO int8_t vs8;

typedef __I int32_t vsc32; /* Read Only */
typedef __I int16_t vsc16; /* Read Only */
typedef __I int8_t vsc8;   /* Read Only */

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

typedef const uint32_t uc32; /* Read Only */
typedef const uint16_t uc16; /* Read Only */
typedef const uint8_t uc8;   /* Read Only */

typedef __IO uint32_t vu32;
typedef __IO uint16_t vu16;
typedef __IO uint8_t vu8;

typedef __I uint32_t vuc32; /* Read Only */
typedef __I uint16_t vuc16; /* Read Only */
typedef __I uint8_t vuc8;   /* Read Only */

typedef enum {RESET = 0, SET = !RESET} FlagStatus, INTStatus;

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;

typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;


/* N32G033 Standard Peripheral Library old definitions (maintained for legacy purpose) */
#define HSEStartUp_TimeOut HSE_STARTUP_TIMEOUT
#define HSE_Value          HSE_VALUE
#define HSI_Value          HSI_VALUE

/** Analog to Digital Converter **/
typedef struct
{
    __IO uint32_t STS;     	//0x00
	__IO uint32_t CTRL1;    //0x04 
    __IO uint32_t CTRL2;   	//0x08  
    __IO uint32_t CTRL3;	//0x0C   
    __IO uint32_t SAMPT1;	//0x10
	__IO uint32_t SAMPT2;	//0x14
	__IO uint32_t AWDHIGH;  //0x18  
	__IO uint32_t AWDLOW;	//0x1c 
	__IO uint32_t AWDEN;	//0x20  
	__IO uint32_t PHCFG;    //0x24  
	__IO uint32_t TRIGSEL;	//0x28  
	__IO uint32_t PHSWTRIG; //0x2c	
	__IO uint32_t SEQ1;	    //0x30	
  	__IO uint32_t SEQ2;	    //0x34  
    __IO uint32_t DAT0;		//0x38
    __IO uint32_t DAT1;		//0x3c	
    __IO uint32_t DAT2;	  	//0x40
    __IO uint32_t DAT3;	  	//0x44
    __IO uint32_t DAT4;		//0x48
    __IO uint32_t DAT5;		//0x4c
    __IO uint32_t DAT6;		//0x50	
    __IO uint32_t DAT7;	  	//0x54
    __IO uint32_t DAT8;		//0x58		
    __IO uint32_t DAT9;		//0x5c	
    __IO uint32_t DATI;		//0x5c				
} ADC_Module;

/** OPAMP **/
typedef struct
{
    __IO uint32_t OPAMP1_CS;  //0x00 
    __IO uint32_t OPAMP2_CS;  //0x04 
    __IO uint32_t OPAMP3_CS;  //0x08
    __IO uint32_t LOCK;       //0x0C
    __IO uint32_t VREFSEL;    //0x10
} OPAMP_Module;

/** COMP **/
typedef struct
{
    __IO uint32_t INTEN;     //0x00
    __IO uint32_t INTSTS;    //0x04
    __IO uint32_t RES1;      //0x08
    __IO uint32_t LOCK;      //0x0C
    __IO uint32_t CTRL;      //0x10
    __IO uint32_t FILC;      //0x14
    __IO uint32_t FILP;      //0x18 
    __IO uint32_t RES2[9];   //0x1C ~ 0x3C
    __IO uint32_t INVREF;    //0x40 
} COMP_Module;

/*** DMA Controller ***/
typedef struct
{
    __IO uint32_t CHCFG;		//0x08+20 * (x-1)
    __IO uint32_t TXNUM;		//0x0c+20 * (x-1)
    __IO uint32_t PADDR;		//0x10+20 * (x-1)
    __IO uint32_t MADDR;		//0x14+20 * (x-1)
    __IO uint32_t CHSEL;		//0x18+20 * (x-1)
} DMA_ChannelType;

typedef struct
{
    __IO uint32_t INTSTS;					//0x00
    __IO uint32_t INTCLR;					//0x04
    __IO DMA_ChannelType DMA_Channel[3];
} DMA_Module;

/** External Interrupt/Event Controller **/
typedef struct
{
	__IO uint32_t EMASK;    /*offset 0x00*/
    __IO uint32_t IMASK;    /*offset 0x04*/
    __IO uint32_t FT_CFG;   /*offset 0x08*/
    __IO uint32_t RT_CFG;   /*offset 0x0C*/
    __IO uint32_t PEND;     /*offset 0x10*/
	__IO uint32_t SWIE;     /*offset 0x14*/
} EXTI_Module;

/** FLASH Registers **/
typedef struct
{
    __IO uint32_t AC;
    __IO uint32_t KEY;
    __IO uint32_t OPTKEY;
    __IO uint32_t STS;
    __IO uint32_t CTRL;
    __IO uint32_t ADD;
	__IO uint32_t OB2;
    __IO uint32_t OB;
    __IO uint32_t WRP;      //0X20  
	uint32_t RESERVED[11];
    __IO uint32_t VTOR;     //0X50
} FLASH_Module;

/** Option Bytes Registers **/
typedef struct
{
    __IO uint32_t USER4_RDP1;	//0x00 
    __IO uint32_t USER0;        //0x04	
    __IO uint32_t USER1;        //0x08
    __IO uint32_t USER3_USER2;  //0x0C		
	__IO uint32_t Data1_Data0;  //0x10
	__IO uint32_t WRP1_WRP0;    //0x14
    __IO uint32_t RDP2;   		//0x18	
} OB_Module;


/** General Purpose I/O **/
typedef struct
{
    __IO uint32_t PMODE;  /*offset 0x00*/
    __IO uint32_t POTYPE; /*offset 0x04*/
    uint32_t RESERVED0;   
    __IO uint32_t PUPD;   /*offset 0x0C*/
    __IO uint32_t PID;    /*offset 0x10*/
    __IO uint32_t POD;    /*offset 0x14*/
    __IO uint32_t PBSC;   /*offset 0x18*/
    __IO uint32_t PLOCK;  /*offset 0x1C*/
    __IO uint32_t AFL;    /*offset 0x20*/
    __IO uint32_t AFH;    /*offset 0x24*/
    __IO uint32_t PBC;    /*offset 0x28*/
	__IO uint32_t DS;     /*offset 0x2C*/
} GPIO_Module;

/** Alternate Function I/O **/
typedef struct
{
    __IO uint32_t CFG;
    uint32_t RESERVED0;
    __IO uint32_t EXTI_CFG[2];
    __IO uint32_t DIGEFT_CFG1;
    __IO uint32_t DIGEFT_CFG2;
    __IO uint32_t DIGEFT_CFG3;
} AFIO_Module;

/** Inter Integrated Circuit Interface **/
typedef struct
{
    __IO uint32_t CTRL1;          //0x00 
    __IO uint32_t CTRL2;          //0x04
    __IO uint16_t OADDR1;         //0x08
    uint16_t  RESERVED1;
    __IO uint16_t OADDR2;         //0x0C
    uint16_t  RESERVED2;
    __IO uint16_t DAT;            //0x10
    uint16_t  RESERVED3; 
    __IO uint32_t STS1;           //0x14  
    __IO uint32_t STS2;           //0x18  
    __IO uint16_t CLKCTRL;        //0x1C
    uint16_t  RESERVED4;
    __IO uint16_t TMRISE;         //0x20
    uint16_t  RESERVED5; 
    uint32_t RESERVED6;           //0x24   
    __IO uint16_t GFLTRCTRL;      //0x28
    uint16_t  RESERVED10; 
} I2C_Module;

/** Independent WATCHDOG **/
typedef struct
{
    __IO uint32_t KEY;    //0x00
    __IO uint32_t STS;    //0x04
    __IO uint32_t PREDIV; //0x08
    __IO uint32_t RELV;   //0x0C
    __IO uint32_t CTRL;	  //0x10
} IWDG_Module;

/**  Power Control **/
typedef struct
{
	__IO uint32_t CTRL;       //0x00
	__IO uint32_t CTRLSTS;    //0x04
	__IO uint32_t CTRL2;      //0x08
	__IO uint32_t DBG_CTRL;   //0x0C
} PWR_Module;


/** Reset and Clock Control **/
typedef struct
{
    __IO uint32_t CTRL;      //0x0
    __IO uint32_t CFG;       //0x4
    __IO uint32_t CLKINT;    //0x8
    __IO uint32_t APBPRST;   //0xC
    __IO uint32_t AHBPCLKEN; //0x10
    __IO uint32_t APBPCLKEN; //0x14
    uint32_t RESERVED0;      //0x18
    __IO uint32_t CTRLSTS;   //0x1C
    __IO uint32_t AHBPRST;   //0x20
    __IO uint32_t CFG2;      //0x24
    uint32_t RESERVED1;      //0x28
	__IO uint32_t LSICAL;    //0x2C
	__IO uint32_t EMCCTRL;   //0x30
	__IO uint32_t LSCTRL;    //0x34
	__IO uint32_t TIMFILTCFG; //0x38
} RCC_Module;

/** Serial Peripheral Interface **/
typedef struct
{
    __IO uint32_t CTRL1;   // 0x00
    __IO uint32_t CTRL2;   // 0x04
    __IO uint32_t STS;     // 0x08
    __IO uint32_t DAT;     // 0x0C
    __IO uint32_t CRCTDAT; // 0x10
    __IO uint32_t CRCRDAT; // 0x14
    __IO uint32_t CRCPOLY; // 0x18
    __IO uint32_t RESERVED0[7]; // 0x1C
    __IO uint32_t CTRL3;   // 0x38
} SPI_Module;

/** TIM **/
typedef struct
{
    __IO uint32_t CTRL1;    //0x00
    __IO uint32_t CTRL2;   	//0x04
    __IO uint32_t STS;	    //0x08
    __IO uint32_t EVTGEN;	//0x0C
    __IO uint32_t SMCTRL;	//0x10
    __IO uint32_t DINTEN;	//0x14
    __IO uint32_t CCMOD1;	//0x18
    __IO uint32_t CCMOD2;	//0x1C
    __IO uint32_t CCMOD3;	//0x20
    __IO uint32_t CCEN;	    //0x24
    __IO uint32_t CCDAT1;	//0x28
    __IO uint32_t CCDAT2;	//0x2C
    __IO uint32_t CCDAT3;	//0x30
    __IO uint32_t CCDAT4;	//0x34
    __IO uint32_t CCDAT5;	//0x38
    __IO uint32_t CCDAT6;	//0x3C    
    __IO uint32_t PSC;	    //0x40   
    __IO uint32_t AR;	    //0x44
    __IO uint32_t CNT;	    //0x48
    __IO uint32_t REPCNT;	//0x4C
    __IO uint32_t BKDT;	    //0x50
    __IO uint32_t CCDAT7;	//0x54
    __IO uint32_t RESERVED0[2];	//0x58 //0x5C
    __IO uint32_t BKFR;	    //0x60
    __IO uint32_t C1FILT;	//0x64
    __IO uint32_t C2FILT;	//0x68
    __IO uint32_t C3FILT;	//0x6C
    __IO uint32_t RESERVED1;	//0x70
    __IO uint32_t FILTO;	//0x74
    __IO uint32_t RESERVED2;	//0x78
    __IO uint32_t AF1;	    //0x7C
    __IO uint32_t RESERVED3[2];	//0x80//0x84
    __IO uint32_t ENCDAT;	//0x88
    __IO uint32_t ENCMCTRL;	//0x8C
    __IO uint32_t ENCLVR;	//0x90    
    __IO uint32_t DCTRL;	//0x94
    __IO uint32_t DADDR;	//0x98
} TIM_Module;

/** Universal Synchronous Asynchronous Receiver Transmitter **/
typedef struct
{
    __IO uint32_t CTRL1;    //0x00
    __IO uint32_t CTRL2;    //0x04
    __IO uint32_t CTRL3;    //0x08
    __IO uint32_t STS;      //0x0C
    __IO uint32_t DAT;      //0x10
    __IO uint32_t BRCF;     //0x14
    __IO uint32_t GTP;      //0x18
    __IO uint32_t FIFO;     //0x1C
    __IO uint32_t IFW;      //0x20
    __IO uint32_t RTO;      //0x24
    __IO uint32_t WKUP;     //0x28
} UART_Module;


/** HDIV **/
typedef struct
{
    __IO uint32_t CTRLSTS;
    __IO uint32_t DIVIDEND;
    __IO uint32_t DIVISOR;
    __IO uint32_t QUOTIENT;
    __IO uint32_t REMAINDER;
    __IO uint32_t DIVBY0;
} HDIV_Module;

/** SQRT **/
typedef struct
{
    __IO uint32_t CTRLSTS;
    __IO uint32_t RADICAND;
    __IO uint32_t ROOT;
} SQRT_Module;


#define FLASH_BASE  ((uint32_t)0x08000000) /* FLASH base address in the alias region */
#define SRAM_BASE   ((uint32_t)0x20000000) /* SRAM base address in the alias region */
#define PERIPH_BASE ((uint32_t)0x40000000) /* Peripheral base address in the alias region */

#define UCID_BASE          ((uint32_t)0x1FFFF4D0) /* UCID Address */
#define UCID_LENGTH        ((uint8_t)0x10)        /* UCID Length : 16 Bytes */
#define UID_BASE           ((uint32_t)0x1FFFF500) /* UID Address */
#define UID_LENGTH         ((uint8_t)0x0C)        /* UID Length : 12 Bytes */
#define DBGMCU_ID_BASE     ((uint32_t)0x1FFFF510) /* DBGMCU_ID Address */
#define DBGMCU_ID_LENGTH   ((uint8_t)0x08)        /* DBGMCU_ID Length : 8 Bytes */

/* Peripheral memory map */
#define APBPERIPH_BASE  (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE  (PERIPH_BASE + 0x20000)

/* APB */
#define TIM3_BASE          (APBPERIPH_BASE + 0x0400 - 0x10000)
#define TIM6_BASE          (APBPERIPH_BASE + 0x1000 - 0x10000)
#define OPA_BASE           (APBPERIPH_BASE + 0x2000 - 0x10000)
#define COMP_BASE          (APBPERIPH_BASE + 0x2400 - 0x10000)
#define IWDG_BASE          (APBPERIPH_BASE + 0x3000 - 0x10000)
#define UART2_BASE         (APBPERIPH_BASE + 0x4400 - 0x10000)
#define UART3_BASE         (APBPERIPH_BASE + 0x4800 - 0x10000)
#define I2C1_BASE          (APBPERIPH_BASE + 0x5400 - 0x10000)
#define I2C2_BASE          (APBPERIPH_BASE + 0x5800 - 0x10000)
#define PWR_BASE           (APBPERIPH_BASE + 0x7000 - 0x10000)
#define EXTI_BASE          (APBPERIPH_BASE + 0x0400)
#define SPI1_BASE          (APBPERIPH_BASE + 0x2000)
#define TIM1_BASE          (APBPERIPH_BASE + 0x2C00)
#define TIM4_BASE          (APBPERIPH_BASE + 0x3400)
#define UART1_BASE         (APBPERIPH_BASE + 0x3800)
#define SPI2_BASE          (APBPERIPH_BASE + 0x4400)

/* AHB */
#define DMA_BASE           (AHBPERIPH_BASE + 0x0000)
#define DMA_CH1_BASE       (AHBPERIPH_BASE + 0x0008)
#define DMA_CH2_BASE       (AHBPERIPH_BASE + 0x001C)
#define DMA_CH3_BASE       (AHBPERIPH_BASE + 0x0030)
#define SQRT_BASE          (AHBPERIPH_BASE + 0x0400)
#define ADC_BASE           (AHBPERIPH_BASE + 0x0800)
#define RCC_BASE           (AHBPERIPH_BASE + 0x1000)
#define FLASH_R_BASE       (AHBPERIPH_BASE + 0x2000) /* Flash registers base address */
#define OB_BASE            ((uint32_t)0x1FFFF600U)    /* Flash Option Bytes base address */
#define GPIOA_BASE         (AHBPERIPH_BASE + 0x3000) 
#define GPIOB_BASE         (AHBPERIPH_BASE + 0x3100) 
#define GPIOF_BASE         (AHBPERIPH_BASE + 0x3200) 
#define AFIO_BASE          (AHBPERIPH_BASE + 0x3300)
#define HDIV_BASE          (AHBPERIPH_BASE + 0x8000)

#define TIM3        ((TIM_Module*)TIM3_BASE)
#define TIM6        ((TIM_Module*)TIM6_BASE)
#define OPAMP       ((OPAMP_Module*)OPA_BASE)
#define COMP        ((COMP_Module*)COMP_BASE)
#define IWDG        ((IWDG_Module*)IWDG_BASE)
#define UART2       ((UART_Module*)UART2_BASE)
#define UART3       ((UART_Module*)UART3_BASE)
#define I2C1        ((I2C_Module*)I2C1_BASE)
#define I2C2        ((I2C_Module*)I2C2_BASE)
#define PWR         ((PWR_Module*)PWR_BASE)
#define EXTI        ((EXTI_Module*)EXTI_BASE)
#define SPI1        ((SPI_Module*)SPI1_BASE)
#define TIM1        ((TIM_Module*)TIM1_BASE)
#define TIM4        ((TIM_Module*)TIM4_BASE)
#define UART1       ((UART_Module*)UART1_BASE)
#define SPI2        ((SPI_Module*)SPI2_BASE)
#define DMA         ((DMA_Module*)DMA_BASE)
#define DMA_CH1     ((DMA_ChannelType*)DMA_CH1_BASE)
#define DMA_CH2     ((DMA_ChannelType*)DMA_CH2_BASE)
#define DMA_CH3     ((DMA_ChannelType*)DMA_CH3_BASE)
#define SQRT        ((SQRT_Module*)SQRT_BASE)
#define ADC         ((ADC_Module*)ADC_BASE)
#define RCC         ((RCC_Module*)RCC_BASE)
#define FLASH       ((FLASH_Module*)FLASH_R_BASE)
#define GPIOA       ((GPIO_Module*)GPIOA_BASE)
#define GPIOB       ((GPIO_Module*)GPIOB_BASE)
#define GPIOF       ((GPIO_Module*)GPIOF_BASE)
#define AFIO        ((AFIO_Module*)AFIO_BASE)
#define HDIV        ((HDIV_Module*)HDIV_BASE)
#define OBT         ((OB_Module*)OB_BASE)




/***  Peripheral Registers_Bits_Definition   ***/
/******************************************************************************/
/*                                                                            */
/*                             Power Control                                  */
/*                                                                            */
/******************************************************************************/
/******** Bit definition for PWR_CTRL register  ********/
#define PWR_CTRL_NRSTCNT                                 ((uint32_t)0x00780000U)         /* Bit[22:19] */
#define PWR_CTRL_NRSTCNT_0                               ((uint32_t)0x00080000U)         /* Bit19*/
#define PWR_CTRL_NRSTCNT_1                               ((uint32_t)0x00100000U)         /* Bit20*/
#define PWR_CTRL_NRSTCNT_2                               ((uint32_t)0x00200000U)         /* Bit21*/
#define PWR_CTRL_NRSTCNT_3                               ((uint32_t)0x00400000U)         /* Bit22*/
#define PWR_CTRL_PVDCNT                                  ((uint32_t)0x0007C000U)         /* Bit[18:14] */
#define PWR_CTRL_PVDCNT_0                                ((uint32_t)0x00004000U)         /* Bit14*/
#define PWR_CTRL_PVDCNT_1                                ((uint32_t)0x00008000U)         /* Bit15*/
#define PWR_CTRL_PVDCNT_2                                ((uint32_t)0x00010000U)         /* Bit16*/
#define PWR_CTRL_PVDCNT_3                                ((uint32_t)0x00020000U)         /* Bit17*/
#define PWR_CTRL_PVDCNT_4                                ((uint32_t)0x00040000U)         /* Bit18*/
#define PWR_CTRL_IWDGRSTEN                               ((uint32_t)0x00001000U)         /* Bit[12] */
#define PWR_CTRL_PLS                                     ((uint32_t)0x000001E0U)         /* Bit[8:5] */
#define PWR_CTRL_PLS_0                                   ((uint32_t)0x00000020U)         /* Bit5*/
#define PWR_CTRL_PLS_1                                   ((uint32_t)0x00000040U)         /* Bit6*/
#define PWR_CTRL_PLS_2                                   ((uint32_t)0x00000080U)         /* Bit7*/
#define PWR_CTRL_PLS_3                                   ((uint32_t)0x00000100U)         /* Bit8*/
#define PWR_CTRL_PVDEN                                   ((uint32_t)0x00000010U)         /* Bit[4] */

/******** Bit definition for PWR_CTRLSTS register  ********/
#define PWR_CTRLSTS_PVDO                                    ((uint32_t)0x00000004U)         /* Bit[2] */

/******** Bit definition for PWR_CTRL2 register  ********/
#define PWR_CTRL2_MRLPDLY                                 ((uint32_t)0x00001FFEU)         /* Bit[12:1] */
#define PWR_CTRL2_MRLPDLY_0                               ((uint32_t)0x00000002U)         /* Bit1*/
#define PWR_CTRL2_MRLPDLY_1                               ((uint32_t)0x00000004U)         /* Bit2*/
#define PWR_CTRL2_MRLPDLY_2                               ((uint32_t)0x00000008U)         /* Bit3*/
#define PWR_CTRL2_MRLPDLY_3                               ((uint32_t)0x00000010U)         /* Bit4*/
#define PWR_CTRL2_MRLPDLY_4                               ((uint32_t)0x00000020U)         /* Bit5*/
#define PWR_CTRL2_MRLPDLY_5                               ((uint32_t)0x00000040U)         /* Bit6*/
#define PWR_CTRL2_MRLPDLY_6                               ((uint32_t)0x00000080U)         /* Bit7*/
#define PWR_CTRL2_MRLPDLY_7                               ((uint32_t)0x00000100U)         /* Bit8*/
#define PWR_CTRL2_MRLPDLY_8                               ((uint32_t)0x00000200U)         /* Bit9*/
#define PWR_CTRL2_MRLPDLY_9                               ((uint32_t)0x00000400U)         /* Bit10*/
#define PWR_CTRL2_MRLPDLY_10                              ((uint32_t)0x00000800U)         /* Bit11*/
#define PWR_CTRL2_MRLPDLY_11                              ((uint32_t)0x00001000U)         /* Bit12*/
#define PWR_CTRL2_MRLPEN                                  ((uint32_t)0x00000001U)         /* Bit[0] */

/******** Bit definition for DBG_CTRL register  ********/
#define DBG_CTRL_TIM6STP                                 ((uint32_t)0x00040000U)         /* Bit[18] */
#define DBG_CTRL_I2C2TIMOUT                              ((uint32_t)0x00010000U)         /* Bit[16] */
#define DBG_CTRL_I2C1TIMOUT                              ((uint32_t)0x00008000U)         /* Bit[15] */
#define DBG_CTRL_TIM4STP                                 ((uint32_t)0x00002000U)         /* Bit[13] */
#define DBG_CTRL_TIM3STP                                 ((uint32_t)0x00001000U)         /* Bit[12] */
#define DBG_CTRL_TIM1STP                                 ((uint32_t)0x00000400U)         /* Bit[10] */
#define DBG_CTRL_IWDGSTP                                 ((uint32_t)0x00000100U)         /* Bit[8] */


/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/

/******** Bit definition for RCC_CTRL register  ********/
#define RCC_CTRL_HSITRIM                                 ((uint32_t)0x007FE000U)         /* Bit[22:13] */
#define RCC_CTRL_HSITRIM_0                               ((uint32_t)0x00002000U)         /* Bit13*/
#define RCC_CTRL_HSITRIM_1                               ((uint32_t)0x00004000U)         /* Bit14*/
#define RCC_CTRL_HSITRIM_2                               ((uint32_t)0x00008000U)         /* Bit15*/
#define RCC_CTRL_HSITRIM_3                               ((uint32_t)0x00010000U)         /* Bit16*/
#define RCC_CTRL_HSITRIM_4                               ((uint32_t)0x00020000U)         /* Bit17*/
#define RCC_CTRL_HSITRIM_5                               ((uint32_t)0x00040000U)         /* Bit18*/
#define RCC_CTRL_HSITRIM_6                               ((uint32_t)0x00080000U)         /* Bit19*/
#define RCC_CTRL_HSITRIM_7                               ((uint32_t)0x00100000U)         /* Bit20*/
#define RCC_CTRL_HSITRIM_8                               ((uint32_t)0x00200000U)         /* Bit21*/
#define RCC_CTRL_HSITRIM_9                               ((uint32_t)0x00400000U)         /* Bit22*/
#define RCC_CTRL_LSICALCF                                ((uint32_t)0x00000800U)         /* Bit[11] */
#define RCC_CTRL_LSICALLEN                               ((uint32_t)0x00000600U)         /* Bit[10:9] */
#define RCC_CTRL_LSICALLEN_0                             ((uint32_t)0x00000200U)         /* Bit9*/
#define RCC_CTRL_LSICALLEN_1                             ((uint32_t)0x00000400U)         /* Bit10*/
#define RCC_CTRL_LSICALEN                                ((uint32_t)0x00000100U)         /* Bit[8] */
#define RCC_CTRL_HSIRDF                                  ((uint32_t)0x00000002U)         /* Bit[1] */
#define RCC_CTRL_HSIEN                                   ((uint32_t)0x00000001U)         /* Bit[0] */

/******** Bit definition for RCC_CFG register  ********/
#define RCC_CFG_MCOPRES                                 ((uint32_t)0x70000000U)         /* Bit[30:28] */
#define RCC_CFG_MCOPRES_0                               ((uint32_t)0x10000000U)         /* Bit28*/
#define RCC_CFG_MCOPRES_1                               ((uint32_t)0x20000000U)         /* Bit29*/
#define RCC_CFG_MCOPRES_2                               ((uint32_t)0x40000000U)         /* Bit30*/
#define RCC_CFG_MCO                                     ((uint32_t)0x0C000000U)         /* Bit[27:26] */
#define RCC_CFG_MCO_0                                   ((uint32_t)0x04000000U)         /* Bit26*/
#define RCC_CFG_MCO_1                                   ((uint32_t)0x08000000U)         /* Bit27*/
#define RCC_CFG_SYSPRES                                 ((uint32_t)0x00010000U)         /* Bit[16] */
#define RCC_CFG_TIMXCLKSEL                              ((uint32_t)0x00002000U)         /* Bit[13] */
#define RCC_CFG_TIM6CLKSEL                              ((uint32_t)0x00001000U)         /* Bit[12] */
#define RCC_CFG_UART3CLKSEL                             ((uint32_t)0x00000800U)         /* Bit[11] */
#define RCC_CFG_APBPRES                                 ((uint32_t)0x00000700U)         /* Bit[10:8] */
#define RCC_CFG_APBPRES_0                               ((uint32_t)0x00000100U)         /* Bit8*/
#define RCC_CFG_APBPRES_1                               ((uint32_t)0x00000200U)         /* Bit9*/
#define RCC_CFG_APBPRES_2                               ((uint32_t)0x00000400U)         /* Bit10*/
#define RCC_CFG_AHBPRES                                 ((uint32_t)0x00000070U)         /* Bit[6:4] */
#define RCC_CFG_AHBPRES_0                               ((uint32_t)0x00000010U)         /* Bit4*/
#define RCC_CFG_AHBPRES_1                               ((uint32_t)0x00000020U)         /* Bit5*/
#define RCC_CFG_AHBPRES_2                               ((uint32_t)0x00000040U)         /* Bit6*/
#define RCC_CFG_SCLKSTS                                 ((uint32_t)0x00000002U)         /* Bit[1] */
#define RCC_CFG_SCLKSW                                  ((uint32_t)0x00000001U)         /* Bit[0] */

#define RCC_CFG_SCLKSTS_HSI                             ((uint32_t)0x00000000U) /* HSI clock used as system clock*/
#define RCC_CFG_SCLKSTS_LSI                             ((uint32_t)0x00000002U) /* LSI oscillator used as system clock */

/******** Bit definition for RCC_CLKINT register  ********/
#define RCC_CLKINT_HSIRDCLR                                ((uint32_t)0x00040000U)         /* Bit[18] */
#define RCC_CLKINT_LSIRDCLR                                ((uint32_t)0x00010000U)         /* Bit[16] */
#define RCC_CLKINT_HSIRDF                                  ((uint32_t)0x00000004U)         /* Bit[2] */
#define RCC_CLKINT_LSIRDF                                  ((uint32_t)0x00000001U)         /* Bit[0] */

/******** Bit definition for RCC_APBPRST register  ********/
#define RCC_APBPRST_OPARST                                  ((uint32_t)0x80000000U)         /* Bit[31] */
#define RCC_APBPRST_COMPRST                                 ((uint32_t)0x20000000U)         /* Bit[29] */
#define RCC_APBPRST_UART3RST                                ((uint32_t)0x00040000U)         /* Bit[18] */
#define RCC_APBPRST_UART2RST                                ((uint32_t)0x00020000U)         /* Bit[17] */
#define RCC_APBPRST_UART1RST                                ((uint32_t)0x00010000U)         /* Bit[16] */
#define RCC_APBPRST_TIM6RST                                 ((uint32_t)0x00008000U)         /* Bit[15] */
#define RCC_APBPRST_TIM4RST                                 ((uint32_t)0x00004000U)         /* Bit[14] */
#define RCC_APBPRST_TIM3RST                                 ((uint32_t)0x00002000U)         /* Bit[13] */
#define RCC_APBPRST_TIM1RST                                 ((uint32_t)0x00001000U)         /* Bit[12] */
#define RCC_APBPRST_SPI2RST                                 ((uint32_t)0x00000400U)         /* Bit[10] */
#define RCC_APBPRST_SPI1RST                                 ((uint32_t)0x00000200U)         /* Bit[9] */
#define RCC_APBPRST_I2C2RST                                 ((uint32_t)0x00000004U)         /* Bit[2] */
#define RCC_APBPRST_I2C1RST                                 ((uint32_t)0x00000002U)         /* Bit[1] */
#define RCC_APBPRST_IOMRST                                  ((uint32_t)0x00000001U)         /* Bit[0] */

/******** Bit definition for RCC_AHBPCLKEN register  ********/
#define RCC_AHBPCLKEN_ADCEN                                   ((uint32_t)0x00001000U)         /* Bit[12] */
#define RCC_AHBPCLKEN_HDIVEN                                  ((uint32_t)0x00000080U)         /* Bit[7] */
#define RCC_AHBPCLKEN_SQRTEN                                  ((uint32_t)0x00000020U)         /* Bit[5] */
#define RCC_AHBPCLKEN_DMAEN                                   ((uint32_t)0x00000001U)         /* Bit[0] */

/******** Bit definition for RCC_APBPCLKEN register  ********/
#define RCC_APBPCLKEN_OPAEN                                   ((uint32_t)0x80000000U)         /* Bit[31] */
#define RCC_APBPCLKEN_COMPFILTEN                              ((uint32_t)0x40000000U)         /* Bit[30] */
#define RCC_APBPCLKEN_COMPEN                                  ((uint32_t)0x20000000U)         /* Bit[29] */
#define RCC_APBPCLKEN_UART3EN                                 ((uint32_t)0x00040000U)         /* Bit[18] */
#define RCC_APBPCLKEN_UART2EN                                 ((uint32_t)0x00020000U)         /* Bit[17] */
#define RCC_APBPCLKEN_UART1EN                                 ((uint32_t)0x00010000U)         /* Bit[16] */
#define RCC_APBPCLKEN_TIM6EN                                  ((uint32_t)0x00008000U)         /* Bit[15] */
#define RCC_APBPCLKEN_TIM4EN                                  ((uint32_t)0x00004000U)         /* Bit[14] */
#define RCC_APBPCLKEN_TIM3EN                                  ((uint32_t)0x00002000U)         /* Bit[13] */
#define RCC_APBPCLKEN_TIM1EN                                  ((uint32_t)0x00001000U)         /* Bit[12] */
#define RCC_APBPCLKEN_SPI2EN                                  ((uint32_t)0x00000400U)         /* Bit[10] */
#define RCC_APBPCLKEN_SPI1EN                                  ((uint32_t)0x00000200U)         /* Bit[9] */
#define RCC_APBPCLKEN_PWREN                                   ((uint32_t)0x00000008U)         /* Bit[3] */
#define RCC_APBPCLKEN_I2C2EN                                  ((uint32_t)0x00000004U)         /* Bit[2] */
#define RCC_APBPCLKEN_I2C1EN                                  ((uint32_t)0x00000002U)         /* Bit[1] */
#define RCC_APBPCLKEN_IOMEN                                   ((uint32_t)0x00000001U)         /* Bit[0] */

/******** Bit definition for RCC_CTRLSTS register  ********/
#define RCC_CTRLSTS_LKUPRSTF                                ((uint32_t)0x00000800U)         /* Bit[11] */
#define RCC_CTRLSTS_EMCGBNF                                 ((uint32_t)0x00000200U)         /* Bit[9] */
#define RCC_CTRLSTS_EMCGBF                                  ((uint32_t)0x00000100U)         /* Bit[8] */
#define RCC_CTRLSTS_GLITCHRSTF                              ((uint32_t)0x00000080U)         /* Bit[7] */
#define RCC_CTRLSTS_IWDGRSTF                                ((uint32_t)0x00000040U)         /* Bit[6] */
#define RCC_CTRLSTS_SFTRSTF                                 ((uint32_t)0x00000020U)         /* Bit[5] */
#define RCC_CTRLSTS_PORRSTF                                 ((uint32_t)0x00000010U)         /* Bit[4] */
#define RCC_CTRLSTS_PINRSTF                                 ((uint32_t)0x00000008U)         /* Bit[3] */
#define RCC_CTRLSTS_RMRSTF                                  ((uint32_t)0x00000001U)         /* Bit[0] */

/******** Bit definition for RCC_AHBPRST register  ********/
#define RCC_AHBPRST_ADCRST                                  ((uint32_t)0x00001000U)         /* Bit[12] */
#define RCC_AHBPRST_HDIVRST                                 ((uint32_t)0x00000080U)         /* Bit[7] */
#define RCC_AHBPRST_SQRTRST                                 ((uint32_t)0x00000020U)         /* Bit[5] */

/******** Bit definition for RCC_CFG2 register  ********/
#define RCC_CFG2_ADCHPRE                                 ((uint32_t)0x00000007U)         /* Bit[2:0] */
#define RCC_CFG2_ADCHPRE_0                               ((uint32_t)0x00000001U)         /* Bit0*/
#define RCC_CFG2_ADCHPRE_1                               ((uint32_t)0x00000002U)         /* Bit1*/
#define RCC_CFG2_ADCHPRE_2                               ((uint32_t)0x00000004U)         /* Bit2*/

/******** Bit definition for RCC_LSICAL register  ********/
#define RCC_LSICAL_HSICALCNT                               ((uint32_t)0x00FFFFFFU)         /* Bit[23:0] */
#define RCC_LSICAL_HSICALCNT_0                             ((uint32_t)0x00000001U)         /* Bit0*/
#define RCC_LSICAL_HSICALCNT_1                             ((uint32_t)0x00000002U)         /* Bit1*/
#define RCC_LSICAL_HSICALCNT_2                             ((uint32_t)0x00000004U)         /* Bit2*/
#define RCC_LSICAL_HSICALCNT_3                             ((uint32_t)0x00000008U)         /* Bit3*/
#define RCC_LSICAL_HSICALCNT_4                             ((uint32_t)0x00000010U)         /* Bit4*/
#define RCC_LSICAL_HSICALCNT_5                             ((uint32_t)0x00000020U)         /* Bit5*/
#define RCC_LSICAL_HSICALCNT_6                             ((uint32_t)0x00000040U)         /* Bit6*/
#define RCC_LSICAL_HSICALCNT_7                             ((uint32_t)0x00000080U)         /* Bit7*/
#define RCC_LSICAL_HSICALCNT_8                             ((uint32_t)0x00000100U)         /* Bit8*/
#define RCC_LSICAL_HSICALCNT_9                             ((uint32_t)0x00000200U)         /* Bit9*/
#define RCC_LSICAL_HSICALCNT_10                            ((uint32_t)0x00000400U)         /* Bit10*/
#define RCC_LSICAL_HSICALCNT_11                            ((uint32_t)0x00000800U)         /* Bit11*/
#define RCC_LSICAL_HSICALCNT_12                            ((uint32_t)0x00001000U)         /* Bit12*/
#define RCC_LSICAL_HSICALCNT_13                            ((uint32_t)0x00002000U)         /* Bit13*/
#define RCC_LSICAL_HSICALCNT_14                            ((uint32_t)0x00004000U)         /* Bit14*/
#define RCC_LSICAL_HSICALCNT_15                            ((uint32_t)0x00008000U)         /* Bit15*/
#define RCC_LSICAL_HSICALCNT_16                            ((uint32_t)0x00010000U)         /* Bit16*/
#define RCC_LSICAL_HSICALCNT_17                            ((uint32_t)0x00020000U)         /* Bit17*/
#define RCC_LSICAL_HSICALCNT_18                            ((uint32_t)0x00040000U)         /* Bit18*/
#define RCC_LSICAL_HSICALCNT_19                            ((uint32_t)0x00080000U)         /* Bit19*/
#define RCC_LSICAL_HSICALCNT_20                            ((uint32_t)0x00100000U)         /* Bit20*/
#define RCC_LSICAL_HSICALCNT_21                            ((uint32_t)0x00200000U)         /* Bit21*/
#define RCC_LSICAL_HSICALCNT_22                            ((uint32_t)0x00400000U)         /* Bit22*/
#define RCC_LSICAL_HSICALCNT_23                            ((uint32_t)0x00800000U)         /* Bit23*/

/******** Bit definition for RCC_EMCCTRL register  ********/
#define RCC_EMCCTRL_LKUPRSTEN                               ((uint32_t)0x80000000U)         /* Bit[31] */
#define RCC_EMCCTRL_GBNSW                                   ((uint32_t)0x00800000U)         /* Bit[23] */
#define RCC_EMCCTRL_GBNRST                                  ((uint32_t)0x00400000U)         /* Bit[22] */
#define RCC_EMCCTRL_GBNDET                                  ((uint32_t)0x00200000U)         /* Bit[21] */
#define RCC_EMCCTRL_GBNDETSEL                               ((uint32_t)0x00030000U)         /* Bit[17:16] */
#define RCC_EMCCTRL_GBNDETSEL_0                             ((uint32_t)0x00010000U)         /* Bit16*/
#define RCC_EMCCTRL_GBNDETSEL_1                             ((uint32_t)0x00020000U)         /* Bit17*/
#define RCC_EMCCTRL_GBSW                                    ((uint32_t)0x00008000U)         /* Bit[15] */
#define RCC_EMCCTRL_GBRST                                   ((uint32_t)0x00004000U)         /* Bit[14] */
#define RCC_EMCCTRL_GBDET                                   ((uint32_t)0x00002000U)         /* Bit[13] */
#define RCC_EMCCTRL_GBDETSEL                                ((uint32_t)0x00000300U)         /* Bit[9:8] */
#define RCC_EMCCTRL_GBDETSEL_0                              ((uint32_t)0x00000100U)         /* Bit8*/
#define RCC_EMCCTRL_GBDETSEL_1                              ((uint32_t)0x00000200U)         /* Bit9*/
#define RCC_EMCCTRL_GVSW                                    ((uint32_t)0x00000080U)         /* Bit[7] */
#define RCC_EMCCTRL_GVRST                                   ((uint32_t)0x00000040U)         /* Bit[6] */
#define RCC_EMCCTRL_GVDET                                   ((uint32_t)0x00000020U)         /* Bit[5] */
#define RCC_EMCCTRL_GVDETSEL                                ((uint32_t)0x0000001FU)         /* Bit[4:0] */
#define RCC_EMCCTRL_GVDETSEL_0                              ((uint32_t)0x00000001U)         /* Bit0*/
#define RCC_EMCCTRL_GVDETSEL_1                              ((uint32_t)0x00000002U)         /* Bit1*/
#define RCC_EMCCTRL_GVDETSEL_2                              ((uint32_t)0x00000004U)         /* Bit2*/
#define RCC_EMCCTRL_GVDETSEL_3                              ((uint32_t)0x00000008U)         /* Bit3*/
#define RCC_EMCCTRL_GVDETSEL_4                              ((uint32_t)0x00000010U)         /* Bit4*/

/******** Bit definition for RCC_LSCTRL register  ********/
#define RCC_LSCTRL_TRIMSEL                                 ((uint32_t)0x00000200U)         /* Bit[9] */
#define RCC_LSCTRL_LSITRIM                                 ((uint32_t)0x000001FFU)         /* Bit[8:0] */
#define RCC_LSCTRL_LSITRIM_0                               ((uint32_t)0x00000001U)         /* Bit0*/
#define RCC_LSCTRL_LSITRIM_1                               ((uint32_t)0x00000002U)         /* Bit1*/
#define RCC_LSCTRL_LSITRIM_2                               ((uint32_t)0x00000004U)         /* Bit2*/
#define RCC_LSCTRL_LSITRIM_3                               ((uint32_t)0x00000008U)         /* Bit3*/
#define RCC_LSCTRL_LSITRIM_4                               ((uint32_t)0x00000010U)         /* Bit4*/
#define RCC_LSCTRL_LSITRIM_5                               ((uint32_t)0x00000020U)         /* Bit5*/
#define RCC_LSCTRL_LSITRIM_6                               ((uint32_t)0x00000040U)         /* Bit6*/
#define RCC_LSCTRL_LSITRIM_7                               ((uint32_t)0x00000080U)         /* Bit7*/
#define RCC_LSCTRL_LSITRIM_8                               ((uint32_t)0x00000100U)         /* Bit8*/

/******** Bit definition for RCC_TIMFILTCFG register  ********/
#define RCC_TIMFILTCFG_IOFLITCLK                               ((uint32_t)0xF0000000U)         /* Bit[31:28] */
#define RCC_TIMFILTCFG_IOFLITCLK_0                             ((uint32_t)0x10000000U)         /* Bit28*/
#define RCC_TIMFILTCFG_IOFLITCLK_1                             ((uint32_t)0x20000000U)         /* Bit29*/
#define RCC_TIMFILTCFG_IOFLITCLK_2                             ((uint32_t)0x40000000U)         /* Bit30*/
#define RCC_TIMFILTCFG_IOFLITCLK_3                             ((uint32_t)0x80000000U)         /* Bit31*/
#define RCC_TIMFILTCFG_TIM4FILTCLK                             ((uint32_t)0x001F0000U)         /* Bit[20:16] */
#define RCC_TIMFILTCFG_TIM4FILTCLK_0                           ((uint32_t)0x00010000U)         /* Bit16*/
#define RCC_TIMFILTCFG_TIM4FILTCLK_1                           ((uint32_t)0x00020000U)         /* Bit17*/
#define RCC_TIMFILTCFG_TIM4FILTCLK_2                           ((uint32_t)0x00040000U)         /* Bit18*/
#define RCC_TIMFILTCFG_TIM4FILTCLK_3                           ((uint32_t)0x00080000U)         /* Bit19*/
#define RCC_TIMFILTCFG_TIM4FILTCLK_4                           ((uint32_t)0x00100000U)         /* Bit20*/
#define RCC_TIMFILTCFG_TIM3FILTCLK                             ((uint32_t)0x00001F00U)         /* Bit[12:8] */
#define RCC_TIMFILTCFG_TIM3FILTCLK_0                           ((uint32_t)0x00000100U)         /* Bit8*/
#define RCC_TIMFILTCFG_TIM3FILTCLK_1                           ((uint32_t)0x00000200U)         /* Bit9*/
#define RCC_TIMFILTCFG_TIM3FILTCLK_2                           ((uint32_t)0x00000400U)         /* Bit10*/
#define RCC_TIMFILTCFG_TIM3FILTCLK_3                           ((uint32_t)0x00000800U)         /* Bit11*/
#define RCC_TIMFILTCFG_TIM3FILTCLK_4                           ((uint32_t)0x00001000U)         /* Bit12*/
#define RCC_TIMFILTCFG_TIM1FILTCLK                             ((uint32_t)0x0000001FU)         /* Bit[4:0] */
#define RCC_TIMFILTCFG_TIM1FILTCLK_0                           ((uint32_t)0x00000001U)         /* Bit0*/
#define RCC_TIMFILTCFG_TIM1FILTCLK_1                           ((uint32_t)0x00000002U)         /* Bit1*/
#define RCC_TIMFILTCFG_TIM1FILTCLK_2                           ((uint32_t)0x00000004U)         /* Bit2*/
#define RCC_TIMFILTCFG_TIM1FILTCLK_3                           ((uint32_t)0x00000008U)         /* Bit3*/
#define RCC_TIMFILTCFG_TIM1FILTCLK_4                           ((uint32_t)0x00000010U)         /* Bit4*/


/*** SystemTick ***/

/*****************  Bit definition for SysTick_CTRL register  *****************/
#define SysTick_CTRL_ENABLE    ((uint32_t)0x00000001) /* Counter enable */
#define SysTick_CTRL_TICKINT   ((uint32_t)0x00000002) /* Counting down to 0 pends the SysTick handler */
#define SysTick_CTRL_CLKSOURCE ((uint32_t)0x00000004) /* Clock source */
#define SysTick_CTRL_COUNTFLAG ((uint32_t)0x00010000) /* Count Flag */

/*****************  Bit definition for SysTick_LOAD register  *****************/
#define SysTick_LOAD_RELOAD                                                                                            \
    ((uint32_t)0x00FFFFFF) /* Value to load into the SysTick Current Value Register when the counter reaches 0 */

/*****************  Bit definition for SysTick_VAL register  ******************/
#define SysTick_VAL_CURRENT ((uint32_t)0x00FFFFFF) /* Current value at the time the register is accessed */

/*****************  Bit definition for SysTick_CALIB register  ****************/
#define SysTick_CALIB_TENMS ((uint32_t)0x00FFFFFF) /* Reload value to use for 10ms timing */
#define SysTick_CALIB_SKEW  ((uint32_t)0x40000000) /* Calibration value is not exactly 10 ms */
#define SysTick_CALIB_NOREF ((uint32_t)0x80000000) /* The reference clock is not provided */

/******************************************************************************/
/*                                                                            */
/*                  Nested Vectored Interrupt Controller                      */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for NVIC_ISER register  *******************/
#define NVIC_ISER_SETENA    ((uint32_t)0xFFFFFFFF) /* Interrupt set enable bits */
#define NVIC_ISER_SETENA_0  ((uint32_t)0x00000001) /* bit 0 */
#define NVIC_ISER_SETENA_1  ((uint32_t)0x00000002) /* bit 1 */
#define NVIC_ISER_SETENA_2  ((uint32_t)0x00000004) /* bit 2 */
#define NVIC_ISER_SETENA_3  ((uint32_t)0x00000008) /* bit 3 */
#define NVIC_ISER_SETENA_4  ((uint32_t)0x00000010) /* bit 4 */
#define NVIC_ISER_SETENA_5  ((uint32_t)0x00000020) /* bit 5 */
#define NVIC_ISER_SETENA_6  ((uint32_t)0x00000040) /* bit 6 */
#define NVIC_ISER_SETENA_7  ((uint32_t)0x00000080) /* bit 7 */
#define NVIC_ISER_SETENA_8  ((uint32_t)0x00000100) /* bit 8 */
#define NVIC_ISER_SETENA_9  ((uint32_t)0x00000200) /* bit 9 */
#define NVIC_ISER_SETENA_10 ((uint32_t)0x00000400) /* bit 10 */
#define NVIC_ISER_SETENA_11 ((uint32_t)0x00000800) /* bit 11 */
#define NVIC_ISER_SETENA_12 ((uint32_t)0x00001000) /* bit 12 */
#define NVIC_ISER_SETENA_13 ((uint32_t)0x00002000) /* bit 13 */
#define NVIC_ISER_SETENA_14 ((uint32_t)0x00004000) /* bit 14 */
#define NVIC_ISER_SETENA_15 ((uint32_t)0x00008000) /* bit 15 */
#define NVIC_ISER_SETENA_16 ((uint32_t)0x00010000) /* bit 16 */
#define NVIC_ISER_SETENA_17 ((uint32_t)0x00020000) /* bit 17 */
#define NVIC_ISER_SETENA_18 ((uint32_t)0x00040000) /* bit 18 */
#define NVIC_ISER_SETENA_19 ((uint32_t)0x00080000) /* bit 19 */
#define NVIC_ISER_SETENA_20 ((uint32_t)0x00100000) /* bit 20 */
#define NVIC_ISER_SETENA_21 ((uint32_t)0x00200000) /* bit 21 */
#define NVIC_ISER_SETENA_22 ((uint32_t)0x00400000) /* bit 22 */
#define NVIC_ISER_SETENA_23 ((uint32_t)0x00800000) /* bit 23 */
#define NVIC_ISER_SETENA_24 ((uint32_t)0x01000000) /* bit 24 */
#define NVIC_ISER_SETENA_25 ((uint32_t)0x02000000) /* bit 25 */
#define NVIC_ISER_SETENA_26 ((uint32_t)0x04000000) /* bit 26 */
#define NVIC_ISER_SETENA_27 ((uint32_t)0x08000000) /* bit 27 */
#define NVIC_ISER_SETENA_28 ((uint32_t)0x10000000) /* bit 28 */
#define NVIC_ISER_SETENA_29 ((uint32_t)0x20000000) /* bit 29 */
#define NVIC_ISER_SETENA_30 ((uint32_t)0x40000000) /* bit 30 */
#define NVIC_ISER_SETENA_31 ((uint32_t)0x80000000) /* bit 31 */

/******************  Bit definition for NVIC_ICER register  *******************/
#define NVIC_ICER_CLRENA    ((uint32_t)0xFFFFFFFF) /* Interrupt clear-enable bits */
#define NVIC_ICER_CLRENA_0  ((uint32_t)0x00000001) /* bit 0 */
#define NVIC_ICER_CLRENA_1  ((uint32_t)0x00000002) /* bit 1 */
#define NVIC_ICER_CLRENA_2  ((uint32_t)0x00000004) /* bit 2 */
#define NVIC_ICER_CLRENA_3  ((uint32_t)0x00000008) /* bit 3 */
#define NVIC_ICER_CLRENA_4  ((uint32_t)0x00000010) /* bit 4 */
#define NVIC_ICER_CLRENA_5  ((uint32_t)0x00000020) /* bit 5 */
#define NVIC_ICER_CLRENA_6  ((uint32_t)0x00000040) /* bit 6 */
#define NVIC_ICER_CLRENA_7  ((uint32_t)0x00000080) /* bit 7 */
#define NVIC_ICER_CLRENA_8  ((uint32_t)0x00000100) /* bit 8 */
#define NVIC_ICER_CLRENA_9  ((uint32_t)0x00000200) /* bit 9 */
#define NVIC_ICER_CLRENA_10 ((uint32_t)0x00000400) /* bit 10 */
#define NVIC_ICER_CLRENA_11 ((uint32_t)0x00000800) /* bit 11 */
#define NVIC_ICER_CLRENA_12 ((uint32_t)0x00001000) /* bit 12 */
#define NVIC_ICER_CLRENA_13 ((uint32_t)0x00002000) /* bit 13 */
#define NVIC_ICER_CLRENA_14 ((uint32_t)0x00004000) /* bit 14 */
#define NVIC_ICER_CLRENA_15 ((uint32_t)0x00008000) /* bit 15 */
#define NVIC_ICER_CLRENA_16 ((uint32_t)0x00010000) /* bit 16 */
#define NVIC_ICER_CLRENA_17 ((uint32_t)0x00020000) /* bit 17 */
#define NVIC_ICER_CLRENA_18 ((uint32_t)0x00040000) /* bit 18 */
#define NVIC_ICER_CLRENA_19 ((uint32_t)0x00080000) /* bit 19 */
#define NVIC_ICER_CLRENA_20 ((uint32_t)0x00100000) /* bit 20 */
#define NVIC_ICER_CLRENA_21 ((uint32_t)0x00200000) /* bit 21 */
#define NVIC_ICER_CLRENA_22 ((uint32_t)0x00400000) /* bit 22 */
#define NVIC_ICER_CLRENA_23 ((uint32_t)0x00800000) /* bit 23 */
#define NVIC_ICER_CLRENA_24 ((uint32_t)0x01000000) /* bit 24 */
#define NVIC_ICER_CLRENA_25 ((uint32_t)0x02000000) /* bit 25 */
#define NVIC_ICER_CLRENA_26 ((uint32_t)0x04000000) /* bit 26 */
#define NVIC_ICER_CLRENA_27 ((uint32_t)0x08000000) /* bit 27 */
#define NVIC_ICER_CLRENA_28 ((uint32_t)0x10000000) /* bit 28 */
#define NVIC_ICER_CLRENA_29 ((uint32_t)0x20000000) /* bit 29 */
#define NVIC_ICER_CLRENA_30 ((uint32_t)0x40000000) /* bit 30 */
#define NVIC_ICER_CLRENA_31 ((uint32_t)0x80000000) /* bit 31 */

/******************  Bit definition for NVIC_ISPR register  *******************/
#define NVIC_ISPR_SETPEND    ((uint32_t)0xFFFFFFFF) /* Interrupt set-pending bits */
#define NVIC_ISPR_SETPEND_0  ((uint32_t)0x00000001) /* bit 0 */
#define NVIC_ISPR_SETPEND_1  ((uint32_t)0x00000002) /* bit 1 */
#define NVIC_ISPR_SETPEND_2  ((uint32_t)0x00000004) /* bit 2 */
#define NVIC_ISPR_SETPEND_3  ((uint32_t)0x00000008) /* bit 3 */
#define NVIC_ISPR_SETPEND_4  ((uint32_t)0x00000010) /* bit 4 */
#define NVIC_ISPR_SETPEND_5  ((uint32_t)0x00000020) /* bit 5 */
#define NVIC_ISPR_SETPEND_6  ((uint32_t)0x00000040) /* bit 6 */
#define NVIC_ISPR_SETPEND_7  ((uint32_t)0x00000080) /* bit 7 */
#define NVIC_ISPR_SETPEND_8  ((uint32_t)0x00000100) /* bit 8 */
#define NVIC_ISPR_SETPEND_9  ((uint32_t)0x00000200) /* bit 9 */
#define NVIC_ISPR_SETPEND_10 ((uint32_t)0x00000400) /* bit 10 */
#define NVIC_ISPR_SETPEND_11 ((uint32_t)0x00000800) /* bit 11 */
#define NVIC_ISPR_SETPEND_12 ((uint32_t)0x00001000) /* bit 12 */
#define NVIC_ISPR_SETPEND_13 ((uint32_t)0x00002000) /* bit 13 */
#define NVIC_ISPR_SETPEND_14 ((uint32_t)0x00004000) /* bit 14 */
#define NVIC_ISPR_SETPEND_15 ((uint32_t)0x00008000) /* bit 15 */
#define NVIC_ISPR_SETPEND_16 ((uint32_t)0x00010000) /* bit 16 */
#define NVIC_ISPR_SETPEND_17 ((uint32_t)0x00020000) /* bit 17 */
#define NVIC_ISPR_SETPEND_18 ((uint32_t)0x00040000) /* bit 18 */
#define NVIC_ISPR_SETPEND_19 ((uint32_t)0x00080000) /* bit 19 */
#define NVIC_ISPR_SETPEND_20 ((uint32_t)0x00100000) /* bit 20 */
#define NVIC_ISPR_SETPEND_21 ((uint32_t)0x00200000) /* bit 21 */
#define NVIC_ISPR_SETPEND_22 ((uint32_t)0x00400000) /* bit 22 */
#define NVIC_ISPR_SETPEND_23 ((uint32_t)0x00800000) /* bit 23 */
#define NVIC_ISPR_SETPEND_24 ((uint32_t)0x01000000) /* bit 24 */
#define NVIC_ISPR_SETPEND_25 ((uint32_t)0x02000000) /* bit 25 */
#define NVIC_ISPR_SETPEND_26 ((uint32_t)0x04000000) /* bit 26 */
#define NVIC_ISPR_SETPEND_27 ((uint32_t)0x08000000) /* bit 27 */
#define NVIC_ISPR_SETPEND_28 ((uint32_t)0x10000000) /* bit 28 */
#define NVIC_ISPR_SETPEND_29 ((uint32_t)0x20000000) /* bit 29 */
#define NVIC_ISPR_SETPEND_30 ((uint32_t)0x40000000) /* bit 30 */
#define NVIC_ISPR_SETPEND_31 ((uint32_t)0x80000000) /* bit 31 */

/******************  Bit definition for NVIC_ICPR register  *******************/
#define NVIC_ICPR_CLRPEND    ((uint32_t)0xFFFFFFFF) /* Interrupt clear-pending bits */
#define NVIC_ICPR_CLRPEND_0  ((uint32_t)0x00000001) /* bit 0 */
#define NVIC_ICPR_CLRPEND_1  ((uint32_t)0x00000002) /* bit 1 */
#define NVIC_ICPR_CLRPEND_2  ((uint32_t)0x00000004) /* bit 2 */
#define NVIC_ICPR_CLRPEND_3  ((uint32_t)0x00000008) /* bit 3 */
#define NVIC_ICPR_CLRPEND_4  ((uint32_t)0x00000010) /* bit 4 */
#define NVIC_ICPR_CLRPEND_5  ((uint32_t)0x00000020) /* bit 5 */
#define NVIC_ICPR_CLRPEND_6  ((uint32_t)0x00000040) /* bit 6 */
#define NVIC_ICPR_CLRPEND_7  ((uint32_t)0x00000080) /* bit 7 */
#define NVIC_ICPR_CLRPEND_8  ((uint32_t)0x00000100) /* bit 8 */
#define NVIC_ICPR_CLRPEND_9  ((uint32_t)0x00000200) /* bit 9 */
#define NVIC_ICPR_CLRPEND_10 ((uint32_t)0x00000400) /* bit 10 */
#define NVIC_ICPR_CLRPEND_11 ((uint32_t)0x00000800) /* bit 11 */
#define NVIC_ICPR_CLRPEND_12 ((uint32_t)0x00001000) /* bit 12 */
#define NVIC_ICPR_CLRPEND_13 ((uint32_t)0x00002000) /* bit 13 */
#define NVIC_ICPR_CLRPEND_14 ((uint32_t)0x00004000) /* bit 14 */
#define NVIC_ICPR_CLRPEND_15 ((uint32_t)0x00008000) /* bit 15 */
#define NVIC_ICPR_CLRPEND_16 ((uint32_t)0x00010000) /* bit 16 */
#define NVIC_ICPR_CLRPEND_17 ((uint32_t)0x00020000) /* bit 17 */
#define NVIC_ICPR_CLRPEND_18 ((uint32_t)0x00040000) /* bit 18 */
#define NVIC_ICPR_CLRPEND_19 ((uint32_t)0x00080000) /* bit 19 */
#define NVIC_ICPR_CLRPEND_20 ((uint32_t)0x00100000) /* bit 20 */
#define NVIC_ICPR_CLRPEND_21 ((uint32_t)0x00200000) /* bit 21 */
#define NVIC_ICPR_CLRPEND_22 ((uint32_t)0x00400000) /* bit 22 */
#define NVIC_ICPR_CLRPEND_23 ((uint32_t)0x00800000) /* bit 23 */
#define NVIC_ICPR_CLRPEND_24 ((uint32_t)0x01000000) /* bit 24 */
#define NVIC_ICPR_CLRPEND_25 ((uint32_t)0x02000000) /* bit 25 */
#define NVIC_ICPR_CLRPEND_26 ((uint32_t)0x04000000) /* bit 26 */
#define NVIC_ICPR_CLRPEND_27 ((uint32_t)0x08000000) /* bit 27 */
#define NVIC_ICPR_CLRPEND_28 ((uint32_t)0x10000000) /* bit 28 */
#define NVIC_ICPR_CLRPEND_29 ((uint32_t)0x20000000) /* bit 29 */
#define NVIC_ICPR_CLRPEND_30 ((uint32_t)0x40000000) /* bit 30 */
#define NVIC_ICPR_CLRPEND_31 ((uint32_t)0x80000000) /* bit 31 */

/******************  Bit definition for NVIC_IABR register  *******************/
#define NVIC_IABR_ACTIVE    ((uint32_t)0xFFFFFFFF) /* Interrupt active flags */
#define NVIC_IABR_ACTIVE_0  ((uint32_t)0x00000001) /* bit 0 */
#define NVIC_IABR_ACTIVE_1  ((uint32_t)0x00000002) /* bit 1 */
#define NVIC_IABR_ACTIVE_2  ((uint32_t)0x00000004) /* bit 2 */
#define NVIC_IABR_ACTIVE_3  ((uint32_t)0x00000008) /* bit 3 */
#define NVIC_IABR_ACTIVE_4  ((uint32_t)0x00000010) /* bit 4 */
#define NVIC_IABR_ACTIVE_5  ((uint32_t)0x00000020) /* bit 5 */
#define NVIC_IABR_ACTIVE_6  ((uint32_t)0x00000040) /* bit 6 */
#define NVIC_IABR_ACTIVE_7  ((uint32_t)0x00000080) /* bit 7 */
#define NVIC_IABR_ACTIVE_8  ((uint32_t)0x00000100) /* bit 8 */
#define NVIC_IABR_ACTIVE_9  ((uint32_t)0x00000200) /* bit 9 */
#define NVIC_IABR_ACTIVE_10 ((uint32_t)0x00000400) /* bit 10 */
#define NVIC_IABR_ACTIVE_11 ((uint32_t)0x00000800) /* bit 11 */
#define NVIC_IABR_ACTIVE_12 ((uint32_t)0x00001000) /* bit 12 */
#define NVIC_IABR_ACTIVE_13 ((uint32_t)0x00002000) /* bit 13 */
#define NVIC_IABR_ACTIVE_14 ((uint32_t)0x00004000) /* bit 14 */
#define NVIC_IABR_ACTIVE_15 ((uint32_t)0x00008000) /* bit 15 */
#define NVIC_IABR_ACTIVE_16 ((uint32_t)0x00010000) /* bit 16 */
#define NVIC_IABR_ACTIVE_17 ((uint32_t)0x00020000) /* bit 17 */
#define NVIC_IABR_ACTIVE_18 ((uint32_t)0x00040000) /* bit 18 */
#define NVIC_IABR_ACTIVE_19 ((uint32_t)0x00080000) /* bit 19 */
#define NVIC_IABR_ACTIVE_20 ((uint32_t)0x00100000) /* bit 20 */
#define NVIC_IABR_ACTIVE_21 ((uint32_t)0x00200000) /* bit 21 */
#define NVIC_IABR_ACTIVE_22 ((uint32_t)0x00400000) /* bit 22 */
#define NVIC_IABR_ACTIVE_23 ((uint32_t)0x00800000) /* bit 23 */
#define NVIC_IABR_ACTIVE_24 ((uint32_t)0x01000000) /* bit 24 */
#define NVIC_IABR_ACTIVE_25 ((uint32_t)0x02000000) /* bit 25 */
#define NVIC_IABR_ACTIVE_26 ((uint32_t)0x04000000) /* bit 26 */
#define NVIC_IABR_ACTIVE_27 ((uint32_t)0x08000000) /* bit 27 */
#define NVIC_IABR_ACTIVE_28 ((uint32_t)0x10000000) /* bit 28 */
#define NVIC_IABR_ACTIVE_29 ((uint32_t)0x20000000) /* bit 29 */
#define NVIC_IABR_ACTIVE_30 ((uint32_t)0x40000000) /* bit 30 */
#define NVIC_IABR_ACTIVE_31 ((uint32_t)0x80000000) /* bit 31 */

/******************  Bit definition for NVIC_PRI0 register  *******************/
#define NVIC_IPR0_PRI_0 ((uint32_t)0x000000FF) /* Priority of interrupt 0 */
#define NVIC_IPR0_PRI_1 ((uint32_t)0x0000FF00) /* Priority of interrupt 1 */
#define NVIC_IPR0_PRI_2 ((uint32_t)0x00FF0000) /* Priority of interrupt 2 */
#define NVIC_IPR0_PRI_3 ((uint32_t)0xFF000000) /* Priority of interrupt 3 */

/******************  Bit definition for NVIC_PRI1 register  *******************/
#define NVIC_IPR1_PRI_4 ((uint32_t)0x000000FF) /* Priority of interrupt 4 */
#define NVIC_IPR1_PRI_5 ((uint32_t)0x0000FF00) /* Priority of interrupt 5 */
#define NVIC_IPR1_PRI_6 ((uint32_t)0x00FF0000) /* Priority of interrupt 6 */
#define NVIC_IPR1_PRI_7 ((uint32_t)0xFF000000) /* Priority of interrupt 7 */

/******************  Bit definition for NVIC_PRI2 register  *******************/
#define NVIC_IPR2_PRI_8  ((uint32_t)0x000000FF) /* Priority of interrupt 8 */
#define NVIC_IPR2_PRI_9  ((uint32_t)0x0000FF00) /* Priority of interrupt 9 */
#define NVIC_IPR2_PRI_10 ((uint32_t)0x00FF0000) /* Priority of interrupt 10 */
#define NVIC_IPR2_PRI_11 ((uint32_t)0xFF000000) /* Priority of interrupt 11 */

/******************  Bit definition for NVIC_PRI3 register  *******************/
#define NVIC_IPR3_PRI_12 ((uint32_t)0x000000FF) /* Priority of interrupt 12 */
#define NVIC_IPR3_PRI_13 ((uint32_t)0x0000FF00) /* Priority of interrupt 13 */
#define NVIC_IPR3_PRI_14 ((uint32_t)0x00FF0000) /* Priority of interrupt 14 */
#define NVIC_IPR3_PRI_15 ((uint32_t)0xFF000000) /* Priority of interrupt 15 */

/******************  Bit definition for NVIC_PRI4 register  *******************/
#define NVIC_IPR4_PRI_16 ((uint32_t)0x000000FF) /* Priority of interrupt 16 */
#define NVIC_IPR4_PRI_17 ((uint32_t)0x0000FF00) /* Priority of interrupt 17 */
#define NVIC_IPR4_PRI_18 ((uint32_t)0x00FF0000) /* Priority of interrupt 18 */
#define NVIC_IPR4_PRI_19 ((uint32_t)0xFF000000) /* Priority of interrupt 19 */

/******************  Bit definition for NVIC_PRI5 register  *******************/
#define NVIC_IPR5_PRI_20 ((uint32_t)0x000000FF) /* Priority of interrupt 20 */
#define NVIC_IPR5_PRI_21 ((uint32_t)0x0000FF00) /* Priority of interrupt 21 */
#define NVIC_IPR5_PRI_22 ((uint32_t)0x00FF0000) /* Priority of interrupt 22 */
#define NVIC_IPR5_PRI_23 ((uint32_t)0xFF000000) /* Priority of interrupt 23 */

/******************  Bit definition for NVIC_PRI6 register  *******************/
#define NVIC_IPR6_PRI_24 ((uint32_t)0x000000FF) /* Priority of interrupt 24 */
#define NVIC_IPR6_PRI_25 ((uint32_t)0x0000FF00) /* Priority of interrupt 25 */
#define NVIC_IPR6_PRI_26 ((uint32_t)0x00FF0000) /* Priority of interrupt 26 */
#define NVIC_IPR6_PRI_27 ((uint32_t)0xFF000000) /* Priority of interrupt 27 */

/******************  Bit definition for NVIC_PRI7 register  *******************/
#define NVIC_IPR7_PRI_28 ((uint32_t)0x000000FF) /* Priority of interrupt 28 */
#define NVIC_IPR7_PRI_29 ((uint32_t)0x0000FF00) /* Priority of interrupt 29 */
#define NVIC_IPR7_PRI_30 ((uint32_t)0x00FF0000) /* Priority of interrupt 30 */
#define NVIC_IPR7_PRI_31 ((uint32_t)0xFF000000) /* Priority of interrupt 31 */

/******************  Bit definition for SCB_CPUID register  *******************/
#define SCB_CPUID_REVISION    ((uint32_t)0x0000000F) /* Implementation defined revision number */
#define SCB_CPUID_PARTNO      ((uint32_t)0x0000FFF0) /* Number of processor within family */
#define SCB_CPUID_Constant    ((uint32_t)0x000F0000) /* Reads as 0x0F */
#define SCB_CPUID_VARIANT     ((uint32_t)0x00F00000) /* Implementation defined variant number */
#define SCB_CPUID_IMPLEMENTER ((uint32_t)0xFF000000) /* Implementer code. ARM is 0x41 */

/*******************  Bit definition for SCB_ICSR register  *******************/
#define SCB_ICSR_VECTACTIVE  ((uint32_t)0x000001FF) /* Active INTSTS number field */
#define SCB_ICSR_RETTOBASE   ((uint32_t)0x00000800) /* All active exceptions minus the IPSR_current_exception yields the empty set */
#define SCB_ICSR_VECTPENDING ((uint32_t)0x003FF000) /* Pending INTSTS number field */
#define SCB_ICSR_ISRPENDING  ((uint32_t)0x00400000) /* Interrupt pending flag */
#define SCB_ICSR_ISRPREEMPT  ((uint32_t)0x00800000) /* It indicates that a pending interrupt becomes active in the next running cycle */
#define SCB_ICSR_PENDSTCLR   ((uint32_t)0x02000000) /* Clear pending SysTick bit */
#define SCB_ICSR_PENDSTSET   ((uint32_t)0x04000000) /* Set pending SysTick bit */
#define SCB_ICSR_PENDSVCLR   ((uint32_t)0x08000000) /* Clear pending pendSV bit */
#define SCB_ICSR_PENDSVSET   ((uint32_t)0x10000000) /* Set pending pendSV bit */
#define SCB_ICSR_NMIPENDSET  ((uint32_t)0x80000000) /* Set pending NMI bit */

/** Bit definition for SCB_AIRCR register **/
#define SCB_AIRCR_VECTCLRACTIVE ((uint32_t)0x00000002U) /* Clear active vector bit */
#define SCB_AIRCR_SYSRESETREQ   ((uint32_t)0x00000004U) /* Requests chip control logic to generate a reset */
#define SCB_AIRCR_ENDIANESS     ((uint32_t)0x00008000U) /* Data endianness bit */
#define SCB_AIRCR_VECTKEYSTAT   ((uint32_t)0xFFFF0000U) /* Reads as 0xFA05 (VECTKEYSTAT) */
#define SCB_AIRCR_VECTKEY       ((uint32_t)0x05FA0000U) /* Register access key */

/** Bit definition for SCB_SCR register **/
#define SCB_SCR_SLEEPONEXIT ((uint8_t)0x02U) /* Sleep on exit bit */
#define SCB_SCR_SLEEPDEEP   ((uint8_t)0x04U) /* Sleep deep bit */
#define SCB_SCR_SEVONPEND   ((uint8_t)0x10U) /* Wake up from WFE */

/** Bit definition for SCB_CCR register **/
#define SCB_CCR_UNALIGN_TRP ((uint16_t)0x0008U) /* Trap for unaligned access */
#define SCB_CCR_STKALIGN    ((uint16_t)0x0200U) /* On exception entry, the SP used prior to the exception is adjusted to be 8-byte aligned */

/** Bit definition for SCB_SHPR register **/
#define SCB_SHPR_PRI_N    ((uint32_t)0x000000FFU) /* Priority of system handler 4,8, and 12. Mem Manage, reserved and Debug Monitor */
#define SCB_SHPR_PRI_N1   ((uint32_t)0x0000FF00U) /* Priority of system handler 5,9, and 13. Bus Fault, reserved and reserved */
#define SCB_SHPR_PRI_N2   ((uint32_t)0x00FF0000U) /* Priority of system handler 6,10, and 14. Usage Fault, reserved and PendSV */
#define SCB_SHPR_PRI_N3   ((uint32_t)0xFF000000U) /* Priority of system handler 7,11, and 15. Reserved, SVCall and SysTick */

/** Bit definition for SCB_SHCSR register **/
#define SCB_SHCSR_SVCALLPENDED   ((uint32_t)0x00008000U) /* SVCall is pended */

/** Bit definition for SCB_DFSR register **/
#define SCB_DFSR_HALTED   ((uint8_t)0x01U) /* Halt request flag */
#define SCB_DFSR_BKPT     ((uint8_t)0x02U) /* BKPT flag */
#define SCB_DFSR_DWTTRAP  ((uint8_t)0x04U) /* Data Watchpoint and Trace (DWT) flag */
#define SCB_DFSR_VCATCH   ((uint8_t)0x08U) /* Vector catch flag */
#define SCB_DFSR_EXTERNAL ((uint8_t)0x10U) /* External debug request flag */

/** Bit definition for SCB_afsr register **/
#define SCB_AFSR_IMPDEF ((uint32_t)0xFFFFFFFFU) /* Implementation defined */

/*** DMA Controller ***/

/** Bit definition for DMA_INTSTS register **/
#define DMA_INTSTS_GLBF1 ((uint32_t)0x00000001U) /* Channel 1 Global interrupt flag */
#define DMA_INTSTS_TXCF1 ((uint32_t)0x00000002U) /* Channel 1 Transfer Complete flag */
#define DMA_INTSTS_HTXF1 ((uint32_t)0x00000004U) /* Channel 1 Half Transfer flag */
#define DMA_INTSTS_ERRF1 ((uint32_t)0x00000008U) /* Channel 1 Transfer Error flag */
#define DMA_INTSTS_GLBF2 ((uint32_t)0x00000010U) /* Channel 2 Global interrupt flag */
#define DMA_INTSTS_TXCF2 ((uint32_t)0x00000020U) /* Channel 2 Transfer Complete flag */
#define DMA_INTSTS_HTXF2 ((uint32_t)0x00000040U) /* Channel 2 Half Transfer flag */
#define DMA_INTSTS_ERRF2 ((uint32_t)0x00000080U) /* Channel 2 Transfer Error flag */
#define DMA_INTSTS_GLBF3 ((uint32_t)0x00000100U) /* Channel 3 Global interrupt flag */
#define DMA_INTSTS_TXCF3 ((uint32_t)0x00000200U) /* Channel 3 Transfer Complete flag */
#define DMA_INTSTS_HTXF3 ((uint32_t)0x00000400U) /* Channel 3 Half Transfer flag */
#define DMA_INTSTS_ERRF3 ((uint32_t)0x00000800U) /* Channel 3 Transfer Error flag */

/** Bit definition for DMA_INTCLR register **/
#define DMA_INTCLR_CGLBF1 ((uint32_t)0x00000001U) /* Channel 1 Global interrupt clear */
#define DMA_INTCLR_CTXCF1 ((uint32_t)0x00000002U) /* Channel 1 Transfer Complete clear */
#define DMA_INTCLR_CHTXF1 ((uint32_t)0x00000004U) /* Channel 1 Half Transfer clear */
#define DMA_INTCLR_CERRF1 ((uint32_t)0x00000008U) /* Channel 1 Transfer Error clear */
#define DMA_INTCLR_CGLBF2 ((uint32_t)0x00000010U) /* Channel 2 Global interrupt clear */
#define DMA_INTCLR_CTXCF2 ((uint32_t)0x00000020U) /* Channel 2 Transfer Complete clear */
#define DMA_INTCLR_CHTXF2 ((uint32_t)0x00000040U) /* Channel 2 Half Transfer clear */
#define DMA_INTCLR_CERRF2 ((uint32_t)0x00000080U) /* Channel 2 Transfer Error clear */
#define DMA_INTCLR_CGLBF3 ((uint32_t)0x00000100U) /* Channel 3 Global interrupt clear */
#define DMA_INTCLR_CTXCF3 ((uint32_t)0x00000200U) /* Channel 3 Transfer Complete clear */
#define DMA_INTCLR_CHTXF3 ((uint32_t)0x00000400U) /* Channel 3 Half Transfer clear */
#define DMA_INTCLR_CERRF3 ((uint32_t)0x00000800U) /* Channel 3 Transfer Error clear */

/** Bit definition for DMA_CHCFGx register **/
#define DMA_CHCFG_CHEN  ((uint16_t)0x0001) /* Channel enable*/
#define DMA_CHCFG_TXCIE ((uint16_t)0x0002) /* Transfer complete interrupt enable */
#define DMA_CHCFG_HTXIE ((uint16_t)0x0004) /* Half Transfer interrupt enable */
#define DMA_CHCFG_ERRIE ((uint16_t)0x0008) /* Transfer error interrupt enable */
#define DMA_CHCFG_DIR   ((uint16_t)0x0010) /* Data transfer direction */
#define DMA_CHCFG_CIRC  ((uint16_t)0x0020) /* Circular mode */
#define DMA_CHCFG_PINC  ((uint16_t)0x0040) /* Peripheral increment mode */
#define DMA_CHCFG_MINC  ((uint16_t)0x0080) /* Memory increment mode */

#define DMA_CHCFG_PSIZE   ((uint16_t)0x0300) /* PSIZE[1:0] bits (Peripheral size) */
#define DMA_CHCFG_PSIZE_0 ((uint16_t)0x0100) /* Bit 0 */
#define DMA_CHCFG_PSIZE_1 ((uint16_t)0x0200) /* Bit 1 */

#define DMA_CHCFG_MSIZE   ((uint16_t)0x0C00) /* MSIZE[1:0] bits (Memory size) */
#define DMA_CHCFG_MSIZE_0 ((uint16_t)0x0400) /* Bit 0 */
#define DMA_CHCFG_MSIZE_1 ((uint16_t)0x0800) /* Bit 1 */

#define DMA_CHCFG_PRIOLVL   ((uint16_t)0x3000) /* PRIOLVL[1:0] bits(Channel Priority level) */
#define DMA_CHCFG_PRIOLVL_0 ((uint16_t)0x1000) /* Bit 0 */
#define DMA_CHCFG_PRIOLVL_1 ((uint16_t)0x2000) /* Bit 1 */

#define DMA_CHCFG_MEM2MEM ((uint16_t)0x4000) /* Memory to memory mode */

/** Bit definition for DMA_TXNUM1 register **/
#define DMA_TXNUM1_NDTX ((uint16_t)0xFFFFU) /* CH1 number of data to transfer */

/** Bit definition for DMA_TXNUM2 register **/
#define DMA_TXNUM2_NDTX ((uint16_t)0xFFFFU) /* CH2 number of data to transfer */

/** Bit definition for DMA_TXNUM3 register **/
#define DMA_TXNUM3_NDTX ((uint16_t)0xFFFFU) /* CH3 number of data to transfer */

/** Bit definition for DMA_PADDR1 register **/
#define DMA_PADDR1_ADDR ((uint32_t)0xFFFFFFFFU) /* Peripheral Address of CH1 */

/** Bit definition for DMA_PADDR2 register **/
#define DMA_PADDR2_ADDR ((uint32_t)0xFFFFFFFFU) /* Peripheral Address of CH2 */

/** Bit definition for DMA_PADDR3 register **/
#define DMA_PADDR3_ADDR ((uint32_t)0xFFFFFFFFU) /* Peripheral Address of CH3 */

/** Bit definition for DMA_MADDR1 register **/
#define DMA_MADDR1_ADDR ((uint32_t)0xFFFFFFFFU) /* Memory Address of CH1 */

/** Bit definition for DMA_MADDR2 register **/
#define DMA_MADDR2_ADDR ((uint32_t)0xFFFFFFFFU) /* Memory Address of CH2 */

/** Bit definition for DMA_MADDR3 register **/
#define DMA_MADDR3_ADDR ((uint32_t)0xFFFFFFFFU) /* Memory Address of CH3 */

/** Bit definition for DMA_CHSELx(x=1~3) register  ***/
#define DMA_CHSEL_CH_SEL   ((uint32_t)0x0000003FU) /* CH_SEL[5:0]: Channel request select */
#define DMA_CHSEL_CH_SEL_0 ((uint32_t)0x00000001U) /* bit0 */
#define DMA_CHSEL_CH_SEL_1 ((uint32_t)0x00000002U) /* bit1 */
#define DMA_CHSEL_CH_SEL_2 ((uint32_t)0x00000004U) /* bit2 */
#define DMA_CHSEL_CH_SEL_3 ((uint32_t)0x00000008U) /* bit3 */
#define DMA_CHSEL_CH_SEL_4 ((uint32_t)0x00000010U) /* bit4 */
#define DMA_CHSEL_CH_SEL_5 ((uint32_t)0x00000020U) /* bit5 */



/***  Analog to Digital Converter ***/

/*** Bit definition for ADC_STS register  ***/
#define ADC_STS_PDRDY                                   ((uint32_t)0x00000800U)         /* Bit[11] */
#define ADC_STS_RDY                                     ((uint32_t)0x00000400U)         /* Bit[10] */
#define ADC_STS_VREFRDY                                 ((uint32_t)0x00000200U)         /* Bit[9] */
#define ADC_STS_STR                                     ((uint32_t)0x00000100U)         /* Bit[8] */
#define ADC_STS_AWDG                                    ((uint32_t)0x00000040U)         /* Bit[6] */
#define ADC_STS_ENDCA                                   ((uint32_t)0x00000020U)         /* Bit[5] */
#define ADC_STS_ENDC                                    ((uint32_t)0x00000010U)         /* Bit[4] */
#define ADC_STS_PH4F                                    ((uint32_t)0x00000008U)         /* Bit[3] */
#define ADC_STS_PH3F                                    ((uint32_t)0x00000004U)         /* Bit[2] */
#define ADC_STS_PH2F                                    ((uint32_t)0x00000002U)         /* Bit[1] */
#define ADC_STS_PH1F                                    ((uint32_t)0x00000001U)         /* Bit[0] */

/*** Bit definition for ADC_CTRL1 register  ***/
#define ADC_CTRL1_AWDGIEN                                 ((uint32_t)0x00000040U)         /* Bit[6] */
#define ADC_CTRL1_ENDCAIEN                                ((uint32_t)0x00000020U)         /* Bit[5] */
#define ADC_CTRL1_ENDCIEN                                 ((uint32_t)0x00000010U)         /* Bit[4] */
#define ADC_CTRL1_PH4IEN                                  ((uint32_t)0x00000008U)         /* Bit[3] */
#define ADC_CTRL1_PH3IEN                                  ((uint32_t)0x00000004U)         /* Bit[2] */
#define ADC_CTRL1_PH2IEN                                  ((uint32_t)0x00000002U)         /* Bit[1] */
#define ADC_CTRL1_PH1IEN                                  ((uint32_t)0x00000001U)         /* Bit[0] */

/*** Bit definition for ADC_CTRL2 register  ***/
#define ADC_CTRL2_ALIG                                    ((uint32_t)0x00000004U)         /* Bit[2] */
#define ADC_CTRL2_CTU                                     ((uint32_t)0x00000002U)         /* Bit[1] */
#define ADC_CTRL2_ON                                      ((uint32_t)0x00000001U)         /* Bit[0] */

/*** Bit definition for ADC_CTRL3 register  ***/
#define ADC_CTRL3_TEMPEN                                  ((uint32_t)0x00000020U)         /* Bit[5] */
#define ADC_CTRL3_REFSEL                                  ((uint32_t)0x00000008U)         /* Bit[3] */
#define ADC_CTRL3_VREFEN                                  ((uint32_t)0x00000004U)         /* Bit[2] */

/*** Bit definition for ADC_SAMPT1 register  ***/
#define ADC_SAMPT1_SAMP7                                   ((uint32_t)0xF0000000U)         /* Bit[31:28] */
#define ADC_SAMPT1_SAMP7_0                                 ((uint32_t)0x10000000U)         /* Bit28*/
#define ADC_SAMPT1_SAMP7_1                                 ((uint32_t)0x20000000U)         /* Bit29*/
#define ADC_SAMPT1_SAMP7_2                                 ((uint32_t)0x40000000U)         /* Bit30*/
#define ADC_SAMPT1_SAMP7_3                                 ((uint32_t)0x80000000U)         /* Bit31*/

#define ADC_SAMPT1_SAMP6                                   ((uint32_t)0x0F000000U)         /* Bit[27:24] */
#define ADC_SAMPT1_SAMP6_0                                 ((uint32_t)0x01000000U)         /* Bit24*/
#define ADC_SAMPT1_SAMP6_1                                 ((uint32_t)0x02000000U)         /* Bit25*/
#define ADC_SAMPT1_SAMP6_2                                 ((uint32_t)0x04000000U)         /* Bit26*/
#define ADC_SAMPT1_SAMP6_3                                 ((uint32_t)0x08000000U)         /* Bit27*/

#define ADC_SAMPT1_SAMP5                                   ((uint32_t)0x00F00000U)         /* Bit[23:20] */
#define ADC_SAMPT1_SAMP5_0                                 ((uint32_t)0x00100000U)         /* Bit20*/
#define ADC_SAMPT1_SAMP5_1                                 ((uint32_t)0x00200000U)         /* Bit21*/
#define ADC_SAMPT1_SAMP5_2                                 ((uint32_t)0x00400000U)         /* Bit22*/
#define ADC_SAMPT1_SAMP5_3                                 ((uint32_t)0x00800000U)         /* Bit23*/

#define ADC_SAMPT1_SAMP4                                   ((uint32_t)0x000F0000U)         /* Bit[19:16] */
#define ADC_SAMPT1_SAMP4_0                                 ((uint32_t)0x00010000U)         /* Bit16*/
#define ADC_SAMPT1_SAMP4_1                                 ((uint32_t)0x00020000U)         /* Bit17*/
#define ADC_SAMPT1_SAMP4_2                                 ((uint32_t)0x00040000U)         /* Bit18*/
#define ADC_SAMPT1_SAMP4_3                                 ((uint32_t)0x00080000U)         /* Bit19*/

#define ADC_SAMPT1_SAMP3                                   ((uint32_t)0x0000F000U)         /* Bit[15:12] */
#define ADC_SAMPT1_SAMP3_0                                 ((uint32_t)0x00001000U)         /* Bit12*/
#define ADC_SAMPT1_SAMP3_1                                 ((uint32_t)0x00002000U)         /* Bit13*/
#define ADC_SAMPT1_SAMP3_2                                 ((uint32_t)0x00004000U)         /* Bit14*/
#define ADC_SAMPT1_SAMP3_3                                 ((uint32_t)0x00008000U)         /* Bit15*/

#define ADC_SAMPT1_SAMP2                                   ((uint32_t)0x00000F00U)         /* Bit[11:8] */
#define ADC_SAMPT1_SAMP2_0                                 ((uint32_t)0x00000100U)         /* Bit8*/
#define ADC_SAMPT1_SAMP2_1                                 ((uint32_t)0x00000200U)         /* Bit9*/
#define ADC_SAMPT1_SAMP2_2                                 ((uint32_t)0x00000400U)         /* Bit10*/
#define ADC_SAMPT1_SAMP2_3                                 ((uint32_t)0x00000800U)         /* Bit11*/

#define ADC_SAMPT1_SAMP1                                   ((uint32_t)0x000000F0U)         /* Bit[7:4] */
#define ADC_SAMPT1_SAMP1_0                                 ((uint32_t)0x00000010U)         /* Bit4*/
#define ADC_SAMPT1_SAMP1_1                                 ((uint32_t)0x00000020U)         /* Bit5*/
#define ADC_SAMPT1_SAMP1_2                                 ((uint32_t)0x00000040U)         /* Bit6*/
#define ADC_SAMPT1_SAMP1_3                                 ((uint32_t)0x00000080U)         /* Bit7*/

#define ADC_SAMPT1_SAMP0                                   ((uint32_t)0x0000000FU)         /* Bit[3:0] */
#define ADC_SAMPT1_SAMP0_0                                 ((uint32_t)0x00000001U)         /* Bit0*/
#define ADC_SAMPT1_SAMP0_1                                 ((uint32_t)0x00000002U)         /* Bit1*/
#define ADC_SAMPT1_SAMP0_2                                 ((uint32_t)0x00000004U)         /* Bit2*/
#define ADC_SAMPT1_SAMP0_3                                 ((uint32_t)0x00000008U)         /* Bit3*/


/*** Bit definition for ADC_SAMP2 register  ***/
#define ADC_SAMP2_SAMP15                                  ((uint32_t)0xF0000000U)         /* Bit[31:28] */
#define ADC_SAMP2_SAMP15_0                                ((uint32_t)0x10000000U)         /* Bit28*/
#define ADC_SAMP2_SAMP15_1                                ((uint32_t)0x20000000U)         /* Bit29*/
#define ADC_SAMP2_SAMP15_2                                ((uint32_t)0x40000000U)         /* Bit30*/
#define ADC_SAMP2_SAMP15_3                                ((uint32_t)0x80000000U)         /* Bit31*/

#define ADC_SAMP2_SAMP14                                  ((uint32_t)0x0F000000U)         /* Bit[27:24] */
#define ADC_SAMP2_SAMP14_0                                ((uint32_t)0x01000000U)         /* Bit24*/
#define ADC_SAMP2_SAMP14_1                                ((uint32_t)0x02000000U)         /* Bit25*/
#define ADC_SAMP2_SAMP14_2                                ((uint32_t)0x04000000U)         /* Bit26*/
#define ADC_SAMP2_SAMP14_3                                ((uint32_t)0x08000000U)         /* Bit27*/

#define ADC_SAMP2_SAMP13                                  ((uint32_t)0x00F00000U)         /* Bit[23:20] */
#define ADC_SAMP2_SAMP13_0                                ((uint32_t)0x00100000U)         /* Bit20*/
#define ADC_SAMP2_SAMP13_1                                ((uint32_t)0x00200000U)         /* Bit21*/
#define ADC_SAMP2_SAMP13_2                                ((uint32_t)0x00400000U)         /* Bit22*/
#define ADC_SAMP2_SAMP13_3                                ((uint32_t)0x00800000U)         /* Bit23*/

#define ADC_SAMP2_SAMP12                                  ((uint32_t)0x000F0000U)         /* Bit[19:16] */
#define ADC_SAMP2_SAMP12_0                                ((uint32_t)0x00010000U)         /* Bit16*/
#define ADC_SAMP2_SAMP12_1                                ((uint32_t)0x00020000U)         /* Bit17*/
#define ADC_SAMP2_SAMP12_2                                ((uint32_t)0x00040000U)         /* Bit18*/
#define ADC_SAMP2_SAMP12_3                                ((uint32_t)0x00080000U)         /* Bit19*/

#define ADC_SAMP2_SAMP11                                  ((uint32_t)0x0000F000U)         /* Bit[15:12] */
#define ADC_SAMP2_SAMP11_0                                ((uint32_t)0x00001000U)         /* Bit12*/
#define ADC_SAMP2_SAMP11_1                                ((uint32_t)0x00002000U)         /* Bit13*/
#define ADC_SAMP2_SAMP11_2                                ((uint32_t)0x00004000U)         /* Bit14*/
#define ADC_SAMP2_SAMP11_3                                ((uint32_t)0x00008000U)         /* Bit15*/

#define ADC_SAMP2_SAMP10                                  ((uint32_t)0x00000F00U)         /* Bit[11:8] */
#define ADC_SAMP2_SAMP10_0                                ((uint32_t)0x00000100U)         /* Bit8*/
#define ADC_SAMP2_SAMP10_1                                ((uint32_t)0x00000200U)         /* Bit9*/
#define ADC_SAMP2_SAMP10_2                                ((uint32_t)0x00000400U)         /* Bit10*/
#define ADC_SAMP2_SAMP10_3                                ((uint32_t)0x00000800U)         /* Bit11*/

#define ADC_SAMP2_SAMP9                                   ((uint32_t)0x000000F0U)         /* Bit[7:4] */
#define ADC_SAMP2_SAMP9_0                                 ((uint32_t)0x00000010U)         /* Bit4*/
#define ADC_SAMP2_SAMP9_1                                 ((uint32_t)0x00000020U)         /* Bit5*/
#define ADC_SAMP2_SAMP9_2                                 ((uint32_t)0x00000040U)         /* Bit6*/
#define ADC_SAMP2_SAMP9_3                                 ((uint32_t)0x00000080U)         /* Bit7*/

#define ADC_SAMP2_SAMP8                                   ((uint32_t)0x0000000FU)         /* Bit[3:0] */
#define ADC_SAMP2_SAMP8_0                                 ((uint32_t)0x00000001U)         /* Bit0*/
#define ADC_SAMP2_SAMP8_1                                 ((uint32_t)0x00000002U)         /* Bit1*/
#define ADC_SAMP2_SAMP8_2                                 ((uint32_t)0x00000004U)         /* Bit2*/
#define ADC_SAMP2_SAMP8_3                                 ((uint32_t)0x00000008U)         /* Bit3*/

/*** Bit definition for ADC_AWDHIGH register  ***/
#define ADC_AWDHIGH_HTH                                     ((uint32_t)0x00000FFFU)         /* Bit[11:0] */

/*** Bit definition for ADC_AWDLOW register  ***/
#define ADC_AWDLOW_LTH                                     ((uint32_t)0x00000FFFU)         /* Bit[11:0] */


/*** Bit definition for ADC_AWDEN register  ***/
#define ADC_AWDEN_AWDENx                                  ((uint32_t)0x00003FFFU)         /* Bit[13:0] */
#define ADC_AWDEN_AWDENx_0                                ((uint32_t)0x00000001U)         /* Bit0*/
#define ADC_AWDEN_AWDENx_1                                ((uint32_t)0x00000002U)         /* Bit1*/
#define ADC_AWDEN_AWDENx_2                                ((uint32_t)0x00000004U)         /* Bit2*/
#define ADC_AWDEN_AWDENx_3                                ((uint32_t)0x00000008U)         /* Bit3*/
#define ADC_AWDEN_AWDENx_4                                ((uint32_t)0x00000010U)         /* Bit4*/
#define ADC_AWDEN_AWDENx_5                                ((uint32_t)0x00000020U)         /* Bit5*/
#define ADC_AWDEN_AWDENx_6                                ((uint32_t)0x00000040U)         /* Bit6*/
#define ADC_AWDEN_AWDENx_7                                ((uint32_t)0x00000080U)         /* Bit7*/
#define ADC_AWDEN_AWDENx_8                                ((uint32_t)0x00000100U)         /* Bit8*/
#define ADC_AWDEN_AWDENx_9                                ((uint32_t)0x00000200U)         /* Bit9*/
#define ADC_AWDEN_AWDENx_10                               ((uint32_t)0x00000400U)         /* Bit10*/
#define ADC_AWDEN_AWDENx_11                               ((uint32_t)0x00000800U)         /* Bit11*/
#define ADC_AWDEN_AWDENx_12                               ((uint32_t)0x00001000U)         /* Bit12*/
#define ADC_AWDEN_AWDENx_13                               ((uint32_t)0x00002000U)         /* Bit13*/

/*** Bit definition for ADC_PHCFG register  ***/
#define ADC_PHCFG_TRIGMD                                  ((uint32_t)0x00030000U)         /* Bit[17:16] */
#define ADC_PHCFG_TRIGMD_0                                ((uint32_t)0x00010000U)         /* Bit16*/
#define ADC_PHCFG_TRIGMD_1                                ((uint32_t)0x00020000U)         /* Bit17*/

#define ADC_PHCFG_PH4CHNUM                                ((uint32_t)0x0000F000U)         /* Bit[15:12] */
#define ADC_PHCFG_PH4CHNUM_0                              ((uint32_t)0x00001000U)         /* Bit12*/
#define ADC_PHCFG_PH4CHNUM_1                              ((uint32_t)0x00002000U)         /* Bit13*/
#define ADC_PHCFG_PH4CHNUM_2                              ((uint32_t)0x00004000U)         /* Bit14*/
#define ADC_PHCFG_PH4CHNUM_3                              ((uint32_t)0x00008000U)         /* Bit15*/

#define ADC_PHCFG_PH3CHNUM                                ((uint32_t)0x00000F00U)         /* Bit[11:8] */
#define ADC_PHCFG_PH3CHNUM_0                              ((uint32_t)0x00000100U)         /* Bit8*/
#define ADC_PHCFG_PH3CHNUM_1                              ((uint32_t)0x00000200U)         /* Bit9*/
#define ADC_PHCFG_PH3CHNUM_2                              ((uint32_t)0x00000400U)         /* Bit10*/
#define ADC_PHCFG_PH3CHNUM_3                              ((uint32_t)0x00000800U)         /* Bit11*/

#define ADC_PHCFG_PH2CHNUM                                ((uint32_t)0x000000F0U)         /* Bit[7:4] */
#define ADC_PHCFG_PH2CHNUM_0                              ((uint32_t)0x00000010U)         /* Bit4*/
#define ADC_PHCFG_PH2CHNUM_1                              ((uint32_t)0x00000020U)         /* Bit5*/
#define ADC_PHCFG_PH2CHNUM_2                              ((uint32_t)0x00000040U)         /* Bit6*/
#define ADC_PHCFG_PH2CHNUM_3                              ((uint32_t)0x00000080U)         /* Bit7*/

#define ADC_PHCFG_PH1CHNUM                                ((uint32_t)0x0000000FU)         /* Bit[3:0] */
#define ADC_PHCFG_PH1CHNUM_0                              ((uint32_t)0x00000001U)         /* Bit0*/
#define ADC_PHCFG_PH1CHNUM_1                              ((uint32_t)0x00000002U)         /* Bit1*/
#define ADC_PHCFG_PH1CHNUM_2                              ((uint32_t)0x00000004U)         /* Bit2*/
#define ADC_PHCFG_PH1CHNUM_3                              ((uint32_t)0x00000008U)         /* Bit3*/

/*** Bit definition for ADC_TRIGSEL register  ***/
#define ADC_TRIGSEL_PH4EXTSEL                             ((uint32_t)0xF0000000U)         /* Bit[31:28] */
#define ADC_TRIGSEL_PH4EXTSEL_0                           ((uint32_t)0x10000000U)         /* Bit28*/
#define ADC_TRIGSEL_PH4EXTSEL_1                           ((uint32_t)0x20000000U)         /* Bit29*/
#define ADC_TRIGSEL_PH4EXTSEL_2                           ((uint32_t)0x40000000U)         /* Bit30*/
#define ADC_TRIGSEL_PH4EXTSEL_3                           ((uint32_t)0x80000000U)         /* Bit31*/

#define ADC_TRIGSEL_PH3EXTSEL                             ((uint32_t)0x0F000000U)         /* Bit[27:24] */
#define ADC_TRIGSEL_PH3EXTSEL_0                           ((uint32_t)0x01000000U)         /* Bit24*/
#define ADC_TRIGSEL_PH3EXTSEL_1                           ((uint32_t)0x02000000U)         /* Bit25*/
#define ADC_TRIGSEL_PH3EXTSEL_2                           ((uint32_t)0x04000000U)         /* Bit26*/
#define ADC_TRIGSEL_PH3EXTSEL_3                           ((uint32_t)0x08000000U)         /* Bit27*/

#define ADC_TRIGSEL_PH2EXTSEL                             ((uint32_t)0x00F00000U)         /* Bit[23:20] */
#define ADC_TRIGSEL_PH2EXTSEL_0                           ((uint32_t)0x00100000U)         /* Bit20*/
#define ADC_TRIGSEL_PH2EXTSEL_1                           ((uint32_t)0x00200000U)         /* Bit21*/
#define ADC_TRIGSEL_PH2EXTSEL_2                           ((uint32_t)0x00400000U)         /* Bit22*/
#define ADC_TRIGSEL_PH2EXTSEL_3                           ((uint32_t)0x00800000U)         /* Bit23*/

#define ADC_TRIGSEL_PH1EXTSEL                             ((uint32_t)0x000F0000U)         /* Bit[19:16] */
#define ADC_TRIGSEL_PH1EXTSEL_0                           ((uint32_t)0x00010000U)         /* Bit16*/
#define ADC_TRIGSEL_PH1EXTSEL_1                           ((uint32_t)0x00020000U)         /* Bit17*/
#define ADC_TRIGSEL_PH1EXTSEL_2                           ((uint32_t)0x00040000U)         /* Bit18*/
#define ADC_TRIGSEL_PH1EXTSEL_3                           ((uint32_t)0x00080000U)         /* Bit19*/

#define ADC_TRIGSEL_SWEN                                  ((uint32_t)0x00008000U)         /* Bit[15] */
#define ADC_TRIGSEL_EXTILINEEN                            ((uint32_t)0x00004000U)         /* Bit[14] */
#define ADC_TRIGSEL_TIM4_TRGOEN                           ((uint32_t)0x00002000U)         /* Bit[13] */
#define ADC_TRIGSEL_TIM4_CC2EN                            ((uint32_t)0x00001000U)         /* Bit[12] */
#define ADC_TRIGSEL_TIM4_CC1EN                            ((uint32_t)0x00000800U)         /* Bit[11] */
#define ADC_TRIGSEL_TIM3_TRGOEN                           ((uint32_t)0x00000400U)         /* Bit[10] */
#define ADC_TRIGSEL_TIM3_CC2EN                            ((uint32_t)0x00000200U)         /* Bit[9] */
#define ADC_TRIGSEL_TIM3_CC1EN                            ((uint32_t)0x00000100U)         /* Bit[8] */
#define ADC_TRIGSEL_TIM1_TRGOEN                           ((uint32_t)0x00000080U)         /* Bit[7] */
#define ADC_TRIGSEL_TIM1_CC7EN                            ((uint32_t)0x00000040U)         /* Bit[6] */
#define ADC_TRIGSEL_TIM1_CC6EN                            ((uint32_t)0x00000020U)         /* Bit[5] */
#define ADC_TRIGSEL_TIM1_CC5EN                            ((uint32_t)0x00000010U)         /* Bit[4] */
#define ADC_TRIGSEL_TIM1_CC4EN                            ((uint32_t)0x00000008U)         /* Bit[3] */
#define ADC_TRIGSEL_TIM1_CC3EN                            ((uint32_t)0x00000004U)         /* Bit[2] */
#define ADC_TRIGSEL_TIM1_CC2EN                            ((uint32_t)0x00000002U)         /* Bit[1] */
#define ADC_TRIGSEL_TIM1_CC1EN                            ((uint32_t)0x00000001U)         /* Bit[0] */

/*** Bit definition for ADC_PHSWTRIG register  ***/
#define ADC_PHSWTRIG_PHSWSTART                            ((uint32_t)0x0000FFFFU)         /* Bit[15:0] */

/*** Bit definition for ADC_SEQ1 register  ***/
#define ADC_SEQ1_SEQ8                                    ((uint32_t)0xF0000000U)         /* Bit[31:28] */
#define ADC_SEQ1_SEQ8_0                                  ((uint32_t)0x10000000U)         /* Bit28*/
#define ADC_SEQ1_SEQ8_1                                  ((uint32_t)0x20000000U)         /* Bit29*/
#define ADC_SEQ1_SEQ8_2                                  ((uint32_t)0x40000000U)         /* Bit30*/
#define ADC_SEQ1_SEQ8_3                                  ((uint32_t)0x80000000U)         /* Bit31*/

#define ADC_SEQ1_SEQ7                                    ((uint32_t)0x0F000000U)         /* Bit[27:24] */
#define ADC_SEQ1_SEQ7_0                                  ((uint32_t)0x01000000U)         /* Bit24*/
#define ADC_SEQ1_SEQ7_1                                  ((uint32_t)0x02000000U)         /* Bit25*/
#define ADC_SEQ1_SEQ7_2                                  ((uint32_t)0x04000000U)         /* Bit26*/
#define ADC_SEQ1_SEQ7_3                                  ((uint32_t)0x08000000U)         /* Bit27*/

#define ADC_SEQ1_SEQ6                                    ((uint32_t)0x00F00000U)         /* Bit[23:20] */
#define ADC_SEQ1_SEQ6_0                                  ((uint32_t)0x00100000U)         /* Bit20*/
#define ADC_SEQ1_SEQ6_1                                  ((uint32_t)0x00200000U)         /* Bit21*/
#define ADC_SEQ1_SEQ6_2                                  ((uint32_t)0x00400000U)         /* Bit22*/
#define ADC_SEQ1_SEQ6_3                                  ((uint32_t)0x00800000U)         /* Bit23*/

#define ADC_SEQ1_SEQ5                                    ((uint32_t)0x000F0000U)         /* Bit[19:16] */
#define ADC_SEQ1_SEQ5_0                                  ((uint32_t)0x00010000U)         /* Bit16*/
#define ADC_SEQ1_SEQ5_1                                  ((uint32_t)0x00020000U)         /* Bit17*/
#define ADC_SEQ1_SEQ5_2                                  ((uint32_t)0x00040000U)         /* Bit18*/
#define ADC_SEQ1_SEQ5_3                                  ((uint32_t)0x00080000U)         /* Bit19*/

#define ADC_SEQ1_SEQ4                                    ((uint32_t)0x0000F000U)         /* Bit[15:12] */
#define ADC_SEQ1_SEQ4_0                                  ((uint32_t)0x00001000U)         /* Bit12*/
#define ADC_SEQ1_SEQ4_1                                  ((uint32_t)0x00002000U)         /* Bit13*/
#define ADC_SEQ1_SEQ4_2                                  ((uint32_t)0x00004000U)         /* Bit14*/
#define ADC_SEQ1_SEQ4_3                                  ((uint32_t)0x00008000U)         /* Bit15*/

#define ADC_SEQ1_SEQ3                                    ((uint32_t)0x00000F00U)         /* Bit[11:8] */
#define ADC_SEQ1_SEQ3_0                                  ((uint32_t)0x00000100U)         /* Bit8*/
#define ADC_SEQ1_SEQ3_1                                  ((uint32_t)0x00000200U)         /* Bit9*/
#define ADC_SEQ1_SEQ3_2                                  ((uint32_t)0x00000400U)         /* Bit10*/
#define ADC_SEQ1_SEQ3_3                                  ((uint32_t)0x00000800U)         /* Bit11*/

#define ADC_SEQ1_SEQ2                                    ((uint32_t)0x000000F0U)         /* Bit[7:4] */
#define ADC_SEQ1_SEQ2_0                                  ((uint32_t)0x00000010U)         /* Bit4*/
#define ADC_SEQ1_SEQ2_1                                  ((uint32_t)0x00000020U)         /* Bit5*/
#define ADC_SEQ1_SEQ2_2                                  ((uint32_t)0x00000040U)         /* Bit6*/
#define ADC_SEQ1_SEQ2_3                                  ((uint32_t)0x00000080U)         /* Bit7*/

#define ADC_SEQ1_SEQ1                                    ((uint32_t)0x0000000FU)         /* Bit[3:0] */
#define ADC_SEQ1_SEQ1_0                                  ((uint32_t)0x00000001U)         /* Bit0*/
#define ADC_SEQ1_SEQ1_1                                  ((uint32_t)0x00000002U)         /* Bit1*/
#define ADC_SEQ1_SEQ1_2                                  ((uint32_t)0x00000004U)         /* Bit2*/
#define ADC_SEQ1_SEQ1_3                                  ((uint32_t)0x00000008U)         /* Bit3*/

/*** Bit definition for ADC_SEQ2 register  ***/
#define ADC_SEQ2_SEQ10                                   ((uint32_t)0x000000F0U)         /* Bit[7:4] */
#define ADC_SEQ2_SEQ10_0                                 ((uint32_t)0x00000010U)         /* Bit4*/
#define ADC_SEQ2_SEQ10_1                                 ((uint32_t)0x00000020U)         /* Bit5*/
#define ADC_SEQ2_SEQ10_2                                 ((uint32_t)0x00000040U)         /* Bit6*/
#define ADC_SEQ2_SEQ10_3                                 ((uint32_t)0x00000080U)         /* Bit7*/

#define ADC_SEQ2_SEQ9                                    ((uint32_t)0x0000000FU)         /* Bit[3:0] */
#define ADC_SEQ2_SEQ9_0                                  ((uint32_t)0x00000001U)         /* Bit0*/
#define ADC_SEQ2_SEQ9_1                                  ((uint32_t)0x00000002U)         /* Bit1*/
#define ADC_SEQ2_SEQ9_2                                  ((uint32_t)0x00000004U)         /* Bit2*/
#define ADC_SEQ2_SEQ9_3                                  ((uint32_t)0x00000008U)         /* Bit3*/

/*** Bit definition for ADC_DAT0 register  ***/
#define ADC_DAT0_DAT0                                    ((uint32_t)0x0000FFFFU)         /* Bit[15:0] */

/*** Bit definition for ADC_DAT1 register  ***/
#define ADC_DAT1_DAT1                                    ((uint32_t)0x0000FFFFU)         /* Bit[15:0] */

/*** Bit definition for ADC_DAT2 register  ***/
#define ADC_DAT2_DAT2                                    ((uint32_t)0x0000FFFFU)         /* Bit[15:0] */

/*** Bit definition for ADC_DAT3 register  ***/
#define ADC_DAT3_DAT3                                    ((uint32_t)0x0000FFFFU)         /* Bit[15:0] */

/*** Bit definition for ADC_DAT4 register  ***/
#define ADC_DAT4_DAT4                                    ((uint32_t)0x0000FFFFU)         /* Bit[15:0] */

/*** Bit definition for ADC_DAT5 register  ***/
#define ADC_DAT5_DAT5                                    ((uint32_t)0x0000FFFFU)         /* Bit[15:0] */

/*** Bit definition for ADC_DAT6 register  ***/
#define ADC_DAT6_DAT6                                    ((uint32_t)0x0000FFFFU)         /* Bit[15:0] */

/*** Bit definition for ADC_DAT7 register  ***/
#define ADC_DAT7_DAT7                                    ((uint32_t)0x0000FFFFU)         /* Bit[15:0] */

/*** Bit definition for ADC_DAT8 register  ***/
#define ADC_DAT8_DAT8                                    ((uint32_t)0x0000FFFFU)         /* Bit[15:0] */

/*** Bit definition for ADC_DAT9 register  ***/
#define ADC_DAT9_DAT9                                    ((uint32_t)0x0000FFFFU)         /* Bit[15:0] */

/***  Optical Preamplifier Amplifier Peripheral Interface ***/

/*** Bit definition for OPAMP1_CS register  ***/
#define OPAMP1_CS_OUTSEL                               ((uint32_t)0x00008000U) /* OPA1 OUTSEL */

#define OPAMP1_CS_VMSEL                                ((uint32_t)0x00007000U) /* OPA1 VMSEL */
#define OPAMP1_CS_VMSEL_0                              ((uint32_t)0x00001000U) /* Bit0 */
#define OPAMP1_CS_VMSEL_1                              ((uint32_t)0x00002000U) /* Bit1 */
#define OPAMP1_CS_VMSEL_2                              ((uint32_t)0x00004000U) /* Bit2 */

#define OPAMP1_CS_VPSEL                                ((uint32_t)0x00000700U) /* OPA1 VPSEL */
#define OPAMP1_CS_VPSEL_0                              ((uint32_t)0x00000100U) /* Bit0 */
#define OPAMP1_CS_VPSEL_1                              ((uint32_t)0x00000200U) /* Bit1 */
#define OPAMP1_CS_VPSEL_2                              ((uint32_t)0x00000400U) /* Bit2 */

#define OPAMP1_CS_GAIN                                 ((uint32_t)0x00000038U) /* OPA1 GAIN */
#define OPAMP1_CS_GAIN_0                               ((uint32_t)0x00000008U) /* Bit0 */
#define OPAMP1_CS_GAIN_1                               ((uint32_t)0x00000010U) /* Bit1 */
#define OPAMP1_CS_GAIN_2                               ((uint32_t)0x00000020U) /* Bit2 */

#define OPAMP1_CS_MOD                                  ((uint32_t)0x00000006U) /* OPA1 Mode */
#define OPAMP1_CS_MOD_0                                ((uint32_t)0x00000002U) /* Bit0 */
#define OPAMP1_CS_MOD_1                                ((uint32_t)0x00000004U) /* Bit1 */

#define OPAMP1_CS_EN                                   ((uint32_t)0x00000001U) /* OPA1 Enable */

/**  Bit definition for OPAMP2_CS register  ***/
#define OPAMP2_CS_GAIN                                 ((uint32_t)0x00000038U) /* OPA2 GAIN */
#define OPAMP2_CS_GAIN_0                               ((uint32_t)0x00000008U) /* Bit0 */
#define OPAMP2_CS_GAIN_1                               ((uint32_t)0x00000010U) /* Bit1 */
#define OPAMP2_CS_GAIN_2                               ((uint32_t)0x00000020U) /* Bit2 */

#define OPAMP2_CS_MOD                                  ((uint32_t)0x00000002U) /* OPA2 Mode */

#define OPAMP2_CS_EN                                   ((uint32_t)0x00000001U) /* OPA2 Enable */
/**  Bit definition for OPAMP3_CS register  ***/
#define OPAMP3_CS_GAIN                                 ((uint32_t)0x00000038U) /* OPA3 GAIN */
#define OPAMP3_CS_GAIN_0                               ((uint32_t)0x00000008U) /* Bit0 */
#define OPAMP3_CS_GAIN_1                               ((uint32_t)0x00000010U) /* Bit1 */
#define OPAMP3_CS_GAIN_2                               ((uint32_t)0x00000020U) /* Bit2 */

#define OPAMP3_CS_MOD                                  ((uint32_t)0x00000002U) /* OPA3 Mode */

#define OPAMP3_CS_EN                                   ((uint32_t)0x00000001U) /* OPA3 Enable */

/**  Bit definition for OPAMP_LOCK register  ***/

#define OPAMP_LOCK                                     ((uint32_t)0x00000001U) /* OPAMP1/2/3 LK */

/**  Bit definition for OPAMP_VREFSEL register  ***/
#define OPAMP1_VREFSEL_SEL                             ((uint32_t)0x00000003U) /* OPAMP1 SEL */
#define OPAMP1_VREFSEL_SEL_0                           ((uint32_t)0x00000001U) /* Bit0 */
#define OPAMP1_VREFSEL_SEL_1                           ((uint32_t)0x00000002U) /* Bit1 */

#define OPAMP2_VREFSEL_SEL                             ((uint32_t)0x0000000CU) /* OPAMP2 SEL */
#define OPAMP2_VREFSEL_SEL_0                           ((uint32_t)0x00000004U) /* Bit0 */
#define OPAMP2_VREFSEL_SEL_1                           ((uint32_t)0x00000008U) /* Bit1 */

#define OPAMP3_VREFSEL_SEL                             ((uint32_t)0x00000030U) /* OPAMP3 SEL */
#define OPAMP3_VREFSEL_SEL_0                           ((uint32_t)0x00000010U) /* Bit0 */
#define OPAMP3_VREFSEL_SEL_1                           ((uint32_t)0x00000020U) /* Bit1 */



/***   TIM  ***/

/** Bit definition for TIM_CTRL1 register  **/
#define TIM_CTRL1_CNTEN                         ((uint32_t)0x00000001U) /* Counter enable */
#define TIM_CTRL1_DIR                           ((uint32_t)0x00000002U) /* Direction */

#define TIM_CTRL1_CAMSEL                        ((uint32_t)0x0000000CU) /* CMS[1:0] bits (Center-aligned mode selection) */
#define TIM_CTRL1_CAMSEL_0                      ((uint32_t)0x00000004U) /* Bit 0 */
#define TIM_CTRL1_CAMSEL_1                      ((uint32_t)0x00000008U) /* Bit 1 */

#define TIM_CTRL1_UPRS                          ((uint32_t)0x00000010U) /* Update request source */
#define TIM_CTRL1_UPDIS                         ((uint32_t)0x00000020U) /* Update disable */

#define TIM_CTRL1_CLKD                          ((uint32_t)0x000000C0U) /* CKD[1:0] bits (clock division) */
#define TIM_CTRL1_CLKD_0                        ((uint32_t)0x00000040U) /* Bit 0 */
#define TIM_CTRL1_CLKD_1                        ((uint32_t)0x00000080U) /* Bit 1 */

#define TIM_CTRL1_ONEPM                         ((uint32_t)0x00000100U) /* One pulse mode */
#define TIM_CTRL1_ARPEN                         ((uint32_t)0x00000200U) /* Auto-reload preload enable */
#define TIM_CTRL1_LBKPEN                        ((uint32_t)0x00000400U) /* LOCKUP as bkp Enable*/
#define TIM_CTRL1_PBKPEN                        ((uint32_t)0x00000800U) /* PVD as bkp Enable */
#define TIM_CTRL1_CLRSEL                        ((uint32_t)0x00002000U) /* OCxRef clear selection */

#define TIM_CTRL1_C1SEL                         ((uint32_t)0x00010000U) /* Channel 1 selection */


#define TIM_CTRL1_ASMMETRIC                     ((uint32_t)0x00800000U)  /* Asynmmetric mode enable in center-aligned */
#define TIM_CTRL1_TRGLDCNTEN                    ((uint32_t)0x10000000U)  /* Trgi reset CNT enable */

/** Bit definition for TIM_CTRL2 register **/
#define TIM_CTRL2_OI1                           ((uint32_t)0x00000001U) /* Output Idle state 1 (OC1 output) */
#define TIM_CTRL2_OI1N                          ((uint32_t)0x00000002U) /* Output Idle state 1 (OC1N output) */
#define TIM_CTRL2_OI2                           ((uint32_t)0x00000004U) /* Output Idle state 2 (OC2 output) */
#define TIM_CTRL2_OI2N                          ((uint32_t)0x00000008U) /* Output Idle state 2 (OC2N output) */
#define TIM_CTRL2_OI3                           ((uint32_t)0x00000010U) /* Output Idle state 3 (OC3 output) */
#define TIM_CTRL2_OI3N                          ((uint32_t)0x00000020U) /* Output Idle state 3 (OC3N output) */
#define TIM_CTRL2_OI4                           ((uint32_t)0x00000040U) /* Output Idle state 4 (OC4 output) */
#define TIM_CTRL2_OI4N                          ((uint32_t)0x00000080U) /* Output Idle state 4 (OC4N output) */


#define TIM_CTRL2_MMSEL                         ((uint32_t)0x0000F000U) /* MMSEL[3:0] bits (Master Mode Selection) */
#define TIM_CTRL2_MMSEL_0                       ((uint32_t)0x00001000U) /* Bit 0 */
#define TIM_CTRL2_MMSEL_1                       ((uint32_t)0x00002000U) /* Bit 1 */
#define TIM_CTRL2_MMSEL_2                       ((uint32_t)0x00004000U) /* Bit 2 */
#define TIM_CTRL2_MMSEL_3                       ((uint32_t)0x00008000U) /* Bit 3 */

#define TIM_CTRL2_CCUSEL                        ((uint32_t)0x00010000U) /* Capture/Compare Control Update Selection */
#define TIM_CTRL2_CCDSEL                        ((uint32_t)0x00020000U) /* Capture/Compare DMA Selection */
#define TIM_CTRL2_CCPCTL                        ((uint32_t)0x00040000U) /* Capture/Compare Preloaded Control */
#define TIM_CTRL2_TI1SEL                        ((uint32_t)0x00080000U) /* TI1 Selection */

/** Bit definition for TIM_STS register **/
#define TIM_STS_CC1ITF                          ((uint32_t)0x00000001U) /* Capture/Compare 1 interrupt Flag */
#define TIM_STS_CC2ITF                          ((uint32_t)0x00000002U) /* Capture/Compare 2 interrupt Flag */
#define TIM_STS_CC3ITF                          ((uint32_t)0x00000004U) /* Capture/Compare 3 interrupt Flag */
#define TIM_STS_CC4ITF                          ((uint32_t)0x00000008U) /* Capture/Compare 4 interrupt Flag */
#define TIM_STS_CC5ITF                          ((uint32_t)0x00000010U) /* Capture/Compare 5 interrupt Flag */
#define TIM_STS_CC6ITF                          ((uint32_t)0x00000020U) /* Capture/Compare 6 interrupt Flag */
#define TIM_STS_C3LDCNTITF                      ((uint32_t)0x00000080U) /* Channel 3 load LVR to CNT interrupt Flag */
#define TIM_STS_CC1OCF                          ((uint32_t)0x00000100U) /* Capture/Compare 1 Overcapture Flag */
#define TIM_STS_CC2OCF                          ((uint32_t)0x00000200U) /* Capture/Compare 2 Overcapture Flag */
#define TIM_STS_CC3OCF                          ((uint32_t)0x00000400U) /* Capture/Compare 3 Overcapture Flag */
#define TIM_STS_CC4OCF                          ((uint32_t)0x00000800U) /* Capture/Compare 4 Overcapture Flag */
#define TIM_STS_UDITF                           ((uint32_t)0x00010000U) /* Update interrupt Flag */
#define TIM_STS_COMITF                          ((uint32_t)0x00020000U) /* COM interrupt Flag */
#define TIM_STS_TITF                            ((uint32_t)0x00040000U) /* Trigger interrupt Flag */
#define TIM_STS_BITF                            ((uint32_t)0x00080000U) /* Break interrupt Flag */
#define TIM_STS_LBKPITF                         ((uint32_t)0x00200000U) /* Lockup break interrupt Flag */
#define TIM_STS_PBKPITF                         ((uint32_t)0x00400000U) /* PVD break interrupt Flag */
#define TIM_STS_COMPBITF                        ((uint32_t)0x00800000U) /* COMP break interrupt Flag */
#define TIM_STS_CC7ITF                          ((uint32_t)0x01000000U) /* Capture/Compare 7 interrupt Flag */
#define TIM_STS_IOMBITF                         ((uint32_t)0x08000000U) /* IOM break interrupt Flag */

/** Bit definition for TIM_EVTGEN register **/
#define TIM_EVTGEN_CC1GN                        ((uint32_t)0x00000001U) /* Capture/Compare 1 Generation */
#define TIM_EVTGEN_CC2GN                        ((uint32_t)0x00000002U) /* Capture/Compare 2 Generation */
#define TIM_EVTGEN_CC3GN                        ((uint32_t)0x00000004U) /* Capture/Compare 3 Generation */
#define TIM_EVTGEN_CC4GN                        ((uint32_t)0x00000008U) /* Capture/Compare 4 Generation */
#define TIM_EVTGEN_UDGN                         ((uint32_t)0x00000100U) /* Update Generation */
#define TIM_EVTGEN_CCUDGN                       ((uint32_t)0x00000200U) /* Capture/Compare Control Update Generation */
#define TIM_EVTGEN_TGN                          ((uint32_t)0x00000400U) /* Trigger Generation */
#define TIM_EVTGEN_BGN                          ((uint32_t)0x00000800U) /* Break Generation */

/** Bit definition for TIM_SMCTRL register **/
#define TIM_SMCTRL_TSEL                         ((uint32_t)0x00000007U) /* TS[2:0] bits (Trigger selection) */
#define TIM_SMCTRL_TSEL_0                       ((uint32_t)0x00000001U) /* Bit 0 */
#define TIM_SMCTRL_TSEL_1                       ((uint32_t)0x00000002U) /* Bit 1 */
#define TIM_SMCTRL_TSEL_2                       ((uint32_t)0x00000004U) /* Bit 2 */

#define TIM_SMCTRL_SMSEL                        ((uint32_t)0x000000F0U) /* SMS[2:0] bits (Slave mode selection) */
#define TIM_SMCTRL_SMSEL_0                      ((uint32_t)0x00000010U) /* Bit 0 */
#define TIM_SMCTRL_SMSEL_1                      ((uint32_t)0x00000020U) /* Bit 1 */
#define TIM_SMCTRL_SMSEL_2                      ((uint32_t)0x00000040U) /* Bit 2 */
#define TIM_SMCTRL_SMSEL_3                      ((uint32_t)0x00000080U) /* Bit 3 */

#define TIM_SMCTRL_EXTPS                        ((uint32_t)0x00000300U) /* ETPS[1:0] bits (External trigger prescaler) */
#define TIM_SMCTRL_EXTPS_0                      ((uint32_t)0x00000100U) /* Bit 0 */
#define TIM_SMCTRL_EXTPS_1                      ((uint32_t)0x00000200U) /* Bit 1 */

#define TIM_SMCTRL_EXCEN                        ((uint32_t)0x00000400U) /* External clock enable */
#define TIM_SMCTRL_EXTP                         ((uint32_t)0x00000800U) /* External trigger polarity */

#define TIM_SMCTRL_EXTF                         ((uint32_t)0x0000F000U) /* ETF[3:0] bits (External trigger filter) */
#define TIM_SMCTRL_EXTF_0                       ((uint32_t)0x00001000U) /* Bit 0 */
#define TIM_SMCTRL_EXTF_1                       ((uint32_t)0x00002000U) /* Bit 1 */
#define TIM_SMCTRL_EXTF_2                       ((uint32_t)0x00004000U) /* Bit 2 */
#define TIM_SMCTRL_EXTF_3                       ((uint32_t)0x00008000U) /* Bit 3 */

#define TIM_SMCTRL_MSMD                         ((uint32_t)0x00010000U) /* Master/slave mode */


/** Bit definition for TIM_DINTEN register **/
#define TIM_DINTEN_CC1IEN                       ((uint32_t)0x00000001U) /* Capture/Compare 1 interrupt enable */
#define TIM_DINTEN_CC2IEN                       ((uint32_t)0x00000002U) /* Capture/Compare 2 interrupt enable */
#define TIM_DINTEN_CC3IEN                       ((uint32_t)0x00000004U) /* Capture/Compare 3 interrupt enable */
#define TIM_DINTEN_CC4IEN                       ((uint32_t)0x00000008U) /* Capture/Compare 4 interrupt enable */
#define TIM_DINTEN_CC5IEN                       ((uint32_t)0x00000010U) /* Capture/Compare 5 interrupt enable */
#define TIM_DINTEN_CC6IEN                       ((uint32_t)0x00000020U) /* Capture/Compare 6 interrupt enable */
#define TIM_DINTEN_CC7IEN                       ((uint32_t)0x00000040U) /* Capture/Compare 7 interrupt enable */
#define TIM_DINTEN_C3LDCNTIEN                  ((uint32_t)0x00000080U) /* Channel 3 reset CNT interrupt enable */
#define TIM_DINTEN_CC1DEN                       ((uint32_t)0x00000100U) /* Capture/Compare 1 DMA request enable */
#define TIM_DINTEN_CC2DEN                       ((uint32_t)0x00000200U) /* Capture/Compare 2 DMA request enable */
#define TIM_DINTEN_CC3DEN                       ((uint32_t)0x00000400U) /* Capture/Compare 3 DMA request enable */
#define TIM_DINTEN_CC4DEN                       ((uint32_t)0x00000800U) /* Capture/Compare 4 DMA request enable */
#define TIM_DINTEN_UIEN                         ((uint32_t)0x00010000U) /* Update interrupt enable */
#define TIM_DINTEN_TIEN                         ((uint32_t)0x00020000U) /* Trigger interrupt enable */
#define TIM_DINTEN_BIEN                         ((uint32_t)0x00040000U) /* Break interrupt enable */
#define TIM_DINTEN_UDEN                         ((uint32_t)0x00080000U) /* Update DMA request enable */
#define TIM_DINTEN_COMDEN                       ((uint32_t)0x00100000U) /* COM DMA request enable */
#define TIM_DINTEN_TDEN                         ((uint32_t)0x00200000U) /* Trigger DMA request enable */
#define TIM_DINTEN_COMIEN                       ((uint32_t)0x00400000U) /* COM interrupt enable */


/** Bit definition for TIM_CCMOD1 register **/
#define TIM_CCMOD1_CC1SEL                       ((uint32_t)0x00000003U) /* CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define TIM_CCMOD1_CC1SEL_0                     ((uint32_t)0x00000001U) /* Bit 0 */
#define TIM_CCMOD1_CC1SEL_1                     ((uint32_t)0x00000002U) /* Bit 1 */

#define TIM_CCMOD1_OC1PEN                       ((uint32_t)0x00000004U) /* Output Compare 1 Preload enable */
#define TIM_CCMOD1_OC1FEN                       ((uint32_t)0x00000008U) /* Output Compare 1 Fast enable */
#define TIM_CCMOD1_OC1CEN                       ((uint32_t)0x00000010U) /* Output Compare 1 Clear Enable */

#define TIM_CCMOD1_OC1MD                        ((uint32_t)0x000000E0U) /* OC1MD[2:0] bits (Output Compare 1 Mode) */
#define TIM_CCMOD1_OC1MD_0                      ((uint32_t)0x00000020U) /* Bit 0 */
#define TIM_CCMOD1_OC1MD_1                      ((uint32_t)0x00000040U) /* Bit 1 */
#define TIM_CCMOD1_OC1MD_2                      ((uint32_t)0x00000080U) /* Bit 2 */

#define TIM_CCMOD1_CC2SEL                       ((uint32_t)0x00000300U) /* CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define TIM_CCMOD1_CC2SEL_0                     ((uint32_t)0x00000100U) /* Bit 0 */
#define TIM_CCMOD1_CC2SEL_1                     ((uint32_t)0x00000200U) /* Bit 1 */

#define TIM_CCMOD1_OC2PEN                       ((uint32_t)0x00000400U) /* Output Compare 2 Preload enable */
#define TIM_CCMOD1_OC2FEN                       ((uint32_t)0x00000800U) /* Output Compare 2 Fast enable */
#define TIM_CCMOD1_OC2CEN                       ((uint32_t)0x00001000U) /* Output Compare 2 Clear Enable */

#define TIM_CCMOD1_OC2MD                        ((uint32_t)0x0000E000U) /* OC2MD[2:0] bits (Output Compare 2 Mode) */
#define TIM_CCMOD1_OC2MD_0                      ((uint32_t)0x00002000U) /* Bit 0 */
#define TIM_CCMOD1_OC2MD_1                      ((uint32_t)0x00004000U) /* Bit 1 */
#define TIM_CCMOD1_OC2MD_2                      ((uint32_t)0x00008000U) /* Bit 2 */

#define TIM_CCMOD1_OC1MD_3                      ((uint32_t)0x00020000U) /* OC1MD3 bit (Output Compare 1 Mode) */
#define TIM_CCMOD1_OC2MD_3                      ((uint32_t)0x00040000U) /* OC2MD3 bit (Output Compare 2 Mode) */

#define TIM_CCMOD1_IC1PSC                       ((uint32_t)0x0000000CU) /* IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define TIM_CCMOD1_IC1PSC_0                     ((uint32_t)0x00000004U) /* Bit 0 */
#define TIM_CCMOD1_IC1PSC_1                     ((uint32_t)0x00000008U) /* Bit 1 */

#define TIM_CCMOD1_IC1F                         ((uint32_t)0x000000F0U) /* IC1F[3:0] bits (Input Capture 1 Filter) */
#define TIM_CCMOD1_IC1F_0                       ((uint32_t)0x00000010U) /* Bit 0 */
#define TIM_CCMOD1_IC1F_1                       ((uint32_t)0x00000020U) /* Bit 1 */
#define TIM_CCMOD1_IC1F_2                       ((uint32_t)0x00000040U) /* Bit 2 */
#define TIM_CCMOD1_IC1F_3                       ((uint32_t)0x00000080U) /* Bit 3 */

#define TIM_CCMOD1_IC2PSC                       ((uint32_t)0x00000C00U) /* IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
#define TIM_CCMOD1_IC2PSC_0                     ((uint32_t)0x00000400U) /* Bit 0 */
#define TIM_CCMOD1_IC2PSC_1                     ((uint32_t)0x00000800U) /* Bit 1 */

#define TIM_CCMOD1_IC2F                         ((uint32_t)0x0000F000U) /* IC2F[3:0] bits (Input Capture 2 Filter) */
#define TIM_CCMOD1_IC2F_0                       ((uint32_t)0x00001000U) /* Bit 0 */
#define TIM_CCMOD1_IC2F_1                       ((uint32_t)0x00002000U) /* Bit 1 */
#define TIM_CCMOD1_IC2F_2                       ((uint32_t)0x00004000U) /* Bit 2 */
#define TIM_CCMOD1_IC2F_3                       ((uint32_t)0x00008000U) /* Bit 3 */

/** Bit definition for TIM_CCMOD2 register **/
#define TIM_CCMOD2_CC3SEL                       ((uint32_t)0x00000003U) /* CC3S[1:0] bits (Capture/Compare 3 Selection) */
#define TIM_CCMOD2_CC3SEL_0                     ((uint32_t)0x00000001U) /* Bit 0 */
#define TIM_CCMOD2_CC3SEL_1                     ((uint32_t)0x00000002U) /* Bit 1 */

#define TIM_CCMOD2_OC3PEN                       ((uint32_t)0x00000004U) /* Output Compare 3 Preload enable */
#define TIM_CCMOD2_OC3FEN                       ((uint32_t)0x00000008U) /* Output Compare 3 Fast enable */
#define TIM_CCMOD2_OC3CEN                       ((uint32_t)0x00000010U) /* Output Compare 3 Clear Enable */

#define TIM_CCMOD2_OC3MD                        ((uint32_t)0x000000E0U) /* OC3MD[2:0] bits (Output Compare 3 Mode) */
#define TIM_CCMOD2_OC3MD_0                      ((uint32_t)0x00000020U) /* Bit 0 */
#define TIM_CCMOD2_OC3MD_1                      ((uint32_t)0x00000040U) /* Bit 1 */
#define TIM_CCMOD2_OC3MD_2                      ((uint32_t)0x00000080U) /* Bit 2 */

#define TIM_CCMOD2_CC4SEL                       ((uint32_t)0x00000300U) /* CC3S[1:0] bits (Capture/Compare 4 Selection) */
#define TIM_CCMOD2_CC4SEL_0                     ((uint32_t)0x00000100U) /* Bit 0 */
#define TIM_CCMOD2_CC4SEL_1                     ((uint32_t)0x00000200U) /* Bit 1 */

#define TIM_CCMOD2_OC4PEN                       ((uint32_t)0x00000400U) /* Output Compare 4 Preload enable */
#define TIM_CCMOD2_OC4FEN                       ((uint32_t)0x00000800U) /* Output Compare 4 Fast enable */
#define TIM_CCMOD2_OC4CEN                       ((uint32_t)0x00001000U) /* Output Compare 4 Clear Enable */

#define TIM_CCMOD2_OC4MD                        ((uint32_t)0x0000E000U) /* OC4MD[2:0] bits (Output Compare 4 Mode) */
#define TIM_CCMOD2_OC4MD_0                      ((uint32_t)0x00002000U) /* Bit 0 */
#define TIM_CCMOD2_OC4MD_1                      ((uint32_t)0x00004000U) /* Bit 1 */
#define TIM_CCMOD2_OC4MD_2                      ((uint32_t)0x00008000U) /* Bit 2 */

#define TIM_CCMOD2_OC3MD_3                      ((uint32_t)0x00020000U) /* OC3MD3 bit (Output Compare 3 Mode) */
#define TIM_CCMOD2_OC4MD_3                      ((uint32_t)0x00040000U) /* OC4MD3 bit (Output Compare 4 Mode) */

#define TIM_CCMOD2_IC3PSC                       ((uint32_t)0x0000000CU) /* IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define TIM_CCMOD2_IC3PSC_0                     ((uint32_t)0x00000004U) /* Bit 0 */
#define TIM_CCMOD2_IC3PSC_1                     ((uint32_t)0x00000008U) /* Bit 1 */

#define TIM_CCMOD2_IC3F                         ((uint32_t)0x000000F0U) /* IC3F[3:0] bits (Input Capture 3 Filter) */
#define TIM_CCMOD2_IC3F_0                       ((uint32_t)0x00000010U) /* Bit 0 */
#define TIM_CCMOD2_IC3F_1                       ((uint32_t)0x00000020U) /* Bit 1 */
#define TIM_CCMOD2_IC3F_2                       ((uint32_t)0x00000040U) /* Bit 2 */
#define TIM_CCMOD2_IC3F_3                       ((uint32_t)0x00000080U) /* Bit 3 */

#define TIM_CCMOD2_IC4PSC                       ((uint32_t)0x00000C00U) /* IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define TIM_CCMOD2_IC4PSC_0                     ((uint32_t)0x00000400U) /* Bit 0 */
#define TIM_CCMOD2_IC4PSC_1                     ((uint32_t)0x00000800U) /* Bit 1 */


#define TIM_CCMOD2_IC4F                         ((uint32_t)0x0000F000U) /* IC4F[3:0] bits (Input Capture 4 Filter) */
#define TIM_CCMOD2_IC4F_0                       ((uint32_t)0x00001000U) /* Bit 0 */
#define TIM_CCMOD2_IC4F_1                       ((uint32_t)0x00002000U) /* Bit 1 */
#define TIM_CCMOD2_IC4F_2                       ((uint32_t)0x00004000U) /* Bit 2 */
#define TIM_CCMOD2_IC4F_3                       ((uint32_t)0x00008000U) /* Bit 3 */

/** Bit definition for TIM_CCMOD3 register **/
#define TIM_CCMOD3_OC5PEN                       ((uint32_t)0x00000004U) /* Output Compare 5 Preload enable */
#define TIM_CCMOD3_OC5FEN                       ((uint32_t)0x00000008U) /* Output Compare 5 Fast enable */
#define TIM_CCMOD3_OC5CEN                       ((uint32_t)0x00000010U) /* Output Compare 5 Clear Enable */

#define TIM_CCMOD3_OC5MD                        ((uint32_t)0x000000E0U) /* OC5M[2:0] bits (Output Compare 5 Mode) */
#define TIM_CCMOD3_OC5MD_0                      ((uint32_t)0x00000020U) /* Bit 0 */
#define TIM_CCMOD3_OC5MD_1                      ((uint32_t)0x00000040U) /* Bit 1 */
#define TIM_CCMOD3_OC5MD_2                      ((uint32_t)0x00000080U) /* Bit 2 */

#define TIM_CCMOD3_OC6PEN                       ((uint32_t)0x00000400U) /* Output Compare 6 Preload enable */
#define TIM_CCMOD3_OC6FEN                       ((uint32_t)0x00000800U) /* Output Compare 6 Fast enable */
#define TIM_CCMOD3_OC6CEN                       ((uint32_t)0x00001000U) /* Output Compare 6 Clear Enable */

#define TIM_CCMOD3_OC6MD                        ((uint32_t)0x0000E000U) /* OC6M[2:0] bits (Output Compare 6 Mode) */
#define TIM_CCMOD3_OC6MD_0                      ((uint32_t)0x00002000U) /* Bit 0 */
#define TIM_CCMOD3_OC6MD_1                      ((uint32_t)0x00004000U) /* Bit 1 */
#define TIM_CCMOD3_OC6MD_2                      ((uint32_t)0x00008000U) /* Bit 2 */

#define TIM_CCMOD3_OC7PEN                       ((uint32_t)0x00010000U) /* Output Compare 7 Preload enable */
#define TIM_CCMOD3_OC7FEN                       ((uint32_t)0x00020000U) /* Output Compare 7 Fast enable */
#define TIM_CCMOD3_OC7CEN                       ((uint32_t)0x00040000U) /* Output Compare 7 Clear Enable */

#define TIM_CCMOD3_OC7MD                        ((uint32_t)0x0E000000U) /* OC6M[2:0] bits (Output Compare 7 Mode) */
#define TIM_CCMOD3_OC7MD_0                      ((uint32_t)0x02000000U) /* Bit 0 */
#define TIM_CCMOD3_OC7MD_1                      ((uint32_t)0x04000000U) /* Bit 1 */
#define TIM_CCMOD3_OC7MD_2                      ((uint32_t)0x08000000U) /* Bit 2 */
/** Bit definition for TIM_CCEN register **/
#define TIM_CCEN_CC1NEN                         ((uint32_t)0x00000001U) /* Capture/Compare 1 Complementary output enable */
#define TIM_CCEN_CC1NP                          ((uint32_t)0x00000002U) /* Capture/Compare 1 Complementary output Polarity */
#define TIM_CCEN_CC1EN                          ((uint32_t)0x00000004U) /* Capture/Compare 1 output enable */
#define TIM_CCEN_CC1P                           ((uint32_t)0x00000008U) /* Capture/Compare 1 output Polarity */
#define TIM_CCEN_CC2NEN                         ((uint32_t)0x00000010U) /* Capture/Compare 2 Complementary output enable */
#define TIM_CCEN_CC2NP                          ((uint32_t)0x00000020U) /* Capture/Compare 2 Complementary output Polarity */
#define TIM_CCEN_CC2EN                          ((uint32_t)0x00000040U) /* Capture/Compare 2 output enable */
#define TIM_CCEN_CC2P                           ((uint32_t)0x00000080U) /* Capture/Compare 2 output Polarity */
#define TIM_CCEN_CC3NEN                         ((uint32_t)0x00000100U) /* Capture/Compare 3 Complementary output enable */
#define TIM_CCEN_CC3NP                          ((uint32_t)0x00000200U) /* Capture/Compare 3 Complementary output Polarity */
#define TIM_CCEN_CC3EN                          ((uint32_t)0x00000400U) /* Capture/Compare 3 output enable */
#define TIM_CCEN_CC3P                           ((uint32_t)0x00000800U) /* Capture/Compare 3 output Polarity */
#define TIM_CCEN_CC4NEN                         ((uint32_t)0x00001000U) /* Capture/Compare 4 Complementary output enable */
#define TIM_CCEN_CC4NP                          ((uint32_t)0x00002000U) /* Capture/Compare 4 Complementary output Polarity */
#define TIM_CCEN_CC4EN                          ((uint32_t)0x00004000U) /* Capture/Compare 4 output enable */
#define TIM_CCEN_CC4P                           ((uint32_t)0x00008000U) /* Capture/Compare 4 output Polarity */
#define TIM_CCEN_CC5EN                          ((uint32_t)0x00040000U) /* Capture/Compare 5 output enable */
#define TIM_CCEN_CC5P                           ((uint32_t)0x00080000U) /* Capture/Compare 5 output Polarity */
#define TIM_CCEN_CC6EN                          ((uint32_t)0x00400000U) /* Capture/Compare 6 output enable */
#define TIM_CCEN_CC6P                           ((uint32_t)0x00800000U) /* Capture/Compare 6 output Polarity */
#define TIM_CCEN_CC7EN                          ((uint32_t)0x01000000U) /* Capture/Compare 6 output enable */
#define TIM_CCEN_CC7P                           ((uint32_t)0x02000000U) /* Capture/Compare 6 output Polarity */

/** Bit definition for TIM_CCDAT1 register **/
#define TIM_CCDAT1_CCDAT1                       ((uint32_t)0x0000FFFFU)  /* Capture/Compare 1 Value */
#define TIM_CCDAT1_CCDDAT1                      ((uint32_t)0xFFFF0000U)  /* Capture/Compare 1 down-counting Value */
#define TIM_CCDAT1                              ((uint32_t)0xFFFFFFFFU)  /* Capture/Compare 1 Value */

/** Bit definition for TIM_CCDAT2 register **/
#define TIM_CCDAT2_CCDAT2                       ((uint32_t)0x0000FFFFU)  /* Capture/Compare 2 Value */
#define TIM_CCDAT2_CCDDAT2                      ((uint32_t)0xFFFF0000U)  /* Capture/Compare 2 down-counting Value */
#define TIM_CCDAT2                              ((uint32_t)0xFFFFFFFFU)  /* Capture/Compare 2 Value */

/** Bit definition for TIM_CCDAT3 register **/
#define TIM_CCDAT3_CCDAT3                       ((uint32_t)0x0000FFFFU)  /* Capture/Compare 3 Value */
#define TIM_CCDAT3_CCDDAT3                      ((uint32_t)0xFFFF0000U)  /* Capture/Compare 3 down-counting Value */
#define TIM_CCDAT3                              ((uint32_t)0xFFFFFFFFU)  /* Capture/Compare 3 Value */

/** Bit definition for TIM_CCDAT4 register **/
#define TIM_CCDAT4_CCDAT4                       ((uint32_t)0x0000FFFFU)  /* Capture/Compare 4 Value */
#define TIM_CCDAT4_CCDDAT4                      ((uint32_t)0xFFFF0000U)  /* Capture/Compare 4 down-counting Value */

/** Bit definition for TIM_CCDAT5 register **/
#define TIM_CCDAT5_CCDAT5                       ((uint32_t)0x0000FFFFU)  /* Capture/Compare 5 Value */

/** Bit definition for TIM_CCDAT6 register **/
#define TIM_CCDAT6_CCDAT6                       ((uint32_t)0x0000FFFFU)  /* Capture/Compare 6 Value */

/** Bit definition for TIM_PSC register **/
#define TIM_PSC_PSC                             ((uint32_t)0x0000FFFFU)  /* Prescaler Value */

/** Bit definition for TIM_AR register **/
#define TIM_AR_AR                               ((uint32_t)0xFFFFFFFFU)  /* actual auto-reload Value */

/** Bit definition for TIM_CNT register **/
#define TIM_CNT_CNT                             ((uint32_t)0xFFFFFFFFU)  /* Counter Value */

/** Bit definition for TIM_REPCNT register **/
#define TIM_REPCNT_REPCNT                       ((uint32_t)0x000000FFU) /* Repetition Counter Value */

/** Bit definition for TIM_BKDT register **/
#define TIM_BKDT_DTGN                           ((uint32_t)0x000000FFU) /* DTG[0:7] bits (Dead-Time Generator set-up) */
#define TIM_BKDT_DTGN_0                         ((uint32_t)0x00000001U) /* Bit 0 */
#define TIM_BKDT_DTGN_1                         ((uint32_t)0x00000002U) /* Bit 1 */
#define TIM_BKDT_DTGN_2                         ((uint32_t)0x00000004U) /* Bit 2 */
#define TIM_BKDT_DTGN_3                         ((uint32_t)0x00000008U) /* Bit 3 */
#define TIM_BKDT_DTGN_4                         ((uint32_t)0x00000010U) /* Bit 4 */
#define TIM_BKDT_DTGN_5                         ((uint32_t)0x00000020U) /* Bit 5 */
#define TIM_BKDT_DTGN_6                         ((uint32_t)0x00000040U) /* Bit 6 */
#define TIM_BKDT_DTGN_7                         ((uint32_t)0x00000080U) /* Bit 7 */

#define TIM_BKDT_MOEN                           ((uint32_t)0x00000100U) /* Main Output enable */
#define TIM_BKDT_AOEN                           ((uint32_t)0x00000200U) /* Automatic Output enable */
#define TIM_BKDT_BKP                            ((uint32_t)0x00000400U) /* Break Polarity */
#define TIM_BKDT_BKEN                           ((uint32_t)0x00000800U) /* Break enable */
#define TIM_BKDT_OSSI                           ((uint32_t)0x00001000U) /* Off-State Selection for Idle mode */
#define TIM_BKDT_OSSR                           ((uint32_t)0x00002000U) /* Off-State Selection for Run mode */

#define TIM_BKDT_LCKCFG                         ((uint32_t)0x0000C000U) /* LOCK[1:0] bits (Lock Configuration) */
#define TIM_BKDT_LCKCFG_0                       ((uint32_t)0x00004000U) /* Bit 0 */
#define TIM_BKDT_LCKCFG_1                       ((uint32_t)0x00008000U) /* Bit 1 */

/** Bit definition for TIM_CCDAT7 register **/
#define TIM_CCDAT7_CCDAT7                       ((uint32_t)0x0000FFFFU)  /* Capture/Compare 7 Value */

/** Bit definition for TIM_BKFR register **/     
#define TIM_BKFR_THRESH                         ((uint32_t)0x3F000000U) /* Break1 filter threshold */
#define TIM_BKFR_THRESH_0                       ((uint32_t)0x01000000U) /* Bit 0 */
#define TIM_BKFR_THRESH_1                       ((uint32_t)0x02000000U) /* Bit 1 */
#define TIM_BKFR_THRESH_2                       ((uint32_t)0x04000000U) /* Bit 2 */
#define TIM_BKFR_THRESH_3                       ((uint32_t)0x08000000U) /* Bit 3 */
#define TIM_BKFR_THRESH_4                       ((uint32_t)0x10000000U) /* Bit 4 */
#define TIM_BKFR_THRESH_5                       ((uint32_t)0x20000000U) /* Bit 5 */

#define TIM_BKFR_WSIZE                          ((uint32_t)0x007E0000U) /* Break1 filter window size */
#define TIM_BKFR_WSIZE_0                        ((uint32_t)0x00020000U) /* Bit 0 */
#define TIM_BKFR_WSIZE_1                        ((uint32_t)0x00040000U) /* Bit 1 */
#define TIM_BKFR_WSIZE_2                        ((uint32_t)0x00080000U) /* Bit 2 */
#define TIM_BKFR_WSIZE_3                        ((uint32_t)0x00100000U) /* Bit 3 */
#define TIM_BKFR_WSIZE_4                        ((uint32_t)0x00200000U) /* Bit 4 */
#define TIM_BKFR_WSIZE_5                        ((uint32_t)0x00400000U) /* Bit 5 */

#define TIM_BKFR_FILTEN                         ((uint32_t)0x00010000U) /* Break1 filter enable */

/** Bit definition for TIM_C1FILT register **/
#define TIM_C1FILT_THRESH                       ((uint32_t)0x3F000000U) /* CH1 filter threshold */
#define TIM_C1FILT_THRESH_0                     ((uint32_t)0x01000000U) /* Bit 0 */
#define TIM_C1FILT_THRESH_1                     ((uint32_t)0x02000000U) /* Bit 1 */
#define TIM_C1FILT_THRESH_2                     ((uint32_t)0x04000000U) /* Bit 2 */
#define TIM_C1FILT_THRESH_3                     ((uint32_t)0x08000000U) /* Bit 3 */
#define TIM_C1FILT_THRESH_4                     ((uint32_t)0x10000000U) /* Bit 4 */
#define TIM_C1FILT_THRESH_5                     ((uint32_t)0x20000000U) /* Bit 5 */

#define TIM_C1FILT_WSIZE                        ((uint32_t)0x007E0000U) /* CH1 filter window size */
#define TIM_C1FILT_WSIZE_0                      ((uint32_t)0x00020000U) /* Bit 0 */
#define TIM_C1FILT_WSIZE_1                      ((uint32_t)0x00040000U) /* Bit 1 */
#define TIM_C1FILT_WSIZE_2                      ((uint32_t)0x00080000U) /* Bit 2 */
#define TIM_C1FILT_WSIZE_3                      ((uint32_t)0x00100000U) /* Bit 3 */
#define TIM_C1FILT_WSIZE_4                      ((uint32_t)0x00200000U) /* Bit 4 */
#define TIM_C1FILT_WSIZE_5                      ((uint32_t)0x00400000U) /* Bit 5 */

#define TIM_C1FILT_FILTEN                       ((uint32_t)0x00010000U)

/** Bit definition for TIM_C2FILT register **/
#define TIM_C2FILT_THRESH                       ((uint32_t)0x3F000000U) /* CH2 filter threshold */
#define TIM_C2FILT_THRESH_0                     ((uint32_t)0x01000000U) /* Bit 0 */
#define TIM_C2FILT_THRESH_1                     ((uint32_t)0x02000000U) /* Bit 1 */
#define TIM_C2FILT_THRESH_2                     ((uint32_t)0x04000000U) /* Bit 2 */
#define TIM_C2FILT_THRESH_3                     ((uint32_t)0x08000000U) /* Bit 3 */
#define TIM_C2FILT_THRESH_4                     ((uint32_t)0x10000000U) /* Bit 4 */
#define TIM_C2FILT_THRESH_5                     ((uint32_t)0x20000000U) /* Bit 5 */

#define TIM_C2FILT_WSIZE                        ((uint32_t)0x007E0000U) /* CH2 filter window size */
#define TIM_C2FILT_WSIZE_0                      ((uint32_t)0x00020000U) /* Bit 0 */
#define TIM_C2FILT_WSIZE_1                      ((uint32_t)0x00040000U) /* Bit 1 */
#define TIM_C2FILT_WSIZE_2                      ((uint32_t)0x00080000U) /* Bit 2 */
#define TIM_C2FILT_WSIZE_3                      ((uint32_t)0x00100000U) /* Bit 3 */
#define TIM_C2FILT_WSIZE_4                      ((uint32_t)0x00200000U) /* Bit 4 */
#define TIM_C2FILT_WSIZE_5                      ((uint32_t)0x00400000U) /* Bit 5 */

#define TIM_C2FILT_FILTEN                       ((uint32_t)0x00010000U)

/** Bit definition for TIM_C3FILT register **/
#define TIM_C3FILT_THRESH                       ((uint32_t)0x3F000000U) /* CH3 filter threshold */
#define TIM_C3FILT_THRESH_0                     ((uint32_t)0x01000000U) /* Bit 0 */
#define TIM_C3FILT_THRESH_1                     ((uint32_t)0x02000000U) /* Bit 1 */
#define TIM_C3FILT_THRESH_2                     ((uint32_t)0x04000000U) /* Bit 2 */
#define TIM_C3FILT_THRESH_3                     ((uint32_t)0x08000000U) /* Bit 3 */
#define TIM_C3FILT_THRESH_4                     ((uint32_t)0x10000000U) /* Bit 4 */
#define TIM_C3FILT_THRESH_5                     ((uint32_t)0x20000000U) /* Bit 5 */

#define TIM_C3FILT_WSIZE                        ((uint32_t)0x007E0000U) /* CH3 filter window size */
#define TIM_C3FILT_WSIZE_0                      ((uint32_t)0x00020000U) /* Bit 0 */
#define TIM_C3FILT_WSIZE_1                      ((uint32_t)0x00040000U) /* Bit 1 */
#define TIM_C3FILT_WSIZE_2                      ((uint32_t)0x00080000U) /* Bit 2 */
#define TIM_C3FILT_WSIZE_3                      ((uint32_t)0x00100000U) /* Bit 3 */
#define TIM_C3FILT_WSIZE_4                      ((uint32_t)0x00200000U) /* Bit 4 */
#define TIM_C3FILT_WSIZE_5                      ((uint32_t)0x00400000U) /* Bit 5 */

#define TIM_C3FILT_FILTEN                       ((uint32_t)0x00010000U)

/** Bit definition for TIM_FILTO register **/
#define TIM_FILTO_C1FILTO                       ((uint32_t)0x00000001U) /* CH1 filter output state */
#define TIM_FILTO_C2FILTO                       ((uint32_t)0x00000002U) /* CH2 filter output state */
#define TIM_FILTO_C3FILTO                       ((uint32_t)0x00000004U) /* CH3 filter output state */

/** Bit definition for TIM_AF1 register **/
#define TIM_AF1_IOM1BRKEN                       ((uint32_t)0x00000001U) /* Enable IOM1 as break1 input */
#define TIM_AF1_COMP1BRKEN                      ((uint32_t)0x00000002U) /* Enable COMP1 as break1 input */
#define TIM_AF1_IOM1BRKP                        ((uint32_t)0x00000200U) /* Select polarity of break1 input from IOM1 */
#define TIM_AF1_COMP1BRKP                       ((uint32_t)0x00000400U) /* Select polarity of break1 input from COMP1 */
#define TIM_AF1_IOM2BRKEN                       ((uint32_t)0x00010000U) /* Enable IOM2 as break1 input */
#define TIM_AF1_IOM3BRKEN                       ((uint32_t)0x00020000U) /* Enable IOM3 as break1 input */
#define TIM_AF1_IOM4BRKEN                       ((uint32_t)0x00040000U) /* Enable IOM4 as break1 input */
#define TIM_AF1_IOM2BRKP                        ((uint32_t)0x00080000U) /* Select polarity of break1 input from IOM2 */
#define TIM_AF1_IOM3BRKP                        ((uint32_t)0x00100000U) /* Select polarity of break1 input from IOM3 */
#define TIM_AF1_IOM4BRKP                        ((uint32_t)0x00200000U) /* Select polarity of break1 input from IOM4 */

/** Bit definition for TIM_ENCDAT register **/
#define TIM_ENCDAT_ENCDAT                       ((uint32_t)0xFFFFFFFFU) /*  */


/** Bit definition for TIM_ENCMCTRL register **/
#define TIM_ENCMCTRL_C3LDCNTEN                   ((uint32_t)0x00000001U) /*  */

#define TIM_ENCMCTRL_C3LDCNTSEL                  ((uint32_t)0x00000006U) /*  */
#define TIM_ENCMCTRL_C3LDCNTSEL_0                ((uint32_t)0x00000002U) /*  */
#define TIM_ENCMCTRL_C3LDCNTSEL_1                ((uint32_t)0x00000004U) /*  */

#define TIM_ENCMCTRL_ENCMD                       ((uint32_t)0x00000078U) /*  */
#define TIM_ENCMCTRL_ENCMD_0                     ((uint32_t)0x00000008U) /*  */
#define TIM_ENCMCTRL_ENCMD_1                     ((uint32_t)0x00000010U) /*  */
#define TIM_ENCMCTRL_ENCMD_2                     ((uint32_t)0x00000020U) /*  */
#define TIM_ENCMCTRL_ENCMD_3                     ((uint32_t)0x00000040U) /*  */

#define TIM_ENCMCTRL_ENCDATS                     ((uint32_t)0x80000000U) /*  */


/** Bit definition for TIM_ENCMCTRL register **/
#define TIM_ENCLVR_LVR                            ((uint32_t)0xFFFFFFFFU) /*  */


/** Bit definition for TIM_DCTRL register **/
#define TIM_DCTRL_DBADDR                        ((uint32_t)0x00003F00U) /* DBA[5:0] bits (DMA Base Address) */
#define TIM_DCTRL_DBADDR_0                      ((uint32_t)0x00000100U) /* Bit 0 */
#define TIM_DCTRL_DBADDR_1                      ((uint32_t)0x00000200U) /* Bit 1 */
#define TIM_DCTRL_DBADDR_2                      ((uint32_t)0x00000400U) /* Bit 2 */
#define TIM_DCTRL_DBADDR_3                      ((uint32_t)0x00000800U) /* Bit 3 */
#define TIM_DCTRL_DBADDR_4                      ((uint32_t)0x00001000U) /* Bit 4 */
#define TIM_DCTRL_DBADDR_5                      ((uint32_t)0x00002000U) /* Bit 5 */

#define TIM_DCTRL_DBLEN                         ((uint32_t)0x0000003FU) /* DBL[5:0] bits (DMA Burst Length) */
#define TIM_DCTRL_DBLEN_0                       ((uint32_t)0x00000001U) /* Bit 0 */
#define TIM_DCTRL_DBLEN_1                       ((uint32_t)0x00000002U) /* Bit 1 */
#define TIM_DCTRL_DBLEN_2                       ((uint32_t)0x00000004U) /* Bit 2 */
#define TIM_DCTRL_DBLEN_3                       ((uint32_t)0x00000008U) /* Bit 3 */
#define TIM_DCTRL_DBLEN_4                       ((uint32_t)0x00000010U) /* Bit 4 */
#define TIM_DCTRL_DBLEN_5                       ((uint32_t)0x00000020U) /* Bit 5 */

/** Bit definition for TIM_DADDR register **/
#define TIM_DADDR_BURST                         ((uint32_t)0xFFFFFFFFU) /* DMA register for burst accesses */

/******************************************************************************/
/*                                                                            */
/*                           Independent WATCHDOG                             */
/*                                                                            */
/******************************************************************************/

/** Bit definition for IWDG_KEY register **/
#define IWDG_KEY_KEYV     ((uint16_t)0xFFFFU) /* Key value (write only, read 0000h) */

/** Bit definition for IWDG_STS register **/
#define IWDG_STS_PVU      ((uint8_t)0x01U)    /* Watchdog prescaler value update */
#define IWDG_STS_CRVU     ((uint8_t)0x02U)    /* Watchdog counter reload value update */

/** Bit definition for IWDG_PREDIV register **/
#define IWDG_PREDIV_PD    ((uint8_t)0x07U)    /* PD[2:0] (Prescaler divider) */
#define IWDG_PREDIV_PD0   ((uint8_t)0x01U)    /* Bit 0 */
#define IWDG_PREDIV_PD1   ((uint8_t)0x02U)    /* Bit 1 */
#define IWDG_PREDIV_PD2   ((uint8_t)0x04U)    /* Bit 2 */

/** Bit definition for IWDG_RELV register **/
#define IWDG_RELV_REL     ((uint16_t)0x3FFFU) /* Watchdog counter reload value */

/** Bit definition for IWDG_CTRL register **/
#define IWDG_CRTL_ITE     ((uint32_t)0x01U) /* Watchdog counter Interrupt */


/*                                                                            */
/*                        Comparators Peripheral Interface                         */
/*                                                                            */
/******************************************************************************/

/******** Bit definition for COMP_INTEN register  ********/
#define COMP_INTEN_CMPIEN                                 ((uint32_t)0x00000001U)         /* Bit[0] */

/******** Bit definition for COMP_INTSTS register  ********/
#define COMP_INTSTS_CMPIS                                 ((uint32_t)0x00000001U)         /* Bit[0] */

/******** Bit definition for COMP_LOCK register  ********/
#define COMP_LOCK_CMPLK                                   ((uint32_t)0x00000001U)         /* Bit[0] */

/******** Bit definition for COMP_CTRL register  ********/
#define COMP_CTRL_CLKSEL                                  ((uint32_t)0x00100000U)         /* Bit[20] */
#define COMP_CTRL_PWRMD                                   ((uint32_t)0x00080000U)         /* Bit[19] */
#define COMP_CTRL_OUT                                     ((uint32_t)0x00020000U)         /* Bit[17] */
#define COMP_CTRL_BLKING                                  ((uint32_t)0x00004000U)         /* Bit[14] */

#define COMP_CTRL_HYST                                    ((uint32_t)0x00003000U)         /* Bit[13:12] */
#define COMP_CTRL_HYST_0                                  ((uint32_t)0x00001000U)         /* Bit12*/
#define COMP_CTRL_HYST_1                                  ((uint32_t)0x00002000U)         /* Bit13*/
#define COMP_CTRL_POL                                     ((uint32_t)0x00000800U)         /* Bit[11] */

#define COMP_CTRL_INPSEL                                  ((uint32_t)0x000000F0U)         /* Bit[7:4] */
#define COMP_CTRL_INPSEL_0                                ((uint32_t)0x00000010U)         /* Bit4*/
#define COMP_CTRL_INPSEL_1                                ((uint32_t)0x00000020U)         /* Bit5*/
#define COMP_CTRL_INPSEL_2                                ((uint32_t)0x00000040U)         /* Bit6*/
#define COMP_CTRL_INPSEL_3                                ((uint32_t)0x00000080U)         /* Bit7*/

#define COMP_CTRL_INMSEL                                  ((uint32_t)0x0000000EU)         /* Bit[3:1] */
#define COMP_CTRL_INMSEL_0                                ((uint32_t)0x00000002U)         /* Bit1*/
#define COMP_CTRL_INMSEL_1                                ((uint32_t)0x00000004U)         /* Bit2*/
#define COMP_CTRL_INMSEL_2                                ((uint32_t)0x00000008U)         /* Bit3*/

#define COMP_CTRL_EN                                      ((uint32_t)0x00000001U)         /* Bit[0] */

/******** Bit definition for COMP_FILC register  ********/
#define COMP_FILC_SAMPW                                   ((uint32_t)0x000007C0U)         /* Bit[10:6] */

#define COMP_FILC_THRESH                                  ((uint32_t)0x0000003EU)         /* Bit[5:1] */

#define COMP_FILC_FILEN                                   ((uint32_t)0x00000001U)         /* Bit[0] */

/******** Bit definition for COMP_FILP register  ********/
#define COMP_FILP_CLKPSC                                  ((uint32_t)0x0000FFFFU)         /* Bit[15:0] */

/******** Bit definition for COMP_INVREF register  ********/
#define COMP_INVREF_VREFSEL                               ((uint32_t)0x000001FEU)         /* Bit[8:1] */

#define COMP_INVREF_VREFEN                                ((uint32_t)0x00000001U)         /* Bit[0] */


/*** Serial Peripheral Interface ***/

/** Bit definition for SPI_CTRL1 register **/
#define SPI_CTRL1_BR        ((uint16_t)0x0007U)      /* BR[2:0] bits (Baud Rate Control) */
#define SPI_CTRL1_BR0       ((uint16_t)0x0001U)      /* Bit 0 */
#define SPI_CTRL1_BR1       ((uint16_t)0x0002U)      /* Bit 1 */
#define SPI_CTRL1_BR2       ((uint16_t)0x0004U)      /* Bit 2 */
#define SPI_CTRL1_CLKPOL    ((uint16_t)0x0010U)      /* Clock Polarity */
#define SPI_CTRL1_CLKPHA    ((uint16_t)0x0020U)      /* Clock Phase */
#define SPI_CTRL1_MSEL      ((uint16_t)0x0040U)      /* Master Selection */
#define SPI_CTRL1_LSBFF     ((uint16_t)0x0080U)      /* Frame Format */
#define SPI_CTRL1_DATFF     ((uint16_t)0x0100U)      /* Data Frame Format */
#define SPI_CTRL1_CRCNEXT   ((uint16_t)0x0200U)      /* Transmit CRC next */
#define SPI_CTRL1_SSOEN     ((uint16_t)0x0400U)      /* SS Output Enable */
#define SPI_CTRL1_SSEL      ((uint16_t)0x0800U)      /* Internal slave select */
#define SPI_CTRL1_SSMEN     ((uint16_t)0x1000U)      /* Software slave management */
#define SPI_CTRL1_RONLY     ((uint16_t)0x2000U)      /* Receive only */
#define SPI_CTRL1_BIDIROEN  ((uint16_t)0x4000U)      /* Output enable in bidirectional mode */
#define SPI_CTRL1_BIDIRMODE ((uint16_t)0x8000U)      /* Bidirectional data mode enable */

/** Bit definition for SPI_CTRL2 register **/ 
#define SPI_CTRL2_SPIEN     ((uint16_t)0x0001U)      /* SPI Enable */
#define SPI_CTRL2_RDMAEN    ((uint16_t)0x0002U)      /* Rx buffer DMA enable */
#define SPI_CTRL2_TDMAEN    ((uint16_t)0x0004U)      /* Tx buffer DMA enable */
#define SPI_CTRL2_CRCEN     ((uint16_t)0x0008U)      /* Hardware CRC calculation enable */
#define SPI_CTRL2_TEINTEN   ((uint16_t)0x0010U)      /* Tx buffer Empty Interrupt Enable */
#define SPI_CTRL2_RNEINTEN  ((uint16_t)0x0020U)      /* RX buffer Not Empty Interrupt Enable */
#define SPI_CTRL2_ERRINTEN  ((uint16_t)0x0040U)      /* Error Interrupt Enable */
#define SPI_CTRL2_NSSPOL    ((uint16_t)0x0080U)      /* NSS polarity */
#define SPI_CTRL2_CRCSTP    ((uint16_t)0x2000U)      /* CRC stop calculation control */

/** Bit definition for SPI_STS register **/
#define SPI_STS_TE          ((uint16_t)0x0001U)      /* Transmit buffer Empty */
#define SPI_STS_RNE         ((uint16_t)0x0002U)      /* Receive buffer Not Empty */
#define SPI_STS_BUSY        ((uint16_t)0x0004U)      /* Busy flag */
#define SPI_STS_CRCERR      ((uint16_t)0x0008U)      /* CRC fault */
#define SPI_STS_MODERR      ((uint16_t)0x0010U)      /* Mode fault */
#define SPI_STS_OVER        ((uint16_t)0x0020U)      /* Overrun flag */

/** Bit definition for SPI_DAT register **/
#define SPI_DAT_DAT         ((uint16_t)0xFFFFU)      /* Data Register */

/** Bit definition for SPI_CRCTDAT register **/
#define SPI_CRCTDAT_DAT     ((uint16_t)0xFFFFU)      /* The CRC result value to send */

/** Bit definition for SPI_CRCRDAT register **/
#define SPI_CRCRDAT_DAT     ((uint16_t)0xFFFFU)      /* The received CRC result value */

/** Bit definition for SPI_CRCPOLY register **/
#define SPI_CRCPOLY_DAT     ((uint16_t)0xFFFFU)      /* CRC polynomial */

/** Bit definition for SPI_CTRL3 register **/
#define SPI_CTRL3_DELAYTIME ((uint16_t)0x000FU)      /* SPI Host Clock Delay Time Configuration */

/******************************************************************************/
/*                                                                            */
/*                      Inter-integrated Circuit Interface                    */
/*                                                                            */
/******************************************************************************/

/** Bit definition for I2C_CTRL1 register **/
#define I2C_CTRL1_EN       ((uint32_t)0x00000001U) /* Peripheral Enable */
#define I2C_CTRL1_SMBMODE  ((uint32_t)0x00000002U) /* SMBus Mode */
#define I2C_CTRL1_SMBTYPE  ((uint32_t)0x00000004U) /* SMBus Type */
#define I2C_CTRL1_ARPEN    ((uint32_t)0x00000008U) /* ARP Enable */
#define I2C_CTRL1_PECEN    ((uint32_t)0x00000010U) /* PEC Enable */
#define I2C_CTRL1_GCEN     ((uint32_t)0x00000020U) /* General Call Enable */
#define I2C_CTRL1_NOEXTEND ((uint32_t)0x00000040U) /* Clock Stretching Disable (Slave mode) */
#define I2C_CTRL1_STARTGEN ((uint32_t)0x00000080U) /* Start Generation */
#define I2C_CTRL1_STOPGEN  ((uint32_t)0x00000100U) /* Stop Generation */
#define I2C_CTRL1_ACKEN    ((uint32_t)0x00000200U) /* Acknowledge Enable */
#define I2C_CTRL1_ACKPOS   ((uint32_t)0x00000400U) /* Acknowledge/PEC Position (for data reception) */
#define I2C_CTRL1_PEC      ((uint32_t)0x00000800U) /* Packet Error Checking */
#define I2C_CTRL1_SMBALERT ((uint32_t)0x00001000U) /* SMBus Alert */
#define I2C_CTRL1_SWRESET  ((uint32_t)0x00002000U) /* Software Reset */

#define I2C_CTRL1_HTOSEL   ((uint32_t)0x18000000U) /* high timeout threshold selection */
#define I2C_CTRL1_HTOSEL_0 ((uint32_t)0x08000000U) /* Bit 0 */
#define I2C_CTRL1_HTOSEL_1 ((uint32_t)0x10000000U) /* Bit 1 */

#define I2C_CTRL1_LTOSEL   ((uint32_t)0x60000000U) /* low timeout threshold selection */
#define I2C_CTRL1_LTOSEL_0 ((uint32_t)0x20000000U) /* Bit 0 */
#define I2C_CTRL1_LTOSEL_1 ((uint32_t)0x40000000U) /* Bit 1 */

/** Bit definition for I2C_CTRL2 register **/
#define I2C_CTRL2_CLKFREQ   ((uint32_t)0x0000007FU) /* FREQ[6:0] bits (Peripheral Clock Frequency) */
#define I2C_CTRL2_CLKFREQ_0 ((uint32_t)0x00000001U) /* Bit 0 */
#define I2C_CTRL2_CLKFREQ_1 ((uint32_t)0x00000002U) /* Bit 1 */
#define I2C_CTRL2_CLKFREQ_2 ((uint32_t)0x00000004U) /* Bit 2 */
#define I2C_CTRL2_CLKFREQ_3 ((uint32_t)0x00000008U) /* Bit 3 */
#define I2C_CTRL2_CLKFREQ_4 ((uint32_t)0x00000010U) /* Bit 4 */
#define I2C_CTRL2_CLKFREQ_5 ((uint32_t)0x00000020U) /* Bit 5 */
#define I2C_CTRL2_CLKFREQ_6 ((uint32_t)0x00000040U) /* Bit 6 */

#define I2C_CTRL2_DMALAST  ((uint32_t)0x00000100U) /* DMA Last Transfer */
#define I2C_CTRL2_BUFINTEN ((uint32_t)0x00001000U) /* Buffer Interrupt Enable */
#define I2C_CTRL2_EVTINTEN ((uint32_t)0x00002000U) /* Event Interrupt Enable */
#define I2C_CTRL2_ERRINTEN ((uint32_t)0x00004000U) /* Error Interrupt Enable */
#define I2C_CTRL2_DMAEN    ((uint32_t)0x00008000U) /* DMA Requests Enable */

#define I2C_CTRL2_SDALTOINTEN    ((uint32_t)0x04000000U) /* SDA low timeout error interrupt enable */
#define I2C_CTRL2_SCLHTOINTEN    ((uint32_t)0x08000000U) /* SCL high timeout error interrupt enable */
#define I2C_CTRL2_SCLLTOINTEN    ((uint32_t)0x10000000U) /* SCL low timeout error interrupt enable */
#define I2C_CTRL2_HTOEN          ((uint32_t)0x20000000U) /* high timeout function enable */
#define I2C_CTRL2_LTOEN          ((uint32_t)0x40000000U) /* low timeout function enable */

/** Bit definition for I2C_OADDR1 register **/
#define I2C_OADDR1_ADDR1_7 ((uint16_t)0x00FEU) /* Interface Address */
#define I2C_OADDR1_ADDR8_9 ((uint16_t)0x0300U) /* Interface Address */

#define I2C_OADDR1_ADDR0 ((uint16_t)0x0001U) /* Bit 0 */
#define I2C_OADDR1_ADDR1 ((uint16_t)0x0002U) /* Bit 1 */
#define I2C_OADDR1_ADDR2 ((uint16_t)0x0004U) /* Bit 2 */
#define I2C_OADDR1_ADDR3 ((uint16_t)0x0008U) /* Bit 3 */
#define I2C_OADDR1_ADDR4 ((uint16_t)0x0010U) /* Bit 4 */
#define I2C_OADDR1_ADDR5 ((uint16_t)0x0020U) /* Bit 5 */
#define I2C_OADDR1_ADDR6 ((uint16_t)0x0040U) /* Bit 6 */
#define I2C_OADDR1_ADDR7 ((uint16_t)0x0080U) /* Bit 7 */
#define I2C_OADDR1_ADDR8 ((uint16_t)0x0100U) /* Bit 8 */
#define I2C_OADDR1_ADDR9 ((uint16_t)0x0200U) /* Bit 9 */

#define I2C_OADDR1_ADDRMODE ((uint16_t)0x8000U) /* Addressing Mode (Slave mode) */

/** Bit definition for I2C_OADDR2 register **/
#define I2C_OADDR2_DUALEN ((uint8_t)0x01U) /* Dual addressing mode enable */
#define I2C_OADDR2_ADDR2  ((uint8_t)0xFEU) /* Interface address */

/** Bit definition for I2C_DAT register **/
#define I2C_DAT_DATA ((uint8_t)0xFFU) /* 8-bit Data Register */

/** Bit definition for I2C_STS1 register **/
#define I2C_STS1_STARTBF  ((uint16_t)0x0001U) /* Start Bit (Master mode) */
#define I2C_STS1_ADDRF    ((uint16_t)0x0002U) /* Address sent (master mode)/matched (slave mode) */
#define I2C_STS1_BSF      ((uint16_t)0x0004U) /* Byte Transfer Finished */
#define I2C_STS1_STOPF    ((uint16_t)0x0008U) /* Stop detection (Slave mode) */
#define I2C_STS1_RXDATNE  ((uint16_t)0x0010U) /* Data Register not Empty (receivers) */
#define I2C_STS1_TXDATE   ((uint16_t)0x0020U) /* Data Register Empty (transmitters) */
#define I2C_STS1_ADDR10F  ((uint16_t)0x0040U) /* 10-bit header sent (Master mode) */

#define I2C_STS1_ACKFAIL  ((uint16_t)0x0100U) /* Acknowledge Failure */
#define I2C_STS1_ARLOST   ((uint16_t)0x0200U) /* Arbitration Lost (master mode) */
#define I2C_STS1_BUSERR   ((uint16_t)0x0400U) /* Bus Error */
#define I2C_STS1_OVERRUN  ((uint16_t)0x0800U) /* Overrun/Underrun */
#define I2C_STS1_PECERR   ((uint16_t)0x1000U) /* PEC Error in reception */
#define I2C_STS1_TIMEOUT  ((uint16_t)0x2000U) /* Timeout */
#define I2C_STS1_SMBALERT ((uint16_t)0x4000U) /* SMBus Alert */

#define I2C_STS1_SDALTO   ((uint32_t)0x00800000U) /* SDA low timeout error */
#define I2C_STS1_SCLHTO   ((uint32_t)0x01000000U) /* SCL high timeout error */
#define I2C_STS1_SCLLTO   ((uint32_t)0x02000000U) /* SCL low timeout error */

/** Bit definition for I2C_STS2 register **/

#define I2C_STS2_BUSY      ((uint16_t)0x0001U) /* Bus Busy */
#define I2C_STS2_MSMODE    ((uint16_t)0x0002U) /* Master/Slave */
#define I2C_STS2_TRF       ((uint16_t)0x0004U) /* Transmitter/Receiver */

#define I2C_STS2_GCALLADDR ((uint16_t)0x0010U) /* General Call Address (Slave mode) */
#define I2C_STS2_DUALFLAG  ((uint16_t)0x0020U) /* Dual Flag (Slave mode) */
#define I2C_STS2_SMBDADDR  ((uint16_t)0x0040U) /* SMBus Device Default Address (Slave mode) */
#define I2C_STS2_SMBHADDR  ((uint16_t)0x0080U) /* SMBus Host Header (Slave mode) */

#define I2C_STS2_PECVAL    ((uint16_t)0xFF00U) /* Packet Error Checking Register */

/** Bit definition for I2C_CLKCTRL register **/
#define I2C_CLKCTRL_CLKCTRL ((uint16_t)0x0FFFU) /* Clock Control Register in Fast/Standard mode (Master mode) */
#define I2C_CLKCTRL_FSMODE  ((uint16_t)0x4000U) /* I2C Master Mode Selection */
#define I2C_CLKCTRL_DUTY    ((uint16_t)0x8000U) /* Fast Mode Duty Cycle */

/**  Bit definition for I2C_TMRISE register  ***/
#define  I2C_TMRISE_TMRISE   ((uint8_t)0x3FU)               /* Maximum Rise Time in Fast/Standard mode (Master mode) */

/**  Bit definition for I2C_GFLTRCTRL register  ***/
#define  I2C_GFLTRCTRL_SDADFW   ((uint16_t)0x000FU) /* SDA digital gfilter width selection */
#define  I2C_GFLTRCTRL_SCLDFW   ((uint16_t)0x00F0U) /* SCL digital gfilter width selection */

#define  I2C_GFLTRCTRL_SDAAFW   ((uint16_t)0x0300U) /* SDA analog gfilter width selection */
#define  I2C_GFLTRCTRL_SDAAFW_0 ((uint16_t)0x0100U) /* Bit 0 */
#define  I2C_GFLTRCTRL_SDAAFW_1 ((uint16_t)0x0200U) /* Bit 1 */

#define  I2C_GFLTRCTRL_SDAAFENN ((uint16_t)0x0800U) /* SDA analog gfilter enable */

#define  I2C_GFLTRCTRL_SCLAFW   ((uint16_t)0x3000U) /* SCL analog gfilter width selection */
#define  I2C_GFLTRCTRL_SCLAFW_0 ((uint16_t)0x1000U) /* Bit 0 */
#define  I2C_GFLTRCTRL_SCLAFW_1 ((uint16_t)0x2000U) /* Bit 1 */

#define  I2C_GFLTRCTRL_SCLAFENN ((uint16_t)0x8000U) /* SCL analog gfilter enable */

/*** Universal Synchronous Asynchronous Receiver Transmitter ***/

/** Bit definition for UART_CTRL1 register **/
#define UART_CTRL1_UEN         ((uint32_t)0x00000001U) /* UART Enable */
#define UART_CTRL1_RXEN        ((uint32_t)0x00000002U) /* Receiver Enable */
#define UART_CTRL1_TXEN        ((uint32_t)0x00000004U) /* Transmitter Enable */
#define UART_CTRL1_PSEL        ((uint32_t)0x00000008U) /* Parity Selection */
#define UART_CTRL1_PCEN        ((uint32_t)0x00000010U) /* Parity Control Enable */
#define UART_CTRL1_WL          ((uint32_t)0x00000020U) /* Word length */
#define UART_CTRL1_RCVWU       ((uint32_t)0x00000040U) /* Receiver wakeup */
#define UART_CTRL1_WUM         ((uint32_t)0x00000080U) /* Wakeup method */
#define UART_CTRL1_IDLEIEN     ((uint32_t)0x00000100U) /* IDLE Interrupt Enable */
#define UART_CTRL1_RXDNEIEN    ((uint32_t)0x00000200U) /* RXNE Interrupt Enable */
#define UART_CTRL1_TXDEIEN     ((uint32_t)0x00000400U) /* PE Interrupt Enable */
#define UART_CTRL1_TXCIEN      ((uint32_t)0x00000800U) /* Transmission Complete Interrupt Enable */
#define UART_CTRL1_PEIEN       ((uint32_t)0x00001000U) /* PE Interrupt Enable */
#define UART_CTRL1_SDBRK       ((uint32_t)0x00002000U) /* Send Break */
#define UART_CTRL1_DEM         ((uint32_t)0x00004000U) /* Driver enable mode */
#define UART_CTRL1_DEP         ((uint32_t)0x00008000U) /* Driver enable polarity selection */
#define UART_CTRL1_DEDT_MASK   ((uint32_t)0x001F0000U) /* Driver Enable deassertion time mask */
#define UART_CTRL1_DEAT_MASK   ((uint32_t)0x03E00000U) /* Driver Enable assertion time mask */
#define UART_CTRL1_OSPM        ((uint32_t)0x04000000U) /* Oversampling mode */
#define UART_CTRL1_SWAP        ((uint32_t)0x08000000U) /* Swap TX/RX pins */

/** Bit definition for UART_CTRL2 register **/
#define UART_CTRL2_ADDR        ((uint32_t)0x0000000FU) /* Address of the UART node */
#define UART_CTRL2_STPB        ((uint32_t)0x00000060U) /* STOP[1:0] bits (STOP bits) */
#define UART_CTRL2_STPB_0      ((uint32_t)0x00000020U) /* Bit 0 */
#define UART_CTRL2_STPB_1      ((uint32_t)0x00000040U) /* Bit 1 */
#define UART_CTRL2_LINMEN      ((uint32_t)0x00001000U) /* LIN mode enable */
#define UART_CTRL2_LINBDIEN    ((uint32_t)0x00002000U) /* LIN Break Detection Interrupt Enable */
#define UART_CTRL2_LINBDL      ((uint32_t)0x00004000U) /* LIN Break Detection Length */
#define UART_CTRL2_RTOEN       ((uint32_t)0x00008000U) /* Receiver timeout enable */
#define UART_CTRL2_RTOCF       ((uint32_t)0x00010000U) /* Receiver timeout clear flag */
#define UART_CTRL2_RTOITE      ((uint32_t)0x00020000U) /* Receiver timeout interrupt enable */

/** Bit definition for UART_CTRL3 register **/
#define UART_CTRL3_HDMEN   ((uint32_t)0x00000008U) /* Half-Duplex Selection */
#define UART_CTRL3_DMATXEN ((uint32_t)0x00000010U) /* DMA Enable Transmitter */
#define UART_CTRL3_DMARXEN ((uint32_t)0x00000020U) /* DMA Enable Receiver */
#define UART_CTRL3_ERRIEN  ((uint32_t)0x00000040U) /* Error Interrupt Enable */
#define UART_CTRL3_IRDAMEN ((uint32_t)0x00000080U) /* IrDA mode Enable */
#define UART_CTRL3_IRDALP  ((uint32_t)0x00000100U) /* IrDA Low-Power */

/** Bit definition for UART_STS register **/
#define UART_STS_IDLEF     ((uint32_t)0x00000040U) /* IDLE line detected */
#define UART_STS_TXDE      ((uint32_t)0x00000080U) /* Transmit Data Register Empty */
#define UART_STS_TXC       ((uint32_t)0x00000100U) /* Transmission Complete */
#define UART_STS_RXDNE     ((uint32_t)0x00000200U) /* Read Data Register Not Empty */
#define UART_STS_LINBDF    ((uint32_t)0x00000800U) /* LIN Break Detection Flag */
#define UART_STS_PEF       ((uint32_t)0x00001000U) /* Parity Error */
#define UART_STS_OREF      ((uint32_t)0x00002000U) /* OverRun Error */
#define UART_STS_NEF       ((uint32_t)0x00004000U) /* Noise Error Flag */
#define UART_STS_FEF       ((uint32_t)0x00008000U) /* Framing Error */
#define UART_STS_RTOF      ((uint32_t)0x00010000U) /* recevier timeout */

/** Bit definition for UART_DAT register **/
#define UART_DAT_DATV      ((uint32_t)0x000001FFU) /* Data value */

/** Bit definition for UART_BRCF register **/
#define UART_BRCF_DIV_Decimal ((uint32_t)0x000FU) /* Fraction of UARTDIV */
#define UART_BRCF_DIV_Integer ((uint32_t)0xFFF0U) /* Mantissa of UARTDIV */

/** Bit definition for UART_GTP register **/
#define UART_GTP_PSCV   ((uint32_t)0x00FFU) /* PSC[7:0] bits (Prescaler value) */
#define UART_GTP_PSCV_0 ((uint32_t)0x0001U) /* Bit 0 */
#define UART_GTP_PSCV_1 ((uint32_t)0x0002U) /* Bit 1 */
#define UART_GTP_PSCV_2 ((uint32_t)0x0004U) /* Bit 2 */
#define UART_GTP_PSCV_3 ((uint32_t)0x0008U) /* Bit 3 */
#define UART_GTP_PSCV_4 ((uint32_t)0x0010U) /* Bit 4 */
#define UART_GTP_PSCV_5 ((uint32_t)0x0020U) /* Bit 5 */
#define UART_GTP_PSCV_6 ((uint32_t)0x0040U) /* Bit 6 */
#define UART_GTP_PSCV_7 ((uint32_t)0x0080U) /* Bit 7 */

/** Bit definition for UART_IFW register **/
#define UART_RTO_WIDTH_MASK        ((uint32_t)0x0FFFFFFFU) /* Receiver timeout value */

/** Bit definition for UART_WAKEUP register **/
#define UART_WAKEUP_EN_MASK            ((uint32_t)0x00000001U) /* Wakeup enable */
#define UART_WAKEUP_DATCLR_MASK        ((uint32_t)0x00000002U) /* Data clear when Wakeup */


/*** HDIV ***/

/** Bit definition for HDIV_CTRLSTS register **/
#define HDIV_CTRLSTS_HDIVEN            ((uint32_t)0x00000001U) /* HDIV enable */
#define HDIV_CTRLSTS_HDIVSTART         ((uint32_t)0x00000002U) /* HDIV start */
#define HDIV_CTRLSTS_HDIVDF            ((uint32_t)0x00000008U) /* HDIV done flag */
#define HDIV_CTRLSTS_HDIVBUSHOLD       ((uint32_t)0x00000040U) /* Indicate the bus when calculating. */   
#define HDIV_CTRLSTS_HDIVAUTOSTART     ((uint32_t)0x00000080U) /* auto start of calculating. */ 
#define HDIV_CTRLSTS_HDIVTYPESEL       ((uint32_t)0x00000100U) /* Indicate the type of the data. */

/** Bit definition for HDIV_DIVIDEND register***/
#define HDIV_DIVIDEND_DIVIDEND         ((uint32_t)0xFFFFFFFFU) /* 32bit unsigned interger dividend */

/** Bit definition for HDIV_DIVISOR register **/
#define HDIV_DIVISOR_DIVISOR           ((uint32_t)0xFFFFFFFFU) /* 32bit unsigned interger divisor */

/** Bit definition for HDIV_QUOTIENT register***/
#define HDIV_QUOTIENT_QUOTIENT         ((uint32_t)0xFFFFFFFFU) /* Quotient calculated by the divider */

/** Bit definition for HDIV_REMAINDER registe****/
#define HDIV_REMAINDER_REMAINDER       ((uint32_t)0xFFFFFFFFU) /* Remainder calculated by the divider */

/** Bit definition for HDIV_DIVBY0 register  */
#define HDIV_DIVBY0_DIVBY0             ((uint32_t)0x00000001U) /* The divisor is 0 flag */


/*** Square Root Calculations(SQRT) ***/

/** Bit definition for SQRT_CTRLSTS register  **/
#define SQRT_CTRLSTS_SQRTEN            ((uint32_t)0x00000001U) /* SQRT enable */
#define SQRT_CTRLSTS_SQRTSTART         ((uint32_t)0x00000002U) /* SQRT start */
#define SQRT_CTRLSTS_SQRTDF            ((uint32_t)0x00000008U) /* SQRT done flag */
#define SQRT_CTRLSTS_BUSHOLD           ((uint32_t)0x00000040U) /* Indicate the bus when calculating. */  
#define SQRT_CTRLSTS_AUTOSTART         ((uint32_t)0x00000080U) /* auto start of calculating. */ 

/** Bit definition for SQRT_RADICANT register **/
#define SQRT_RADICANT_RADICANT         ((uint32_t)0xFFFFFFFFU) /* 32bit unsigned interger squared */

/** Bit definition for SQRT_ROOT register **/
#define SQRT_ROOT_ROOT                 ((uint32_t)0x0000FFFFU) /* 16bit Square root output */



/*** FLASH and Option Bytes Registers ***/

/** Bit definition for FLASH_AC register **/
#define FLASH_AC_LATENCY                                 ((uint32_t)0x00000007U)         /* Bit[2:0] */
#define FLASH_AC_LATENCY_0                               ((uint32_t)0x00000000U)         /* Bit 0 = 0 */
#define FLASH_AC_LATENCY_1                               ((uint32_t)0x00000001U)         /* Bit 0 = 1 */

/** Bit definition for FLASH_KEY register **/
#define FLASH_KEY_FKEY                                    ((uint32_t)0xFFFFFFFFU)        /* FLASH Key */

/** Bit definition for FLASH_OPTKEY register **/
#define FLASH_OPTKEY_OPTKEY                               ((uint32_t)0xFFFFFFFFU)         /* Option Byte Key */

/** Bit definition for FLASH_STS register **/
#define FLASH_STS_EOP                                     ((uint32_t)0x00000020U)         /* Bit[5] */
#define FLASH_STS_WRPERR                                  ((uint32_t)0x00000010U)         /* Bit[4] */
#define FLASH_STS_PGERR                                   ((uint32_t)0x00000004U)         /* Bit[2] */
#define FLASH_STS_BUSY                                    ((uint32_t)0x00000001U)         /* Bit[0] */

/** Bit definition for FLASH_CTRL register **/
#define FLASH_CTRL_EOPITE                                  ((uint32_t)0x00001000U)         /* Bit[12] */
#define FLASH_CTRL_ERRITE                                  ((uint32_t)0x00000400U)         /* Bit[10] */
#define FLASH_CTRL_OPTWE                                   ((uint32_t)0x00000200U)         /* Bit[9] */
#define FLASH_CTRL_LOCK                                    ((uint32_t)0x00000080U)         /* Bit[7] */
#define FLASH_CTRL_START                                   ((uint32_t)0x00000040U)         /* Bit[6] */
#define FLASH_CTRL_OPTER                                   ((uint32_t)0x00000020U)         /* Bit[5] */
#define FLASH_CTRL_OPTPG                                   ((uint32_t)0x00000010U)         /* Bit[4] */
#define FLASH_CTRL_MER                                     ((uint32_t)0x00000004U)         /* Bit[2] */
#define FLASH_CTRL_PER                                     ((uint32_t)0x00000002U)         /* Bit[1] */
#define FLASH_CTRL_PG                                      ((uint32_t)0x00000001U)         /* Bit[0] */

/** Bit definition for FLASH_ADD register **/
#define FLASH_ADD_FADD                                     ((uint32_t)0xFFFFFFFFU)        /* Flash Address */

/** Bit definition for FLASH_OB2 register **/
#define FLASH_OB2_Data1                                   ((uint32_t)0x0000FF00U)         /* Bit[15:8] */
#define FLASH_OB2_Data1_0                                 ((uint32_t)0x00000100U)         /* Bit8*/
#define FLASH_OB2_Data1_1                                 ((uint32_t)0x00000200U)         /* Bit9*/
#define FLASH_OB2_Data1_2                                 ((uint32_t)0x00000400U)         /* Bit10*/
#define FLASH_OB2_Data1_3                                 ((uint32_t)0x00000800U)         /* Bit11*/
#define FLASH_OB2_Data1_4                                 ((uint32_t)0x00001000U)         /* Bit12*/
#define FLASH_OB2_Data1_5                                 ((uint32_t)0x00002000U)         /* Bit13*/
#define FLASH_OB2_Data1_6                                 ((uint32_t)0x00004000U)         /* Bit14*/
#define FLASH_OB2_Data1_7                                 ((uint32_t)0x00008000U)         /* Bit15*/
#define FLASH_OB2_Data0                                   ((uint32_t)0x000000FFU)         /* Bit[7:0] */
#define FLASH_OB2_Data0_0                                 ((uint32_t)0x00000001U)         /* Bit0*/
#define FLASH_OB2_Data0_1                                 ((uint32_t)0x00000002U)         /* Bit1*/
#define FLASH_OB2_Data0_2                                 ((uint32_t)0x00000004U)         /* Bit2*/
#define FLASH_OB2_Data0_3                                 ((uint32_t)0x00000008U)         /* Bit3*/
#define FLASH_OB2_Data0_4                                 ((uint32_t)0x00000010U)         /* Bit4*/
#define FLASH_OB2_Data0_5                                 ((uint32_t)0x00000020U)         /* Bit5*/
#define FLASH_OB2_Data0_6                                 ((uint32_t)0x00000040U)         /* Bit6*/
#define FLASH_OB2_Data0_7                                 ((uint32_t)0x00000080U)         /* Bit7*/

/** Bit definition for FLASH_OB register **/
#define FLASH_OB_RDPRT2                                  ((uint32_t)0x80000000U)         /* Bit[31] */
#define FLASH_OB_BOOT_SEL                                ((uint32_t)0x00300000U)         /* Bit[21:20] */
#define FLASH_OB_BOOT_SEL_0                              ((uint32_t)0x00100000U)         /* Bit20*/
#define FLASH_OB_BOOT_SEL_1                              ((uint32_t)0x00200000U)         /* Bit21*/
#define FLASH_OB_BOOT0_CFG                               ((uint32_t)0x00008000U)         /* Bit[15] */
#define FLASH_OB_nSWBOOT0                                ((uint32_t)0x00004000U)         /* Bit[14] */
#define FLASH_OB_nBOOT1                                  ((uint32_t)0x00002000U)         /* Bit[13] */
#define FLASH_OB_nBOOT0                                  ((uint32_t)0x00001000U)         /* Bit[12] */
#define FLASH_OB_POR_DELAY                               ((uint32_t)0x00000FF0U)         /* Bit[11:4] */
#define FLASH_OB_POR_DELAY_0                             ((uint32_t)0x00000010U)         /* Bit4*/
#define FLASH_OB_POR_DELAY_1                             ((uint32_t)0x00000020U)         /* Bit5*/
#define FLASH_OB_POR_DELAY_2                             ((uint32_t)0x00000040U)         /* Bit6*/
#define FLASH_OB_POR_DELAY_3                             ((uint32_t)0x00000080U)         /* Bit7*/
#define FLASH_OB_POR_DELAY_4                             ((uint32_t)0x00000100U)         /* Bit8*/
#define FLASH_OB_POR_DELAY_5                             ((uint32_t)0x00000200U)         /* Bit9*/
#define FLASH_OB_POR_DELAY_6                             ((uint32_t)0x00000400U)         /* Bit10*/
#define FLASH_OB_POR_DELAY_7                             ((uint32_t)0x00000800U)         /* Bit11*/
#define FLASH_OB_NRST_PF3                                ((uint32_t)0x00000008U)         /* Bit[3] */
#define FLASH_OB_IWDG_SW                                 ((uint32_t)0x00000004U)         /* Bit[2] */
#define FLASH_OB_RDPRT1                                  ((uint32_t)0x00000002U)         /* Bit[1] */
#define FLASH_OB_OBERR                                   ((uint32_t)0x00000001U)         /* Bit[0] */

/** Bit definition for FLASH_WRP register **/
#define FLASH_WRP_WRPT                                     ((uint32_t)0x00FF00FFU)         /* Write Protect */
#define FLASH_WRP_WRPT_0                                   ((uint32_t)0x00000001U)         /* Bit0*/
#define FLASH_WRP_WRPT_1                                   ((uint32_t)0x00000002U)         /* Bit1*/
#define FLASH_WRP_WRPT_2                                   ((uint32_t)0x00000004U)         /* Bit2*/
#define FLASH_WRP_WRPT_3                                   ((uint32_t)0x00000008U)         /* Bit3*/
#define FLASH_WRP_WRPT_4                                   ((uint32_t)0x00000010U)         /* Bit4*/
#define FLASH_WRP_WRPT_5                                   ((uint32_t)0x00000020U)         /* Bit5*/
#define FLASH_WRP_WRPT_6                                   ((uint32_t)0x00000040U)         /* Bit6*/
#define FLASH_WRP_WRPT_7                                   ((uint32_t)0x00000080U)         /* Bit7*/
#define FLASH_WRP_WRPT_8                                   ((uint32_t)0x00010000U)         /* Bit8*/
#define FLASH_WRP_WRPT_9                                   ((uint32_t)0x00020000U)         /* Bit9*/
#define FLASH_WRP_WRPT_10                                  ((uint32_t)0x00040000U)         /* Bit10*/
#define FLASH_WRP_WRPT_11                                  ((uint32_t)0x00080000U)         /* Bit11*/
#define FLASH_WRP_WRPT_12                                  ((uint32_t)0x00100000U)         /* Bit12*/
#define FLASH_WRP_WRPT_13                                  ((uint32_t)0x00200000U)         /* Bit13*/
#define FLASH_WRP_WRPT_14                                  ((uint32_t)0x00400000U)         /* Bit14*/
#define FLASH_WRP_WRPT_15                                  ((uint32_t)0x00800000U)         /* Bit15*/

/** Bit definition for FLASH_VTOR register **/
#define FLASH_VTOR_EN                                     ((uint32_t)0x80000000U)         /* Bit[31] */
#define FLASH_VTOR_VALUE                                  ((uint32_t)0x7FFFFFFFU)         /* Bit[30:0] */

/*** Option Bytes register ***/

/**  Bit definition for FLASH_RDP register  **/
#define  FLASH_RDP_RDP1                      ((uint32_t)0x000000FFU)        /* Read protection option byte */
#define  FLASH_RDP_nRDP1                     ((uint32_t)0x0000FF00U)        /* Read protection complemented option byte */

/**  Bit definition for FLASH_USER0 register  **/
#define  FLASH_USER_USER0                    ((uint32_t)0x00FF00FFU)        /* User option byte */
#define  FLASH_USER_nUSER0                   ((uint32_t)0xFF00FF00U)        /* User complemented option byte */

/**  Bit definition for FLASH_USER1 register  **/
#define  FLASH_USER_USER1                    ((uint32_t)0x00FF00FFU)        /* User option byte */
#define  FLASH_USER_nUSER1                   ((uint32_t)0xFF00FF00U)        /* User complemented option byte */

/**  Bit definition for FLASH_USER2 register  **/
#define  FLASH_USER_USER2                    ((uint32_t)0x000000FFU)        /* User option byte */
#define  FLASH_USER_nUSER2                   ((uint32_t)0x0000FF00U)        /* User complemented option byte */

/**  Bit definition for FLASH_USER3 register  **/
#define  FLASH_USER_USER3                    ((uint32_t)0x00FF0000U)        /* User option byte */
#define  FLASH_USER_nUSER3                   ((uint32_t)0xFF000000U)        /* User complemented option byte */

/**  Bit definition for FLASH_USER4 register  **/
#define  FLASH_USER_USER4                    ((uint32_t)0x00FF0000U)        /* User option byte */
#define  FLASH_USER_nUSER4                   ((uint32_t)0xFF000000U)        /* User complemented option byte */

/**  Bit definition for FLASH_Data0 register  **/
#define  FLASH_Data0_Data0                   ((uint32_t)0x000000FFU)        /* User data storage option byte */
#define  FLASH_Data0_nData0                  ((uint32_t)0x0000FF00U)        /* User data storage complemented option byte */

/**  Bit definition for FLASH_Data1 register  **/
#define  FLASH_Data1_Data1                   ((uint32_t)0x00FF0000U)        /* User data storage option byte */
#define  FLASH_Data1_nData1                  ((uint32_t)0xFF000000U)        /* User data storage complemented option byte */

/**  Bit definition for OptionByte WRP0  **/
#define FLASH_WRP0_WRP0                      ((uint32_t)0x000000FFU)        /* Flash memory write protection option bytes */
#define FLASH_WRP0_NWRP0                     ((uint32_t)0x0000FF00U)        /* Flash memory write protection complemented option bytes */

/**  Bit definition for OptionByte WRP1  **/
#define FLASH_WRP1_WRP1                      ((uint32_t)0x00FF0000U)        /* Flash memory write protection option bytes */
#define FLASH_WRP1_NWRP1                     ((uint32_t)0xFF000000U)        /* Flash memory write protection complemented option bytes */

/**  Bit definition for FLASH_RDP2 register  **/
#define  FLASH_RDP_RDP2                      ((uint32_t)0x000000FFU)        /* Read protection level 2 option byte */
#define  FLASH_RDP_nRDP2                     ((uint32_t)0x0000FF00U)        /* Read protection level 2 complemented option byte */

/*** General Purpose and Alternate Function I/O ***/

/** Bit definition for GPIO_PMODE register **/
#define GPIO_PMODE0_Pos            (uint32_t)(0U)                                   
#define GPIO_PMODE0_Msk            (uint32_t)(0x3U << GPIO_PMODE0_Pos)         /* 0x00000003 */ 
#define GPIO_PMODE0                (uint32_t)         GPIO_PMODE0_Msk          /* 0x00000003 */
#define GPIO_PMODE0_0              (uint32_t)(0x0U << GPIO_PMODE0_Pos)         /* 0x00000000 */
#define GPIO_PMODE0_1              (uint32_t)(0x1U << GPIO_PMODE0_Pos)         /* 0x00000001 */
#define GPIO_PMODE0_2              (uint32_t)(0x2U << GPIO_PMODE0_Pos)         /* 0x00000002 */
#define GPIO_PMODE0_3              (uint32_t)(0x3U << GPIO_PMODE0_Pos)         /* 0x00000003 */

#define GPIO_PMODE1_Pos            (uint32_t)(2U)                                   
#define GPIO_PMODE1_Msk            (uint32_t)(0x3U << GPIO_PMODE1_Pos)         /* 0x0000000C */
#define GPIO_PMODE1                (uint32_t)         GPIO_PMODE1_Msk          /* 0x0000000C */
#define GPIO_PMODE1_0              (uint32_t)(0x0U << GPIO_PMODE1_Pos)         /* 0x00000000 */
#define GPIO_PMODE1_1              (uint32_t)(0x1U << GPIO_PMODE1_Pos)         /* 0x00000004 */
#define GPIO_PMODE1_2              (uint32_t)(0x2U << GPIO_PMODE1_Pos)         /* 0x00000008 */
#define GPIO_PMODE1_3              (uint32_t)(0x3U << GPIO_PMODE1_Pos)         /* 0x0000000C */

#define GPIO_PMODE2_Pos            (uint32_t)(4U)                                   
#define GPIO_PMODE2_Msk            (uint32_t)(0x3U << GPIO_PMODE2_Pos)         /* 0x00000030 */               
#define GPIO_PMODE2                (uint32_t)         GPIO_PMODE2_Msk          /* 0x00000030 */
#define GPIO_PMODE2_0              (uint32_t)(0x0U << GPIO_PMODE2_Pos)         /* 0x00000000 */
#define GPIO_PMODE2_1              (uint32_t)(0x1U << GPIO_PMODE2_Pos)         /* 0x00000010 */
#define GPIO_PMODE2_2              (uint32_t)(0x2U << GPIO_PMODE2_Pos)         /* 0x00000020 */
#define GPIO_PMODE2_3              (uint32_t)(0x3U << GPIO_PMODE2_Pos)         /* 0x00000030 */

#define GPIO_PMODE3_Pos            (uint32_t)(6U)                                   
#define GPIO_PMODE3_Msk            (uint32_t)(0x3U << GPIO_PMODE3_Pos)         /* 0x000000C0 */
#define GPIO_PMODE3                (uint32_t)         GPIO_PMODE3_Msk          /* 0x000000C0 */
#define GPIO_PMODE3_0              (uint32_t)(0x0U << GPIO_PMODE3_Pos)         /* 0x00000000 */
#define GPIO_PMODE3_1              (uint32_t)(0x1U << GPIO_PMODE3_Pos)         /* 0x00000040 */
#define GPIO_PMODE3_2              (uint32_t)(0x2U << GPIO_PMODE3_Pos)         /* 0x00000080 */
#define GPIO_PMODE3_3              (uint32_t)(0x3U << GPIO_PMODE3_Pos)         /* 0x000000C0 */

#define GPIO_PMODE4_Pos            (uint32_t)(8U)                                   
#define GPIO_PMODE4_Msk            (uint32_t)(0x3U << GPIO_PMODE4_Pos)         /* 0x00000300 */ 
#define GPIO_PMODE4                (uint32_t)         GPIO_PMODE4_Msk          /* 0x00000300 */
#define GPIO_PMODE4_0              (uint32_t)(0x0U << GPIO_PMODE4_Pos)         /* 0x00000000 */
#define GPIO_PMODE4_1              (uint32_t)(0x1U << GPIO_PMODE4_Pos)         /* 0x00000100 */
#define GPIO_PMODE4_2              (uint32_t)(0x2U << GPIO_PMODE4_Pos)         /* 0x00000100 */
#define GPIO_PMODE4_3              (uint32_t)(0x3U << GPIO_PMODE4_Pos)         /* 0x00000300 */

#define GPIO_PMODE5_Pos            (uint32_t)(10U)                                   
#define GPIO_PMODE5_Msk            (uint32_t)(0x3U << GPIO_PMODE5_Pos)         /* 0x00000C00 */
#define GPIO_PMODE5                (uint32_t)         GPIO_PMODE5_Msk          /* 0x00000C00 */
#define GPIO_PMODE5_0              (uint32_t)(0x0U << GPIO_PMODE5_Pos)         /* 0x00000000 */
#define GPIO_PMODE5_1              (uint32_t)(0x1U << GPIO_PMODE5_Pos)         /* 0x00000400 */
#define GPIO_PMODE5_2              (uint32_t)(0x2U << GPIO_PMODE5_Pos)         /* 0x00000800 */
#define GPIO_PMODE5_3              (uint32_t)(0x3U << GPIO_PMODE5_Pos)         /* 0x00000C00 */

#define GPIO_PMODE6_Pos            (uint32_t)(12U)                                   
#define GPIO_PMODE6_Msk            (uint32_t)(0x3U << GPIO_PMODE6_Pos)         /* 0x00003000 */      
#define GPIO_PMODE6                (uint32_t)         GPIO_PMODE6_Msk          /* 0x00003000 */
#define GPIO_PMODE6_0              (uint32_t)(0x0U << GPIO_PMODE6_Pos)         /* 0x00000000 */
#define GPIO_PMODE6_1              (uint32_t)(0x1U << GPIO_PMODE6_Pos)         /* 0x00001000 */
#define GPIO_PMODE6_2              (uint32_t)(0x2U << GPIO_PMODE6_Pos)         /* 0x00002000 */
#define GPIO_PMODE6_3              (uint32_t)(0x3U << GPIO_PMODE6_Pos)         /* 0x00003000 */

#define GPIO_PMODE7_Pos            (uint32_t)(14U)                                   
#define GPIO_PMODE7_Msk            (uint32_t)(0x3U << GPIO_PMODE7_Pos)         /* 0x0000C000 */
#define GPIO_PMODE7                (uint32_t)         GPIO_PMODE7_Msk          /* 0x0000C000 */
#define GPIO_PMODE7_0              (uint32_t)(0x0U << GPIO_PMODE7_Pos)         /* 0x00000000 */
#define GPIO_PMODE7_1              (uint32_t)(0x1U << GPIO_PMODE7_Pos)         /* 0x00004000 */
#define GPIO_PMODE7_2              (uint32_t)(0x2U << GPIO_PMODE7_Pos)         /* 0x00008000 */
#define GPIO_PMODE7_3              (uint32_t)(0x3U << GPIO_PMODE7_Pos)         /* 0x0000C000 */

#define GPIO_PMODE8_Pos            (uint32_t)(16U)                                   
#define GPIO_PMODE8_Msk            (uint32_t)(0x3U << GPIO_PMODE8_Pos)         /* 0x00030000 */
#define GPIO_PMODE8                (uint32_t)         GPIO_PMODE8_Msk          /* 0x00030000 */
#define GPIO_PMODE8_0              (uint32_t)(0x0U << GPIO_PMODE8_Pos)         /* 0x00000000 */
#define GPIO_PMODE8_1              (uint32_t)(0x1U << GPIO_PMODE8_Pos)         /* 0x00010000 */
#define GPIO_PMODE8_2              (uint32_t)(0x2U << GPIO_PMODE8_Pos)         /* 0x00020000 */
#define GPIO_PMODE8_3              (uint32_t)(0x3U << GPIO_PMODE8_Pos)         /* 0x00030000 */

#define GPIO_PMODE9_Pos            (uint32_t)(18U)                                   
#define GPIO_PMODE9_Msk            (uint32_t)(0x3U << GPIO_PMODE9_Pos)         /* 0x000C0000 */
#define GPIO_PMODE9                (uint32_t)         GPIO_PMODE9_Msk          /* 0x000C0000 */
#define GPIO_PMODE9_0              (uint32_t)(0x0U << GPIO_PMODE9_Pos)         /* 0x00000000 */
#define GPIO_PMODE9_1              (uint32_t)(0x1U << GPIO_PMODE9_Pos)         /* 0x00040000 */
#define GPIO_PMODE9_2              (uint32_t)(0x2U << GPIO_PMODE9_Pos)         /* 0x00080000 */
#define GPIO_PMODE9_3              (uint32_t)(0x3U << GPIO_PMODE9_Pos)         /* 0x000C0000 */

#define GPIO_PMODE10_Pos           (uint32_t)(20U)                                   
#define GPIO_PMODE10_Msk           (uint32_t)(0x3U << GPIO_PMODE10_Pos)         /* 0x00300000 */ 
#define GPIO_PMODE10               (uint32_t)         GPIO_PMODE10_Msk          /* 0x00300000 */
#define GPIO_PMODE10_0             (uint32_t)(0x0U << GPIO_PMODE10_Pos)         /* 0x00000000 */
#define GPIO_PMODE10_1             (uint32_t)(0x1U << GPIO_PMODE10_Pos)         /* 0x00100000 */
#define GPIO_PMODE10_2             (uint32_t)(0x2U << GPIO_PMODE10_Pos)         /* 0x00200000 */
#define GPIO_PMODE10_3             (uint32_t)(0x3U << GPIO_PMODE10_Pos)         /* 0x00300000 */

#define GPIO_PMODE11_Pos           (uint32_t)(22U)                                   
#define GPIO_PMODE11_Msk           (uint32_t)(0x3U << GPIO_PMODE11_Pos)         /* 0x00C00000 */ 
#define GPIO_PMODE11               (uint32_t)         GPIO_PMODE11_Msk          /* 0x00C00000 */
#define GPIO_PMODE11_0             (uint32_t)(0x0U << GPIO_PMODE11_Pos)         /* 0x00000000 */
#define GPIO_PMODE11_1             (uint32_t)(0x1U << GPIO_PMODE11_Pos)         /* 0x00400000 */
#define GPIO_PMODE11_2             (uint32_t)(0x2U << GPIO_PMODE11_Pos)         /* 0x00800000 */
#define GPIO_PMODE11_3             (uint32_t)(0x3U << GPIO_PMODE11_Pos)         /* 0x00C00000 */

#define GPIO_PMODE12_Pos           (uint32_t)(24U)                                   
#define GPIO_PMODE12_Msk           (uint32_t)(0x3U << GPIO_PMODE12_Pos)         /* 0x03000000 */
#define GPIO_PMODE12               (uint32_t)         GPIO_PMODE12_Msk          /* 0x03000000 */
#define GPIO_PMODE12_0             (uint32_t)(0x0U << GPIO_PMODE12_Pos)         /* 0x00000000 */
#define GPIO_PMODE12_1             (uint32_t)(0x1U << GPIO_PMODE12_Pos)         /* 0x01000000 */
#define GPIO_PMODE12_2             (uint32_t)(0x2U << GPIO_PMODE12_Pos)         /* 0x02000000 */
#define GPIO_PMODE12_3             (uint32_t)(0x3U << GPIO_PMODE12_Pos)         /* 0x03000000 */

#define GPIO_PMODE13_Pos           (uint32_t)(26U)                                   
#define GPIO_PMODE13_Msk           (uint32_t)(0x3U << GPIO_PMODE13_Pos)         /* 0x0C000000 */
#define GPIO_PMODE13               (uint32_t)         GPIO_PMODE13_Msk          /* 0x0C000000 */
#define GPIO_PMODE13_0             (uint32_t)(0x0U << GPIO_PMODE13_Pos)         /* 0x00000000 */
#define GPIO_PMODE13_1             (uint32_t)(0x1U << GPIO_PMODE13_Pos)         /* 0x04000000 */
#define GPIO_PMODE13_2             (uint32_t)(0x2U << GPIO_PMODE13_Pos)         /* 0x08000000 */
#define GPIO_PMODE13_3             (uint32_t)(0x3U << GPIO_PMODE13_Pos)         /* 0x0C000000 */

#define GPIO_PMODE14_Pos           (uint32_t)(28U)                                   
#define GPIO_PMODE14_Msk           (uint32_t)(0x3U << GPIO_PMODE14_Pos)         /* 0x30000000 */
#define GPIO_PMODE14               (uint32_t)         GPIO_PMODE14_Msk          /* 0x30000000 */
#define GPIO_PMODE14_0             (uint32_t)(0x0U << GPIO_PMODE14_Pos)         /* 0x00000000 */
#define GPIO_PMODE14_1             (uint32_t)(0x1U << GPIO_PMODE14_Pos)         /* 0x10000000 */
#define GPIO_PMODE14_2             (uint32_t)(0x2U << GPIO_PMODE14_Pos)         /* 0x20000000 */
#define GPIO_PMODE14_3             (uint32_t)(0x3U << GPIO_PMODE14_Pos)         /* 0x30000000 */

#define GPIO_PMODE15_Pos           (uint32_t)(30U)                                   
#define GPIO_PMODE15_Msk           (uint32_t)(0x3U << GPIO_PMODE15_Pos)         /* 0xC0000000 */
#define GPIO_PMODE15               (uint32_t)         GPIO_PMODE15_Msk          /* 0xC0000000 */
#define GPIO_PMODE15_0             (uint32_t)(0x0U << GPIO_PMODE15_Pos)         /* 0x00000000 */
#define GPIO_PMODE15_1             (uint32_t)(0x1U << GPIO_PMODE15_Pos)         /* 0x40000000 */
#define GPIO_PMODE15_2             (uint32_t)(0x2U << GPIO_PMODE15_Pos)         /* 0x80000000 */
#define GPIO_PMODE15_3             (uint32_t)(0x3U << GPIO_PMODE15_Pos)         /* 0xC0000000 */

/** Bit definition for GPIO_POTYPE register **/
#define GPIO_POTYPE_POT0           ((uint16_t)0x0001U) 
#define GPIO_POTYPE_POT1           ((uint16_t)0x0002U) 
#define GPIO_POTYPE_POT2           ((uint16_t)0x0004U) 
#define GPIO_POTYPE_POT3           ((uint16_t)0x0008U) 
#define GPIO_POTYPE_POT4           ((uint16_t)0x0010U) 
#define GPIO_POTYPE_POT5           ((uint16_t)0x0020U) 
#define GPIO_POTYPE_POT6           ((uint16_t)0x0040U) 
#define GPIO_POTYPE_POT7           ((uint16_t)0x0080U) 
#define GPIO_POTYPE_POT8           ((uint16_t)0x0100U) 
#define GPIO_POTYPE_POT9           ((uint16_t)0x0200U) 
#define GPIO_POTYPE_POT10          ((uint16_t)0x0400U) 
#define GPIO_POTYPE_POT11          ((uint16_t)0x0800U) 
#define GPIO_POTYPE_POT12          ((uint16_t)0x1000U) 
#define GPIO_POTYPE_POT13          ((uint16_t)0x2000U) 
#define GPIO_POTYPE_POT14          ((uint16_t)0x4000U) 
#define GPIO_POTYPE_POT15          ((uint16_t)0x8000U)                          

/** Bit definition for GPIO_PUPD register **/
#define GPIO_PUPD0_Pos             (uint32_t)(0U)                                   
#define GPIO_PUPD0_Msk             (uint32_t)(0x3U << GPIO_PUPD0_Pos)         /* 0x00000003 */
#define GPIO_PUPD0                 (uint32_t)         GPIO_PUPD0_Msk          /* 0x00000003 */     
#define GPIO_PUPD0_0               (uint32_t)(0x0U << GPIO_PUPD0_Pos)         /* 0x00000000 */
#define GPIO_PUPD0_1               (uint32_t)(0x1U << GPIO_PUPD0_Pos)         /* 0x00000001 */
#define GPIO_PUPD0_2               (uint32_t)(0x2U << GPIO_PUPD0_Pos)         /* 0x00000002 */

#define GPIO_PUPD1_Pos             (uint32_t)(2U)                                   
#define GPIO_PUPD1_Msk             (uint32_t)(0x3U << GPIO_PUPD1_Pos)         /* 0x0000000C */
#define GPIO_PUPD1                 (uint32_t)         GPIO_PUPD1_Msk          /* 0x0000000C */     
#define GPIO_PUPD1_0               (uint32_t)(0x0U << GPIO_PUPD1_Pos)         /* 0x00000000 */
#define GPIO_PUPD1_1               (uint32_t)(0x1U << GPIO_PUPD1_Pos)         /* 0x00000004 */
#define GPIO_PUPD1_2               (uint32_t)(0x2U << GPIO_PUPD1_Pos)         /* 0x00000008 */

#define GPIO_PUPD2_Pos             (uint32_t)(4U)                                   
#define GPIO_PUPD2_Msk             (uint32_t)(0x3U << GPIO_PUPD2_Pos)         /* 0x00000030 */
#define GPIO_PUPD2                 (uint32_t)         GPIO_PUPD2_Msk          /* 0x00000030 */       
#define GPIO_PUPD2_0               (uint32_t)(0x0U << GPIO_PUPD2_Pos)         /* 0x00000000 */
#define GPIO_PUPD2_1               (uint32_t)(0x1U << GPIO_PUPD2_Pos)         /* 0x00000010 */
#define GPIO_PUPD2_2               (uint32_t)(0x2U << GPIO_PUPD2_Pos)         /* 0x00000020 */

#define GPIO_PUPD3_Pos             (uint32_t)(6U)                                   
#define GPIO_PUPD3_Msk             (uint32_t)(0x3U << GPIO_PUPD3_Pos)         /* 0x000000C0 */
#define GPIO_PUPD3                 (uint32_t)         GPIO_PUPD3_Msk          /* 0x000000C0 */        
#define GPIO_PUPD3_0               (uint32_t)(0x0U << GPIO_PUPD3_Pos)         /* 0x00000000 */
#define GPIO_PUPD3_1               (uint32_t)(0x1U << GPIO_PUPD3_Pos)         /* 0x00000040 */
#define GPIO_PUPD3_2               (uint32_t)(0x2U << GPIO_PUPD3_Pos)         /* 0x00000080 */

#define GPIO_PUPD4_Pos             (uint32_t)(8U)                                   
#define GPIO_PUPD4_Msk             (uint32_t)(0x3U << GPIO_PUPD4_Pos)         /* 0x00000300 */
#define GPIO_PUPD4                 (uint32_t)         GPIO_PUPD4_Msk          /* 0x00000300 */         
#define GPIO_PUPD4_0               (uint32_t)(0x0U << GPIO_PUPD4_Pos)         /* 0x00000000 */
#define GPIO_PUPD4_1               (uint32_t)(0x1U << GPIO_PUPD4_Pos)         /* 0x00000100 */
#define GPIO_PUPD4_2               (uint32_t)(0x2U << GPIO_PUPD4_Pos)         /* 0x00000200 */

#define GPIO_PUPD5_Pos             (uint32_t)(10U)                                   
#define GPIO_PUPD5_Msk             (uint32_t)(0x3U << GPIO_PUPD5_Pos)         /* 0x00000C00 */
#define GPIO_PUPD5                 (uint32_t)         GPIO_PUPD5_Msk          /* 0x00000C00 */         
#define GPIO_PUPD5_0               (uint32_t)(0x0U << GPIO_PUPD5_Pos)         /* 0x00000000 */
#define GPIO_PUPD5_1               (uint32_t)(0x1U << GPIO_PUPD5_Pos)         /* 0x00000400 */
#define GPIO_PUPD5_2               (uint32_t)(0x2U << GPIO_PUPD5_Pos)         /* 0x00000800 */

#define GPIO_PUPD6_Pos             (uint32_t)(12U)                                   
#define GPIO_PUPD6_Msk             (uint32_t)(0x3U << GPIO_PUPD6_Pos)         /* 0x00003000 */
#define GPIO_PUPD6                 (uint32_t)         GPIO_PUPD6_Msk          /* 0x00003000 */         
#define GPIO_PUPD6_0               (uint32_t)(0x0U << GPIO_PUPD6_Pos)         /* 0x00000000 */
#define GPIO_PUPD6_1               (uint32_t)(0x1U << GPIO_PUPD6_Pos)         /* 0x00001000 */
#define GPIO_PUPD6_2               (uint32_t)(0x2U << GPIO_PUPD6_Pos)         /* 0x00002000 */

#define GPIO_PUPD7_Pos             (uint32_t)(14U)                                   
#define GPIO_PUPD7_Msk             (uint32_t)(0x3U << GPIO_PUPD7_Pos)         /* 0x0000C000 */
#define GPIO_PUPD7                 (uint32_t)         GPIO_PUPD7_Msk          /* 0x0000C000 */         
#define GPIO_PUPD7_0               (uint32_t)(0x0U << GPIO_PUPD7_Pos)         /* 0x00000000 */
#define GPIO_PUPD7_1               (uint32_t)(0x1U << GPIO_PUPD7_Pos)         /* 0x00004000 */
#define GPIO_PUPD7_2               (uint32_t)(0x2U << GPIO_PUPD7_Pos)         /* 0x00008000 */

#define GPIO_PUPD8_Pos             (uint32_t)(16U)                                   
#define GPIO_PUPD8_Msk             (uint32_t)(0x3U << GPIO_PUPD8_Pos)         /* 0x00030000 */
#define GPIO_PUPD8                 (uint32_t)         GPIO_PUPD8_Msk          /* 0x00030000 */         
#define GPIO_PUPD8_0               (uint32_t)(0x0U << GPIO_PUPD8_Pos)         /* 0x00000000 */
#define GPIO_PUPD8_1               (uint32_t)(0x1U << GPIO_PUPD8_Pos)         /* 0x00010000 */
#define GPIO_PUPD8_2               (uint32_t)(0x2U << GPIO_PUPD8_Pos)         /* 0x00020000 */

#define GPIO_PUPD9_Pos             (uint32_t)(18U)                                   
#define GPIO_PUPD9_Msk             (uint32_t)(0x3U << GPIO_PUPD9_Pos)         /* 0x000C0000 */
#define GPIO_PUPD9                 (uint32_t)         GPIO_PUPD9_Msk          /* 0x000C0000 */         
#define GPIO_PUPD9_0               (uint32_t)(0x0U << GPIO_PUPD9_Pos)         /* 0x00000000 */
#define GPIO_PUPD9_1               (uint32_t)(0x1U << GPIO_PUPD9_Pos)         /* 0x00040000 */
#define GPIO_PUPD9_2               (uint32_t)(0x2U << GPIO_PUPD9_Pos)         /* 0x00080000 */

#define GPIO_PUPD10_Pos            (uint32_t)(20U)                                   
#define GPIO_PUPD10_Msk            (uint32_t)(0x3U << GPIO_PUPD10_Pos)        /* 0x00300000 */
#define GPIO_PUPD10                (uint32_t)         GPIO_PUPD10_Msk         /* 0x00300000 */         
#define GPIO_PUPD10_0              (uint32_t)(0x0U << GPIO_PUPD10_Pos)        /* 0x00000000 */
#define GPIO_PUPD10_1              (uint32_t)(0x1U << GPIO_PUPD10_Pos)        /* 0x00100000 */
#define GPIO_PUPD10_2              (uint32_t)(0x2U << GPIO_PUPD10_Pos)        /* 0x00200000 */

#define GPIO_PUPD11_Pos            (uint32_t)(22U)                                   
#define GPIO_PUPD11_Msk            (uint32_t)(0x3U << GPIO_PUPD11_Pos)        /* 0x00C00000 */
#define GPIO_PUPD11                (uint32_t)         GPIO_PUPD11_Msk         /* 0x00C00000 */         
#define GPIO_PUPD11_0              (uint32_t)(0x0U << GPIO_PUPD11_Pos)        /* 0x00000000 */
#define GPIO_PUPD11_1              (uint32_t)(0x1U << GPIO_PUPD11_Pos)        /* 0x00400000 */
#define GPIO_PUPD11_2              (uint32_t)(0x2U << GPIO_PUPD11_Pos)        /* 0x00800000 */

#define GPIO_PUPD12_Pos            (uint32_t)(24U)                                   
#define GPIO_PUPD12_Msk            (uint32_t)(0x3U << GPIO_PUPD12_Pos)        /* 0x03000000 */
#define GPIO_PUPD12                (uint32_t)         GPIO_PUPD12_Msk         /* 0x03000000 */         
#define GPIO_PUPD12_0              (uint32_t)(0x0U << GPIO_PUPD12_Pos)        /* 0x00000000 */
#define GPIO_PUPD12_1              (uint32_t)(0x1U << GPIO_PUPD12_Pos)        /* 0x01000000 */
#define GPIO_PUPD12_2              (uint32_t)(0x2U << GPIO_PUPD12_Pos)        /* 0x02000000 */

#define GPIO_PUPD13_Pos            (uint32_t)(26U)                                   
#define GPIO_PUPD13_Msk            (uint32_t)(0x3U << GPIO_PUPD13_Pos)         /* 0x0C000000 */
#define GPIO_PUPD13                (uint32_t)         GPIO_PUPD13_Msk          /* 0x0C000000 */         
#define GPIO_PUPD13_0              (uint32_t)(0x0U << GPIO_PUPD13_Pos)         /* 0x00000000 */
#define GPIO_PUPD13_1              (uint32_t)(0x1U << GPIO_PUPD13_Pos)         /* 0x04000000 */
#define GPIO_PUPD13_2              (uint32_t)(0x2U << GPIO_PUPD13_Pos)         /* 0x08000000 */

#define GPIO_PUPD14_Pos            (uint32_t)(28U)                                   
#define GPIO_PUPD14_Msk            (uint32_t)(0x3U << GPIO_PUPD14_Pos)         /* 0x30000000 */
#define GPIO_PUPD14                (uint32_t)         GPIO_PUPD14_Msk          /* 0x30000000 */ 
#define GPIO_PUPD14_0              (uint32_t)(0x0U << GPIO_PUPD14_Pos)         /* 0x00000000 */
#define GPIO_PUPD14_1              (uint32_t)(0x1U << GPIO_PUPD14_Pos)         /* 0x10000000 */
#define GPIO_PUPD14_2              (uint32_t)(0x2U << GPIO_PUPD14_Pos)         /* 0x30000000 */

#define GPIO_PUPD15_Pos            (uint32_t)(30U)                                   
#define GPIO_PUPD15_Msk            (uint32_t)(0x3U << GPIO_PUPD15_Pos)         /* 0xC0000000 */
#define GPIO_PUPD15                (uint32_t)         GPIO_PUPD15_Msk          /* 0xC0000000 */         
#define GPIO_PUPD15_0              (uint32_t)(0x0U << GPIO_PUPD15_Pos)         /* 0x00000000 */
#define GPIO_PUPD15_1              (uint32_t)(0x1U << GPIO_PUPD15_Pos)         /* 0x40000000 */
#define GPIO_PUPD15_2              (uint32_t)(0x2U << GPIO_PUPD15_Pos)         /* 0x80000000 */

/** Bit definition for GPIO_PID register **/
#define GPIO_PID_PID0              ((uint16_t)0x0001U) /* Port input data, bit 0  */
#define GPIO_PID_PID1              ((uint16_t)0x0002U) /* Port input data, bit 1  */
#define GPIO_PID_PID2              ((uint16_t)0x0004U) /* Port input data, bit 2  */
#define GPIO_PID_PID3              ((uint16_t)0x0008U) /* Port input data, bit 3  */
#define GPIO_PID_PID4              ((uint16_t)0x0010U) /* Port input data, bit 4  */
#define GPIO_PID_PID5              ((uint16_t)0x0020U) /* Port input data, bit 5  */
#define GPIO_PID_PID6              ((uint16_t)0x0040U) /* Port input data, bit 6  */
#define GPIO_PID_PID7              ((uint16_t)0x0080U) /* Port input data, bit 7  */
#define GPIO_PID_PID8              ((uint16_t)0x0100U) /* Port input data, bit 8  */
#define GPIO_PID_PID9              ((uint16_t)0x0200U) /* Port input data, bit 9  */
#define GPIO_PID_PID10             ((uint16_t)0x0400U) /* Port input data, bit 10 */
#define GPIO_PID_PID11             ((uint16_t)0x0800U) /* Port input data, bit 11 */
#define GPIO_PID_PID12             ((uint16_t)0x1000U) /* Port input data, bit 12 */
#define GPIO_PID_PID13             ((uint16_t)0x2000U) /* Port input data, bit 13 */
#define GPIO_PID_PID14             ((uint16_t)0x4000U) /* Port input data, bit 14 */
#define GPIO_PID_PID15             ((uint16_t)0x8000U) /* Port input data, bit 15 */

/** Bit definition for GPIO_POD register **/
#define GPIO_POD_POD0              ((uint16_t)0x0001U) /* Port output data, bit 0  */
#define GPIO_POD_POD1              ((uint16_t)0x0002U) /* Port output data, bit 1  */
#define GPIO_POD_POD2              ((uint16_t)0x0004U) /* Port output data, bit 2  */
#define GPIO_POD_POD3              ((uint16_t)0x0008U) /* Port output data, bit 3  */
#define GPIO_POD_POD4              ((uint16_t)0x0010U) /* Port output data, bit 4  */
#define GPIO_POD_POD5              ((uint16_t)0x0020U) /* Port output data, bit 5  */
#define GPIO_POD_POD6              ((uint16_t)0x0040U) /* Port output data, bit 6  */
#define GPIO_POD_POD7              ((uint16_t)0x0080U) /* Port output data, bit 7  */
#define GPIO_POD_POD8              ((uint16_t)0x0100U) /* Port output data, bit 8  */
#define GPIO_POD_POD9              ((uint16_t)0x0200U) /* Port output data, bit 9  */
#define GPIO_POD_POD10             ((uint16_t)0x0400U) /* Port output data, bit 10 */
#define GPIO_POD_POD11             ((uint16_t)0x0800U) /* Port output data, bit 11 */
#define GPIO_POD_POD12             ((uint16_t)0x1000U) /* Port output data, bit 12 */
#define GPIO_POD_POD13             ((uint16_t)0x2000U) /* Port output data, bit 13 */
#define GPIO_POD_POD14             ((uint16_t)0x4000U) /* Port output data, bit 14 */
#define GPIO_POD_POD15             ((uint16_t)0x8000U) /* Port output data, bit 15 */

/** Bit definition for GPIO_PBSC register **/
#define GPIO_PBSC_PBS0             ((uint32_t)0x00000001U) /* Port x Set bit 0  */
#define GPIO_PBSC_PBS1             ((uint32_t)0x00000002U) /* Port x Set bit 1  */
#define GPIO_PBSC_PBS2             ((uint32_t)0x00000004U) /* Port x Set bit 2  */
#define GPIO_PBSC_PBS3             ((uint32_t)0x00000008U) /* Port x Set bit 3  */
#define GPIO_PBSC_PBS4             ((uint32_t)0x00000010U) /* Port x Set bit 4  */
#define GPIO_PBSC_PBS5             ((uint32_t)0x00000020U) /* Port x Set bit 5  */
#define GPIO_PBSC_PBS6             ((uint32_t)0x00000040U) /* Port x Set bit 6  */
#define GPIO_PBSC_PBS7             ((uint32_t)0x00000080U) /* Port x Set bit 7  */
#define GPIO_PBSC_PBS8             ((uint32_t)0x00000100U) /* Port x Set bit 8  */
#define GPIO_PBSC_PBS9             ((uint32_t)0x00000200U) /* Port x Set bit 9  */
#define GPIO_PBSC_PBS10            ((uint32_t)0x00000400U) /* Port x Set bit 10 */
#define GPIO_PBSC_PBS11            ((uint32_t)0x00000800U) /* Port x Set bit 11 */
#define GPIO_PBSC_PBS12            ((uint32_t)0x00001000U) /* Port x Set bit 12 */
#define GPIO_PBSC_PBS13            ((uint32_t)0x00002000U) /* Port x Set bit 13 */
#define GPIO_PBSC_PBS14            ((uint32_t)0x00004000U) /* Port x Set bit 14 */
#define GPIO_PBSC_PBS15            ((uint32_t)0x00008000U) /* Port x Set bit 15 */

#define GPIO_PBSC_PBC0             ((uint32_t)0x00010000U) /* Port x Reset bit 0  */
#define GPIO_PBSC_PBC1             ((uint32_t)0x00020000U) /* Port x Reset bit 1  */
#define GPIO_PBSC_PBC2             ((uint32_t)0x00040000U) /* Port x Reset bit 2  */
#define GPIO_PBSC_PBC3             ((uint32_t)0x00080000U) /* Port x Reset bit 3  */
#define GPIO_PBSC_PBC4             ((uint32_t)0x00100000U) /* Port x Reset bit 4  */
#define GPIO_PBSC_PBC5             ((uint32_t)0x00200000U) /* Port x Reset bit 5  */
#define GPIO_PBSC_PBC6             ((uint32_t)0x00400000U) /* Port x Reset bit 6  */
#define GPIO_PBSC_PBC7             ((uint32_t)0x00800000U) /* Port x Reset bit 7  */
#define GPIO_PBSC_PBC8             ((uint32_t)0x01000000U) /* Port x Reset bit 8  */
#define GPIO_PBSC_PBC9             ((uint32_t)0x02000000U) /* Port x Reset bit 9  */
#define GPIO_PBSC_PBC10            ((uint32_t)0x04000000U) /* Port x Reset bit 10 */
#define GPIO_PBSC_PBC11            ((uint32_t)0x08000000U) /* Port x Reset bit 11 */
#define GPIO_PBSC_PBC12            ((uint32_t)0x10000000U) /* Port x Reset bit 12 */
#define GPIO_PBSC_PBC13            ((uint32_t)0x20000000U) /* Port x Reset bit 13 */
#define GPIO_PBSC_PBC14            ((uint32_t)0x40000000U) /* Port x Reset bit 14 */
#define GPIO_PBSC_PBC15            ((uint32_t)0x80000000U) /* Port x Reset bit 15 */

/**  Bit definition for GPIO_PLOCK register **/
#define GPIO_PLOCK_PLOCK0          ((uint32_t)0x00000001U) /* Port x Lock bit 0  */
#define GPIO_PLOCK_PLOCK1          ((uint32_t)0x00000002U) /* Port x Lock bit 1  */
#define GPIO_PLOCK_PLOCK2          ((uint32_t)0x00000004U) /* Port x Lock bit 2  */
#define GPIO_PLOCK_PLOCK3          ((uint32_t)0x00000008U) /* Port x Lock bit 3  */
#define GPIO_PLOCK_PLOCK4          ((uint32_t)0x00000010U) /* Port x Lock bit 4  */
#define GPIO_PLOCK_PLOCK5          ((uint32_t)0x00000020U) /* Port x Lock bit 5  */
#define GPIO_PLOCK_PLOCK6          ((uint32_t)0x00000040U) /* Port x Lock bit 6  */
#define GPIO_PLOCK_PLOCK7          ((uint32_t)0x00000080U) /* Port x Lock bit 7  */
#define GPIO_PLOCK_PLOCK8          ((uint32_t)0x00000100U) /* Port x Lock bit 8  */
#define GPIO_PLOCK_PLOCK9          ((uint32_t)0x00000200U) /* Port x Lock bit 9  */
#define GPIO_PLOCK_PLOCK10         ((uint32_t)0x00000400U) /* Port x Lock bit 10 */
#define GPIO_PLOCK_PLOCK11         ((uint32_t)0x00000800U) /* Port x Lock bit 11 */
#define GPIO_PLOCK_PLOCK12         ((uint32_t)0x00001000U) /* Port x Lock bit 12 */
#define GPIO_PLOCK_PLOCK13         ((uint32_t)0x00002000U) /* Port x Lock bit 13 */
#define GPIO_PLOCK_PLOCK14         ((uint32_t)0x00004000U) /* Port x Lock bit 14 */
#define GPIO_PLOCK_PLOCK15         ((uint32_t)0x00008000U) /* Port x Lock bit 15 */
#define GPIO_PLOCK_PLOCKK          ((uint32_t)0x00010000U) /* Lock key */

/** Bit definition for GPIO_AFL register **/
#define GPIO_AFL_AFSEL0            ((uint32_t)0x0000000FU) /* Port x AFL bit (0..3) */
#define GPIO_AFL_AFSEL1            ((uint32_t)0x000000F0U) /* Port x AFL bit (4..7) */
#define GPIO_AFL_AFSEL2            ((uint32_t)0x00000F00U) /* Port x AFL bit (8..11) */
#define GPIO_AFL_AFSEL3            ((uint32_t)0x0000F000U) /* Port x AFL bit (12..15) */
#define GPIO_AFL_AFSEL4            ((uint32_t)0x000F0000U) /* Port x AFL bit (16..19) */
#define GPIO_AFL_AFSEL5            ((uint32_t)0x00F00000U) /* Port x AFL bit (20..23) */
#define GPIO_AFL_AFSEL6            ((uint32_t)0x0F000000U) /* Port x AFL bit (24..27) */
#define GPIO_AFL_AFSEL7            ((uint32_t)0xF0000000U) /* Port x AFL bit (27..31) */

/** Bit definition for GPIO_AFH register **/
#define GPIO_AFH_AFSEL8            ((uint32_t)0x0000000FU) /* Port x AFH bit (0..3) */
#define GPIO_AFH_AFSEL9            ((uint32_t)0x000000F0U) /* Port x AFH bit (4..7) */
#define GPIO_AFH_AFSEL10           ((uint32_t)0x00000F00U) /* Port x AFH bit (8..11) */
#define GPIO_AFH_AFSEL11           ((uint32_t)0x0000F000U) /* Port x AFH bit (12..15) */
#define GPIO_AFH_AFSEL12           ((uint32_t)0x000F0000U) /* Port x AFH bit (16..19) */
#define GPIO_AFH_AFSEL13           ((uint32_t)0x00F00000U) /* Port x AFH bit (20..23) */
#define GPIO_AFH_AFSEL14           ((uint32_t)0x0F000000U) /* Port x AFH bit (24..27) */
#define GPIO_AFH_AFSEL15           ((uint32_t)0xF0000000U) /* Port x AFH bit (28..31) */

/** Bit definition for GPIO_PBC register **/
#define GPIO_PBC_PBC0              ((uint16_t)0x0001U) /* Port x Reset bit 0  */
#define GPIO_PBC_PBC1              ((uint16_t)0x0002U) /* Port x Reset bit 1  */
#define GPIO_PBC_PBC2              ((uint16_t)0x0004U) /* Port x Reset bit 2  */
#define GPIO_PBC_PBC3              ((uint16_t)0x0008U) /* Port x Reset bit 3  */
#define GPIO_PBC_PBC4              ((uint16_t)0x0010U) /* Port x Reset bit 4  */
#define GPIO_PBC_PBC5              ((uint16_t)0x0020U) /* Port x Reset bit 5  */
#define GPIO_PBC_PBC6              ((uint16_t)0x0040U) /* Port x Reset bit 6  */
#define GPIO_PBC_PBC7              ((uint16_t)0x0080U) /* Port x Reset bit 7  */
#define GPIO_PBC_PBC8              ((uint16_t)0x0100U) /* Port x Reset bit 8  */
#define GPIO_PBC_PBC9              ((uint16_t)0x0200U) /* Port x Reset bit 9  */
#define GPIO_PBC_PBC10             ((uint16_t)0x0400U) /* Port x Reset bit 10 */
#define GPIO_PBC_PBC11             ((uint16_t)0x0800U) /* Port x Reset bit 11 */
#define GPIO_PBC_PBC12             ((uint16_t)0x1000U) /* Port x Reset bit 12 */
#define GPIO_PBC_PBC13             ((uint16_t)0x2000U) /* Port x Reset bit 13 */
#define GPIO_PBC_PBC14             ((uint16_t)0x4000U) /* Port x Reset bit 14 */
#define GPIO_PBC_PBC15             ((uint16_t)0x8000U) /* Port x Reset bit 15 */

/** Bit definition for GPIOB_DS register **/
#define GPIO_DS_DS3               ((uint16_t)0x0008U) /* GPIOB_DS bit 3  */
#define GPIO_DS_DS4               ((uint16_t)0x0010U) /* GPIOB_DS bit 4  */
#define GPIO_DS_DS5               ((uint16_t)0x0020U) /* GPIOB_DS bit 5  */
#define GPIO_DS_SR3               ((uint16_t)0x0100U) /* GPIOB_DS bit 8  */
#define GPIO_DS_SR4               ((uint16_t)0x0200U) /* GPIOB_DS bit 9  */
#define GPIO_DS_SR5               ((uint16_t)0x0400U) /* GPIOB_DS bit 10 */

/** Bit definition for AFIO register **/

/** Bit definition for AFIO_CFG register **/
#define AFIO_CFG_SPI2_NSS           ((uint32_t)0x00800000U) /* AFIO_CFG bit 23 */
#define AFIO_CFG_SPI1_NSS           ((uint32_t)0x00400000U) /* AFIO_CFG bit 22 */
#define AFIO_CFG_EXTI_ETRR          ((uint32_t)0x00003800U) /* AFIO_CFG bit (11..13) */
#define AFIO_CFG_EXTIFILTEN         ((uint32_t)0x00000008U) /* AFIO_CFG bit 3 */
#define AFIO_CFG_IOFILTCFG          ((uint32_t)0x00000007U) /* AFIO_CFG bit (2..0) */

/**  Bit definition for AFIO_EXTI_CFG1 register **/
#define AFIO_EXTI_CFG1_EXTI0        ((uint16_t)0x0007) /* EXTI 0 configuration */
#define AFIO_EXTI_CFG1_EXTI1        ((uint16_t)0x0070) /* EXTI 1 configuration */
#define AFIO_EXTI_CFG1_EXTI2        ((uint16_t)0x0700) /* EXTI 2 configuration */
#define AFIO_EXTI_CFG1_EXTI3        ((uint16_t)0x7000) /* EXTI 3 configuration */

/* EXTI0 configuration */
#define AFIO_EXTI_CFG1_EXTI0_PA0   ((uint32_t)0x00000000U) /* PA[0] pin */
#define AFIO_EXTI_CFG1_EXTI0_PA1   ((uint32_t)0x00000001U) /* PA[1] pin */
#define AFIO_EXTI_CFG1_EXTI0_PA2   ((uint32_t)0x00000002U) /* PA[2] pin */
#define AFIO_EXTI_CFG1_EXTI0_PA3   ((uint32_t)0x00000003U) /* PA[3] pin */

/* EXTI1 configuration */
#define AFIO_EXTI_CFG1_EXTI1_PA4   ((uint32_t)0x00000000U) /* PA[4] pin */
#define AFIO_EXTI_CFG1_EXTI1_PA5   ((uint32_t)0x00000010U) /* PA[5] pin */
#define AFIO_EXTI_CFG1_EXTI1_PA6   ((uint32_t)0x00000020U) /* PA[6] pin */
#define AFIO_EXTI_CFG1_EXTI1_PA7   ((uint32_t)0x00000030U) /* PA[7] pin */

/* EXTI2 configuration */
#define AFIO_EXTI_CFG1_EXTI2_PA8   ((uint32_t)0x00000000U) /* PA[8] pin */
#define AFIO_EXTI_CFG1_EXTI2_PA9   ((uint32_t)0x00000100U) /* PA[9] pin */
#define AFIO_EXTI_CFG1_EXTI2_PA10  ((uint32_t)0x00000200U) /* PA[10] pin */
#define AFIO_EXTI_CFG1_EXTI2_PA11  ((uint32_t)0x00000300U) /* PA[11] pin */

/* EXTI3 configuration */
#define AFIO_EXTI_CFG1_EXTI3_PA12   ((uint32_t)0x00000000U) /* PA[12] pin */
#define AFIO_EXTI_CFG1_EXTI3_PA13   ((uint32_t)0x00001000U) /* PA[13] pin */
#define AFIO_EXTI_CFG1_EXTI3_PA14   ((uint32_t)0x00002000U) /* PA[14] pin */
#define AFIO_EXTI_CFG1_EXTI3_PA15   ((uint32_t)0x00003000U) /* PA[15] pin */

/**  Bit definition for AFIO_EXTI_CFG2 register **/
#define AFIO_EXTI_CFG2_EXTI4        ((uint16_t)0x0007U) /* EXTI 4 configuration */
#define AFIO_EXTI_CFG2_EXTI5        ((uint16_t)0x0070U) /* EXTI 5 configuration */
#define AFIO_EXTI_CFG2_EXTI6        ((uint16_t)0x0700U) /* EXTI 6 configuration */

/* EXTI4 configuration */
#define AFIO_EXTI_CFG2_EXTI4_PB0   ((uint32_t)0x00000000U) /* PB[0] pin */
#define AFIO_EXTI_CFG2_EXTI4_PB1   ((uint32_t)0x00000001U) /* PB[1] pin */
#define AFIO_EXTI_CFG2_EXTI4_PB2   ((uint32_t)0x00000002U) /* PB[2] pin */
#define AFIO_EXTI_CFG2_EXTI4_PB3   ((uint32_t)0x00000003U) /* PB[3] pin */

/* EXTI5 configuration */
#define AFIO_EXTI_CFG2_EXTI5_PB4   ((uint32_t)0x00000000U) /* PB[4] pin */
#define AFIO_EXTI_CFG2_EXTI5_PB5   ((uint32_t)0x00000010U) /* PB[5] pin */
#define AFIO_EXTI_CFG2_EXTI5_PB6   ((uint32_t)0x00000020U) /* PB[6] pin */
#define AFIO_EXTI_CFG2_EXTI5_PB7   ((uint32_t)0x00000030U) /* PB[7] pin */
#define AFIO_EXTI_CFG2_EXTI5_PB8   ((uint32_t)0x00000040U) /* PB[8] pin */

/* EXTI6 configuration */
#define AFIO_EXTI_CFG2_EXTI6_PF0   ((uint32_t)0x00000000U) /* PF[0] pin */
#define AFIO_EXTI_CFG2_EXTI6_PF1   ((uint32_t)0x00000100U) /* PF[1] pin */
#define AFIO_EXTI_CFG2_EXTI6_PF2   ((uint32_t)0x00000200U) /* PF[2] pin */
#define AFIO_EXTI_CFG2_EXTI6_PF3   ((uint32_t)0x00000300U) /* PF[3] pin */

/** Bit definition for AFIO_DIGEFT_CFG1 register **/
#define AFIO_DIGEFT_CFG1_PA0DIGEFTEN  ((uint32_t)0x00000001U) /* PA[0]  DIGEFT IE */
#define AFIO_DIGEFT_CFG1_PA1DIGEFTEN  ((uint32_t)0x00000002U) /* PA[1]  DIGEFT IE */
#define AFIO_DIGEFT_CFG1_PA2DIGEFTEN  ((uint32_t)0x00000004U) /* PA[2]  DIGEFT IE */
#define AFIO_DIGEFT_CFG1_PA3DIGEFTEN  ((uint32_t)0x00000008U) /* PA[3]  DIGEFT IE */
#define AFIO_DIGEFT_CFG1_PA4DIGEFTEN  ((uint32_t)0x00000010U) /* PA[4]  DIGEFT IE */
#define AFIO_DIGEFT_CFG1_PA5DIGEFTEN  ((uint32_t)0x00000020U) /* PA[5]  DIGEFT IE */
#define AFIO_DIGEFT_CFG1_PA6DIGEFTEN  ((uint32_t)0x00000040U) /* PA[6]  DIGEFT IE */
#define AFIO_DIGEFT_CFG1_PA7DIGEFTEN  ((uint32_t)0x00000080U) /* PA[7]  DIGEFT IE */
#define AFIO_DIGEFT_CFG1_PA8DIGEFTEN  ((uint32_t)0x00000100U) /* PA[8]  DIGEFT IE */
#define AFIO_DIGEFT_CFG1_PA9DIGEFTEN  ((uint32_t)0x00000200U) /* PA[9]  DIGEFT IE */
#define AFIO_DIGEFT_CFG1_PA10DIGEFTEN ((uint32_t)0x00000400U) /* PA[10] DIGEFT IE */
#define AFIO_DIGEFT_CFG1_PA11DIGEFTEN ((uint32_t)0x00000800U) /* PA[11] DIGEFT IE */
#define AFIO_DIGEFT_CFG1_PA12DIGEFTEN ((uint32_t)0x00001000U) /* PA[12] DIGEFT IE */
#define AFIO_DIGEFT_CFG1_PA13DIGEFTEN ((uint32_t)0x00002000U) /* PA[13] DIGEFT IE */
#define AFIO_DIGEFT_CFG1_PA14DIGEFTEN ((uint32_t)0x00004000U) /* PA[14] DIGEFT IE */
#define AFIO_DIGEFT_CFG1_PA15DIGEFTEN ((uint32_t)0x00008000U) /* PA[15] DIGEFT IE */

/** Bit definition for AFIO_DIGEFT_CFG2 register **/
#define AFIO_DIGEFT_CFG2_PB0DIGEFTEN  ((uint32_t)0x00000001U) /* PB[0]  DIGEFT IE */
#define AFIO_DIGEFT_CFG2_PB1DIGEFTEN  ((uint32_t)0x00000002U) /* PB[1]  DIGEFT IE */
#define AFIO_DIGEFT_CFG2_PB2DIGEFTEN  ((uint32_t)0x00000004U) /* PB[2]  DIGEFT IE */
#define AFIO_DIGEFT_CFG2_PB3DIGEFTEN  ((uint32_t)0x00000008U) /* PB[3]  DIGEFT IE */
#define AFIO_DIGEFT_CFG2_PB4DIGEFTEN  ((uint32_t)0x00000010U) /* PB[4]  DIGEFT IE */
#define AFIO_DIGEFT_CFG2_PB5DIGEFTEN  ((uint32_t)0x00000020U) /* PB[5]  DIGEFT IE */
#define AFIO_DIGEFT_CFG2_PB6DIGEFTEN  ((uint32_t)0x00000040U) /* PB[6]  DIGEFT IE */
#define AFIO_DIGEFT_CFG2_PB7DIGEFTEN  ((uint32_t)0x00000080U) /* PB[7]  DIGEFT IE */
#define AFIO_DIGEFT_CFG2_PB8DIGEFTEN  ((uint32_t)0x00000100U) /* PB[8]  DIGEFT IE */

/** Bit definition for AFIO_DIGEFT_CFG3 register **/
#define AFIO_DIGEFT_CFG2_PF0DIGEFTEN  ((uint32_t)0x00000001U) /* PF[0]  DIGEFT IE */
#define AFIO_DIGEFT_CFG2_PF1DIGEFTEN  ((uint32_t)0x00000002U) /* PF[1]  DIGEFT IE */
#define AFIO_DIGEFT_CFG2_PF2DIGEFTEN  ((uint32_t)0x00000004U) /* PF[2]  DIGEFT IE */
#define AFIO_DIGEFT_CFG2_PF3DIGEFTEN  ((uint32_t)0x00000008U) /* PF[3]  DIGEFT IE */

/*** External Interrupt/Event Controller ***/

/** Bit definition for EXTI_EMASK register **/
#define EXTI_EMASK_EMASK0        ((uint32_t)0x00000001U) /* Event Mask on line 0 */
#define EXTI_EMASK_EMASK1        ((uint32_t)0x00000002U) /* Event Mask on line 1 */
#define EXTI_EMASK_EMASK2        ((uint32_t)0x00000004U) /* Event Mask on line 2 */
#define EXTI_EMASK_EMASK3        ((uint32_t)0x00000008U) /* Event Mask on line 3 */
#define EXTI_EMASK_EMASK4        ((uint32_t)0x00000010U) /* Event Mask on line 4 */
#define EXTI_EMASK_EMASK5        ((uint32_t)0x00000020U) /* Event Mask on line 5 */
#define EXTI_EMASK_EMASK6        ((uint32_t)0x00000040U) /* Event Mask on line 6 */
#define EXTI_EMASK_EMASK7        ((uint32_t)0x00000080U) /* Event Mask on line 7 */
#define EXTI_EMASK_EMASK8        ((uint32_t)0x00000100U) /* Event Mask on line 8 */
#define EXTI_EMASK_EMASK9        ((uint32_t)0x00000200U) /* Event Mask on line 9 */
#define EXTI_EMASK_EMASK10       ((uint32_t)0x00000400U) /* Event Mask on line 10 */

/** Bit definition for EXTI_IMASK register **/
#define EXTI_IMASK_IMASK0        ((uint32_t)0x00000001U) /* Interrupt Mask on line 0 */
#define EXTI_IMASK_IMASK1        ((uint32_t)0x00000002U) /* Interrupt Mask on line 1 */
#define EXTI_IMASK_IMASK2        ((uint32_t)0x00000004U) /* Interrupt Mask on line 2 */
#define EXTI_IMASK_IMASK3        ((uint32_t)0x00000008U) /* Interrupt Mask on line 3 */
#define EXTI_IMASK_IMASK4        ((uint32_t)0x00000010U) /* Interrupt Mask on line 4 */
#define EXTI_IMASK_IMASK5        ((uint32_t)0x00000020U) /* Interrupt Mask on line 5 */
#define EXTI_IMASK_IMASK6        ((uint32_t)0x00000040U) /* Interrupt Mask on line 6 */
#define EXTI_IMASK_IMASK7        ((uint32_t)0x00000080U) /* Interrupt Mask on line 7 */
#define EXTI_IMASK_IMASK8        ((uint32_t)0x00000100U) /* Interrupt Mask on line 8 */
#define EXTI_IMASK_IMASK9        ((uint32_t)0x00000200U) /* Interrupt Mask on line 9 */
#define EXTI_IMASK_IMASK10       ((uint32_t)0x00000400U) /* Interrupt Mask on line 10 */

/** Bit definition for EXTI_FT_CFG register **/
#define EXTI_FT_CFG_FT_CFG0        ((uint32_t)0x00000001U) /* Falling trigger event configuration bit of line 0 */
#define EXTI_FT_CFG_FT_CFG1        ((uint32_t)0x00000002U) /* Falling trigger event configuration bit of line 1 */
#define EXTI_FT_CFG_FT_CFG2        ((uint32_t)0x00000004U) /* Falling trigger event configuration bit of line 2 */
#define EXTI_FT_CFG_FT_CFG3        ((uint32_t)0x00000008U) /* Falling trigger event configuration bit of line 3 */
#define EXTI_FT_CFG_FT_CFG4        ((uint32_t)0x00000010U) /* Falling trigger event configuration bit of line 4 */
#define EXTI_FT_CFG_FT_CFG5        ((uint32_t)0x00000020U) /* Falling trigger event configuration bit of line 5 */
#define EXTI_FT_CFG_FT_CFG6        ((uint32_t)0x00000040U) /* Falling trigger event configuration bit of line 6 */
#define EXTI_FT_CFG_FT_CFG7        ((uint32_t)0x00000080U) /* Falling trigger event configuration bit of line 7 */
#define EXTI_FT_CFG_FT_CFG8        ((uint32_t)0x00000100U) /* Falling trigger event configuration bit of line 8 */
#define EXTI_FT_CFG_FT_CFG9        ((uint32_t)0x00000200U) /* Falling trigger event configuration bit of line 9 */
#define EXTI_FT_CFG_FT_CFG10       ((uint32_t)0x00000400U) /* Falling trigger event configuration bit of line 10 */

/** Bit definition for EXTI_RT_CFG register **/
#define EXTI_RT_CFG_RT_CFG0        ((uint32_t)0x00000001U) /* Rising trigger event configuration bit of line 0 */
#define EXTI_RT_CFG_RT_CFG1        ((uint32_t)0x00000002U) /* Rising trigger event configuration bit of line 1 */
#define EXTI_RT_CFG_RT_CFG2        ((uint32_t)0x00000004U) /* Rising trigger event configuration bit of line 2 */
#define EXTI_RT_CFG_RT_CFG3        ((uint32_t)0x00000008U) /* Rising trigger event configuration bit of line 3 */
#define EXTI_RT_CFG_RT_CFG4        ((uint32_t)0x00000010U) /* Rising trigger event configuration bit of line 4 */
#define EXTI_RT_CFG_RT_CFG5        ((uint32_t)0x00000020U) /* Rising trigger event configuration bit of line 5 */
#define EXTI_RT_CFG_RT_CFG6        ((uint32_t)0x00000040U) /* Rising trigger event configuration bit of line 6 */
#define EXTI_RT_CFG_RT_CFG7        ((uint32_t)0x00000080U) /* Rising trigger event configuration bit of line 7 */
#define EXTI_RT_CFG_RT_CFG8        ((uint32_t)0x00000100U) /* Rising trigger event configuration bit of line 8 */
#define EXTI_RT_CFG_RT_CFG9        ((uint32_t)0x00000200U) /* Rising trigger event configuration bit of line 9 */
#define EXTI_RT_CFG_RT_CFG10       ((uint32_t)0x00000400U) /* Rising trigger event configuration bit of line 10 */

/** Bit definition for EXTI_PEND register **/
#define EXTI_PEND_PEND0        ((uint32_t)0x00000001U) /* Pending bit for line 0 */
#define EXTI_PEND_PEND1        ((uint32_t)0x00000002U) /* Pending bit for line 1 */
#define EXTI_PEND_PEND2        ((uint32_t)0x00000004U) /* Pending bit for line 2 */
#define EXTI_PEND_PEND3        ((uint32_t)0x00000008U) /* Pending bit for line 3 */
#define EXTI_PEND_PEND4        ((uint32_t)0x00000010U) /* Pending bit for line 4 */
#define EXTI_PEND_PEND5        ((uint32_t)0x00000020U) /* Pending bit for line 5 */
#define EXTI_PEND_PEND6        ((uint32_t)0x00000040U) /* Pending bit for line 6 */
#define EXTI_PEND_PEND7        ((uint32_t)0x00000080U) /* Pending bit for line 7 */
#define EXTI_PEND_PEND8        ((uint32_t)0x00000100U) /* Pending bit for line 8 */
#define EXTI_PEND_PEND9        ((uint32_t)0x00000200U) /* Pending bit for line 9 */
#define EXTI_PEND_PEND10       ((uint32_t)0x00000400U) /* Pending bit for line 10 */

/** Bit definition for EXTI_SWIE register **/
#define EXTI_SWIE_SWIE0        ((uint32_t)0x00000001U) /* Software Interrupt on line 0 */
#define EXTI_SWIE_SWIE1        ((uint32_t)0x00000002U) /* Software Interrupt on line 1 */
#define EXTI_SWIE_SWIE2        ((uint32_t)0x00000004U) /* Software Interrupt on line 2 */
#define EXTI_SWIE_SWIE3        ((uint32_t)0x00000008U) /* Software Interrupt on line 3 */
#define EXTI_SWIE_SWIE4        ((uint32_t)0x00000010U) /* Software Interrupt on line 4 */
#define EXTI_SWIE_SWIE5        ((uint32_t)0x00000020U) /* Software Interrupt on line 5 */
#define EXTI_SWIE_SWIE6        ((uint32_t)0x00000040U) /* Software Interrupt on line 6 */
#define EXTI_SWIE_SWIE7        ((uint32_t)0x00000080U) /* Software Interrupt on line 7 */
#define EXTI_SWIE_SWIE8        ((uint32_t)0x00000100U) /* Software Interrupt on line 8 */
#define EXTI_SWIE_SWIE9        ((uint32_t)0x00000200U) /* Software Interrupt on line 9 */
#define EXTI_SWIE_SWIE10       ((uint32_t)0x00000400U) /* Software Interrupt on line 10 */

/** Bit Offset register **/
#define REG_BIT1_OFFSET    ((uint32_t)0x00000001U)
#define REG_BIT2_OFFSET    ((uint32_t)0x00000002U)
#define REG_BIT3_OFFSET    ((uint32_t)0x00000003U)
#define REG_BIT4_OFFSET    ((uint32_t)0x00000004U)
#define REG_BIT5_OFFSET    ((uint32_t)0x00000005U)
#define REG_BIT6_OFFSET    ((uint32_t)0x00000006U)
#define REG_BIT7_OFFSET    ((uint32_t)0x00000007U)
#define REG_BIT8_OFFSET    ((uint32_t)0x00000008U)
#define REG_BIT9_OFFSET    ((uint32_t)0x00000009U)
#define REG_BIT10_OFFSET   ((uint32_t)0x0000000AU)
#define REG_BIT11_OFFSET   ((uint32_t)0x0000000BU)
#define REG_BIT12_OFFSET   ((uint32_t)0x0000000CU)
#define REG_BIT13_OFFSET   ((uint32_t)0x0000000DU)
#define REG_BIT14_OFFSET   ((uint32_t)0x0000000EU)
#define REG_BIT15_OFFSET   ((uint32_t)0x0000000FU)
#define REG_BIT16_OFFSET   ((uint32_t)0x00000010U)
#define REG_BIT17_OFFSET   ((uint32_t)0x00000011U)
#define REG_BIT18_OFFSET   ((uint32_t)0x00000012U)
#define REG_BIT19_OFFSET   ((uint32_t)0x00000013U)
#define REG_BIT20_OFFSET   ((uint32_t)0x00000014U)
#define REG_BIT21_OFFSET   ((uint32_t)0x00000015U)
#define REG_BIT22_OFFSET   ((uint32_t)0x00000016U)
#define REG_BIT23_OFFSET   ((uint32_t)0x00000017U)
#define REG_BIT24_OFFSET   ((uint32_t)0x00000018U)
#define REG_BIT25_OFFSET   ((uint32_t)0x00000019U)
#define REG_BIT26_OFFSET   ((uint32_t)0x0000001AU)
#define REG_BIT27_OFFSET   ((uint32_t)0x0000001BU)
#define REG_BIT28_OFFSET   ((uint32_t)0x0000001CU)
#define REG_BIT29_OFFSET   ((uint32_t)0x0000001DU)
#define REG_BIT30_OFFSET   ((uint32_t)0x0000001EU)
#define REG_BIT31_OFFSET   ((uint32_t)0x0000001FU)
#define REG_BIT32_OFFSET   ((uint32_t)0x00000020U)

/***********************  Common macro fuction define       *******************/

#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

#ifdef __cplusplus
}
#endif

#endif /* __N32G033_H__ */
