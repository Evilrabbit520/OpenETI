/**
 * @file GetUnixTimestamp.cpp
 * @author Evilrabbit (evilrabbit520@gmail.com)
 * @brief Get Unix timestamp.
 * @version 1.0.0
 * @date 2021-12-29
 * @update log
 * 		1) 20220109-20220110 V1.0.0
 * 			1. 初代版本
 * 
 * @copyright Copyright (c) 2021-2022 Evilrabbit. All rights reserved.
 * 
 */

#include "GetUnixTimestamp.h"

ProcessingTimestamp::ProcessingTimestamp()
{

}

ProcessingTimestamp::~ProcessingTimestamp()
{

}

std::string ProcessingTimestamp::GetUnixTimestamp()
{
    /* Return the current time and put it in *TIMER if TIMER is not NULL.  */
    //来自time.h。这里用函数返回值的方式获取Timestamp。
    time_t Timestamp = time(NULL);
	unsigned long long time = (unsigned long long)Timestamp;
	return std::to_string(time);
}

std::string StampTime(long long timestamp)
{
    int ms = timestamp % 1000;//取毫秒
	time_t tick = (time_t)(timestamp/1000);//转换时间
	struct tm tm;
	char s[40];
	tm = *localtime(&tick);
	strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", &tm);
	std::string str(s);
	str = str+ " " + std::to_string(ms);
	return str;
}