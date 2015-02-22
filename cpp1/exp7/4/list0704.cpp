#include <iostream>
#include <ostream>

int main()
{
  int sum(0);

  for (int i(10); i != 21; ++i)
    sum += i;
  std::cout << "The sum from 10 to 20 (inclusive) = " << sum << '\n';
}
