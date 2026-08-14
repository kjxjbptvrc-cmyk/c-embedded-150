/*
=====================================================================
 【第 053 题】字符串输入与库函数四大件
 难度：★★★☆☆
 知识点：scanf %s 的空格截断、fgets 整行读入、
         strlen strcmp strcpy strcat
=====================================================================

【题目描述】
    实验一：连续两次 scanf %s。输入一行 hello world，
    把两次读到的内容分别打印。你会看到第一次只拿到
    hello——%s 遇到空白就停；第二次不用你再敲，直接把
    world 捡走了——它一直堵在输入缓冲区里。顺带注意：
    scanf("%s", word) 里 word 前面没有取地址符 &，
    为什么这样也行？第 067 题揭开数组名的秘密。

    实验二：换 fgets 读一整行（先把上一行的残留清干净）。
    fgets 会把行末换行符一起收进来：把它找出来换成 \0，
    打印处理前后的 strlen 对比。

    实验三：string.h 四大件各用一遍。重点是 strcmp：
    它返回的不是 1 和 -1，而是"正数、零、负数"，
    用三组字符串打印原始返回值亲眼确认。

【输入输出示例】
    第一行输入: hello world
    scanf 第 1 次: [hello]
    scanf 第 2 次: [world]
    第二行输入: good morning MCU
    fgets 原始 strlen=17，去换行后 strlen=16 [good morning MCU]
    strcmp("apple","apple") = 0
    strcmp("apple","banana") = 负数（打印你机器上的实际值）
    strcmp("hello","he") = 正数（打印实际值）
    strcpy 再 strcat: [hello world] strlen=11

【要求】
    1. 实验一必须连续两次 scanf %s，证明 world 堵在缓冲区
    2. 进实验二之前把该行残留清干净：反复 getchar
       直到吃掉换行符
    3. fgets 第二个参数用 sizeof 缓冲区；去掉换行后
       打印前后两个 strlen
    4. strcmp 三组测试打印原始返回值（%d），
       结论只按"正、零、负"来下
    5. strcpy 先把 "hello" 抄进足够大的缓冲区，
       再 strcat 接上 " world"，打印结果和 strlen

【提示】
    - 清残留可以写：while (getchar() != '\n');
    - 去换行别盲写 buf[strlen(buf) - 1] = '\0'——
      想想 strlen 为 0 时这句踩到哪里去了
    - 用四大件记得 #include <string.h>

【吃透自检】
    1. fgets 比 gets 安全在哪？gets 为什么被 C 标准开除？
    2. 为什么不能假设 strcmp 只返回 1、0、-1？
       你的机器上 strcmp("apple","banana") 返回了几？
    3. 用 s1 == s2 判断"内容相等"靠谱吗？== 比的
       到底是什么？（第 071 题见分晓）
    4. strcat(dst, src) 对 dst 有哪两个前提要求？
       违反任意一个会怎样？
    5. 附加挑战：查一查 strncpy 和 strcpy 的差别，
       并演示一次 strncpy 不补 \0 的坑

===================== 在下面写你的代码 =====================
*/

