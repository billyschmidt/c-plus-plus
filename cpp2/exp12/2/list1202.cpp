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

  for (std::vector<int>::iterator iter(data.begin()); iter != data.end(); ++iter)
    {
      int value(*iter);
      std::vector<int>::iterator here(std::lower_bound(data.begin(), iter, value));
      if (iter != here)
	{
	  data.erase(iter);
	  iter = data.insert(here, value);
	}
    }
  for (std::vector<int>::iterator iter(data.begin()), prev(data.end());
       iter != data.end();
       ++iter)
    {
      if (prev != data.end())
	assert(not (*iter < *prev));
      prev = iter;
    }
  std::cout << '{';
  std::string separator(" ");
  for (std::vector<int>::iterator iter(data.begin()); iter != data.end(); ++iter)
    {
      std::cout << separator << *iter;
      separator = ", ";
    }
  std::cout << " }\n";
}
