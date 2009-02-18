#ifndef _INTDOM
#define _INTDOM

#include "../memory/environment.h"
#include "../memory/storedbitset.h"
#include "../memory/storedint.h"
#include <string>  
#include <iostream>  
#include <sstream>

class Contradiction
{
public:
  int cause;
  Contradiction(int __cause) : cause(__cause){} 
};



class IntDomain
{
  
private: 
  StoredInt _inf;
  StoredInt _sup;
  StoredBitSet _repr;
  int _offset;
  
  
public:
  
  IntDomain(Environment*,int,int);
  
  void remove(int);
  void update_inf(int);
  void update_sup(int);
  
  int sup();
  int inf();
  bool is_singleton();
  bool is_empty();
  size_t cardinality();
  std::string str();
  
  
  
};











#endif