/** 
 * Bill Schmidt
 * 4159697
 * sample program testing absval function
 * with variety of argument types
 */

#include <iostream>
#include <ostream>
#include "rational.hpp"

template<class T>
T absval(T x)
{
  if (x < 0)
    return -x;
  else
    return x;
}

int main()
{
  using namespace std;

  cout << absval(-345) << '\n';
  cout << absval(-4.345) << '\n';
  cout << absval(12345678L) << '\n';
  cout << absval(-344.4322F) << '\n';
  cout << absval(-87.245F) << '\n';
  
  cout << absval(rational(123, -246)) << '\n';
  cout << absval(rational(-42, 5)) << '\n';
  cout << absval(rational(42, -5)) << '\n';
  cout << absval(rational(35,- 6)) << "\n\n";

  cout << "rational test_01(98, -6):" << '\n' << "should be: -49/3: " << '\n';
  rational test_01(98, -6);
  cout << "actual: " << test_01 << "\n\n";

  cout << "absval(test_01):" << '\n' << "should be: 49/3: " << '\n';
  cout << "actual: " << absval(test_01) << "\n\n";

  cout << "rational test_02(-2.4, 8.4):" << '\n' << "should be: -1/4: " << '\n';
  rational test_02(-2.4, 8.4);
  cout << "actual: " << test_02 << "\n\n";

  cout << "absval(test_02):" << '\n' << "should be: 1/4: " << '\n';
  cout << "actual: " << absval(test_02) << '\n';
}
