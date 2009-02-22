#include "solver.h"
#include "val_chooser.h"
#include "var_chooser.h"
Solver::Solver()  {}

Solver::~Solver()
{
  for (std::vector<IntVarObj*>::iterator it = _vars.begin() ; it != _vars.end() ; ++it)
  {
    delete(*it);
   // std::cout << " 1 DELETE " << std::endl;   
  }
  for (std::vector<ConstraintObj*>::iterator it = _phantom.begin() ; it != _phantom.end() ; ++it)
  {
    delete(*it);
   // std::cout << " 1 DELETE " << std::endl;   
  }
  
 // std::cout<< "normalement il n'y a plus d'objet IntVarObj" << std::endl;
}

void Solver::push()
{
  _env.push();
}

void Solver::pop()
{
  _env.pop();
}

void Solver::post(Constraint c)
{
  c.get_constraint()->record_vars();
  add_to_queue(c.get_constraint());
  _cons.push_back(c.get_constraint());
}

bool Solver::solve()
{
  std::stack<IntVarObj*> __var;
  std::stack<int> __branch;
  
  var_chooser __varc(_vars);
  val_chooser __valc;
  bool stop = false;
  int type = 0;
  
  push();
  try {
    propagate();
  }
  catch (Contradiction &c)
  {
    pop();
    return false;
  }
  while (!stop)
  {
    if (type == 0)
    {
      IntVarObj* __v = __varc.get_var();
      if (__v != NULL)
      {
        __var.push(__v);
        __branch.push(__valc.get_val(__v));
        type = 1;
      }
      else
      {
        stop = true;
      }
    }
    else if (type == 1)
    {
      try 
      {
        push();
        //std::cout<< __var.top()->str() << std::endl;
        __var.top()->restrict(__branch.top());
        //std::cout<< __var.top()->str() << std::endl;
        
        propagate();
        type = 0;
      }
      catch (Contradiction &c)
      {
        //std::cout << "Contradiction : " << c.cause << std::endl;
        type = 2;
      }
    }
    else if (type == 2)
    {
      if (!__var.empty())
      {
        try 
        {
          pop();
          //std::cout<< "POP : " <<  __var.top()->str() << std::endl;    
          IntVarObj* __v = __var.top(); __var.pop();
          int __b = __branch.top(); __branch.pop();
          __v->remove(__b);
          propagate();
          type = 0;
        }
        catch (Contradiction &c)
        {
          type = 2;
        }
      }
      else 
      {
        return false;
      }
    }
    
      
  }
  return true;
  
}

void Solver::propagate()
{
  _queue.propagate();
  
}

void Solver::add_to_queue(ConstraintObj* __cons)
{
  _queue.add(__cons);
}

IntVar Solver::make_var(std::string __name,int __inf, int __sup)
{
  IntVarObj* a = new IntVarObj(this,__name,__inf,__sup);
  //std::cout << " 1 NEW " << std::endl;
  _vars.push_back(a);
  return IntVar(a);
  
}

Constraint Solver::eq(IntVar __a, IntVar __b)
{
  std::vector<IntVar> __v;
  __v.push_back(__a);
  __v.push_back(__b);
  Eq* e= new Eq(this,__v);
  _phantom.push_back(e);
  return Constraint(e);
}

Constraint Solver::eq(IntVar __a,int __b)
{
  return eq(__a,make_var("no_name",__b,__b));
}
Constraint Solver::eq(int __b, IntVar __a)
{
  return eq(__a,__b);
}


Constraint Solver::neq(IntVar __a, IntVar __b)
{
  std::vector<IntVar> __v;
  __v.push_back(__a);
  __v.push_back(__b);
  Neq* e= new Neq(this,__v);
  _phantom.push_back(e);
  return Constraint(e);
}

Constraint Solver::neq(IntVar __a,int __b)
{
  return neq(__a,make_var("no_name",__b,__b));
}
Constraint Solver::neq(int __b, IntVar __a)
{
  return neq(__a,__b);
}

