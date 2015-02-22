/**
 * Ordered String Class Declaration
 *
 */

#ifndef __ORDERED_STRING_LIST
#define __ORDERED_STRING_LIST

#include <string>

class ordered_string_list {
private:
  
  class node {
  public:
    node(std::string s, node* p, node* n) :
      val(s), prev(p), next(n) {} 
    std::string val;
    node *prev;
    node *next;
  };

  int count;
  node* first;
  node* last;

  node* find(std::string s) const;
	
public:
	
  ordered_string_list() : count(0), first(0), last(0) {}
  ~ordered_string_list();
	
  int size();
  void insert(std::string s);
  bool remove(std::string s);
  bool member(std::string s) const;
  operator std::string(); //conversion to string

};

#endif
