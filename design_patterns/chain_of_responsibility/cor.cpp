#include "cor.h"

using namespace std;

handler::handler(){
    next = NULL;
}
handler::~handler(){}

void handler::setNextHandler(handler* nextinline){
  next = nextinline;
}

specialhandler::specialhandler(int limit, int i){
  mylimit = limit;
  id = i;
}
specialhandler::~specialhandler(){}

void specialhandler::request(int value){
  if(value >= mylimit){
    cout << "Handler " << id << " handled the request with a limit of " << mylimit << endl;
    int new_val = value - mylimit;
    cout<<"remaining: "<<new_val<<endl;
    if(new_val!=0){
      this->request(new_val);
    }
    else
      cout<<"handeled succesfully" <<endl;
  }
  else if(next != NULL){
    next->request(value);
  }
  else
    cout << "Sorry, I am the last handler (" << id << ") and I can't handle the request." << endl;
}
