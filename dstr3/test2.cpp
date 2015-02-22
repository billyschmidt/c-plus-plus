
#include <iostream>
#include <string>

#include "binary_heap.hpp"


int main() {
	using namespace std;
	
	priority_queue Q(100);
	
	Q.insert("Eight", 8);
	Q.insert("Eleven", 11);
	Q.insert("Fifteen", 15);
	Q.insert("Five", 5);
	Q.insert("Four", 4);
	Q.insert("Fourteen", 14);
	Q.insert("Nine", 9);
	Q.insert("One", 1);
	Q.insert("Seven", 7);
	Q.insert("Six", 6);
	Q.insert("Sixteen", 16);
	Q.insert("Ten", 10);
	Q.insert("Thirteen", 13);
	Q.insert("Three", 3);
	Q.insert("Twelve", 12);
	Q.insert("Two", 2);
	
	cout << "Should be One: " << Q.extract_min() << endl;
	
	Q.insert("Eighteen", 18);
	Q.insert("Nineteen", 19);
	Q.insert("One", 1);
	Q.insert("Seventeen", 17);
	Q.insert("Twenty", 20);

	cout << "Now should produce One through Twenty in order:\n";
	
	while( ! Q.empty() ) {
	cout << Q.extract_min() << endl;
	//cout << string(Q);
	}
	
}
