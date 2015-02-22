/** 
 * Bill Schmidt
 * 4159697
 * counting occurences of tokens
 * modifying 50-10 to use map instead of vector
 *
 */

#include <iostream>
#include <istream>
#include <iterator>
#include <algorithm>
#include <map>
#include <ostream>
#include <string>

namespace parser
{
  class token
  {
  public:
    // constructors
    token() : text_() {}
    token(std::string& s) : text_(s) {}
    
    // assignment overload
    token& operator=(std::string const& s)
    {
      text_ = s; return *this; 
    }

    // get text    
    std::string text() const 
    { 
      return text_; 
    }
    
  private:
    std::string text_;
  };
  
  // less-than overload to store in map
  bool operator<(token const& a, token const& b)
  {
    return a.text() < b.text();
  }

  // input overload  
  std::istream& operator>>(std::istream& in, parser::token& t)
  {
    std::string str;
    if (in >> str)
      t = str;
    return in;
  }

  // output overload
  std::ostream& operator<<(std::ostream& out, parser::token const& t)
  {
    out << t.text();
    return out;
  }

  // additional output overload for pairs
  std::ostream& operator<<(std::ostream& out, std::pair<const token, long> const& count)
  {
    out << count.first.text() << '\t' << count.second << '\n';
    return out;
  }
}

int main()
{
  using namespace parser;
  using namespace std;
  
  map<token, long> tokens;
  token t;
  
  while (std::cin >> t) {
    ++tokens[t];
  }
  copy(tokens.begin(),
       tokens.end(),
       ostream_iterator<pair<const token, long> >(cout));
}
