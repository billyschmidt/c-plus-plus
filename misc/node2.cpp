#include <iostream>
#include <ostream>

template<typename T>
struct node {
  T val; //this was type int in class
  node* next;
  node(T v, node* np) : val(v), next(np) { /*empty*/ }
};

template<typename T>
void push(node<T>* & ls, T x) {
  ls = new node<T>(x, ls);
};

template<typename T>
void append(node<T>*& ls, T x) {
  node<T>* last = new node<T>(x, 0);
  if( ls == 0 ) {
    ls = last;
    return;
  }
  node<T>* curr(ls);
  while( curr->next != 0 ) 
    curr = curr->next;
  curr->next = last;
}

template<typename T>
T sum(node<T>* ls) {
  T total(0);
  node<T>* curr(ls);
  while( curr != 0 ) {
    total += curr->val;
    curr = curr->next;
  }
  return total;
}

template<typename T>
std::ostream& operator<< (std::ostream& out, node<T>* ls) {
  node<int>* curr(ls);
  while( curr != 0 ) {
    out << curr->val << std::endl;
    curr = curr->next;
  }
  return out;
}

template<typename T>
bool change(node<T>*& ls, T x, T y) {
  node<T>* curr(ls);
  while( curr != 0 and curr->val != x )
    curr = curr->next;
  if( curr == 0 ) return false;
  curr->val = y;
  return true;
}

template<typename T>
bool del(node<T>*& ls, T x) {
  node<T>* prev(0);
  node<T>* curr(ls);
  while( curr != 0 and curr->val != x ) {
    prev = curr;
    curr = curr->next;
  }
  if( curr == 0 ) return false;
  if( prev == 0 )  ls = curr->next;
  else prev->next = curr->next;
  delete curr;
  return true;
}

template<typename T>
T hd(node<T>* ls) { return ls->val; }

template<typename T>
node<T>* tl(node<T>* ls) { return ls->next; }

template<typename T>
node<T>* copy(node<T>* ls) {
  if( ls == 0 ) return 0;
  return new node<T>(ls->val, copy(ls->next) );
}

template<typename T>
node<T>* concat(node<T>* ls1, node<T>* ls2 ) {
  if( ls1 == 0 ) return copy(ls2);
  node<T>* curr = ls1 = copy(ls1);
  while( curr->next != 0 )
    curr = curr->next;
  curr->next = copy(ls2);
  return ls1;
}
