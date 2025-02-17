#include <stdio.h>

int exponentialSearch(int arr[], int n, int key, int *comparisons)
{
  if (arr[0] == key)
  {
    (*comparisons)++;
    return 0;
  }

  int i = 1;
  while (i < n && arr[i] <= key)
  {
    (*comparisons)++;
    i *= 2;
  }

  for (int j = i / 2; j < (i < n ? i : n); j++)
  {
    (*comparisons)++;
    if (arr[j] == key)
      return j;
  }

  return -1;
}

void processTestCase()
{
  int n;
  scanf("%d", &n); // Size of array
  int arr[n];

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  int key;
  scanf("%d", &key); // Key to search

  int comparisons = 0;
  int result = exponentialSearch(arr, n, key, &comparisons);

  if (result != -1)
    printf("Present %d\n", comparisons);
  else
    printf("Not Present %d\n", comparisons);
}

int main()
{
  int t;
  scanf("%d", &t); // Number of test cases

  while (t--)
  {
    processTestCase();
  }

  return 0;
}
