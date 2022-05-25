/**
 * @file RAS.h
 * @author Evilrabbit (evilrabbit520@gmail.com)
 * @brief RAS header file definition.
 * @version 1.0.0
 * @date 2022-05-14
 * @update log
 * 		1) 20220514-20220520 V1.0.0
 * 			1. 初代版本
 * 
 * @copyright Copyright (c) 2021-2022 Evilrabbit. All rights reserved.
 * 
 */

#ifndef OPENETI_INCLUDE_RAS_H__
#define OPENETI_INCLUDE_RAS_H__

#include <cstring>
#include <vector>
#include <iostream>

#ifdef __cplusplus
extern "C"{
#endif

struct Key
{
    //公钥(public_key, share_key)
    long long share_key;
    long long public_key;
    //私钥(private_key, share_key)
    long long private_key;
};

class RSA
{
private:
    //生成一个素数
    long ProducePrime();

    //判断一个素数是否为真
    bool IfPrime(long Prime);

    //生成所有Kye值
    void ProduceKeys();

    //求share_key
    long ProduceShareKey(long prime1, long prime2);

    //根据欧拉函数求乘积
    long ProduceOrla(long prime1, long prime2);

    //求public_key
    long ProducePublicKey(long orla);
    
    //判断两个数之间最大公约是否为1
    long ProduceGcd(long public_key, long orla);

    //求private_key
    long ProducePrivateKey(long public_key, long orla);

    //加密单个信息
    long Ecrept(long msg, long key, long share_key);

public:
    RSA(/* args */);

    Key GetKey()
    {
        return _key;
    }
    //加密字符串
    std::vector<long> Ecrept(std::string& str_in, long public_key, long share_key);
    std::string DEcrept(std::vector<long>& ecrept_str, long private_key, long share_key);

    //加密文件

    //打印结果
    void PrintInfo(std::vector<long>& ecrept_str);
    
    ~RSA();

private:
    Key _key;
};






#ifdef __cplusplus
} //extern "C"
#endif

#endif //OPENETI_INCLUDE_MAIN_H__