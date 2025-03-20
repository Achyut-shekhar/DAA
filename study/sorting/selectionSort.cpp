#include <bits/stdc++.h>
using namespace std;

void selectionsort(vector<int> &arr, int low, int high)
{
  for (int i = low; i <= high; i++)
  {
    int min = i;
    for (int j = i + 1; j <= high; j++)
    {
      if (arr[j] < arr[min])
      {
        min = j;
      }
    }
    if (arr[min] != arr[i])
      swap(arr[i], arr[min]);
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

  selectionsort(arr, 0, arr.size() - 1);

  cout << "\nSorted array is \n";
  printArray(arr);
  return 0;
}