/**
 * @file sha256.cpp
 * @author Evilrabbit (evilrabbit520@gmail.com)
 * @brief SHA256算法实现
 * @version 1.0.0
 * @date 2021-12-29
 * @update log
 * 		1) 20220103-20220104 V1.0.0
 * 			1. 初代版本
 * @attention 
 *      1）输入信息中有中文时，得到的数字指纹与使用SHA256在线加密工具得到数字指纹可能不相同。原因是中文的编码方式不同。
 * 
 * 
 * @copyright Copyright (c) 2021-2022 Evilrabbit. All rights reserved.
 * 
 */

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

#include "sha256.hpp"

/**
 * @brief Hash散列包含空间
 * 
 */
namespace Hash
{

std::vector<uint32_t> SHA256::initial_message_digest_ = 
{ 
    0x6a09e667, 0xbb67ae85, 0x3c6ef372,
    0xa54ff53a, 0x510e527f, 0x9b05688c,
    0x1f83d9ab, 0x5be0cd19 
};

std::vector<uint32_t> SHA256::add_constant_ = 
{
    0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
    0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
    0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
    0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
    0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
    0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
    0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
    0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
};

bool SHA256::encrypt(const std::vector<uint8_t>& input_message, std::vector<uint8_t>* _digest)
{
    if (!input_message.empty() && _digest)
    {
        // 文本预处理
        std::vector<uint8_t> message = input_message;
        preprocessing(&message);

        // 将文本分解成连续的64Byte大小的数据块
        std::vector<std::vector<uint8_t>> chunks;
        breakTextInto64ByteChunks(message, &chunks);

        // 由64Byte大小的数据块，构造出64个4Byte大小的字。然后进行循环迭代。
        std::vector<uint32_t> message_digest(initial_message_digest_); // 初始化信息摘要

        std::vector<uint32_t> words;
        for (const auto& chunk : chunks)
        {
            structureWords(chunk, &words);
            transform(words, &message_digest);
        }

        // 获取最终结果
        produceFinalHashValue(message_digest, _digest);

        return true;
    }
    else
    {
        return false;
    }
}

std::string SHA256::getHexMessageDigest(const std::string& message)
{
    if (!message.empty())
    {
        std::vector<uint8_t> __message;
        for (auto it = message.begin(); it != message.end(); ++it)
        {
            __message.push_back(static_cast<uint8_t>(*it));
        }

        std::vector<uint8_t> digest;
        encrypt(__message, &digest);

        std::ostringstream o_s;
        o_s << std::hex << std::setiosflags(std::ios::uppercase);
        for (auto it = digest.begin(); it != digest.end(); ++it)
        {
            o_s << std::setw(2) << std::setfill('0')
                << static_cast<unsigned short>(*it);
        }

        return o_s.str();
    }
    else
    {
        return "";
    }
}

bool SHA256::preprocessing(std::vector<uint8_t>* _message) const
{
    if (_message)
    {
        const uint64_t original_bit_size = _message->size() * 8;

        //! 附加填充比特
        size_t remainder = _message->size() % 64;
        if (remainder < 56)
        {
            _message->push_back(0x80); // ox80 == 10000000
            for (size_t i = 1; i < 56 - remainder; ++i)
            {
                _message->push_back(0x00);
            }
        }
        else if (remainder == 56)
        {
            _message->push_back(0x80);
            for (size_t i = 1; i < 64; ++i)
            {
                _message->push_back(0x00);
            }
        }
        else
        {
            _message->push_back(0x80);
            for (size_t i = 1; i < 64 - remainder + 56; ++i)
            {
                _message->push_back(0x00);
            }
        }

        //! 附加原始文本的长度值
        for (int i = 1; i <= 8; ++i)
        {
            uint8_t c = static_cast<uint8_t>(original_bit_size >> (64 - 8 * i));
            _message->push_back(c);
        }

        return true;
    }
    else
    {
        return false;
    }
}

bool SHA256::breakTextInto64ByteChunks(const std::vector<uint8_t>& message, 
    std::vector<std::vector<uint8_t>>* _chunks) const
{
    if (_chunks && 0 == message.size() % 64)
    {
        _chunks->clear(); // 清空输出buffer

        size_t quotient = message.size() / 64;
        for (size_t i = 0; i < quotient; ++i)
        {
            std::vector<uint8_t> temp(message.begin() + i * 64, message.begin() + (i + 1) * 64);
            _chunks->push_back(temp);
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool SHA256::structureWords(const std::vector<uint8_t>& chunk, std::vector<uint32_t>* _words) const
{
    if (_words && 64 == chunk.size())
    {
        _words->resize(64);

        auto& words = *_words;
        for (int i = 0; i < 16; ++i)
        {
            words[i] = (static_cast<uint32_t>(chunk[i * 4]) << 24)
                       | (static_cast<uint32_t>(chunk[i * 4 + 1]) << 16)
                       | (static_cast<uint32_t>(chunk[i * 4 + 2]) << 8)
                       | static_cast<uint32_t>(chunk[i * 4 + 3]);
        }
        for (int i = 16; i < 64; ++i)
        {
            words[i] = small_sigma1(words[i - 2]) 
                + words[i - 7] 
                + small_sigma0(words[i - 15]) 
                + words[i - 16];
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool SHA256::transform(const std::vector<uint32_t>& words, std::vector<uint32_t>* _message_digest) const
{
    if (_message_digest && 8 == _message_digest->size() && 64 == words.size())
    {
        std::vector<uint32_t> d = *_message_digest;

        for (int i = 0; i < 64; ++i)
        {
            uint32_t temp1 = d[7] + big_sigma1(d[4]) + ch(d[4], d[5], d[6]) + add_constant_[i] + words[i];
            uint32_t temp2 = big_sigma0(d[0]) + maj(d[0], d[1], d[2]);
            
            d[7] = d[6];
            d[6] = d[5];
            d[5] = d[4];
            d[4] = d[3] + temp1;
            d[3] = d[2];
            d[2] = d[1];
            d[1] = d[0];
            d[0] = temp1 + temp2;
        }

        for (int i = 0; i < 8; ++i)
        {
            (*_message_digest)[i] += d[i];
        }

        return true;
    }
    else
    {
        return false;
    }
}

bool SHA256::produceFinalHashValue(const std::vector<uint32_t>& input, std::vector<uint8_t>* _output) const
{
    if (_output)
    {
        _output->clear();

        for (auto it = input.begin(); it != input.end(); ++it)
        {
            for (int i = 0; i < 4; i++)
            {
                _output->push_back(static_cast<uint8_t>((*it) >> (24 - 8 * i)));
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

} // namespace Hash
