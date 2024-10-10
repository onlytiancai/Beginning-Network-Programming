## 编译

    gcc server.c -o server
    gcc client.c -o client

## 运行

    ./server
    ./client

## 头文件介绍

```c
#include <stdio.h>
```
- **标准输入输出库**：提供输入输出功能，如 `printf()` 和 `scanf()` 函数，常用于处理文本数据。

```c
#include <stdlib.h>
```
- **标准库**：提供通用工具函数，如内存分配 (`malloc()`, `free()`)、程序退出 (`exit()`) 和随机数生成 (`rand()`) 等。

```c
#include <string.h>
```
- **字符串处理库**：包含处理字符串的函数，如 `strlen()`、`strcpy()`、`strcat()` 等，常用于字符串操作和比较。

```c
#include <unistd.h>
```
- **Unix 标准函数库**：提供对 POSIX 操作系统 API 的访问，包含文件操作、进程控制和其他低级别的系统调用，如 `read()`、`write()`、`close()` 和 `fork()`。

```c
#include <arpa/inet.h>
```
- **互联网地址操作库**：提供网络地址转换和操作功能，如 IP 地址的转换 (`inet_pton()`、`inet_ntop()`) 和网络字节序的处理。


