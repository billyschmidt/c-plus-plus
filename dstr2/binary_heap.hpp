
#include <string>

class priority_queue_overflow{};	//if insert tries to exceed the size of A then throw priority_queue_overflow() 
class priority_queue_underflow{};	//if extract_min tries is called on an empty heap then throw priority_queue_overflow() 

class priority_queue {
private:
	
  class pair {
  public:
    std::string object;
    double key;
  };
	
  pair* A;	//the array used to store the heap - a is dynamic array of type pair
  int heapsize;	//the current heap size
  int size;	//the current size of the array: does not change
	
  void heapify(int k);	//as described in Cormen et al
	
public:
	
  priority_queue(int n); //don't forget to allocate the array of size n+1 as we don't use slot zero
  ~priority_queue();	//delete the array
	
  bool empty();	//true/false depending upon whether the heap is empty
  void insert(std::string s, double priority); //add s to the heap with the given priority as its key
  std::string extract_min();	//remove the string of lowest key and return that string

  operator std::string();
};
