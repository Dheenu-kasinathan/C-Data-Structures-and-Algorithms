#include "binarytree.h"

using namespace std;

int main(){

  binarytree tree;
  int n[14] = {50,35,65,25,45,55,75,20,30,40,60,70,80,100};

  for(int i =0; i< 14; i++){
    tree.add(n[i]);
  }

  tree.bfs_print();
  tree.dfs_print();
  tree.inorder();
  tree.preorder();
  tree.postorder();

  tree.tree_size();
  tree.maxdepth();

  return 0;
}
