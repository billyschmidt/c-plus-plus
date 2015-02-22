#include <ios>
#include <iostream>
#include <limits>
#include <locale>
#include <ostream>

int main()
{
  using namespace std;
  cout.imbue(locale(""));
  cout << boolalpha;

  typedef double d;
  cout << "min=" << numeric_limits<d>::min() << '\n'
       << "max=" << numeric_limits<d>::max() << '\n'
       << "IEC 60559? " << numeric_limits<d>::is_iec559 << '\n'
       << "max exponent=" << numeric_limits<d>::max_exponent << '\n'
       << "min exponent=" << numeric_limits<d>::min_exponent << '\n'
       << "mantissa places=" << numeric_limits<d>::digits << '\n'
       << "radix=" << numeric_limits<d>::radix << '\n'
       << "has infinity? " << numeric_limits<d>::has_infinity << '\n'
       << "has quiet NaN? " << numeric_limits<d>::has_quiet_NaN << '\n'
       << "has signaling NaN? " << numeric_limits<d>::has_signaling_NaN << '\n';

  if (numeric_limits<d>::has_infinity)
    {
      d zero(0.0);
      d one(1.0);
      d inf(numeric_limits<d>::infinity());
      if (one/zero == inf)
	cout << "1.0/0.0 = infinity\n";
      if (inf + inf == inf)
	cout << "infinity + infinity = infinity\n";
    }
  if (numeric_limits<d>::has_quiet_NaN)
    {
      d zero(0.0);
      d inf(numeric_limits<d>::infinity());
      cout << "zero/zero = " << zero/zero << '\n';
      cout << "inf/inf = " << inf/inf << '\n';
    }
}
