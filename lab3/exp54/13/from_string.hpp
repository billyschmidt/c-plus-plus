/**
 * extracting a value from a string
 *
 */

#include <istream>
#include <sstream>
#include <string>

template<class T>
T from_string(std::string const& str)
{
  std::istringstream in(str);
  T result;
  if (in >> result)
    return result;
  else
    throw "Error!";
}
