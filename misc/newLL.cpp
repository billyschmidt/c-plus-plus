template <typename T>
struct Listnode
{
  T value;
  Listnode *next;

  Listnode(Listnode* list, T val)
    : next(NULL), value(val)
  {}
};

struct List
{
  ListNode *head;
  ListNode *tail;

  List()
    : head(NULL), tail(NULL)
  {}
};
