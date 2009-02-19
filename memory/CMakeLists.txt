SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -pedantic -Wno-long-long")
 
 SET(LIB_FILES environment.cc  storedbitset.cc)
 ADD_LIBRARY(memory ${LIB_FILES})
