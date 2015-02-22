// Bill Schmidt
// 4159697
// adding contructors for making a rational number from one integer

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
  // constructor
  rational(int num, int den)
    :numerator(num), denominator(den)
  {
    reduce();
  }

  // overload constructor for only one int
  rational(int num)
    : numerator(num), denominator(1)
  {}

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
  rational test_01(24652);
  rational pi(1420, 452);
  std::cout << "pi is about " << pi.numerator << "/" << pi.denominator << '\n';
  std::cout << "Test_02 = "   << test_01.numerator << "/" << test_01.denominator << '\n';
}


