#include <iostream>
#include <istream>
#include <locale>
#include <map>
#include <ostream>
#include <string>

int main()
{
  using namespace std;
  typedef map<string, int>    count_map;
  typedef count_map::iterator count_iter;

  locale native("");             // get the native locale
  cin.imbue(native);             // interpret the input and output according to
  cout.imbue(native);            // the native locale

  count_map counts;
  string word;

  while (cin >> word)
    {
      string copy;
      for (string::iterator w(word.begin()); w != word.end(); ++w)
	if (isalnum(*w, native))
	  copy.push_back(*w);
      if (not copy.empty())
	++counts[copy];
    }

  for (count_iter iter(counts.begin()); iter != counts.end(); ++iter)
    cout << iter->first << '\t' << iter->second << '\n';
}
