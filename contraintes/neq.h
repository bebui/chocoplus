#ifndef _NEQ
#define _NEQ


#include <limits.h>
#include <vector>
#include "contraintes.h"
#include "../memory/storedbool.h"

class Neq : public ConstraintObj
{
private:
  IntVar _a;
  IntVar _b;
  
public:
  Neq(Solver*,std::vector<IntVar>);
  void propagate();
  bool entailed();
  
};


#endif