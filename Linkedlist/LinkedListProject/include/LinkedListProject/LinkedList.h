#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct node{
  int val;
  node* next;
};

class linkedlist{
private:
  node* head;
  node* tail;
  int size_;

public:
  linkedlist();
  void add_list(int value);
  void print();
  void delete_by_pos();
  void delete_by_val();
  void swap(int a , int b);
  void swap_half();
  void reverse();
};

#endif
