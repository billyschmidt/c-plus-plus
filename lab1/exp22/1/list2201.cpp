#include <algorithm>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

// int as param, print param to cout
void print(int i)
{
  cout << i;
}

// two ints as params, print first to cout, second as field width
void print(int i, int width)
{
  cout << i;
  cout.width(width);
}

// vector<int> as forst param, then three string params
// print first string, then each elem of vector
void print(vector<int> const& vec, int width, string const& pre, string const& sep, string const& post)
{
  bool print_pre(true);
  for (vector<int>::const_iterator v(vec.begin()); v != vec.end(); ++v)
    {
      if (print_pre)
	cout << pre;
      else
	cout << sep;
      print_pre = false;
      cout.width(width);
      cout << *v;
    }
  if (print_pre)
    cout << pre;
  cout << post;
}

// same params as vecotr form, and also takes int as field width for each element
void print(vector<int> const& vec, string const& pre, string const& sep, string const& post)
{
  print(vec, 0, pre, sep, post);
}


// main func to tie it all together
int main()
{
  vector<int> input;
  // call insert
  input.insert(input.begin(), istream_iterator<int>(cin), istream_iterator<int>());

  //output data
  cout << "column input:\n";
  print(input, 10, "", "", "\n");
  cout << "row input:\n";
  print(input, "{", ", ", "}\n");
}
