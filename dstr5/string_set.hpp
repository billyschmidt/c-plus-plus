/**
 * Bill Schmidt
 * 4159697
 *
 * string_set class declaration
 * 
 */

#include <ostream>
#include <string>
#include <list>

class string_set
{
public:
  
  string_set(int n);
  ~string_set();
  
  bool insert(std::string s);
  bool remove(std::string s);
  bool member(std::string s);
  
  operator std::string();
  
private:
  typedef std::list<std::string>* ptr_to_list_of_strings;
  
  //array of pointers to lists of strings
  ptr_to_list_of_strings* table;
  
  int hash(std::string s);

  //the current number of lists in the table array
  int size;
  
};
