/**
 * nodetest.cpp - 
 * driver for list_template.hpp
 *
 */

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
	
  cout << "It's head is " << hd(ls) << endl;
  cout << "and it's tail is\n" << tl(ls);
	
  list ls2 = copy(ls);
	
  change(ls2, -1, 99);
	
  cout << "New list with 99 in place of -1 is\n" << ls2;
  cout << "Original list is still\n" << ls;
	
  change(ls2, 3, 99);
	
  cout << "New list with 99 in place of 3 and -1 is\n" << ls2;
  cout << "Original list is still\n" << ls;

  del(ls2, 99);
  cout << "New list with first 99 deleted is\n" << ls2;
	
  del(ls2, 99);
  cout << "New list with first and second 99s deleted is\n" << ls2;
  cout << "Original list is still\n" << ls;
	
  list longlist = concat(ls, ls2);
  cout << "concatenation of the two lists is\n" << longlist;
	
}
