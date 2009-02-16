#include "memory/storedint.h"
#include "memory/storedlong.h"

#include "memory/environment.h"
#include "solver/solver.h"
#include <iostream>

using namespace std;
int main()
{
  
  Solver s;
  StoredInt si(10);
  StoredLong sl(9999394);
  StoredLong sl2(6);
  StoredLong sl3;
  sl3 = sl|sl2;
  cout << (StoredLong(12) > 0) << endl;
  s.push();
  si.set(255);
  sl.set(245245245);
  cout << si.get() << endl;
  cout << sl.get() << endl;

  s.push();
  si.set(212);
  si.set(220);
  sl.set(200);  
  s.push();
  cout << si.get() << endl;  
  si.set(25);
  cout << sl.get() << endl;
  sl.set(200);
  cout << si.get() << endl;
  cout << sl.get() << endl;
  
  s.pop();
  
  cout << si.get() << endl;
  cout << sl.get() << endl;
  
  s.pop();
  cout << si.get() << endl;
  cout << sl.get() << endl;
  
  s.pop();
  cout << si.get() << endl;
  cout << sl.get() << endl;
  
  
  
}