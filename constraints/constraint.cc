#include "constraint.h"
#include "../solver.h"

ConstraintObj::ConstraintObj(Solver* __s, std::vector<IntVar> __vars) : _s(__s), _vars(__vars), _entailed(__s->getEnvironment(),false),
                                                                        _inqueue(false)
{}


bool ConstraintObj::entailed()
{ 
  return _entailed.get();
}

Solver* ConstraintObj::getSolver()
{
  return _s;
}

void ConstraintObj::record_vars()
{
  for( std::vector<IntVar>::iterator it = _vars.begin() ; it != _vars.end() ; ++it)
    (*it).get_obj()->record(this);
}

bool ConstraintObj::in_queue()
{
  return _inqueue;
}
void ConstraintObj::set_in_queue(bool __b)
{
  _inqueue = __b;
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

