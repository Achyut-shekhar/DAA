#include<stdio.h>
int find(int arr[],int left,int right)
{  if(right<=left)
      return 0;
int mid = left + (right - left) / 2;
    
    
    if (arr[mid] == arr[mid + 1] || arr[mid] == arr[mid - 1]) {
        return 1;  
    }
    
    
    if (arr[left] <= arr[mid]) {
        if (arr[left] == arr[mid]) {
            return 1;  
        }
        
        return find(arr, mid + 1, right);
    } else {
       
        return find(arr, left, mid - 1);
    }
}
int main()
{
    int n;
    int arr[100];
    printf("input the size of array");
    scanf("%d",&n);
    printf("input the element");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int res=find(arr,0,n-1);
    if(res==0)
    printf("not found");
    else
    printf("found");
}
