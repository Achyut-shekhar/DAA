#include <bits/stdc++.h>
using namespace std;

int comparisons = 0;  
int swaps = 0;        

int partition(vector<int> &vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        comparisons++;  
        if (vec[j] < pivot) {
            i++;
            swap(vec[i], vec[j]);
            swaps++; 
        }
    }
    swap(vec[i + 1], vec[high]);
    swaps++;  
    return (i + 1);
}

void quicksort(vector<int> &vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);
        quicksort(vec, low, pi - 1);
        quicksort(vec, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Input the number of elements: ";
    cin >> n;

    vector<int> vec(n);
    cout << "Input the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    
    quicksort(vec, 0, n - 1);

   
    cout << "Sorted array: ";
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;

   
    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total swaps: " << swaps << endl;

    return 0;
}
