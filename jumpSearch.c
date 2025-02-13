#include<stdio.h>
#include<math.h>


int jumpSearch(int arr[], int n, int target) {
    
    int step = sqrt(n);
    int prev = 0;

    
    while (arr[step - 1] < target && step < n) {
        prev = step;
        step += sqrt(n);
        if (step > n) {
            step = n;
        }
    }

   
    for (int i = prev; i < step; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1; 
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 15;

    int result = jumpSearch(arr, n, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}

