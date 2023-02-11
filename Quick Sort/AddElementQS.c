
// quickSort(array, leftmostIndex, rightmostIndex)
//   if (leftmostIndex < rightmostIndex)
//     pivotIndex <- partition(array,leftmostIndex, rightmostIndex)
//     quickSort(array, leftmostIndex, pivotIndex - 1)
//     quickSort(array, pivotIndex, rightmostIndex)

// partition(array, leftmostIndex, rightmostIndex)
//   set rightmostIndex as pivotIndex
//   storeIndex <- leftmostIndex - 1
//   for i <- leftmostIndex + 1 to rightmostIndex
//   if element[i] < pivotElement
//     swap element[i] and element[storeIndex]
//     storeIndex++
//   swap pivotElement and element[storeIndex+1]
// return storeIndex + 1


#include <stdio.h>

int partition(int arr[], int farLeft, int farRight) {
    int pivot = arr[farRight];
    int i = farLeft - 1;
    for (int j=farLeft; j<=farRight-1; j++) {
        if(arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i+1] = arr[farRight];
    arr[farRight] = temp;
    return i + 1;
}

void quickSort(int arr[], int farLeft, int farRight) {
    if (farLeft > farRight) {
        int pivot_index = partition(arr, farLeft, farRight);
        quickSort(arr, farLeft, pivot_index -1);
        quickSort(arr, pivot_index+1, farRight);
    }
}

int main () {
    int n;
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];


    printf("Enter elements: ");
    for ( i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        while (arr[i] < 0) {
            printf("Please enter only positive intgers: ");
            scanf("%d", &arr[i]);
        }
    }

    quickSort(arr, 0, n-1);
    printf("Sorted Elements: ");
    for ( i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}