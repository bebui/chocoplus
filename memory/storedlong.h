#ifndef _STOREDLONG
#define _STOREDLONG


#include <stack>
#include "environment.h"
class StoredLong : public StoredElement
{
private:
  unsigned long _current;
  std::stack<long> _trail;
  std::stack<int> _worlds;
    
public:
  
//  StoredLong(unsigned long val = 0);
  StoredLong(int val = 0);
  
  unsigned long get();
  void set(unsigned long);
  void add(unsigned long);
  void restore(int);
  
  void operator=(unsigned long a) {
    set(a);
  }
       
};

unsigned long operator+(unsigned long,StoredLong);
unsigned long operator+(StoredLong,unsigned long);
unsigned long operator+(StoredLong,StoredLong);

unsigned long operator|(unsigned long,StoredLong);
unsigned long operator|(StoredLong,unsigned long);
unsigned long operator|(StoredLong,StoredLong);

unsigned long operator^(unsigned long,StoredLong);
unsigned long operator^(StoredLong,unsigned long);
unsigned long operator^(StoredLong,StoredLong);

unsigned long operator&(unsigned long,StoredLong);
unsigned long operator&(StoredLong,unsigned long);
unsigned long operator&(StoredLong,StoredLong);

bool operator>(unsigned long,StoredLong);
bool operator>(StoredLong,unsigned long);
bool operator>(StoredLong,StoredLong);

bool operator<(unsigned long,StoredLong);
bool operator<(StoredLong,unsigned long);
bool operator<(StoredLong,StoredLong);

bool operator==(unsigned long,StoredLong);
bool operator==(StoredLong,unsigned long);
bool operator==(StoredLong,StoredLong);


#endif