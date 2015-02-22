/**
 * stack.hpp -
 * stack class template
 *
 */

#ifndef __STACK_HPP
#define __STACK_HPP

#include <iostream>
#include <ostream>

class stackerror {};   // an object of this class is something to throw if there's an error

class stack
{
public:
  stack(int n);           // set num to zero and allocate an array of doubles of size n for A to point to
  
  ~stack();               // delete the array that A points to
  
  bool empty();	          // return true or false according to whether the stack is empty
  
  void push(double x);    /* push an item onto the top of the stack; if the array A is full, allocate a new one of twice the size,
			     copy the old array into it, make A point to it and delete the old array */

  double pop();           // pop the value off the top of the stack and return it; throw a new stackerror() if the stack is empty
    
  void dump();            // (to help you fix bugs) write out the stack to standard output from top to bottom, one number per line

private:
  double* A;	// array to store items on the stack
  int num;	// number of items on the stack
  int size;	// the size of the array that A currently points to
};

#endif
