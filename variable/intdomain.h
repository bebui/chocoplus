#ifndef _INTDOM
#define _INTDOM

#include "../memory.h"
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
  Stored<int> _card;
  
  
public:
  
  IntDomain(Environment*,int,int);
  
  bool remove(int);
  bool update_inf(int);
  bool update_sup(int);
  
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

