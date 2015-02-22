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

  typedef float T;
  cout << "min=" << numeric_limits<T>::min() << '\n'
       << "max=" << numeric_limits<T>::max() << '\n'
       << "IEC 60559? " << numeric_limits<T>::is_iec559 << '\n'
       << "max exponent=" << numeric_limits<T>::max_exponent << '\n'
       << "min exponent=" << numeric_limits<T>::min_exponent << '\n'
       << "mantissa places=" << numeric_limits<T>::digits << '\n'
       << "radix=" << numeric_limits<T>::radix << '\n'
       << "has infinity? " << numeric_limits<T>::has_infinity << '\n'
       << "has quiet NaN? " << numeric_limits<T>::has_quiet_NaN << '\n'
       << "has signaling NaN? " << numeric_limits<T>::has_signaling_NaN << '\n';

  if (numeric_limits<T>::has_infinity)
    {
      T zero(0.0);
      T one(1.0);
      T inf(numeric_limits<T>::infinity());
      if (one/zero == inf)
	cout << "1.0/0.0 = infinity\n";
      if (inf + inf == inf)
	cout << "infinity + infinity = infinity\n";
    }
  if (numeric_limits<T>::has_quiet_NaN)
    {
      T zero(0.0);
      T inf(numeric_limits<T>::infinity());
      cout << "zero/zero = " << zero/zero << '\n';
      cout << "inf/inf = " << inf/inf << '\n';
    }
}
