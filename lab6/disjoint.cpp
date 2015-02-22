/**
 * Bill Schmidt
 * 4159697
 *
 * disjoint_sets class implementation
 *
 */

#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include <list>

#include "disjoint.hpp"



/*********************
 * CONSTRUCTOR
 *********************/
disjoint_sets::disjoint_sets(int n)
{
	size = n;

	// initialize all arrays to same size (n+1)  
	p      =    new int[n+1];
	rank   =    new int[n+1];
	set    =    new listptr[n+1];
  
	// loop through set (array of pointers) and initialize
	//   each element to an empty list
	for (int i(1); i <= n; i++)
		{
		set[i] = new std::list<int>;
		}
}



/*********************
 * DESTRUCTOR
 *********************/
disjoint_sets::~disjoint_sets()
{
	delete[] p;
	delete[] rank;
  
	// delete each element in the set first, then delete the set.
	for(int i(1); i<=size; i++)
		{
		set[i]->clear();	
		}
	delete[] set;
}



/*********************
 * MAKE_SET
 *********************/
bool disjoint_sets::make_set(int n)
{
	// if parent already exists
	if (p[n] != 0)
		{
		return false;
		}

	// else we need to make a set	 
	else
		{
		// make itself the parent
		p[n] = n;

		// use push_front to add the int to front of set
		set[n]->push_front(n);
	  
		return true;
		}
}



/*********************
 * FIND_SET
 ***********************/
int disjoint_sets::find_set(int u)
{
	while (u != p[u])
		{
		u = p[u];
		}

	// returns parent  
	return u;
}



/*********************
 * UNION_SET
 *********************/
bool disjoint_sets::union_set(int u, int v)
{
	// assign parents to u, v
	u = find_set(u);
	v = find_set(v);
  
  
	// return false if parent is 0, list is empty
	if (u == 0 or v == 0)
		{
		return false;
		}
  
  
	// if u's height is less than v's (not in same set)
	if (rank[u] > rank[v])
		{
		// point u's parent to v (merge them)
		p[v] = u;
	  
		// splice u out
		(*set[v]).splice((*set[v]).end(), (*set[u]));

		// need to do the eqivalent of ths:
		//listptr	tmp = *set[u];
		//(*set[v]).splice((*set[v]).end(), tmp);
		//*set[u]=tmp;
		//
		// look into using either std::swap() or copy()
		//
		//	also do in other spot we call splice!
		//   when done, the second list should be changed!!!!
		//

		return true;
		}
  
	// u's height is greater than or equal to v's height  
	else
		{
		// set u's parent to v
		p[u] = v;
	  
		// splice v out
		(*set[u]).splice((*set[u]).end(), (*set[v]));

  
		// if ranks are equal
		if (rank[u] == rank[v])
			{
			// increment rank of v
			rank[v]++;
	  
			}
		return true;
		}
}




/*********************
 * PRINT_SET
 *********************/
void disjoint_sets::print_set(std::ostream& out, int u)
{
	if (set[u]-> empty() == false)
		{
		// begin brace for set
		out << "{ ";
	  
		// loop through with iter, seperate with comma
		for (std::list<int>::iterator iter((*set[u]).begin()); iter != (*set[u]).end(); iter++)
			{
			out << *iter << ", ";
			}
	  
		// end brace for set
		out << "}";
		}
}
  

/*********************
 * STRING CONVERSION

std::string disjoint_sets::OLD_operator_()
{
// sstream variable
  std::stringstream text; 

  
  // pointer to int array
  int *test;
  test = new int[size+1];


  // opening paren
  text << "{ ";

  
  // start main loop through the array
  for (int i(1); i <= (size + 1); i++)
	{

	// if the root is empty
	  if (test[find_set(i)] == 0)
		{
		  
		// set to anything != 0?
		  test[find_set(i)] = 10;
		  
		  
		  // check if list is empty
		  if (set[i]->empty())
			{
			  text << "";
			}
		  
		  
		  else
			{
			// individual set opening parenthesis
			  text << "{ ";
			  
			  // use iterator to loop through and load up the stringstream, separate w/ comma
			  for (std::list<int>::iterator iter((*set[i]).begin()); iter != (*set[i]).end(); iter++)
				{
				  text << *iter << ", ";
				}
			  
				// individual set closing parenthesis w/ proper punctuation
			  text << "}, ";	
			}
		}  
	}
  
	// closing parenthesis
  text << "}";	  

  delete[] test;  

  return text.str(); 
}
*********************/

 /*********************
  * STRING CONVERSION
  *********************/
	disjoint_sets::operator std::string()
{
	// sstream variable
	std::stringstream text; 

	// opening paren
	text << "{ ";

  
	// start main loop through the array
	for (int i(1); i <= size; i++)
		{
		print_set(text,i);
		}
  
	// closing parenthesis
	text << "}";	  

	return text.str(); 
}
