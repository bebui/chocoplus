#ifndef _CONSTRAINT
#define _CONSTRAINT

#include <vector>
#include "../memory/storedbool.h"
#include "../variable/intvar.h"
#include "../solver/solver.h"


class ConstraintObj
{
protected:
  Solver* _s;
  std::vector<IntVar> _vars;
  StoredBool _entailed;
  
public:
  virtual ~ConstraintObj() {};
  ConstraintObj(Solver* __s,std::vector<IntVar> __vars) : _s(__s), _vars(__vars),_entailed(__s->getEnvironment(),false) {}
  
  virtual void propagate() {};
  virtual bool entailed() { return _entailed.get();}
  Solver* getSolver(){return _s;}
};

class Constraint
{
private:
  ConstraintObj* _cons;
  
public:
  
  Constraint(ConstraintObj* __cons) : _cons(__cons) {}
  
  void propagate() {_cons->propagate();}
  bool entailed() { return _cons->entailed();}
  ConstraintObj* get_constraint() { return _cons;}
  
  
};








#endif