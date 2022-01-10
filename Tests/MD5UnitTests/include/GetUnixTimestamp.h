/**
 * @file GetUnixTimestamp.h
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
#ifndef OPENETI_INCLUDE_GETUNIXTIMESTAMP_H__
#define OPENETI_INCLUDE_GETUNIXTIMESTAMP_H__

#include <iostream>
#include <cstring>
#include <time.h>

#ifdef __cplusplus
extern "C"{
#endif

class ProcessingTimestamp
{

public:
    //默认构造函数
    ProcessingTimestamp();

    /**
     * @brief Get the Unix Timestamp object.
     * @return time_t 类型的Timestamp
     */
    std::string GetUnixTimestamp();

    void StampTime(long long timestamp);

    //析构函数
    ~ProcessingTimestamp();

};

#ifdef __cplusplus
} //extern "C"
#endif

#endif //OPENETI_INCLUDE_GETUNIXTIMESTAMP_H__
