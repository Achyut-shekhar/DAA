#include<bits/stdc++.h>
using namespace std;
void sorting(vector<int> vec,int size)
{
   int count=0,comp=0;
    for (int i = 1; i < size; ++i) {
        int key = vec[i]; 
        int j = i - 1;
        comp=0;
        count=0;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
            count++;
            comp++;
        }
        vec[j + 1] = key;
        cout<<"\n";
        cout<<"comp is: "<<comp<<" shifted: "<<count;  
    }
    cout<<"\n";
     for(auto it:vec)
   {
     cout<<it<<" ";
    }
}
int main()
{
   int key;
   vector<int> arr;
   int size;
   cout<<"input the size of array:\n";
   cin>>size;
   for(int i=0;i<size;i++)
   {
      int num;
      cin>>num;
      arr.push_back(num);
   }
   for(auto it:arr)
   {
     cout<<it<<" ";
    }
    sorting(arr,size);
}
