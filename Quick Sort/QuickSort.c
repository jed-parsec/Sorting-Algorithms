#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int array[], int low, int high) {
    int pivot = array[low];
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j) {
            return j;
        }

        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int randPartition(int array[], int low, int high) {
    srand(time(0));
    int random = low + rand() % (high - low);

    int temp = array[random];
    array[random] = array[low];
    array[low] = temp;

    return partition(array, low, high);
}



void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pivot = partition(array, low, high);

        quickSort(array, low, pivot);
        quickSort(array, pivot + 1, high);
    }
}

void randomQuicksort(int array[], int low, int high) {
    if (low < high) {
        int pivot = randPartition(array, low, high);

        quickSort(array, low, pivot);
        quickSort(array, pivot + 1, high);
    }
}



void displayArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}



int main () {

    int array[] = {87, 21, 82, 44, 18, 12, 17};
    int size = sizeof(array) / sizeof(array[0]);
    quickSort(array, 0, size - 1);
    printf("Sorted QuickSort Array Without Random Partition: \n");
    displayArray(array, size);
    randomQuicksort(array, 0, size - 1);
    printf("Soted QuickSort Array With Random Partition: \n");
    displayArray(array, size);

    return 0;
}