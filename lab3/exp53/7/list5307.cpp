/** 
 * testing collation order of wide strings 
 * rewrite listing 53-6 to use wstring instead
 * of string literals, write to wcout
 *
 */

#include <iostream>
#include <ostream>
#include <locale>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

std::wstring widen(std::string const& narrow)
{
  return std::wstring(narrow.begin(), narrow.end());
}

void sort_words(std::vector<std::wstring> words, std::locale loc)
{
  std::sort(words.begin(), words.end(), loc);
  std::wcout << widen(loc.name()) << L":\n";
  std::copy(words.begin(), words.end(), std::ostream_iterator<std::wstring, wchar_t>(std::wcout, L"\n"));
}

int main()
{
  using namespace std;
  
  vector<wstring> words;
  
  words.push_back(L"circus");
  words.push_back(L"\u00e5ngstrom");
  words.push_back(L"\u00e7irc\u00ea");
  words.push_back(L"angle");
  words.push_back(L"essen");
  words.push_back(L"ether");
  words.push_back(L"\u00e6ther");
  words.push_back(L"aether");
  words.push_back(L"e\u00dfen"); 

  sort_words(words, locale::classic());
  sort_words(words, locale("en_GB.utf8"));
  sort_words(words, locale("no_NO.utf8"));
}
