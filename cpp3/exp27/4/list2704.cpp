// Bill Schmidt
// 4159697
// add assign member function to struct

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <ostream>

// GCD function, takes two int args, returns the GCD
int gcd(int n, int m)
{
  n = abs(n);
  while (m != 0) {
    int tmp(n % m);
    n = m;
    m = tmp;
  }
  return n;
}

// struct representing a rational number
// assigns numerator and denominator, then reduces
struct rational
{
  void assign(int num, int den)
  {
    numerator = num;
    denominator = den;
    reduce();
  }

  void reduce()
  {
    assert(denominator != 0);
    int div(gcd(numerator, denominator));
    numerator = numerator / div;
    denominator = denominator / div;
  }

  int numerator;
  int denominator;
};

int main()
{
  // create test object
  rational test;
  rational test_2;

  // call assign on test with proper arguments
  test.assign(65465,1325);
  test_2.assign(1000, 5);

  // print info
  std::cout << "Test = " << test.numerator << "/" << test.denominator << '\n';
  std::cout << "Test_2 = " << test_2.numerator << "/" << test_2.denominator << '\n';
}
