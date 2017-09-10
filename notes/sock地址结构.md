# Socket 地址结构

大多数套接字结构都需要一个指向套接字地址结构的指针作为参数。每个协议都定义它们自己的套接字地址结构，这些地址结构的命名均以 `sockaddr_` 开头。

## IPv4 的套接字地址结构

IPv4 套接字地址结构被命名为 `sockaddr_in`，被定义在 `<netinet/in.h>` 头文件中，它的 POSIX 定义为：

```c
struct in_addr {
    in_addr_t s_addr;   // 32-bit IP地址，使用网络（大端）大端字节序
}

struct sockaddr_in {
    uint8_t         sin_len;        // 套接字地址结构的长度      
    sa_family_t     sin_family;     // AF_INET，是一个 unsigned short
    in_port_t       sin_port;       // 16-bit 端口号
    struct in_addr  sin_addr;       // 32-bit 地址
    char            sin_zero[8];    // unused
}
```

