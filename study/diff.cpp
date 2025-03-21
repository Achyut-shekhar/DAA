#include <bits/stdc++.h>
using namespace std;

void diff(vector<int> arr, int k)
{
  int i = 0, j = 1, count = 0;
  while (j <= arr.size())
  {
    if (arr[j] - arr[i] == k)
    {
      count++;
      i++;
      j++;
    }
    else if (arr[j] - arr[i] < k)
    {
      j++;
    }
    else
    {
      i++;
    }
  }
  cout << "count is " << count << endl;
}

int main()
{
  vector<int> arr = {1, 2, 2, 2, 3, 4};
  cout << "Input the value of key:";
  int k;
  cin >> k;
  diff(arr, k);
}