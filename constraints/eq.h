#ifndef _EQ
#define _EQ


#include <limits.h>
#include <vector>
#include "constraint.h"


class Eq : public ConstraintObj 
{
private:
  IntVar _a;
  IntVar _b;
  
public:
  Eq(Solver*,std::vector<IntVar>);
  void propagate();
  
};

#endif
