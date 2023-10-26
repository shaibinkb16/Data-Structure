#include <stdio.h>

#define MAX_SIZE 100

// Function to read elements of a set from the user
int readSet(int set[]) {
    int size, i;

    printf("Enter the size of the set: ");
    scanf("%d", &size);

    printf("Enter elements of the set:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &set[i]);
    }

    return size;
}

// Function to display the elements of a set
void displaySet(int set[], int size) {
    int i;

    printf("Set: { ");
    for (i = 0; i < size; i++) {
        printf("%d ", set[i]);
    }
    printf("}\n");
}

// Function to perform set union
int setUnion(int set1[], int size1, int set2[], int size2, int result[]) {
    int i, j, k = 0;

    for (i = 0; i < size1; i++) {
        result[k++] = set1[i];
    }

    for (i = 0; i < size2; i++) {
        int found = 0;
        for (j = 0; j < size1; j++) {
            if (set2[i] == set1[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            result[k++] = set2[i];
        }
    }

    return k;
}

// Function to perform set intersection
int setIntersection(int set1[], int size1, int set2[], int size2, int result[]) {
    int i, j, k = 0;

    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            if (set1[i] == set2[j]) {
                result[k++] = set1[i];
                break;
            }
        }
    }

    return k;
}

// Function to perform set difference (set1 - set2)
int setDifference(int set1[], int size1, int set2[], int size2, int result[]) {
    int i, j, k = 0;

    for (i = 0; i < size1; i++) {
        int found = 0;
        for (j = 0; j < size2; j++) {
            if (set1[i] == set2[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            result[k++] = set1[i];
        }
    }

    return k;
}

int main() {
    int set1[MAX_SIZE], set2[MAX_SIZE], result[MAX_SIZE];
    int size1, size2, resultSize;
    int choice;

    size1 = readSet(set1);
    size2 = readSet(set2);

    do {
        printf("\nSet Operations:\n");
        printf("1. Union\n");
        printf("2. Intersection\n");
        printf("3. Difference (set1 - set2)\n");
        printf("4. Display Sets\n");
        printf("5. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                resultSize = setUnion(set1, size1, set2, size2, result);
                displaySet(result, resultSize);
                break;

            case 2:
                resultSize = setIntersection(set1, size1, set2, size2, result);
                displaySet(result, resultSize);
                break;

            case 3:
                resultSize = setDifference(set1, size1, set2, size2, result);
                displaySet(result, resultSize);
                break;

            case 4:
                printf("\nSets:\n");
                printf("Set 1: ");
                displaySet(set1, size1);
                printf("Set 2: ");
                displaySet(set2, size2);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
