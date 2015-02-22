
#include <istream>
#include <iostream>
#include "disjoint.hpp"
#include <iterator>
#include <list>
#include <sstream>

disjoint_sets::disjoint_sets(int n)
 :size(n)
{
  p = new int[n+1];
  rank = new int[n+1];
  set = new listptr[n+1];
	
  for (int j(1); j <= n+1; ++j)
	set[j] = new std::list<int>;
		
		
}

//need to do this
disjoint_sets::~disjoint_sets()
{}

//takes root node and an output stream
void disjoint_sets::print_set(std::ostream& out, int u)
{
  out << "{ ";
  for ( std::list<int>::iterator iter( (*set[u]).begin() ) ; iter != (*set[u]).end(); ++iter)
	out<< *iter << ", ";
  out<< "}";
}

//confused about implementation of this function wanted to use print set but seg fault was having none of it
//makes an array and runtime should be O(n) since it makes an array to check if values have been used so it only loops through list once;
disjoint_sets::operator std::string()
{
  int *test;
  test = new int[size+1];
  std::stringstream text;
  text << "{ ";
  //main loop through the array
  for (int i(1); i <= (size + 1); ++i )
	{
		
		
		
	  //if the root hasn't been used yet do this
	  if (test[find_set(i)] == 0  )
		{	//set to anything != 0
		  test[find_set(i)] = 15;
			
		  //make sure the list isn't empty	
		  if ( (*set[i]).empty() )
			text<<"";
		
		  else{
			
			text << "{ ";
			for ( std::list<int>::iterator iter( (*set[i]).begin() ) ; iter != (*set[i]).end(); ++iter)
			  text<< *iter << ", ";
		
		
			text<< "}, ";
			
		  }
		 
		}
	}

  text<<" }";
	
  delete[] test;
	
  return text.str();
}


bool disjoint_sets::make_set(int n)
{
  //if p[n] is in the list return false
  if (p[n] != 0)
	return false;
	
  else{
		
	p[n] = n;
	(*set[n]).push_front(n);
		
	return true;
  }
	
	
}


bool disjoint_sets::union_set(int u, int v)
{
	
  int x = find_set(u);
  int y = find_set(v);
	
  if (x == 0 or y == 0)
	return false;
	
  if (rank[x] < rank[y])
	{
		
	  //set lower parents root to bigger root and make the value of the root to contain the combined lists
	  //then get rid of the old pointer
	  p[x] = y;
	  (*set[y]).splice((*set[y]).end(), (*set[x]) );
		
		
	  return true;
	}
	
  else 
	{
	  //same as above
	  p[y] = x;
	  (*set[x]).splice( (*set[x]).end(), (*set[y]) );
	  //if they are the same increase the rank(height) by 1
	  if (rank[x] == rank[y])
		++rank[x];
	  return true;
	}
		
}
	

//some badass path compression returns the root;
int disjoint_sets::find_set(int u)
{
  if (u != p[u])
	p[u] = find_set(p[u]);
  return p[u];
}



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

