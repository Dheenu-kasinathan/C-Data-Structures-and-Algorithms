#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class listnode{
public:
  int val;
  listnode *next;
};

class linked_list{
private:
  listnode* head;
  listnode* tail;
  listnode* createnode();
public:
  linked_list();

  void addnode(int k);
  void printlist();
  void deletebyposition(int d);
  void deletebyvalue(int v);
  void reverselist();
};

#endif
