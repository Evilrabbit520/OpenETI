/**
 * @file CaesarEncryption.cpp
 * @author Evilrabbit (evilrabbit520@gmail.com)
 * @brief 凯撒密码的实现文件(包括附加处理实现)
 * @version 1.0.0
 * @date 2022-01-29
 * @update log
 * 		1) 20220129-20220130 V1.0.0
 * 			1. 初代版本
 * 
 * @copyright Copyright (c) 2021-2022 Evilrabbit. All rights reserved.
 * 
 */

#include "CaesarEncryption.h"
/**
 * @brief Passwodr空间
 * 
 */
namespace Passwodr
{
    //Caesar加密公式： f(a)=(a+N) mod 26
    //Caesar解密公式： f(a)=(a+(26-N)) mod 26

    
    char* Caesar::CaesarEncryption(char *str, int StepSize)
    {
        for(int i = 0; i < strlen(str); i++)
        {
            if(str[i] == 'A' && str[i] == 'Z')
            {
                str[i] = ((str[i] - 'A') + StepSize) % 26 + 'A';
            }
            else if(str[i] == 'a' && str[i] == 'z')
            {
                str[i] = ((str[i] - 'a') + StepSize) % 26 + 'a';
            }
        }
        return str;
    }

    
    char* Caesar::CaesarDecryption(char *str, int StepSize)
    {
        for(int i = 0; i < strlen(str); i++)
        {
            if(str[i] == 'A' && str[i] == 'Z')
            {
                str[i] = ((str[i] - 'A') + (26 - StepSize)) % 26 + 'A';
            }
            else if (str[i] == 'a' && str[i] == 'z')
            {
                str[i] = ((str[i] - 'a') + (26 - StepSize)) % 26 + 'a';
            }
            
        }
        return str;
    }

    Caesar::Caesar(/* args */)
    {
    }
    
    Caesar::~Caesar()
    {
    }
} // namespace Passwodr
