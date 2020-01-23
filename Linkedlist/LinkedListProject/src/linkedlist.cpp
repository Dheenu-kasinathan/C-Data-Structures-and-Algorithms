#include <LinkedListProject/LinkedList.h>

using namespace std;

linkedlist::linkedlist() : head(NULL), tail(NULL), size_(0){}

void linkedlist::add_list(int value) {
  node* temp = new node();
  temp->val = value;
  temp->next = NULL;

  size_++;

  if(head == NULL){
    head = temp;
    tail = temp;
  }
  else{
    tail->next = temp;
    tail = tail->next;
  }
}

void linkedlist::swap_half(){

  //method 1: using the size
  node* p = head;
  int mid = size_/2;

  for(int i = 1; i < mid; i++)
    p = p->next;

  tail->next =  head;
  head = p->next;
  tail = p;
  p->next = NULL;
}

void linkedlist::reverse(){
  node* cur = head;
  node* post = head;
  node* prev = NULL;

  if(head->next){ //checks for one element in loop

    while(cur){
      post = cur->next;
      cur->next = prev;
      prev = cur;
      cur = post;
    }
    
    head = prev;
  }
}

void linkedlist::print(){
  node* ptr = head;

  cout<<"size of linkedlist: "<<size_<<endl;

  while(ptr){
    cout<<ptr->val<<"->";
    ptr=ptr->next;
  }
  cout<<"NULL"<<endl;
}
