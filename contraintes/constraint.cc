#include "constraint.h"
#include "../solver.h"

ConstraintObj::ConstraintObj(Solver* __s, std::vector<IntVar> __vars) : _s(__s), _vars(__vars), _entailed(__s->getEnvironment(),false){}


bool ConstraintObj::entailed()
{ 
  return _entailed.get();
}

Solver* ConstraintObj::getSolver()
{
  return _s;
}



Constraint::Constraint(ConstraintObj* __cons) : _cons(__cons) {}

void Constraint::propagate()
{
  _cons->propagate();
}

bool Constraint::entailed()
{ 
  return _cons->entailed();
}

ConstraintObj* Constraint::get_constraint()
{
  return _cons;
}

