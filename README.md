# C to Embedded · 150 Exercises / C 语言 150 题 · 通往嵌入式之路

[English](#english) · [中文](#中文)

A practical, sequence-locked C curriculum for people who want to reach embedded firmware — not just pass an online judge.

一套按编号锁死顺序的 C 语言习题，目标不是刷 OJ，而是走到 STM32 / 固件门口。

**Built with [ChatGPT Pro](https://openai.com/chatgpt/pricing/) · 由 ChatGPT Pro 构建**

---

## English

### Why this exists

Most C tutorials stop at syntax. Most embedded tutorials assume you already think in registers, buffers, and state machines. This repo is the missing middle: **150 blank exercises** that start at `printf` and end at a mini firmware simulator (GPIO bits, a ring buffer, a shell, software timers, a cooperative scheduler).

Each file is a problem, not a solution. You write the code yourself, compile it, and check it against the sample output. Later problems reuse skills from earlier ones on purpose — the set is one continuous story.

It is especially useful if you are a beginner who wants a clear on-ramp into embedded C: one file, one skill, one self-check, then the next board-level idea.

### Built with ChatGPT Pro

This project was designed and written with **ChatGPT Pro**.

Pro is what made a *curriculum* possible, not just a pile of drills. It held the whole 150-problem arc in mind: pointers before `void *`, bit operations before fake registers, ring buffers before a parser, timers before a scheduler. It wrote teaching comments that sound like a patient lab instructor — requirements, traps, and “did you actually get this?” questions — instead of dumping answers.

For a learner building a path into firmware, that long-horizon teaching quality is the difference between random exercises and something you can actually follow to a development board. Working with Pro also makes the studying itself faster: when a pointer or a bitwise trap does not click, you can ask it to unpack the same idea another way, still without handing you a finished answer.

The model is genuinely strong at this. It keeps the whole map in its head, notices what you are about to misunderstand, and explains it like someone who has sat beside a lot of beginners.

### Who it is for

- Beginners who know a little C and want to reach STM32 / firmware
- Learners who are shaky on pointers, memory, and bitwise work
- Anyone willing to go in order and not skip ahead

### Roadmap

| Stage | Problems | Focus |
|---|---|---|
| 01 Basics | 001–025 | I/O, types, operators, branches, loops |
| 02 Functions | 026–040 | Parameters, return values, scope, recursion |
| 03 Arrays & strings | 041–060 | 1D/2D arrays, search, sort, strings |
| 04 Pointers (core) | 061–090 | Addresses, function pointers, callbacks, memory view |
| 05 Structs & enums | 091–105 | Structs, unions, bit-fields, enums |
| 06 Bitwise & bases | 106–120 | The daily craft of talking to registers |
| 07 Memory | 121–132 | Memory layout, malloc, linked lists, `volatile` |
| 08 Preprocessor | 133–140 | Headers, macros, conditionals, register-map macros |
| 09 Capstone | 141–150 | State machines, ring buffers, protocols, schedulers |

Full checklist: [`000_总目录.md`](000_总目录.md).

### How to use it

1. Go strictly in numeric order. Do not skip.
2. If you are stuck for more than an hour: look up syntax and concepts, not a full solution. Then close the notes and rewrite from scratch.
3. A problem is done only when all three hold: output matches the sample, you can answer every self-check question without notes, and you attempted the extra challenge.
4. For a hard problem, create a blank file the next day and write it again from memory.

### Compile

You need [GCC](https://gcc.gnu.org/) ([MinGW-w64](https://www.mingw-w64.org/) or MSYS2 on Windows). In the problem’s folder:

```bash
gcc 001_输出与转义字符.c -o 001
./001
```

Windows PowerShell:

```powershell
gcc .\001_输出与转义字符.c -o 001.exe
.\001.exe
```

Add `-lm` on Linux / macOS when a problem uses the math library.

### After problem 150

Buy an STM32 board (F103 or F407). Learn GPIO → UART → timer → interrupt → DMA → RTOS. The skeleton will already feel familiar — you practiced it here.

### License

[MIT License](LICENSE). Use, modify, and republish freely; keep the license notice.

---

## 中文

### 这套题在补哪一段路

多数 C 教程停在语法。多数嵌入式教程一上来就默认你会寄存器、缓冲区和状态机。中间缺的就是这一段：**150 道空白习题**，从 `printf` 走到迷你固件模拟器（GPIO 位操作、环形缓冲、shell、软件定时器、合作式调度）。

每个 `.c` 文件里只有题目，没有答案。代码写在注释下方，自己编译，对照示例输出。后面的题会反复调用前面练过的手艺——整套题是一部连续剧。

如果你是想入门嵌入式的新手，这套材料很省事：一次一题，一题一个技能，做完有自检，下一题就接到板上会用到的想法。

### 由 ChatGPT Pro 构建

本项目由 **ChatGPT Pro** 设计并写成。

Pro 做成的是一门**课程**，而不是一堆散题。它能把 150 题的弧线拿住：先指针再 `void *`，先位运算再假寄存器，先环形缓冲再解析器，先定时器再调度器。题目注释像实验室里会盯着你的助教——有要求、有坑、有「你真的吃透了吗」——而不是把答案摊在桌上。

对一个要走进固件的学习者来说，这种跨一百多题仍不散架的教学能力，才是随机练习和「可以跟着走到开发板」之间的差别。有 Pro 在旁边，学习效率也会高一截：指针或位运算卡住时，可以让它换个说法把同一个点讲透，而不必直接要完整答案。

这个模型确实很厉害。整张地图它记得住，你快踩坑的时候它先看见，讲解的口气像带过很多新手的人。

### 适合谁

- 会一点 C，想走到 STM32 / 固件
- 指针、内存、位运算还不踏实
- 愿意按顺序做，不跳题

### 阶段

| 阶段 | 题号 | 主题 |
|---|---|---|
| 01 基础语法 | 001–025 | 输出、变量、运算符、分支、循环 |
| 02 函数 | 026–040 | 参数、返回值、作用域、递归 |
| 03 数组与字符串 | 041–060 | 一维/二维数组、查找排序、字符串 |
| 04 指针（重点） | 061–090 | 从地址到函数指针、回调、内存透视 |
| 05 结构体与枚举 | 091–105 | 结构体、联合体、位域、枚举 |
| 06 位运算与进制 | 106–120 | 操作寄存器的基本功 |
| 07 内存管理 | 121–132 | 内存四区、malloc、链表、volatile |
| 08 预处理与宏 | 133–140 | 头文件、宏、条件编译、寄存器映射 |
| 09 综合实战 | 141–150 | 状态机、环形缓冲、协议、调度器 |

完整进度清单见 [`000_总目录.md`](000_总目录.md)。

### 怎么用

1. 严格按编号顺序做，不要跳题。
2. 卡住超过 1 小时：可以查语法和概念，不要看完整答案；查完合上资料从零重写。
3. 「吃透」三条全过才算过关：输出与示例一致、自检问题能说清楚、附加挑战做过。
4. 觉得费劲的题，隔天新建空白文件盲写一遍。

### 怎么编译

需要安装 [GCC](https://gcc.gnu.org/)（Windows 可用 [MinGW-w64](https://www.mingw-w64.org/) 或 MSYS2）。在题目所在目录：

```bash
gcc 001_输出与转义字符.c -o 001
./001
```

Windows PowerShell：

```powershell
gcc .\001_输出与转义字符.c -o 001.exe
.\001.exe
```

部分题目需要数学库时加上 `-lm`（Linux / macOS）。

### 做完之后

买一块 STM32 开发板（F103 或 F407 均可），按 GPIO → 串口 → 定时器 → 中断 → DMA → RTOS 的顺序学。骨架你已经在这 150 题里练过了。

### 许可证

[MIT License](LICENSE)。题目与示例可自由使用、修改、再发布；转载或二次发布时请保留原许可证声明。
