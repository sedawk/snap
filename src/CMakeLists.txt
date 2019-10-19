find_package(SQLite3)

build_shared_library(
  NAME snap
  SRCS sqlite3/Database.cpp sqlite3/Statement.cpp sqlite3/Column.cpp
  PUBLIC_HEADERS ${CMAKE_SOURCE_DIR}/include ${SQLite3_INCLUDE_DIRS}
  LIBS ${SQLite3_LIBRARIES}
  )
