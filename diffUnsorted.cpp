#include <bits/stdc++.h>
using namespace std;

void diff(vector<int> arr, int k)
{
   int i = 0, j = 1, count = 0;
   sort(arr.begin(), arr.end());
   while (j < arr.size())
   {
      if (arr[j] + arr[i] == k)
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
   cout << count << endl;
}

int main()
{
   int T;
   cin >> T;
   while (T--)
   {
      int n, key;
      cin >> n;
      vector<int> arr(n);
      for (int i = 0; i < n; i++)
      {
         cin >> arr[i];
      }
      cin >> key;
      sort(arr.begin(),arr.end());
      for (int i = 0; i < n; i++)
      {
         cout << arr[i];
      }
      cout<<endl;
      diff(arr, key);
   }
   return 0;
}
