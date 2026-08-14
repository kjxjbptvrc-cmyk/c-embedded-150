/*
=====================================================================
 【第 141 题】表驱动状态机：告别 if-else 丛林
 难度：★★★★☆
 知识点：枚举状态、函数指针表、事件驱动、表驱动设计
=====================================================================

【题目描述】
    第 101 题售货机用 if/switch 硬编码跳转，状态一多就乱。
    工业级写法是：状态 × 事件 → 一张转移表。

    定义：
        enum State { IDLE, COIN_IN, DISPENSE, COUNT };
        enum Event { INSERT_COIN, PRESS_BTN, TIMEOUT, COUNT_E };
        typedef void (*Action)(void);

    转移表（二维数组即可）：
        next[COUNT][COUNT_E]     —— 下一状态
        action[COUNT][COUNT_E]   —— 转移时要执行的动作（可为 NULL）

    规则（自行填进表里）：
        IDLE + INSERT_COIN  → COIN_IN，动作：打印 "coin accepted"
        COIN_IN + PRESS_BTN → DISPENSE，动作：打印 "dispensing..."
        COIN_IN + TIMEOUT   → IDLE，动作：打印 "timeout, refund"
        DISPENSE + TIMEOUT  → IDLE，动作：打印 "done, back to idle"
        其余组合：保持当前状态，动作打印 "ignored"

    main 里模拟事件序列：
        INSERT_COIN → PRESS_BTN → TIMEOUT → INSERT_COIN → TIMEOUT
    每步打印：当前状态名、收到事件、下一状态名。

【输出示例】
    [IDLE] + INSERT_COIN → [COIN_IN] coin accepted
    [COIN_IN] + PRESS_BTN → [DISPENSE] dispensing...
    [DISPENSE] + TIMEOUT → [IDLE] done, back to idle
    [IDLE] + INSERT_COIN → [COIN_IN] coin accepted
    [COIN_IN] + TIMEOUT → [IDLE] timeout, refund

【要求】
    1. 状态跳转只许查表，main 里不许出现针对具体状态的 if/switch
    2. 状态名、事件名用字符串表（指针数组）打印，别手写数字
    3. 非法组合必须走 "ignored" 路径，不能越界崩溃

【提示】
    - 动作函数签名统一成 void f(void)，方便塞进函数指针表
    - 嵌入式里按键、通信、电机控制几乎都是这套骨架

【吃透自检】
    1. 表驱动和巨型 switch 比，改需求时改哪里？优势是什么？
    2. 若新增一个状态 REFUND，表要扩哪一维？动作函数要加几个？
    3. action 为 NULL 时怎么安全调用？（先判空再调）
    4. 附加挑战：把转移表改成结构体数组
       {from, event, to, action}，用线性查找代替二维下标

===================== 在下面写你的代码 =====================
*/

