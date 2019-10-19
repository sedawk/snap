build_test_program(
  NAME unittest
  SUFFIX .out
  SRCS StringTest.cpp sqlite3/DatabaseTest.cpp sqlite3/StatementTest.cpp sqlite3/ColumnTest.cpp
  LIBS snap
  )
