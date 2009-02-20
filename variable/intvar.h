#include "intdomain.h"
#include <string>

#ifndef _IVAR
#define _IVAR

class IntVarObj
{
private:
  IntDomain _dom;
  std::string _name;

public:
  
  IntVarObj(Environment*,std::string,int,int);
  
  int sup();
  int inf();
  void restrict(int);
  void remove(int);
  void update_inf(int);
  void update_sup(int);
  
  int next(int);
  int prev(int);
  bool contains(int);
  
  
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
  void restrict(int);
  void remove(int);
  void update_inf(int);
  void update_sup(int);
  size_t cardinality();
  std::string getName() { return _repr->getName();}
  std::string str();
  int next(int);
  int prev(int);
  bool contains(int);
   
  
};





#endif