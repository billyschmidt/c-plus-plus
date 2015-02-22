/**
 * Bill Schmidt
 * 4159697
 * stack.cpp -
 * implementation of stack.hpp
 *
 */

#include <iostream>
#include <ostream>

#include "stack.hpp"


// constructor
stack::stack(int n)
  :num(0), size(n)
{
  A = new double[n];
}


// destructor
stack::~stack()
{
  delete[] A;
}


// test for empty
bool stack::empty()
{
  return num == 0;
}


// push
void stack::push(double x)
{
  if (num < size)  // only push if num is less than size, else throw an exception (out of space)
    {
      A[num] = x;  // assign value given into slot
      ++num;  //increment value given
    }
  else
    {
      throw stackerror();
    }
}


// pop
double stack::pop()
{
  if (size != 0)  // list contains at least one element
    {
      --num; // reduce number
      return A[num]; // remove number
    }
  else
    {
      throw stackerror();
    }
}


// dump
void stack::dump()
{
  if (size == 0) {
    std::cout << "Stack is empty." << '\n';
  }
  
  else {
    std::cout << "Stack contains:" << '\n';
    
    for (int i = 0; A[i] !=0; ++i) {
      std::cout << A[i] << '\n';
    }
  }
}
