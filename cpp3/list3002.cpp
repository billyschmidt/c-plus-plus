struct rational
{
#include "list3002.code"
  rational& operator=(rational const& that)
  {
    this->numerator = that.numerator;
    this->denominator = that.denominator;
    return *this;
  }
};
