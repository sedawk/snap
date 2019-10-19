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

#ifndef INCLUDE_SNAP_SQLITE3_STATEMENT_HPP_
#define INCLUDE_SNAP_SQLITE3_STATEMENT_HPP_

#include <sqlite3.h>
#include <cstdint>
#include <memory>
#include <string>
#include "snap/sqlite3/Column.hpp"

namespace snap {
namespace sqlite3 {

class Statement {
 public:
  explicit Statement(sqlite3_stmt* statement);

  int execute();
  bool fetch();
  void reset();

  Statement& bind(const int index, const std::int32_t value);
  Statement& bind(const int index, const std::uint32_t value);
  Statement& bind(const int index, const std::int64_t value);
  Statement& bind(const int index, const double value);
  Statement& bind(const int index, const std::string& value);
  Statement& bind(const int index, const char* value);
  Statement& bind(const int index, const void* value, int size);
  Statement& bind(const int index);
  Statement& bind(const std::string& name, const std::int32_t value);
  Statement& bind(const std::string& name, const std::uint32_t value);
  Statement& bind(const std::string& name, const std::int64_t value);
  Statement& bind(const std::string& name, const double value);
  Statement& bind(const std::string& name, const std::string& value);
  Statement& bind(const std::string& name, const char* value);
  Statement& bind(const std::string& name, const void* value, int size);
  Statement& bind(const std::string& name);

  Column getColumn(const int index);
  Column getColumn(const std::string& name);

 private:
  void asserted(int status, int response = SQLITE_OK);
  struct sqlite3* getDB();
  sqlite3_stmt* getStmt();
  
  std::unique_ptr<sqlite3_stmt, int(*)(sqlite3_stmt*)> mStatement;
};

}  // namespace sqlite3
}  // namespace snap

#endif  // INCLUDE_SNAP_SQLITE3_STATEMENT_HPP_
