#ifndef _CONSTRAINT
#define _CONSTRAINT

#include <vector>
#include "../variable/intvar.h"
class Contrainte
{
private:
  std::vector<IntVar> _vars;
  
public:
  Contrainte(IntVar __vars) : _vars(__vars) {}
  
  virtual void propagate(){}
};








#endif