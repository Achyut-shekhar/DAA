#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int low, int high, int key)
{

  if (low < high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == key)
      return mid;
    else if (arr[mid] < key)
      return binarySearch(arr, mid + 1, high, key);
    else
      return binarySearch(arr, low, mid - 1, key);
  }
}

int exponentialSearch(int arr[], int size, int key)
{
  if (arr[0] == key)
  {
    return 0;
  }
  int i = 1;
  while (i < size && arr[i] <= key)
  {
    i = i * 2;
  }

  // return binarySearch(arr, i / 2, min(i, size - 1), key);
  for (int j = i / 2; j < size - 1; j++)
  {
    if (arr[j] == key)
    {
      return j;
    }
  }
}

int main()
{
  int arr[] = {2, 4, 6, 8, 10, 12, 14}; // array should be sorted
  int size = sizeof(arr) / sizeof(arr[0]);
  int key = 10;

  int result = exponentialSearch(arr, size, key);

  if (result != -1)
  {
    cout << "Element found at index: " << result << endl;
  }
  else
  {
    cout << "Element not found in the array" << endl;
  }

  return 0;
}