#include<stdio.h>
#include<iostream>

#include<array>
#include<vector>

using namespace std;

int main(){

  int arr1[10];
  for(int i =0; i<10; i++){
    arr1[i] = i;
    cout<<arr1[i]<<" ";
  }
  cout<<endl;

  int* arr2 = new int[5];
  delete[] arr2;

  int* arr3 = (int*)malloc(sizeof(8));
  arr3[7] = 10;
  cout<<arr3[8]<<endl;




  return 0;
}
