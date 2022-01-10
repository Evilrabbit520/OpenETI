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

void ProcessingTimestamp::StampTime(long long UnixTimestamp)
{
    struct tm *time;
    uint16_t year, yday;
    uint8_t month, day, week, hour, minute, second;
    time_t timestamp = UnixTimestamp;

    //调用系统函数
    time = localtime(&timestamp);

    year = time->tm_year;
    month = time->tm_mon;
    week = time->tm_wday;
    yday = time->tm_mday;
    day = time->tm_mday;
    hour = time->tm_hour;
    minute = time->tm_min;
    second = time->tm_sec;

    /* 时间校正 */
    year += 1900;
    month += 1;
    
    std::cout << "UNIX时间戳: " << timestamp << std::endl;
    printf("日期:%d-%d-%d 第%d天 星期%d 时间:%d:%d:%d\r\n",
        year, month, day, yday, week, hour, minute, second);
    
    const int cMessbt = 50;
    char *str = new char[cMessbt];
    strftime(str, cMessbt, "%F %T", time);
    std::cout << str << std::endl;
    delete []str;
}