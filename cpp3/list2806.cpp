rational operator+(rational const& lhs, rational const& rhs)
{
  return rational(lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator,
                  lhs.denominator * rhs.denominator);
}

rational operator-(rational const& r)
{
  return rational(-r.numerator, r.denominator);
}
