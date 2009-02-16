#include "solver.h"
#include "../memory/storedint.h"
#include <iostream>

Environment Solver::_env;
Solver::Solver()  {}

void Solver::push()
{
  _env.push();
}

void Solver::pop()
{
  _env.pop();
}

bool Solver::solve()
{
  return true;
}