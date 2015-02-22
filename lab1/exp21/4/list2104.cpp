// Bill Schmidt
// 4159697

#include <algorithm>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <vector>

// returns largest int
int descending(int a, int b)
{
  return a > b;
}

int main()
{
  using namespace std;
  vector<int> input;

  // insert ints into vector
  input.insert(input.begin(), istream_iterator<int>(cin), istream_iterator<int>());

  // sort, then call descending function
  sort(input.begin(), input.end(), descending);

  // output using ostream_iterator
  copy(input.begin(), input.end(), ostream_iterator<int>(cout, "\n"));
}
