// Bill Schmidt
// 4159697
// modifying the rational type to accept negative denominators
// following book's suggestion to modify reduce function

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <ostream>

int gcd(int n, int m)
{
  n = abs(n);
  while (m != 0) {
    int tmp(n % m);
    n = m;
    m = tmp;
  }
  return n;
}

struct rational
{
  rational(int num, int den)
    :numerator(num), denominator(den)
  {
    reduce();
  }

  void assign(int num, int den)
  {
    numerator = num;
    denominator = den;
    reduce();
  }

  void reduce()
  {
    // check for div by zero
    assert(denominator != 0);

    // if den is negative, swap sign
    if (denominator < 0)
      {
	denominator = -denominator;
	numerator = -numerator;
      }

    // initialize div variable to value of GCD function call
    int div(gcd(numerator, denominator));
  
    //set values accordingly
    numerator = numerator / div;
    denominator = denominator / div;
  }
  int numerator;
  int denominator;
};

int main()
{
  // check with neg ints
  rational pi(-1420, -452);
  std::cout << "pi is about " << pi.numerator << "/" << pi.denominator << '\n';
}

