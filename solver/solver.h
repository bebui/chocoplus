#ifndef _SOLV
#define _SOLV

#include "../memory/environment.h"
class Solver
{
private:
  static Environment _env;
  //vector<Constraint> _constraints;
  
public:
  static Environment& getEnvironment() { return _env; }
  void push();
  void pop();
  Solver();
  bool solve();
};



#endif