# N32G033 — 智能晾衣架电机控制器 工程逻辑分析报告

## 一、项目概览

| 项目 | 详情 |
|------|------|
| **产品名称** | 智能晾衣架/窗帘电机控制器 (Xiaomi MIIO 生态) |
| **目标芯片** | N32G033K8 (Nations Technology, Cortex-M0+) |
| **工具链** | Keil MDK V5.41 + ARMCLANG V6.22 |
| **版权方** | Nsing Technologies Inc. & 杭州凯撒大帝技术有限公司 |
| **产品型号** | `xiaomi.airer.0003` (智能晾衣架) |
| **代码规模** | Code≈10KB RO-data≈470 RW-data≈72 ZI-data≈1552 |
| **堆栈配置** | Stack=1KB, Heap=512B |
| **Flash布局** | Boot(0x08000000~0x08003000) + APP(0x08003000~) + Data(0x0800FC00~) |

---

## 二、完整文件结构与模块图谱

```
E:\N32\N32G033\
├── readme.txt                     # 项目简介
├── ALL.h                          # ★ 全局类型/变量/函数声明 (644行核心)
├── H_ALL.h                        # 空头文件(占位)
│
├── h_433.h                        # ★ 硬件配置总纲: GPIO引脚/宏/常量 (492行)
├── h_tim.h                        # 定时器硬件配置宏
├── h_uart.h                       # UART日志宏系统
│
├── USER/                          # 用户层: 程序入口+中断处理
│   ├── inc/main.h                 # 系统头文件汇总
│   ├── inc/n32g033_it.h           # 系统异常处理声明
│   ├── src/main.c                 # ★ 主程序入口 (273行)
│   └── src/n32g033_it.c           # ★ 中断向量+UART/PVD中断 (324行)
│
├── CMSIS/                         # ARM CMSIS标准层
│   ├── core/                      # CM0+/CM3/CM4/CM7/CM23/CM33 内核文件
│   └── device/
│       ├── n32g033.h              # 芯片寄存器定义
│       ├── system_n32g033.c/.h    # 系统初始化(SystemInit/SystemCoreClock)
│       └── startup/startup_n32g033.s  # ★ 启动文件 (向量表+堆栈)
│
├── n32g033_std_periph_driver/     # ★ 标准外设库 (Nations官方)
│   ├── inc/ (26个头文件)
│   └── src/ (20个源文件)
│       # GPIO/UART/TIM/ADC/DMA/I2C/SPI/IWDG/PWR/FLASH/EXTI/COMP/OPAMP/SQRT/HDIV
│
├── DVI/src/                       # 驱动抽象层 (部分功能)
│   ├── dri_gpio.c                 # GPIO驱动封装(LedOn/LedOff/初始化)
│   └── dri_flash/adc/dog/timer.c  # Flash/ADC/看门狗/定时器驱动
│
├── app_motor.c                    # ★ 电机控制逻辑 (433行)
├── app_uart.c                     # ★ WiFi/MIIO协议处理 (2411行,最大模块)
├── app_433.c                      # ★ 433MHz遥控解码+按键处理 (676行)
├── app_flash.c                    # ★ Flash数据存储管理 (278行)
├── app_limt.c                     # ★ 限位/障碍/超重检测 (521行)
├── app_adc.c                      # ADC电流检测/超重校准 (212行)
├── app_led.c                      # LED灯光控制+色温调节 (339行)
├── app_buzz.c                     # 蜂鸣器音效系统 (202行)
│
├── dri_uart.c                     # ★ UART驱动(log_init/printf重定向/队列)
├── dri_pvd.c                      # PVD掉电检测+看门狗初始化
│
├── keelop_crc.c                   # ★ KeeLoq加密算法(433遥控器密钥解密)
│
├── it_timer.c                     # ★ TIM6 1ms定时中断(全局时基)
├── it_exit.c                      # ★ EXTI中断(Holl编码器+AC过零)
├── it_433.c                       # ★ TIM1捕获中断(433MHz脉冲测量)
└── it_adc.c                       # ADC中断处理
```

---

## 三、系统启动流程 (main 函数逻辑链)

```
上电 → Reset_Handler
  │
  ├─ 1. OTA模式判断 (宏 #define OTA)
  │    ├─ _VTOREN() → 使能中断向量表重映射
  │    └─ _VTORVALUE() → 设置向量表偏移到 APP_START_ADDR (0x08003000)
  │    说明: 当编译为 Bootloader 时使能; APP 固件跳过此步骤
  │
  ├─ 2. SystemInit() → 系统时钟配置
  │
  ├─ 3. RCC_Configuration()
  │    使能时钟: TIM3/TIM1/TIM4/TIM6/ADC/GPIO
  │    ADC时钟4分频
  │
  ├─ 4. GPIO_Configuration() [dri_gpio.c]
  │    配置: LED_PWM (PF0/PF1), 433捕获(PB6), 蜂鸣器(PA2)
  │         电机PWM(PB0/PB1), 灯光(PA15), LED指示灯(PB5/PB7)
  │         限位开关(PA4/PA5), Holl传感器(PB4), 异物检测(PA6)
  │
  ├─ 5. NVIC_Configuration()
  │    使能中断: TIM6(1ms) PRI=1, TIM1_CC(433) PRI=1
  │            ADC PRI=2, UART1(WiFi) PRI=1, UART2(调试) PRI=1
  │            EXTI_LINE9 上升/下降沿
  │
  ├─ 6. log_init() → UART1 @115200 初始化
  │
  ├─ 7. PVD_Init() → 掉电检测 @3.6V阈值
  │
  ├─ 8. TIM初始化:
  │    TIM3_PWM_LED() → 灯光PWM (CH1白/CH2黄)
  │    TIM3_PWM_MOTOR() → 电机PWM (CH3/CH4)
  │    TIM4_PWM_BUZZ() → 蜂鸣器PWM
  │
  ├─ 9. ADC_Initial() → 电机电流采样
  │
  ├─ 10. read_data() → 从Flash Block0/Block1读取存储参数
  │     [关键: 数据恢复逻辑 - 详见存储系统]
  │
  ├─ 11. variable_init() → 全局变量初始化
  │
  ├─ 12. r_uart0_protocol_init() → WiFi协议栈初始化(环形队列)
  │
  ├─ 13. 外部中断:
  │     KeyInputExtiInit(PA7, AC过零检测) - 上升/下降沿
  │     HOLLInputExtiInit(PB4, Holl编码器) - 上升/下降沿
  │
  ├─ 14. 启动状态处理:
  │     Flash_Data.Quite_updata==1 → 长鸣一声(自动升级模式)
  │     Flash_Data.Device_updata==2 → 恢复断电前电机/灯光状态
  │
  └─ 15. while(1) 主循环:
       ├─ r_uart0_service()        # WiFi MIIO协议轮询
       ├─ limit_protect()          # 限位保护判断
       ├─ ADC_StartConversion()    # ADC采样
       ├─ _220AC_Power_down_save() # 掉电检测保存
       ├─ [5ms] Motor_speed()      # PWM软启动
       ├─ [5ms] 433按键状态机
       ├─ [10ms] alarm_signal_test_and_beep()  # 故障检测+报警
       ├─ [10ms] CmdBzhx()         # 蜂鸣器状态机
       ├─ [100ms] PowerOn_ModelSet()  # MIIO配网流程
       └─ [150ms] _150ms_work()    # WiFi状态上报
```

---

## 四、核心子系统深度分析

### 4.1 时基系统 (it_timer.c / TIM6 1ms中断)

- 每1ms递增全局计数器: Time.time5ms/10ms/100ms/150ms/test_speed/...
- 产生定时标志: 5ms(电机PWM调速), 10ms(故障检测+蜂鸣器), 100ms(配网流程), 150ms(WiFi状态上报)
- 电机换向延时控制: Motor_down_to_up→1s延时, Motor_up_to_down→1s延时, Motor_raise_up→200ms延时
- 上电10s学习窗口: power_on_10stime → 10s后使能 (用于433遥控器配对学习)
- 按键删除码计时: STOP_CMD_Repeat → 5s超时
- 报警提示音循环: 5s周期报警

### 4.2 电机控制系统 (app_motor.c)

**电机五态**: 上升 / 下降 / 暂停 / 上停止 / 下停止

**PWM软启动** (Motor_speed 函数, 每5ms调用):
- 启动: 使用 sin(0~π/2) 曲线平滑加速, PWM值 = 1600 - (PWM_MAX_VALUE * sin(angle))
- 停止: 同样使用正弦曲线平滑减速
- 急停: MOTOR_CLOSE_IO (遇到障碍物时直接关断)

**方向切换保护**: 换向前有1s延时防冲击

**A/B双电机**:
- A电机: TIM3 PWM (CH3下降/CH4上升) + Holl编码器位置反馈
- B电机: GPIO直接控制 (B_MOTOR_DN_IO/B_MOTOR_UP_IO)

### 4.3 位置检测系统 (it_exit.c / app_limt.c)

**Holl编码器**:
- EXTI_LINE5 (PB4) 上升/下降沿中断
- 根据 Holl_DIR 判断方向: 1=上升计数++, 0=下降计数--
- 每10转 → Motor_Run_Circle++ (寿命追踪)

**限位系统**:
- 上限位(PA4): Motor_Current_Position = 1000
- 下限位(PA5): Motor_Current_Position = 5000
- 行程总量: 4000脉冲 (对应1.3m), 1% = 40脉冲

**异物检测(YZ)**: PA6=0 → 电机停止 → 自动反向抬升 → 3s后再次尝试

### 4.4 安全保护系统 (app_limt.c — 6状态机)

| 状态 | 名称 | 功能 |
|------|------|------|
| State 0 | 正常运行 | 堵转/超重/遇障检测, 速度计算 |
| State 1 | 上行遇阻 | 自动下降500ms |
| State 2 | 超重 | 自动下降 |
| State 3 | 超重后等待 | 到达限位→State 0 |
| State 4 | 遇阻下降后 | 3s后暂停→State 0 |
| State 5 | 强制下降 | 10s后→State 0 |

**报警蜂鸣**: 遇障(长鸣×3), 超重(两声长鸣×3), 堵转(三声长鸣×3), 间隔5s

### 4.5 WiFi/MIIO协议系统 (app_uart.c — 2411行, 最大模块)

**协议层级**: MIIO应用层 → 帧解析层(CRLF分帧) → 环形缓冲队列(256B) → UART1中断收发

**配网流程** (6步):
1. `"model xiaomi.airer.0003\r"` — 上报型号
2. `"mcu_version 0005\r"` — 上报版本
3. `"echo off\r"` — 关闭回显
4. `"ble_config set 29375 0005\r"` — PID设置
5. `"mcu_version 0005\r"` — 再次上报版本
6. `"set_mcu_auto_ota on\r"` — 开启自动OTA

**SIID属性体系**:
- SIID 2 (电机A): 故障/状态/位置(0-100%)/电子限位/合拢/速度
- SIID 3 (灯光): 开关/亮度/色温(3000-5700K)/夜灯开关/夜灯亮度/定时
- SIID 5 (提示音): 开关
- SIID 7 (双端): 故障/状态/限位...(同上)
- SIID 8 (遥控器): 开关/已配对列表(最多3个)

**状态变化上报**: 通过 Device_State_Data vs Up_State_Data 双向比较, 仅状态变化时上报

### 4.6 433MHz遥控系统 (app_433.c + it_433.c + keelop_crc.c)

**信号采集**: TIM1_CH2(PB6) 输入捕获, 分别记录高/低电平脉宽

**解码状态机**: NO_DATA → HEAD_HIGH → FIXED_CODE → ROLL_CODE → COMMAND_END

**帧格式**:
- 引导高电平: 3800-5000us
- 固定码: 66电平(33bit) → ID(24bit) + Command(8bit)
- 滚动码: 129电平(64bit) → Secret_Key(32bit)
- 宽脉冲(650-950us)→1, 窄脉冲(200-600us)→0

**KeeLoq解密**: 528轮非线性反馈+位移解密, 5维NLF查找表, 固定密钥

**按键处理**: 短按/长按(3s~10s分级), 最多配对3个遥控器(FIFO替换)

### 4.7 灯光控制系统 (app_led.c)

- 双色温PWM: TIM3 CH1(白光) + CH2(黄光), 3000K~5700K
- 亮度: 0-100%, 缓启动/缓灭
- 色温渐变步长自适应: 5~25
- 夜灯模式: 时间段内自动切换

### 4.8 掉电保护系统 (dri_pvd.c + PVD中断)

**PVD**: 3.6V阈值, 中断优先级0(最高)
- 掉电流程: 立即停电机 → 关蜂鸣器+灯光 → 保存配置+位置到Flash → 死循环等待掉电

**AC过零检测** (PA7):
- 有信号 → 正常供电
- 无信号50ms → 预判掉电 → 提前停车保存

**上电恢复**: Device_updata==2 → 恢复断电前电机方向和灯光状态

### 4.9 Flash存储系统 (app_flash.c)

| 区块 | 地址 | 大小 | 内容 |
|------|------|------|------|
| Block0 | 0x0800FC00 | 512B | 配置参数(11条目), Magic=0x5AA5 |
| Block1 | 0x0800FE00 | 512B | 位置数据(8条目) |

**FDL_DATA**(44字节): 亮度/色温/遥控器ID密钥/电子限位/超重校准/状态备份

**磨损均衡**: 循环递增写入位置, 空间不足时擦除整页

---

## 五、中断优先级

| 中断源 | IRQn | 优先级 | 功能 |
|--------|------|--------|------|
| PVD_IRQn | PVD | 0(最高) | 掉电紧急保存 |
| TIM6_IRQn | TIM6 | 1 | 1ms时基 |
| TIM1_CC_IRQn | TIM1 | 1 | 433脉冲捕获 |
| UART1_IRQn | UART1 | 1 | WiFi数据收发 |
| EXTI0_6_IRQn | EXTI | 1(Holl)/3(AC) | 编码器+过零检测 |
| ADC_IRQn | ADC | 2 | 电流采样 |
| UART2_IRQn | UART2 | 1 | 调试串口 |

---

## 六、系统数据流图

```
┌──────────┐  ┌──────────┐  ┌───────────┐
│ 433遥控器 │  │ WiFi模块  │  │ 机械按键   │
└────┬─────┘  └────┬─────┘  └─────┬─────┘
     │ 433MHz      │ UART1         │ GPIO
     ▼             ▼               ▼
┌─────────────────────────────────────────┐
│          命令处理层 (data_handle)        │
│      命令分发: 电机/灯光/学习/配置       │
└──────────┬──────────────────────────────┘
           │
    ┌──────┴──────┐
    ▼             ▼
┌────────┐  ┌──────────┐
│电机控制│  │ 灯光控制  │
└───┬────┘  └─────┬─────┘
    ▼              ▼
┌────────┐   ┌──────────┐
│PWM输出 │   │PWM输出   │
│TIM3 CH3│   │TIM3 CH1/2│
│TIM3 CH4│   └──────────┘
└────────┘
     │
     ▼
┌──────────┐   ┌──────────┐
│Holl编码器│──▶│位置计算  │
└──────────┘   └────┬─────┘
                    ▼
              ┌──────────┐
              │限位保护  │
              │障碍检测  │
              └──────────┘
```

---

## 七、关键配置参数速查

| 参数 | 值 | 说明 |
|------|-----|------|
| ADC采样缓冲深度 | 11 | AD_BUFF_DIP |
| 堵转电流 | 4A | MOTOR_ERR_CURRENT |
| 超重电流 | ~1.82A | OVER_WIGHT_REAL_CURRENT |
| 行程总量 | 4000脉冲 | STROKE_TOTAL (对应1.3m) |
| 上限位脉冲值 | 1000 | UP_POSITION_VALUE |
| 下限位脉冲值 | 5000 | DOWN_POSITION_VALUE |
| 遥控学习窗口 | 10s | POWER_ON_ENABLE_STUDY_TIME |
| 蜂鸣器报警周期 | 5s | ALARM_BEEP_CYCLE_TIME |
| 极限运行圈数 | 6000 | MOTOR_MAX_CIRCLE |
| PWM最大值 | 1600 | PWM_MAX_VALUE |
| 电机换向延时 | 1s | MOTOR_DIR_CHANGE_DELAY |
| 帧间间隔 | 20ms | RECEIVE_DATA_PACKET_INTERVAL_TIME |
| PVD电压阈值 | 3.6V | PWR_PVD_LEVEL_3V6 |
| 配网等待超时 | 30分钟 | WAIT_CONFIG_NETTIME |

---

## 八、代码质量评估

### 优点
1. **功能完备**: 电机控制/灯光/433/WiFi/掉电保护/自检/OTA一应俱全
2. **安全保护完善**: 堵转/超重/遇障/限位/掉电多层防护
3. **实时性良好**: TIM6 1ms时基+TIM1捕获+EXTI编码器中断优先级合理
4. **Flash磨损均衡**: Block0/Block1循环写入策略
5. **状态机清晰**: 电机控制/433解码/报警/配网均有明确状态机
6. **MIIO协议完整**: 支持小米IoT完整属性体系和OTA升级

### 问题与风险
1. **中文注释乱码**: 所有中文注释因编码问题无法正常阅读 (GB2312/UTF-8不匹配)
2. **编译宏硬编码**: `#define OTA` 在 main.c 中硬编码, 应移到项目配置
3. **双433实现**: it_433.c 中有 `#ifdef D_433` 两套解码代码
4. **全局变量过多**: ALL.h 有600+行 extern 声明, 缺乏模块封装
5. **无RTOS**: 裸机循环, 大型状态上报可能阻塞
6. **B电机功能未启用**: 大量B电机代码被注释(#if 0)
7. **KeeLoq固定密钥**: key_fixed 数组硬编码, 缺乏安全保护
8. **看门狗未启用**: WDT_Init 被注释(#if 0)
