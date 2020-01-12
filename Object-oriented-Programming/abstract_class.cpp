#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

class Car{
protected:
  bool isSedan;
  string seats;

public:
  Car(bool isSedan, string seats){
    this->isSedan = isSedan;
    this->seats = seats;
  }

  bool getIsSedan(){
    return this->isSedan;
  }

  string getSeats(){
    return this->seats;
  }

  virtual string getMileage() = 0; //abstract pure virtual function

  void printCar(string name){
    cout<<"A "<<name<<" is"<<(this->getIsSedan() ? " " : " not ")
      <<"Sedan, is " << this->getSeats() << "-seater, and has a mileage of around "
      <<getMileage() << endl;
  }
};

class WagonR : public Car{
public:
  WagonR() : Car(true, "Four"){}

  string getMileage(){
    return "25";
  }

};

class HondaCity : public Car{
public:
  HondaCity() : Car(true, "Four"){}

  string getMileage(){
    return "15";
  }

};

class Innova : public Car{
public:
  Innova() : Car(false, "Six"){}

  string getMileage(){
    return "20";
  }

};

int main(){

  //car a; error

  WagonR obj;
  obj.printCar("WagonR");

  HondaCity Ho;
  Ho.printCar("HondaCity");

  Innova In;
  In.printCar("Innova");




  return 0;
}
