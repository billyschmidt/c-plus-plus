#include <iostream>
#include <limits>
#include <ostream>

int main()
{
  std::cout << "bits per bool: " << '\n';
  std::cout << std::numeric_limits<bool>::digits << '\n';
}
