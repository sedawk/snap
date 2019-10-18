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
#include <string>
#include <vector>
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

TEST_F(StringTest, endsWith) {
  EXPECT_TRUE(snap::string::endsWith("hello world", "world"));
  EXPECT_TRUE(snap::string::endsWith("hello world", "hello world"));
  EXPECT_TRUE(snap::string::endsWith("hello world", ""));
  EXPECT_TRUE(snap::string::endsWith("hello world", "\0"));
  EXPECT_TRUE(snap::string::endsWith("", ""));
  EXPECT_TRUE(snap::string::endsWith("\0", ""));
  EXPECT_TRUE(snap::string::endsWith("\0", "\0"));
  EXPECT_FALSE(snap::string::endsWith("hello world", "hello"));
  EXPECT_FALSE(snap::string::endsWith("hello world", "???"));
  
  EXPECT_TRUE(snap::string::endsWith(u8"hello world", u8"world"));
  EXPECT_TRUE(snap::string::endsWith(u8"hello world", u8"hello world"));
  EXPECT_TRUE(snap::string::endsWith(u8"hello world", u8""));
  EXPECT_TRUE(snap::string::endsWith(u8"hello world", u8"\0"));
  EXPECT_TRUE(snap::string::endsWith(u8"", u8""));
  EXPECT_TRUE(snap::string::endsWith(u8"\0", u8""));
  EXPECT_TRUE(snap::string::endsWith(u8"\0", u8"\0"));
  EXPECT_FALSE(snap::string::endsWith(u8"hello world", u8"hello"));
  EXPECT_FALSE(snap::string::endsWith(u8"hello world", u8"???"));
  
  EXPECT_TRUE(snap::string::endsWith(L"hello world", L"world"));
  EXPECT_TRUE(snap::string::endsWith(L"hello world", L"hello world"));
  EXPECT_TRUE(snap::string::endsWith(L"hello world", L""));
  EXPECT_TRUE(snap::string::endsWith(L"hello world", L"\0"));
  EXPECT_TRUE(snap::string::endsWith(L"", L""));
  EXPECT_TRUE(snap::string::endsWith(L"\0", L""));
  EXPECT_TRUE(snap::string::endsWith(L"\0", L"\0"));
  EXPECT_FALSE(snap::string::endsWith(L"hello world", L"hello"));
  EXPECT_FALSE(snap::string::endsWith(L"hello world", L"???"));
}

TEST_F(StringTest, upper) {
  EXPECT_EQ("HELLO", snap::string::upper("hello"));
  EXPECT_EQ("HELLO", snap::string::upper("HELLO"));
  EXPECT_EQ(" ", snap::string::upper(" "));
  EXPECT_EQ("", snap::string::upper(""));
  EXPECT_EQ("한글", snap::string::upper("한글"));
  EXPECT_EQ("\0", snap::string::upper("\0"));
  
  EXPECT_EQ(u8"HELLO", snap::string::upper(u8"hello"));
  EXPECT_EQ(u8"HELLO", snap::string::upper(u8"HELLO"));
  EXPECT_EQ(u8" ", snap::string::upper(u8" "));
  EXPECT_EQ(u8"", snap::string::upper(u8""));
  EXPECT_EQ(u8"한글", snap::string::upper(u8"한글"));
  EXPECT_EQ(u8"\0", snap::string::upper(u8"\0"));
  
  EXPECT_EQ(L"HELLO", snap::string::upper(L"hello"));
  EXPECT_EQ(L"HELLO", snap::string::upper(L"HELLO"));
  EXPECT_EQ(L" ", snap::string::upper(L" "));
  EXPECT_EQ(L"", snap::string::upper(L""));
  EXPECT_EQ(L"한글", snap::string::upper(L"한글"));
  EXPECT_EQ(L"\0", snap::string::upper(L"\0"));
}

TEST_F(StringTest, lower) {
  EXPECT_EQ("hello", snap::string::lower("HELLO"));
  EXPECT_EQ("hello", snap::string::lower("hello"));
  EXPECT_EQ(" ", snap::string::lower(" "));
  EXPECT_EQ("", snap::string::lower(""));
  EXPECT_EQ("한글", snap::string::lower("한글"));
  EXPECT_EQ("\0", snap::string::lower("\0"));
  
  EXPECT_EQ(u8"hello", snap::string::lower(u8"HELLO"));
  EXPECT_EQ(u8"hello", snap::string::lower(u8"hello"));
  EXPECT_EQ(u8" ", snap::string::lower(u8" "));
  EXPECT_EQ(u8"", snap::string::lower(u8""));
  EXPECT_EQ(u8"한글", snap::string::lower(u8"한글"));
  EXPECT_EQ(u8"\0", snap::string::lower(u8"\0"));

  EXPECT_EQ(L"hello", snap::string::lower(L"HELLO"));
  EXPECT_EQ(L"hello", snap::string::lower(L"hello"));
  EXPECT_EQ(L" ", snap::string::lower(L" "));
  EXPECT_EQ(L"", snap::string::lower(L""));
  EXPECT_EQ(L"한글", snap::string::lower(L"한글"));
  EXPECT_EQ(L"\0", snap::string::lower(L"\0"));
}

TEST_F(StringTest, ltrim) {
  EXPECT_EQ("hello", snap::string::ltrim("hello"));
  EXPECT_EQ("hello", snap::string::ltrim(" \r\t hello"));
  EXPECT_EQ("hello ", snap::string::ltrim(" \r\t hello "));
  EXPECT_EQ("", snap::string::ltrim(" \r\t "));
  EXPECT_EQ("", snap::string::ltrim(""));
  EXPECT_EQ("\0", snap::string::ltrim("\0"));
  
  EXPECT_EQ(u8"hello", snap::string::ltrim(u8"hello"));
  EXPECT_EQ(u8"hello", snap::string::ltrim(u8" \r\t hello"));
  EXPECT_EQ(u8"hello ", snap::string::ltrim(u8" \r\t hello "));
  EXPECT_EQ(u8"", snap::string::ltrim(u8" \r\t "));
  EXPECT_EQ(u8"", snap::string::ltrim(u8""));
  EXPECT_EQ(u8"\0", snap::string::ltrim(u8"\0"));
  
  EXPECT_EQ(L"hello", snap::string::ltrim(L"hello"));
  EXPECT_EQ(L"hello", snap::string::ltrim(L" \r\t hello"));
  EXPECT_EQ(L"hello ", snap::string::ltrim(L" \r\t hello "));
  EXPECT_EQ(L"", snap::string::ltrim(L" \r\t "));
  EXPECT_EQ(L"", snap::string::ltrim(L""));
  EXPECT_EQ(L"\0", snap::string::ltrim(L"\0"));
}

TEST_F(StringTest, ltrimWithChar) {
  EXPECT_EQ("hello", snap::string::ltrim(" hello", L' '));
  EXPECT_EQ("hello", snap::string::ltrim("/hello", L'/'));
  EXPECT_EQ(" hello", snap::string::ltrim(" hello", L'?'));
  EXPECT_EQ("", snap::string::ltrim("  ", L' '));
  EXPECT_EQ("", snap::string::ltrim("", L'\0'));
  EXPECT_EQ("\0", snap::string::ltrim("\0", L' '));

  EXPECT_EQ(u8"hello", snap::string::ltrim(u8" hello", L' '));
  EXPECT_EQ(u8"hello", snap::string::ltrim(u8"/hello", L'/'));
  EXPECT_EQ(u8" hello", snap::string::ltrim(u8" hello", L'?'));
  EXPECT_EQ(u8"", snap::string::ltrim(u8"  ", L' '));
  EXPECT_EQ(u8"", snap::string::ltrim(u8"", L'\0'));
  EXPECT_EQ(u8"\0", snap::string::ltrim(u8"\0", L' '));
  
  EXPECT_EQ(L"hello", snap::string::ltrim(L" hello", L' '));
  EXPECT_EQ(L"hello", snap::string::ltrim(L"/hello", L'/'));
  EXPECT_EQ(L" hello", snap::string::ltrim(L" hello", L'?'));
  EXPECT_EQ(L"", snap::string::ltrim(L"  ", L' '));
  EXPECT_EQ(L"", snap::string::ltrim(L"", L'\0'));
  EXPECT_EQ(L"\0", snap::string::ltrim(L"\0", L' '));
}

TEST_F(StringTest, rtrim) {
  EXPECT_EQ("hello", snap::string::rtrim("hello"));
  EXPECT_EQ("hello", snap::string::rtrim("hello \r\t "));
  EXPECT_EQ(" hello", snap::string::rtrim(" hello \r\t "));
  EXPECT_EQ("", snap::string::rtrim(" \r\t "));
  EXPECT_EQ("", snap::string::rtrim(""));
  EXPECT_EQ("\0", snap::string::rtrim("\0"));
  
  EXPECT_EQ(u8"hello", snap::string::rtrim(u8"hello"));
  EXPECT_EQ(u8"hello", snap::string::rtrim(u8"hello \r\t "));
  EXPECT_EQ(u8" hello", snap::string::rtrim(u8" hello \r\t "));
  EXPECT_EQ(u8"", snap::string::rtrim(u8" \r\t "));
  EXPECT_EQ(u8"", snap::string::rtrim(u8""));
  EXPECT_EQ(u8"\0", snap::string::rtrim(u8"\0"));
  
  EXPECT_EQ(L"hello", snap::string::rtrim(L"hello"));
  EXPECT_EQ(L"hello", snap::string::rtrim(L"hello \r\t "));
  EXPECT_EQ(L" hello", snap::string::rtrim(L" hello \r\t "));
  EXPECT_EQ(L"", snap::string::rtrim(L" \r\t "));
  EXPECT_EQ(L"", snap::string::rtrim(L""));
  EXPECT_EQ(L"\0", snap::string::rtrim(L"\0"));
}

TEST_F(StringTest, rtrimWithChar) {
  EXPECT_EQ("hello", snap::string::rtrim("hello ", ' '));
  EXPECT_EQ("hello", snap::string::rtrim("hello/", '/'));
  EXPECT_EQ("hello ", snap::string::rtrim("hello ", '?'));
  EXPECT_EQ("", snap::string::rtrim("  ", ' '));
  EXPECT_EQ("", snap::string::rtrim("", '\0'));
  EXPECT_EQ("\0", snap::string::rtrim("\0", ' '));
  
  EXPECT_EQ(u8"hello", snap::string::rtrim(u8"hello ", ' '));
  EXPECT_EQ(u8"hello", snap::string::rtrim(u8"hello/", '/'));
  EXPECT_EQ(u8"hello ", snap::string::rtrim(u8"hello ", '?'));
  EXPECT_EQ(u8"", snap::string::rtrim(u8"  ", ' '));
  EXPECT_EQ(u8"", snap::string::rtrim(u8"", '\0'));
  EXPECT_EQ(u8"\0", snap::string::rtrim(u8"\0", ' '));
  
  EXPECT_EQ(L"hello", snap::string::rtrim(L"hello ", L' '));
  EXPECT_EQ(L"hello", snap::string::rtrim(L"hello/", L'/'));
  EXPECT_EQ(L"hello ", snap::string::rtrim(L"hello ", L'?'));
  EXPECT_EQ(L"", snap::string::rtrim(L"  ", L' '));
  EXPECT_EQ(L"", snap::string::rtrim(L"", L'\0'));
  EXPECT_EQ(L"\0", snap::string::rtrim(L"\0", L' '));
}

TEST_F(StringTest, trim) {
  EXPECT_EQ("hello", snap::string::trim("hello"));
  EXPECT_EQ("hello", snap::string::trim(" \r\t hello \r\t "));
  EXPECT_EQ("hello", snap::string::trim(" hello \r\t "));
  EXPECT_EQ("", snap::string::trim(" \r\t "));
  EXPECT_EQ("", snap::string::trim(""));
  EXPECT_EQ("\0", snap::string::trim("\0"));
  
  EXPECT_EQ(u8"hello", snap::string::trim(u8"hello"));
  EXPECT_EQ(u8"hello", snap::string::trim(u8" \r\t hello \r\t "));
  EXPECT_EQ(u8"hello", snap::string::trim(u8" hello \r\t "));
  EXPECT_EQ(u8"", snap::string::trim(u8" \r\t "));
  EXPECT_EQ(u8"", snap::string::trim(u8""));
  EXPECT_EQ(u8"\0", snap::string::trim(u8"\0"));
  
  EXPECT_EQ(L"hello", snap::string::trim(L"hello"));
  EXPECT_EQ(L"hello", snap::string::trim(L" \r\t hello \r\t "));
  EXPECT_EQ(L"hello", snap::string::trim(L" hello \r\t "));
  EXPECT_EQ(L"", snap::string::trim(L" \r\t "));
  EXPECT_EQ(L"", snap::string::trim(L""));
  EXPECT_EQ(L"\0", snap::string::trim(L"\0"));
}

TEST_F(StringTest, trimWithChar) {
  EXPECT_EQ("hello", snap::string::trim(" hello ", ' '));
  EXPECT_EQ("hello", snap::string::trim("//hello/", '/'));
  EXPECT_EQ("hello ", snap::string::trim("hello ", '?'));
  EXPECT_EQ("", snap::string::trim("  ", ' '));
  EXPECT_EQ("", snap::string::trim("", '\0'));
  EXPECT_EQ("\0", snap::string::trim("\0", ' '));
  
  EXPECT_EQ(u8"hello", snap::string::trim(u8" hello ", ' '));
  EXPECT_EQ(u8"hello", snap::string::trim(u8"//hello/", '/'));
  EXPECT_EQ(u8"hello ", snap::string::trim(u8"hello ", '?'));
  EXPECT_EQ(u8"", snap::string::trim(u8"  ", ' '));
  EXPECT_EQ(u8"", snap::string::trim(u8"", '\0'));
  EXPECT_EQ(u8"\0", snap::string::trim(u8"\0", ' '));
  
  EXPECT_EQ(L"hello", snap::string::trim(L" hello ", L' '));
  EXPECT_EQ(L"hello", snap::string::trim(L"//hello/", L'/'));
  EXPECT_EQ(L"hello ", snap::string::trim(L"hello ", L'?'));
  EXPECT_EQ(L"", snap::string::trim(L"  ", L' '));
  EXPECT_EQ(L"", snap::string::trim(L"", L'\0'));
  EXPECT_EQ(L"\0", snap::string::trim(L"\0", L' '));
}

TEST_F(StringTest, contains) {
  EXPECT_TRUE(snap::string::contains("hello world", "hello world"));
  EXPECT_TRUE(snap::string::contains("hello world", "hello"));
  EXPECT_TRUE(snap::string::contains("hello world", " "));
  EXPECT_TRUE(snap::string::contains("hello world", ""));
  EXPECT_TRUE(snap::string::contains("", ""));
  EXPECT_FALSE(snap::string::contains("hello", "hello world"));
  EXPECT_FALSE(snap::string::contains("", " "));
  
  EXPECT_TRUE(snap::string::contains(u8"hello world", u8"hello world"));
  EXPECT_TRUE(snap::string::contains(u8"hello world", u8"hello"));
  EXPECT_TRUE(snap::string::contains(u8"hello world", u8" "));
  EXPECT_TRUE(snap::string::contains(u8"hello world", u8""));
  EXPECT_TRUE(snap::string::contains(u8"", u8""));
  EXPECT_FALSE(snap::string::contains(u8"hello", u8"hello world"));
  EXPECT_FALSE(snap::string::contains(u8"", u8" "));
  
  EXPECT_TRUE(snap::string::contains(L"hello world", L"hello world"));
  EXPECT_TRUE(snap::string::contains(L"hello world", L"hello"));
  EXPECT_TRUE(snap::string::contains(L"hello world", L" "));
  EXPECT_TRUE(snap::string::contains(L"hello world", L""));
  EXPECT_TRUE(snap::string::contains(L"", L""));
  EXPECT_FALSE(snap::string::contains(L"hello", L"hello world"));
  EXPECT_FALSE(snap::string::contains(L"", L" "));
}

TEST_F(StringTest, replaceWithChar) {
  EXPECT_EQ("Hello", snap::string::replace("hello", 'h', 'H'));
  EXPECT_EQ("hello", snap::string::replace("hello", '?', 'H'));
  EXPECT_EQ("hello", snap::string::replace("hello", '\0', 'H'));
  
  EXPECT_EQ(u8"Hello", snap::string::replace(u8"hello", 'h', 'H'));
  EXPECT_EQ(u8"hello", snap::string::replace(u8"hello", '?', 'H'));
  EXPECT_EQ(u8"hello", snap::string::replace(u8"hello", '\0', 'H'));
  
  EXPECT_EQ(L"Hello", snap::string::replace(L"hello", L'h', L'H'));
  EXPECT_EQ(L"hello", snap::string::replace(L"hello", L'?', L'H'));
  EXPECT_EQ(L"hello", snap::string::replace(L"hello", L'\0', L'H'));
}

TEST_F(StringTest, replaceWithStrings) {
  EXPECT_EQ("HEllo", snap::string::replace("hello", "he", "HE"));
  EXPECT_EQ("hello", snap::string::replace("hello", "?", "H"));
  EXPECT_EQ("hello", snap::string::replace("hello", "", "H"));
  EXPECT_EQ("", snap::string::replace("hello", "hello", ""));
  EXPECT_EQ("", snap::string::replace("", "", "hello"));
  
  EXPECT_EQ(u8"HEllo", snap::string::replace(u8"hello", u8"he", u8"HE"));
  EXPECT_EQ(u8"hello", snap::string::replace(u8"hello", u8"?", u8"H"));
  EXPECT_EQ(u8"hello", snap::string::replace(u8"hello", u8"", u8"H"));
  EXPECT_EQ(u8"", snap::string::replace(u8"hello", u8"hello", u8""));
  EXPECT_EQ(u8"", snap::string::replace(u8"", u8"", u8"hello"));
  
  EXPECT_EQ(L"HEllo", snap::string::replace(L"hello", L"he", L"HE"));
  EXPECT_EQ(L"hello", snap::string::replace(L"hello", L"?", L"H"));
  EXPECT_EQ(L"hello", snap::string::replace(L"hello", L"", L"H"));
  EXPECT_EQ(L"", snap::string::replace(L"hello", L"hello", L""));
  EXPECT_EQ(L"", snap::string::replace(L"", L"", L"hello"));
}

TEST_F(StringTest, format) {
  EXPECT_EQ("hello123", snap::string::format("%s%d%d%d", "hello", 1, 2, 3));
  EXPECT_EQ("hello123", snap::string::format("%s%d%d%d", std::string("hello"), 1, 2, 3));
  EXPECT_EQ(L"hello123", snap::string::format(L"%S%d%d%d", L"hello", 1, 2, 3));
  EXPECT_EQ(L"hello123", snap::string::format(L"%S%d%d%d", std::wstring(L"hello"), 1, 2, 3));
}

TEST_F(StringTest, split) {
  std::vector<std::string> expected = {"hello", "world"};
  EXPECT_EQ(expected, snap::string::split("hello world", ' '));

  std::vector<std::wstring> wexpected = {L"hello", L"world"};
  EXPECT_EQ(wexpected, snap::string::split(L"hello world", L' '));
}

TEST_F(StringTest, join) {
  std::vector<std::string> tokens = {"hello", "world"};
  EXPECT_EQ("hello world", snap::string::join(tokens, " "));

  std::vector<std::wstring> wtokens = {L"hello", L"world"};
  EXPECT_EQ(L"hello world", snap::string::join(wtokens, L" "));
}

TEST_F(StringTest, translateByChars) {
  EXPECT_EQ("HELLO", snap::string::translate("hello", "eloh?", "ELOH"));
  EXPECT_EQ("hello", snap::string::translate("hello", "hel", ""));
}
