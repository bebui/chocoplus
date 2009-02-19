#ifndef _SOLV
#define _SOLV

#include "../memory/environment.h"
#include "../variable/intvar.h"
//#include "../contraintes/contraintes.h"
#include "../contraintes/eq.h"
#include <vector>
#include <string>
class ConstraintObj;
class Constraint;
class Solver
{
private:
  Environment _env;
  std::vector<IntVarObj*> _vars;
  std::vector<ConstraintObj*> _cons;
  
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