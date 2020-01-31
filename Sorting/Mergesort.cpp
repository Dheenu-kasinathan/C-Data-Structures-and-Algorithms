#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int left, int mid, int right){

  vector<int> left_array (mid-left+1,0);
  vector<int> right_array (right-mid,0);

  for(int i = 0; i < left_array.size(); i++)
    left_array[i] = arr[left+i];

  for(int i = 0; i <right_array.size(); i++)
    right_array[i] = arr[mid+1+i];

  int i = 0;
  int j = 0;

  int ptr = left;

  while( (i<left_array.size()) && (j<right_array.size()) ){
    if(left_array[i] <= right_array[j])
      arr[ptr++] = left_array[i++];
    else
      arr[ptr++] = right_array[j++];
  }

  while (i < left_array.size())
    arr[ptr++] = left_array[i++];

  while(j < right_array.size())
    arr[ptr++] = right_array[j++];

}

void mergesort(vector<int> &arr, int left, int right){

  if(left < right){

    int mid = left + (right-left)/2;

    mergesort(arr, left, mid);
    mergesort(arr, mid+1, right);

    merge(arr, left, mid, right);
  }
}


int main(){

  vector<int> arr = {3,5,9,1,7,6,8,2,4,0};

  mergesort(arr, 0, arr.size()-1);

  cout<<"Sorted array: ";
  for(auto val: arr)
    cout<<val<<" ";
  cout<<endl;

  return 0;
}
