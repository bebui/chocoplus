#include "storedint.h"
#include "environment.h"
#include "../solver/solver.h"
#include <iostream>
StoredInt::StoredInt(Environment& __env,int val) : StoredElement(__env),_current(val) {}

int StoredInt::get()
{
  return _current;
}

void StoredInt::set(int val)
{
  int widx =_env.getIndex();
  if (widx > _lastsave)
  {
    _trail.push(_current);
    _worlds.push(_lastsave);
    _lastsave = widx;
  }
  _current = val;
}

void StoredInt::restore(int widx)
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

void StoredInt::add(int val)
{
  set(val+_current);
}