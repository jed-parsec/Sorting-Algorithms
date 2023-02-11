//QUICK SORT IN ASCENDING ORDER



#include <stdio.h>

int partition (int arr[], int farLeft, int farRight) {
    int i;
    int j;
    int temp;
    int pivot = arr[farRight];

    i = farLeft - 1;

    for (j=farLeft; j<=farRight - 1; j++) {
        if (arr[j] <= pivot) {
            i++;

            temp = arr[i];
            arr[i]=arr[j];
            arr[j]= temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[farRight];
    arr[farRight] = temp;
    return i + 1;
}

void quickSort (int arr[], int farLeft, int farRight) {
    if (farLeft < farRight) {
            int pivot_index = partition(arr, farLeft, farRight);
            quickSort(arr, farLeft, pivot_index - 1);
            quickSort(arr, pivot_index + 1, farRight);
    }
}

int main () {
    int arr [] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    for (int i=0; i<n; i++) {
        printf("%d " , arr[i]);
    }

    return 0;

}