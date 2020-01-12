#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class shape{
private:

protected:
  double area;
  double circum;
  double t_area;
  double t_area_1;
public:
  double getArea(){
    return this->area;
  }

  virtual void circumference() = 0;

  shape(){

  }

  void print(){
    cout<<"Area: "<<area<<endl;
    cout<<"Circumference: "<<this->circum<<endl;
  }

  void total_area(shape *s_1, shape *s_2){
    t_area = s_1->area + s_2->area;
    cout<<"Total area: "<<t_area<<endl;
  }

  void total_area_1(shape *s_1){
    t_area_1 = this->area + s_1->area;
    cout<<"Total area: "<<t_area_1<<endl;
  }


};

class rectangle : public shape{
private:
  double length;
  double breath;

public:
  rectangle(){}

  rectangle (double l, double b) {
    length = l;
    breath = b;
    this->area = length*breath;
  }

  void circumference(){
    this->circum =  2*(length+breath);
  }



};

class circle : public shape{
private:
  double radius;

public:

  circle(double r) : radius(r){
    this->area = (3.14*r*r);
  }

  void circumference(){
    this->circum = 2*3.14*radius;
  }


};



class animal{
protected:
  string name;
  string food;
  char dominance;
  int legs;

public:
  animal(){}

  void print(){
    cout<<"Animal: "<<get_name()<<" Type: "<<this->food<<" Dominance: "<<
        this->dominance<<" Legs: "<<this->legs<<endl;
  }

  virtual string get_name() = 0;

  void set_dominance(char c){
    this->dominance = c;
  }
};

class lion : public animal{
protected:
  string name_;

public:

  lion() : name_("Lion"){
    this->food = "Carnovorous";
    this->set_dominance('A');
  }

  string get_name(){
    return this->name_;
  }


};

class deer : public animal{
protected:
  string name_;

public:

  deer() : name_("Deer"){
    this->food = "Herbivorous";
    this->set_dominance('B');
  }

  string get_name(){
    return this->name_;
  }


};

template<typename T>
void print_(T obj){
  obj.print();
};


int main(){

  lion l;
  print_(l);
  deer d;
  print_(d);


/*
  rectangle rect(2,4);
  rect.circumference();
  rect.print();

  circle cir(3);
  cir.circumference();
  cir.print();

  shape *s_1;
  rectangle r(3,5);  //allocate memory in stack
  s_1 = &r;
  s_1->circumference();
  s_1->print();

  shape *s_2 = new circle(5); //allocate memory in heap
  s_2->circumference();
  s_2->print();

  shape *s_3 = new rectangle();
  s_3->total_area(s_1, s_2);

  s_2->total_area_1(s_1);
  */

}
