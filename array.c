#include <stdio.h>

#include <stdlib.h>

#define SIZE 4

void insertion();
void deletion();
void sorting();
void delete();

int main()
{

  int i, arr[20], n;
  int choice;

  printf("Enter the size of array: \n");
  scanf("%d", &n);

  printf("Enter the elements of array : ");

  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

    while (1)
    {
        printf("\nPerform operations on the ARRAY:");
        printf("\n1.INSERTION\n2.DELETION \n3.SORTING \n4.EXIT");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            sorting();
            break;
        case 4:
            deletion();
            break;
        case 5:
            exit(0);

        default:
            printf("\nInvalid choice!!");
        }
    }
}
