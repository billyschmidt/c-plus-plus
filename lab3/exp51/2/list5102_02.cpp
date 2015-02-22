/**
 * Bill Schmidt
 * 4159697
 * program that reads list of strings from standard input
 * into a set of strings single argument insert
 *
 */

#include <iostream>
#include <istream>
#include <set>
#include <string>

int main()
{
  std::string str;
  std::set<std::string> data;
  std::set<std::string>::iterator test(data.begin());
  
  while (std::cin >> str) {
    data.insert(str);
  }
}
