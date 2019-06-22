#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

struct node{
  int key;
  node* left;
  node* right;
};

class binarytree{
private:
  node* root;
  int size;
  int max_d;
  void add_private(int val,node* ptr);
  void bfs_print_private(node* ptr);
  void dfs_print_private(node* ptr);
  void inorder_private(node* ptr);
  void preorder_private(node* ptr);
  void postorder_private(node* ptr);
  int tree_size_private(node* ptr);
  int maxdepth_private(node* ptr);

public:
  binarytree();
  void add(int x);
  void bfs_print();
  void dfs_print();
  void inorder();
  void preorder();
  void postorder();
  void tree_size();
  void maxdepth();

};




#endif
