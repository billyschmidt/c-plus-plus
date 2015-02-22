/**
 * expr.cpp -
 * driver for stack.hpp 
 *
 */

#include <iostream>
#include <istream>

#include "stack.hpp"

int main() {
  using namespace std;

  stack stack(100);
  char op;
  double left, right, val;
	
  try{
  
    while( true ) {
      stack.dump();
      cin >> val;
      if( cin ) 
	stack.push(val);
      else { //reading a double failed, and we have an operator or the end of input
	cin.clear(); //fix the failed read
	cin.unget(); //put back the character that cause the read to fail
	cin >> op;
	if( !cin ) break; //failed to read an operator; end of input so break out of while loop
	right = stack.pop();
	left = stack.pop();
	switch( op ) { //new kind of branch
	case '+': stack.push(left + right); break;
	case '-': stack.push(left - right); break;
	case '*': stack.push(left * right); break;
	case '/': stack.push(left / right); break;
	default: throw "nonsense";  // quick-and-dirty  termination for garbage character
	}
      } // end do operator
    } //end while
    val = stack.pop(); //get the answer off the stack
	
  } catch( stackerror se ) {
    cout << "Invalid expression: attempted to pop an empty stack!\n";
    return 0; //from main
  } catch( ... ) {
    cout << "Illegal operator or other illegal input!\n";
    return 0;
  }

  if( not stack.empty() )
    cout << "Invalid expression: numbers remain on the stack when evaluation complete!\n";
  else
    cout << "The value of the input expression is " << val << endl;
}
