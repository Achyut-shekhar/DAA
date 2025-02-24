#include<bits/stdc++.h>
using namespace std;
void diff(vector<int> arr,int k,int n)
{
int i=0,j=i+1,count=0;
   sort(arr.begin(),arr.end());
   while(j<=arr.size())
   {
      if(arr[j]-arr[i]==k)
      {
        i++;
        j++;
        count++;
      }
      else if(arr[j]-arr[i]<k)
      {
        j++;
      }
      else
      i++;
   }
   cout<<"count is: "<<count;
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
     cout<<it;
    }
    cout<<"input the key"<<endl;
    cin>>key;
    diff(arr,key,size);
}
