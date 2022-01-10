/**
 * @file UnitTest/main.cpp
 * @author Evilrabbit (evilrabbit520@gmail.com)
 * @brief Unit test.
 * @version 1.0.1
 * @date 2021-12-29
 * 
 * @copyright Copyright (c) 2021-2022 Evilrabbit. All rights reserved.
 * 
 */
#include <iostream>
#include <cstring>
#include <thread>
#include <time.h>

#include "include/md5.h"
#include "include/sha256.hpp"
#include "include/GetUnixTimestamp.h"

using namespace std;

// template<typename T, typename... Ts>
// void newPrint(T arg1, Ts... arg_left)
// {
//     std::cout<<arg1<<", ";
//     if constexpr(sizeof...(arg_left) > 0)
//     {
//         newPrint(arg_left...);
//     }
// }

// void StampTime(long sss)
// {
//     // int ms = timestamp % 1000;//取毫秒
// 	// time_t tick = (time_t)(timestamp/1000);//转换时间
// 	// struct tm tm;
// 	// char s[40];
// 	// tm = *localtime(&tick);
// 	// strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", &tm);
// 	// std::string str(s);
// 	// str = str+ " " + std::to_string(ms);
// 	// return str;

//     char str[100];
//     struct tm *time;
//     uint16_t year, yday;
//     uint8_t month, day, week, hour, minute, second;
//     time_t timestamp = sss;  /*北京时间2020-06-24 01:16:51*/
// /*
//     几个用于测试的时间戳和北京时间对应
//     1592932611 = 2020-06-24 01:16:51(北京时间) 
//     1593541011 = 2020-07-01 02:16:51
//     1593526611 = 2020-06-30 22:16:51
// */    

//     /* 北京时间补偿 */
//     //timestamp += 8*60*60;
//     /* 调用系统函数 */
//     time = localtime(&timestamp);
    
//     year = time->tm_year;   /* 自1900年算起 */
//     month = time->tm_mon;   /* 从1月算起，范围0-11 */
//     week = time->tm_wday;   /* 从周末算起，范围0-6 */
//     yday = time->tm_yday;  /* 从1月1日算起，范围0-365 */
//     day = time->tm_mday;    /* 日: 1-31 */
//     hour = time->tm_hour;   /* 小时:0-23点,UTC+0时间 */
//     minute = time->tm_min;  /* 分钟:0-59 */
//     second = time->tm_sec;  /* 0-60，偶尔出现的闰秒 */
    
//     /* 时间校正 */
//     year += 1900;
//     month += 1;
//     week += 1;
    
//     printf("UNIX时间戳:%d\r\n", timestamp);
//     printf("日期:%d-%d-%d 第%d天 星期%d 时间:%d:%d:%d\r\n",
//         year, month, day, yday, week, hour, minute, second);
    
//     /* 格式化时间字符串 */
//     strftime(str, 100, "%F %T", time);  /* 2020-07-01 02:16:51 */
// //    strftime(str, 100, "%m-%d %H:%M", time);  /* 06-30 22:16 */
//     printf("%s\r\n", str);

// }

int main()
{
    //hello();
    //newPrint(1, 22, "www");


    // string zf;
    // Hash::SHA256 sha256;
    // cin >> zf;
    // cout << "md5 of " << zf << ": " << Hash::md5(zf, "lower") << endl;
    // cout << endl;
    // cout << "md5 of " << zf << ": " << Hash::md5(zf, "upper") << endl;
    // cout << endl;
    // cout << "sha256 of " << zf << ": " << sha256.getHexMessageDigest(zf) << endl;

    ProcessingTimestamp pt;
    cout << pt.GetUnixTimestamp() << endl;

    //pt.StampTime(1641807984);
    long long nnm = 1641817415;
    pt.StampTime(nnm);
    

    //StampTime(1641798930);
	return 0;
}