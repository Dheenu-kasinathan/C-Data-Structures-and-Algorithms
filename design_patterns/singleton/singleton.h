#ifndef SINGLETON_H
#define SINGLETON_H

#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

class singleton{
private:
  static singleton* _instance; //static instance (object points address of a class)
  static int count;
  vector<int> fibo;
  singleton();

public:
  static singleton* getInstance();
  void getfibo();
};

#endif
