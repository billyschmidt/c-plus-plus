/**
 * adding error checking to detect lines
 * with extra text
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
  double prev_odometer(0.0);
  double odometer(0.0);
  double total_fuel(0.0);

  std::string line;
  int linenum(0);
  bool error(false);

  // gather input, checking for extra text  
  while (std::getline(std::cin, line)) {
    ++linenum;
    std::string::size_type comment(line.find('#'));
    
    if (comment != std::string::npos)
      line.erase(comment);
    
    std::istringstream input(line);
    double fuel;
    
    if (input >> odometer) {
      char check;

      if (not (input >> fuel)) {
	std::cerr << "missing input" << linenum << '\n';
	error = true;
      }

      else if (input >> check) {
	std::cerr << "extra input!" << linenum << '\n';
	error = true;
      } 

      else if (fuel != 0) {
	double distance(odometer - prev_odometer);
	std::cout << distance / fuel << '\n';
	total_fuel += fuel;
	prev_odometer = odometer;
      }
    }
  }
  
  if (total_fuel != 0) {
    std::cout << "You miles per gallon are:" << odometer / total_fuel;
    
    if (error)
      std::cout << " *estimated becasue of error ";
    std::cout << '\n';
  }
}
