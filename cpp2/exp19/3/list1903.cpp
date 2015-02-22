#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <locale>
#include <map>
#include <ostream>
#include <string>

typedef std::map<std::string, int>  count_map;
typedef count_map::iterator         count_iter;
typedef std::string::size_type      str_size;


void initialize_streams(std::locale locale)
{
  std::cin.imbue(locale);
  std::cout.imbue(locale);
}


str_size get_longest_key(count_map map)
{
  str_size result(0);
  for (count_iter iter(map.begin()); iter != map.end(); ++iter)
    if (iter->first.size() > result)
      result = iter->first.size();
  return result;
}


void print_pair(count_iter iter, str_size longest)
{
  const int count_size(10);
  std::cout << std::setw(longest)    << std::left  << iter->first <<
    std::setw(count_size) << std::right << iter->second << '\n';
}


void print_counts(count_map counts)
{
  str_size longest(get_longest_key(counts));
  
  for (count_iter iter(counts.begin()); iter != counts.end(); ++iter)
    print_pair(iter, longest);
}


std::string sanitize(std::string str, std::locale loc)
{
  std::string result;
  for (std::string::iterator s(str.begin()); s != str.end(); ++s)
    if (std::isalnum(*s, loc))
      result.push_back(std::tolower(*s, loc));
  return result;
}


int main()
{
  std::locale native("");
  initialize_streams(native);

  count_map counts;
  std::string word;

  while (std::cin >> word)
    {
      std::string copy(sanitize(word, native));
      if (not copy.empty())
	++counts[copy];
    }

  print_counts(counts);
}
