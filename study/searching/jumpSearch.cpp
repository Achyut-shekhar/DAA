#include <bits/stdc++.h>
using namespace std;
int jumpSearch(int arr[], int size, int key)
{
  int step = sqrt(size);
  int prev = 0;
  while (step < size && arr[step - 1] < key)
  {
    prev = step;
    step += sqrt(size);
    if (step > size)
    {
      step = size;
    }
  }
  for (int i = prev; i < step; i++)
  {
    if (arr[i] == key)
    {
      return i;
    }
  }
  return -1;
}
int main()
{
  int arr[] = {2, 4, 6, 8, 10, 12, 14}; //array should be sorted
  int size = sizeof(arr) / sizeof(arr[0]);
  int key = 10;

  int result = jumpSearch(arr, size, key);

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