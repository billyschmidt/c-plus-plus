// Bill Schmidt
// 4159697
// read integesrs from the standard input
// and use find_if and int_range to find
// the first value within the range

#include <algorithm>
#include <iostream>
#include <ostream>
#include "data.hpp"
#include "intrange.hpp"

int main()
{
  // initialize vector and gathert input using header file functions
  intvector input;
  read_data(input);
  write_data(input);

  // use find_if and int_range to locate values with desired range
  // using header to initialize iterator
  intvec_iterator iter(std::find_if(input.begin(), input.end(), intrange(10, 20)));
  if (iter == input.end())
    std::cout << "No values were in that range [10, 20].\n";
  else
    // !! dereference iterators !!
    std::cout << *iter << " is the first value in the range [10, 20].\n";
}
