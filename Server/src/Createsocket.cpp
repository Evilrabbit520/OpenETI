/**
 * @file Createsocket.cpp
 * @author Evilrabbit (evilrabbit520@gmail.com)
 * @brief 创建Socket套接字（服务端）
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
#include "SubjectLogic.h"

#define PORT 3003

int CreateSocket(int counter)
{
    if (PORT == ' ')
    {
        printf("Using:./server port\nExample:./server 5005\n\n");
        return -1;
    }

    // 第1步：创建服务端的socket。
    int listenfd;
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        return -1;
    }

    // 第2步：把服务端用于通信的地址和端口绑定到socket上。
    struct sockaddr_in servaddr; // 服务端地址信息的数据结构。
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;                // 协议族，在socket编程中只能是AF_INET。
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // 任意ip地址。
    // servaddr.sin_addr.s_addr = inet_addr("192.168.190.134"); // 指定ip地址。
    servaddr.sin_port = htons(PORT); // 指定通信端口。
    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
    {
        perror("bind");
        close(listenfd);
        return -1;
    }

    // 第3步：把socket设置为监听模式。
    if (listen(listenfd, 5) != 0)
    {
        perror("listen");
        close(listenfd);
        return -1;
    }

    // 第4步：接受客户端的连接。
    int clientfd;                             // 客户端的socket。
    int socklen = sizeof(struct sockaddr_in); // struct sockaddr_in的大小
    struct sockaddr_in clientaddr;            // 客户端的地址信息。
    
    clientfd = accept(listenfd, (struct sockaddr *)&clientaddr, (socklen_t *)&socklen);
    if(1 == counter)
    {
        printf("客户端（%s）已连接。\n", inet_ntoa(clientaddr.sin_addr));
        
        // Container con;
        // printf("%s", con.MessageBox().c_str());
    }
    else
    {
        printf("客户端（%s）第%d次通信。\n", inet_ntoa(clientaddr.sin_addr), counter);
    }
    

    // 第5步：与客户端通信，接收客户端发过来的报文后，回复ok。
    char buffer[1024];
    std::string SpecialOrder;
    if(1 == counter)
    {
        while (1)
        {
            int iret;
            memset(buffer, 0, sizeof(buffer));
            if ((iret = recv(clientfd, buffer, sizeof(buffer), 0)) <= 0) // 接收客户端的请求报文。
            {
                //printf("iret=%d\n", iret);
                break;
            }
            printf("Server receives：%s\n", buffer);
            
            SpecialOrder = buffer;
            
            if("apply" == SpecialOrder)
            {
                strcpy(buffer, "收到客户端传输申请，服务端同意！");
                if ((iret = send(clientfd, buffer, strlen(buffer), 0)) <= 0) // 向客户端发送响应结果。
                {
                    perror("send");
                }
                printf("Server send：%s\n", buffer);
                Container con;
                //printf("%s", con.MessageBox().c_str());
                sleep(1);
                strcpy(buffer, con.MessageBox().c_str());
                if ((iret = send(clientfd, buffer, strlen(buffer), 0)) <= 0) // 向客户端发送响应结果。
                {
                    perror("send");
                }
                printf("Server send：%s\n", buffer);
                sleep(1);
                strcpy(buffer, "111");
                if ((iret = send(clientfd, buffer, strlen(buffer), 0)) <= 0) // 向客户端发送响应结果。
                {

                }
                sleep(1);
            }
            else if("applyErr" == SpecialOrder)
            {
                strcpy(buffer, "收到客户端传输申请，服务端拒绝了申请！");
                if ((iret = send(clientfd, buffer, strlen(buffer), 0)) <= 0) // 向客户端发送响应结果。
                {
                    perror("send");
                }
                printf("Server send：%s\n", buffer);
                sleep(1);
                strcpy(buffer, "参数不合法！");
                if ((iret = send(clientfd, buffer, strlen(buffer), 0)) <= 0) // 向客户端发送响应结果。
                {
                    perror("send");
                }
                printf("Server send：%s\n", buffer);
                sleep(1);
            }
            else if("CTS" == SpecialOrder)
            {
                strcpy(buffer, "收到结束服务端命令，服务端已停止 Bye...");
                if ((iret = send(clientfd, buffer, strlen(buffer), 0)) <= 0) // 向客户端发送响应结果。
                {
                    perror("send");
                }
                printf("Server send：%s\n", buffer);
                    close(listenfd);
                    close(clientfd);
                return 2;
            }
            else
            {
                
            }

                // strcpy(buffer, "服务端收到Message");
                // if ((iret = send(clientfd, buffer, strlen(buffer), 0)) <= 0) // 向客户端发送响应结果。
                // {
                //     perror("send");
                //     break;
                // }
                // printf("Server send：%s\n", buffer);
        }
    }
    else
    {
        while (1)
        {
            int iret;
            memset(buffer, 0, sizeof(buffer));
            if ((iret = recv(clientfd, buffer, sizeof(buffer), 0)) <= 0) // 接收客户端的请求报文。
            {
                //printf("iret=%d\n", iret);
                break;
            }
            printf("Server receives：%s\n", buffer);
            
            SpecialOrder = buffer;
            
            if("apply" == SpecialOrder)
            {
                strcpy(buffer, "收到客户端传输申请，服务端同意！");
                if ((iret = send(clientfd, buffer, strlen(buffer), 0)) <= 0) // 向客户端发送响应结果。
                {
                    //perror("send");
                }
                printf("Server send：%s\n", buffer);
                sleep(1);
                strcpy(buffer, "111");
                if ((iret = send(clientfd, buffer, strlen(buffer), 0)) <= 0) // 向客户端发送响应结果。
                {
                    
                }
                sleep(1);
            }
            else if("applyErr" == SpecialOrder)
            {
                strcpy(buffer, "收到客户端传输申请，服务端拒绝了申请！");
                if ((iret = send(clientfd, buffer, strlen(buffer), 0)) <= 0) // 向客户端发送响应结果。
                {
                    perror("send");
                }
                printf("Server send：%s\n", buffer);
                sleep(1);
                strcpy(buffer, "参数不合法！");
                if ((iret = send(clientfd, buffer, strlen(buffer), 0)) <= 0) // 向客户端发送响应结果。
                {
                    perror("send");
                }
                printf("Server send：%s\n", buffer);
                sleep(1);
            }
            else if("CTS" == SpecialOrder)
            {
                strcpy(buffer, "收到结束服务端命令，服务端已停止 Bye...");
                if ((iret = send(clientfd, buffer, strlen(buffer), 0)) <= 0) // 向客户端发送响应结果。
                {
                    perror("send");
                }
                printf("Server send：%s\n", buffer);
                    close(listenfd);
                    close(clientfd);
                return 2;
            }
            else
            {
                
            }

                // strcpy(buffer, "服务端收到Message");
                // if ((iret = send(clientfd, buffer, strlen(buffer), 0)) <= 0) // 向客户端发送响应结果。
                // {
                //     perror("send");
                //     break;
                // }
                // printf("Server send：%s\n", buffer);

            
            
        }
    }
    
// 第6步：关闭socket，释放资源。
    close(listenfd);
    close(clientfd);
    
}
