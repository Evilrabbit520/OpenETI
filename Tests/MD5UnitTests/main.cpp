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
#include "include/json.hpp"
#include "include/sha256.hpp"
#include "include/GetUnixTimestamp.h"
#include "include/RSA.h"

using namespace std;
using json = nlohmann::json;



void TestString() {
	RSA rsa;
	Key key = rsa.GetKey();
	std::string strin;
	std::cout << "输入加密信息" << std::endl;
	std::cin >> strin;
	std::vector<long> strecrept = rsa.Ecrept(strin, key.public_key, key.share_key);
	std::string strout = rsa.DEcrept(strecrept, key.private_key, key.share_key);
	std::cout << "加密信息" << std::endl;
	rsa.PrintInfo(strecrept);
	std::cout << "解密信息" << std::endl;
	std::cout << strout << std::endl;
}

int main()
{
    // time_t times = time(0);
    // char Arrs[255];
    // strftime(Arrs, sizeof(Arrs), "%Y-%m-%d-%H-%M-%S",localtime(&times));
    // time_t result = std::time(nullptr);
    // cout << std::asctime(std::localtime(&result));
    // stringstream strtime;
    // time_t timep;
    // time (&timep);
    // char tmp[64];
    // strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep) );
    // cout << tmp << endl;

    // time_t timep;
    // time (&timep);
    // char tArr[255];
    // strftime(tArr, sizeof(tArr), "%Y-%m-%d %H:%M:%S", localtime(&timep));
    // cout << tArr << endl;
    
    // create JSON values

    // json object = {{"one", 1}, {"two", 2}};
    // object["psw"] = "ccc";

    // // print values
    // std::cout << object << '\n';

    // time_t ti;
    // time(&ti);
    // char aArr[255];
    // strftime(aArr, sizeof(aArr), "%Y-%m-%d %H:%M:%S", localtime(&ti));

    //cout << Hash::md5("zzz", "lower") << endl;
    TestString();


	return 0;
}