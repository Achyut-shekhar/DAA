#include <bits/stdc++.h>
using namespace std;

// Partition function used by QuickSelect
int partition(vector<int>& arr, int low, int high) {
    // Choose the last element as the pivot
    int pivotValue = arr[high];
    int storeIndex = low;

    // Partition the array
    for (int i = low; i < high; i++) {
        if (arr[i] < pivotValue) {
            swap(arr[storeIndex], arr[i]);
            storeIndex++;
        }
    }

    // Move pivot to its final place
    swap(arr[storeIndex], arr[high]);
    return storeIndex;
}

// Function to find the k-th smallest element
int findKthSmallest(vector<int>& arr, int k) {
    int low = 0, high = arr.size() - 1;
    
    while (low <= high) {
        int pivotIndex = partition(arr, low, high);

        // If the pivot index is the k-th position, return the element
        if (pivotIndex == k - 1) {
            return arr[pivotIndex];
        } 
        else if (pivotIndex < k - 1) {
            low = pivotIndex + 1; // Search the right part
        } else {
            high = pivotIndex - 1; // Search the left part
        }
    }
    
    return -1; // This should never be reached if k is valid
}

int main() {
    vector<int> arr = {12, 3, 5, 7, 19, 1, 4, 6};
    int k = 4;

    cout << k << "th smallest element: " << findKthSmallest(arr, k) << endl;

    return 0;
}
