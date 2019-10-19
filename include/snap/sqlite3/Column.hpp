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

#ifndef INCLUDE_SNAP_SQLITE3_COLUMN_HPP_
#define INCLUDE_SNAP_SQLITE3_COLUMN_HPP_

#include <sqlite3.h>
#include <cstdint>
#include <string>

namespace snap {
namespace sqlite3 {

class Column {
 public:
  Column(sqlite3_stmt* stmt, const int index);

  std::int32_t getInt() const noexcept;
  std::int64_t getInt64() const noexcept;
  double getDouble() const noexcept;
  const char* getText() const noexcept;
  std::string getString() const noexcept;
  const void* getBlob() const noexcept;

  const char* getName() const noexcept;
  int size() const noexcept;

 private:
  sqlite3_stmt* mStmt;
  int mIndex;
};

}  // namespace sqlite3
}  // namespace snap

#endif  // INCLUDE_SNAP_SQLITE3_COLUMN_HPP_
