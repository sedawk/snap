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
#include <memory>
#include <stdexcept>
#include "Constants.hpp"
#include "snap/sqlite3/Column.hpp"
#include "snap/sqlite3/Database.hpp"
#include "snap/sqlite3/Statement.hpp"

class Sqlite3ColumnTest : public ::testing::Test {
 protected:
  void SetUp() override {
    db = std::make_shared<snap::sqlite3::Database>(test::sqlite3::DB_FILE);
    db->execute(test::sqlite3::CREATE_TABLE);
  }

  std::shared_ptr<snap::sqlite3::Database> db;
};

TEST_F(Sqlite3ColumnTest, testGetColumnData) {
  db->execute(test::sqlite3::INSERT_DATA);
  auto stmt = db->prepare(test::sqlite3::SELECT_ALL_DATA);
  stmt.fetch();
  EXPECT_STREQ("first", stmt.getColumn(0).getName());
  EXPECT_EQ(1, stmt.getColumn(0).getInt());
  EXPECT_EQ(2.0, stmt.getColumn(1).getDouble());
  EXPECT_STREQ("three", stmt.getColumn("third").getText());
  EXPECT_EQ("넷", stmt.getColumn("fourth").getString());
}
