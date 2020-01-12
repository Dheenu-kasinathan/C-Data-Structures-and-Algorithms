#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

class animal{
protected:
  string name;
  int legs;
public:
  void setname(string name){
    this->name = name;
  }
  void setlegs(int legs){
    this->legs = legs;
  }



};

class food{
protected:
  string eat;
public:
  food(string eat) {
    this->eat =eat;
  }

};

class deer : public animal{
public:
  deer() {
    this->setname("deer");
    this->setlegs(4);
  }

};

class lion : public animal{
public:
  lion() {
    this->setname("Lion");
    this->setlegs(4);
  }

};

/*
class grass : public food {
protected:

public:
  grass() : food("deer_eats_grass"){}
};
*/

int main(){



  return 0;
}
