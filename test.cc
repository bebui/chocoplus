#include "memory/storedint.h"
#include "memory/storedlong.h"
#include "memory/storedbitset.h"
#include "variable/intdomain.h"
#include "memory/environment.h"
#include "solver/solver.h"
#include "contraintes/eq.h"
#include <iostream>
#include <vector>

using namespace std;
int main()
{
  
  Solver s;
  
  IntVar a = s.make_var("a",10,20);
  IntVar b = s.make_var("b",5,11);
  
  Constraint c = s.eq(a,b);
  
  s.post(c);
  cout << s.solve() << endl;
  cout << a.str() << endl << b.str() << endl; 
    
  
  
  
}