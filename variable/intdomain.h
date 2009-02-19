#ifndef _INTDOM
#define _INTDOM

#include "../memory/environment.h"
#include "../memory/storedbitset.h"
#include "../memory/stored.h"
#include <string>  
#include <iostream>  
#include <sstream>
#include <limits.h>

class Contradiction
{
public:
  int cause;
  Contradiction(int __cause) : cause(__cause){} 
};



class IntDomain
{
  
private: 
  Stored<int> _inf;
  Stored<int> _sup;
  StoredBitSet _repr;
  int _offset;
  
  
public:
  
  IntDomain(Environment*,int,int);
  
  void remove(int);
  void update_inf(int);
  void update_sup(int);
  
  int sup();
  int inf();
  int next(int);
  int prev(int);
  bool contains(int);
  
  bool is_singleton();
  bool is_empty();
  size_t cardinality();
  std::string str();
  
  
  
};











#endif
