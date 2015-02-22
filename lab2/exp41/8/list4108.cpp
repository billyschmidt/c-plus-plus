// testing the comparison algorithms

#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>
#include "data.hpp"

int main()
{
  using namespace std;

  // initialize vectors
  intvector input_01;
  intvector input_02;

  // gather input
  read_data(input_01);
  cin.clear();
  read_data(input_02);

  // display vectors
  cout << "input_01: ";
  write_data(input_01);
  cout << "input_02: ";
  write_data(input_02);

  // initialize new iterator
  intvec_iterator input_01_end(input_01.begin() + min(input_01.size(), input_02.size()));

  // begin comparisons with standard library functions
  cout << boolalpha;
  cout << "equal(input_01, input_02) = " <<
    equal(input_01.begin(), input_01_end, input_02.begin()) << '\n';

  pair<intvec_iterator, intvec_iterator> 
    result(mismatch(input_01.begin(), input_01_end, input_02.begin()));
    
  // print results for comparison
  cout << "mismatch(input_01, input_02) = index " <<
    distance(input_01.begin(),
	     result.first) << '\n';
  
  cout << "lex_comp(input_01, input_02) = " <<
    lexicographical_compare(input_01.begin(), 
			    input_01.end(),
			    input_02.begin(),
			    input_02.end()) << '\n';
}
