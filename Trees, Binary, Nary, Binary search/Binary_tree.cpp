#include <iostream>
#include <stdio.h>
#include <vector>
#include <memory>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;

struct node{
  int val;
  node* left;
  node* right;
};

class binarytree{
private:
  node* root;
  void addnode_rec_private(int val, node* ptr);
  node* create_node(int val);

public:
  static int minDepth;
  static int maxDepth;

  binarytree();
  ~binarytree();
  void addnode_rec(int val);
  vector<vector<int>> levelorder();
  vector<int> inorder();
  vector<int> preorder();
  vector<int> postorder();
  bool validate_tree();
  bool findelemet(int val);
  void getMinMaxDepth();
  void invert();
  void delete(int val);
  node* minValueNode(node* ptr);
};
int binarytree::minDepth = 0;
int binarytree::maxDepth = 0;

binarytree::binarytree() : root(nullptr){ cout<<"Tree is created"<<endl; }
binarytree::~binarytree() { cout<<"Tree is destroyed "<<endl;  }

node* binarytree::create_node(int val){
  node* temp = new node;
  temp->val = val;
  temp->left = nullptr;
  temp->right = nullptr;
  return temp;
}

void binarytree::addnode_rec(int val){
  addnode_rec_private(val, root);
}

void binarytree::addnode_rec_private(int val, node* ptr){

  if(root == nullptr){
    root = create_node(val);
  }
  else{
    if(val < ptr->val){
      if(!ptr->left)
        ptr->left = create_node(val);
      else
        addnode_rec_private(val, ptr->left);
    }
    else{
      if(!ptr->right)
        ptr->right = create_node(val);
      else
        addnode_rec_private(val, ptr->right);
    }
  }

}

vector<vector<int>> binarytree::levelorder(){

  vector<vector<int>> level_order;

  if(!root){
    return level_order;
  }

  queue<node*> q;
  q.push(root);

  bool depth = true;

  while(!q.empty()){
    int s = q.size();
    maxDepth++; //only for find the min and max depth
    vector<int> row = {};
    for(int i = 0 ; i< s; i++){
      node* temp = q.front();
      q.pop();
      row.push_back(temp->val);
      if(temp->left)
        q.push(temp->left);
      if(temp->right)
        q.push(temp->right);

      if((!temp->left) && (!temp->right) && (depth)){ //only for find the min and max depth
        minDepth = maxDepth;             //only for find the min and max depth
        depth = false;
      }
    }
    level_order.push_back(row);
  }

  return level_order;
}

vector<int> binarytree::inorder(){
  vector<int> inorder;

  if(!root)
    return inorder;

  stack<node*> st;
  node* ptr = root;

  while(!st.empty() || ptr){

    while(ptr){
      st.push(ptr);
      ptr = ptr->left;
    }
    ptr = st.top();
    st.pop();
    inorder.push_back(ptr->val);
    ptr = ptr->right;
  }

  return inorder;
}

vector<int> binarytree::preorder(){
  vector<int> preorder;

  if(!root)
    return preorder;

  stack<node*> st;
  st.push(root);

  while(!st.empty()){

    node* temp = st.top();
    st.pop();

    preorder.push_back(temp->val);

    if(temp->right)
      st.push(temp->right);
    if(temp->left)
      st.push(temp->left);

  }

  return preorder;
}

vector<int> binarytree::postorder(){
  vector<int> postorder;

  if(!root)
    return postorder;

  stack<node*> st;
  st.push(root);

  while(!st.empty()){

    node* temp = st.top();
    st.pop();

    postorder.push_back(temp->val);

    if(temp->left)
      st.push(temp->left);
    if(temp->right)
      st.push(temp->right);

  }
  reverse(postorder.begin(), postorder.end());

  return postorder;
}

bool binarytree::validate_tree(){

  if(!root)
    return false;

  stack<node*> st;
  node* ptr = root;

  int node_p = INT_MIN;
  while(!st.empty() || ptr){

    while(ptr){
      st.push(ptr);
      ptr = ptr->left;
    }
    ptr = st.top();
    st.pop();
    if(node_p >= ptr->val)
      return false;
    node_p = ptr->val;
    ptr = ptr->right;
  }

  return true;
}

bool binarytree::findelemet(int val){
  node* ptr = root;

  while(ptr){
    if(ptr->val == val)
      return true;
    else if(ptr->val > val)
      ptr = ptr->left;
    else if(ptr->val < val)
      ptr = ptr->right;
  }

  return false;
}

void binarytree::getMinMaxDepth(){
  cout<<minDepth<<" "<<maxDepth<<endl;
}

void binarytree::invert(){

  if(!root)
    return ;

  queue<node*> q;
  q.push(root);

  while(!q.empty()){
    int s = q.size();

    for(int i =0 ;i< s; i++){
      node* temp = q.front();
      q.pop();
      if(temp->left)
        q.push(temp->left);
      if(temp->right)
        q.push(temp->right);
      swap(temp->left, temp->right);
    }
  }
}

node* minValueNode(node* ptr){

  node* temp = ptr;

  if(temp && temp->left)
    temp = temp->left;

  return temp;
}
//need to complete
void binarytree::delete(int val){

  if(!root)
    return root;

  node* ptr = root;


}

int main(){

  unique_ptr<binarytree> tree = make_unique<binarytree>();

  vector<int> seq = {8,3,11,1,5,9,15};

  for(auto val: seq)
    tree->addnode_rec(val);

  vector<vector<int>> level = tree->levelorder();

  cout<<"Level order: ";
  for(auto row: level){
    cout<<"[ ";
    for(auto val: row)
      cout<<val<<" ";
    cout<<"] ";
  }
  cout<<endl;

  vector<int> inorder = tree->inorder();
  cout<<"Inorder  : [ ";
  for(auto val: inorder)
    cout<<val<<" ";
  cout<<" ] "<<endl;

  vector<int> preorder = tree->preorder();
  cout<<"Preorder : [ ";
  for(auto val: preorder)
    cout<<val<<" ";
  cout<<" ] "<<endl;

  vector<int> postorder = tree->postorder();
  cout<<"Postorder: [ ";
  for(auto val: postorder)
    cout<<val<<" ";
  cout<<" ] "<<endl;

  int bst = tree->validate_tree();
  if(bst)
    cout<<"The given sequence is a binary tree"<<endl;
  else
    cout<<"the given sequence is not a binary tree"<<endl;

  int find_val = 9;
  cout<<"Element " <<(tree->findelemet(find_val) ? "found" : "not found") << endl;

  cout<<"Min depth and Max Depth: ";
  tree->getMinMaxDepth();

  int del_val = 5;
  tree->delete(delete_val);

  tree->invert();
  vector<vector<int>> inverted = tree->levelorder();
  cout<<"Inverted tree: ";
  for(auto row: inverted){
    cout<<"[ ";
    for(auto val: row)
      cout<<val<<" ";
    cout<<"] ";
  }
  cout<<endl;

  return 0;
}
