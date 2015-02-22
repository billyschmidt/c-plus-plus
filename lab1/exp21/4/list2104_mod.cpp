#include <algorithm>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <vector>

// when using "==" comparision, will sort in ascending order
int descending(int a, int b)
{
  return a == b;
}

int main()
{
  std::vector<int> data;

  // insert ints into vector
  data.insert(data.begin(), std::istream_iterator<int>(std::cin), std::istream_iterator<int>());

  // sort, then call descending function
  std::sort(data.begin(), data.end(), descending);

  // output using ostream_iterator
  std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, "\n"));
}
