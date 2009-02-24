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
  void post(const Constraint &);
  
  Solver();
  bool solve();
  void propagate();
  void add_to_queue(ConstraintObj*);
  IntVar make_var(const std::string &,int,int);
  Constraint eq(const IntVar &, const IntVar &);
  Constraint eq(const IntVar &,int);
  Constraint eq(int, const IntVar &);
  Constraint neq(const IntVar &, const IntVar &);
  Constraint neq(const IntVar &,int);
  Constraint neq(int, const IntVar &);

};



#endif

