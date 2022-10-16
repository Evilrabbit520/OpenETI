/**
 * @file Createsocket.cpp
 * @author Evilrabbit (evilrabbit520@gmail.com)
 * @brief 创建Socket套接字（客户端）
 * @version 1.0.0
 * @date 2022-10-09
 * @update log
 * 		1) 20221009 V1.0.0
 * 			1. 初代版本
 * 
 * @copyright Copyright (c) 2021-2022 Evilrabbit. All rights reserved.
 * 
 */

#include "Createsocket.h"
#include <iostream>

#define HOST "127.0.0.1"
#define PORT 3003

int CreateSocket(char *message, int mseeage_len)
{
    if (strlen(HOST) == 0 || PORT == ' ')
    {
        printf("Using:./client ip port\nExample:./client 127.0.0.1 5005\n\n");
        return -1;
    }

    // 第1步：创建客户端的socket。
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        return -1;
    }

    // 第2步：向服务器发起连接请求。
    struct hostent *h;
    if ((h = gethostbyname(HOST)) == 0) // 指定服务端的ip地址。
    {
        printf("gethostbyname failed.\n");
        close(sockfd);
        return -1;
    }
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT); // 指定服务端的通信端口。
    memcpy(&servaddr.sin_addr, h->h_addr, h->h_length);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) // 向服务端发起连接清求。
    {
        perror("connect");
        close(sockfd);
        return -1;
    }

    char buffer[1024];
    std::string SpecialOrder;

    // 第3步：与服务端通信，发送一个报文后等待回复，然后再发下一个报文。
    // for (int ii = 0; ii < 3; ii++)
    // {
        int iret;
        memset(buffer, 0, sizeof(buffer));
        sprintf(buffer, message);
        if ((iret = send(sockfd, buffer, strlen(buffer), 0)) <= 0) // 向服务端发送请求报文。
        {
            perror("send");
            // break;
        }
        printf("发送：%s\n", buffer);

        memset(buffer, 0, sizeof(buffer));
        if ((iret = recv(sockfd, buffer, sizeof(buffer), 0)) <= 0) // 接收服务端的回应报文。
        {
            printf("iret=%d\n", iret);
            // break;
        }
        printf("接收：%s\n", buffer);

        while(1)
        {
            memset(buffer, 0, sizeof(buffer));
            if ((iret = recv(sockfd, buffer, sizeof(buffer), 0)) <= 0) // 接收服务端的回应报文。
            {
                printf("iret=%d\n", iret);
                // break;
            }
            printf("接收：%s\n", buffer);
            SpecialOrder = buffer;
            if(SpecialOrder == "111")
            {
                break;
            }
        }
        
    // }

    // 第4步：关闭socket，释放资源。
    close(sockfd);
}
