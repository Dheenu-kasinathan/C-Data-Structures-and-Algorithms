#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

class base{
public:
  base(){
    //cout<<"Base class constructor"<<endl;
  }
  virtual ~base(){
    //cout<<"Base class destructor"<<endl;
  }

  //static virtual print() // virtual function cant be static
  virtual void print(){
    cout<<"Print Base"<<endl;
  }
  void show(){
    cout<<"Show Base"<<endl;
  }

};


class derived_1 : public base{
public:
  derived_1(){
    //cout<<"Derived 1 constructor"<<endl;
  }
  ~derived_1(){
    //cout<<"Derived 1 destructor"<<endl;
  }

  //override keyword is used for silly mistakes while calling the functions
  //like void print(int a), 
  void print() override{
    cout<<"Print Derived 1"<<endl;
  }
  void show(){
    cout<<"Show Derived 1"<<endl;
  }
};

class derived_2 : public base{
public:
  derived_2(){
    //cout<<"Derived 2 constructor"<<endl;
  }
  ~derived_2(){
    //cout<<"Derived 2 destructor"<<endl;
  }
  void print() override{
    cout<<"Print Derived 2"<<endl;
  }
  void show(){
    cout<<"Show Derived 2"<<endl;
  }
};


class function_overloading{
public:
  void func(int x){
    cout<<"Value of X: "<<x<<endl;
  }
  void func(double x){
    cout << "Value of X: "<<x<<endl;
  }
  void func(int x, int y){
    cout<<"Value of X and Y: "<<x<<" "<<y<<endl;
  }
};


class operator_overloading{ // adding complex numbers
public:
  int real, imag;
  operator_overloading (int x=0, int y=0){
    real = x;
    imag = y;
  }

  operator_overloading operator+(operator_overloading const &obj){
    operator_overloading temp;
    //obj.real =10; //const used to remove changes
    temp.real = real + obj.real;
    temp.imag = imag + obj.imag;

    return temp;
  }

  void print_(){
    cout<<"complex number: "<<real<<" + "<<imag<<"i"<<endl;
  }

};


int main(){
  //function overloading
  function_overloading obj;
  obj.func(1);
  obj.func(1.111);
  obj.func(1,2);
  cout<<endl;

  //operator overloading
  operator_overloading c1(1,2), c2(3,4);
  operator_overloading c = c1+c2;
  c.print_();
  cout<<endl;

  //virtual function
  base *b;
  derived_1 d1;
  b = &d1;
  b->print();
  b->show();

  derived_2 d2;
  b = &d2;
  b->print();
  b->show();

  return 0;
}

/*
The word polymorphism means having many forms.
In simple words, we can define polymorphism as the ability of a message to be
displayed in more than one form.

Polymorphism
1. Compile time - Method Overriding, Operator Overriding
2. Run time - Virtual function
*/
