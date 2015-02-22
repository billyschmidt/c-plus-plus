/** Changing fixed from a Class to a Class Template */

#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <cassert>
#include <cmath>
#include <iomanip>
#include <ios>
#include <istream>
#include <locale>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cstdlib>

#include "ioflags.hpp"

template<class T, int N>
class fixed
{
public:
  typedef T value_type;

  static value_type const places = N;
  static value_type const places10;

  fixed() : value_() {}

  fixed(value_type integer, value_type fraction);

  fixed(value_type integer);

  fixed(double value)
    : value_(static_cast<value_type>(value * places10 + (value < 0 ? -0.5 : 0.5)))
  {}

  std::string as_string() const;

  template<class Char, class Traits>
  bool read(std::basic_istream<Char, Traits>& strm);

  // Convert to long double
  double as_long_double() const { return static_cast<long double>(value()) / places10; }

  // Convert to double
  double as_double() const { return static_cast<double>(value()) / places10; }

  // Convert to float
  float as_float() const { return static_cast<float>(value()) / places10; }

  // Return just the integer part
  value_type round() const;

  // Return the integer part
  value_type integer() const { return value() / places10; }

  // Return the fractional part
  value_type fraction() const;

  // Addition assignment operator
  fixed& operator+=(fixed f);

  // Subtraction assignment operator
  fixed& operator-=(fixed f);

  // Multiplication assignment operator
  fixed& operator*=(fixed f);

  // Division assignment operator
  fixed& operator/=(fixed f);

  // Negate this value
  void negate();

  // Pre-increment
  fixed& operator++();

  // Post-increment
  fixed operator++(int);

  // Pre-decrement
  fixed& operator--();

  // Post-decrement
  fixed operator--(int);

  // Return the internal value
  value_type value()    const { return value_; }
private:

  // Reduce frac to the range [0, places10) by discarding digits to the right
  value_type reduce(value_type frac);
  value_type value_;
};

template<class T, int N>
typename fixed<T,N>::value_type const fixed<T,N>::places10 = static_cast<typename fixed<T,N>::value_type>(std::pow(10.0, double(places)));

// Construct a fixed value from an integer part and a fraction part
template<class T, int N>
fixed<T,N>::fixed(value_type integer, value_type fraction)
{
  if (fraction < T())
    throw std::invalid_argument("negative fraction not allowed");
  fraction = reduce(fraction);
  if (integer < T())
    value_ = integer * places10 - fraction;
  else
    value_ = integer * places10 + fraction;
}

// Construct a fixed value from an integer part with no fraction
template<class T, int N>
fixed<T,N>::fixed(value_type integer)
  : value_(integer * places10)
{}

// Get the fraction part
template<class T, int N>
typename fixed<T,N>::value_type fixed<T,N>::fraction()
  const
{
  return std::abs(value()) % places10;
}

// Reduce the fractional part to the range [0, places10)
template<class T, int N>
typename fixed<T,N>::value_type fixed<T,N>::reduce(value_type frac)
{
  // scan for zero digits on the right
  value_type f(frac);
  while (f >= places10*10 and f % 10 == 0)
    {
      f /= 10;
    }

  if (f >= places10*10)
    {
      int x(0);
     
      while (f >= places10)
	{
	  x = f % 10;
	  f /= 10;
	}

      if (x >= 5)
	++f;
      return f;
    }

  else if (f >= places10)
    {

      int x(f % 10);
      f /= 10;
      assert(f < places10);
      if (x == 5)
	{
	  if (f % 2 != 0)
	    ++f;
	  return f;
	}
      else if (x < 5)
	{
	  return f;
	}
      else
	{
	  return f + 1;
	}
    }

  assert(frac < places10);
  return frac;
}

// Round off to nearest integer
template<class T, int N>
typename fixed<T,N>::value_type fixed<T,N>::round()
  const
{
  const value_type frac(fraction());
  int adjust(value() < 0 ? -1 : +1);
  if (frac > places10/2)
    return integer()+adjust;
  else if (frac < places10/2)
    return integer();
  else if (integer() % 2 == 0)
    return integer();
  else
    return integer()+adjust;
}

// Convert to a string using fixed-point notation
template<class T, int N>
std::string fixed<T,N>::as_string()
  const
{
  std::ostringstream out;
  out << integer() << '.'
      << std::setfill('0') << std::setw(places) << fraction();
  return out.str();
}

template<class T, int N>
fixed<T,N>& fixed<T,N>::operator+=(fixed f)
{
  value_ += f.value();
  return *this;
}

template<class T, int N>
fixed<T,N>& fixed<T,N>::operator-=(fixed f)
{
  value_ -= f.value();
  return *this;
}

template<class T, int N>
fixed<T,N>& fixed<T,N>::operator*=(fixed f)
{
  value_ = (value_ * f.value()) / places10;
  return *this;
}

template<class T, int N>
fixed<T,N>& fixed<T,N>::operator/=(fixed f)
{
  value_ = (value_ * places10) / f.value();
  return *this;
}

template<class T, int N>
void fixed<T,N>::negate()
{
  value_ = -value_;
}

template<class T, int N>
fixed<T,N>& fixed<T,N>::operator++()
{
  value_ += places10;
  return *this;
}

template<class T, int N>
fixed<T,N> fixed<T,N>::operator++(int)
{
  fixed result(*this);
  ++*this;
  return result;
}

template<class T, int N>
fixed<T,N>& fixed<T,N>::operator--()
{
  value_ -= places10;
  return *this;
}

template<class T, int N>
fixed<T,N> fixed<T,N>::operator--(int)
{
  fixed result(*this);
  --*this;
  return result;
}

template<class T, int N>
template<class Char, class Traits>
bool fixed<T,N>::read(std::basic_istream<Char, Traits>& strm)
{
  ioflags flags(strm);

  value_type integer;
  char decimal;
  if (not (strm >> integer))
    return false;
  strm.unsetf(std::ios_base::skipws);
  if (not (strm >> decimal) or decimal != '.')
    {
      strm.unget();
      strm.clear(strm.rdstate() & ~strm.failbit);
      value_ = integer * places10;
      return true;
    }
  else
    {
      value_type fraction(0);
      char c;
      int p(0);

      for (;
	   p != places+1 and strm >> c and std::isdigit(c, strm.getloc());
	   ++p)
	{
	  fraction = fraction * 10 + (c - '0');
	}

      for (; p < places; ++p)
	fraction = fraction * 10;

      while (strm and std::isdigit(c, strm.getloc()))
	strm >> c;

      strm.unget();

      strm.clear(strm.rdstate() & ~strm.failbit);
      fraction = reduce(fraction);
      if (integer < 0)
	value_ = integer * places10 - fraction;
      else
	value_ = integer * places10 + fraction;
    }
  return true;
}

// Read a fixed value
template<class T, int N, class Char, class Traits>
std::basic_istream<Char, Traits>& operator>>(std::basic_istream<Char, Traits>& strm, fixed<T,N>& f)
{
  if (not f.read(strm))
    strm.setstate(strm.failbit);
  return strm;
}

// Write a fixed value
template<class T, int N, class Char, class Traits>
std::basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& strm, fixed<T,N> f)
{
  strm << f.as_string();
  return strm;
}

// Add fixed values
template<class T, int N>
fixed<T,N> operator+(fixed<T,N> a, fixed<T,N> b)
{
  a += b;
  return a;
}

// Subtract fixed values
template<class T, int N>
fixed<T,N> operator-(fixed<T,N> a, fixed<T,N> b)
{
  a -= b;
  return a;
}

// Multiply fixed values
template<class T, int N>
fixed<T,N> operator*(fixed<T,N> a, fixed<T,N> b)
{
  a *= b;
  return a;
}

// Divide fixed values
template<class T, int N>
fixed<T,N> operator/(fixed<T,N> a, fixed<T,N> b)
{
  a /= b;
  return a;
}

// Negate a fixed value
template<class T, int N>
fixed<T,N> operator-(fixed<T,N> a)
{
  a.negate();
  return a;
}

// Compare fixed values for equality by comparing the underlying values
template<class T, int N>
bool operator==(fixed<T,N> a, fixed<T,N> b)
{
  return a.value() == b.value();
}

// Compare fixed values for equality by comparing the value wih an integer
template<class T, int N>
bool operator==(T a, fixed<T,N> b)
{
  return a == b.value();
}

// Compare fixed values for equality by comparing the value wih an integer
template<class T, int N>
bool operator==(fixed<T,N> a, T b)
{
  return a.value() == b;
}

// Compare fixed values for inequality by comparing the underlying values
template<class T, int N>
bool operator!=(fixed<T,N> a, fixed<T,N> b)
{
  return not (a == b);
}

// Compare fixed values for inequality by comparing the value wih an integer
template<class T, int N>
bool operator!=(T a, fixed<T,N> b)
{
  return not (a == b);
}

// Compare fixed values for inequality by comparing the value wih an integer
template<class T, int N>
bool operator!=(fixed<T,N> a, T b)
{
  return not (a == b);
}

// Compare fixed values for less-than by comparing the underlying values
template<class T, int N>
bool operator<(fixed<T,N> a, fixed<T,N> b)
{
  return a.value() < b.value();
}

// Compare fixed values for less-than by comparing the value wih an integer
template<class T, int N>
bool operator<(T a, fixed<T,N> b)
{
  return a < b.value();
}

// Compare fixed values for less-than by comparing the value wih an integer
template<class T, int N>
bool operator<(fixed<T,N> a, T b)
{
  return a.value() < b;
}

// Compare fixed values for greater-than by comparing the underlying values.
template<class T, int N>
bool operator>(fixed<T,N> a, fixed<T,N> b)
{
  return b < a;
}

// Compare fixed values for greater-than by comparing the value wih an integer
template<class T, int N>
bool operator>(T a, fixed<T,N> b)
{
  return b < a;
}

// Compare fixed values for greater-than by comparing the value wih an integer
template<class T, int N>
bool operator>(fixed<T,N> a, T b)
{
  return b < a;
}

// Compare fixed values for less-than-or-equal by comparing the underlying values
template<class T, int N>
bool operator<=(fixed<T,N> a, fixed<T,N> b)
{
  return not (b < a);
}

// Compare fixed values for less-than-or-equal by comparing the value wih an integer
template<class T, int N>
bool operator<=(T a, fixed<T,N> b)
{
  return not (b < a);
}

// Compare fixed values for less-than-or-equal by comparing the value wih an integer
template<class T, int N>
bool operator<=(fixed<T,N> a, T b)
{
  return not (b < a);
}

// Compare fixed values for greater-than-or-equal by comparing the underlying values
template<class T, int N>
bool operator>=(fixed<T,N> a, fixed<T,N> b)
{
  return not (a < b);
}

// Compare fixed values for greater-than-or-equal by comparing the value wih an integer
template<class T, int N>
bool operator>=(T a, fixed<T,N> b)
{
  return not (a < b);
}

// Compare fixed values for greater-than-or-equal by comparing the value wih an integer
template<class T, int N>
bool operator>=(fixed<T,N> a, T b)
{
  return not (a < b);
}

#endif
