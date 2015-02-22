#include <algorithm>
#include <iostream>
#include <istream>
#include <locale>
#include <ostream>

// more overloading practice

using namespace std;

bool is_alpha(char ch)
{
  return isalpha(ch, locale());
}

bool is_alpha(string const& str)
{
  for (string::const_iterator iter(str.begin()); iter != str.end(); ++iter)
    if (not is_alpha(*iter))
      return false;
  return true;
}

char to_lower(char ch)
{
  return tolower(ch, locale());
}

string to_lower(string str)
{
  for (string::iterator iter(str.begin()); iter != str.end(); ++iter)
    *iter = to_lower(*iter);
  return str;
}
  
char to_upper(char ch)
{
  return toupper(ch, locale());
}

string to_upper(string str)
{
  for (string::iterator iter(str.begin()); iter != str.end(); ++iter)
    *iter = to_upper(*iter);
  return str;
}

int main()
{
  string str;
  while (cin >> str)
    {
      if (is_alpha(str))
	cout << "alpha\n";
      else
	cout << "not alpha\n";
        cout << "lower: " << to_lower(str) << "\nupper: " << to_upper(str) << '\n';
    }
}
