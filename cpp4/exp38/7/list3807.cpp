// declaring counter outside of generate_id function

#include <iostream>
#include <ostream>

// global declaration
int counter;

// begin function
int generate_id()
{
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

