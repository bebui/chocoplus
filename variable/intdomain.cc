#include "intdomain.h"


IntDomain::IntDomain(Environment* __env, int __min, int __max) : _inf(__env,__min), _sup(__env,__max), 
                                                                 _repr(__env,__max-__min+1),  _offset(__min), 
                                                                 _card(__env,__max-__min+1)
{}

bool IntDomain::remove(int __val)
{
  int min = _inf.get();
  int max = _sup.get();
  if (__val >= min && __val <= max&& _repr.get(__val-_offset))
  {
    if (min == max && __val == min)
    {
      //std::cout<< min << "  " << max << "  " << __val << std::endl;
      throw Contradiction(0);
      
    }
    
    _repr.clear(__val-_offset);
    _card.add(-1);
    
    if (__val == min)
      _inf.set(_repr.next_set(min-_offset)+_offset);
    if (__val == max)
      _sup.set(_repr.prev_set(max-_offset)+_offset);
    
  
    
    return true;
  }
  return false;
}

bool IntDomain::update_inf(int __inf)
{
  int min = _inf.get();
  int max = _sup.get();
  if (__inf <= max )
  {
    if (__inf > min)
    {
      for (int __i = __inf-1 ; __i >= min ; __i--)
        remove(__i);
      return true;    
    }
  }
  else 
  {
    throw Contradiction(1);
  }
  return false;
}

bool IntDomain::update_sup(int __sup)
{
  int min = _inf.get();
  int max = _sup.get();
  if (__sup >= min)
  {
    if (__sup < max)
    {
      for (int __i = __sup+1 ; __i <= max ; __i++)
        remove(__i);
      return true;
    }
  }
  else 
  {
    throw Contradiction(2);
  }
  return false;
}

int IntDomain::sup() const
{
  return _sup.get();
}

int IntDomain::inf() const
{
  return _inf.get();
}

int IntDomain::next(int __val) const
{
  if (__val >= inf() && __val <= sup())
  {
    int __idx = __val - _offset;
    int __next = _repr.next_set(__idx);
    if (__next != -1) 
      return __next+_offset;
  }
  return INT_MIN;
}
int IntDomain::prev(int __val) const
{
  if (__val >= inf() && __val <= sup())
  {
    int __idx = __val - _offset;
    int __prev = _repr.prev_set(__idx);
    if (__prev != -1) 
      return __prev+_offset;
  }
  return INT_MIN;
}

bool IntDomain::contains(int __val) const
{
  return _repr.get(__val-_offset);
}

bool IntDomain::is_singleton() const
{
  return _sup.get() == _inf.get();
}

bool IntDomain::is_empty() const
{
  
  return _repr.cardinality() == 0;
}

size_t IntDomain::cardinality() const
{
  //assert(_card.get() == _repr.cardinality());
  return _card.get();
}

std::string IntDomain::str() const
{     
  std::ostringstream o;  
  o << "{ ";
  for (int __i = _repr.next_set(0) ; __i != -1 ; __i = _repr.next_set(++__i))
    o << (__i+_offset) << " ";
  o << "}";
  return o.str();
}

