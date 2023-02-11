#include <stdio.h>

#define MAX_ELEMENTS 100

int arr[MAX_ELEMENTS];
int size = 0;



void selectionSortAscending(int array[], int size) {
  int i, j;
  int temp;
  for (i = 0; i < size - 1; i++) {
    int minimum_index = i;
    for (j = i + 1; j < size; j++) {
      if (array[j] < array[minimum_index]) {
        minimum_index = j;
      }
    }
    temp = array[minimum_index];
    array[minimum_index] = array[i];
    array[i] = temp;
  }
}

void selectionSortDescending(int array[], int size) {
  int i, j;
  int temp;
  for (i = 0; i < size - 1; i++) {
    int maximum_index = i;
    for (j = i + 1; j < size; j++) {
      if (array[j] > array[maximum_index]) {
        maximum_index = j;
      }
    }
    temp = array[maximum_index];
    array[maximum_index] = array[i];
    array[i] = temp;
  }
}

void displayArray(int array[], int size, char order) {
  int i;
  if (order == 'A') {
    printf("\n[+] DISPLAYING ARRAY IN ASCENDING ORDER\n");
    selectionSortAscending(array, size);
  } else if (order == 'D') {
    printf("\n[+] DISPLAYING ARRAY IN DESCENDING ORDER\n");
    selectionSortDescending(array, size);
  }
  for (i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void addElement() {
  int n, element;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  printf("Enter %d elements: \n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &element);
    arr[size++] = element;
  }

}

int main() {
  int choice;
  char order;
  do {
    printf("\n[+] SELECT AN OPERATION\n");
    printf("1. Add Element\n");
    printf("2. Display Element\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", & choice);
    switch (choice) {
    case 1:
      addElement();
      break;
    case 2:
      printf("\n[+] DISPLAY ARRAY IN ORDER\n");
      printf("A. Ascending\n");
      printf("D. Descending\n");
      printf("Enter your choice: ");
      scanf(" %c", & order);
      displayArray(arr, size, order);
      break;
    case 3:
      printf("\n[+] EXITING THE APPLICATION\n");
      break;
    default:
      printf("\n[-] INVALID CHOICE\n");
      break;
    }
  } while (choice != 3);
  return 0;
}