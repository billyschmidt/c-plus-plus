/**
 * writing the prgoram
 * using the miles per gallon approach
 */

#include <iostream>
#include <istream>
#include <ostream>

int main()
{
  // initialize variables
  double fuel;
  double odometer;
  double prev_odometer(0.0);
  double total_fuel(0.0);

  // gather input
  while (std::cin >> odometer >> fuel) {
    
    // make computations
    if (fuel != 0) {

      double distance(odometer - prev_odometer);

      std::cout << distance / fuel << '\n';

      total_fuel += fuel;

      prev_odometer = odometer;
    }
  }
  
  // print message
  if (total_fuel != 0) {

    std::cout << "Your Miles per gallon are: " << odometer / total_fuel << '\n';
  }  
}
