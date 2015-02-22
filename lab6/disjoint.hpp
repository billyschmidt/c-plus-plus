/**
 * disjoint_sets class declaration
 *
 */

#include<ostream>
#include<string>
#include<list>

class disjoint_sets 
{
public:
  
  disjoint_sets(int n); //n is the maximum int that can be in a set, so arrays need to be of size n+1
  ~disjoint_sets();
  
  bool make_set(int n);
  int find_set(int u);
  bool union_set(int u, int v);
  void print_set(std::ostream& out, int u); //e.g. { 1, 2, 4, 8, 10, }

  operator std::string(); //e.g. "{ { 1, 2, 4, 8, 10, }, { 3, 6, }, { 5, }, { 7, }, { 9, }, }"

private:
  typedef std::list<int>* listptr;

  int* p;		//parent array
  int* rank;	//rank array
  listptr* set;	//array of pointers. Each set[i] is a pointer is to a list<int> containing the integers in the i'th set
  int size;		//the size i.e. maximum int that can be in a set

};
