/**
 * queue ADT class declaration
 * 
 */

#ifndef __QUEUE_HPP
#define __QUEUE_HPP


class queue_error {}; // an object of this class is something to throw if there's an error

class queue { //a queue of integers
public:
  
  queue(int n) : front(0), back(0), N(n+1) { A = new int[n+1]; } //empty queue with max size of n
  ~queue() { delete[] A; } //delete all storage allocated dynamically

  bool empty();	// return true or false according to whether the queue is empty
	
  double get(); 	// get (& remove) the value from the front of the queue and return it; throw a new queue_error() if empty
	
  void put(int x);	// put an item at the back of the queue; if the array A is full, throw queue_error()

  void dump(); 	// (to help you fix bugs) write out the queue to standard output from front to back, one number per line
							
private:
  int* A;	// array to store items on the queue
  int front;	// the index of the item at the front of the queue;
  int back;	// the index one more (modulo N) than  that of the back of the queue; the place put assigns its x
  int N;		// the size of the array that A currently points to
	
  void increment(int& k) { if( ++k == N ) k = 0; } //move k on one, modulo N
};


#endif
