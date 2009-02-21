#ifndef _STOREDVECTORT
#define _STOREDVECTORT

#include <stack>
#include <string>
#include <sstream>

#include "environment.h"
#include "stored.h"
template <class T>
class storedvector
{
private:
  Environment* _env;
  Stored<size_t> _size;
  typedef Stored<T> StoredT;
  std::vector<StoredT*> _current;
  
        
public:
  storedvector(Environment* __env) : _env(__env), _size(__env,0) {}
  ~storedvector() {
    for (size_t __i = 0 ; __i < _current.size() ; __i++)
    {
      delete _current[__i];
    }
  }
  
  T get(size_t __idx)
  {
    return _current[__idx]->get();
  }

  void set(size_t __idx, T __val)
  {
    _current[__idx]->set(__val);
  }
        
  void add(T __val)
  {
    _current.push_back(new StoredT(_env,__val));
    _size.add(1);
  }
  
  T removeLast()
  {
    if (_size.get() > 0)
    {
      _size.add(-1);
      return _current[_size.get()]->get();
    }
    return NULL;
  }
  
  std::string str()
  {
    std::ostringstream o;  
    o << "[ ";
    for (size_t __i = 0 ; __i < _size.get() ; __i++)
      o << _current[__i]->get() << " ";
    o << "]";
    return o.str();
  }

};

#endif
