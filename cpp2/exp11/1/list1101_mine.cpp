#include <ios>
#include <iostream>
#include <ostream>

using namespace std;

int main()
{
  cout << "true" << true << '\n';
  cout << "false" << false << '\n';
  cout << std::boolalpha;
  cout << "true" << true << '\n';
  cout << "false" << false << '\n';
}
