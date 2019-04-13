#include <iostream>
#include<vector>

using namespace std;

struct node{
    int key;
    vector<node*> child;
};

class N_ary_tree{
private:
    node* root;
    //node* create_node_pri(int key, node* ptr);
    void add_node_pri(node* ptr);
    void pre_order_rec_pri(node* ptr);

    
public:
    
    //constructor
    N_ary_tree(){
        root = NULL;
    }
    
    node* create_node(int key);
    void add_node();
    void pre_order_rec();

    
};

//create a new node
node* N_ary_tree::create_node(int key){
    node* temp = new node;
    temp -> key = key;
    return temp;
}

//create an n tree
void N_ary_tree::add_node(){
    add_node_pri(root);
}
void N_ary_tree::add_node_pri(node* ptr){
    root = create_node(1); //first created node
    
    node* temp = root;
    temp->child.push_back(create_node(2));
    temp->child.push_back(create_node(3));
    temp->child.push_back(create_node(4));
    temp->child.push_back(create_node(5));
    temp->child[0]->child.push_back(create_node(6));
    temp->child[0]->child.push_back(create_node(7));
    temp->child[0]->child[0]->child.push_back(create_node(8));
    temp->child[0]->child[0]->child.push_back(create_node(9));
    temp->child[2]->child.push_back(create_node(10));
    temp->child[3]->child.push_back(create_node(11));
    temp->child[3]->child.push_back(create_node(12));
    temp->child[3]->child.push_back(create_node(13));
    temp->child[3]->child[2]->child.push_back(create_node(14));
}

//pre order travesal recursive
void N_ary_tree::pre_order_rec(){
    pre_order_rec_pri(root);
}
void N_ary_tree::pre_order_rec_pri(node* ptr){
    cout << ptr->key <<" ";
    for(node* child: ptr->child)
        pre_order_rec_pri(child);
    
}



int main() {
    
    N_ary_tree tree;
    
    tree.add_node();
    
    tree.pre_order_rec();

    return 0;
}
