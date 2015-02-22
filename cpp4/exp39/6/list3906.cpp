// rewrite of main to include "generate_id.hpp"
#include <iostream>
#include <ostream>
#include "generate_id.hpp"

short generate_id::prefix_(1);
long const generate_id::max_counter_;

long generate_id::next()
{
  if (counter_ == max_counter_)
    counter_ = 0;
  else
    ++counter_;
  return prefix_ * (max_counter_ + 1) + counter_;
}

int main()
{
  generate_id gen;
  for (int i = 0; i != 100; ++i)
    std::cout << gen.next() << '\n';
}
