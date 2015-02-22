// rewriting 42-3 to use const_iterator

#include <iostream>
#include <ostream>
#include "data.hpp"

int main()
{
  // initialize vector
  intvector data;

  // read data into vector
  read_data(data);
  
  // initialize iterator
  intvector::const_iterator iter(data.begin());
  
  // advance to middle of vector (divide number of elements by 2)
  std::advance(iter, data.size() / 2);
  
  // send to std output with message
  if (not data.empty()) {
    std::cout << "the item in the middle is: " << *iter << '\n';
  }
}
