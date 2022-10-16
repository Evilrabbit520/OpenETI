/**
 * @file main.cpp
 * @author Evilrabbit (evilrabbit520@gmail.com)
 * @brief 主函数
 * @version 1.0.0
 * @date 2022-10-09
 * @update log
 * 		1) 20221009 V1.0.0
 * 			1. 初代版本
 * 
 * @copyright Copyright (c) 2021-2022 Evilrabbit. All rights reserved.
 * 
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include "src/Createsocket.h"

int main()
{
    char host[100];
    //scanf("%s", host);
    std::cin.getline(host,99);
    //host = "strn";
    CreateSocket(host, sizeof(host));
    return 0;
}