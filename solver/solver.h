#ifndef _SOLV
#define _SOLV

#include "../memory.h"
#include "../variable.h"
#include "../constraint.h"
#include <vector>
#include <string>

class Solver
{
private:
  Environment _env;
  std::vector<IntVarObj*> _vars;
  std::vector<ConstraintObj*> _cons;
  std::vector<ConstraintObj*> _phantom;
  
public:
  ~Solver();
  Environment* getEnvironment() { return &_env; }
  void push();
  void pop();
  void post(Constraint);
  
  Solver();
  bool solve();
  IntVar make_var(std::string,int,int);
  Constraint eq(IntVar,IntVar);
};



#endif