#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <istream>
#include <ostream>
#include <string>

// begin fixed class
class fixed
{
public:
  // underlying integer type
  typedef int value_type;

  // number of places after decimal point
  static int const places = 4;

  // scale factor for fixed point values
  static value_type const places10 = 10000;

  // default constructor
  fixed() : value_(0) {}

  // overload constructors according to rules
  // 
  // make value from fixed and fraction parts
  fixed(value_type integer, value_type fraction);

  // make fixed from integer
  fixed(value_type integer);

  // make fixed value from floating point
  fixed(double value)
    : value_(static_cast<value_type>(value * places10 + (value < 0 ? -0.5 : 0.5)))
  {}
  
  // convert to a string
  std::string as_string() const;

  // read from a stream
  bool read(std::istream& stream);

  // convert to long double
  double as_long_double() const
  {
    return static_cast<long double>(value()) / places10;
  }

  // convert to double
  double as_double() const
  {
    return static_cast<double>(value()) / places10;
  }
  
  // convert to float
  float as_float() const
  { 
    return static_cast<float>(value()) / places10;
  }
  
  // return rounded integer portion
  value_type round() const;
  
  // return integer portion
  value_type integer() const
  {
    return value() / places10; 
  }
  
  // return fraction portion
  value_type fraction() const;
  
  // addition
  fixed& operator+=(fixed f);
  
  // subtraction
  fixed& operator-=(fixed f);

  // multiplication
  fixed& operator*=(fixed f);
  
  //division
  fixed& operator/=(fixed f);

  // negation
  void negate();

  // increment and decrement operators
  fixed& operator++();
  fixed operator++(int);
  fixed& operator--();
  fixed operator--(int);
  
  // return internal value
  value_type value() const 
  {
    return value_;
  }

private:
  // reduce frac to the range [0, places10) by discarding digits to the right
  value_type reduce(value_type frac);
  value_type value_;
};

// end class

// function declarations - will define xin fixed.cpp
std::istream& operator>>(std::istream& stream, fixed& f);

std::ostream& operator<<(std::ostream& stream, fixed f);

fixed operator+(fixed x, fixed y);

fixed operator-(fixed x, fixed y);

fixed operator*(fixed x, fixed y);

fixed operator/(fixed x, fixed y);

fixed operator-(fixed x);

bool operator==(fixed x, fixed y);

bool operator!=(fixed x, fixed y);

bool operator<(fixed x, fixed y);

bool operator>(fixed x, fixed y);

bool operator<=(fixed x, fixed y);

bool operator>=(fixed x, fixed y);

#endif
