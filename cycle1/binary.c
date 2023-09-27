#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}

int main() {
    int arr[100];
    int size, target, choice, result;


    printf("Enter the size of the array (max 100): ");
    scanf("%d", &size);


    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nSelect an option:\n 1. Linear Search\n 2. Binary Search\n 3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:

                printf("Enter the value to search for: ");
                scanf("%d", &target);
                result = linearSearch(arr, size, target);
                if (result != -1) {
                    printf("Linear search: Element %d found at index %d.\n", target, result);
                } else {
                    printf("Linear search: Element %d not found.\n", target);
                }
                break;

            case 2:
        
                for (int i = 0; i < size-1; i++) {
                    for (int j = 0; j < size-i-1; j++) {
                        if (arr[j] > arr[j+1]) {
                            int temp = arr[j];
                            arr[j] = arr[j+1];
                            arr[j+1] = temp;
                        }
                    }
                }

                printf("Enter the value to search for: ");
                scanf("%d", &target);
                result = binarySearch(arr, size, target);
                if (result != -1) {
                    printf("Binary search: Element %d found at index %d.\n", target, result);
                } else {
                    printf("Binary search: Element %d not found.\n", target);
                }
                break;

            case 3:
                return 0; 

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
  }

      return 0;
}
