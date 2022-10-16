/**
 * @file Createsocket.h
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

#ifndef OETI_PRIVATEINCL_CREATESOCKET_H__
#define OETI_PRIVATEINCL_CREATESOCKET_H__

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#ifdef __cplusplus
extern "C"{
#endif

int CreateSocket(char *message, int mseeage_len);

#ifdef __cplusplus
} //extern "C"
#endif

#endif //OETI_PRIVATEINCL_CREATESOCKET_H__
