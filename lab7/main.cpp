/**
 * Bill Schmidt
 * 4159697
 *
 * driver for ordered_set class
 *
 */


#include <iostream>

#include "ordered_set.hpp"


int main()
{
	ordered_set os; 

	double x;	
	int count(0);
	
	// read from cin and call insert on ordered_set object
	while (std::cin >> x)
		{
		os.insert(x);
		}
	
	// sort vector
	std::vector<double>* myvec = os.sort();
	
	// print ten per line, separated by tab
	for (std::vector<double>::iterator iter = myvec->begin(); iter != myvec->end(); iter++)
		{
		std::cout << *iter << '\t';
		count++;
		
		if (count == 10)
			{
			std::cout << '\n';
			count = 0;
			}
		}
	
	// ending newline
	std::cout << '\n';
	
	delete myvec;

}
