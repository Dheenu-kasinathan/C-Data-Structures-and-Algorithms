#include "cor.h"

using namespace std;

int main(){

  handler* h1 = new specialhandler(100,1);
  handler* h2 = new specialhandler(50,2);
  handler* h3 = new specialhandler(20,3);
  handler* h4 = new specialhandler(5,4);

  h1->setNextHandler(h2);
  h2->setNextHandler(h3);
  h3->setNextHandler(h4);

  h1->request(45);
  cout<<endl;
  h1->request(70);
  cout<<endl;
  h1->request(105);
  cout<<endl;
  h1->request(4);

  delete h1;
  delete h2;
  delete h3;
  delete h4;

  return 0;
}
