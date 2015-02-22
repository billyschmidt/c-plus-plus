/**
 * driver for priority_queue.cpp
 *
 */

#include <iostream>
#include <ostream>
#include <string>

#include "binary_heap.hpp"

int main()
{
  
  using namespace std;
  
  // NOT USING POSITION ZERO
  std::string* string_array;
  string_array = new std::string[8];
  string_array[1] = "hey";
  string_array[2] = "there";
  string_array[3] = "bill";
  string_array[4] = "you";
  string_array[5] = "are ";
  string_array[6] = "really";
  string_array[7] = "awesome";

  priority_queue Q(100, string_array, 7);

  double *key_array = new double[8];
  key_array[1] = 100.0;		//hey
  key_array[2] = 90.0;		//there
  key_array[3] = 80.0;		//bill
  key_array[4] = 70.0;		//you
  key_array[5] = 60.0;		//are
  key_array[6] = 50.0;		//really
  key_array[7] = 40.0;		//awesome

  priority_queue S(100, string_array, key_array,7);


  //cout << "EVEN SOONER:\n";
  //cout << "=======================\n";
  //cout << string(S);
  //cout << "=======================\n";

  cout << "Should be awesome: " << S.extract_min() << endl;
	
  S.insert("Eighteen", 18);
  S.insert("Nineteen", 19);
  S.insert("One", 1);
  S.insert("Seventeen", 17);
  S.insert("Twenty", 20);

  //cout << "BEFORE SHOULD BE:\n";
  //cout << "One\n";
  //cout << "Seventeen\n";
  //cout << "Eighteen\n";
  //cout << "Nineteen\n";
  //cout << "Twenty\n";
  //cout << "really\n";
  //cout << "are\n";
  //cout << "you\n";
  //cout << "bill\n";
  //cout << "there\n";
  //cout << "hey\n";
  //cout << "=======================\n";

  //cout << "before\n";
  //cout << "=======================\n";
  //cout << string(S);
  //cout << "=======================\n";

  cout << "AFTER SHOULD BE:\n";
  cout << "One\n";
  cout << "Seventeen\n";
  cout << "Eighteen\n";
  cout << "Nineteen\n";
  cout << "Twenty\n";
  cout << "really\n";
  cout << "are\n";
  cout << "you\n";
  cout << "there\n";
  cout << "bill\n";
  cout << "hey\n";
  cout << "=======================\n";

  S.decrease_key("there", 75.0);

  cout << "after\n";
  cout << "=======================\n";
  cout << string(S);
  cout << "=======================\n";


  cout << "=======================\n";
  cout << "AFTER\n";
  cout << "=======================\n";
	
  
  while( ! S.empty() ) {
    cout << S.extract_min() << endl;
    //cout << string(S);
  }

  cout << "=======================\n";





  // Q.insert("Eight", 8);
  // Q.insert("Eleven", 11);
  // Q.insert("Fifteen", 15);
  // Q.insert("Five", 5);
  // Q.insert("Four", 4);
  // Q.insert("Fourteen", 14);
  // Q.insert("Nine", 9);
  // Q.insert("One", 1);
  // Q.insert("Seven", 7);
  // Q.insert("Six", 6);
  // Q.insert("Sixteen", 16);
  // Q.insert("Ten", 10);
  // Q.insert("Thirteen", 13);
  // Q.insert("Three", 3);
  // Q.insert("Twelve", 12);
  // Q.insert("Two", 2);
	
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



  // std::string* string_array;
  // string_array = new std::string[7];
  // string_array[0] = "hey";
  // string_array[1] = "there";
  // string_array[2] = "bill";
  // string_array[3] = "you";
  // string_array[4] = "are ";
  // string_array[5] = "really";
  // string_array[6] = "awesome";
  
  // for (int i(0); i <= 6; i++)
  // 	std::cout << string_array[i] << std::endl;
  
  // priority_queue S(10, string_array, 7);
  // std::cout << S << std::endl;

}	

