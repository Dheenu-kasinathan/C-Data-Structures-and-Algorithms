#include "factorydesign.h"

using namespace std;

int main(){
  toy* obj = NULL;
  string toy_name ;

  while(obj == NULL){
    cout<< "Type the name of the toy you want to create (bike, car, plane or 'q' to quit): "<<endl;
    cin >> toy_name;

    if(toy_name == "q")
      break;

    toy* obj = toy_factory::createtoy(toy_name);

    if(obj){
      cout<<"Number of wheels:  "<<obj->numberofwheels()<<endl;
      cout<<"Price of the toy: ";
      obj->getprice();
    }
    else
      cout<< "Toy doesnt exists "<<endl;

    if(obj)
      obj->free_();

    obj = NULL;
    toy_name.clear();
  }
  return 0;
}
