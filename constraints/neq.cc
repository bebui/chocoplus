#include "neq.h"
Neq::Neq(Solver* __s, const std::vector<IntVar> & __vars) : ConstraintObj(__s,__vars) ,_a(__vars[0]) , _b(__vars[1]) {}

void Neq::propagate()
{
  int __ai = _a.inf();
  int __as = _a.sup();
  int __bi = _b.inf();
  int __bs = _b.sup();
  
  if (__as < __bi || __ai > __bs)
  {
    _entailed.set(true);
  }
  else
  {
    if (_a.cardinality() == 1)
    {
      //std::cout << "ai : " << __ai << std::endl;
      _b.remove(__ai);
      //std::cout << _b.str() << std::endl;
      __bi = _b.inf();
    }
    if (_b.cardinality() ==1)
    {
      //std::cout << "bi : " << __bi << std::endl;
      _a.remove(__bi);
    }
  }
  
}

