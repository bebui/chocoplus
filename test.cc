#include "memory.h"
#include "variable.h"
#include "solver.h"
#include <iostream>
#include <vector>

using namespace std;
int main()
{
  
    Solver s;
    storedvector<int> __v(s.getEnvironment());
    std::vector<Stored<int>* > __ve;
    s.push();
    for (int i = 0 ; i < 100000 ; i++)
    {
      //__v.add(i);
      __ve.push_back(new Stored<int>(s.getEnvironment(),i));
    }
    
     
     
}

