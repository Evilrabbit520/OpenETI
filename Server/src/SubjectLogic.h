/**
 * @file SubjectLogic.h
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

#ifndef OETI_PRIVATEINCL_SUBJECTLOGIC_H__
#define OETI_PRIVATEINCL_SUBJECTLOGIC_H__

#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include <iostream>


#ifdef __cplusplus
extern "C"{
#endif


class Container
{
private:
    /**
     * @brief 实现噪声随机数的获得和处理
     * 
     * @param RandomNum 通过嵌入式设备获得
     * @return 经过处理的真随机整数
     */
    int RandomNumber();

    /**
     * @brief 初始化容器唯一标识符
     * 
     * @return 容器标识符
     */
    int MBId();

    /**
     * @brief 混淆值
     * 
     */
    char* ConNameKey = "rq";
    //std::string ConNameKey = "rq";
public:
    Container(/* args */);

    /**
     * @brief 生成消息容器
     * 
     * @param NULL
     * @return 返回一个容器
     */
    std::string MessageBox();

    /**
     * @brief Get the Unix Timestamp object.
     * 
     * @return long long 类型的Timestamp
     */
    long long GetUnixTimestamp();

    ~Container();
};



#ifdef __cplusplus
} //extern "C"
#endif

#endif //OETI_PRIVATEINCL_SUBJECTLOGIC_H__
