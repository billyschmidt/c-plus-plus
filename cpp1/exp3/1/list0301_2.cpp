// Bill Schmidt 4159697

#include <iostream>
#include <ostream>

int main()
{
  int sum(0);
  int count(0);
  int x;
  while (std::cin >> x)
    
    {
      sum = sum + x;
      count = count + 1;
    }
  
  if (count != 0)
    std::cout << "average = " << sum / count << '\n';
  else
    std::cout << "count is zero!" << '\n';
}
