; *********************************************************************************************************
;     Copyright (c) 2025, Nsing Technologies Inc.
; 
;     All rights reserved.
;
;     This software is the exclusive property of Nsing Technologies Inc. (Hereinafter 
; referred to as Nsing). This software, and the product of Nsing described herein 
; (Hereinafter referred to as the Product) are owned by Nsing under the laws and treaties
; of the People's Republic of China and other applicable jurisdictions worldwide.
;
;     Nsing does not grant any license under its patents, copyrights, trademarks, or other 
; intellectual property rights. Names and brands of third party may be mentioned or referred 
; thereto (if any) for identification purposes only.
;
;     Nsing reserves the right to make changes, corrections, enhancements, modifications, and 
; improvements to this software at any time without notice. Please contact Nsing and obtain 
; the latest version of this software before placing orders.

;     Although Nsing has attempted to provide accurate and reliable information, Nsing assumes 
; no responsibility for the accuracy and reliability of this software.
; 
;     It is the responsibility of the user of this software to properly design, program, and test 
; the functionality and safety of any application made of this information and any resulting product. 
; In no event shall Nsing be liable for any direct, indirect, incidental, special,exemplary, or 
; consequential damages arising in any way out of the use of this software or the Product.
;
;     Nsing Products are neither intended nor warranted for usage in systems or equipment, any
; malfunction or failure of which may cause loss of human life, bodily injury or severe property 
; damage. Such applications are deemed, "Insecure Usage".
;
;     All Insecure Usage shall be made at user's risk. User shall indemnify Nsing and hold Nsing 
; harmless from and against all claims, costs, damages, and other liabilities, arising from or related 
; to any customer's Insecure Usage.

;     Any express or implied warranty with regard to this software or the Product, including,but not 
; limited to, the warranties of merchantability, fitness for a particular purpose and non-infringement
; are disclaimed to the fullest extent permitted by law.

;     Unless otherwise explicitly permitted by Nsing, anyone may not duplicate, modify, transcribe
; or otherwise distribute this software for any purposes, in whole or in part.
;
;     Nsing products and technologies shall not be used for or incorporated into any products or systems
; whose manufacture, use, or sale is prohibited under any applicable domestic or foreign laws or regulations. 
; User shall comply with any applicable export control laws and regulations promulgated and administered by 
; the governments of any countries asserting jurisdiction over the parties or transactions.
; ************************************************************************************************************

; Amount of memory (in bytes) allocated for Stack
; Tailor this value to your application needs
; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>
  
    MODULE  ?cstartup
        
        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        EXTERN  SystemInit        
        PUBLIC  __vector_table

        DATA
       
__vector_table
        DCD     sfe(CSTACK)
        DCD     Reset_Handler             ; Reset Handler
        DCD     NMI_Handler               ; NMI Handler
        DCD     HardFault_Handler         ; Hard Fault Handler
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     SVC_Handler               ; SVCall Handler
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     PendSV_Handler            ; PendSV Handler
        DCD     SysTick_Handler           ; SysTick Handler

        ; External Interrupts
        DCD     PVD_IRQHandler             ; PVD through EXTI Line 7 detect
        DCD     FLASH_IRQHandler           ; Flash				
        DCD     EXTI0_6_IRQHandler         ; EXTI Line 0.6
        DCD     COMP_IRQHandler            ; COMP
        DCD     UART1_IRQHandler           ; UART1
        DCD     UART2_IRQHandler           ; UART2
        DCD     TIM1_BRK_UP_TRG_COM_IRQHandler ; TIM1 Break/Update/Trigger and Commutation
        DCD     TIM1_CC_IRQHandler         ; TIM1 Capture Compare
        DCD     ADC_IRQHandler             ; ADC
        DCD     SPI1_IRQHandler            ; SPI1
        DCD     IWDG_IRQHandler            ; IWDG
        DCD     TIM4_IRQHandler            ; TIM4
        DCD     TIM3_IRQHandler            ; TIM3
        DCD     TIM6_IRQHandler            ; TIM6								
        DCD     UART3_IRQHandler           ; UART3									
        DCD     SPI2_IRQHandler            ; SPI2									
        DCD     I2C1_EV_IRQHandler         ; I2C1	event 								
        DCD     I2C1_ER_IRQHandler         ; I2C1	error									
        DCD     I2C2_EV_IRQHandler         ; I2C2	event								
        DCD     I2C2_ER_IRQHandler         ; I2C2	error									
        DCD     DMA_IRQHandler ; DMA Channel 1,2,3
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB

        PUBWEAK Reset_Handler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler
        LDR     R0, =SystemInit
        BLX     R0
        LDR     R0, =__iar_program_start
        BX      R0
               
        PUBWEAK NMI_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
NMI_Handler
        B NMI_Handler

        PUBWEAK HardFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
HardFault_Handler
        B HardFault_Handler

        PUBWEAK SVC_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SVC_Handler
        B SVC_Handler

        PUBWEAK PendSV_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
PendSV_Handler
        B PendSV_Handler

        PUBWEAK SysTick_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SysTick_Handler
        B SysTick_Handler

        PUBWEAK PVD_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
PVD_IRQHandler
        B PVD_IRQHandler

        PUBWEAK FLASH_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
FLASH_IRQHandler
        B FLASH_IRQHandler

        PUBWEAK EXTI0_6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI0_6_IRQHandler
        B EXTI0_6_IRQHandler

        PUBWEAK COMP_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
COMP_IRQHandler
        B COMP_IRQHandler

        PUBWEAK UART1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART1_IRQHandler
        B UART1_IRQHandler

        PUBWEAK UART2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART2_IRQHandler
        B UART2_IRQHandler

        PUBWEAK TIM1_BRK_UP_TRG_COM_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM1_BRK_UP_TRG_COM_IRQHandler
        B TIM1_BRK_UP_TRG_COM_IRQHandler

        PUBWEAK TIM1_CC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM1_CC_IRQHandler
        B TIM1_CC_IRQHandler

        PUBWEAK ADC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADC_IRQHandler
        B ADC_IRQHandler

        PUBWEAK SPI1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI1_IRQHandler
        B SPI1_IRQHandler

        PUBWEAK IWDG_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
IWDG_IRQHandler
        B IWDG_IRQHandler

        PUBWEAK TIM4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM4_IRQHandler
        B TIM4_IRQHandler

        PUBWEAK TIM3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM3_IRQHandler
        B TIM3_IRQHandler

        PUBWEAK TIM6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM6_IRQHandler
        B TIM6_IRQHandler

        PUBWEAK UART3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART3_IRQHandler
        B UART3_IRQHandler

        PUBWEAK SPI2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI2_IRQHandler
        B SPI2_IRQHandler

        PUBWEAK I2C1_EV_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C1_EV_IRQHandler
        B I2C1_EV_IRQHandler

        PUBWEAK I2C1_ER_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C1_ER_IRQHandler
        B I2C1_ER_IRQHandler

        PUBWEAK I2C2_EV_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C2_EV_IRQHandler
        B I2C2_EV_IRQHandler

        PUBWEAK I2C2_ER_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C2_ER_IRQHandler
        B I2C2_ER_IRQHandler

        PUBWEAK DMA_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA_IRQHandler
        B DMA_IRQHandler 
		
        END

