#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>

int main()
{
  using namespace std;
  
  cout << setfill('0') << setw(6) << 42 << '\n';
  cout << 420000 << '\n';
  cout << 42 << '\n';
  cout << left<< setfill('-') << setw(4) << -42 << '\n';
}
