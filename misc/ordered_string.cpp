class ordered string list
{
 private:

  class node 
  {
  public:
    node(std::string s, node* p, node* n)
      : val(s), prev(p), next(n) {}

    std::string val;
    node *prev;
    node *next;
  };

  int count;
  node* first;
  node* last;

  node* find(std::string s) const;

  // use >= for membership testing, inserting, and removal

 public:

  ordered_string_list()
    : count(0), first(0), last(0) {}

  int size();
  void insert();
  void remove();
  void member();
  operator std::string();
};
    
// find main
np = ls.find("8");

//find
node* find(string x)
{
  node* curr(first);
  while (curr !=0 and curr -> val < x) // list not null, and haven not exceeded thing were tring to insert
    curr = curr -> next; // move along
  return curr;
  
  // returns null if string searching for is bigger, or if list is empty
  
  // membership function can be written in like two lines, testing if equal, then true, else false
}


void remove(std::string s)
{
  if (first->next == 0 and first->val == s) { // if only item in list needs to be removed
    curr->prev = 0;
    curr->next = 0;


  if (first==find(s)) { // first item in list needs to be removed
    
  }

  if (last==find(s)) {  // need to remove last item in list
    
  }
  
  
  curr -> prev -> next = curr -> next;
  curr->next->prev = curr -> prev;
  
  
ordered_string_list::operator std::string() 
{
  std::stringstream text;
  node* curr(first);
    
  while (curr !=0) {
    text << curr -> val << std::endl;
    curr = curr -> next;
  }
  return text.str();
}
