/**
 * Bill Schmidt
 * 4159697
 * program that reads list of strings from standard input
 * into a set of strings using hinted insert
 *
 */

#include <iostream>
#include <istream>
#include <set>
#include <string>

int main()
{
  std::string word;
  std::set<std::string> words;

  std::set<std::string>::iterator hint(words.begin());
  while(std::cin >> word)
    hint = words.insert(hint, word);
}
