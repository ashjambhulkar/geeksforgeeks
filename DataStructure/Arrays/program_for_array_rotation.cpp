#include <iostream>

using namespace std;

void print_array(int arr[], int size){
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " " ;
  }
  cout << endl;
}

// shift the whole array
void shift_array(int arr[], int size, int count){
  int temp[size];
  int j = 0;
  for (int i = count; i < size ; i++)
  {
    temp[j] = arr[i];
    j++;
  }
  int k = 0;
  for (int i = size - count; i < size; i++)
  {
    temp[i] = arr[k];
    k++;
  }
  print_array(temp, size);
  
}

// rotate array one by one
void rotate_by_one(int arr[], int size){
  int temp = arr[0];
  for (int i = 0; i < size-1; i++)
  {
    arr[i] = arr[i+1];
  }
  arr[size-1] = temp;
  print_array(arr, size);
}

int calculate_gcd(int size, int count){
  if(count == 0)
    return size;
  else
    return calculate_gcd(count, size % count);
}

// rotate array by using GCD
void using_gcd(int arr[], int size, int count){
  int gcd_count = calculate_gcd(size, count);
  for (int i = 0; i < gcd_count; i++)
  {
    int j = i;
    int temp = arr[i];
    while (1)
    {
      int k = (j + count)% size;
      if( k == i)
        break;
      else
      {
        arr[j] = arr[k];
        j = k;
      }
    }
    arr[j] = temp;
  }
  print_array(arr, size);
}

int main(int argc, char const *argv[])
{
  int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12};
  int size = sizeof(arr)/ sizeof(arr[0]);
  int count = 3;
  rotate_by_one(arr, size);
  shift_array(arr, size, count);
  using_gcd(arr, size, count);
  return 0;
}
