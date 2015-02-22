// updated rational struct with tests using member functions

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include "test.hpp"

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
    : numerator(num), denominator(den)
  {
    reduce();
  }

  // overload constructor
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
    assert(denominator != 0);
    if (denominator < 0)
      {
	denominator = -denominator;
	numerator = -numerator;
      }

    int div(gcd(numerator, denominator));
    numerator = numerator / div;
    denominator = denominator / div;  
  }

  int numerator;
  int denominator;
};

// compare for equality
bool operator==(rational const& a, rational const& b)
{
  return a.numerator == b.numerator and a.denominator == b.denominator;
}

// compare for inequality
bool operator!=(rational const& a, rational const& b)
{
  return not (a == b);
}

// compare for less-than
bool operator<(rational const& a, rational const& b)
{
  return a.numerator * b.denominator < b.numerator * a.denominator;
}

// inline compare for less-than or equal
inline bool operator<=(rational const& a, rational const& b)
{
  return not (b < a);
}

// inline compare for greater-than
inline bool operator>(rational const& a, rational const& b)
{
  return b < a;
}

// inline compare for greater-than-or-equal
inline bool operator>=(rational const& a, rational const& b)
{
  return not (b > a);
}

int main()
{
  rational a(60, 6);
  rational b(30, 3);
  rational c(-50, -5);
  rational d(400, 40);
  rational e(8, 2);

  std::cout << " Begin Running Tests... \n";

  TEST(a == b);
  TEST(a >= b);
  TEST(a <= b);
  TEST(b <= a);
  TEST(b >= a);
  TEST(b == c);
  TEST(b >= c);
  TEST(b <= c);
  TEST(a == c);
  TEST(a >= c);
  TEST(a <= c);
  TEST(e < a);
  TEST(e <= a);
  TEST(c != e);
  TEST(a > e);
  TEST(a >= e);
  TEST(a != e);
  TEST(a > e);
  TEST(a >= e);
  TEST(e != a);
  TEST(e < a);
  TEST(e <= a);
  TEST(a != e);

  std::cout << "If no errors, tests are good! \n";
}
