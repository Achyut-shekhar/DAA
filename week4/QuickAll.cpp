#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int> &arr, int left, int right)
{
  int pivot = arr[right];
  int i = left;
  for (int j = left; j < right; j++)
  {
    if (arr[j] <= pivot)
    {
      swap(arr[i], arr[j]);
      i++;
    }
  }
  swap(arr[i], arr[right]);
  return i;
}

int quickSelect(vector<int> &arr, int left, int right, int k)
{
  if (left <= right)
  {
    int pivotIndex = partition(arr, left, right);
    if (pivotIndex == k)
      return arr[pivotIndex];
    else if (pivotIndex > k)
      return quickSelect(arr, left, pivotIndex - 1, k);
    else
      return quickSelect(arr, pivotIndex + 1, right, k);
  }
  return -1;
}

int findKthSmallest(vector<int> &arr, int k)
{
  return quickSelect(arr, 0, arr.size() - 1, k - 1);
}

int findKthLargest(vector<int> &arr, int k)
{
  return quickSelect(arr, 0, arr.size() - 1, arr.size() - k);
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    cin >> k;

    cout << "Kth smallest element: " << findKthSmallest(arr, k) << endl;
    cout << "Kth largest element: " << findKthLargest(arr, k) << endl;
  }
  return 0;
}