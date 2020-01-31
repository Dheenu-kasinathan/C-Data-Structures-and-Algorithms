#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void quicksort(vector<int> &arr, int left, int right){

  if(left >= right)
    return;

  int pivot = arr[right];

  int i = left;

  for(int j = left; j < right; j++)
    if(pivot > arr[j])
      swap(arr[i++],arr[j]); //swap(arr[i],arr[j]); i++;


  swap(arr[i], arr[right]);

  quicksort(arr, left, i-1);
  quicksort(arr, i+1, right);

}


int main(){

  vector<int> arr = {3,5,9,1,7,6,8,2,4,0};

  quicksort(arr, 0, arr.size()-1);

  cout<<"Sorted array: ";
  for(auto val: arr)
    cout<<val<<" ";
  cout<<endl;

  return 0;
}
