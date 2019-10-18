/*
  MIT License
  
  Copyright (c) 2019 Sung Gon Kim
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#include <gtest/gtest.h>
#include "snap/string.hpp"

class StringTest : public ::testing::Test {
};

TEST_F(StringTest, startsWith) {
  EXPECT_TRUE(snap::string::startsWith("hello world", "hello"));
  EXPECT_TRUE(snap::string::startsWith("hello world", "hello world"));
  EXPECT_TRUE(snap::string::startsWith("hello world", ""));
  EXPECT_TRUE(snap::string::startsWith("hello world", "\0"));
  EXPECT_TRUE(snap::string::startsWith("", ""));
  EXPECT_TRUE(snap::string::startsWith("\0", ""));
  EXPECT_TRUE(snap::string::startsWith("\0", "\0"));
  EXPECT_FALSE(snap::string::startsWith("hello world", "world"));
  EXPECT_FALSE(snap::string::startsWith("hello world", "???"));

  EXPECT_TRUE(snap::string::startsWith(u8"hello world", u8"hello"));
  EXPECT_TRUE(snap::string::startsWith(u8"hello world", u8"hello world"));
  EXPECT_TRUE(snap::string::startsWith(u8"hello world", u8""));
  EXPECT_TRUE(snap::string::startsWith(u8"hello world", u8"\0"));
  EXPECT_TRUE(snap::string::startsWith(u8"", u8""));
  EXPECT_TRUE(snap::string::startsWith(u8"\0", u8""));
  EXPECT_TRUE(snap::string::startsWith(u8"\0", u8"\0"));
  EXPECT_FALSE(snap::string::startsWith(u8"hello world", u8"world"));
  EXPECT_FALSE(snap::string::startsWith(u8"hello world", u8"???"));

  EXPECT_TRUE(snap::string::startsWith(L"hello world", L"hello"));
  EXPECT_TRUE(snap::string::startsWith(L"hello world", L"hello world"));
  EXPECT_TRUE(snap::string::startsWith(L"hello world", L""));
  EXPECT_TRUE(snap::string::startsWith(L"hello world", L"\0"));
  EXPECT_TRUE(snap::string::startsWith(L"", L""));
  EXPECT_TRUE(snap::string::startsWith(L"\0", L""));
  EXPECT_TRUE(snap::string::startsWith(L"\0", L"\0"));
  EXPECT_FALSE(snap::string::startsWith(L"hello world", L"world"));
  EXPECT_FALSE(snap::string::startsWith(L"hello world", L"???"));
}
