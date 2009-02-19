#include "intvar.h"

IntVarObj::IntVarObj(Environment* __env, std::string __name, int __min, int __max) : _dom(__env,__min,__max), _name(__name) {}

int IntVarObj::sup()
{
  return _dom.sup();
}
int IntVarObj::inf()
{
  return _dom.inf();
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

void IntVarObj::restrict(int __val)
{
  update_inf(__val);
  update_sup(__val);
}

void IntVarObj::remove(int __val)
{
  _dom.remove(__val);
}
void IntVarObj::update_inf(int __inf)
{
  _dom.update_inf(__inf);
}

void IntVarObj::update_sup(int __sup)
{
  _dom.update_sup(__sup);
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

void IntVar::restrict(int __val)
{
  update_inf(__val);
  update_sup(__val);
}

void IntVar::remove(int __val)
{
  _repr->remove(__val);
}
void IntVar::update_inf(int __inf)
{
  _repr->update_inf(__inf);
}

void IntVar::update_sup(int __sup)
{
  _repr->update_sup(__sup);
}

size_t IntVar::cardinality()
{
  return _repr->cardinality(); 
}

std::string IntVar::str()
{
  return _repr->str();
}



