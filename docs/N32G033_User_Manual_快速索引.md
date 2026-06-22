# N32G033 系列用户手册 - 快速索引

> 源文件: `docs/N32G033_User_Manual.docx` (从官方PDF提取, 共475页)
> 芯片: 国民技术 N32G033 Cortex-M0, 最高主频 64MHz

---

## 文档结构速查

| 章节 | 内容 | 关键寄存器/地址 |
|------|------|----------------|
| **1. 概述** | 芯片特性、外设列表 | - |
| **2. 系统架构** (pg 21-32) | 总线矩阵、存储器映射、启动配置、Flash规格 | 0x4002_2000 FLASH |
| **3. 电源控制 PWR** | 低功耗模式、PVD、POR | 0x4000_7000 PWR |
| **4. 时钟与复位 RCC** | 时钟树、PLL、HSI/HSE、外设时钟使能 | 0x4002_1000 RCC |
| **5. 外部中断 EXTI** | 中断线映射、边沿触发配置 | 0x4001_0400 EXTI |
| **6. GPIO / AFIO** | 复用功能、数字毛刺滤波器、外部中断配置 | 0x4002_3000 IOM |
| **7. DMA** (pg 90+) | 7通道DMA，传输模式、流控 | 0x4002_0000 DMA |
| **8. I2C** (pg 110+) | I2C1/I2C2，主从模式 | 0x4000_5400 I2C1, 0x4000_5800 I2C2 |
| **9. UART** (pg 140+) | UART1/2/3, IrDA, LIN, RS485 | 0x4000_4400 UART2, 0x4000_4800 UART3 |
| **10. SPI** (pg 420+) | SPI1，主从模式，DMA | 0x4001_2000 SPI1 |
| **11. SQRT** (pg 170+) | 硬件开方运算 | 0x4002_0400 SQRT |
| **12. TIM1 高级定时器** (pg 173-249) | 16bit, 7通道PWM, 刹车, 编码器, 霍尔 | 0x4001_2C00 TIM1 |
| **13. TIM3 通用定时器** (pg 250-309) | 16bit, 4通道PWM, 编码器 | 0x4000_0400 TIM3 |
| **14. TIM4 通用定时器** (pg 310-369) | 16bit, 4通道PWM, 编码器 | APB总线 |
| **15. TIM6 基础定时器** (pg 370-379) | 16bit, 仅时基 | 0x4000_1000 TIM6 |
| **16. ADC** (pg 380-420) | 12bit, 16通道(8外部+8内部), 1Msps | 0x4002_0800 ADC |
| **17. COMP 比较器** (pg 400+) | 2个比较器，互联 | 0x4000_2400 COMP |
| **18. OPA 运放** (pg 410+) | 运算放大器 | 0x4000_2000 OPA |
| **19. IWDG 独立看门狗** | 独立看门狗 | 0x4000_3000 IWDG |
| **20. HDIV 硬件除法器** | 硬件除法 | 0x4002_8000 HDIV |

---

## 存储器映射速查

```
Main Flash:      0x0800_0000 - 0x0800_FFFF  (最大64KB, 128 Pages x 0.5KB)
System Memory:   0x1FFF_0000 - 0x1FFF_0BFF  (3KB, BOOT程序)
System Config:   0x1FFF_F000 - 0x1FFF_F5FF  (1.5KB, 芯片信息)
Option Bytes:    0x1FFF_F600 - 0x1FFF_F619  (26B, 用户配置)
SRAM:            0x2000_0000 - 0x2000_3FFF  (16KB)
```

---

## 外设基地址速查

| 外设 | 基地址 | 总线 |
|------|--------|------|
| DMA | 0x4002_0000 | AHB |
| SQRT | 0x4002_0400 | AHB |
| ADC | 0x4002_0800 | AHB |
| RCC | 0x4002_1000 | AHB |
| FLASH | 0x4002_2000 | AHB |
| IOM (GPIO) | 0x4002_3000 | AHB |
| HDIV | 0x4002_8000 | AHB |
| TIM3 | 0x4000_0400 | APB |
| TIM6 | 0x4000_1000 | APB |
| OPA | 0x4000_2000 | APB |
| COMP | 0x4000_2400 | APB |
| IWDG | 0x4000_3000 | APB |
| UART2 | 0x4000_4400 | APB |
| UART3 | 0x4000_4800 | APB |
| I2C1 | 0x4000_5400 | APB |
| I2C2 | 0x4000_5800 | APB |
| PWR | 0x4000_7000 | APB |
| EXTI | 0x4001_0400 | APB |
| SPI1 | 0x4001_2000 | APB |
| TIM1 | 0x4001_2C00 | APB |
| UART1 | 0x4001_3800 | APB |

---

## 关键Flash寄存器

| 寄存器 | 偏移 | 描述 |
|--------|------|------|
| FLASH_AC | 0x00 | 访问控制 (等待周期) |
| FLASH_KEY | 0x04 | 解锁密钥 (KEY1=0x45670123, KEY2=0xCDEF89AB) |
| FLASH_OPTKEY | 0x08 | 选项字节解锁密钥 |
| FLASH_STS | 0x0C | 状态寄存器 (BUSY位) |
| FLASH_CTRL | 0x10 | 控制寄存器 (PG/PER/MER/START/OPTWE) |
| FLASH_ADD | 0x14 | 地址寄存器 |
| FLASH_OB | 0x1C | 选项字节 |
| FLASH_WRP | 0x20 | 写保护 |
| FLASH_VTOR | 0x50 | 向量表偏移 |

---

## 启动模式

| BOOT0引脚 | nBOOT1 | nBOOT0 | 启动源 |
|-----------|--------|--------|--------|
| 0 | 1 | X | Main Flash (0x0800_0000) |
| 0 | 0 | 1 | System Memory (0x1FFF_0000) |
| 0 | 1 | 0 | SRAM (0x2000_0000) |

---

## 读保护等级

| 等级 | RDP1 | RDP2 | 特性 |
|------|------|------|------|
| L0 | 0xA5 | - | 无保护，SWD可调试 |
| L1 | ≠0xA5 | - | 代码保护，禁止SWD读Flash，改回L0自动擦除全部 |
| L2 | 任意 | 0xCC | 不可逆锁定，禁止所有调试 |

---

## 寄存器缩写说明

| 缩写 | 含义 |
|------|------|
| rw | 软件可读写 |
| r | 只读 |
| w | 只写 |
| rc_w1 | 读/写1清除 |
| rc_w0 | 读/写0清除 |
| rc_r | 读后自动清除 |
| rs | 读/设置 |
| rt_w | 读/写触发事件 |
| t | 写1翻转 |

---

## 已包含在当前项目中的外设驱动

当前项目 `e:\N32\N32G033\` 已使用的外设:
- **GPIO** - [DVI/src/dri_gpio.c](DVI/src/dri_gpio.c)
- **ADC** - [DVI/src/dri_adc.c](DVI/src/dri_adc.c)
- **TIMER** - [DVI/src/dri_timer.c](DVI/src/dri_timer.c)
- **FLASH** - [DVI/src/dri_flash.c](DVI/src/dri_flash.c)
- **DOG (IWDG)** - [DVI/src/dri_dog.c](DVI/src/dri_dog.c)
- **UART** - 参考 app_uart.c
- **PVD** - 参考 dri_pvd.c

> 详细寄存器定义见 `CMSIS/device/n32g033.h`
