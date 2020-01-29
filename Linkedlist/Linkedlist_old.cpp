#include <iostream>
#include  <stdio.h>
#include <vector>
#include <memory>

using namespace std;

struct node{
  int val;
  node* next;
};

class linkedlist{
private:
  node* head;
  node* tail;

public:
  linkedlist();
  void add (int val);
  node* create_node(int val);
  void print();
  void reverse();
  void delete_val(int val);
};

linkedlist::linkedlist() {
  head = nullptr;
  tail = nullptr;
}

node* linkedlist::create_node(int val){
  node* temp = new node;
  temp->val = val;
  temp->next = nullptr;
  return temp;
}

void linkedlist::add(int val){
  node* new_node = create_node(val);
  if(!head){
    head = new_node;
    tail = head;
  }
  else{
    tail->next = new_node;
    tail = tail->next;
  }
}

void linkedlist::reverse(){
  node* cur = head;
  node* post = head;
  node* prev = nullptr;

  if(!head->next)
    return;
  else{
    tail = head;
    while(cur){
      post = cur->next;
      cur->next = prev;
      prev = cur;
      cur = post;
    }
    head = prev;
  }

  cout<<"List reversed: ";
  this->print();
}

void linkedlist::delete_val(int val){

  while(head && (head->val==val))
    head = head->next;

  if(!head)
    return;

  node* ptr = head->next;
  node* prev = head;
  while(ptr){

    if(ptr->val == val)
      prev->next = ptr->next;
    else
      prev = ptr;

    ptr = ptr->next;
  }

  cout<<"List after deletion: ";
  this->print();
}

void linkedlist::print(){
  node* ptr = head;
  while(ptr){
    cout<<ptr->val<<" ";
    ptr=ptr->next;
  }
  cout<<endl;
}


int main(){

  //unique_ptr<linkedlist> list = make_unique<linkedlist>();
  unique_ptr<linkedlist> list (new linkedlist);

  //linkedlist list;

  vector<int> seq = {1,2,3,4,5,6,7,8,9,10};

  for(auto val: seq)
    list->add(val);

  cout<<"Initial list: ";
  list->print();

  list->reverse();
  list->reverse();

  list->delete_val(10);


  return 0;
}
