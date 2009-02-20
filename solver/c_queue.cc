#include "c_queue.h"
#include "../constraint.h"

void constraint_queue::add(ConstraintObj* __cons)
{
  if (!__cons->in_queue() && !__cons->entailed())
  {
    __cons->set_in_queue(true);
    _queue.push_front(__cons);
  }
}

void constraint_queue::propagate()
{
  while(!_queue.empty())
  {
    ConstraintObj* __c = _queue.back();
    _queue.pop_back();
    __c->set_in_queue(false);
    __c->propagate();
  }
  
}

void constraint_queue::empty()
{
  while(!_queue.empty())
  {
    ConstraintObj* __c = _queue.back();
    _queue.pop_back();
    __c->set_in_queue(false);
  }  
}