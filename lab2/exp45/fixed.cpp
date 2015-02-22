// fixed class function definitions

#include <cassert>
#include <cstdlib>
#include <iomanip>
#include <istream>
#include <locale>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "fixed.hpp"
#include "ioflags.hpp"

// make fixed from integer
fixed::fixed(value_type integer)
  : value_(integer * places10) 
{}

// return fraction part
fixed::value_type fixed::fraction() const
{
  return std::abs(value()) % places10;
}

// make fixed value from integer and fraction part
fixed::fixed(value_type integer, value_type fraction)
{
  if (fraction < 0)
    throw std::invalid_argument("no negative fractions!");
  fraction = reduce(fraction);
  
  if (integer < 0)
    value_ = integer * places10 - fraction;

  else
    value_ = integer * places10 + fraction;
}

// round off to nearest integer.
fixed::value_type fixed::round() const
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

// Convert to a string using fixed-point notation.
std::string fixed::as_string() const
{
  std::ostringstream out;
  out << integer() << '.' << std::setfill('0') << std::setw(places) << fraction();
  return out.str();
}

// reduce
fixed::value_type fixed::reduce(value_type frac)
{
  value_type f(frac);
  
  while (f >= places10*10 and f % 10 == 0) {
    f /= 10;
  }
  
  if (f >= places10*10) {
    
    int x(0);
    
    while (f >= places10) {
      x = f % 10;
      f /= 10;
    }
    
    if (x >= 5)
      ++f;
    return f;
  }
  
  else if (f >= places10) {
    int x(f % 10);
    f /= 10;
    assert(f < places10);
    if (x == 5) {
      if (f % 2 != 0)
	++f;
      return f;
    }
    
    else if (x < 5) {
      return f;
    }
    
    else {
      return f + 1;
    }
  }
  
  assert(frac < places10);  
  return frac;
}

// read definition
bool fixed::read(std::istream& stream)
{
  ioflags flags(stream);

  value_type integer;
  char decimal;
  if (not (stream >> integer))
    return false;
  stream.unsetf(std::ios_base::skipws);
  if (not (stream >> decimal) or decimal != '.')
    {
      stream.unget();
      stream.clear(stream.rdstate() & ~stream.failbit);
      value_ = integer * places10;
      return true;
    }
  else
    {
      value_type fraction(0);
      char c;
      int p(0);

      for (/* empty */; p != places+1 and stream >> c and std::isdigit(c, stream.getloc()); ++p)
	{
	  fraction = fraction * 10 + (c - '0');
	}

      for (/* empty */; p < places; ++p)
	{
	  fraction = fraction * 10;
	}      
      
      while (stream and std::isdigit(c, stream.getloc()))
	stream >> c;
      
      stream.unget();
      
      stream.clear(stream.rdstate() & ~stream.failbit);
      fraction = reduce(fraction);
      
      if (integer < 0)
	value_ = integer * places10 - fraction;
      else
	value_ = integer * places10 + fraction;
    }
  return true;
}

// begin operator overloads

// input
std::istream& operator>>(std::istream& stream, fixed& f)
{
  if (not f.read(stream))
    stream.setstate(stream.failbit);
  return stream;
}

// output
std::ostream& operator<<(std::ostream& stream, fixed f)
{
  stream << f.as_string();
  return stream;
}

// addition
fixed operator+(fixed x, fixed y)
{
  x += y;
  return x;
}

// subtraction
fixed operator-(fixed x, fixed y)
{
  x -= y;
  return x;
}

// multiplication
fixed operator*(fixed x, fixed y)
{
  x *= y;
  return x;
}

// division
fixed operator/(fixed x, fixed y)
{
  x /= y;
  return x;
}

// equal to
bool operator==(fixed x, fixed y)
{
  return x.value() == y.value();
}

// not equal to
bool operator!=(fixed x, fixed y)
{
  return not (x == y);
}

// less than
bool operator<(fixed x, fixed y)
{
  return x.value() < y.value();
}

// greater than
bool operator>(fixed x, fixed y)
{
  return y < x;
}

// less than or equal
bool operator<=(fixed x, fixed y)
{
  return not (y < x);
}

// greater than or eqaul
bool operator>=(fixed x, fixed y)
{
  return not (x < y);
}

// additional arithmentic operators
fixed& fixed::operator+=(fixed f)
{
  value_ += f.value();
  return *this;
}

fixed& fixed::operator-=(fixed f)
{
  value_ -= f.value();
  return *this;
}

fixed& fixed::operator*=(fixed f)
{
  value_ = (value_ * f.value()) / places10;
  return *this;
}

fixed& fixed::operator/=(fixed f)
{
  value_ = (value_ * places10) / f.value();
  return *this;
}

void fixed::negate()
{
  value_ = -value_;
}

fixed operator-(fixed x)
{
  x.negate();
  return x;
}

// increment and decrement operators (prefix and postfix)
fixed& fixed::operator++()
{
  value_ += places10;
  return *this;
}

fixed fixed::operator++(int)
{
  fixed result(*this);
  ++*this;
  return result;
}

fixed& fixed::operator--()
{
  value_ -= places10;
  return *this;
}

fixed fixed::operator--(int)
{
  fixed result(*this);
  --*this;
  return result;
}
