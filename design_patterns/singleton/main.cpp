#include "singleton.h"

using namespace std;

int main(){

  //singleton* obj = singleton::getInstance();

  int i =0;
  while(i < 10){
    singleton* obj = singleton::getInstance(); //not new singleton since constructor in private
    obj->getfibo();
    i++;
  }

  cout<<endl;

  return 0;
}
