#ifndef _ENV
#define _ENF

#include <stack>
#include <vector>

class StoredInt 
{
private:
  Environment _env;
  int _current;
  int _lastsave;
  std::stack<int> _trail;
  std::stack<int> _worlds;
    
public:
  
  StoredInt(Environment&,int val = 0);
  
  int get();
  void set(int);
  void restore(int);
  void add(int);
  
};

class Environment
{
private:
  std::vector<StoredInt*> _ints;
  int _currentworld;
  
public:
  
  Environment();
  
  void push();
  void pop(int w);
  void pop();
  int getIndex();
  
};

#endif