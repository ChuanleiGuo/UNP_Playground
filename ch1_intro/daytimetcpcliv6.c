#include "unp.h"

int main(int argc, char **argv) 
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in6 servaddr; // 使用 IPv6 地址

    // 检查参数个数，要求符合输入格式
    if (argc != 2) {
        err_quit("usage: daytimetcpcli.out <IPaddress>");
    }

    // 返回 socket 描述符
    if ( (sockfd = socket(AF_INET6, SOCK_STREAM, 0)) < 0) {
        err_sys("socket error");
    }

    // 设置 socket 地址，包括地址和访问端口
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin6_family = AF_INET6;
    // htons: 主机到网络短整数，将整数从主机字节顺序转换到网络字节顺序（big-endian）
    servaddr.sin6_port = htons(1026);

    // inet_pton: 将 IP 地址的呈现形式转换为整数
    if (inet_pton(AF_INET6, argv[1], &servaddr.sin6_addr) <= 0) {
        err_quit("inet_pton error for %s", argv[1]);
    }

    // connect: 建立连接
    if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) < 0) {
        err_sys("connect error");
    }

    while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = 0;
        if (fputs(recvline, stdout) == EOF) {
            err_sys("fputs error");
        }
    }
    if (n < 0) {
        err_sys("read error");
    }

    exit(0);
}