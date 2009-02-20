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
  IntVar a = s.make_var("a",10,12);
  IntVar b = s.make_var("b",10,11);
  
  //Constraint c = s.eq(a,b);
  Constraint c2 = s.neq(a,b);
  
  //s.post(c);
  s.post(c2);
  cout << ((s.solve()==0)?"NO SOLUTION" : "SOLVED") << endl;
//  b.update_inf(10);
  cout << a.str() << endl << b.str() << endl; 
    
 
  
  
  
}
