#include <iostream>
#include <ostream>

template<typename T>
struct node 
{
  T val;
  node* next;

  node(T v, node* np)
    : val(v), next(np)
  {}
};
  

template<typename T>
void push(node<T>*& ls, T x) 
{
  ls = new node<T>(x, ls);
}


template<typename T>
void append(node<T>*& ls, T x) 
{
  node<T>* last = new node<T>(x, 0);
  if (ls == 0) {
    ls = last;
    return;
  }
  
  node<T>* curr(ls);
  while (curr -> next != 0)
    curr = curr -> next;
  curr -> next = last;
}

void delete(node<T>*& ls T x)
{
  while (curr->next != 0 and curr->val != x)
    curr = curr->next;
  
  node<T>* prev = 0;
  node<T>* curr = ls;  
  
  while (curr !=0 and curr->value != x) {
    prev = curr; // assign current to previous
    curr = curr -> next;
  }
  
  if (curr == 0) // list is empty
    return;
  
  if (prev == 0) { // deleting first item
    tmp = ls;
    ls = ls -> next;
    delete tmp;
  }
  
  // other cases
  prev -> next = curr -> next;
  delte curr;
}
  
  
class list {
    
public:
  void push(T x) {
    head = new node(x, head);
  }
  
  list()
    : head(0) 
  {}
  
  bool empty() 
  {
    return head == 0; 
  }
  
private:
  node<T>* head;
};

// emaple usage
list<int> L;
if (L.empty() { ... }
L.push(3);


// informally
pop()
  {
    tmp = ls;
    ls = ls -> next;
    
    return tmp -> val;
  }

// arrays
// array is pointer
// inside stack class, two private vars: num, A
class Stack
  {
    // constructor
    stack()
      : num(0)
    {
      A = new int[INIT]; // define init to const int
    }
    
    // destructor
    ~stack()
    {
      delete[] A;
    }
    
    // empty
    bool empty()
    {
      return num == 0;
    }
    
    // push
    //example calls:
    // stack s;
    //s.push(3)
    //s.push(5)
    void push(int x)
    {
      A[num] = x; // assign value given into slot
      ++num;  //increment value given
    }
    
    // sample call - i = s.pop()
    int pop()
    {
      --num; // reduce number
      return A[num]; // remove number
    }
  
  private:
    int* A;
    int num;
};

    // keep size of array
    // in constructor
    // size(INIT)
    // overflow?
    // if num == size, that means that the arrya is full

    if (num == size)
      {
	int* temp(A);
	A = new int[2 * size];
	size *= 2;
	
	for (int i=0, i < size; ++i)
	  A[i] = tmp[i];
	size *= 2;
	delete{} tmp;

