#include "constraint.h"
#include "../solver.h"

ConstraintObj::ConstraintObj(Solver* __s, const std::vector<IntVar> &__vars) : _s(__s), _vars(__vars), _entailed(__s->getEnvironment(),false),
                                                                        _inqueue(false)
{}


bool ConstraintObj::entailed() const
{ 
  return _entailed.get();
}

Solver* ConstraintObj::getSolver() const
{
  return _s;
}

void ConstraintObj::record_vars()
{
  for( std::vector<IntVar>::iterator it = _vars.begin() ; it != _vars.end() ; ++it)
    (*it).get_obj()->record(this);
}

bool ConstraintObj::in_queue() const
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

bool Constraint::entailed() const
{ 
  return _cons->entailed();
}

ConstraintObj* Constraint::get_constraint() const
{
  return _cons;
}

