#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}


void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}


void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}


void breadthFirstSearch(struct Node* root) {
    if (root == NULL)
        return;

  
    struct Node* queue[100];
    int front = -1, rear = -1;


    queue[++rear] = root;

    while (front < rear) {
        struct Node* current = queue[++front];
        printf("%d ", current->data);

        if (current->left != NULL)
            queue[++rear] = current->left;

        if (current->right != NULL)
            queue[++rear] = current->right;
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\nBinary Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Breadth-First Search (BFS)\n");
        printf("6. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("In-order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Pre-order Traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Post-order Traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Breadth-First Search (BFS): ");
                breadthFirstSearch(root);
                printf("\n");
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
