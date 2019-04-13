#include <iostream>
#include<queue>

using namespace std;
//-------------------------------------------------------------------------------------------
//tree structure
struct node{
    int key;
    node* left;
    node* right;
};
//------------------------------------------------------------------------------------------
//tree class
class binary_tree{
private:
    node* root;
    void add_node_pri(int key, node* ptr);
    void print_tree_inorder_pri(node* ptr);
    node* return_node_pri(int key, node* ptr);
    void breadth_first_search_pri(node* root);

public:
    binary_tree(){
        root = NULL;
    }
    
    node* create_node(int key);
    void add_node(int key);
    void print_tree_inorder();
    node* return_node(int key);
    void breadth_first_search();
    
};
//------------------------------------------------------------------------------------------
//create a node
node* binary_tree::create_node(int key){
    node *temp = new node;
    temp -> key = key;
    temp -> left = NULL;
    temp -> right = NULL;
    
    return temp;
}
//------------------------------------------------------------------------------------------
//insert a node
void binary_tree::add_node(int key){
    add_node_pri(key, root);
}
void binary_tree::add_node_pri(int key, node* ptr){
    
    if(root == NULL){
        root = create_node(key);
    }
    else if(key < ptr->key){
        if(ptr -> left != NULL){
            add_node_pri(key, ptr->left);
        }
        else{
            ptr->left = create_node(key);
        }
    }
    else if(key > ptr->key){
        if(ptr -> right != NULL){
            add_node_pri(key, ptr->right);
        }
        else{
            ptr->right = create_node(key);
        }
    }
    else{
        cout<<"the key "<<key<<"already addedtp the tree"<<endl;
    }
}
//------------------------------------------------------------------------------------------
//print inorder traversal
void binary_tree::print_tree_inorder(){
    print_tree_inorder_pri(root);
}
void binary_tree::print_tree_inorder_pri(node* ptr){
    if(root != NULL){
        if(ptr->left != NULL){
            print_tree_inorder_pri(ptr->left);
        }
        cout<< ptr->key <<" ";
        if(ptr->right != NULL){
            print_tree_inorder_pri(ptr->right);
        }
    }
    else{
        cout<< "tree is empty" <<endl;
    }
}
//------------------------------------------------------------------------------------------
//return node
node* binary_tree::return_node(int key){
    return return_node_pri(key, root);
}
node* binary_tree::return_node_pri(int key, node* ptr){
    if(ptr != NULL){
        if(ptr->key == key){
            return ptr;
        }
        else{
            if(key < ptr->key){
                return return_node_pri(key, ptr->left);
            }
            else{
                return return_node_pri(key, ptr->right);
            }
        }
    }
    else{
        return NULL;
    }
}
//------------------------------------------------------------------------------------------
void binary_tree::breadth_first_search(){
    breadth_first_search_pri(root);
}
void binary_tree::breadth_first_search_pri(node* ptr){
    if(ptr == NULL)
        return;
    queue<node*> q;//queue pointer to node
    q.push(ptr); //push the first node
    
    while(!q.empty()){
        node* cur = q.front(); //
        cout << cur->key <<" ";
        
        if(cur->left != NULL)
            q.push(cur->left);
        if(cur->right != NULL)
            q.push(cur->right);
        
        q.pop();
    }
    
}
//------------------------------------------------------------------------------------------
int main() {
    binary_tree tree;
    
    tree.add_node(10);
    tree.add_node(7);
    tree.add_node(2);
    tree.add_node(9);
    tree.add_node(8);
    tree.add_node(18);
    tree.add_node(14);
    tree.add_node(25);
    tree.add_node(11);
    tree.add_node(20);
    tree.add_node(21);
    tree.add_node(50);
    
    cout<<"Print tree inorder: "<<endl;
    tree.print_tree_inorder();
    cout<<endl;
    
    //tree.return_node(8);
    cout<< "BFS :"<<endl;
    tree.breadth_first_search();
    cout<<endl;

    return 0;
}
//------------------------------------------------------------------------------------------
