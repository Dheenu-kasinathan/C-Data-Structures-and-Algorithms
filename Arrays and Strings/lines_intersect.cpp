#include<stdio.h>
#include<iostream>
#include<vector>
#include<float.h>

using namespace std;

#define point pair<float,float>

float slope(point a, point b){
  float m = (b.second - a.second)/(b.first - a.first);
  return m;
}

bool intersect_of_line(point a, point b, point c, point d){
  bool flag = true;

  float line_1 = slope(a, b);
  float line_2 = slope(c, d);

  if(line_1 == line_2)
    flag = false;

  return flag;
}


point intersection_of_segments(point A, point B, point C, point D){
  point res = {FLT_MAX,FLT_MAX};

  // Line AB represented as a1x + b1y = c1
  float a1 = B.second - A.second;
  float b1 = A.first - B.first;
  float c1 = a1*(A.first) + b1*(A.second);

  // Line CD represented as a2x + b2y = c2
  double a2 = D.second - C.second;
  double b2 = C.first - D.first;
  double c2 = a2*(C.first)+ b2*(C.second);

  double determinant = a1*b2 - a2*b1;

  if (determinant != 0){
      double x = (b2*c1 - b1*c2)/determinant;
      double y = (a1*c2 - a2*c1)/determinant;
      res ={x, y};
  }

  return res;
}


int main(){

  point a,b,c,d;

  a = {1,1};
  b = {2,1};
  c = {1,2};
  d = {2,2.5};
  bool temp = intersect_of_line(a,b,c,d);
  if(temp == true)
    cout<<"lines intersect"<<endl;
  else
    cout<<"parallel lines"<<endl;

  a = {1,1};
  b = {3,1};
  c = {2,2};
  d = {2,0};
  pair<float,float> t = intersection_of_segments(a,b,c,d);
  if(t.first != FLT_MAX  && t.second != FLT_MAX)
    cout<<"segments intersect: x - "<<t.first<<" y - "<<t.second<<endl;
  else
    cout<<"segments doesnot intersect"<<endl;

  return 0;
}
