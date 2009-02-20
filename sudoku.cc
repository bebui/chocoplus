#include "memory.h"
#include "variable.h"
#include "solver.h"
#include <iostream>
#include <vector>

using namespace std;
int main()
{

  Solver s;
  int n = 9;
  
  vector<IntVar> vars;
  for (int i =0 ; i < 81 ; i++)
  {
    vars.push_back(s.make_var("x"+i,1,9));
  }  
  
  s.post(s.eq(vars[6],5));
  s.post(s.eq(vars[7],3));
  
  s.post(s.eq(vars[10],6));
  s.post(s.eq(vars[12],9));
  s.post(s.eq(vars[14],7));
  
  s.post(s.eq(vars[18],2));
  s.post(s.eq(vars[21],8));
  s.post(s.eq(vars[23],4));
  s.post(s.eq(vars[26],1));
  
  s.post(s.eq(vars[27],8));
  s.post(s.eq(vars[29],6));
  s.post(s.eq(vars[30],7));
  s.post(s.eq(vars[33],3));
  
  s.post(s.eq(vars[37],5));
  s.post(s.eq(vars[43],8));
  
  s.post(s.eq(vars[47],7));
  s.post(s.eq(vars[50],6));
  s.post(s.eq(vars[51],4));
  s.post(s.eq(vars[53],5));
  
  s.post(s.eq(vars[54],3));
  s.post(s.eq(vars[57],6));
  s.post(s.eq(vars[59],9));
  s.post(s.eq(vars[62],4));
  
  s.post(s.eq(vars[66],3));
  s.post(s.eq(vars[68],1));
  s.post(s.eq(vars[70],7));
  
  s.post(s.eq(vars[73],9));
  s.post(s.eq(vars[74],4));
  
  
  
  
  
  
  
  
  
  for (int k = 0 ; k < 9 ; k++)
  {
    for (int i =0 ; i < 9 ; i++)
    {
      for (int j = i+1 ; j < 9 ;j++)
      {
        s.post(s.neq(vars[k*9+i],vars[k*9+j]));
      }
    }
  }
  
  for (int i = 0 ; i < 9 ; i++)
  {
    for (int j =0 ; j < 81 ; j+=9)
    {
      for (int k = j+9 ; k < 81 ;k+=9)
      {
        s.post(s.neq(vars[j+i],vars[k+i]));
      }
    }
  }
  
        // Not equal constraint between each case of a sub region
  for (int ci = 0; ci < n; ci += 3) 
  {
    for (int cj = 0; cj < n; cj += 3) 
    {
      for (int i = ci; i < ci + 3; i++) 
      {
        for (int j = cj; j < cj + 3; j++) 
        {
          for (int k = ci; k < ci + 3; k++) 
          {
            for (int l = cj; l < cj + 3; l++) 
            {
              if (k != i || l != j) s.post(s.neq(vars[i*9+j], vars[k*9+l]));
            }
          }
        }
      }
    }
  }
  
  
  
  
  
  
  if (s.solve())
  {
    for (int i = 0 ; i< 9 ;i++)
    {
      for (int j =0 ; j < 9 ;j++)
      {
        cout << vars[i*9+j].get() << "\t" ;
      }
      cout << endl;
    }
    
  }
  
}
