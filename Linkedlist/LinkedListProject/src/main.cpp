#include <LinkedListProject/LinkedList.h>

using namespace std;

int main(){

  cout<<"Linked List Project"<<endl;

  linkedlist list;

  for(int i = 1; i <= 10; i++)
    list.add_list(i);
  list.print();

  list.swap_half();
  list.print();
  list.swap_half();

  list.reverse();
  list.print();

  return 0;
}
