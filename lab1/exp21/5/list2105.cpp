#include <ostream>
#include <iostream>
#include <istream>
#include <algorithm>
#include <iterator>
#include <locale>
#include <string>

using namespace std;

// non-letter test
bool non_letter(char ch)
{
  return not isalpha(ch, locale());
}

// convert to lowercase
char lowercase(char ch)
{
  return tolower(ch, locale());
}

// compare two characters
bool same_char(char a, char b)
{
  return lowercase(a) == lowercase(b);
}

// palindrome check
bool is_palindrome(string str)
{
  string::iterator end(remove_if(str.begin(), str.end(), non_letter));
  string rev(str.begin(), end);
  reverse(rev.begin(), rev.end());
  return not rev.empty() and equal(str.begin(), end, rev.begin(), same_char);
}

int main()
{
  // set locales
  locale::global(locale(""));
  cin.imbue(locale());
  cout.imbue(locale());

  // print the line if is_palindrome is true
  string line;
  while (getline(cin, line))
    if (is_palindrome(line))
      cout << line << '\n';
    else cout << "Not a Palindrome.";
}
