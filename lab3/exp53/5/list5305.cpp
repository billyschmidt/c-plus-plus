/** 
 * counting words again -
 * copying program 40-5, and changing the functor
 * classes to use cached facets
 *
 */

#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <locale>
#include <map>
#include <ostream>
#include <string>
#include <algorithm>


typedef std::map<std::string, int> count_map;
typedef count_map::iterator count_iter;
typedef std::string::size_type str_size;


// initialize the I/O streams by imbuing them with the global locale
void initialize_streams()
{
  std::cin.imbue(std::locale());
  std::cout.imbue(std::locale());
}


// find the longest key in a map
str_size get_longest_key(count_map map)
{
  str_size result(0);
  for (count_iter iter(map.begin()); iter != map.end(); ++iter)
    if (iter->first.size() > result)
      result = iter->first.size();
  return result;
}


// print the word, count, newline
void print_pair(count_iter iter, str_size longest)
{
  const int count_size(10);
  std::cout << std::setw(longest) << std::left  << iter->first 
	    << std::setw(count_size) << std::right << iter->second << '\n';
}


// print the results in neat columns
void print_counts(count_map counts)
{
  str_size longest(get_longest_key(counts));
  
  for (count_iter iter(counts.begin()); iter != counts.end(); ++iter)
    print_pair(iter, longest);
}


typedef std::map<std::string, int> count_map;
typedef count_map::iterator count_iter;
typedef std::string::size_type str_size;


// base class to hold a ctype facet
class function
{
public:
  function(std::locale loc) : ctype_(std::use_facet<std::ctype<char> >(loc)) {}
  bool isalnum(char ch) const { return ctype_.is(std::ctype_base::alnum, ch); }
  char tolower(char ch) const { return ctype_.tolower(ch); }
private:
  std::ctype<char> const& ctype_;
};


// test for non-letter
class non_letter : public function
{
public:
  non_letter(std::locale loc) : function(loc) {}
  bool operator()(char ch)
    const
  {
    return not isalnum(ch);
  }
};


// convert to lowercase
class lowercase : public function
{
public:
  lowercase(std::locale loc) : function(loc) {}
  char operator()(char ch)
    const
  {
    return tolower(ch);
  }
};


// sanitize a string by keeping only alphabetic characters
class sanitizer : public function
{
public:
  sanitizer(std::locale loc) : function(loc), non_letter_(loc), lowercase_(loc) {}
  std::string operator()(std::string str)
  {
    str.erase(std::remove_if(str.begin(), str.end(), non_letter_), str.end());

    std::transform(str.begin(), str.end(), str.begin(), lowercase_);

    return str;
  }
private:
  non_letter non_letter_;
  lowercase lowercase_;
};


int main()
{
  std::locale native(std::locale(""));
  std::locale::global(native);
  initialize_streams();
  
  count_map counts;
  std::string word;
  sanitizer sanitize(native);
  
  while (std::cin >> word) {
    
    std::string copy(sanitize(word));
    
    if (not copy.empty()) {
      
      ++counts[copy];
    }    
  }
  
  print_counts(counts);
}
