#include <ios>
#include <iostream>
#include <ostream>

using namespace std;

void print(int precision, float value)
{
  cout.precision(precision);
  cout << scientific << value << '\t' << fixed << value << '\t';
  cout.unsetf(ios_base::floatfield);
  cout << value << '\n';
}

int main()
{
  print(2, 34654356.239F);
  print(5, .34552343245F);
  print(1, 5234523454.F);
  print(3, -4324.4224F);
}
