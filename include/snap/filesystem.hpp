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

#ifndef INCLUDE_SNAP_FILESYSTEM_HPP_
#define INCLUDE_SNAP_FILESYSTEM_HPP_

#include <unistd.h>
#include <string>

namespace snap {
namespace filesystem {

inline std::string dirname(const std::string& path) {
  auto position = path.find_last_of('/');
  return (position == std::string::npos) ? "" : path.substr(0, position);
}

inline std::string filename(const std::string& path) {
  auto position = path.find_last_of('/');
  return (position == std::string::npos) ? path : path.substr(position + 1);
}

inline std::string basename(const std::string& path) {
  auto file = filename(path);
  auto position = file.find_last_of('.');
  return (position == std::string::npos) ? file : file.substr(0, position);
}

inline std::string extension(const std::string& path) {
  auto file = filename(path);
  auto position = file.find_last_of('.');
  return (position == std::string::npos) ? "" : file.substr(position + 1);
}

inline bool exists(const std::string& path) {
  return access(path.c_str(), 0) == 0;
}

inline bool is_directory(const std::string& path) {
  struct stat stbuf = {};
  stat(path.c_str(), &stbuf);
  return S_ISDIR(stbuf.st_mode);
}

inline bool is_regular_file(const std::string& path) {
  struct stat stbuf = {};
  stat(path.c_str(), &stbuf);
  return S_ISREG(stbuf.st_mode);
}

}  // namespace filesystem
}  // namespace snap

#endif  // INCLUDE_SNAP_FILESYSTEM_HPP_
