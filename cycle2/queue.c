#include <stdio.h>

int MAX_SIZE;

int queue[100];
int front = -1, rear = -1;

int isFull() {
    return rear == MAX_SIZE - 1;
}

int isEmpty() {
    return front == -1;
}

int main() {
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &MAX_SIZE);

    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Check if full\n");
        printf("5. Check if empty\n");
        printf("6. Display Front\n");
        printf("7. Display Rear\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Queue is full. Cannot enqueue.\n");
                } else {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    if (front == -1) {
                        front = 0;
                    }
                    rear++;
                    queue[rear] = value;
                    printf("%d enqueued successfully.\n", value);
                }
                break;
            case 2:
                if (isEmpty()) {
                    printf("Queue is empty. Cannot dequeue.\n");
                } else {
                    int removed = queue[front];
                    if (front == rear) {
                        front = rear = -1;
                    } else {
                        front++;
                    }
                    printf("%d dequeued successfully.\n", removed);
                }
                break;
            case 3:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue elements: ");
                    for (int i = front; i <= rear; i++) {
                        printf("%d ", queue[i]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                if (isFull()) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 5:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 6:
                if (front != -1) {
                    printf("Front value: %d\n", queue[front]);
                } else {
                    printf("Queue is empty.\n");
                }
                break;
            case 7:
                if (rear != -1) {
                    printf("Rear value: %d\n", queue[rear]);
                } else {
                    printf("Queue is empty.\n");
                }
                break;
            case 8:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
}
    return 0;
        }

