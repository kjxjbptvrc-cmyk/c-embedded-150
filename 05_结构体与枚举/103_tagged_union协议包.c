/*
=====================================================================
 【第 103 题】tagged union 协议包：协议消息的标准内存形态
 难度：★★★★★
 知识点：带标签的联合体（tagged union）、switch 分发、自由与责任
=====================================================================

【题目描述】
    union 自己不记得当前住的是谁，所以工程上给它配一个 type
    标签，合称 tagged union。RTOS 消息队列里跑的消息、协议
    解析完的帧，内存形态就是它（第 143 题协议解析实战见）。

    enum MsgType { MSG_SENSOR, MSG_LED, MSG_LOG };
    typedef struct {
        int type;
        union {
            struct { double temp; } sensor;
            struct { int on; } led;
            struct { char text[16]; } log;
        } payload;
    } Msg;

    1. 写 void handle_msg(const Msg *m)：switch (m->type) 分发，
       三种消息各有各的打印格式（见示例）。
    2. 构造一个 Msg 数组当消息队列：温度 36.5、开灯、
       日志 boot ok、关灯，循环逐条交给 handle_msg。
    3. 反面实验：type 填 MSG_LED，却往 payload.sensor.temp
       写 36.7，再交给 handle_msg，看它读出什么。

【运行效果示例】
    SENSOR: temp=36.5
    LED: on=1
    LOG: boot ok
    LED: on=0
    -- 反面实验 --
    LED: on=-1717986918
    （垃圾值：36.7 的位模式被硬当 int 读，具体数值看平台）

【要求】
    1. type 字段只许用枚举常量，不许写裸数字——第 096 题的纪律
    2. handle_msg 必须有 default 分支兜住未知 type
    3. 用 sizeof 实测两个数：Msg 多大？把三种 payload 全铺开
       放进一个 struct（不用 union）又多大？打印对比
    4. 反面实验的输出要在注释里解释成因

【提示】
    - 嵌套赋值一路点到底：q[0].payload.sensor.temp = 36.5;
    - 字符串写进 text 用 strcpy
    - union 的大小由最大成员决定，这里是 text[16]

【吃透自检】
    1. 为什么必须带 type 字段？（union 不记得自己住的是谁，
       全靠标签指认）
    2. tagged union 比"全铺开"省了多少字节？报实测数字
    3. type 说谎会怎样？（读出垃圾但不报错——这是纪律问题，
       编译器帮不了你）
    4. handle_msg 为什么用 const Msg 指针？（第 093 题的规矩）
    5. 附加挑战：加第四种消息 MSG_KEY（成员 int key_code），
       数数一共要动几处代码——这就是 tagged union 的扩展成本

===================== 在下面写你的代码 =====================
*/

