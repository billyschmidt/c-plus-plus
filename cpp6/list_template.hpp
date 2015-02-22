/**
 * Bill Schmidt
 * 4159697
 * Implementing a concrete singly linked list data structure
 *
 */

#include <iostream>
#include <ostream>


template<typename T>
struct node 
{
  node* next_;
  T value_;  
  
  node(node* list, T value)  // constructor only called once when new node created
    :next_(list), value_(value) // initialize next pointer to 0, value to value
  {} 
};

// add to beginning of list represented by the pointer list to its first node
template<typename T>
void push(node<T>*& list, T value)
{
  list = new node<T>(list, value);
}

// add value to the end of the node represented by list
template<typename T>
void append(node<T>*& list, T value)
{
  node<T>* newnode = new node<T>(0, value); // create new list, set pointer to null
  
  if (list == 0) { // if list is null
    list = newnode; // set list to last
    return;
  } 
  
  // list is not not null, so make pointer curr to look around
  node<T>* curr(list);  
  while (curr -> next_ != 0) { // keep moving pointer until it hits the end
    curr = curr -> next_;
  }
  
  // breaking out of the while, we know next is null
  curr -> next_ = newnode; // so make the new node and set curr->next to be that guy. also can make the next point to null since it's at the end
}


// return the sum of all the elements of the list represented by list
template<typename T>
T sum(node<T>* list)
{
  int total(0);  // initialize variable for getting total
  node<T>* curr(list);  // make current pointer looking at list
  
  while (curr) {  // loop through,
    total += curr -> value_;  // +='ing the values,
    curr = curr -> next_;  // setting curr to curr -> next
  }
  return total; // return that bad boy
}

//write out the elements of the list each followed by a newline
template<typename T>
std::ostream& operator<<(std::ostream& out, node<T>* list)
{
  node<T>* curr(list);  // made head pointer looking at list, head=list is same as head(list) is guess?
 
  while (curr != 0) {  // loop while a head exists
    out << curr -> value_ << std::endl; // cout that sucker
    curr = curr -> next_; //  moving right along
  }
  return out;
}
