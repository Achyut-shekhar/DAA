#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
  vector<int> temp;
  int left = low;
  int right = mid + 1;
  while (left <= mid && right <= high)
  {
    if (arr[left] <= arr[right])
    {
      temp.push_back(arr[left]);
      left++;
    }
    else
    {
      temp.push_back(arr[right]);
      right++;
    }
  }

  while (left <= mid)
  {
    temp.push_back(arr[left]);
    left++;
  }
  while (right <= high)
  {
    temp.push_back(arr[right]);
    right++;
  }

  for (int i = low; i <= high; i++)
  {
    arr[i] = temp[i - low];
  }
}

void mergeSort(std::vector<int> &arr, int low, int high)
{
  int mid;
  if (low < high)
  {
    mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

void printArray(const std::vector<int> &arr)
{
  for (int num : arr)
    std::cout << num << " ";
  std::cout << std::endl;
}

int main()
{
  std::vector<int> arr = {12, 11, 13, 5, 6, 7};
  std::cout << "Given array is \n";
  printArray(arr);

  mergeSort(arr, 0, arr.size() - 1);

  std::cout << "\nSorted array is \n";
  printArray(arr);
  return 0;
}