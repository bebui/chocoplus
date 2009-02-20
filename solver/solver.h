#ifndef _SOLV
#define _SOLV

#include "../memory.h"
#include "../variable.h"
#include "../constraint.h"
#include <deque>
#include <vector>
#include <string>
#include "c_queue.h"

class Solver
{
private:
  Environment _env;
  constraint_queue _queue;
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
  void propagate();
  void add_to_queue(ConstraintObj*);
  IntVar make_var(std::string,int,int);
  Constraint eq(IntVar,IntVar);
  Constraint eq(IntVar,int);
  Constraint eq(int,IntVar);
  Constraint neq(IntVar,IntVar);
  Constraint neq(IntVar,int);
  Constraint neq(int,IntVar);

};



#endif