/*
=====================================================================
 【第 144 题】迷你 shell：命令表 + 函数指针分发
 难度：★★★★☆
 知识点：命令表、字符串分割、函数指针、argc/argv 风格
=====================================================================

【题目描述】
    调试串口时敲一行命令控制板子——本质就是一个迷你 shell。

    定义命令表：
        typedef void (*CmdHandler)(int argc, char *argv[]);
        typedef struct {
            const char *name;
            CmdHandler  handler;
            const char *help;
        } Cmd;

    至少实现 4 条命令：
        help                 列出所有命令与帮助
        echo <args...>       原样打印参数，空格分隔
        add <a> <b>          把两个整数相加打印
        set <name> <value>   设置一个全局变量（如 led=0/1），再 get
        get <name>           读取并打印（本题可只支持 led 一个变量）

    主循环：
        用 fgets 读一行 → 按空格拆成 argc/argv（088 题分割手艺）
        → 在命令表里线性查找 name → 找到就调 handler，找不到打印
          "unknown cmd"

    输入以一行 quit 结束程序。

【交互示例】
    > help
    help - list commands
    echo - print args
    add  - add two ints
    set  - set variable
    get  - get variable
    > echo hello world
    hello world
    > add 3 5
    8
    > set led 1
    ok
    > get led
    led=1
    > foo
    unknown cmd
    > quit

【要求】
    1. 新增命令只许"往表里加一行"，不许改主循环的分发逻辑
    2. 拆词时注意末尾 '\n'，记得剥掉
    3. argv 里的指针指向原行缓冲区即可（原地改空格为 '\0'）

【提示】
    - 079 题函数指针数组、082 题 main 参数，是本题直系亲戚
    - 嵌入式里 AT 指令解析、Bootloader 命令行都是这套

【吃透自检】
    1. 为什么命令表比"一长串 if (strcmp(...))"更易维护？
    2. 原地把空格改成 '\0' 后，原字符串还能完整打印吗？为什么？
    3. handler 的 argc/argv 约定和真正的 main 有什么相同点？
    4. 附加挑战：支持引号包裹参数（"hello world" 算一个 argv）

===================== 在下面写你的代码 =====================
*/

