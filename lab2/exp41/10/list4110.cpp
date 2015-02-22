// using sequence.hpp, generate a vector of 100 sequential
//  integers then shuffle it into random order and print it

#include <algorithm>
#include "data.hpp"
#include "sequence.hpp"

int main()
{
  // initialize vector to 100 zeros
  intvector input(100);

  // generate with sequence call from header file
  std::generate(input.begin(), input.end(), sequence(1, 1));

  // write to std output
  write_data(input);

  // use shuffle algorithm across entire vector
  std::random_shuffle(input.begin(), input.end());

  // write to std output
  write_data(input);
}
