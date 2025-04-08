#include<stdio.h>
int binaryKey(int arr[],int n,int key)
{
  int low=0,high=n-1,f1=-1;
  
  while(low<=high)
  {
  int mid=low+(high-low)/2;
  if(arr[mid]==key)
  {
    f1=mid;
    high=mid-1;
  }
  else if(arr[mid]<key)
  low=mid+1;
  else
  high=mid-1;
  }
  return f1;
}
int Key(int arr[],int n,int key)
{
  int low=0,high=n-1,f1=-1;
  
  while(low<=high)
  {int mid=low+(high-low)/2;
  if(arr[mid]==key)
  {
    f1=mid;
    low=mid+1;
  }
  else if(arr[mid]<key)
  low=mid+1;
  else
  high=mid-1;
  }
  return f1;
}

int main() {
    int test, key;
    printf("Enter the number of test cases: ");
    scanf("%d", &test);

    while (test--) {
        int n;
        printf("Enter the size of array: ");
        scanf("%d", &n);

        int arr[n];
        printf("Enter the array elements in sorted order: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        printf("Enter the key: ");
        scanf("%d", &key);

        int f = binaryKey(arr, n, key);
        int f1 = Key(arr, n, key);

        if (f != -1 && f1 != -1) { // Check if the key was found
            printf("Frequency of key %d: %d\n", key, f1 - f + 1);
        } else {
            printf("Key not found\n");
        }
    }

    return 0;
}
