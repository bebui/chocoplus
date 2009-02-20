#include "memory.h"
#include "variable.h"
#include "solver.h"
#include <iostream>
#include <vector>

using namespace std;
int main()
{
  
  Solver s;
  

  s.push();
  IntVar a = s.make_var("a",10,20);
  IntVar b = s.make_var("b",5,11);
  
  Constraint c = s.eq(a,b);
  
  s.post(c);
  cout << s.solve() << endl;
  cout << a.str() << endl << b.str() << endl; 
    
  s.pop();
  cout << endl;  
  cout << a.str() << endl << b.str() << endl; 
  
  
  
}
