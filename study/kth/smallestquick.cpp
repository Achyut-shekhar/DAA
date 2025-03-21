#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
  int pivot = arr[low];
  int i = low;
  int j = high;
  while (i < j)
  {
    while (arr[i] <= pivot && i <= high)
      i++;
    while (arr[j] > pivot && j >= low)
      j--;

    if (i < j)
      swap(arr[i], arr[j]);
  }
  swap(arr[low], arr[j]);
  return j;
}

int quickSelect(vector<int> &arr, int low, int high, int k)
{
  if (low <= high)
  {
    int pindex = partition(arr, low, high);
    if (pindex == k)
      return arr[pindex];
    else if (pindex > k)
      return quickSelect(arr, low, pindex - 1, k);
    else
      return quickSelect(arr, pindex + 1, high, k);
  }
  return -1;
}

int findKthLargest(vector<int> &arr, int k)
{
  int n = arr.size();
  return quickSelect(arr, 0, n - 1, k - 1); // kth smallest
}

int main()
{
  vector<int> arr = {12, 3, 5, 7, 19, 1, 4, 6};
  int k = 2;

  cout << k << "th smallest element: " << findKthLargest(arr, k) << endl;
  return 0;
}
