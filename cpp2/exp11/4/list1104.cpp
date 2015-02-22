#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <vector>

int main()
{
  std::vector<int> input;
  input.insert(input.begin(),
	       std::istream_iterator<int>(std::cin),
	       std::istream_iterator<int>());

  std::vector<int>::iterator incr;
  for (incr = input.begin(); incr != input.end() and *incr == 0; ++incr; /* empty */)
    if (incr == input.end())
      std::cout << "you entered all zeroes\n";
    else
      std::cout << "you did not enter all zeroes\n";
}
