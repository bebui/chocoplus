#ifndef _NEQ
#define _NEQ


#include <limits.h>
#include <vector>
#include "constraint.h"


class Neq : public ConstraintObj
{
private:
  IntVar _a;
  IntVar _b;
  
public:
  Neq(Solver*, const std::vector<IntVar>&);
  void propagate();
  
};


#endif

