#include <bits/stdc++.h>
using namespace std;
// int binarySearch(int arr[], int size, int key)
// {
//   int low = 0, high = size - 1;
//   int mid;
//   while (low <= high)
//   {
//     mid = (low + high) / 2;
//     if (arr[mid] == key)
//     {
//       return mid;
//     }
//     else if (arr[mid] < key)
//     {
//       low = mid + 1;
//     }
//     else
//     {
//       high = mid - 1;
//     }
//   }
//   return -1;
// }

// RECURSIVE WAY
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
int main()
{
  int arr[] = {2, 4, 6, 8, 10, 12, 14};
  int size = sizeof(arr) / sizeof(arr[0]);
  int key = 10;

  // int result = binarySearch(arr, size, key); (for non recursive code)
  int result = binarySearch(arr, 0, size - 1, key);

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