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
    
    s.push();
    __v.add(10);
    __v.add(20);
    __v.add(30);
    s.push();
    
    cout << __v.str() << endl;
    
    __v.removeLast();
    cout << __v.str() << endl;
    s.pop();
    cout << __v.str() << endl;
    s.push();
    __v.set(1,25);
    cout << __v.str() << endl;
    
    s.pop();
    cout << __v.str() << endl;
    s.push();
    __v.add(0);
    __v.set(0,15);
    cout << __v.str() << endl;
    s.push();
    __v.add(150);
    __v.set(1,25);
    __v.set(2,35);
    __v.set(3,45);
    cout << __v.str() << endl;
    
    s.pop();
    cout << __v.str() << endl;
    
    s.pop();
    cout << __v.str() << endl;
    
     
}

