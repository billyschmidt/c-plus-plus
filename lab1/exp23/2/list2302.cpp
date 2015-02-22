#include <iostream>
#include <limits>
#include <ostream>

// modified 23-1 to check bits in long and short ints
int main()
{
  using namespace std;

  cout << "bits per int = ";
  if (numeric_limits<int>::is_signed)
    cout << numeric_limits<int>::digits + 1 << '\n';
  else
    cout << numeric_limits<int>::digits << '\n';

  cout << "bits per bool = ";
  if (numeric_limits<bool>::is_signed)
    cout << numeric_limits<bool>::digits + 1 << '\n';
  else
    cout << numeric_limits<bool>::digits << '\n';

  cout << "bits per long int = ";
  if (numeric_limits<long>::is_signed)
    cout << numeric_limits<long>::digits + 1 << '\n';
  else
    cout << numeric_limits<long>::digits << '\n';

  cout << "bits per short int = ";
  if (numeric_limits<short>::is_signed)
    cout << numeric_limits<short>::digits + 1 << '\n';
  else
    cout << numeric_limits<short>::digits << '\n';
}
