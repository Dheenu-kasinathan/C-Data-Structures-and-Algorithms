#include <iostream>
#include <stdio.h>

using namespace std;

class car{
public:
  int whelsize;
  string name;

  car(int val, string name_){
    whelsize = val;
    name = name_;
  }

  void print(){
    cout<<this->whelsize<<" "<<this->name<<endl;
  }


};

class bmw : public car{
public:
  bmw (): car(10, "i8"){}


};

class audi : public car{
public:
  audi (): car(5, "a8"){}


};

class ford: public car{
public:
  ford(int val, string name) : car(val, name){}
};



int main(){

  bmw b;
  b.print();

  audi a;
  a.print();

  ford f(1, "gt40");
  f.print();

  return 0;
}
