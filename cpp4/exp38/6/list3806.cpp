// calling generate_id() multiple times and
// verifying that it makes new values each time

#include <iostream>
#include <ostream>

// begin generate_id definition
int generate_id()
{
  static int counter(0);
  ++counter;
  return counter;
}

// begin main
int main()
{
  int i(0);
  while (i != 1000)
    {
      std::cout << generate_id() << '\n';
      ++i;
    }
}

