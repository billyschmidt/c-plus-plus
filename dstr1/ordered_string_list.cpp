/**
 * Bill Schmidt
 * 4159697
 * ordered string list implementation
 * using doubly linked list
 *
 */

#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>

#include "ordered_string_list.hpp"


// destructor
ordered_string_list::~ordered_string_list()
{
  node* curr(first);
  
  while (curr->next != 0) {
    curr = curr->next;
    delete curr->prev;
  }
		  
  delete last;
  first = 0;
  last = 0;
}


// find
//
// return 0 is no node found and no node that is greater than s
// return not-null if EITHER node found OR node after it in the sort order
//
//
ordered_string_list::node* ordered_string_list::find(std::string s) const
{
  node* curr(first);

  while (curr != 0 and curr->val < s) {
    curr = curr->next;
  }
  return curr; 
}


// size
int ordered_string_list::size()
{
  return count;
}


// insert
void ordered_string_list::insert(std::string s)
{
  
  if (size() == 0) {  // empty list so insert in front
    
    node* tmp = new node(s, 0, 0);
    first = tmp;
    last = tmp;
    ++count;
  }
  
  else	{
	node* curr = find(s);
	
	// if we have fallen off the end
	// then we need to add new node at the end as new last
	if (curr == 0) { 
	  
	  node* final = new node(s, last, 0);
	  last->next = final;
	  last = final;
	  ++count;
	}
	//
	// else if we found it OR we found the node AFTER it
	else {
	  if (curr->val == s) {
		// uh-oh this should not happen!
	  }
	  //
	  // if we are here then curr->val > s
	  //
	  else {
		//
		// we found the node after s and this node
		// is the first node 
		// then we need to make this the new first
		//
		if (curr->prev == 0) { // insert at front
			
		  node* tmp = new node(s, 0, curr);
		  curr->prev = tmp;
		  first = tmp;
		  ++count;
		}
		//
		// else we found the node after it and it 
		// is NOT the first but it could be the last...
		//
		else if (curr->next==0) {
		  //
		  //    BEFORE:
		  //      curr+
		  //          |
		  //          v              
		  //    [A]->[C]->null
		  //
		  //    look for [B]<----tmp
		  //
		  //    AFTER
		  //             tmp+curr+
		  //                |    |
		  //             yy v xx v              
		  //    firs->[A]->[B]->[C]->null
		  //    null<-[A]<-[B]<-[C]<-last
		  //             xx   zz   
		  //
		  //    xx - set tmp, tmp->prev, and tmp->next in constructor
		  //	yy - set tmp->prev->next to point to tmp
		  //	zz - set tmp->next->prev to point to tmp
			
		  // this is xx above
		  node* tmp = new node(s, curr->prev, curr);
			
		  // this is yy above
		  tmp->prev->next = tmp;
			
		  // this is zz above
		  tmp->next->prev = tmp;
			
		  ++count;
		}
	  }
	}
  }
}


// remove
bool ordered_string_list::remove(std::string s)
{
  node* curr = find(s);
  
  if (size() == 0) {
    
    return false;
  }
  
  //ensures current contains the value otherwise it is not in the list
  else if (curr->val != s) {
    
    return false;
  }
  
  //if only 1 item in list returns the empty list	
  else if (size() == 1) {
    
    first = 0;
    last = 0;
    --count;
    return true;
  }
  
  //remove first node
  else if (curr->prev == 0) {
    
    curr->next->prev = 0;
    first = curr->next;
    --count;
    delete curr;
    return true;
  }
  
  //remove last node
  else if (curr->next == 0) {
    
    curr->prev->next = 0;
    last = curr->prev;
    --count;
    delete curr;
    return true;
  }
  
  //general case
  else {
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
	delete curr;
    --count;
    return true;
  }
}


// member
bool ordered_string_list::member(std::string s) const
{
  node *target=find(s);
  
  // we cannot do this:
  //  return (find(s)!=0);
  // that is too simplistic
  // 
  // if find is NULL we did not find the target (s)
  // if target is not null then either we found it 
  // or we found the node that comes AFTER s
  if (target!=0)
	{
	  if (target->val==s)
		{
		  return true;
		}
	}
  
  return false;  // returns true if we can find string in list, else returns false
}


// string conversion
ordered_string_list::operator std::string() 
{ 
  std::stringstream text; 
  node* current = first; 
  
  while(current != 0) { 
    text << current->val << std::endl; 
    current = current->next; 
  } 
  
  return text.str(); 
}
