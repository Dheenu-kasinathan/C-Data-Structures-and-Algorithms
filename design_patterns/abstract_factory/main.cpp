#include "abstract_factory.h"

using namespace std;

int main(){

  factory* sim = new simple_factory();

  factory* rob = new robust_factory();

  shape* shapes[4];

  shapes[0] = sim -> create_curved_instance();
  shapes[1] = sim -> create_straight_instance();
  shapes[2] = rob -> create_curved_instance();
  shapes[3] = rob -> create_straight_instance();

  for(int i =0; i<4;i++){
    shapes[i]->draw();
  }
  
  return 0;
}
