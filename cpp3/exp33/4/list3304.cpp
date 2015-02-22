// redo of rational class to use access levels

#include <cassert>
#include <cstdlib>
#include <istream>
#include <ostream>
#include <iostream>
#include <sstream>

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

// begin class definition
class rational
{

public:
  // constructors and overload constructors
  rational()
    : numerator_(0), denominator_(1)
  {}

  rational(int num)
    : numerator_(num), denominator_(1)
  {}
  
  rational(int num, int den)
    : numerator_(num), denominator_(den)
  {
    reduce();
  }
  
  rational(double r)
    : numerator_(static_cast<int>(r * 10000)), denominator_(10000)
  {
    reduce();
  }

  int numerator()
    const
  {
    return numerator_;
  }
  int denominator() const
  {
    return denominator_; 
  }
  
  float as_float()
    const
  {
    return static_cast<float>(numerator()) / denominator();
  }
  
  double as_double()
    const
  {
    return static_cast<double>(numerator()) / denominator();
  }
  
  long double as_long_double()
    const
  {
    return static_cast<long double>(numerator()) / denominator();
  }
  
  void assign(int num, int den)
  {
    numerator_ = num;
    denominator_ = den;
    reduce();
  }
  
private:
  void reduce()
  {
    assert(denominator() != 0);
    if (denominator() < 0)
      {
	denominator_ = -denominator();
	numerator_ = -numerator();
      }
    int div(gcd(numerator(), denominator()));
    numerator_ = numerator() / div;
    denominator_ = denominator() / div;
  }
  
  int numerator_;
  int denominator_;
};

// abs function
rational abs(rational const& r)
{
  return rational(abs(r.numerator()), r.denominator());
}

// operator overloads
rational operator-(rational const& r)
{
  return rational(-r.numerator(), r.denominator());
}

rational operator+(rational const& lhs, rational const& rhs)
{
  return rational(
		  lhs.numerator() * rhs.denominator() + rhs.numerator() * lhs.denominator(),
		  lhs.denominator() * rhs.denominator());
}

rational operator-(rational const& lhs, rational const& rhs)
{
  return rational(
		  lhs.numerator() * rhs.denominator() - rhs.numerator() * lhs.denominator(),
		  lhs.denominator() * rhs.denominator());
}

rational operator*(rational const& lhs, rational const& rhs)
{
  return rational(lhs.numerator() * rhs.numerator(),
                  lhs.denominator() * rhs.denominator());
}

rational operator/(rational const& lhs, rational const& rhs)
{
  return rational(lhs.numerator() * rhs.denominator(),
                  lhs.denominator() * rhs.numerator());
}

bool operator==(rational const& a, rational const& b)
{
  return a.numerator() == b.numerator() and a.denominator() == b.denominator();
}

inline bool operator!=(rational const& a, rational const& b)
{
  return not (a == b);
}

bool operator<(rational const& a, rational const& b)
{
  return a.numerator() * b.denominator() < b.numerator() * a.denominator();
}

inline bool operator<=(rational const& a, rational const& b)
{
  return not (b < a);
}

inline bool operator>(rational const& a, rational const& b)
{
  return b < a;
}

inline bool operator>=(rational const& a, rational const& b)
{
  return not (b > a);
}

std::istream& operator>>(std::istream& in, rational& rat)
{
  int n(0), d(0);
  char sep('\0');
  if (not (in >> n >> sep))
    in.setstate(in.failbit);
  else if (sep != '/')
    {
      in.unget();
      rat.assign(n, 1);
    }
  else if (in >> d)
    rat.assign(n, d);
  else
    in.setstate(in.failbit);
  
  return in;
}

std::ostream& operator<<(std::ostream& out, rational const& rat)
{
  std::ostringstream tmp;
  tmp << rat.numerator() << '/' << rat.denominator();
  out << tmp.str();
  return out;
}

// run some tests
int main()
{
  rational a(23, 56);
  rational b(5, 125);
  rational c(-32, -7.8);
  rational d(60000, 100000);

  std::cout << a << '\n'
	    << b << '\n'
	    << c << '\n'
	    << d << "\n\n";

  std::cout << a*d << '\n'
	    << b/a << '\n'
	    << d+a << '\n'
	    << c-b << '\n';
}
