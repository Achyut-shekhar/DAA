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
    {
      i++;
    }
    while (arr[j] > pivot && j >= low)
    {
      j--;
    }
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
    int pIndex = partition(arr, low, high);
    if (pIndex == k)
      return arr[pIndex];
    else if (pIndex > k)
      return quickSelect(arr, low, pIndex - 1, k);
    else
      return quickSelect(arr, pIndex + 1, high, k);
  }
  return -1;
}

// Function to find the k-th largest element
int findKthLargest(vector<int> &arr, int k)
{
  int n = arr.size();
  return quickSelect(arr, 0, n - 1, n - k); // Convert k-th largest to (n-k)-th smallest
}

int main()
{
  vector<int> arr = {12, 3, 5, 7, 19, 1, 4, 6};
  int k = 2;

  cout << k << "th largest element: " << findKthLargest(arr, k) << endl;
  return 0;
}
