#include <iostream>
#include <istream>
#include <locale>
#include <map>
#include <ostream>
#include <string>

using namespace std;

int main()
{
  locale native("");             
  
  cin.imbue(native);             
  cout.imbue(native);            

  typedef map<string, int> count_map;
  typedef count_map::iterator count_iter;

  count_map counter;
  string word;

  while (cin >> word)
    {
      string copy;
      for (string::iterator w(word.begin()); w != word.end(); ++w)
	if (isalnum(*w, native))
	  copy.push_back(tolower(*w, native));

      if (not copy.empty())
	++counter[copy];
    }

  for (count_iter iter(counter.begin()); iter != counter.end(); ++iter)
    cout << iter->first << '\t' << iter->second << '\n';
}
