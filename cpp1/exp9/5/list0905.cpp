#include <iostream>
#include <istream>
#include <ostream>
#include <vector>

int main()
{
  std::vector<int> input;
  int x(0);

  while (std::cin >> x)
    input.push_back(x);

  for (std::vector<int>::iterator i(input.begin()); i != input.end(); ++i)
    *i *= 2;

  for (std::vector<int>::iterator i(input.begin()); i != input.end(); ++i)
    std::cout << *i << '\n';
}
