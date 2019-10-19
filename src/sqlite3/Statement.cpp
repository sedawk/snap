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

#include <sqlite3.h>
#include <stdexcept>
#include <string>
#include "snap/sqlite3/Column.hpp"
#include "snap/sqlite3/Statement.hpp"

namespace snap {
namespace sqlite3 {

Statement::Statement(sqlite3_stmt* statement) :
    mStatement(statement, sqlite3_finalize) {
}

int Statement::execute() {
  auto status = sqlite3_step(getStmt());
  if (status == SQLITE_DONE) {
    return sqlite3_changes(getDB());
  }
  if (status == sqlite3_errcode(getDB())) {
    throw std::runtime_error(sqlite3_errmsg(getDB()));
  }
  throw std::runtime_error(sqlite3_errstr(SQLITE_MISUSE));
}

bool Statement::fetch() {
  auto status = sqlite3_step(getStmt());
  if (status == SQLITE_ROW) {
    return true;
  }
  if (status == SQLITE_DONE) {
    return false;
  }
  if (status == sqlite3_errcode(getDB())) {
    throw std::runtime_error(sqlite3_errmsg(getDB()));
  }
  throw std::runtime_error(sqlite3_errstr(SQLITE_MISUSE));
}

void Statement::reset() {
  sqlite3_reset(getStmt());
  sqlite3_clear_bindings(getStmt());
}

Statement& Statement::bind(const int index, const std::int32_t value) {
  asserted(sqlite3_bind_int(getStmt(), index, value));
  return *this;
}

Statement& Statement::bind(const int index, const std::uint32_t value) {
  asserted(sqlite3_bind_int64(getStmt(), index, value));
  return *this;
}

Statement& Statement::bind(const int index, const std::int64_t value) {
  asserted(sqlite3_bind_int64(getStmt(), index, value));
  return *this;
}

Statement& Statement::bind(const int index, const double value) {
  asserted(sqlite3_bind_double(getStmt(), index, value));
  return *this;
}

Statement& Statement::bind(const int index, const std::string& value) {
  asserted(sqlite3_bind_text(getStmt(), index,
                             value.c_str(),
                             static_cast<int>(value.size()),
                             SQLITE_TRANSIENT));
  return *this;
}

Statement& Statement::bind(const int index, const char* value) {
  asserted(sqlite3_bind_text(getStmt(), index,
                             value,
                             -1,
                             SQLITE_TRANSIENT));
  return *this;
}

Statement& Statement::bind(const int index, const void* value, int size) {
  asserted(sqlite3_bind_blob(getStmt(), index,
                             value,
                             size,
                             SQLITE_TRANSIENT));
  return *this;
}

Statement& Statement::bind(const int index) {
  asserted(sqlite3_bind_null(getStmt(), index));
  return *this;
}

Statement& Statement::bind(const std::string& name, const std::int32_t value) {
  auto index = sqlite3_bind_parameter_index(getStmt(), name.c_str());
  return bind(index, value);
}

Statement& Statement::bind(const std::string& name, const std::uint32_t value) {
  auto index = sqlite3_bind_parameter_index(getStmt(), name.c_str());
  return bind(index, value);
}

Statement& Statement::bind(const std::string& name, const std::int64_t value) {
  auto index = sqlite3_bind_parameter_index(getStmt(), name.c_str());
  return bind(index, value);
}

Statement& Statement::bind(const std::string& name, const double value) {
  auto index = sqlite3_bind_parameter_index(getStmt(), name.c_str());
  return bind(index, value);
}

Statement& Statement::bind(const std::string& name, const std::string& value) {
  auto index = sqlite3_bind_parameter_index(getStmt(), name.c_str());
  return bind(index, value);
}

Statement& Statement::bind(const std::string& name, const char* value) {
  auto index = sqlite3_bind_parameter_index(getStmt(), name.c_str());
  return bind(index, value);
}

Statement& Statement::bind(const std::string& name,
                           const void* value, int size) {
  auto index = sqlite3_bind_parameter_index(getStmt(), name.c_str());
  return bind(index, value, size);
}

Statement& Statement::bind(const std::string& name) {
  auto index = sqlite3_bind_parameter_index(getStmt(), name.c_str());
  return bind(index);
}

Column Statement::getColumn(const int index) {
  if (index < 0 || sqlite3_column_count(getStmt()) < index) {
    throw std::runtime_error(std::to_string(index) + ": index out of bounds");
  }
  return Column(getStmt(), index);
}

Column Statement::getColumn(const std::string& name) {
  for (auto i = 0; i < sqlite3_column_count(getStmt()); i++) {
    if (name == sqlite3_column_name(getStmt(), i)) {
      return Column(getStmt(), i);
    }
  }
  throw std::runtime_error(name + ": column name does not exist");
}

void Statement::asserted(int status, int response) {
  if (status != response) {
    throw std::runtime_error(sqlite3_errmsg(getDB()));
  }
}

struct sqlite3* Statement::getDB() {
  return sqlite3_db_handle(getStmt());
}

sqlite3_stmt* Statement::getStmt() {
  return mStatement.get();
}

}  // namespace sqlite3
}  // namespace snap
