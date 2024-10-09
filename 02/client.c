#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *message = "Hello, Server!";
    char buffer[BUFFER_SIZE] = {0};

    // 创建 socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("socket creation error");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // 将 IPv4 地址从文本转化为二进制形式
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        handle_error("Invalid address/ Address not supported");
    }

    // 连接到服务器
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        handle_error("Connection Failed");
    }

    // 发送消息
    if (send(sock, message, strlen(message), 0) < 0) {
        handle_error("send");
    }
    printf("消息已发送\n");

    // 接收回应
    ssize_t bytes_read = read(sock, buffer, BUFFER_SIZE - 1);
    if (bytes_read < 0) {
        handle_error("read");
    }
    buffer[bytes_read] = '\0'; // 确保字符串结束
    printf("收到回应: %s\n", buffer);

    // 关闭 socket
    close(sock);
    
    return 0;
}
