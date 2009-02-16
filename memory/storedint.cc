#include "storedint.h"
#include "environment.h"
#include "../solver/solver.h"
#include <iostream>
StoredInt::StoredInt(int val) : StoredElement(),_current(val) 
{
  //std::cout << "buibiu" << std::endl;
  Solver::getEnvironment().addElement(this);
}

int StoredInt::get()
{
  return _current;
}

void StoredInt::set(int val)
{
  int widx = Solver::getEnvironment().getIndex();
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