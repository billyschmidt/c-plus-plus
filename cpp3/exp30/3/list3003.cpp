// updated version with operator that takes an int as an arg

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

  // operator that takes an int as an arg
  rational& operator=(int num)
  {
    this->numerator = num;
    this->denominator = 1;
    return *this;
  }

  // absolute value function
  rational absval(rational const& a)
  {
    return rational(abs(a.numerator), a.denominator);
  }

  // float conversion
  float as_float()
  {
    return static_cast<float>(numerator) / denominator;
  }

  // double conversion
  double as_double()
  {
    return numerator / static_cast<double>(denominator);
  }

  // long double conversion
  long double as_long_double()
  {
    return static_cast<long double>(numerator) / 
      static_cast<long double>(denominator);
  }

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
  std::cout << result_8.numerator << '/' << result_8.denominator << '\n';;

  // floating point tests
  rational f(3456, 735);
  rational g(345*765, 234*234);
  double h(15467), i(39.87);
  long j = 8 * g.as_double() * h;
  std::cout << "g = " << g.as_long_double() << '\n';
  std::cout << "f = " << f.as_float() << '\n';
  f=1;
  std::cout << f.numerator << '\n' << f.denominator << '\n';
}
