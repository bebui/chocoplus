#include "storedlong.h"
#include <iostream>
#include <boost/dynamic_bitset.hpp>
int main(int, char*[]) {
  boost::dynamic_bitset<StoredLong> x(5); // all 0's by default
  x[0] = 1;
  x[1] = 1;
  x[4] = 1;
  for (boost::dynamic_bitset<StoredLong>::size_type i = 0; i < x.size(); ++i)
    std::cout << x[i];
  std::cout << "\n";
  std::cout << x << "\n";
  return EXIT_SUCCESS;
}
