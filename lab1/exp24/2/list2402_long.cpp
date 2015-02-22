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

  typedef long L;
  cout << "min=" << numeric_limits<L>::min() << '\n'
       << "max=" << numeric_limits<L>::max() << '\n'
       << "IEC 60559? " << numeric_limits<L>::is_iec559 << '\n'
       << "max exponent=" << numeric_limits<L>::max_exponent << '\n'
       << "min exponent=" << numeric_limits<L>::min_exponent << '\n'
       << "mantissa places=" << numeric_limits<L>::digits << '\n'
       << "radix=" << numeric_limits<L>::radix << '\n'
       << "has infinity? " << numeric_limits<L>::has_infinity << '\n'
       << "has quiet NaN? " << numeric_limits<L>::has_quiet_NaN << '\n'
       << "has signaling NaN? " << numeric_limits<L>::has_signaling_NaN << '\n';

  if (numeric_limits<L>::has_infinity)
    {
      L zero(0.0);
      L one(1.0);
      L inf(numeric_limits<L>::infinity());
      if (one/zero == inf)
	cout << "1.0/0.0 = infinity\n";
      if (inf + inf == inf)
	cout << "infinity + infinity = infinity\n";
    }
  if (numeric_limits<L>::has_quiet_NaN)
    {
      L zero(0.0);
      L inf(numeric_limits<L>::infinity());
      cout << "zero/zero = " << zero/zero << '\n';
      cout << "inf/inf = " << inf/inf << '\n';
    }
}
