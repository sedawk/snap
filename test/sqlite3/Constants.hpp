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

namespace test {
namespace sqlite3 {

constexpr static const char* DB_FILE = ":memory:";
constexpr static const char* CREATE_TABLE = "CREATE TABLE IF NOT EXISTS Test ("
                                            "first INTEGER PRIMARY KEY, "
                                            "second DOUBLE, "
                                            "third TEXT, "
                                            "fourth BLOB)";
constexpr static const char* INVALID_STMT = "INVALID STATEMENT";
constexpr static const char* INSERT_DATA = "INSERT INTO Test VALUES (1, 2.0, 'three', '넷')";
constexpr static const char* INSERT_PREP_STMT = "INSERT INTO Test VALUES "
                                                "(:first, :second, :third, :fourth)";
constexpr static const char* SELECT_ALL_DATA = "SELECT * FROM Test";

}  // namespace sqlite3
}  // namespace test
