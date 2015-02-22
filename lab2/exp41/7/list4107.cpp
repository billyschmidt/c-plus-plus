// Bill Schmidt
// 4159697
// test program using lower_bound and upper_bound

#include <iostream>
#include <istream>
#include <vector>
#include <algorithm>
#include "data.hpp"

int main()
{
  // initialize vector
  intvector input;

  // read input into vector
  read_data(input);

  // sort using generic algorithm and member function iterators
  std::sort(input.begin(), input.end());

  // write to std output, surrounding with curly braces
  write_data(input);
  std::cin.clear();

  // new variable for looping
  int test;

  // loop until EOF keystroke
  while (std::cin >> test) {
    
    // initialize iterators using upper and lower bound function calls
    intvec_iterator upper(std::upper_bound(input.begin(), input.end(), test)); 
    intvec_iterator lower(std::lower_bound(input.begin(), input.end(), test));
    
    
    // output values from distace algorithm with upp and lower iterator values
    std::cout << "The upper bound is " << std::distance(input.begin(), upper) << '\n';
    std::cout << "The lower bound is " << std::distance(input.begin(), lower) << '\n'; 
  }
}
