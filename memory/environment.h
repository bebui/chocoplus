#ifndef _ENVI
#define _ENVI


#include <vector>

class StoredElement;

class Environment
{
private:
  std::vector<StoredElement*> _elems;
  int _currentworld;
  
public:
  
  Environment();
  
  void push();
  void pop(int w);
  void pop();
  int getIndex();
  void addElement(StoredElement*);
  
};


class StoredElement
{
protected:
  int _lastsave;
  
  
public:
  virtual ~StoredElement() {};
  StoredElement() : _lastsave(0) {};
  virtual void restore(int) = 0;
  
};

#endif