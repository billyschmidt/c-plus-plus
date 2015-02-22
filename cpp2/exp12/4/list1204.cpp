#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

int main()
{
  int v;
  std::vector<int> input;
  std::vector<int>::iterator i, p;
  std::string s;

  std::copy(std::istream_iterator<int>(std::cin),
            std::istream_iterator<int>(),
            std::back_inserter(input));
  i = input.begin();

  while (i != input.end())
    {
      v = *i;
      p = std::lower_bound(input.begin(), i, v);
      i = input.erase(i);
      input.insert(p, v);
    }

  s = " ";
  for (p = i, i = input.begin(); i != input.end(); p = i, ++i)
    {
      if (p != input.end())
	assert(not (*i < *p));
    }

  std::cout << '{';
  for (i = input.begin(); i != input.end(); ++i)
    {
      v = *p;
      std::cout << s << v;
      s = ", ";
    }
  std::cout << " }\n";
}
