// program to reveal the nature of the reverse_iterator's base iterator
// HINT: fill vector with sequence of ints
//       use reverse iterator to get middle value
//       compare with value of iterator's base()

#include <iostream>
#include <ostream>
#include <algorithm>
#include <cassert>
#include "data.hpp"
#include "sequence.hpp"

int main()
{
  using namespace std;

  // initialize vector
  intvector input(10);
  
  // use generate algorithm with call to sequence
  generate(input.begin(), input.end(), sequence(1));

  // send to std output  
  write_data(input);

  // initialize iterator at beginning  
  intvector::iterator iter(input.begin());  
  iter += 10;
  cout << *iter << '\n';
    
  // initialize new iterator
  intvector::reverse_iterator iter_reverse(input.rbegin());
  cout << *iter_reverse << '\n';
  iter_reverse+= 9;

  // send to std output  
  cout << *iter_reverse << '\n'
	    << *iter_reverse.base() << '\n'
	    << *input.rend().base() << '\n';
  
  // run  asserts to be check equality with base()
  assert(input.rbegin().base() == input.end());  
  assert(input.rend().base() == input.begin());
}
