#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <map>
#include <ostream>
#include <string>

int main()
{
  using namespace std;
  typedef map<string, int>    count_map;
  typedef count_map::iterator count_iter;
  typedef string::size_type   str_size;

  count_map counter;
  string word;

  string allow("ABCDEFGHIJKLMNOPQRSTUVWXYZ"
              "abcdefghijklmnopqrstuvwxyz"
              "0123456789-_");
  while (cin >> word)
    {
      string copy;
      for (string::iterator w(word.begin()); w != word.end(); ++w)
	if (allow.find(*w) != string::npos)
	  copy.push_back(*w);
    
      if (not copy.empty())
	++counter[copy];
    }

  str_size longest(0);
  for (count_iter iter(counter.begin()); iter != counter.end(); ++iter)
    if (iter->first.size() > longest)
      longest = iter->first.size();
  
  const int count_size(10);
  for (count_iter iter(counter.begin()); iter != counter.end(); ++iter)
    cout << setw(longest)    << left << iter->first <<
      setw(count_size) << right << iter->second << '\n';
}
