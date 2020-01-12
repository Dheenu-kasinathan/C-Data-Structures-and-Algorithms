#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;


class mov_avg{
public:

  vector<float> vect;
  int n;
  float first, last;
  float sum = 0;

  mov_avg(int n_){
    vect.resize(n_);
    n = n_;

    for(int i = 1; i <= n; i++){
      vect[i-1] = i;
      sum += i;
    }
    first = vect[0];
    last = vect[n-1];
  }

  void calculate(){
    float avg = sum/n;

    cout<<"average "<< avg <<endl;

  }

  void move(){
    vect.erase(vect.begin());
    vect.push_back(last+1);

    sum = sum - first;
    sum = sum + last+1;

    last = last+1;
    first = vect[0];
  }

  void print(){

    for(auto v : vect){
      cout<< v <<" ";
    }

    cout <<endl;
    cout<<"sum: "<<sum<<endl;
  }


};

int main(){

  int n = 10;

  mov_avg obj(n);

  for(int i =0; i< 4; i++){
    cout<<endl;
    obj.print();
    obj.calculate();
    obj.move();
  }

  return 0;
}
