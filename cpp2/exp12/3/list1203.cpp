#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

int main()
{
  std::vector<int> data;
  data.insert(data.begin(), std::istream_iterator<int>(std::cin),
	      std::istream_iterator<int>());

  std::sort(data.begin(), data.end());
  {
    std::cout << '{';
    std::string separator(" ");
    for (std::vector<int>::iterator iter(data.begin()); iter != data.end(); ++iter)
      {
	std::cout << separator << *iter;
	separator = ", ";
      }
    std::cout << " }\n";
  }
}
