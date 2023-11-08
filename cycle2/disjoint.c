#include <stdio.h>
#define MAX 100

int parent[MAX], rank[MAX], n;


int find(int x) {
    if (x != parent[x])
        parent[x] = find(parent[x]); 
    return parent[x];
}

int main() {
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Invalid input. Please enter a positive integer less than or equal to %d.\n", MAX);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int choice, x, y;
    while (1) {
        printf("\nOperations:\n1. Union\n2. Find\n3. Display Set Representatives\n4. Exit\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            continue;
        }

        switch (choice) {
            case 1:
              
                printf("Enter elements to perform union: ");
                if (scanf("%d %d", &x, &y) != 2 || x < 0 || x >= n || y < 0 || y >= n) {
                    printf("Invalid input. Please enter valid elements.\n");
                } else {
                    int rootX = find(x);
                    int rootY = find(y);

                    if (rootX == rootY) {
                        printf("%d and %d are already in the same set.\n", x, y);
                    } else {
                      
                        if (rank[rootX] > rank[rootY]) {
                            parent[rootY] = rootX;
                        } else if (rank[rootX] < rank[rootY]) {
                            parent[rootX] = rootY;
                        } else {
                            parent[rootY] = rootX;
                            rank[rootX]++;
                        }
                        printf("Union of %d and %d is performed.\n", x, y);
                    }
                }
                break;
            case 2:
              
                printf("Enter element to find its set: ");
                if (scanf("%d", &x) != 1 || x < 0 || x >= n) {
                    printf("Invalid input. Please enter a valid element.\n");
                } else {
                    printf("Set representative of %d is %d\n", x, find(x));
                }
                break;
            case 3:
              
                printf("Set Representatives:\n");
                for (int i = 0; i < n; i++) {
                    printf("Element %d belongs to set with representative %d\n", i, find(i));
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }
}
