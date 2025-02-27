#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) {
        arr[k++] = leftArr[i++];
    }
    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}


void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


void findDuplicates(vector<int>& arr) {
   
    mergeSort(arr, 0, arr.size() - 1);

   
    cout << "Duplicate elements: ";
    bool foundDuplicate = false;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1]) { 
            cout << arr[i] << " ";
            foundDuplicate = true;
        }
    }
    if (!foundDuplicate) {
        cout << "No duplicates found.";
    }
    cout << endl;
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
        findDuplicates(arr);
        
     
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
        
       
    }

    return 0;
}
