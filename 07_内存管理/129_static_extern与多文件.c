/*
=====================================================================
 【第 129 题】static、extern 与多文件：第一次拆工程
 难度：★★★★☆
 知识点：多文件编译、extern 声明、static 全局 = 文件私有、
         编译与链接两阶段
=====================================================================

【题目描述】
    一直写单文件，今天拆出你的第一个多文件工程。在本文件
    夹自建两个源文件：

    mathutil.c：实现 int add(int a, int b) 和
        int is_prime(int n)，再放一个 static int call_count，
        两个函数每被调用一次就加一，并提供
        int get_count(void) 供外部查询
    main.c：顶部用 extern 声明 add、is_prime、get_count，
        调用它们并打印结果

    编译命令（PowerShell 里执行）：
        gcc main.c mathutil.c -o app
        .\app.exe

    撞墙实验：在 main.c 里写 extern int call_count; 并直接
    打印它——链接阶段报 undefined reference。static 全局
    变量就是"文件私有"，这是 C 语言的 private。

    可见性总结表（做完实验后默写进注释）：
        普通全局      全工程可见，extern 一声明就能用
        static 全局   只有本文件可见
        static 局部   只有本函数可见，但常驻不灭（033 题）

    嵌入式点：真实工程就是每个外设一个 c 文件——led.c、
    uart.c、adc.c，各自用 static 管住内部状态，对外只留
    几个函数接口。今天拆的就是这个套路的最小版。

【输出示例】
    add(3, 4) = 7
    is_prime(97) = 1
    call_count = 2

【要求】
    1. 两个源文件建在本文件夹；实验记录和总结表写在本文件
       下方的注释里
    2. 撞墙实验的报错信息原样抄一行留档——链接错误和编译
       错误长得不一样，认认脸
    3. 把 call_count 前面的 static 去掉重新编译链接，对比

【提示】
    - gcc 一次接多个 .c：先分别编译成目标文件，再统一链接
    - 报错里出现 ld 或 undefined reference 字样就是链接错

【吃透自检】
    1. static 的两种用法各改变了什么？（局部：改生命周期；
       全局：改链接可见性）
    2. 声明和定义的区别是什么？extern int x; 是哪一种？
    3. 编译、链接两阶段各干什么？undefined reference 出在
       哪个阶段？
    4. 附加挑战：写一个 mathutil.h 收纳声明，用 #include
       替代手写 extern，体会头文件为什么存在

===================== 在下面写你的代码 =====================
*/

