#include <iostream>
using namespace std;

// Recursive Bubble Sort Function
void recursiveBubbleSort(int arr[], int n) {
    // Base case: If array size is 1, return
    if (n == 1) 
        return;

    // Perform one pass of bubble sort
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    // Recursive call for the remaining array
    recursiveBubbleSort(arr, n - 1);
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    recursiveBubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
