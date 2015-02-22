/**
 * Bill Schmidt
 * 4159697
 * 
 * implementing the queue ADT class
 * 
 */

#include <iostream>
#include <ostream>

#include "queue.hpp"



/**************
 * NAME: empty 
 * DESC: return true or false according to whether the queue is empty
 ***************/
bool queue::empty()
{
  return (front == back);
}



/**************
 * NAME: get
 * DESC: get (& remove) the value from the front of the queue and return it; throw a new queue_error() if empty
 ***************/
double queue::get()
{
  // 1. if empty, throw error  
  if (empty())
	{
	  throw queue_error();
	}

  // 2. increment front
  increment(front);

  // 3. return front
  return A[front];
}



/**************
 * NAME: put
 * DESC: put an item at the back of the queue; if the array A is full, throw queue_error()
 ***************/
void queue::put(int x)
{
  // 1. check if full, throw error
  if (front == back+1 % N)
	{
	  throw queue_error();
	}
  
  // 2. increment back
  increment(back);

  // 3. put x in back of queue 
  A[back] = x;   
}



/**************
 * NAME: dump 
 * DESC: (to help you fix bugs) write out the queue to standard output from front to back, one number per line
 ***************/
void queue::dump()
{
  if (!empty())
	{
	  int i(front);    
	  
	  do 	   
		{		  
		  increment(i);
		  std::cout << A[i] << std::endl;
		}
	  
	  while (i != back);
	}
}
