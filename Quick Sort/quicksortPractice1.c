#include <stdio.h>

int partition (int arr[], int leftEndIndex, int rightEndIndex) {

    int j;
    int temp;

    int pivot = arr[rightEndIndex];
    int i = leftEndIndex - 1;

    for (j=leftEndIndex; j<=rightEndIndex - 1; j++) {

        if (arr[j] <= pivot) {              //if the element smaller than pivot
            i++;                            //is found, swap it with greater
                                            //greater element pointed by 1
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            
        }
    }

     temp = arr[i+1];
    arr[i+1] = arr[rightEndIndex];
    arr[rightEndIndex] = temp;
    return i + 1;
}

void quicksort(int arr[], int leftEndIndex, int rightEndIndex) {
    if (leftEndIndex < rightEndIndex) {
        int pivot_index = partition(arr, leftEndIndex, rightEndIndex);
        quicksort(arr, leftEndIndex, pivot_index - 1);
        quicksort(arr, pivot_index  + 1, rightEndIndex);
    }
}

int main () {
    int arr[] = {10, 7, -8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, n-1);

    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;

}