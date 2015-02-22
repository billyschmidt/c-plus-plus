
#include<iostream>

#include "disjoint.hpp"


int main() {
  using namespace std;

  disjoint_sets ds(12);

  for( int i=1; i <= 10; ++i)
    ds.make_set(i);

  ds.union_set(1,2);
  ds.union_set(2,4);
  ds.union_set(1,8);
  ds.union_set(3,6);
  ds.union_set(2,10);

  //{ { 1, 2, 4, 8, 10, }, { 3, 6, }, { 5, }, { 7, }, { 9, }, }
  cout << string(ds) << endl;
}
