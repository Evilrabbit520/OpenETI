/**
 * @file sha256.hpp
 * @author Evilrabbit (evilrabbit520@gmail.com)
 * @brief SHA256算法定义
 * @version 1.0.0
 * @date 2021-12-29
 * @update log
 * 		1) 20220103-20220104 V1.0.0
 * 			1. 初代版本
 * @attention 
 *      1）输入信息中有中文时，得到的数字指纹与使用SHA256在线加密工具得到数字指纹可能不相同。原因是中文的编码方式不同。
 * 
 * @copyright Copyright (c) 2021-2022 Evilrabbit. All rights reserved.
 * 
 */

#ifndef OPENETI_INCLUDE_CAESARENCRYPTION_HPP__
#define OPENETI_INCLUDE_CAESARENCRYPTION_HPP__

#include <iostream>
#include <cstring>

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Passwodr空间
 * 
 */
namespace Passwodr
{
    //Caesar加密公式： f(a)=(a+N) mod 26
    //Caesar解密公式： f(a)=(a+(26-N)) mod 26
    class Caesar
    {
    private:
        /* data */
    public:
        Caesar(/* args */);
        char* CaesarEncryption(char *str, int StepSize);
        char* CaesarDecryption(char *str, int StepSize);
        ~Caesar();
    };
    
    
    

} // namespace Passwodr





#ifdef __cplusplus
} //extern "C"
#endif

#endif //OPENETI_INCLUDE_CAESARENCRYPTION_HPP__