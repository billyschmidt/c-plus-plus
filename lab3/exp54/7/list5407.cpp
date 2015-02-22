/** 
 * enhancing program to allow comment
 * markers anywhere
 *
 */

#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>

int main()
{
  // initialize variables
  double prev_odometer(0.0), odometer(0.0);
  double total_fuel(0.0);

  std::string line;
  int linenum(0);
  bool error(false);

  // gather input
  while (std::getline(std::cin, line)) {
    
    ++linenum;
    std::string::size_type comment(line.find('#'));

    if (comment != std::string::npos) 
      line.erase(comment);
    std::istringstream input(line);
    double fuel;
    

    if (input >> odometer) {

      // throw error is missing input
      if (not (input >> fuel)) {
	std::cerr << "No fuel consumption" << linenum << '\n';
	error = true;
      }

      // make computations
      else if (fuel != 0) {
	double distance(odometer - prev_odometer);
	std::cout << distance / fuel << '\n';
	total_fuel += fuel;
	prev_odometer = odometer;
      }
    }
  }

  // print computations
  if (total_fuel != 0) {
    std::cout << "You miles per gallon are:" << odometer / total_fuel;

    // print message with error
    if (error) {
      std::cout << " (estimated, due to input error)";
      std::cout << '\n';
    }
  }
}
