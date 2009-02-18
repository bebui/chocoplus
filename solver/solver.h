#ifndef _SOLV
#define _SOLV

#include "../memory/environment.h"
#include "../variable/intvar.h"
#include <vector>
#include <string>
class Solver
{
private:
  Environment _env;
  std::vector<IntVarObj*> _vars;
  //vector<Constraint> _constraints;
  
public:
  ~Solver();
  Environment* getEnvironment() { return &_env; }
  void push();
  void pop();
  Solver();
  bool solve();
  IntVar make_var(std::string,int,int);
};



#endif