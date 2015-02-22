#include <iostream>
#include <istream>
#include <ostream>
#include <string>

int main()
{
  std::cout << "How old are you? ";
  int age(0);
  std::cin >> age;

  std::cout << "What's your name? ";
  std::string name;
  std::cin >> name;

  std::cout << "Later, " << name << ". You're " << age << " year";
  if (age != 1)
    std::cout << 's';
  std::cout << " old.\n";
}
