#include "abstract_factory.h"

using namespace std;

shape* simple_factory::create_curved_instance(){
    return new circle;
}
shape* simple_factory::create_straight_instance(){
    return new square;
}

shape* robust_factory::create_curved_instance(){
    return new ellipse;
}
shape* robust_factory::create_straight_instance(){
    return new rectangle;
}
int shape::total = 0;


shape::shape(){
  id = total++;
}

void circle::draw(){
  cout<<"Circle " << id << " draw"<<endl;
}
void square::draw(){
  cout<<"Square " << id << " draw"<<endl;
}
void ellipse::draw(){
  cout<<"Ellipse " << id << " draw"<<endl;
}
void rectangle::draw(){
  cout<<"Rectangle " << id << " draw"<<endl;
}
