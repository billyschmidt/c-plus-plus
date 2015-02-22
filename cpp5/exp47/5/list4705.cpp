/** 
 * Bill Schmidt
 * 4159697
 * adding the IO operators
 * and performing simple test 
 */

#include <iostream>
#include <istream>
#include <ostream>

#include "rational.hpp"

int main()
{
  using namespace std;

  rational<int> test_int;
  
  while (cin) {
    cin >> test_int;
    cout << test_int << '\n';
  }
}
