信息加密传输(Encrypted transmission of information(ETI))

# OpenETI

[![License](https://img.shields.io/badge/license-BSD--3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)


With the rapid development and improvement of modern communication technology, people's needs for network transmission security are self-evident, and various ways of network stealing have become prominent security issues for users and enterprises (institutions). String encryption and transmission have also become the basic unit of network transmission security, playing a vital role. String encryption and transmission security have become an important prerequisite for determining network transmission security.

随着现代通信技术的高速发展和完善，人们对网络传输安全的需求不言而喻，各种各样的网络窃密方式成为用户和企（事）业单位的突出安全问题。字符串加密及传输也成为了网络传输安全的基本单元，发挥着至关重要的作用。字符串的加密及传输安全保障已然成了决定网络传输安全保障的重要先决条件。

**QQ技术交流群：864265068(超多大佬)**

## Build

The original build of the macOS uses the vscode of the M1 chip, we recommend that it is best to compile with vscode.

``` sh
#MacOS ARM or Intel

cd <OpenETI-root-dir>
cd build

cmake -DCMAKE_OSX_ARCHITECTURES="[x86_64][arm64]" ..

make -j4

```

## The current construction status of each platform.

| System | CPU (32bit) | CPU (64bit) |
| :---: | :---: | :---: |
| Linux (GCC) | [![Build Status](https://img.shields.io/github/workflow/status/Tencent/ncnn/linux-x86-cpu-gcc)](https://github.com/Tencent/ncnn/actions?query=workflow%3Alinux-x86-cpu-gcc) | [![Build Status](https://img.shields.io/github/workflow/status/Tencent/ncnn/linux-x64-cpu-gcc)](https://github.com/Tencent/ncnn/actions?query=workflow%3Alinux-x64-cpu-gcc) |
| Linux (Clang) | [![Build Status](https://img.shields.io/github/workflow/status/Tencent/ncnn/linux-x86-cpu-gcc)](https://github.com/Tencent/ncnn/actions?query=workflow%3Alinux-x86-cpu-gcc) | [![Build Status](https://img.shields.io/github/workflow/status/Tencent/ncnn/linux-x64-cpu-gcc)](https://github.com/Tencent/ncnn/actions?query=workflow%3Alinux-x64-cpu-gcc) |
| Windows (VS2017) | [![Build Status](https://img.shields.io/github/workflow/status/Tencent/ncnn/linux-x86-cpu-gcc)](https://github.com/Tencent/ncnn/actions?query=workflow%3Alinux-x86-cpu-gcc) | [![Build Status](https://img.shields.io/github/workflow/status/Tencent/ncnn/linux-x64-cpu-gcc)](https://github.com/Tencent/ncnn/actions?query=workflow%3Alinux-x64-cpu-gcc) |
| Windows (VS2019) | [![Build Status](https://img.shields.io/github/workflow/status/Tencent/ncnn/linux-x86-cpu-gcc)](https://github.com/Tencent/ncnn/actions?query=workflow%3Alinux-x86-cpu-gcc) | [![Build Status](https://img.shields.io/github/workflow/status/Tencent/ncnn/linux-x64-cpu-gcc)](https://github.com/Tencent/ncnn/actions?query=workflow%3Alinux-x64-cpu-gcc) |
| macOS | [![Build Status](https://img.shields.io/github/workflow/status/Tencent/ncnn/linux-x86-cpu-gcc)](https://github.com/Tencent/ncnn/actions?query=workflow%3Alinux-x86-cpu-gcc) | [![Build Status](https://img.shields.io/github/workflow/status/Tencent/ncnn/linux-x64-cpu-gcc)](https://github.com/Tencent/ncnn/actions?query=workflow%3Alinux-x64-cpu-gcc) |
| macOS(ARM) | [![Build Status](https://img.shields.io/github/workflow/status/Tencent/ncnn/linux-x86-cpu-gcc)](https://github.com/Tencent/ncnn/actions?query=workflow%3Alinux-x86-cpu-gcc) | [![Build Status](https://img.shields.io/github/workflow/status/Tencent/ncnn/linux-x64-cpu-gcc)](https://github.com/Tencent/ncnn/actions?query=workflow%3Alinux-x64-cpu-gcc) |
| Android | - | - |

## License

[BSD 3 Clause](https://opensource.org/licenses/BSD-3-Clause)