#include <iostream>
#include <istream>
#include <locale>
#include <ostream>

using namespace std;

int main()
{
  cin.imbue(locale(""));
  int total(0);
  int x;
 
  while (cin >> x)
    total += x;
  cout << "total is " << total << '\n';
}
