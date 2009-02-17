#ifndef _STOREDLONG
#define _STOREDLONG


#include <stack>
#include "environment.h"
class StoredLong : public StoredElement
{
private:
  uint64_t _current;
  std::stack<uint64_t> _trail;
  std::stack<int> _worlds;
    
public:
  
  StoredLong(Environment& __env,uint64_t val = 0);
  
  uint64_t get();
  void set(uint64_t);
  void add(uint64_t);
  void restore(int);
  
  StoredLong& operator=(const StoredLong&);
       
};



#endif