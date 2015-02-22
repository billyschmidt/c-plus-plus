/**
 * Bill Schmidt
 * 4159697
 *
 * driver for string_set class
 *
 */


#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <list>
#include <string>
#include <locale>

#include "string_set.hpp"

int main()
{
  // declare a single string_set of table size 1000
  string_set S(1000);
  
  //
  // then read in strings (i.e. words) from the first file and put them in S
  //
  
  std::ifstream fin("first.txt");
  
  if (not fin)
	{
	  std::perror("first.txt");
	}
  
  else
	{
	  std::string word;
	  
	  while (fin >> word)
		{
		  S.insert(word);
		}

	  fin.close();
	}
  
  //
  // then read in strings (i.e. words) from the second file and take those out of S.
  //
  
  std::ifstream sin("second.txt");
  
  if (not sin)
	{
	  std::perror("second.txt");
	}
  
  else
	{
	  std::string word;
	  
	  while (sin >> word)
		{
		  S.remove(word);
		}
	  
	  sin.close();
	}
  
  // output the words in S to standard output (i.e. std::cout).
  std::cout << (std::string)S;

  return 0;	
}
