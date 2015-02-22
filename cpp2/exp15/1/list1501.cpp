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

  count_map counts;
  string word;

  while (cin >> word)
    ++counts[word];

  str_size longest(0);
  for (count_iter iter(counts.begin()); iter != counts.end(); ++iter)
    if (iter->first.size() > longest)
      longest = iter->first.size();
  
  const int count_size(10);
  for (count_iter iter(counts.begin()); iter != counts.end(); ++iter)
    cout << setw(longest)    << left << iter->first <<
      setw(count_size) << right << iter->second << '\n';
}
