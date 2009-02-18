#include "solver.h"
#include "../memory/storedint.h"
#include <iostream>

Solver::Solver()  {}

Solver::~Solver()
{
  for (std::vector<IntVarObj*>::iterator it = _vars.begin() ; it != _vars.end() ; ++it)
  {
    delete(*it);
    std::cout << " 1 DELETE " << std::endl;
    
  }
  std::cout<< "normalement il n'y a plus d'objet IntVarObj" << std::endl;
}

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

IntVar Solver::make_var(std::string __name,int __inf, int __sup)
{
  IntVarObj* a = new IntVarObj(&_env,__name,__inf,__sup);
  std::cout << " 1 NEW " << std::endl;
  _vars.push_back(a);
  return IntVar(a);
  
}