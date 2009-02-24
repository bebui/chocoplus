#include "environment.h"

Environment::Environment(): _currentworld(0){}

Environment::~Environment()
{}

void Environment::push()
{
  _currentworld++;
}

int Environment::getIndex() const
{
  return _currentworld;
}

void Environment::addElement(StoredElement* si)
{
  //std::cout << "addInt" << std::endl;
  _elems.push_back(si);
  //std::cout << _ints.size() << std::endl;
}

void Environment::pop(int w)
{
  //std::cout << _ints.size() << std::endl;
  for (std::vector<StoredElement*>::iterator it = _elems.begin(); it!=_elems.end(); ++it)
  {
    //std::cout << "bui" << std::endl;
    (*it)->restore(w);
  }
  _currentworld = w;
}

void Environment::pop()
{
  pop(_currentworld-1);
}

