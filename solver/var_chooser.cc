#include "var_chooser.h"
#include "../variable.h"

var_chooser::var_chooser(std::vector<IntVarObj*> __vars) : _vars(__vars) {}

IntVarObj* var_chooser::get_var() const
{
  IntVarObj* __v = NULL;
  int min = INT_MAX;
  for (std::vector<IntVarObj*>::const_iterator it = _vars.begin() ; it != _vars.end() ; ++it)
  {
    int __m  = (*it)->cardinality();
    if (__m > 1 && __m < min)
    {
      min = __m;
      __v = (*it);
    }
  }
  return __v;
}
