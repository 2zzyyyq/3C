1.照明大功率的时候啸叫
2.电源电压波动触发PVD下降沿
3.在之前发送一次相当于延时，过掉了上电过程中的波动

================================================================================
  data_handle() 函数优化记录 (2026-06-18)
================================================================================

【优化背景】
data_handle() 是 MIIO 协议的命令分发器，WiFi 模块每 150ms 下发一帧指令，
该函数在主循环中高频调用。原始实现存在多层 if-else 嵌套、冗余 strcmp、
响应缓冲复用 rx_buf 等问题。

【调用链】
主循环 → r_uart0_service() → mcu_common_uart_data_unpack() → data_handle()
                                                                     ↑
                                                           收到完整CRLF帧触发

【优化内容】

1. 首字节预判 (First-byte pre-filter)
   - 原理: MIIO 命令首字符分布集中
     'd' → "down ..." 系列 (属性查询/设置/动作/OTA/网络)
     'o' → "ok\r" / "offline\r"
     'e' → "error\r"
     'l' → "local\r"
     'c' → "cloud\r"
     'u' → "uap/unprov/updating\r"
     'M' → "MCU TEST\r" (调试)
   - 效果: 收到 "down action\r" 时 strcmp 从 20+ 次降至 ~6 次
           收到心跳 "ok\r" 时直接从 2 次降至 1 次即 goto 退出
           网络状态命令直接命中空 case，0 次 strcmp

2. 结构扁平化 (switch-case + goto clear_buf)
   原始: 5 层 if-else 嵌套金字塔
   优化: switch(first) 分发 → 每个 case 内用 goto clear_buf 提前退出
   新增 clear_buf 标签统一收尾，memset 大小改用 Frame_length 动态计算

3. 修复响应缓冲复用问题
   原始: memcpy(错误响应 → uart1_rx_buf) 再用 rx_buf 发送
         → 逻辑可工作但语义混乱，且之后 memset 会清除刚写入的响应
   优化: r_uart0_send_bytes() 直接用字面量指针发送，不污染 rx_buf

4. 配网阶段提前退出
   原始: step < 6 时处理 "ok"/"error" 后仍继续向下执行
   优化: 处理完后直接 goto clear_buf，避免进入正常命令分发逻辑

5. 网络状态处理精简
   原始: 12 个 strcmp (长短格式各 6 个)，处理函数均被注释
   优化: 通过首字节 'o'/'l'/'c'/'u' 空 case 跳过，不再执行 strcmp

6. 错误回复防重入集中化
   原始: g_MiioErrorFlag 检查和设置在多个分支中分散
   优化: 各 error/poweroff/UnknownCommand 分支内集中判断和回复

7. TESTADC 调试命令隔离
   原始: #ifdef 块混在正常命令流中，且强改 Poweron_Set_Model_step=6
   优化: 独立 case 'M'，通过 SET_MODEL_OK 赋值完成配网，不影响正常结构

【命令查找效率对比】

  场景                 原始strcmp次数    优化后strcmp次数
  ─────────────────────────────────────────────────
  "ok\r" 心跳             2               1
  "down action\r"         20+             6
  "down get_properties\r" 20+             4
  "local\r" 网络状态      8+              0
  未知命令                 20+             1 (首字节未命中)

【函数三阶段】

  Phase 1: PCBA 自检 (Enter_Pcba_test_flag)
    → 仅检测 WiFi 模块 "ok\r" 应答, 然后 goto clear_buf

  Phase 2: MIIO 配网握手 (step < 6)
    → "ok\r" → step++ (step==4 时跳+2)
    → "error\r" → step==4 时 step++ (mode查询容错)
    → 其他命令均忽略, goto clear_buf

  Phase 3: 正常运行 (step >= 6)
    → UART帧溢出 → 回复 error5001
    → "ok"/"down none" 心跳 → 忽略
    → switch(first) 分发:
      'd' → down 命令族: OTA/属性查询/属性设置/动作/关机/未知命令
      'e' → error → 回复 error5002 + 清空协议栈
      'o','l','c','u' → 网络状态 (handler预留)
      'M' → TESTADC 调试开关
    → clear_buf: memset 清零接收缓冲