#include <bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int> &arr, int low, int high)
{
  for (int i = low + 1; i <= high; i++)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= low && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void printArray(const vector<int> &arr)
{
  for (int num : arr)
    cout << num << " ";
  cout << endl;
}

int main()
{
  vector<int> arr = {12, 11, 13, 5, 6, 7};
  cout << "Given array is \n";
  printArray(arr);

  InsertionSort(arr, 0, arr.size() - 1);

  cout << "\nSorted array is \n";
  printArray(arr);
  return 0;
}