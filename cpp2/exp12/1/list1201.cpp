#include <iostream>
#include <ostream>
#include <vector>

int main()
{
  std::vector<int> positive_data, negative_data;

  for (int x(0); std::cin >> x ;) {
    if (x < 0)
      {
	negative_data.push_back(x);
      }
    else
      {
	positive_data.push_back(x);
      }
  }
}
