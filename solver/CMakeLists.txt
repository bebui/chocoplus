SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -pedantic -Wno-long-long")
 
 SET(LIB_FILES c_queue.cc var_chooser.cc val_chooser.cc solver.cc)
 ADD_LIBRARY(solver ${LIB_FILES})
