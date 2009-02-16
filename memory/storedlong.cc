#include "storedlong.h"
#include "environment.h"
#include "../solver/solver.h"
#include <iostream>

unsigned long operator+(unsigned long l, StoredLong b)
{
  return l+b.get();
}
unsigned long operator+(StoredLong b, unsigned long l)
{
  return l+b.get();
}
unsigned long operator+(StoredLong a, StoredLong b)
{
  return a.get()+b.get();
}

unsigned long operator|(unsigned long l, StoredLong b)
{
  return l|b.get();
}
unsigned long operator|(StoredLong b, unsigned long l)
{
  return l|b.get();
}
unsigned long operator|(StoredLong a, StoredLong b)
{
  return a.get()|b.get();
}

unsigned long operator&(unsigned long l, StoredLong b)
{
  return l&b.get();
}
unsigned long operator&(StoredLong b, unsigned long l)
{
  return l&b.get();
}
unsigned long operator&(StoredLong a, StoredLong b)
{
  return a.get()&b.get();
}

unsigned long operator^(unsigned long l, StoredLong b)
{
  return l^b.get();
}
unsigned long operator^(StoredLong b, unsigned long l)
{
  return l^b.get();
}
unsigned long operator^(StoredLong a, StoredLong b)
{
  return a.get()^b.get();
}

bool operator>(unsigned long l, StoredLong b)
{
  return l>b.get();
}
bool operator>(StoredLong b, unsigned long l)
{
  return l<b.get();
}
bool operator>(StoredLong a, StoredLong b)
{
  return a.get()>b.get();
}

bool operator<(unsigned long l, StoredLong b)
{
  return l<b.get();
}
bool operator<(StoredLong b, unsigned long l)
{
  return l>b.get();
}
bool operator<(StoredLong a, StoredLong b)
{
  return a.get()<b.get();
}

bool operator==(unsigned long l, StoredLong b)
{
  return l==b.get();
}
bool operator==(StoredLong b, unsigned long l)
{
  return l==b.get();
}
bool operator==(StoredLong a, StoredLong b)
{
  return a.get()==b.get();
}

StoredLong::StoredLong(int val) : StoredElement(),_current(val) 
{
  //std::cout << "buibiu" << std::endl;
  Solver::getEnvironment().addElement(this);

}

unsigned long StoredLong::get()
{
  return _current;
}

void StoredLong::set(unsigned long val)
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

void StoredLong::add(unsigned long val)
{
  set(val+_current);
}