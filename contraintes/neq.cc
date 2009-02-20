#include "neq.h"
Neq::Neq(Solver* __s,std::vector<IntVar> __vars) : ConstraintObj(__s,__vars) ,_a(__vars[0]) , _b(__vars[1]) {}

void Neq::propagate()
{
  int __ai = _a.inf();
  int __as = _a.sup();
  int __bi = _b.inf();
  int __bs = _b.sup();
  
  if (__as < __bi || __ai > __bs)
  {
    //_entailed.set(true);
  }
  else
  {
    
  }
  
}


bool Neq::entailed()
{
  return 0;//_entailed.get();
}