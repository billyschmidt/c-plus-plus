#include <iostream>
#include <istream>
#include <map>
#include <ostream>
#include <string>

int main()
{
  using namespace std;

  map<string, int> counts;
  string word;

  while (cin >> word)
    ++counts[word];

  for (map<string,int>::iterator iter(counts.begin()); iter != counts.end(); ++iter)
    cout << iter->first << '\t' << iter->second << '\n';
}
