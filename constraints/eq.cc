#include "eq.h"

Eq::Eq(Solver* __s, const std::vector<IntVar> & __vars) : ConstraintObj(__s,__vars) ,_a(__vars[0]) , _b(__vars[1]) {}


void Eq::propagate()
{
  int __ai = _a.inf();
  int __as = _a.sup();
  int __bi = _b.inf();
  int __bs = _b.sup();
  
  if (__ai > __bi) 
    _b.update_inf(__ai);
  else 
    _a.update_inf(__bi);
  
  if (__as < __bs)
    _b.update_sup(__as);
  else
    _a.update_sup(__bs);
  
  
  for (int __i = __ai ; __i != INT_MIN ; __i = _a.next(__i+1))
  {
    if(!_b.contains(__i))
      _a.remove(__i);
  }
  
  for (int __i = __bi ; __i != INT_MIN ; __i = _b.next(__i+1))
  {
    if(!_a.contains(__i))
      _b.remove(__i);
  }
  
  if (_a.cardinality() == 1 && _b.cardinality() == 1)
    _entailed.set(true);
  
}

