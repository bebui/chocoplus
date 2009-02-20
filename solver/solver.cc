#include "solver.h"

Solver::Solver()  {}

Solver::~Solver()
{
  for (std::vector<IntVarObj*>::iterator it = _vars.begin() ; it != _vars.end() ; ++it)
  {
    delete(*it);
   // std::cout << " 1 DELETE " << std::endl;   
  }
  for (std::vector<ConstraintObj*>::iterator it = _phantom.begin() ; it != _phantom.end() ; ++it)
  {
    delete(*it);
   // std::cout << " 1 DELETE " << std::endl;   
  }
  
 // std::cout<< "normalement il n'y a plus d'objet IntVarObj" << std::endl;
}

void Solver::push()
{
  _env.push();
}

void Solver::pop()
{
  _env.pop();
}

void Solver::post(Constraint c)
{
  _cons.push_back(c.get_constraint());
}

bool Solver::solve()
{
  push();
  try 
  {
    for (std::vector<ConstraintObj*>::iterator it = _cons.begin() ; it != _cons.end() ; ++it)
    {
      (*it)->propagate();
    }
    return true;
  }
  catch(Contradiction &c)
  {
    pop();
    return false;
  }
}

IntVar Solver::make_var(std::string __name,int __inf, int __sup)
{
  IntVarObj* a = new IntVarObj(&_env,__name,__inf,__sup);
  //std::cout << " 1 NEW " << std::endl;
  _vars.push_back(a);
  return IntVar(a);
  
}

Constraint Solver::eq(IntVar __a, IntVar __b)
{
  std::vector<IntVar> __v;
  __v.push_back(__a);
  __v.push_back(__b);
  Eq* e= new Eq(this,__v);
  _phantom.push_back(e);
  return Constraint(e);
}


