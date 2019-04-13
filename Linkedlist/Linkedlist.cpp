
#include <iostream>
#include<stdio.h>

using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class linked_list{
private:
    Node *head, *tail;
public:
    linked_list(){
        head = NULL;
        tail = NULL;
    }
    void create_node(int data);
    void print_list();
    void delete_position(int pos);
    void delete_by_node_value(int val);
    void reverse();
    
};

void linked_list::create_node(int data){
    Node *temp = new Node;
    temp -> data = data;
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

void linked_list::delete_position(int pos){
    Node *cur;
    Node *prev;
    cur =  head;
    prev = head;
    for(int i=1; i<pos;i++){
        prev = cur;
        cur = cur -> next;
    }
    cur = cur -> next;
    prev -> next = cur;
}

void linked_list::delete_by_node_value(int val){
    Node *cur;
    Node *prev;
    Node *temp;
    cur =  head;
    prev = head;
    temp = head;
    
    while( temp != NULL){
        if( temp->data == val){
            cur = cur -> next;
            prev -> next = cur;
        }
        else{
            prev = cur;
            cur = cur->next;
        }
        temp = temp -> next;
    }
}

void linked_list::reverse(){ 
    Node *cur = NULL;
    while(head){
        Node* temp = head -> next;
        head -> next = cur;
        cur = head;
        head = temp;
    }
}

void linked_list::print_list(){
    Node *temp;
    temp = head;
    while(temp != NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
}


int main(){
    linked_list list;
    
    for(int i=1; i<=10; i++){
        list.create_node(i);
    }
    //list.delete_position(10);
    //list.delete_by_node_value(7);
    //list.reverse();
    
    list.print_list();
    cout<<endl;
    return 0;
}
