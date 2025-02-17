#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key, int &comparisons)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void processTestCase()
{
    int n;
    cin >> n; // Size of array
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cin >> key; // Key to search

    int comparisons = 0;
    int result = binarySearch(arr, n, key, comparisons);

    if (result != -1)
        cout << "Present " << comparisons << endl;
    else
        cout << "Not Present " << comparisons << endl;
}

int main()
{
    int t;
    cin >> t; // Number of test cases

    while (t--)
    {
        processTestCase();
    }

    return 0;
}
