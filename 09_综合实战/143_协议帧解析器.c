/*
=====================================================================
 【第 143 题】协议帧解析器：从字节流里抠出完整包
 难度：★★★★★
 知识点：帧格式、校验和、状态机解析、粘包/半包处理
=====================================================================

【题目描述】
    嵌入式通信最常见的帧（自定协议，够练手）：

        [0xAA][0x55][LEN][CMD][DATA...][SUM]
         帧头两字节  数据长度  命令  载荷    校验

    约定：
        LEN = DATA 字节数（不含 CMD）
        SUM = (LEN + CMD + 每个 DATA 字节) 的低 8 位累加和
        LEN 最大 16，超出直接丢弃该帧

    写一个流式解析器（一次喂 1 字节，内部用状态机）：
        typedef enum {
            S_HEAD0, S_HEAD1, S_LEN, S_CMD, S_DATA, S_SUM
        } ParseState;

        typedef struct {
            ParseState st;
            unsigned char len, cmd, idx;
            unsigned char data[16];
            unsigned char sum_calc;
        } Parser;

        void parser_init(Parser *p);
        /* 喂入一字节；若拼出完整合法帧返回 1，否则返回 0

===================== 在下面写你的代码 =====================
*/

