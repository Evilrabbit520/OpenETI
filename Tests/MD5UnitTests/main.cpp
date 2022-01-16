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


int main()
{


    ProcessingTimestamp pt;
    cout << pt.GetUnixTimestamp() << endl;

    //pt.StampTime(1641807984);
    long long nnm = 1641817415;
    pt.StampTime(nnm);
    

    //StampTime(1641798930);
	return 0;
}