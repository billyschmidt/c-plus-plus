#include <iomanip>
#include <iostream>
#include <ostream>

int main()
{
  using namespace std;
  
  int const low(1);        
  int const high(10);     
  int const colwidth(4); 
 
  cout << right;
  
  cout << setw(colwidth) << '*'
       << '|';
  for (int i(low); i <= high; i = i + 1)
    cout << setw(colwidth) << i;
  cout << '\n';
  
  cout << setfill('-')
       << setw(colwidth) << ""                 
       << '+'                                    
       << setw((high-low+1) * colwidth) << ""
       << '\n';
  
  cout << setfill(' ');
  
  for (int row(low); row <= high; row = row + 1)
    {
      cout << setw(colwidth) << row << '|';
      for (int col(low); col <= high; col = col + 1)
	cout << setw(colwidth) << row * col;
      cout << '\n';
    }
}
