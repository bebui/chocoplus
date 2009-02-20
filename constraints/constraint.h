#ifndef _CONSTRAINT
#define _CONSTRAINT

#include <vector>
#include "../variable.h"
#include "../memory.h"

class Solver;
class ConstraintObj
{
protected:
  Solver* _s;
  std::vector<IntVar> _vars;
  Stored<bool> _entailed;
  bool _inqueue;
  
public:
  virtual ~ConstraintObj() {};
  ConstraintObj(Solver*,std::vector<IntVar>);
  
  virtual void propagate() {}
  virtual bool entailed();
  void record_vars();
  Solver* getSolver();
  bool in_queue();
  void set_in_queue(bool);
};

class Constraint
{
private:
  ConstraintObj* _cons;
  
public:
  
  Constraint(ConstraintObj*);
  
  void propagate();
  bool entailed();
  ConstraintObj* get_constraint();
  
  
};








#endif