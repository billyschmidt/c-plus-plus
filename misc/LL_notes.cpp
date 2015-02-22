struct node 
{ 
  int val; 
  node* next; 
    
  // constructor
  node(int v, node* l)
    :val(v), next(l) //can do typedef node* list 
  {} 
}; 

// append to end 
void append(node* & l, int x) 
{ 
  if (l == 0) { //use nullptr if it works 

    l = new node(x,0); 
    return; 
  } 

  node* curr(l); 
  while (curr -> next != 0) 
    curr = curr -> next; 
  curr -> next = new node(x,0); 
} 

//add to front 
void push(int x, node*& l) 
{ 
  l = new node(x,l); 
} 

int main() 
{ 
  node* ls(0); 
  append(ls,2); 
  push(1,ls); 
}

