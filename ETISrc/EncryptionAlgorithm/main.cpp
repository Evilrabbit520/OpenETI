/**
 * @file main.cpp
 * @author Evilrabbit (evilrabbit520@gmail.com)
 * @brief Temporary files copied.
 * @version 1.0.1
 * @date 2021-12-29
 * 
 * @copyright Copyright (c) 2021 Evilrabbit. All rights reserved.
 * 
 */

#include <iostream>

#include "main.h"
#include "md5.h"

using namespace std;

void hello()
{
    string zf;
    cin >> zf;
    cout << "md5 of " << zf << ": " << md5(zf, "lower") << endl;
    cout << endl;
    cout << "md5 of " << zf << ": " << md5(zf, "upper") << endl;
};

int sum(int a,int b)
{
    return (a+b);
};