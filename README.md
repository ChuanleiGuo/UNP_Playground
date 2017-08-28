# UNP_Playground

记录阅读《Unix 网络学习编程》的代码和笔记。准备在阅读的过程中充分理解，重新实现书中的实例代码以及课后作业代码，并记录主要知识点，补充自己在阅读源码和文档过程中搜集的资料。

## Prerequisites

1. 运行 ./configure，生成对应操作系统的编译信息
2. 将《Unix Network Programming》示例代码的依赖库：lib, libfree, libgai 和 libroute 导入项目文件夹并编译。所有的库函数都会被编译到 libunp.a 中
3. 在学习过程中，我没有编写 Makefile，而是使用 VSCode 中的 C/C++ 拓展的构建系统，编译信息在 /.vscode/task.json 中
