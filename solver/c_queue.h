#ifndef _QUEUE
#define _QUEUE


#include <deque>
class ConstraintObj;
class constraint_queue
{
private:
  std::deque<ConstraintObj*> _queue;
  
public:
  void add(ConstraintObj*);
  void propagate();
  void empty();
  
};



#endif

