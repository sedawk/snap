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
#include "snap/sqlite3/Database.hpp"
#include "snap/sqlite3/Statement.hpp"

namespace snap {
namespace sqlite3 {

Database::Database(const std::string& path, int flags) : mDB(nullptr, nullptr) {
  struct sqlite3* db = nullptr;
  asserted(sqlite3_open_v2(path.c_str(), &db, flags, nullptr));
  mDB = { db, sqlite3_close_v2 };
}

int Database::execute(const std::string& query) {
  asserted(sqlite3_exec(getDB(), query.c_str(), nullptr, nullptr, nullptr));
  return sqlite3_changes(getDB());
}

Statement Database::prepare(const std::string& query) {
  sqlite3_stmt* stmt = nullptr;
  asserted(sqlite3_prepare_v2(getDB(),
                              query.c_str(), query.size(), &stmt, nullptr));
  return Statement(stmt);
}

struct sqlite3* Database::getDB() {
  return mDB.get();
}

void Database::asserted(int status, int response) {
  if (response != status) {
    throw std::runtime_error(sqlite3_errmsg(getDB()));
  }
}

}  // namespace sqlite3
}  // namespace snap
