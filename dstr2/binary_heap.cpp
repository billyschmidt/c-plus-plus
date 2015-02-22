/**
 * Bill Schmidt
 * 4159697
 * implementing the priority queue as a binary heap
 *
 */

#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <map>
#include <algorithm>

#include "binary_heap.hpp"

/***********************
 *** inline functions
 ***********************/
inline int left(int i) { return i << 1; }

inline int right(int i) { return i << 1 | 1; }

inline int parent(int i) { return i >> 1; }


/*********************
 *** constructor
 *********************/
priority_queue::priority_queue(int n)  
{
  heapsize = 0;
  size = n;

  // don't forget to allocate the array of size n+1 as we don't use slot zero 
  A = new pair[n+1];
}


/*********************
 *** destructor
 *********************/
priority_queue::~priority_queue()  //delete the array
{
  delete[] A;
}


/*******************************************
 *** heapify * finds max of three things
 *******************************************/
void priority_queue::heapify(int k)
{
  pair smallest = A[k];
  int pos = k;        
  
  //only treat child as object if it's inside heap
  if (left(k) <= heapsize and A[left(k)].key < A[pos].key) {
    
    // update variables
    smallest = A[left(k)];
    pos = left(k);
  }
  
  // identical for right
  if (right(k) <= heapsize and A[right(k)].key < A[pos].key) {
    
    // update variables
    smallest = A[right(k)];
    pos = right(k);
  }
  
  // after both if's exectued: smallest is pair with smallest key and
  // pos is index of that pair in A[]
  
  // only need to do something if pos is NOT the same position
  // that we were passed in originally
  if (pos != k) {
    
    // swap items
    std::swap(A[k], A[pos]);
    
    // go recursive to trickle down...
    heapify(pos);
  }
}


/****************
 *** empty
 ****************/
bool priority_queue::empty()
{
  return (heapsize == 0);
}


/****************
 *** insert
 ****************/
void priority_queue::insert(std::string s, double priority)  //add s to the heap with the given priority as its key
{
  if (heapsize == size) {
    throw priority_queue_overflow();
  }
  
  // make room for insert
  ++heapsize;  
  // assign string arg to object member
  A[heapsize].object = s;
  // assign priority arg to key member
  A[heapsize].key = priority;
  
  // loop through and trickle up as needed
  int i(heapsize);
  while (i > 1 and A[parent(i)].key > A[i].key) {
    std::swap(A[parent(i)], A[i]);
    i = parent(i);	
  }
}


/*******************
 *** extract_min
 *******************/
std::string priority_queue::extract_min()  //remove the string of lowest key and return that string
{
  if (heapsize == 0) {
    throw priority_queue_underflow();
  }
  
  std::string ans = A[1].object;
  A[1] = A[heapsize];
  --heapsize;
  // trickle down as needed
  heapify(1);
  return ans;        
}


/**********************************
 *** function operator overload
 **********************************/
priority_queue::operator std::string()
{
  std::stringstream text; 
  int i(1);    

  while (i <= size) { 
    text << A[i].object << std::endl;
    ++i;
  } 
  return text.str(); 
}
