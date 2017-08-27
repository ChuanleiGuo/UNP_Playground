#include "unp.h"
#include <time.h>

int main(int argc, char **argv)
{
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char buff[MAXLINE];
    time_t ticks;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    // 允许任何用户访问服务器
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(1026);

    // 将
    Bind(listenfd, (SA *)&servaddr, sizeof(servaddr));

    // listen：将套接字转换为监听套接字
    Listen(listenfd, LISTENQ);

    for ( ; ; ) {
        // 完成三次握手并返回连接描述符
        connfd = Accept(listenfd, (SA *)NULL, NULL);

        ticks = time(NULL);
        // ctime 将时间转换为可读格式
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        Write(connfd, buff, strlen(buff));

        // 四次挥手，断开连接
        Close(connfd);
    }
}