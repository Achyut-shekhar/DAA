#include<stdio.h>

int count_duplicates(int arr[], int n, int index) {
    int count = 1; 

    
    int left = index - 1;
    while (left >= 0 && arr[left] == arr[index]) {
        count++;
        left--;
    }

    
    int right = index + 1;
    while (right < n && arr[right] == arr[index]) {
        count++;
        right++;
    }

    return count;
}

int binarysearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;  
        } 
        else if (arr[mid] < target) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    return -1;  
}

void find_duplicate_and_count(int arr[], int n) {
    int flag = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            int mid = binarysearch(arr, n, arr[i]);  
            if (mid != -1) {
                int count = count_duplicates(arr, n, mid);  
                printf("Found duplicate for %d with %d occurrences.\n", arr[i], count);
                flag = 1;
                break;  
            }
        }
    }

    if (!flag) {
        printf("No adjacent duplicates found!\n");
    }
}

int main() {
    int test;
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

        find_duplicate_and_count(arr, n);
    }
    return 0;
}
