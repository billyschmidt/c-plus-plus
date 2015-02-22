#include <iomanip>
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

  map<string,int>::iterator the(counts.find("the"));
  if (the == counts.end())
    cout << "\"the\": not found\n";
  else if (the->second == 1)
    cout << "\"the\": occurs " << the->second << " time\n";
  else
    cout << "\"the\": occurs " << the->second << " times\n";
}
