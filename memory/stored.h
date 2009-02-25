#ifndef _STOREDT
#define _STOREDT

#include <stack>
#include "environment.h"
#include "../signals.h"
#include "boost/bind.hpp"
template <class T>
class Stored : public StoredElement
{
    private:
        T _current;
        std::stack<T> _trail;
        std::stack<int> _worlds;

    public:

        Stored(Environment* __env,T val = 0) : StoredElement(__env),_current(val)
        {
            backtrack.connect(boost::bind(&Stored::restore, this, _1));
        }

        T get() const
        {
            return _current;
        }

        void set(const T & val)
        {
            int widx =_env->getIndex();
            if (widx > _lastsave)
            {
                _trail.push(_current);
                _worlds.push(_lastsave);
                _lastsave = widx;
            }
            _current = val;
        }

        void restore()
        {
                 _worlds.pop();
                  _trail.pop();
        }
        void restore(int widx)
        {
            if (widx < _lastsave)
            {
                while (_worlds.top() > widx)
                {
                    _worlds.pop();
                    _trail.pop();
                }
                _current = _trail.top(); _trail.pop();
                _lastsave = _worlds.top(); _worlds.pop();
            }
        }

        void add(const T & val)
        {
            set(val+_current);
        }
};

#endif

