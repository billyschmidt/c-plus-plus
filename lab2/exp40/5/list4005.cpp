// Bill Schmidt
// 4159697 
// implementing suggested optimization
// by creating objects in main and
// passing them as args to sanitize

#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <locale>
#include <map>
#include <ostream>
#include <string>
#include <algorithm>

// make typedefs to cleanup code
typedef std::map<std::string, int> count_map;
typedef count_map::iterator count_iter;
typedef std::string::size_type str_size;

// imbue with native locale
void initialize_streams()
{
  std::cin.imbue(std::locale());
  std::cout.imbue(std::locale());
}

// get the longest key
str_size get_longest_key(count_map map)
{
  str_size result(0);
  for (count_iter iter(map.begin()); iter != map.end(); ++iter)
    if (iter->first.size() > result)
      result = iter->first.size();
  return result;
}

// print the word, count, then newline
void print_pair(count_iter iter, str_size longest)
{
  const int count_size(10);
  std::cout << std::setw(longest)
	    << std::left << iter->first 
	    << std::setw(count_size)
	    << std::right << iter->second << '\n';
}

// print in columns
void print_counts(count_map counts)
{
  str_size longest(get_longest_key(counts));
  
  for (count_iter iter(counts.begin()); iter != counts.end(); ++iter)
    print_pair(iter, longest);
}

// base class to hold locale object
class function
{
public:
  function(std::locale loc) : locale_(loc) {}
  bool isalnum(char ch) const { return std::isalnum(ch, locale()); }
  char tolower(char ch) const { return std::tolower(ch, locale()); }
private:
  std::locale const& locale() const { return locale_; }
  std::locale locale_;
};


// class with tests for non-letter characters
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

// class to make conversion to lowercase
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

// class to sanitize string
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


// begin main
int main()
{
  // use native locale as global
  std::locale native(std::locale(""));
  std::locale::global(native);
  initialize_streams();

  count_map counts;
  std::string word;

  // pass locale object to sanitize
  sanitizer sanitize(native);

  while (std::cin >> word)
    {
      std::string copy(sanitize(word));

      if (not copy.empty())
	++counts[copy];
    }

  print_counts(counts);
}
