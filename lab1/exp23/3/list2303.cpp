#include <iostream>
#include <locale>
#include <ostream>

using namespace std;

void print(int i)
{
  cout << "int=" << i << '\n';
}

void print(long l)
{
  cout << "long=" << l << '\n';
}

int main()
{
  cout.imbue(locale(""));
  print(0);
  print(0L);
  print(1234345);
  print(1234345L);
  print(-112345);
  print(-112345L);
  print(456435645);
  print(456435645L);
  print(234665365);
  print(234665365L);
  print(653654465);
  print(653654455L);
}
