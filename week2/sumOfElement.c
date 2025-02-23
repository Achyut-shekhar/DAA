#include <stdio.h>

void findSequence(int arr[], int n)
{
  for (int k = 2; k < n; k++)
  {
    int i = 0, j = k - 1;
    while (i < j)
    {
      int sum = arr[i] + arr[j];
      if (sum == arr[k])
      {
        printf("%d %d %d\n", i, j, k);
        i++;
        j--;
      }
      else if (sum < arr[k])
      {
        i++; // Increase sum
      }
      else
      {
        j--;
      }
    }
  }
  printf("No sequence found\n");
}

int main()
{
  int T;
  printf("input the number of cases\n");
  scanf("%d", &T);

  while (T--)
  {
    int n;
    printf("input the size of array\n");
    scanf("%d", &n);
    int arr[n];
    printf("input the element of array size");
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &arr[i]);
    }

    findSequence(arr, n);
  }

  return 0;
}
