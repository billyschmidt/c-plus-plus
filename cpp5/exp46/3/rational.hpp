/** 
 * Bill Schmidt
 * 4159697
 * Rational Class Template
 */

#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_

#include <istream>
#include <ostream>
#include <sstream>
#include <limits>
#include <string>
#include <stdexcept>
#include <cassert>
#include <cstdlib>

// represent a rational number as numerator and denominator
struct rational
{
  int numerator;
  int denominator;

  // default constructor
  rational()
    : numerator(0), denominator(1)
  {}

  rational(int num)
    : numerator(num), denominator(1)
  {}
  
  rational(int num, int den)
    : numerator(num), denominator(den)
  {
    reduce();
  }
  
  rational(double r)
    : numerator(static_cast<int>(r * 10000)), denominator(10000)
  {
    reduce();
  }

  float as_float()
  {
    return static_cast<float>(numerator) / denominator;
  }

  double as_double()
  {
    return static_cast<double>(numerator) / denominator;
  }

  long double as_long_double()
  {
    return static_cast<long double>(numerator) /  denominator;
  }

  // assign numerator and denominator
  void assign(int num, int den)
  {
    numerator = num;
    denominator = den;
    reduce();
  }
 
  // reduce the numerator and denominator by their GCD
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
  
  int gcd(int n, int m)
  {
    n = std::abs(n);
    while (m != 0) {
      int tmp(n % m);
      n = m;
      m = tmp;
    }
    return n;
  }
};

// negation of rational number
rational operator-(rational const& r)
{
  return rational(-r.numerator, r.denominator);
}

// add rational numbers
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

// compare two rational numbers for equality
bool operator==(rational const& a, rational const& b)
{
  return a.numerator == b.numerator and a.denominator == b.denominator;
}

// compare two rational numbers for inequality
inline bool operator!=(rational const& a, rational const& b)
{
  return not (a == b);
}

// compare two rational numbers for less-than
bool operator<(rational const& a, rational const& b)
{
  return a.numerator * b.denominator < b.numerator * a.denominator;
}

// compare two rational numbers for less-than-or-equal
inline bool operator<=(rational const& a, rational const& b)
{
  return not (b < a);
}

// compare two rational numbers for greater-than
inline bool operator>(rational const& a, rational const& b)
{
  return b < a;
}

// compare two rational numbers for greater-than-or-equal
inline bool operator>=(rational const& a, rational const& b)
{
  return not (b > a);
}

// input operator
std::istream& operator>>(std::istream& in, rational& rat)
{
  int n(0), d(0);
  char sep('\0');
  
  if (not (in >> n >> sep)) {
    in.setstate(std::cin.failbit);
  }
  
  else if (sep != '/') {
    in.unget();
    rat.assign(n, 1);
  }
  
  else if (in >> d) {
    rat.assign(n, d);
  }
  
  else {
    in.setstate(std::cin.failbit);
  }
  
  return in;
}

// output operator
std::ostream& operator<<(std::ostream& out, rational const& rat)
{
  std::ostringstream tmp;
  tmp << rat.numerator;

  if (rat.denominator != 1) {
    tmp << '/' << rat.denominator;
    out << tmp.str();
  }
  return out;
}

#endif
