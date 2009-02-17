#include "solver.h"
#include "../memory/storedint.h"
#include <iostream>

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