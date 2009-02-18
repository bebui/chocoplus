#ifndef _ENVI
#define _ENVI


#include <vector>
#include <iostream>
class StoredElement;

class Environment
{
private:
  std::vector<StoredElement*> _elems;
  int _currentworld;
  
public:
  
  Environment();
  ~Environment();
  
  void push();
  void pop(int w);
  void pop();
  int getIndex();
  void addElement(StoredElement*);
  
};

class StoredElement
{
protected:
  Environment* _env;
  int _lastsave;
  
  
public:
  virtual ~StoredElement() {};
  StoredElement(Environment* __env) : _env(__env),_lastsave(0) {__env->addElement(this);}
  virtual void restore(int){} 
  
};

#endif