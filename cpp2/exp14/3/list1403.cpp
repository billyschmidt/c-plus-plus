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

  map<string, int> counter;
  string word;

  while (cin >> word)
    ++counter[word];

  string::size_type longest(0);
  for (map<string,int>::iterator iter(counter.begin()); iter != counter.end(); ++iter)
    if (iter->first.size() > longest)
      longest = iter->first.size();
  
  const int count_size(10);
  for (map<string,int>::iterator iter(counter.begin()); iter != counter.end(); ++iter)
    cout << setw(longest)    << left  << iter->first <<
      setw(count_size) << right << iter->second << '\n';
}
