#include <bits/stdc++.h>
using namespace std;

void SOE(vector<int> arr)
{

  int n = arr.size();
  for (int k = 2; k <= n; k++)
  {
    int i = 0, j = k - 1;
    int sum = arr[i] + arr[j];
    while (i < j)
    {
      if (sum == arr[k])
      {
        cout << i << " " << j << " " << k << endl;
        i++;
        j--;
      }
      else if (sum < arr[k])
      {
        i++;
      }
      else
      {
        j--;
      }
    }
  }
}

int main()
{
  vector<int> arr = {1, 2,4,5,6};

  SOE(arr);
}