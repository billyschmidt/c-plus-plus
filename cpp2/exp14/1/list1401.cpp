#include <iostream>
#include <istream>
#include <map>
#include <ostream>
#include <string>

int main()
{
  std::map<std::string, int> counts;
  std::string word;
  while (std::cin >> word) 
    ++counts[word];
  //  Print the results.
}
