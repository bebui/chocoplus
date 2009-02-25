
#include "signals.h"
#include <iostream>
boost::signal<void (int)> backtrack;
boost::signal<void ()> solver_start;
boost::signal<void ()> solver_stop;