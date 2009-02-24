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
  
  int sup() const;
  int inf() const;
  int next(int) const;
  int prev(int) const;
  bool contains(int) const;
  
  bool is_singleton() const;
  bool is_empty() const;
  size_t cardinality() const;
  std::string str() const;
  
  
  
};

#endif

