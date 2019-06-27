#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H

#include<stdio.h>
#include<iostream>

using namespace std;

class shape{
public:
  shape();
  virtual void draw() = 0;
protected:
  int id;
  static int total;
};

class circle : public shape{
public:
  void draw();
};

class square : public shape{
public:
  void draw();
};

class ellipse : public shape{
public:
  void draw();
};

class rectangle : public shape{
public:
  void draw();
};

class factory{
public:
  virtual shape* create_curved_instance() = 0;
  virtual shape* create_straight_instance() = 0;
};

class simple_factory : public factory{
  shape* create_curved_instance();
  shape* create_straight_instance();
};

class robust_factory : public factory{
  shape* create_curved_instance();
  shape* create_straight_instance();
};

#endif
