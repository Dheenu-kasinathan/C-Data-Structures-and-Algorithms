#include "factorydesign.h"

using namespace std;

toy* toy_factory::createtoy(string type_){
  if(type_ == "car")
    return new car();
  else if (type_ == "bike")
    return new bike();
  else if (type_ == "plane")
    return new plane;
  else
    return NULL;
}


int car::numberofwheels() const{
  return 4;
}
void car::getprice(){
  cout<<"50 USD"<<endl;
}
void car::free_(){
  delete this;
}

int bike::numberofwheels() const{
  return 2;
}
void bike::getprice(){
  cout<<"30 USD"<<endl;
}
void bike::free_(){
  delete this;
}

int plane::numberofwheels() const{
  return 6;
}
void plane::getprice(){
  cout<<"100 USD"<<endl;
}
void plane::free_(){
  delete this;
}
