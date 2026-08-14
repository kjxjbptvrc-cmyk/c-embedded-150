/*
=====================================================================
 【第 054 题】手写字符串四大件（下标版）
 难度：★★★★☆
 知识点：手写 strlen strcpy strcat strcmp、\0 的责任归属
=====================================================================

【题目描述】
    库函数好用，但你必须能徒手写出来。四个函数一律用
    下标版实现（第 070 题会用指针风格重写一遍，
    两版对着看是理解指针的最快捷径）：

      int my_strlen(const char s[])
      void my_strcpy(char dst[], const char src[])
      void my_strcat(char dst[], const char src[])
      int my_strcmp(const char a[], const char b[])

    写完和库函数对照测试，用例必须覆盖：空串、相等串、
    前缀串（"abc" 对 "abcd"）。

    另做一场事故实验：写个 bad_strcpy，故意不拷 \0。
    准备 char buf[16] = "XXXXXXXXXX"（10 个 X），用
    bad_strcpy 往里拷 "hi" 再用 %s 打印——垃圾尾巴当场
    现形，而且这回是稳定复现的。看完把 my_strcpy 里的
    \0 检查一遍。

【输出示例】
    my_strlen("hello")=5 库=5
    my_strlen("")=0 库=0
    my_strcpy: [hello] 与库一致
    my_strcat: [hello world] 与库一致
    my_strcmp("abc","abc")=0
    my_strcmp("abc","abd")=负 库=负
    my_strcmp("abcd","abc")=正 库=正
    bad_strcpy 事故现场: [hiXXXXXXXX]

【要求】
    1. 四个函数内部不许调用任何库函数，纯下标加循环
    2. my_strcmp 只要求"正、零、负"与库一致，
       数值不必逐个相等（库的约定 053 讲过）
    3. my_strcpy 必须把 \0 一起拷过去
    4. 对照测试逐行打印，至少覆盖题面点名的三类用例

【提示】
    - my_strcat 的第一步：先沿着 dst 走到它的 \0 所在处
    - my_strcmp 逐位走，走到"字符不等"或"有一方到头"
      就停，返回 a[i] - b[i]

【吃透自检】
    1. 不拷 \0 的后果，本质是什么？%s 到底信了谁？
    2. my_strcmp 什么时候停？"字符不等"和"到头"两个
       停机条件少写一个各会怎样？
    3. 这四个函数为什么都不需要传长度参数？
       长度信息藏在哪里？
    4. bad_strcpy 的事故为什么"稳定复现"，052 实验四的
       垃圾尾巴却要看运气？（想想 buf 里预先填了什么）
    5. 附加挑战：写 my_strncmp(a, b, n)，只比前 n 个字符

===================== 在下面写你的代码 =====================
*/

