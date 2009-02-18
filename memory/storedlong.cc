#include "storedlong.h"
#include "environment.h"
#include "../solver/solver.h"
#include <iostream>


StoredLong::StoredLong(Environment* __env ,uint64_t val) : StoredElement(__env),_current(val) {}


StoredLong& StoredLong::operator=(const StoredLong& b)
{
  _current = b._current;
  _env = b._env;
  _lastsave = b._lastsave;
  return *this;
}



uint64_t StoredLong::get()
{
  return _current;
}

void StoredLong::set(uint64_t val)
{
  int widx = _env->getIndex();
  if (widx > _lastsave)
  {
    _trail.push(_current);
    _worlds.push(_lastsave);
    _lastsave = widx;
  }
  _current = val;
}

void StoredLong::restore(int widx)
{
  if (widx < _lastsave)
  {
    while (_worlds.top() > widx)
    {
      _worlds.pop();
      _trail.pop();
    }
    _current = _trail.top(); _trail.pop();
    _lastsave = _worlds.top(); _worlds.pop();
  }
}

void StoredLong::add(uint64_t val)
{
  set(val+_current);
}