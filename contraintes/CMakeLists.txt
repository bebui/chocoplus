SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -pedantic -Wno-long-long")
 
 SET(LIB_FILES eq.cc)
 ADD_LIBRARY(contraintes ${LIB_FILES})
