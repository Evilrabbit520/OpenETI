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

	return 0;
}
