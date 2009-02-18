#include "intdomain.h"


IntDomain::IntDomain(Environment* __env, int __min, int __max) : _inf(__env,__min), _sup(__env,__max), _repr(__env,__max-__min+1),  _offset(__min)
{}

void IntDomain::remove(int __val)
{
  int min = _inf.get();
  int max = _sup.get();
  if (__val >= min && __val <= max)
  {
    _repr.clear(__val-_offset);
    
    if (__val == min)
      _inf.add(1);
    if (__val == max)
      _sup.add(-1);
    
    if (min == max && __val == min)
      throw Contradiction(0);
    
  }
}

void IntDomain::update_inf(int __inf)
{
  int min = _inf.get();
  int max = _sup.get();
  if (__inf <= max)
  {
    _repr.clear(min-_offset,__inf-_offset);
    _inf.set(__inf);
  }
  else 
  {
    throw Contradiction(1);
  }
}

void IntDomain::update_sup(int __sup)
{
  int min = _inf.get();
  int max = _sup.get();
  if (__sup >= min)
  {
    _repr.clear(__sup+1-_offset,max+1-_offset);
    _sup.set(__sup);
  }
  else 
  {
    throw Contradiction(2);
  }
}

int IntDomain::sup()
{
  return _inf.get();
}

int IntDomain::inf()
{
  return _sup.get();
}

bool IntDomain::is_singleton()
{
  return _sup.get() == _inf.get();
}

bool IntDomain::is_empty()
{
  return _repr.cardinality() == 0;
}

size_t IntDomain::cardinality()
{
  return _repr.cardinality();
}

std::string IntDomain::str()
{     
  std::ostringstream o;  
  o << "{ ";
  for (int __i = _repr.next_set(0) ; __i != -1 ; __i = _repr.next_set(++__i))
    o << (__i+_offset) << " ";
  o << "}";
  return o.str();
}



