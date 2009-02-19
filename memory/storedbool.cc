#include "storedbool.h"

StoredBool::StoredBool(Environment* __env,bool val) : StoredElement(__env),_current(val) {}

bool StoredBool::get()
{
  return _current;
}

void StoredBool::set(bool val)
{
  int widx =_env->getIndex();
  if (widx > _lastsave)
  {
    _trail.push(_current);
    _worlds.push(_lastsave);
    _lastsave = widx;
  }
  _current = val;
}

void StoredBool::restore(int widx)
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
