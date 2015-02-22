// addition of arithmetic operators

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

// addition of rational numbers
rational operator+(rational const& lhs, rational const& rhs)
{
  return rational(lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator,
		  lhs.denominator * rhs.denominator);
}

// subtraction of rational numbers
rational operator-(rational const& lhs, rational const& rhs)
{
  return rational(lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator,
		  lhs.denominator * rhs.denominator);
}

// multiplication of rational numbers
rational operator*(rational const& lhs, rational const& rhs)
{
  return rational(lhs.numerator * rhs.numerator, lhs.denominator * rhs.denominator);
}

// division of rational numbers
rational operator/(rational const& lhs, rational const& rhs)
{
  return rational(lhs.numerator * rhs.denominator, lhs.denominator * rhs.numerator);
}

int main()
{
  rational a(1, 3);
  rational b(3, 6);
  rational c(432, 6);
  rational d(365, 23);
  rational e(756, -23);

  rational result_1(a * b);
  std::cout << result_1.numerator << '/' << result_1.denominator << '\n';
  
  rational result_2(a / b);
  std::cout << result_2.numerator << '/' << result_2.denominator << '\n';
  
  rational result_3(a - b);
  std::cout << result_3.numerator << '/' << result_3.denominator << '\n';
  
  rational result_4(a + b);
  std::cout << result_4.numerator << '/' << result_4.denominator << '\n';
  
  rational result_5(c * d);
  std::cout << result_5.numerator << '/' << result_5.denominator << '\n';
  
  rational result_6(e / d);
  std::cout << result_6.numerator << '/' << result_6.denominator << '\n';
  
  rational result_7(d - c);
  std::cout << result_7.numerator << '/' << result_7.denominator << '\n';
  
  rational result_8(a + e);
  std::cout << result_8.numerator << '/' << result_8.denominator << '\n';
}
