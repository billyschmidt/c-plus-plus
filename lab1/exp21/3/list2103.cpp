// Bill Schmidt 
// 4159697 
// sanitize re-write using transform and remove_if
// then placed inside of listing 2102 with slight mods

#include <iomanip>
#include <ios>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <map>

// returns letters
bool non_letter(char c)
{
  return not isalnum(c, std::locale());
}

// make lowercase func
char make_lowercase(char c)
{
  return std::tolower(c, std::locale());
}

// string sanitizer
std::string sanitize(std::string s)
{
  s.erase(std::remove_if(s.begin(), s.end(), non_letter), s.end());

  std::transform(s.begin(), s.end(), s.begin(), make_lowercase);

  return s;
}

// use typedefs to make code easier to manage
typedef std::map<std::string, int>  count_map;  ///< Map words to counts
typedef count_map::iterator         count_iter; ///< Iterate over a @c count_map
typedef std::string::size_type      str_size;   ///< String size type

// stream initializer
void initialize_streams()
{
  std::cin.imbue(std::locale());
  std::cout.imbue(std::locale());
}

// find longest key
str_size get_longest_key(count_map map)
{
  str_size result(0);
  for (count_iter iter(map.begin()); iter != map.end(); ++iter)
    if (iter->first.size() > result)
      result = iter->first.size();
  return result;
}

// print words
void print_pair(count_iter iter, str_size longest)
{
  const int count_size(10); // Number of places for printing the count
  std::cout << std::setw(longest)    << std::left  << iter->first <<
    std::setw(count_size) << std::right << iter->second << '\n';
}

// print counts
void print_counts(count_map counts)
{
  str_size longest(get_longest_key(counts));
  
  for (count_iter iter(counts.begin()); iter != counts.end(); ++iter)
    print_pair(iter, longest);
}

/** main program to count unique words in the standard input
 * using modified sanitize function. */
int main()
{
  // set locales to native
  std::locale::global(std::locale(""));
  initialize_streams();

  count_map counts;
  std::string word;

  while (std::cin >> word)
    {
      std::string copy(sanitize(word));

      if (not copy.empty())
	++counts[copy];
    }
  print_counts(counts);
}
