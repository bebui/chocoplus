cmake_minimum_required (VERSION 2.6)
project (CHOCOC)

add_subdirectory (memory)
add_subdirectory (solver)
ADD_EXECUTABLE(test test.cc)
TARGET_LINK_LIBRARIES(test memory solver)
