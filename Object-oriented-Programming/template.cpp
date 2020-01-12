#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

/*
template <class identifier> function_declaration;
template <typename identifier> function_declaration;
*/

// Function templates

//template <class T_1>
template<typename T_1>
T_1 fun_1(T_1 a, T_1 b){
  return a>b?a:b;
}


// Class templates
template<class T>
class max_{
public:
  T a, b;

  max_(T a_, T b_) {
    a = a_;
    b = b_;
  }

  T getmax();
};

template<class T>
T max_<T>::getmax(){
  T temp = a>b?a:b;
  return temp;
}


int main(){
  int a = 4, b = 8, c;
  long m = 5, n = 3, o;
  c = fun_1(a,b);
  o = fun_1(m,n);
  cout<<"max value is: "<<c<<endl;
  cout<<"max value is: "<<o<<endl;

  max_<int> obj(10,11);
  int tt = obj.getmax();
  cout<<"Max val in class: "<<tt<<endl;
  max_<double> obj_1(1.1,0.9);
  double tt_1= obj_1.getmax();
  cout<<"Max val in class: "<<tt_1<<endl;

  return 0;
}
