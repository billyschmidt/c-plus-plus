// nodetest.cpp

#include <iostream>

#include "list_template.hpp"

int main() {
  typedef node<int>* list;
  using namespace std;
	
  list ls(0); //empty list
	
  push(ls, 0); //add zero to the front of the list
  push(ls, 1);
  push(ls, 2);
  push(ls, 3);

  append(ls, -1);	//add -1 to the far end of the list
  append(ls, -2);
  append(ls, -3);
		
  cout << "The list is:\n" << ls; //print the list one number per line
  cout << "and it's sum is " << sum(ls) << endl; //add up the list
}
