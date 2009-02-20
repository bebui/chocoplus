#ifndef _IVAR
#define _IVAR

#include "intdomain.h"
#include <limits.h>
#include <string>
#include <set>
class Solver;
class ConstraintObj;
class IntVarObj
{
private:
  Solver* _s;
  
  std::set<ConstraintObj*> _cons;
  IntDomain _dom;
  std::string _name;

public:
  
  IntVarObj(Solver*,std::string,int,int);
  
  int sup();
  int inf();
  int get();
  bool restrict(int);
  bool remove(int);
  bool update_inf(int);
  bool update_sup(int);
  
  int next(int);
  int prev(int);
  bool contains(int);
  
  void record(ConstraintObj*);
  std::set<ConstraintObj*> get_constraints();
  
  size_t cardinality();
  std::string getName() { return _name;}
  std::string str();
  
};

class IntVar
{
private:
  IntVarObj* _repr;
  
public:
  IntVar(IntVarObj*);
  int sup();
  int inf();
  int get();
  bool restrict(int);
  bool remove(int);
  bool update_inf(int);
  bool update_sup(int);
  size_t cardinality();
  std::string getName() { return _repr->getName();}
  std::string str();
  int next(int);
  int prev(int);
  bool contains(int);
  IntVarObj* get_obj() { return _repr;}
   
  
};





#endif