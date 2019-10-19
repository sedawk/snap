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
#include "snap/filesystem.hpp"

class FilesystemTest : public ::testing::Test {
 protected:
  constexpr static const char* UNKNOWN_PATH = "path/to/unknown.file";
  constexpr static const char* TEST_FILE = "unittest.out";
  constexpr static const char* ROOT_DIR = "/";
  constexpr static const char* BLANK = "";
};

constexpr const char* FilesystemTest::UNKNOWN_PATH;
constexpr const char* FilesystemTest::TEST_FILE;
constexpr const char* FilesystemTest::ROOT_DIR;
constexpr const char* FilesystemTest::BLANK;

TEST_F(FilesystemTest, dirname) {
  EXPECT_EQ("path/to", snap::filesystem::dirname(UNKNOWN_PATH));
  EXPECT_EQ(BLANK, snap::filesystem::dirname(TEST_FILE));
  EXPECT_EQ(BLANK, snap::filesystem::dirname(BLANK));
}

TEST_F(FilesystemTest, filename) {
  EXPECT_EQ("unknown.file", snap::filesystem::filename(UNKNOWN_PATH));
  EXPECT_EQ(TEST_FILE, snap::filesystem::filename(TEST_FILE));
  EXPECT_EQ(BLANK, snap::filesystem::filename(BLANK));
}

TEST_F(FilesystemTest, basename) {
  EXPECT_EQ("unknown", snap::filesystem::basename(UNKNOWN_PATH));
  EXPECT_EQ("unittest", snap::filesystem::basename(TEST_FILE));
  EXPECT_EQ(BLANK, snap::filesystem::basename(BLANK));
}

TEST_F(FilesystemTest, extension) {
  EXPECT_EQ("file", snap::filesystem::extension(UNKNOWN_PATH));
  EXPECT_EQ("out", snap::filesystem::extension(TEST_FILE));
  EXPECT_EQ(BLANK, snap::filesystem::extension("no_extension"));
  EXPECT_EQ(BLANK, snap::filesystem::extension(BLANK));
}

TEST_F(FilesystemTest, exists) {
  EXPECT_FALSE(snap::filesystem::exists(UNKNOWN_PATH));
  EXPECT_TRUE(snap::filesystem::exists(TEST_FILE));
}

TEST_F(FilesystemTest, is_directory) {
  EXPECT_FALSE(snap::filesystem::is_directory(UNKNOWN_PATH));
  EXPECT_FALSE(snap::filesystem::is_directory(TEST_FILE));
  EXPECT_TRUE(snap::filesystem::is_directory(ROOT_DIR));
  EXPECT_FALSE(snap::filesystem::is_directory(BLANK));
}

TEST_F(FilesystemTest, is_regular_file) {
  EXPECT_FALSE(snap::filesystem::is_regular_file(UNKNOWN_PATH));
  EXPECT_TRUE(snap::filesystem::is_regular_file(TEST_FILE));
  EXPECT_FALSE(snap::filesystem::is_regular_file(ROOT_DIR));
  EXPECT_FALSE(snap::filesystem::is_regular_file(BLANK));
}
