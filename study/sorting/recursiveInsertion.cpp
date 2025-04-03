#include <bits/stdc++.h>
using namespace std;

// Recursive Insertion Sort function
void RecursiveInsertionSort(vector<int> &arr, int low, int high)
{
  // Base case: If there's only one element, it's already sorted
  if (low >= high)
    return;

  // Recursively sort the first (high - 1) elements
  RecursiveInsertionSort(arr, low, high - 1);

  // Insert the last element at its correct position
  int key = arr[high];
  int j = high - 1;

  // Shift elements to the right to make space for the key
  while (j >= low && arr[j] > key)
  {
    arr[j + 1] = arr[j];
    j--;
  }
  arr[j + 1] = key;
}

// Function to print array
void printArray(const vector<int> &arr)
{
  for (int num : arr)
    cout << num << " ";
  cout << endl;
}

// Main function
int main()
{
  vector<int> arr = {12, 11, 13, 5, 6, 7};

  cout << "Given array is \n";
  printArray(arr);

  RecursiveInsertionSort(arr, 0, arr.size() - 1);

  cout << "\nSorted array is \n";
  printArray(arr);

  return 0;
}
