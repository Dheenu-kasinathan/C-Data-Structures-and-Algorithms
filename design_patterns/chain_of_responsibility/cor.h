#ifndef COR_H
#define COR_H

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class handler{
protected:
  handler* next;
public:
  handler();
  virtual ~handler();

  virtual void request(int val) = 0; //pure virtual class;

  void setNextHandler(handler* nextinline);
};

class specialhandler: public handler{
private:
  int mylimit;
  int id;
public:
  specialhandler(int limit, int i);
  ~specialhandler();

  void request(int value);

};





#endif
