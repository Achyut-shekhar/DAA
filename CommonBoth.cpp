#include <iostream>
#include <vector>
using namespace std;

// Function to find common elements in two sorted arrays
vector<int> findCommonElements(const vector<int> &arr1, const vector<int> &arr2)
{
  vector<int> common;
  int i = 0, j = 0;
  int m = arr1.size(), n = arr2.size();

  while (i < m && j < n)
  {
    if (arr1[i] < arr2[j])
    {
      i++; // Move pointer in arr1
    }
    else if (arr1[i] > arr2[j])
    {
      j++; // Move pointer in arr2
    }
    else
    {
      // Common element found
      if (common.empty() || common.back() != arr1[i])
      {
        common.push_back(arr1[i]);
      }
      i++;
      j++; // Move both pointers
    }
  }
  return common;
}

int main()
{
  int t;
  cout << "Enter number of test cases: ";
  cin >> t;

  while (t--)
  {
    int m, n;
    cout << "Enter size of first array: ";
    cin >> m;
    vector<int> arr1(m);
    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < m; i++)
    {
      cin >> arr1[i];
    }

    cout << "Enter size of second array: ";
    cin >> n;
    vector<int> arr2(n);
    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < n; i++)
    {
      cin >> arr2[i];
    }

    vector<int> result = findCommonElements(arr1, arr2);

    cout << "Common elements: ";
    for (int num : result)
    {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}