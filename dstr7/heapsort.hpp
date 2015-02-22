/**
 * Bill Schmidt
 * 4159697
 *
 * heapsort implementation
 *
 */

#include <algorithm>

/***********************
 *** INLINE FUNCTIONS
 ***********************/
inline int left(int i)      { return i << 1; }
inline int right(int i)     { return i << 1 | 1; }
inline int parent(int i)    { return i >> 1; }



/***********************
 *** HEAPSORT
 ***********************/
template<typename T>
	void heapsort(T* array, int n)
{
	// index from 1 to n
	--array;
	
	// build the heap
	buildheap(array, n);
  	
	// loop through, swap elements, heapify

	for (int i(n);i>=2;i--)	
		//	int i (n);
		//while (i >= 2)
		{
		std::swap(array[1], array[i]);
		//i--;
		
		heapify(array, 1, i);
		}
}



/***********************
 *** BUILDHEAP
 ***********************/
template<typename T>
	void buildheap(T* array, int n)
{
	// loop through array and heapify each parent	
  	for (int i(n/2); i >= 1; i--)
		{   
 		heapify(array, i, n);
		}
}



/***********************
 *** HEAPIFY
 ***********************/
template<typename T>
	void heapify(T* array, int k, int heapsize)
{
	int pos = k;
	
	//only treat child as object if it's inside heap
	if (left(k) <= heapsize and array[left(k)] < array[pos]) 
		{
		// update variables
		pos = left(k);
		}
  
	// identical for right
	if (right(k) <= heapsize and array[right(k)] < array[pos]) 
		{
		// update variables
		pos = right(k);
		}
  
	// only need to do something if pos is NOT the same position
	// that we were passed in originally
	if (pos != k) 
		{
		// swap items
		std::swap(array[pos], array[k]);
		
		//array[k] = array[pos];
		//array[pos] = array[k];
		
		// go recursive to trickle down...
		heapify(array, pos, heapsize);
		}
}

