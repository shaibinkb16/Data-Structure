
#include <stdio.h>

#define MAX_SIZE 100

void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *size, int element, int position) {
    if (*size < MAX_SIZE && position >= 1 && position <= *size + 1) {
        for (int i = *size; i >= position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position - 1] = element;
        (*size)++;
        printf("Element inserted.\n");
    } else {
        printf("Invalid position for insertion.\n");
    }
}

void deleteElement(int arr[], int *size, int position) {
    if (position >= 1 && position <= *size) {
        for (int i = position - 1; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
        printf("Element deleted.\n");
    } else {
        printf("Invalid position for deletion.\n");
    }
}

void sortArray(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted.\n");
}

void mergeSort(int arr1[], int *size1, int arr2[], int size2) {
    if (*size1 + size2 <= MAX_SIZE) {
        for (int i = 0; i < size2; i++) {
            arr1[*size1 + i] = arr2[i];
        }
        *size1 += size2;
        sortArray(arr1, *size1);
        printf("Arrays merged and sorted.\n");
    } else {
        printf("Merging not possible. Resultant array would exceed maximum size.\n");
    }
}

int main() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE];
    int size1 = 0, size2 = 0;
    int choice, element, position;


    printf("Enter the size of the first array (max %d): ", MAX_SIZE);
    scanf("%d", &size1);

    printf("Enter elements of the first array: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }


    printf("Enter the size of the second array (max %d): ", MAX_SIZE - size1);
    scanf("%d", &size2);

    printf("Enter elements of the second array: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Sorting\n");
        printf("4. Merge and Sort\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
 
                printf("Enter element and position for insertion: ");
                scanf("%d %d", &element, &position);
                insertElement(arr1, &size1, element, position);
                displayArray(arr1, size1);
                break;

            case 2:
     
                printf("Enter position for deletion: ");
                scanf("%d", &position);
                deleteElement(arr1, &size1, position);
                displayArray(arr1, size1);
                break;

            case 3:
 
                sortArray(arr1, size1);
                displayArray(arr1, size1);
                break;

            case 4:
             
                mergeSort(arr1, &size1, arr2, size2);
                displayArray(arr1, size1);
                break;

            case 5:
                return 0; 

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}


