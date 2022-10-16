/**
 * @file SubjectLogic.cpp
 * @author Evilrabbit (evilrabbit520@gmail.com)
 * @brief 项目逻辑模块（服务端）
 * @version 1.0.0
 * @date 2022-10-10
 * @update log
 * 		1) 20221010 V1.0.0
 * 			1. 初代版本
 * 
 * @copyright Copyright (c) 2021-2022 Evilrabbit. All rights reserved.
 * 
 */

#include "SubjectLogic.h"





Container::Container()
{
}

Container::~Container()
{
}

int Container::MBId()
{
    static int id=0;
    id++;
    return id;
}

long long Container::GetUnixTimestamp()
{
    // Return the current time and put it in *TIMER if TIMER is not NULL.
    // 来自time.h。这里用函数返回值的方式获取Timestamp。
    time_t Timestamp = time(NULL);
	unsigned long long time = (unsigned long long)Timestamp;
	return time;

}

int Container::RandomNumber()
{

}

std::string Container::MessageBox()
{
    int RandomNum = rand() % 90 + 10; // 生成临时伪随机数([10～99])
    long long MessageBoxId = MBId() + RandomNum;
    std::string ConName = ConNameKey + std::to_string(MessageBoxId);

    return ConName;
}