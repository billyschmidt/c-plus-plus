/** 
 * Bill Schmidt
 * 4159697
 * fixing listing 50-5
 *
 */

#include <iostream>
#include <ostream>

void print(int i)
{
  std::cout << "int: " << i << '\n';
}

namespace labeled
{
  void print(double d)
  {
    std::cout << "double: " << d << '\n';
  }
}

namespace simple
{
  void print(int i)
  {
    std::cout << i << '\n';
  }
  void print(double d)
  {
    std::cout << d << '\n';
  }
}

void test_simple()
{
  // call print function in simple namespace
  simple::print(42);
  print(3.14159);
}

void test_labeled()
{
  using namespace labeled;
  print(42);
  print(3.14159);
}

int main()
{
  test_simple();
  test_labeled();
}
