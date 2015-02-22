/** 
 * adding the feature
 * parsing comments in the miles per gallon file
 *
 */

#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>

int main()
{

  using namespace std;

  // initialize variables
  double prev_odometer(0.0);
  double odometer(0.0);
  double total_fuel(0.0);
  
  string line;
  int linenum(0);
  bool error(false);
  
  // gather input
  while (getline(cin, line)) {
    
    istringstream input(line);
    ++linenum;
    
    char comment;

    if (input >> comment && comment != '#') {

      input.unget();
      double fuel;

      if (input >> odometer) {
	
	if (not (input >> fuel)) {
	  
	  // throw error message
	  cerr << "No fuel consumption" << linenum << '\n';
	  error = true;
	}
	
	else if (fuel != 0) {
	  
	  // compute mpg
	  double distance(odometer - prev_odometer);
	  cout << distance / fuel << '\n';
	  total_fuel += fuel;
	  prev_odometer = odometer;
	}
      }
    }
  }
  
  // print message
  if (total_fuel != 0) {
    
    cout << "Your miles per gallon are: " << odometer / total_fuel;
    
    // print message is error detected
    if (error) {
      
      cout << "estimated with input error";
      cout << '\n';
    }
  }
}
