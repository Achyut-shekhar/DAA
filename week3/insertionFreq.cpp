#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr, int& comparisons, int& shifts) {
    int n = arr.size();
    comparisons = 0;
    shifts = 0;
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        int shift_count = 0;
        
        // Move elements that are greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            shift_count++;
            j--;
        }
        
        // Place the key in its correct position
        if (shift_count > 0) {
            arr[j + 1] = key;
            shift_count++;
        }
        shifts += shift_count;
        
        if (j >= 0) comparisons++; // Extra comparison when while loop fails
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
        insertionSort(arr, comparisons, shifts);
        
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
