#include <iostream>
#include <ostream>
#include <string>

int main()
{
  std::string x("hello "), y("hello ");
  if (x != y) std::cout << "no:  hello != hello\n";
  if (x < y)  std::cout << "no:  hello <  hello\n";
  if (x > y)  std::cout << "no:  hello >  hello\n";
  if (x == y) std::cout << "yes: hello == hello\n";
  if (x >= y) std::cout << "yes: hello >= hello\n";
  if (x <= y) std::cout << "yes: hello <= hello\n";

  x.push_back('b');
  if (x != y) std::cout << "yes: hello b != hello\n";
  if (x < y)  std::cout << "no:  hello b <  hello\n";
  if (x > y)  std::cout << "yes: hello b >  hello\n";
  if (x == y) std::cout << "no:  hello b == hello\n";
  if (x >= y) std::cout << "yes: hello b >= hello\n";
  if (x <= y) std::cout << "no:  hello b <= hello\n";

  y.push_back('u');
  if (x != y) std::cout << "yes: hello b != hello u\n";
  if (x < y)  std::cout << "yes: hello b <  hello u\n";
  if (x > y)  std::cout << "no:  hello b >  hello u\n";
  if (x == y) std::cout << "no:  hello b == hello u\n";
  if (x >= y) std::cout << "no:  hello b >= hello u\n";
  if (x <= y) std::cout << "yes: hello b <= hello u\n";
}
