#include "intvar.h"
#include "../constraint.h"
#include "../solver.h"

IntVarObj::IntVarObj(Solver* __s, std::string __name, int __min, int __max) : _s(__s), _dom(__s->getEnvironment(),__min,__max), _name(__name) {}

int IntVarObj::sup()
{
  return _dom.sup();
}
int IntVarObj::inf()
{
  return _dom.inf();
}

int IntVarObj::get()
{
  if (_dom.inf() == _dom.sup())
    return _dom.inf();
  else
    return INT_MAX;
}

int IntVarObj::next(int __val)
{
  return _dom.next(__val);
}
int IntVarObj::prev(int __val)
{
  return _dom.prev(__val);
}

bool IntVarObj::contains(int __val)
{
  return _dom.contains(__val);
}

void IntVarObj::record(ConstraintObj* __cons)
{
  _cons.insert(__cons);
}
std::set<ConstraintObj*> IntVarObj::get_constraints()
{
  return _cons;
}

bool IntVarObj::restrict(int __val)
{
  return update_inf(__val) || update_sup(__val);
}

bool IntVarObj::remove(int __val)
{
  bool __rem = _dom.remove(__val);
  if (__rem)
  {
    for (std::set<ConstraintObj*>::iterator it = _cons.begin() ; it != _cons.end() ; ++it)
      _s->add_to_queue(*it);
  }
  return __rem;
}
bool IntVarObj::update_inf(int __inf)
{
  bool __rem = _dom.update_inf(__inf);
  if (__rem)
  {
    for (std::set<ConstraintObj*>::iterator it = _cons.begin() ; it != _cons.end() ; ++it)
      _s->add_to_queue(*it);
  }
  return __rem;
}

bool IntVarObj::update_sup(int __sup)
{
  bool __rem = _dom.update_sup(__sup);
  if (__rem)
  {
    for (std::set<ConstraintObj*>::iterator it = _cons.begin() ; it != _cons.end() ; ++it)
      _s->add_to_queue(*it);
  }
  return __rem;
}

size_t IntVarObj::cardinality()
{
  return _dom.cardinality(); 
}

std::string IntVarObj::str()
{
  return _name + ":" + _dom.str();
}




IntVar::IntVar(IntVarObj* __var) : _repr(__var) {}

int IntVar::sup()
{
  return _repr->sup();
}
int IntVar::inf()
{
  return _repr->inf();
}

int IntVar::get()
{
  return _repr->get();
}

int IntVar::next(int __val)
{
  return _repr->next(__val);
}
int IntVar::prev(int __val)
{
  return _repr->prev(__val);
}

bool IntVar::contains(int __val)
{
  return _repr->contains(__val);
}

bool IntVar::restrict(int __val)
{
  return update_inf(__val) || update_sup(__val);
}

bool IntVar::remove(int __val)
{
  return _repr->remove(__val);
}
bool IntVar::update_inf(int __inf)
{
  return _repr->update_inf(__inf);
}

bool IntVar::update_sup(int __sup)
{
  return _repr->update_sup(__sup);
}

size_t IntVar::cardinality()
{
  return _repr->cardinality(); 
}

std::string IntVar::str()
{
  return _repr->str();
}

