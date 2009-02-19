#ifndef _EQ
#define _EQ


#include <limits.h>
#include <vector>
#include "contraintes.h"

class Eq : public ConstraintObj
{
private:
  IntVar _a;
  IntVar _b;
  
public:
  Eq(std::vector<IntVar>);
  void propagate();
  
};







#endif