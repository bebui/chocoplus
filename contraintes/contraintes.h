#ifndef _CONSTRAINT
#define _CONSTRAINT

#include <vector>
#include "../variable/intvar.h"

class ConstraintObj
{
private:
  std::vector<IntVar> _vars;
  
public:
  virtual ~ConstraintObj() {};
  ConstraintObj(std::vector<IntVar> __vars) : _vars(__vars) {}
  
  virtual void propagate() {};
  virtual bool entailed() { return 0;}
  
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