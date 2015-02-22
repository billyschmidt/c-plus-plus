struct rational
{
#include "list3001.code"
  rational& operator=(rational const& rhs)
  {
    numerator = rhs.numerator;
    denominator = rhs.denominator;
    return *this;
  }
};
