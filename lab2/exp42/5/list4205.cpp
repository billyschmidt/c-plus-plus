// program will not compile when trying to change
// middle value, proving const_iterator works.
// changing const_iterator to iterator

#include <iostream>
#include <ostream>
#include "data.hpp"

int main()
{
  // initialize and read data into vector
  intvector data;
  read_data(data);
  
  // initialize iterator at front
  intvector::iterator iter(data.begin());
  
  // advance to middle of vector
  std::advance(iter, data.size() / 2);
  
  // send to std output (be sure to dereference iterator)
  if (not data.empty()) {
    *iter = - *iter;
  }
  std::cout << "middle item = " << *iter << '\n';
}
