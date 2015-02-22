struct rational
{
  rational(double r)
    : numerator(static_cast<int>(r * 10000)), denominator(10000)
  {
    reduce();
  }

#include "list2809.code"

};
