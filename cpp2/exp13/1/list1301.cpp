#include <cstdio>
#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>

int main()
{
  std::ifstream in("list1301.txt");
  if (not in)
    std::perror("list1301.txt");
  else
    {
      int x(0);
      while (in >> x)
	std::cout << x << '\n'; 
      in.close();
    }
}
