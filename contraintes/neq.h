#ifndef _NEQ
#define _NEQ


#include <limits.h>
#include <vector>
#include "constraint.h"
#include "../memory/storedbool.h"

class Neq : public ConstraintObj
{
private:
  IntVar _a;
  IntVar _b;
  
public:
  Neq(std::vector<IntVar>);
  void propagate();
  bool entailed();
  
};


#endif