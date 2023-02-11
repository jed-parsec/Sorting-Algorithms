#include <stdio.h>

#define MAX_ELEMENT 100

int arr[MAX_ELEMENT];
int size = 0;

int partition(int arr[], int farLeft, int farRight) {
    int pivot = arr[farRight];
    int i = farLeft - 1;
    for (int j=farLeft; j<=farRight-1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[farRight];
    arr[farRight] = temp;
    return i+1;
}

void quickSortAsc(int arr[], int farLeft, int farRight) {
    if (farLeft > farRight) {
        int pivot_index = partition(arr, farLeft, farRight);
        quickSortAsc(arr, farLeft, pivot_index -1);
        quickSortAsc(arr, pivot_index+1, farRight);
    }
}


void quickSortDescs(int arr[], int farLeft, int farRight) {
    if (farLeft < farRight) {
        int pivot_index = partition(arr, farLeft, farRight);
        quickSortDescs(arr, farLeft, pivot_index -1);
        quickSortDescs(arr, pivot_index+1, farRight);
    }
}



void displayArray(int array[], int size, char order) {
  int i;
  if (order == 'A') {
    printf("\n[+] DISPLAYING ARRAY IN ASCENDING ORDER\n");
    quickSortAsc(arr, 0, size-1);
  } else if (order == 'D') {
    printf("\n[+] DISPLAYING ARRAY IN DESCENDING ORDER\n");
    quickSortDescs(arr, 0, size-1);
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
    if (element < 0 ) {
        printf("Please enter only positive numbers: ");
        i--;
        continue;
    }
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