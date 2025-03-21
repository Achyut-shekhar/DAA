#include <bits/stdc++.h>
using namespace std;

int binarysearch(vector<int> &arr, int key)
{
  int f1;
  int low = 0, high = arr.size() - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == key)
    {
      f1 = mid;
      high = mid - 1;
    }
    else if (arr[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return f1;
}
int lastbinarysearch(vector<int> &arr, int key)
{
  int f1;
  int low = 0, high = arr.size() - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == key)
    {
      f1 = mid;
      low = mid + 1;
    }
    else if (arr[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return f1;
}
int main()
{
  vector<int> arr = {1, 2, 2, 2, 3, 4};
  cout << "Input the value of key:";
  int k;
  cin >> k;
  int firstFound = binarysearch(arr, k);
  int lastFound = lastbinarysearch(arr, k);

  cout << "The frequency of key is at index " << lastFound - firstFound + 1 << endl;
}