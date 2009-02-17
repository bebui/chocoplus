#ifndef _STOREDINT
#define _STOREDINT


#include <stack>
#include "environment.h"
class StoredInt : public StoredElement
{
private:
  const static int BUI = 0 << 6;
  int _current;
  std::stack<int> _trail;
  std::stack<int> _worlds;
    
public:
  
  StoredInt(Environment& __env,int val = 0);
  
  int get();
  void set(int);
  void add(int);
  void restore(int);
  
};

#endif