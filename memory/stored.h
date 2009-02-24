#ifndef _STOREDT
#define _STOREDT

#include <stack>
#include "environment.h"
template <class T>
class Stored : public StoredElement
{
    private:
        T _current;
        std::stack<T> _trail;
        std::stack<int> _worlds;

    public:

        Stored(Environment* __env,T val = 0) : StoredElement(__env),_current(val) {}

        T get() const
        {
            return _current;
        }

        void set(T val)
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

        void add(T val)
        {
            set(val+_current);
        }
};

#endif

