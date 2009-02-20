cmake_minimum_required (VERSION 2.6)
project (CHOCOC)

add_subdirectory (memory)
add_subdirectory (solver)
add_subdirectory (variable)
add_subdirectory (constraints)
ADD_EXECUTABLE(test test.cc)
ADD_EXECUTABLE(sudoku sudoku.cc)

TARGET_LINK_LIBRARIES(test memory solver variable constraints)
TARGET_LINK_LIBRARIES(sudoku memory solver variable constraints)
