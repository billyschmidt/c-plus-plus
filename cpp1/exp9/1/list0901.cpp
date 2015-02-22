#include <algorithm>
#include <iostream>
#include <istream>
#include <ostream>
#include <vector>

int main()
{
  std::vector<int> data;   
  int x(0);

  while (std::cin >> x)
    data.push_back(x);

  std::sort(data.begin(), data.end());

  for (std::vector<int>::size_type i(0); i != data.size(); i = i + 1)
    std::cout << data.at(i) << '\n';
}
