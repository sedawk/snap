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
#include "snap/sqlite3/Statement.hpp"

class Sqlite3StatementTest : public ::testing::Test {
 protected:
  void SetUp() override {
    db = std::make_shared<snap::sqlite3::Database>(test::sqlite3::DB_FILE);
    db->execute(test::sqlite3::CREATE_TABLE);
  }

  std::shared_ptr<snap::sqlite3::Database> db;
};

TEST_F(Sqlite3StatementTest, testExecutePreparedStatement) {
  auto stmt = db->prepare(test::sqlite3::INSERT_DATA);
  EXPECT_EQ(1, stmt.execute());
  EXPECT_THROW(stmt.execute(), std::runtime_error);
}

TEST_F(Sqlite3StatementTest, testBindArgumentsWithIndices) {
  auto stmt = db->prepare(test::sqlite3::INSERT_PREP_STMT);
  stmt.bind(1, 1)
      .bind(2, 2.0)
      .bind(3, "three")
      .bind(4);
  EXPECT_EQ(1, stmt.execute());
}

TEST_F(Sqlite3StatementTest, testBindArgumentsWithNames) {
  auto stmt = db->prepare(test::sqlite3::INSERT_PREP_STMT);
  stmt.bind(":first", 1)
      .bind(":second", 2.0)
      .bind(":third", "three")
      .bind(":fourth");
  EXPECT_EQ(1, stmt.execute());
}

TEST_F(Sqlite3StatementTest, testResetAndBindArguments) {
  auto stmt = db->prepare("INSERT INTO Test VALUES (?, 0.0, NULL, NULL)");
  stmt.bind(1, 1).execute();
  stmt.reset();
  stmt.bind(1, 2).execute();
  EXPECT_EQ(2, db->execute("UPDATE Test SET second = 2.0"));
}

TEST_F(Sqlite3StatementTest, testFetchRows) {
  db->execute("INSERT INTO Test VALUES (1, 0.0, NULL, NULL)");
  db->execute("INSERT INTO Test VALUES (2, 0.0, NULL, NULL)");
  auto stmt = db->prepare(test::sqlite3::SELECT_ALL_DATA);
  EXPECT_TRUE(stmt.fetch());
  EXPECT_TRUE(stmt.fetch());
  EXPECT_FALSE(stmt.fetch());
}

TEST_F(Sqlite3StatementTest, testGetColumnFailsWhenInvalidIndexGiven) {
  db->execute(test::sqlite3::INSERT_DATA);
  auto stmt = db->prepare(test::sqlite3::SELECT_ALL_DATA);
  EXPECT_THROW(stmt.getColumn(100), std::runtime_error);
  EXPECT_THROW(stmt.getColumn("unknown"), std::runtime_error);
}
