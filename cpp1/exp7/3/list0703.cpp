#include <iostream>
#include <ostream>

int main()
{
  std::cout << '*';
  for (int i(0); i != 20; i = i + 1)
    std::cout << '*';

  std::cout << "*\n|";
  for (int i(0); i != 3; i = i + 1)
    std::cout << ' ';

  std::cout << "Hey there, guy!";
  for (int i(0); i != 3; i = i + 1)
    std::cout << ' ';

  std::cout << "|\n*";
  for (int i(0); i != 20; i = i + 1)
    std::cout << '*';
  std::cout << "*\n";
}
