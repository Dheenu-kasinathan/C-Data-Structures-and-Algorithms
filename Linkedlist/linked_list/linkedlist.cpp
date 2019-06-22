#include "linkedlist.h"

using namespace std;

linked_list::linked_list(){
  head = NULL;
  tail = NULL;
}

listnode* linked_list::createnode(){
  listnode* node = new listnode();
  return node;
}

void linked_list::addnode(int k){
  listnode* temp = linked_list::createnode();
  //listnode* temp = new listnode();
  temp -> val = k;
  temp -> next = NULL;
  if(head == NULL){
    head = temp;
    tail = temp;
  }
  else{
    tail -> next = temp;
    tail = temp;
  }
}

void linked_list::deletebyposition(int d){
  listnode* prev = head;
  //listnode* temp = head;
  if(d == 1){
    prev -> val = prev->next->val;
    prev -> next = prev->next->next;
  }
  else{
    for(int i = 1; i < d-1; i++){
      prev = prev->next;
    }
    //temp = prev->next;
    prev->next = prev->next->next;
  }
  //delete temp;
}

void linked_list::deletebyvalue(int v){
  listnode* prev = head;
  listnode* temp = head;

  while(temp){
    if(temp ->val == v){
      temp->val = temp->next->val;
      temp->next= temp->next->next;
      break;
    }
    else if(temp->next->val == v){
      temp -> next = temp ->next->next;
      break;
    }
    else
      temp = temp->next;
  }
}

void linked_list::reverselist(){
  listnode* cur = head;
  listnode* post = head;
  listnode* prev = NULL;
  if(head->next != NULL){
    while(cur){
      post = cur->next;
      cur->next = prev;
      prev = cur;
      cur = post;
    }
    head = prev;
  }
}

void linked_list::printlist(){
  listnode* temp = head;
  while(temp){
    cout<< temp -> val;
    temp= temp->next;
    if(temp)
      cout<<" -> ";
  }
}
