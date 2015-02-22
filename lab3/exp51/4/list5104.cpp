/*
 * Bill Schmidt
 * 4159697
 * program testing erase_less with both list and vector,
 * as well as ascending, descending, and mixed data
 *
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <istream>
#include <iterator>
#include <list>
#include <ostream>
#include <sstream>
#include <vector>

#include "erase_less.hpp"

// extract items from a string and store them in a container
template<class Container>
void read(std::string const& str, Container& cont)
{
  std::istringstream in(str);
  cont.insert(cont.begin(),
              std::istream_iterator<typename Container::value_type>(in),
              std::istream_iterator<typename Container::value_type>());
}

// print items from a container to the standard output
template<class Container>
void print(std::string const& label, Container const& cont)
{
  std::cout << label;
  std::copy(cont.begin(), cont.end(),
            std::ostream_iterator<typename Container::value_type>(std::cout, " "));
  std::cout << '\n';
}

// test erase_less by extracting integers from a string into a container
// and calling erase_less. print the container before and after
// double-check that the same results obtain with a list and a vector
void test(std::string const& str)
{
  std::list<int> list;
  read(str, list);
  print("before: ", list);
  erase_less(list);
  print("after:  ", list);

  std::vector<int> vector;
  read(str, vector);
  erase_less(vector);

  assert(list.size() == vector.size());
  assert(std::equal(list.begin(), list.end(), vector.begin()));
}

int main()
{
  test("1 7 30 49 59 64 72 81 90");
  test("9 8 7 6 5 4 3 2 1");
  test("");
  test("36");
  test("123 256 234 326 435");
}
