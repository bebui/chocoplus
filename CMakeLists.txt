cmake_minimum_required (VERSION 2.6)
project (CHOCOC)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wextra -Weffc++ -pedantic -Wold-style-cast")

find_package( Boost REQUIRED COMPONENTS signals)
link_directories ( ${Boost_LIBRARY_DIRS} )
include_directories ( ${Boost_INCLUDE_DIRS} )

ADD_LIBRARY(choco
    memory/environment.cc
    memory/storedbitset.cc

    solver/c_queue.cc
    solver/var_chooser.cc
    solver/val_chooser.cc
    solver/solver.cc

    variable/intdomain.cc
    variable/intvar.cc

    constraints/constraint.cc
    constraints/eq.cc
    constraints/neq.cc
    signals.cc
   )


ADD_EXECUTABLE(test test.cc)
ADD_EXECUTABLE(sudoku sudoku.cc)

TARGET_LINK_LIBRARIES(test boost_signals choco)
TARGET_LINK_LIBRARIES(sudoku boost_signals choco)

