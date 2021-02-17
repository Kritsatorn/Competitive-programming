#include <iostream>

using namespace std;

typedef int valueType;

struct ListNode
{
  valueType val;
  ListNode* next;

  ListNode(valueType val, ListNode* next=0)
    : val(val), next(next) {}
};

class LinkedList
{
private:
  ListNode* header;
  ListNode* tail;
  void free_list();

public:
  LinkedList();
  ~LinkedList();
  void print_list();
  void insert_front(valueType x);
  void append(valueType x);
};

LinkedList::LinkedList()
{
  header = new ListNode(0);
  tail = header;
}

LinkedList::~LinkedList()
{
  free_list();
}

void LinkedList::append(valueType x) {
    ListNode* n = new ListNode(x);
    tail ->next = n ;
    tail = n ;
  return ;
}
void LinkedList::insert_front(valueType x) {
  ListNode* n = new ListNode(x);
  ListNode* tmp = header-> next;
  if ( header->next == NULL )tail = n ;
  header ->next = n;
  n -> next = tmp ;
  return ;
}
void LinkedList::free_list() {
      while (header ->next != '\0'){
    header = header-> next ;
    delete header;
  }
  return ;
}
void LinkedList::print_list()
{
  ListNode* node = header->next;
  while(node != 0) {
    cout << node->val << endl;
    node = node->next;
  }
}
main()
{
  LinkedList list;
  int t;

  cin >> t;
  for(int i = 0; i < t; i++) {
    int dir, val;
    cin >> dir >> val;
    if(dir == 1) {
      list.insert_front(val);
    } else {
      list.append(val);
    }
  }
  list.print_list();
}