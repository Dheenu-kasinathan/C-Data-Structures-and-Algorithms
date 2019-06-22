#include "linkedlist.h"
using namespace std;

int main(){

  linked_list list;

  for(int i = 1; i<= 10; i++){
    list.addnode(i);
  }
  cout<<"after node creation: ";
  list.printlist();
  cout<<endl;

  cout<<"delete the desired position: ";
  list.deletebyposition(1);
  list.printlist();
  cout<<endl;

  cout<<"delete the desired value: ";
  list.deletebyvalue(2);
  list.printlist();
  cout<<endl;

  cout<<"reverse a list: ";
  list.reverselist();
  list.printlist();
  cout<<endl;

  return 0;
}
