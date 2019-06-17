// Reveral algorithm to reverse elements of an array by counr
#include <iostream>

    using namespace std;

void print_array(int arr[], int size){
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void swap_elements(int arr[], int start, int end){
  while(start < end){
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
} 

void reversal_algorithm(int arr[] ,int size,int count){
  swap_elements(arr, 0, count-1);
  swap_elements(arr, count ,size-1);
  swap_elements(arr, 0, size-1);
  print_array(arr, size);
}

int main(int argc, char const *argv[])
{
  int arr[]  = {1,2,3,4,5,6,7,8};
  int size = sizeof(arr) / sizeof(arr[0]);
  int count = 3; 
  reversal_algorithm(arr, size, count);
  return 0;
}
