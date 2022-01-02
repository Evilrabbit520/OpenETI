信息加密传输(Encrypted transmission of information(ETI))

# OpenETI

[![License](https://img.shields.io/badge/license-BSD--3--Clause-blue.svg)](hhttps://opensource.org/licenses/BSD-3-Clause)


With the rapid development and improvement of modern communication technology, people's needs for network transmission security are self-evident, and various ways of network stealing have become prominent security issues for users and enterprises (institutions). String encryption and transmission have also become the basic unit of network transmission security, playing a vital role. String encryption and transmission security have become an important prerequisite for determining network transmission security.

随着现代通信技术的高速发展和完善，人们对网络传输安全的需求不言而喻，各种各样的网络窃密方式成为用户和企（事）业单位的突出安全问题。字符串加密及传输也成为了网络传输安全的基本单元，发挥着至关重要的作用。字符串的加密及传输安全保障已然成了决定网络传输安全保障的重要先决条件。

**QQ技术交流群：864265068(超多大佬)**

## Build

1. Manually build

`cd` enter the `build` directory and use `cmake -DCMAKE_CXX_FLAGS=-std=c++20 -Wall -Werror ..` to build(Because `if constexpr()` is used in the code, be sure to use C++17 and above standards to build the code.).

2. Build with script files

Run `sh Build.sh` (currently only macOS is supported, other platforms are welcome to improve).

1. 手动构建

`cd` 进入 `build` 目录使用 `cmake -DCMAKE_CXX_FLAGS=-std=c++20 -Wall -Werror ..` 构建（因为代码中使用了`if constexpr()`请务必使用C++17及以上标准构建代码。）.

2. 利用脚本文件构建

运行`sh Build.sh`（目前只支持macOS，其他平台欢迎完善）。

## License

BSD 3 Clause