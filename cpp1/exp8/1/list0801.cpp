#include <iomanip>
#include <iostream>
#include <ostream>

int main()
{
  std::cout << "  N    N^2     N^3\n";
  for (int i(1); i != 21; ++i)
    std::cout << std::setw(3) << i
	      << std::setw(7) << i*i
	      << std::setw(8) << i*i*i
	      << '\n';
}
