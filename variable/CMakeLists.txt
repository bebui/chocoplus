SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -pedantic -Wno-long-long")
 
 SET(LIB_FILES intdomain.cc intvar.cc)
 ADD_LIBRARY(variable ${LIB_FILES})
TARGET_LINK_LIBRARIES(variable memory)
