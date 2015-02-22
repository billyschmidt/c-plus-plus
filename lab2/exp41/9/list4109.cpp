// program that reads a vector of integers and replaces all
// occurences of values in the range [10, 20] with 0

#include <algorithm>
#include "data.hpp"
#include "intrange.hpp"

int main()
{
  // initialize vector
  intvector input;

  // read input into vector and write to std output
  read_data(input);
  write_data(input);

  // call replace_if to replace input in range with '0'
  std::replace_if(input.begin(), input.end(), intrange(10, 20), 0);

  // wirte to std output
  write_data(input);
}
