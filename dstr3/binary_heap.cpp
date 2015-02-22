/**
 * Bill Schmidt
 * 4159697
 * implementing the priority queue as a binary heap
 *
 */

#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <map>
#include <algorithm>

#include "binary_heap.hpp"

/***********************
 *** inline functions
 ***********************/
inline int left(int i) { return i << 1; }

inline int right(int i) { return i << 1 | 1; }

inline int parent(int i) { return i >> 1; }


/*********************
 *** constructor
 *********************/
priority_queue::priority_queue(int n)  
{
  heapsize = 0;
  size = n;

  // don't forget to allocate the array of size n+1 as we don't use slot zero 
  A = new pair[n+1];
}


/*************************************
 *** new constructor
 **************************************
 //
 // convert string_array into heap "in place"
 // use string_count param for not accessing memory out of bounds
 // n/2 looks at parent, then heapifies each parent (which handles the children)
 // swap min value from string array argument, with max of "heap"(end of array)
 // first element in array will always be the min in a min_heap

 // STRING CONVERSION: 
 // 1. pick largest (parent?)
 // 2. swap with last element in array
 // 3. re-establish heap propert (bubble/heapify/trickle)
 //
  
 // BUILDING THE HEAP:
 // set heapsize = string_count, loop through using the 1st parent node (n/2) as
 // loop variable, stopping when it equals 1(the root).
 // heapify each time through
 // decrement heapsize
 // 
 ***********************************************************************************/
priority_queue::priority_queue(int n, std::string* strs, int string_count)
{
  heapsize = string_count;
  size = n;
  A = new pair[n+1];
  
  for (int i(1); i <= string_count; i++)
	{
	  // copy string elements into new array
	  A[i].object = strs[i];
	  A[i].key = i;
	  string_to_pos[A[i].object] = i;
	}
  
  // building the heap
  for (int i(string_count/2); i >= 1; i--)
	{
	  heapify(i);
	}
}

/*************************************
 *** new constructor
 **************************************/
priority_queue::priority_queue(int n, std::string* strs, double* keys, int num)
{
  heapsize = num;
  size = n;
  A = new pair[n+1];
  
  for (int i(1); i <= num; i++)
	{
	  // copy string elements into new array
	  A[i].object = strs[i];
	  A[i].key = keys[i];
	  string_to_pos[A[i].object] = i;
	}
  
  // building the heap
  for (int i(num/2); i >= 1; i--)
	{
	  heapify(i);
	}
}


/*********************
 *** destructor
 *********************/
priority_queue::~priority_queue()  //delete the array
{
  delete[] A;
}


/*******************************************
 *** heapify min 
 *******************************************/
void priority_queue::heapify(int k)
{
  pair smallest = A[k];
  int pos = k;        
  
  //only treat child as object if it's inside heap
  if (left(k) <= heapsize and A[left(k)].key < A[pos].key) 
	{
	  // update variables
	  smallest = A[left(k)];
	  pos = left(k);
	}
  
  // identical for right
  if (right(k) <= heapsize and A[right(k)].key < A[pos].key) 
	{
	  // update variables
	  smallest = A[right(k)];
	  pos = right(k);
	}
  
  // after both if's exectued: smallest is pair with smallest key and
  // pos is index of that pair in A[]
  
  // only need to do something if pos is NOT the same position
  // that we were passed in originally
  if (pos != k) 
	{
	  // swap items
	  std::swap(A[k], A[pos]);
	  
	  //std::swap(string_to_pos[A[k].object], string_to_pos[A[pos].object]);
	  string_to_pos[A[k].object]		=	pos;
	  string_to_pos[A[pos].object]	=	k;
	  
	  // go recursive to trickle down...
	  heapify(pos);
	}
}


/****************
 *** empty
 ****************/
bool priority_queue::empty()
{
  return (heapsize == 0);
}

/*****************
 *** decrease_key
 *******************/
void priority_queue::decrease_key(int pos, double new_key)
{
  if (new_key > A[pos].key)
	{
	  throw "new key is greater than current key";
	}
  
  A[pos].key = new_key;

  while (pos > 1 and A[parent(pos)].key > A[pos].key)
	{
	  std::string parent_string	=	A[parent(pos)].object;
	  std::string pos_string	=	A[pos].object;
	  
	  std::swap(A[parent(pos)], A[pos]);
	  
	  //std::swap(string_to_pos[parent_string], string_to_pos[pos_string]);
	  
	  string_to_pos[parent_string]	=	pos;
	  string_to_pos[pos_string]		=	parent(pos);
	  
	  pos = parent(pos);
	}
}


/*****************
 *** bool decrease_key

Finally, implement the public decrease_key function mentioned far above. 

  Use the map to find the position of the string,
    and return false if it is not present in the heap.
  Otherwise use that position with a call of the private decrease_key function to effect the key change.

*******************/
bool priority_queue::decrease_key(std::string s, double new_key)
{
  // if the string does not exist
  if (string_to_pos.find(s) == string_to_pos.end())
	{
	  return false;
	}
  
  decrease_key(string_to_pos[s], new_key);
  return true;
}



/****************
 *** insert
 **	Now modify the member function insert so that it 
 **		first checks the map to see if the string to be inserted is already in the heap, 
 **			and if so, 
 **				simply decrease its key by calling the above decrease_key function 
 **					with the position given by the map and the key given to insert as the new key.
 **		
 ****************/
void priority_queue::insert(std::string s, double priority)  //add s to the heap with the given priority as its key
{
  if (heapsize == size) 
	{
	  throw priority_queue_overflow();
	}
  
  // if the string alrady exists
  if (string_to_pos.find(s) != string_to_pos.end())
	{
	  decrease_key(string_to_pos[s], priority);
	  
	}
  
  // make room for insert
  ++heapsize;  

  // assign string arg to object member
  A[heapsize].object = s;

  // assign priority arg to key member
  A[heapsize].key = priority;
  
  string_to_pos[s] = heapsize;
  
  // loop through and trickle up as needed
  int i(heapsize);
  while (i > 1 and A[parent(i)].key > A[i].key) 
	{
	  std::string parent_string	=	A[parent(i)].object;
	  std::string i_string		=	A[i].object;
	  
	  std::swap(A[parent(i)], A[i]);
	  
	  //std::swap(string_to_pos[parent_string], string_to_pos[i_string]);
	  
	  string_to_pos[parent_string]	=	i;
	  string_to_pos[i_string]			=	parent(i);
	  
	  i = parent(i);	
	}
}


/*******************
 *** extract_min
 *******************/
std::string priority_queue::extract_min()  //remove the string of lowest key and return that string
{
  if (heapsize == 0) 
	{
	  throw priority_queue_underflow();
	}
  
  std::string ans = A[1].object;
  A[1] = A[heapsize];
  string_to_pos[A[1].object] = 1;
  string_to_pos.erase(ans);
  
  --heapsize;
  
  // trickle down as needed
  heapify(1);
  return ans;        
}


/**********************************
 *** function operator overload
 **********************************/
priority_queue::operator std::string()
{
  std::stringstream text; 
  int i(1);    
  
  while (i <= heapsize) 
	{ 
	  text << i<< ". " << A[i].key << "=>"<< A[i].object << std::endl;
	  ++i;
	} 
  return text.str(); 
}
