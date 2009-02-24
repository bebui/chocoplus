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
  
  int sup() const;
  int inf() const;
  int get() const;
  bool restrict(int);
  bool remove(int);
  bool update_inf(int);
  bool update_sup(int);
  
  int next(int) const;
  int prev(int) const;
  bool contains(int) const;
  
  void record(ConstraintObj*);
  std::set<ConstraintObj*> get_constraints() const;
  
  size_t cardinality() const;
  std::string getName() const { return _name;}
  std::string str() const;
  
};

class IntVar
{
private:
  IntVarObj* _repr;
  
public:
  IntVar(IntVarObj*);
  int sup() const;
  int inf() const;
  int get() const;
  bool restrict(int);
  bool remove(int);
  bool update_inf(int);
  bool update_sup(int);
  size_t cardinality() const;
  std::string getName() const { return _repr->getName();}
  std::string str() const;
  int next(int) const;
  int prev(int) const;
  bool contains(int) const;
  IntVarObj* get_obj() const { return _repr;}
   
  
};





#endif

