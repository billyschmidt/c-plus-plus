/**
 * Project 3:
 * implement a currency type
 *
 */

#ifndef CURRENCY_HPP_
#define CURRENCY_HPP_

#include <istream>
#include <ostream>
#include <sstream>
#include <iomanip>
#include <locale>
#include <string>
#include <stdexcept>

// header files
#include "ioflags.hpp"
#include "fixed.hpp"
#include "rational.hpp"

// class to represent a currency value in the global locale
template<class T=long, int N=2>
class currency
{
public:
  typedef T int_type;
  typedef fixed<T,N> value_type;

  //default constructor initializes the value to zero
  currency() : value_() {}

  //initialize the value to integer
  currency(T integer) : value_(integer) {}

  // initialize the value
  currency(T integer, T fraction) : value_(integer, fraction) {}

  // initialize from a floating point number
  currency(double value) : value_(value) {}

  // copy a value that uses a different precision
  template<class U, int M>
  currency(currency<U, M> const& rhs): value_(rhs.value()) {}

  // assign a value that uses a different precision
  template<class U, int M>
  currency& operator=(currency<U, M> rhs)
  {
    value_ = rhs.value();
    return *this;
  }

  // convert to a string
  std::string as_string() const;

  // overwrite value from stream
  template<class Char, class Traits>
  bool read(std::basic_istream<Char, Traits>& strm);

  // convert the value to a different numeric type
  template<class U>
  U convert() const { return value().convert<U>(); }

  // round off to the nearest integer
  int_type round() const { return value().round(); }

  // return the integer part
  int_type integer()  const { return value().integer(); }

  // return the fractional part to M places
  template<int M>
  int_type fraction() const { return value().fraction<M>(); }

  // return the fractional part
  int_type fraction() const { return value().fraction(); }

  // addition operator
  currency& operator+=(currency c);

  // subtraction operator
  currency& operator-=(currency c);

  // multiplication operator
  currency& operator*=(value_type m);

  // multiplication operator
  currency& operator*=(int_type m);

  // division operator
  currency& operator/=(value_type m);

  // division operator
  currency& operator/=(int_type m);

  // negate this value
  void negate();

  // pre-increment operator
  currency& operator++();

  // post-increment operator
  currency operator++(int);

  // pre-decrement operator
  currency& operator--();

  // post-decrement operator
  currency operator--(int);

  // return the internal value
  value_type value()    const { return value_; }

private:
  value_type value_;
};

template<class T, int N>
std::string currency<T,N>::as_string() const
{
  std::ostringstream digits;

  digits.imbue(std::locale::classic());

  digits << integer() << std::setw(value_type::places) << std::setfill('0') << fraction();

  std::ostringstream out;

  std::money_put<char> const& put(std::use_facet<std::money_put<char> >(std::locale()));

  put.put(std::ostreambuf_iterator<char>(out), false, out, '0', digits.str());

  return out.str();
}

template<class T, int N>
currency<T,N>& currency<T,N>::operator+=(currency f)
{
  value_ += f.value();
  return *this;
}

template<class T, int N>
currency<T,N>& currency<T,N>::operator-=(currency f)
{
  value_ -= f.value();
  return *this;
}

template<class T, int N>
currency<T,N>& currency<T,N>::operator*=(value_type i)
{
  value_ *= i;
  return *this;
}

template<class T, int N>
currency<T,N>& currency<T,N>::operator*=(int_type i)
{
  value_ *= i;
  return *this;
}

template<class T, int N>
currency<T,N>& currency<T,N>::operator/=(value_type i)
{
  value_ /= i;
  return *this;
}

template<class T, int N>
currency<T,N>& currency<T,N>::operator/=(int_type i)
{
  value_ /= i;
  return *this;
}

template<class T, int N>
void currency<T,N>::negate()
{
  value_ = -value_;
}

template<class T, int N>
currency<T,N>& currency<T,N>::operator++()
{
  ++value_;
  return *this;
}

template<class T, int N>
currency<T,N> currency<T,N>::operator++(int)
{
  currency result(*this);
  ++value_;
  return result;
}

template<class T, int N>
currency<T,N>& currency<T,N>::operator--()
{
  --value_;
  return *this;
}

template<class T, int N>
currency<T,N> currency<T,N>::operator--(int)
{
  currency result(*this);
  --value_;
  return result;
}

template<class T, int N>
template<class CharT, class Traits>
bool currency<T,N>::read(std::basic_istream<CharT,Traits>& strm)
{
  ioflags flags(strm);

  typename std::basic_istream<CharT, Traits>::sentry sentry(strm, false);

  if (not sentry)
    return false;

  std::ios_base::iostate error(std::ios_base::goodbit);

  std::string digits;

  std::money_get<CharT> const& get(std::use_facet<std::money_get<CharT> >(strm.getloc()));

  get.get(std::istreambuf_iterator<CharT>(strm), std::istreambuf_iterator<CharT>(),
	  false, strm, error, digits);

  if ((error & std::ios_base::failbit) != 0)
    return false;

  std::moneypunct<CharT> const& punct(std::use_facet<std::moneypunct<CharT> >(strm.getloc()));

  // Set fraction to the rightmost frac_digits() characters of digits
  std::string fraction(digits.substr(digits.size() - punct.frac_digits(), punct.frac_digits()));

  // set integer to the remainder of digits
  std::string integer(digits.substr(0, digits.size() - punct.frac_digits()));

  std::istringstream fixed_stream(integer + "." + fraction);
  return value_.read(fixed_stream);
}

// read a currency value
template<class T, int N, class Char, class Traits>
std::basic_istream<Char, Traits>& operator>>(std::basic_istream<Char, Traits>& strm, currency<T,N>& c)
{
  if (not c.read(strm))
    strm.setstate(strm.failbit);
  return strm;
}

// Write a currency value
template<class T, int N, class Char, class Traits>
std::basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& strm, currency<T,N> c)
{
  typename std::basic_ostream<Char, Traits>::sentry sentry(strm);
  strm << c.as_string();
  return strm;
}

// Negate a currency value
template<class T, int N>
currency<T,N> operator-(currency<T,N> a)
{
  a.negate();
  return a;
}

// Add currency values
template<class T, int N>
currency<T,N> operator+(currency<T,N> a, currency<T,N> b)
{
  a += b;
  return a;
}

// subtract currency values
template<class T, int N>
currency<T,N> operator-(currency<T,N> a, currency<T,N> b)
{
  a -= b;
  return a;
}

// multiply currency value and an integer
template<class T, int N>
currency<T,N> operator*(currency<T,N> a, T b)
{
  a *= b;
  return a;
}

// multiply currency value and an integer
template<class T, int N>
currency<T,N> operator*(T a, currency<T,N> b)
{
  b *= a;
  return b;
}

// Divide currency value by an integer
template<class T, int N>
currency<T,N> operator/(currency<T,N> a, T b)
{
  a /= b;
  return a;
}

// Divide currency values to yield a rational result
template<class T, int N>
rational<T> operator/(currency<T,N> n, currency<T,N> d)
{
  return rational<T>(n.value().value(), d.value().value());
}

// Compare currency values for equality by comparing the underlying values
template<class T, int N>
bool operator==(currency<T,N> a, currency<T,N> b)
{
  return a.value() == b.value();
}

// Compare currency value and an integer for equality
template<class T, int N>
bool operator==(currency<T,N> a, T b)
{
  return a.value() == b;
}

// Compare currency value and an integer for equality
template<class T, int N>
bool operator==(T a, currency<T,N> b)
{
  return a == b.value();
}

// Compare currency values for inequality
template<class T, int N>
inline bool operator!=(currency<T,N> a, currency<T,N> b)
{
  return not (a == b);
}

// Compare currency value and an integer for inequality
template<class T, int N>
inline bool operator!=(currency<T,N> a, T b)
{
  return not (a == b);
}

// Compare currency value and an integer for inequality
template<class T, int N>
inline bool operator!=(T a, currency<T,N> b)
{
  return not (a == b);
}

// Compare currency values for less-than by comparing the underlying values
template<class T, int N>
bool operator<(currency<T,N> a, currency<T,N> b)
{
  return a.value() < b.value();
}

// Compare a currency value and an integer for less-than
template<class T, int N>
bool operator<(currency<T,N> a, T b)
{
  return a.value() < b;
}

// Compare a currency value and an integer for less-than
template<class T, int N>
bool operator<(T a, currency<T,N> b)
{
  return a < b.value();
}

// Compare currency values for greater-than
template<class T, int N>
inline bool operator>(currency<T,N> a, currency<T,N> b)
{
  return b < a;
}

// Compare a currency value and an integer for greater-than
template<class T, int N>
inline bool operator>(currency<T,N> a, T b)
{
  return b < a;
}

// Compare a currency value and an integer for greater-than
template<class T, int N>
inline bool operator>(T a, currency<T,N> b)
{
  return b < a;
}

// Compare currency values for less-than-or-equal
template<class T, int N>
inline bool operator<=(currency<T,N> a, currency<T,N> b)
{
  return not (b < a);
}

// Compare a currency value and an integer for less-than-or-equal
template<class T, int N>
inline bool operator<=(currency<T,N> a, T b)
{
  return not (b < a);
}

// Compare a currency value and an integer for less-than-or-equal
template<class T, int N>
inline bool operator<=(T a, currency<T,N> b)
{
  return not (b < a);
}

// Compare currency values for greater-than-or-equal
template<class T, int N>
inline bool operator>=(currency<T,N> a, currency<T,N> b)
{
  return not (a < b);
}

// Compare a currency value and an integer for greater-than-or-equal
template<class T, int N>
inline bool operator>=(currency<T,N> a, T b)
{
  return not (a < b);
}

// Compare a currency value and an integer for greater-than-or-equal
template<class T, int N>
inline bool operator>=(T a, currency<T,N> b)
{
  return not (a < b);
}

#endif
