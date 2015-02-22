// Bill Schmidt
// 4159697

#include <ios>
#include <iostream>
#include <ostream>

int main()
{
  bool b;
  std::cout << std::boolalpha;
  b = false;                   std::cout << b << ' ';
  b = true;                    std::cout << b << ' ';
  b = false;                   std::cout << b << ' ';
  b = true;                    std::cout << b << ' ';
  b = 42;                      std::cout << b << ' ';
  b = 3.1415926535897;         std::cout << b << ' ';
  b = 0;                       std::cout << b << ' ';
  b = -0.0;                    std::cout << b << ' ';
  b = -1;                      std::cout << b << ' ';
  b = "1";                     std::cout << b << ' ';
  b = "0";                     std::cout << b << ' ';
  b = "false";                 std::cout << b << ' ';
  b = "";                      std::cout << b << ' ';
  b = '0';                     std::cout << b << ' ';
  b = '\0';                    std::cout << b << ' ';
  b = std::cout;               std::cout << b << ' ';
  b = std::cin;                std::cout << b << ' ';
  std::cout << '\n';
}
