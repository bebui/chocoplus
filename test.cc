#include "memory/storedint.h"
#include "memory/storedlong.h"
#include "memory/storedbitset.h"
#include "memory/environment.h"
#include "solver/solver.h"
#include <iostream>


using namespace std;
int main()
{
  
  Solver s;
  
  
  
  Environment& env = s.getEnvironment();
  
  
  
  
  StoredBitSet bui(env,80);
  s.push();
  for (int i = 40 ; i < 70 ; i++) bui.clear(i);
  bui.print();
  std::cout << bui.prev_clear(78) << std::endl;
  
  s.pop();
  bui.print();
  
  
  StoredInt si(env,10);
  StoredLong sl(env,9999394);
  StoredLong sl2(env,6);
  
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