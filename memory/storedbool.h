#ifndef _STOREDBOOL
#define _STOREDBOOL


#include <stack>
#include "environment.h"
class StoredBool : public StoredElement
{
private:
  bool _current;
  std::stack<bool> _trail;
  std::stack<int> _worlds;
    
public:
  
  StoredBool(Environment* __env,bool val = 0);
  
  bool get();
  void set(bool);
  void restore(int);
  
};

#endif