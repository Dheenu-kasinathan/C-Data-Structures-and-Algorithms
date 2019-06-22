#include "binarytree.h"

using namespace std;

binarytree::binarytree(){
  root  = NULL;
}

node* create_node(int val){
  node* temp = new node();
  temp->key = val;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

void binarytree::add(int val){
  if(root == NULL)
    root = create_node(val);
  else
    add_private(val, root);
}
void binarytree::add_private(int val, node* ptr){
  if (val < ptr->key ){
    if(ptr->left != NULL)
      add_private(val, ptr->left);
    else
      ptr->left = create_node(val);
  }
  else if (val > ptr->key ){
    if(ptr->right != NULL)
      add_private(val, ptr->right);
    else
      ptr->right = create_node(val);
  }
  else
    cout<<"Value already entered: "<<val<< endl;
}

void binarytree::bfs_print(){
  cout<<"BFS: ";
  bfs_print_private(root);
}
void binarytree::bfs_print_private(node* ptr){
  queue<node*> q;
  q.push(ptr);

  while (!q.empty()) {
    node* cur = q.front();
    cout<<cur->key<<" ";

    if(cur->left!= NULL)
      q.push(cur->left);
    if (cur->right != NULL)
      q.push(cur->right);

    q.pop();
  }
  cout<<endl;
}

void binarytree::dfs_print(){
  cout<<"DFS: ";
  dfs_print_private(root);
}
void binarytree::dfs_print_private(node* ptr){
  stack<node*> s;
  s.push(ptr);

  while (!s.empty()) {
    node* cur = s.top();
    cout<<cur->key<<" ";
    s.pop();

    if (cur->right != NULL)
      s.push(cur->right);
    if(cur->left!= NULL)
      s.push(cur->left);
  }
  cout<<endl;
}

void binarytree::inorder(){
  if(root == NULL)
    cout<<"tree is empty"<<endl;
  else{
    cout<<"Inorder traversal: ";
    inorder_private(root);
  }
  cout<<endl;
}
void binarytree::inorder_private(node* ptr){
  if(ptr->left != NULL){
    inorder_private(ptr->left);
  }
  cout<<ptr->key<<" ";
  if(ptr->right != NULL){
    inorder_private(ptr->right);
  }
}

void binarytree::preorder(){
  if(root == NULL)
    cout<<"tree is empty"<<endl;
  else{
    cout<<"Preorder traversal: ";
    preorder_private(root);
  }
  cout<<endl;
}
void binarytree::preorder_private(node* ptr){
  cout<<ptr->key<<" ";
  if(ptr->left != NULL){
    preorder_private(ptr->left);
  }
  if(ptr->right != NULL){
    preorder_private(ptr->right);
  }
}

void binarytree::postorder(){
  if(root == NULL)
    cout<<"tree is empty"<<endl;
  else{
    cout<<"postorder traversal: ";
    postorder_private(root);
  }
  cout<<endl;
}
void binarytree::postorder_private(node* ptr){
  if(ptr->left != NULL){
    postorder_private(ptr->left);
  }
  if(ptr->right != NULL){
    postorder_private(ptr->right);
  }
  cout<<ptr->key<<" ";
}

void binarytree::tree_size(){
  if(root == NULL)
    cout<< "Tree is empty"<<endl;
  else{
      size = tree_size_private(root);
      cout<<"Size of the tree is: "<<size<<endl;
    }
}
int binarytree::tree_size_private(node* ptr){
  if (ptr == NULL)
    return 0;
  else
    return tree_size_private(ptr->left) + 1 + tree_size_private(ptr->right);
}

void binarytree::maxdepth(){
  if(root == NULL)
    cout<<"Tree is empty"<<endl;
  else{
    max_d = maxdepth_private(root);
    cout<<"Max depth of the tree is: "<<max_d<<endl;
  }
}
int binarytree::maxdepth_private(node* ptr){
  if(ptr== NULL)
    return 0;
  else{
    int left = maxdepth_private(ptr->left);
    int right = maxdepth_private(ptr->right);
    return std::max(left,right)+1; //change min for min depth
  }
}
