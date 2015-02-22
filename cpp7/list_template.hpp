/**
 * Bill Schmidt
 * 4159697
 * C++ Homework 7
 * Implementing a concrete singly linked list data structure (cont.)
 *
 * list_template.hpp -
 * node template definition
 *
 */


#include <iostream>
#include <ostream>


template<typename T>_
struct node
{
  T val;
  node* next;

  node(T v, node* np)
    : val(v), next(np) // use v and np to initialize val and next
  { /*empty*/ }
};


/* add x to beginning of list represented by pointer ls to its first node */
template<typename T>
void push(node<T>* & ls, T x)
{
  ls = new node<T>(x, ls); // set ls to new node
};


/* add x to the end of the list represented by ls */
template<typename T>
void append(node<T>*& ls, T x) 
{
  node<T>* last = new node<T>(x, 0); // make new node and set last pointer
  
  if (ls == 0) { // if list is null
    ls = last; // set list to last
    return;
  }
  
  node<T>* curr(ls); // make curr pointer to list
  
  while (curr->next != 0) { // continue until next is null
    curr = curr->next;
  }

  curr->next = last; // next is null, so set next to last
}


/* return the sum of all the elements of the list represented by ls */
template<typename T>
T sum(node<T>* ls) 
{
  T total(0); // initialize total
  
  node<T>* curr(ls); // make curr pointer to list
  
  while (curr != 0) { // loop through until null
    
    total += curr->val; // add values
    curr = curr->next;
  }
  
  return total;
}


/* write out the elements of the list each followed by a newline */
template<typename T>
std::ostream& operator<< (std::ostream& out, node<T>* ls) 
{
  node<int>* curr(ls);
  
  while (curr != 0) {
    out << curr->val << std::endl;
    curr = curr->next;
  }
  
  return out;
}


/* find the first node containing x and modify it to contain y, returning true if x is found and false if not */
template<typename T>
bool change(node<T>*& ls, T x, T y) 
{
  node<T>* curr(ls);
  
  while (curr != 0 and curr->val != x) {
    curr = curr->next;
  }
  
  if (curr == 0) {
    return false;
  }
  
  curr->val = y;
  return true;
}


/* delete the first node containing x from the list, returning true if x was found and false if not */
template<typename T>
bool del(node<T>*& ls, T x) 
{
  node<T>* prev(0);
  node<T>* curr(ls);
  
  while (curr != 0 and curr->val != x) {
    prev = curr;
    curr = curr->next;
  }
  
  if (curr == 0) { // ls is null or we could not find x
    return false;
  }
  
  else if (prev == 0) {  
	//
	// only possible if we found x in ls, since we already handled null ls
	// and this means that x was in the FIRST position
	//
    ls = curr->next; // cut off the head
  }
  
  else { 
	// x not first in list and we did find it in the list, connect prev to next
	//                           
	// i.e leap frog curr   [p] -> [c] -> [n]
	//
	//  after               [p] -> [n]
	//
    prev->next = curr->next;  
  }

  //
  // only way here is if curr is not null, and if curr->val is x
  // we already fixed the links above, so just delete it and return true!
  //
  delete curr;
  return true;
}


/* return the value in the first node in the list (the 'head') */
template<typename T>
T hd(node<T>* ls)
{
  return ls->val;
}


/* return all but the first node (the 'tail'), i.e. a pointer to the second node in the chain */
template<typename T>
node<T>* tl(node<T>* ls) 
{
  return ls->next; 
}


/* produce a copy of the entire chain of nodes,  returning a pointer to the first node in the copy */
template<typename T>
node<T>* copy(node<T>* ls) 
{
  if (ls == 0) {
    return 0;
  }
  
  return new node<T>(ls->val, copy(ls->next));
}


/* make a new list from copies of the two given lists
   the new list consists of the elements of ls1 followed by those of ls2 */
template<typename T>
node<T>* concat(node<T>* ls1, node<T>* ls2 ) 
{
  if (ls1 == 0) {
    return copy(ls2);
  }
  
  node<T>* curr = ls1 = copy(ls1);
  
  while (curr->next != 0) {
    curr = curr->next;
  }
  
  curr->next = copy(ls2);
  return ls1;
}
