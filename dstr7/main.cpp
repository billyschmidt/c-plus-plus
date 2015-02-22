/**
 * Bill Schmidt
 * 4159697
 *
 * heapsort driver
 *
 */


#include <iostream>

#include "heapsort.hpp"


int main()
{
	// initialize variable for storing array size
	int size, num;	

	// get first token, which is the size of the array
	std::cin >> size;
	
	// dynamically allocate new integer array
	int* arr = new int[size];

	//
	// get input form std::cin
	//	

	int i(0);
	
	while (std::cin >> num and i < size)
		{
		arr[i] = num;
		i++;
		}	
	
	//
	// sort the array using heapsort
	//
	heapsort(arr, size);
		
	//
	// loop through and output to std::cout
	//
	for (int i(0); i < size; i++)
		{
		std::cout << arr[i] << std::endl;
		}
}
