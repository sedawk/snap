find_package(SQLite3)
find_package(LibZip)

build_shared_library(
  NAME snap
  VERSION ${PROJECT_VERSION}
  SRCS sqlite3/Database.cpp sqlite3/Statement.cpp sqlite3/Column.cpp zip/Archive.cpp
  PUBLIC_HEADERS ${CMAKE_SOURCE_DIR}/include ${SQLite3_INCLUDE_DIRS} ${LIBZIP_INCLUDE_DIR_ZIP}
  LIBS ${SQLite3_LIBRARIES} ${LIBZIP_LIBRARY}
  )
