#include <algorithm>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <vector>

int main()
{
  std::vector<int> data;

  std::copy(std::istream_iterator<int>(std::cin),
            std::istream_iterator<int>(),
            std::back_inserter(data));

  std::sort(data.begin(), data.end());

  std::copy(data.begin(), data.end(),
            std::ostream_iterator<int>(std::cout, "\n"));
}
