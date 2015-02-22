#include <ios>
#include <iostream>
#include <istream>
#include <ostream>

using namespace std;

int main()
{
  char x;
  cin >> noskipws;

  while (cin >> x)
    cout << x << '\n';
}
