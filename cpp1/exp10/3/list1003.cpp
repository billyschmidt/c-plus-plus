#include <algorithm>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <vector>

int main()
{
  int x;
  std::vector<int> input;

  while (std::cin >> x)
    input.push_back(x);

  for (std::vector<int>::iterator start(input.begin()), end(input.end()); start != end;)  {
    end -=1;
    if (start != end)  {
      int temp = *start;
      *start = *end;
      *end = temp;
      ++start;
    }
  }

  std::copy(input.begin(), input.end(), std::ostream_iterator<int>(std::cout, "\n"));
}
