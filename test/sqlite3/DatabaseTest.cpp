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
#include "snap/sqlite3/Database.hpp"

class Sqlite3DatabaseTest : public ::testing::Test {
 protected:
  void SetUp() override {
    db = std::make_shared<snap::sqlite3::Database>(test::sqlite3::DB_FILE);
    db->execute(test::sqlite3::CREATE_TABLE);
  }

  std::shared_ptr<snap::sqlite3::Database> db;
};

TEST_F(Sqlite3DatabaseTest, testFailsWhenUnknownPathWithNoOptionGiven) {
  EXPECT_THROW({ snap::sqlite3::Database o(test::sqlite3::DB_FILE, 0); },
               std::runtime_error);
}

TEST_F(Sqlite3DatabaseTest, testOkWhenUnknownPathWithDefaultOptionGiven) {
  EXPECT_NO_THROW({ snap::sqlite3::Database o(test::sqlite3::DB_FILE); });
}

TEST_F(Sqlite3DatabaseTest, testExecuteSimpleQueries) {
  EXPECT_EQ(1, db->execute(test::sqlite3::INSERT_DATA));
  EXPECT_THROW(db->execute(test::sqlite3::INSERT_DATA), std::runtime_error);
}

TEST_F(Sqlite3DatabaseTest, testExecuteFailsWhenInvalidStatementGiven) {
  EXPECT_THROW(db->execute(test::sqlite3::INVALID_STMT), std::runtime_error);
}

TEST_F(Sqlite3DatabaseTest, testPrepareFailsWhenInvalidStatementGiven) {
  EXPECT_THROW(db->prepare(test::sqlite3::INVALID_STMT), std::runtime_error);
}
