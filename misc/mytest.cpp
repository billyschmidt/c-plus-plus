/**
 * driver for queue ADT class
 *  
 */


#include <iostream>
#include <ostream>

#include "queue.hpp"

int main() {
  using namespace std;
	
  queue even(100), odd(100);
  int x;

  try {

	while( cin >> x ) {
	  if( x % 2 == 1 ) odd.put(x);
	  else even.put(x);
	}

	cout << "DUMPING EVEN" << endl;
	even.dump();
	cout << "DUMPING ODD" << endl;
	odd.dump();

	cout << endl;
	while( !even.empty() ) cout << even.get() << endl;
	cout << endl;
	while( !odd.empty() ) cout << odd.get() << endl;
	
  } catch( queue_error ) {
	cout << "queue overflowed\n";
  }
	
}

