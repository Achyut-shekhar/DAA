#include<bits/stdc++.h>
using namespace std;

void sel(vector<int>& arr, int& comparisons, int& shifts) {
    int n = arr.size();
    comparisons = 0;
    shifts = 0;
    int min,i,j,temp;
    
   for( i=0;i<n-1;i++)
   {  min=i;
      for( j=i+1;j<n;j++)
      { comparisons++;  
     
      if(arr[j]<arr[min])
         min=j;
      }
      
   if(arr[min]!=arr[i]){
     shifts+=1;
     temp=arr[i];
    arr[i]=arr[min];
    arr[min]=temp;
  
    }
   }
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        int comparisons, shifts;
        sel(arr, comparisons, shifts);
        
        // Output sorted array
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
        
        // Output number of comparisons
        cout << "Comparisons: " << comparisons << endl;
        
        // Output number of shifts
        cout << "Shifts: " << shifts << endl;
    }
    
    return 0;
}
