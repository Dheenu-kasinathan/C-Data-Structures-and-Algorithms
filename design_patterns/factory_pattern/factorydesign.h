#ifndef FACTORYDESIGN_H
#define FACTORYDESIGN_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class toy{                    //Abstract class
public:
  virtual int numberofwheels() const = 0;
  virtual void getprice() = 0;
  virtual void free_() = 0;
};

class car : public toy{       // CAR
public:
  int numberofwheels() const;
  void getprice();
  void free_();
};

class bike : public toy{      // BIKE
public:
  int numberofwheels() const;
  void getprice();
  void free_();
};

class plane : public toy{     // Plane
public:
  int numberofwheels() const;
  void getprice();
  void free_();
};

class toy_factory{            // Factory
public:
  static toy* createtoy(string type_);

};

#endif
