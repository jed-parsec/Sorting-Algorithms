#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quicksort(int arr[], int low, int high) { 
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
