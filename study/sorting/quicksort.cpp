#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
  int pivot = arr[low];
  int i = low;
  int j = high;
  while (i <= j)
  {
    while (i <= high && arr[i] <= pivot)
    {
      i++;
    }
    while (j >= low && arr[j] > pivot)
    {
      j--;
    }
    if (i < j)
    {
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[low], arr[j]);
  return j;
}

void quickSort(vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int pindex = partition(arr, low, high);
    quickSort(arr, low, pindex - 1);
    quickSort(arr, pindex + 1, high);
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

  quickSort(arr, 0, arr.size() - 1);

  cout << "\nSorted array is \n";
  printArray(arr);
  return 0;
}