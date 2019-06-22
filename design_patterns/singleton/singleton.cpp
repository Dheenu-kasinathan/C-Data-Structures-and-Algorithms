#include "singleton.h"

using namespace std;

singleton* singleton::_instance;  //static to define outside class
int singleton::count = 1;

singleton::singleton(){
  fibo.push_back(0);
  fibo.push_back(1);
}

singleton* singleton::getInstance(){
  if(_instance == NULL){
    _instance = new singleton();
  }
  return _instance;
}


void singleton::getfibo(){
  cout<<fibo[count]<<" ";
  fibo.push_back(fibo[count]+fibo[count-1]);
  count++;
}
