/*
=====================================================================
 【第 117 题】事件标志组：一个 u32 管 32 个事件
 难度：★★★★★
 知识点：1u << n 形态的枚举、flag_set 与 flag_clear、
         test_any 与 test_all 的位运算表达
=====================================================================

【题目描述】
    嵌入式主循环的日常：按键按了没？串口来数据没？定时器
    到点没？32 个"是 / 否"用一个 unsigned int 全管，
    每个事件独占一位。

    1. 枚举定义事件位，值必须是 1u << n 形态：
           EVT_KEY   = 1u << 0,  EVT_UART  = 1u << 1,
           EVT_TIMER = 1u << 2,  EVT_ERROR = 1u << 3
    2. 四个函数（本题灵魂是后两个的表达式）：
           void flag_set(unsigned int *f, unsigned int mask)
           void flag_clear(unsigned int *f, unsigned int mask)
           int flag_test_any(unsigned int f, unsigned int mask)
               任一命中：按位与的结果非 0
           int flag_test_all(unsigned int f, unsigned int mask)
               全部命中：按位与的结果恰好等于 mask
    3. 场景仿真：循环若干轮，每轮用 rand() % 4 随机让一个
       事件到来（flag_set），然后检查两个唤醒条件并打日志：
           条件甲：等 KEY 或 UART 任一到来（test_any）
           条件乙：等 KEY 和 TIMER 同时到齐（test_all）
       命中就把对应位清掉，模拟"事件被取走处理"。

【输出示例】（与 rand 有关，此为一种可能的运行）
    [轮 0] 到来 TIMER   flags = 0000 0100
    [轮 1] 到来 KEY     flags = 0000 0101
           甲命中(任一): 处理按键或串口
           乙命中(到齐): KEY 与 TIMER 都在, 执行周期任务
           取走后 flags = 0000 0000
    [轮 2] 到来 UART    flags = 0000 0010
           甲命中(任一): 处理按键或串口

【要求】
    1. 枚举值必须写 1u << n，不许写 1、2、4、8 裸数字
    2. test_any 与 test_all 各用一行 return 完成
    3. 日志里的 flags 用 110 的 print_bin(f, 8) 打印

【提示】
    - 等"任一"时 mask 用按位或拼起来：EVT_KEY | EVT_UART
    - 别忘 srand，否则每次运行的"随机"都一样

【吃透自检】
    1. test_any 和 test_all 的表达式默写，一个字符不能错
    2. 为什么用一个 u32 而不是 32 个 bool？（省 RAM 是
       一层；更深一层：一次读写天然同步，32 个 bool
       读到一半可能被中断改掉）
    3. 枚举值定成 1u << n 是什么规矩？谁要是把 EVT_ERROR
       写成 3，会踩到哪两个事件的地盘？
    4. FreeRTOS 的事件组 xEventGroupWaitBits 就是本题的
       正式版——它的"等全部 / 等任一 / 退出时清位"参数
       分别对应你这里的哪个函数、哪个动作？
    5. 附加挑战：写 flag_take(f, mask, all)：all 为真走
       test_all、为假走 test_any，命中自动清位并返回 1

===================== 在下面写你的代码 =====================
*/

