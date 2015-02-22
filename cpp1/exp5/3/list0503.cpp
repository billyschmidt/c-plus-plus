#include <iostream>
#include <istream>
#include <ostream>
#include <string>

int main()
{
  std::cout << "What's your name? ";
  std::string name;
  std::cin >> name;

  std::cout << "Hey " << name << ", how old are you? ";
  int age(0);
  std::cin >> age;
  
  std::cout << "See ya, " << name << ". You're " << age << " year";
  if (age != 1)
    std::cout << 's';
  std::cout << " old.\n";
}
