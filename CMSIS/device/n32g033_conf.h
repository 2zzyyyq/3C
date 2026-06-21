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
 * @file n32g033_conf.h
 * @author Nsing
 * @version v1.0.0
 *
 * @copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
 */

/**
*\*\file n32g033_conf.h
*\*\author Nsing
*\*\version v1.0.0
*\*\copyright Copyright (c) 2025, Nsing Technologies Inc. All rights reserved.
**/ 

#ifndef __N32G033_CONF_H__
#define __N32G033_CONF_H__

/* Uncomment/Comment the line below to enable/disable peripheral header file inclusion */

#include "n32g033_adc.h"
#include "n32g033_comp.h"
#include "n32g033_dbg.h"
#include "n32g033_dma.h"
#include "n32g033_exti.h"
#include "n32g033_flash.h"
#include "n32g033_gpio.h"
#include "n32g033_hdiv.h"
#include "n32g033_i2c.h"
#include "n32g033_iwdg.h"
#include "n32g033_opamp.h"
#include "n32g033_pwr.h"
#include "n32g033_rcc.h"
#include "n32g033_spi.h"
#include "n32g033_sqrt.h"
#include "n32g033_tim.h"
#include "n32g033_uart.h"
#include <stdint.h> 
#include "misc.h" /* High level functions for NVIC and SysTick (add-on to CMSIS functions) */

/* Uncomment the line below to expanse the "assert_param" macro in the
   Standard Peripheral Library drivers code */
/* #define USE_FULL_ASSERT    1  */

#ifdef USE_FULL_ASSERT

/**
 * @brief  The assert_param macro is used for function's parameters check.
 * @param expr If expr is false, it calls assert_failed function which reports
 *         the name of the source file and the source line number of the call
 *         that failed. If expr is true, it returns no value.
 */
#define assert_param(expr) ((expr) ? (void)0 : assert_failed((const uint8_t*)#expr, (const uint8_t*)__FILE__, __LINE__))

void assert_failed(const uint8_t* expr, const uint8_t* file, uint32_t line);
#else
#define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */

#endif /* __N32G033_CONF_H__ */
