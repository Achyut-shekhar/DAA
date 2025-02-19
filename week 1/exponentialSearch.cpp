#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key, int &comparisons)
{
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    comparisons++;
    if (arr[mid] == key)
      return mid;
    else if (arr[mid] < key)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return -1;
}

int exponentialSearch(int arr[], int n, int key, int &comparisons)
{
  if (arr[0] == key)
  {
    comparisons++;
    return 0;
  }

  int i = 1;
  while (i < n && arr[i] <= key)
  {
    comparisons++;
    i *= 2;
  }

  // Perform binary search within the found range
  return binarySearch(arr, i / 2, min(i, n - 1), key, comparisons);
}

void processTestCase()
{
  int n;
  cin >> n; // Size of array

  // Dynamically allocate memory for the array
  int *arr = new int[n];

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int key;
  cin >> key; // Key to search

  int comparisons = 0;
  int result = exponentialSearch(arr, n, key, comparisons);

  if (result != -1)
    cout << "Present " << comparisons << endl;
  else
    cout << "Not Present " << comparisons << endl;

  // Free dynamically allocated memory
  delete[] arr;
}

int main()
{
  int t;
  cin >> t; // Number of test cases

  while (t--)
  {
    processTestCase();
  }

  return 0;
}
