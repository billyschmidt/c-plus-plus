/**
 * Driver for ordered string class
 *
 */

#include <iostream>

#include "ordered_string_list.hpp"

int main() {
  using namespace std;

  ordered_string_list ls; //empty list

  ls.insert("one");
  ls.insert("two");
  ls.insert("three");
  ls.insert("four");
  ls.insert("five");

  cout << "the list is of size " << ls.size() << endl;
  cout << "here is the list: \n" << string(ls);
	
  ls.remove("one");
  ls.remove("three");
  ls.remove("five");

  cout << "the list is now of size " << ls.size() << endl;
  cout << "here is the list: \n" << string(ls);
	
  if( ls.member("four") ) 
    cout << "four is still a member";
  else 
    cout << "four is not a member! (error)";
	
  if( !ls.member("three") ) 
    cout << " but three is not.\n";
  else 
    cout << " but three is still a member! (error)\n";
	
}
