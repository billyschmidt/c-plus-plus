/**
 * Bill Schmidt
 * 4159697
 *
 * string_set class implementation
 * 
 */


#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

#include "string_set.hpp"



/***************************
 * CONSTRUCTOR
 * allocates a table array of size n,
 * and initializes it to contain n pointers to n empty lists.
 ***************************/
string_set::string_set(int n)
{
  size = n; 
  	
  // initialize table to new pointer
  table = new ptr_to_list_of_strings[n];
	
  // loop through and create a list in each array index
  for (int i(0); i < n; i++)
	{
	  table[i] = new std::list<std::string>;
	}
}



/**************************
 * DESTRUCTOR
 * deletes the table array 
 ***************************/
string_set::~string_set()
{
  for (int i(0); i < size; i++)
	{
	  delete table[i];
	}
	
  delete[] table;
}



/**************************
 * INSERT
 * add the given string to the string_set if it is not already present. 
 * The boolean returned should indicate whether the string_set was modified.
 ***************************/
bool string_set::insert(std::string s)
{
  // if string already exists
  if (member(s))
	{
	  return false;
	}
	
  // otherwise string does not exist
  else
	{
	  // push string onto list at hashed table index
	  table[hash(s)]-> push_front(s);
	}
	
  return true;
}



/**************************
 * REMOVE
 * remove the given string from the string_set if it is present. 
 * The boolean returned should indicate whether the string_set was modified.
 ***************************/
bool string_set::remove(std::string s)
{
  // if string exists
  if (member(s))
	{
	  // remove the string from its hashed array index
	  table[hash(s)]-> remove(s);	  
		
	  return true;
	}
	
  return false;	
}



/**************************
 * MEMBER
 * return a boolean indicating whether the given string is present in the string_set. 
 ***************************/
bool string_set::member(std::string s)
{
  // store hash value in index varibale
  int index = hash(s);
	
  // initialize iter for looping
  std::list<std::string>::iterator iter;
	
  ptr_to_list_of_strings elm = table[index];
	
  // loop through table array
  for (iter = elm-> begin(); iter != elm-> end(); iter++)
	{
	  // if equal string found
	  if ((*iter) == s)
		{
		  return true;
		}
	}
	
  return false;	
}



/**************************
 * COMPARE NOCASE
 * return a boolean indicating the string precedence 
 ***************************/
bool compare_nocase(std::string first, std::string second)
{
  unsigned int i = 0;
  
  while ((i < first.length()) and (i < second.length()))
	{
	  if (tolower(first[i]) < tolower(second[i])) 
		{
		  return true;
		}
	  
	  else if (tolower(first[i]) > tolower(second[i])) 
		{ 
		  return false;
		}
	  
	  ++i;
	}
  
  if (first.length() < second.length()) 
	{
	  return true;
	}
  
  else 
	{
	  return false;
	}
}



/**************************
 * CONVERSION TO STRING
 * produce a string consisting of the strings in your string_set in no particular order
 * concatenated together, each followed by a newline. The empty set should produce just a newline.
 ***************************/
string_set::operator std::string() 
{
  // initialize stringstream variable
  std::stringstream text;
  
  bool has_at_least_one_word = false;
  std::list<std::string>* sorted_list =	new	std::list<std::string>;
  
  // loop through array
  for (int i(0); i < size; i++)
	{
	  ptr_to_list_of_strings elm = table[i];	  

	  if (elm-> empty() == false)
		{
		  sorted_list-> insert(sorted_list-> end(), elm-> begin(), elm-> end());
		  has_at_least_one_word = true;
		}
	}
	
  // if bool indicates we have empty set, use newline
  if (has_at_least_one_word == false)
	{
	  text << '\n';
	}
  else
	{
	  sorted_list-> sort(compare_nocase);

	  // loop through table
	  for (std::list<std::string>::iterator iter = sorted_list-> begin(); iter != sorted_list-> end(); iter++)
		{
		  // load strings into stringstream
		  text << *iter << '\n';
		}
	}
	
  delete sorted_list;
	
  return text.str();
}



/**************************
 * HASH FUNCTION
 ***************************/
int string_set::hash(std::string s)
{
  using namespace std;
	
  locale loc;
	
  const collate<char>& coll = use_facet<collate<char> > (loc);
	
  unsigned long hash_num = coll.hash(s.data(), s.data() + s.length());
	
  return hash_num % size;
}
