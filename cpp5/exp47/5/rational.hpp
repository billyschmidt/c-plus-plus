/**
 * Bill Schmidt
 * 4159697 
 * Rational Class Template
 **/

#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_

#include <istream>
#include <ostream>
#include <sstream>
#include <limits>
#include <string>
#include <stdexcept>
#include "gcd.hpp"
#include "ioflags.hpp"

// represent rational number as numerator and denominator
template<class T>
class rational
{
public:
  // typedef for readability and maintainability
  typedef T value_type;

  // exception class if the denominator is ever zero
  class zero_denominator : public std::logic_error
  {
  public:
    // construct exception object
    zero_denominator(std::string const& what) : logic_error(what) {}
  };

  // default constructor and constructor from a single value
  rational(value_type num = 0): numerator_(num), denominator_(1) {}

  // make a rational number
  rational(value_type num, value_type den);

  // initialize the rational number with an approximation of r
  rational(double r);

  // copy from a different type of rational
  template<class U>
  rational(rational<U> const& that);

  // return the numerator
  value_type numerator() const
  {
    return numerator_; 
  }

  // return the denominator
  value_type denominator() const
  { 
    return denominator_; 
  }
  
  // convert the rational number to another type
  template<class U>
  U as() const
  { 
    return static_cast<U>(numerator()) / denominator();
  }
  
  // assign integer
  rational& operator=(value_type);

  // assign rational with different size
  template<class U>
  rational& operator=(rational<U> const& rhs);

  // addition operator
  rational& operator+=(rational const& rhs);

  // addition operator
  rational& operator+=(value_type const& rhs);

  // subtraction operator
  rational& operator-=(rational const& rhs);

  // subtraction operator
  rational& operator-=(value_type const& rhs);

  // multiplication operator
  rational& operator*=(rational const& rhs);

  // multiplication operator
  rational& operator*=(value_type const& rhs);

  // division operator
  rational& operator/=(rational const& rhs);

  // division operator
  rational& operator/=(value_type const& rhs);

  // pre-increment
  rational& operator++();

  // pre-decrement
  rational& operator--();

  // post-increment
  rational operator++(int);

  // post-decrement
  rational operator--(int);

private:
  void reduce();
  void normalize();

  template<class U>
  value_type scale(U value);

  value_type numerator_;
  value_type denominator_;
};

template<class T>
rational<T>::rational(value_type num, value_type den)
  : numerator_(num),
    denominator_(den == value_type() ? throw zero_denominator("zero denominator") : den)
{
  normalize();
}

template<class T>
rational<T>::rational(double r)
  : numerator_(static_cast<T>(r / 100000)), denominator_(static_cast<T>(100000))
{}

template<class T>
template<class U>
rational<T>::rational(rational<U> const& that)
  : numerator_(scale<U>(that.numerator())), denominator_(scale<U>(that.denominator()))
{
  reduce();
}

template<class T>
template<class U>
T rational<T>::scale(U value)
{
  if (std::numeric_limits<T>::digits >= std::numeric_limits<U>::digits)
    return T(value);
  else
    return T(value >> (std::numeric_limits<U>::digits - std::numeric_limits<T>::digits));
}

template<class T>
void rational<T>::normalize()
{
  if (denominator_ < value_type())
    {
      denominator_ = -denominator_;
      numerator_ = -numerator_;
    }
  reduce();
}

template<class T>
void rational<T>::reduce()
{
  value_type div(gcd(numerator(), denominator()));
  if (div == value_type())
    throw zero_denominator("zero denominator");
  numerator_ /= div;
  denominator_ /= div;
}

template<class T>
rational<T>& rational<T>::operator=(T num)
{
  numerator_ = num;
  denominator_ = value_type(1);
  return *this;
}

template<class T>
template<class U>
rational<T>& rational<T>::operator=(rational<U> const& rhs)
{
  numerator_ = scale<U>(rhs.numerator());
  denominator_ = scale<U>(rhs.denominator());
  reduce();
  return *this;
}

template<class T>
rational<T>& rational<T>::operator+=(rational const& rhs)
{
  numerator_ = numerator() * rhs.denominator() + rhs.numerator() * denominator();
  denominator_ *= rhs.denominator();
  reduce();
  return *this;
}

template<class T>
rational<T>& rational<T>::operator+=(value_type const& rhs)
{
  numerator_ = numerator() + rhs * denominator();
  reduce();
  return *this;
}

template<class T>
rational<T>& rational<T>::operator-=(rational const& rhs)
{
  numerator_ = numerator() * rhs.denominator() - rhs.numerator() * denominator();
  denominator_ *= rhs.denominator();
  reduce();
  return *this;
}

template<class T>
rational<T>& rational<T>::operator-=(value_type const& rhs)
{
  numerator_ = numerator() - rhs * denominator();
  reduce();
  return *this;
}

template<class T>
rational<T>& rational<T>::operator*=(rational const& rhs)
{
  numerator_ *= rhs.numerator();
  denominator_ *= rhs.denominator();
  reduce();
  return *this;
}

template<class T>
rational<T>& rational<T>::operator*=(value_type const& rhs)
{
  numerator_ *= rhs;
  reduce();
  return *this;
}

template<class T>
rational<T>& rational<T>::operator/=(rational const& rhs)
{
  if (rhs.numerator() == value_type())
    throw zero_denominator("divide by zero");
  numerator_ *= rhs.denominator();
  denominator_ *= rhs.numerator();
  normalize();
  return *this;
}

template<class T>
rational<T>& rational<T>::operator/=(value_type const& rhs)
{
  if (rhs == value_type())
    throw zero_denominator("divide by zero");
  denominator_ *= rhs;
  normalize();
  return *this;
}

template<class T>
rational<T>& rational<T>::operator++()
{
  numerator_ += denominator();
  return *this;
}

template<class T>
rational<T> rational<T>::operator++(int)
{
  rational result(*this);
  ++*this;
  return result;
}

template<class T>
rational<T>& rational<T>::operator--()
{
  numerator_ -= denominator();
  return *this;
}

template<class T>
rational<T> rational<T>::operator--(int)
{
  rational result(*this);
  --*this;
  return result;
}

// negate a rational number
template<class T>
rational<T> operator-(rational<T> const& r)
{
  return rational<T>(-r.numerator(), r.denominator());
}

template<class T>
rational<T> absval(rational<T> const& r)
{
  using namespace std;
  return rational<T>(abs(r.numerator()), r.denominator());
}

// addition
template<class T>
rational<T> operator+(rational<T> lhs, rational<T> const& rhs)
{
  lhs += rhs;
  return lhs;
}

// addition
template<class T>
rational<T> operator+(rational<T> lhs, T const& rhs)
{
  lhs += rhs;
  return lhs;
}

// addition
template<class T>
rational<T> operator+(T const& lhs, rational<T> rhs)
{
  rhs += lhs;
  return rhs;
}

// subtraction
template<class T>
rational<T> operator-(rational<T> lhs, rational<T> const& rhs)
{
  lhs -= rhs;
  return lhs;
}

// subtraction
template<class T>
rational<T> operator-(rational<T> lhs, T const& rhs)
{
  lhs -= rhs;
  return lhs;
}

// subtraction
template<class T>
rational<T> operator-(T const& lhs, rational<T> rhs)
{
  rhs += -lhs;
  return -rhs;
}

// multiplication
template<class T>
rational<T> operator*(rational<T> lhs, rational<T> const& rhs)
{
  lhs *= rhs;
  return lhs;
}

// multiplication
template<class T>
rational<T> operator*(rational<T> lhs, T const& rhs)
{
  lhs *= rhs;
  return lhs;
}

// multiplication
template<class T>
rational<T> operator*(T const& lhs, rational<T> rhs)
{
  rhs *= lhs;
  return rhs;
}

// division
template<class T>
rational<T> operator/(rational<T> lhs, rational<T> const& rhs)
{
  lhs /= rhs;
  return lhs;
}

// division
template<class T>
rational<T> operator/(rational<T> lhs, T const& rhs)
{
  lhs /= rhs;
  return lhs;
}

// division
template<class T>
rational<T> operator/(T const& lhs, rational<T> rhs)
{
  return rational<T>(lhs * rhs.denominator(), rhs.numerator());
}


// equality comparison
template<class T, class U>
bool operator==(rational<T> const& a, rational<U> const& b)
{
  return a.numerator() == b.numerator() and
    a.denominator() == b.denominator();
}

// equality comparison
template<class T>
bool operator==(rational<T> const& lhs, T rhs)
{
  return lhs.denominator() == 1 and
    lhs.numerator()   == rhs;
}

// equality comparison
template<class T>
bool operator==(T lhs, rational<T> const& rhs)
{
  return rhs.denominator() == 1 and
    rhs.numerator()   == lhs;
}

// less-than comparison
template<class T>
bool operator<(rational<T> const& a, rational<T> const& b)
{
  return a.numerator() * b.denominator() < b.numerator() * a.denominator();
}

// less-than comparison
template<class T>
bool operator<(rational<T> const& a, T const& b)
{
  return a.numerator() < b * a.denominator();
}

// less-than comparison
template<class T>
bool operator<(T const& a, rational<T> const& b)
{
  return a * b.denominator() < b.numerator();
}

// inequality comparison
template<class T, class U>
inline bool operator!=(rational<T> const& a, rational<U> const& b)
{
  return not (a == b);
}

// inequality comparison
template<class T>
inline bool operator!=(rational<T> const& a, T b)
{
  return not (a == b);
}

// inequality comparison
template<class T>
inline bool operator!=(T a, rational<T> const& b)
{
  return not (a == b);
}

// less-than-or-equal comparison
template<class T>
inline bool operator<=(rational<T> const& a, rational<T> const& b)
{
  return not (b < a);
}

// less-than-or-equal comparison
template<class T>
inline bool operator<=(rational<T> const& a, T const& b)
{
  return not (b < a);
}

// less-than-or-equal comparison
template<class T>
inline bool operator<=(T const& a, rational<T> const& b)
{
  return not (b < a);
}

// greater-than comparison
template<class T>
inline bool operator>(rational<T> const& a, rational<T> const& b)
{
  return b < a;
}

// greater-than comparison
template<class T>
inline bool operator>(rational<T> const& a, T const& b)
{
  return b < a;
}

// greater-than comparison
template<class T>
inline bool operator>(T const& a, rational<T> const& b)
{
  return b < a;
}

// greater-than-or-equal comparison
template<class T>
inline bool operator>=(rational<T> const& a, rational<T> const& b)
{
  return not (b > a);
}

// greater-than-or-equal comparison
template<class T>
inline bool operator>=(rational<T> const& a, T const& b)
{
  return not (b > a);
}

// greater-than-or-equal comparison
template<class T>
inline bool operator>=(T const& a, rational<T> const& b)
{
  return not (b > a);
}

// input operator
template<class T, class Char, class Traits>
std::basic_istream<Char, Traits>& operator>>(std::basic_istream<Char, Traits>& in, rational<T>& rat)
{
  typename std::basic_istream<Char, Traits>::sentry sentry(in, false);

  ioflags flags(in);

  T n = T();
  if (not (in >> n))
    return in;

  in >> std::noskipws;
  char sep('\0');
  if (not (in >> sep))
    return in;

  else if (sep != '/') {
    in.unget();
    rat = n;
    return in;
  }

  else {
    T d = T();
    if (in >> d)
      rat = rational<T>(n, d);
  }
  return in;
}

// output operator
template<class T, class Char, class Traits>
std::basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& out, rational<T> const& rat)
{
  typename std::basic_ostream<Char, Traits>::sentry sentry(out);

  std::ostringstream stream;

  stream << rat.numerator() << '/' << rat.denominator();

  out << stream.str();

  return out;
}

#endif
