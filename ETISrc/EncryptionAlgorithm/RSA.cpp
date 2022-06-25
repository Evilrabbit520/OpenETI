/**
 * @file RSA.cpp
 * @author Evilrabbit (evilrabbit520@gmail.com)
 * @brief RSA source file implementation.
 * @version 1.0.1
 * @date 2022-05-14
 * @update log
 * 		1) 20220514-20220520 V1.0.0
 * 			1. 初代版本
 * 
 * @copyright Copyright (c) 2021-2022 Evilrabbit. All rights reserved.
 * 
 */

#include "RSA.h"

RSA::RSA()
{}

//对字符串加密
std::vector<long> RSA::Ecrept(std::string& str_in, long public_key, long share_key)
{
    std::vector<long> vecout;
    for(const auto& e : str_in)
    {
        vecout.push_back(Ecrept(e, public_key, share_key));
    }
    return vecout;
}

std::string RSA::DEcrept(std::vector<long>& ecrept_str, long private_key, long share_key)
{
    std::string strout;
    for(const auto& e : ecrept_str)
    {
        strout.push_back((char)Ecrept(e, private_key, share_key));
    }
    return strout;
}

void RSA::PrintInfo(std::vector<long>& ecrept_str)
{
    for(const auto& e : ecrept_str)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

//生成一个素数
long RSA::ProducePrime()
{
    srand(time(nullptr));
    long prime = 0;
    while(1)
    {
        prime = rand() % 50 + 2;
        if(IfPrime(prime))
        {
            break;
        }
    }
    return prime;
}

//判断一个数是否为素数
bool RSA::IfPrime(long Prime)
{
    if(Prime < 2)
    {
        return false;
    }
    for(int i = 3; i < sqrt(Prime); ++i)
    {
        if(Prime % i == 0)
        {
            return false;
        }
    }
    return true;
}

//生成所有Kye值
void RSA::ProduceKeys()
{
    //选择两个不相等的素数
    long prime1 = ProducePrime();
    long prime2 = ProducePrime();
    while (prime1 == prime2)
    {
        prime2 = ProducePrime();
    }
    _key.share_key = ProduceShareKey(prime1, prime2);
    long orla = ProduceOrla(prime1, prime2);
    _key.public_key = ProducePublicKey(orla);
    _key.private_key = ProducePrivateKey(_key.public_key, orla);
}

//求share_key
long RSA::ProduceShareKey(long prime1, long prime2)
{
    return prime1 * prime2;
}

//根据欧拉函数求乘积
long RSA::ProduceOrla(long prime1, long prime2)
{
    return (prime1 - 1) * (prime2 - 1);
}

//求public_key，随机选择一个数， 1 < public_key < orla，public_key,oala互质
long RSA::ProducePublicKey(long orla)
{
    long public_key;
    srand(time(nullptr));
    while(1){
        public_key = rand() % orla;
        if (public_key > 1 && ProduceGcd(public_key, orla) == 1)
			break;
    }
    return public_key;
}

//判断两个数之间最大公约是否为1
    long ProduceGcd(long public_key, long orla)
    {
        long residual;
        while (residual = public_key % orla)
        {
<<<<<<< HEAD
            public_key = orla;
		    orla = residual;
        }
        return orla;
=======
            if(public_key
        }
        

>>>>>>> b4f50665e725c7f14e4a95a22dd9d8361cf84075
    }

//求private_key
long ProducePrivateKey(long public_key, long orla)
{
    long private_key = orla / public_key;
    while (1)
    {
        if((private_key * public_key) % orla == 1)
            break;
    }
    ++private_key;
    return private_key;
<<<<<<< HEAD

}

//加密单个信息，模幂运算
long RSA::Ecrept(long msg, long key, long share_key){
	long msg_out = 1;
	long a = msg;
	long b = key;
	int c = share_key;
	while (b){
		if (b & 1){
			//msg_out = (A0*A1...Ai...An) % c
			msg_out = (msg_out * a) % c;
		}
		b >>= 1;
		a = (a * a) % c;
	}
	return msg_out;
}
=======
>>>>>>> b4f50665e725c7f14e4a95a22dd9d8361cf84075

//打印加密之后的信息
void RSA::PrintInfo(std::vector<long>& ecrept_str) {
	for (const auto& e : ecrept_str){
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

// //加密单个信息
// long RSA::Ecrept(long msg, long key, long share_key)
// {

// }


RSA::~RSA()
{}
