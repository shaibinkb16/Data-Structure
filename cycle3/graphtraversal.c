
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 5

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjList[MAX_VERTICES];
    int numVertices;
} Graph;

// Function to create a new graph with a given number of vertices
Graph* createGraph(int numVertices) {
    if (numVertices <= 0 || numVertices > MAX_VERTICES) {
        printf("Invalid number of vertices. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; ++i)
        graph->adjList[i] = NULL;

    return graph;
}

// Function to add an edge to a directed graph
void addEdge(Graph* graph, int src, int dest) {
    if (src < 0 || src >= graph->numVertices || dest < 0 || dest >= graph->numVertices) {
        printf("Invalid source or destination vertex. Ignoring edge...\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Function to perform Depth-First Search (DFS)
void DFS(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    Node* adjNode = graph->adjList[vertex];
    while (adjNode != NULL) {
        int adjVertex = adjNode->vertex;
        if (!visited[adjVertex])
            DFS(graph, adjVertex, visited);
        adjNode = adjNode->next;
    }
}

// Function to perform Breadth-First Search (BFS)
void BFS(Graph* graph, int start) {
    if (start < 0 || start >= graph->numVertices) {
        printf("Invalid starting vertex. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    bool visited[MAX_VERTICES] = { false };
    int queue[MAX_VERTICES];
    int front = 0, rear = -1;

    visited[start] = true;
    queue[++rear] = start;

    while (front <= rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        Node* adjNode = graph->adjList[vertex];
        while (adjNode != NULL) {
            int adjVertex = adjNode->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue[(++rear) % MAX_VERTICES] = adjVertex; // Circular array for the queue
            }
            adjNode = adjNode->next;
        }
    }
}

// Function to perform Topological Sorting using DFS
void topologicalSortUtil(Graph* graph, int vertex, bool visited[], int stack[], int* stackIndex) {
    visited[vertex] = true;

    Node* adjNode = graph->adjList[vertex];
    while (adjNode != NULL) {
        int adjVertex = adjNode->vertex;
        if (!visited[adjVertex])
            topologicalSortUtil(graph, adjVertex, visited, stack, stackIndex);
        adjNode = adjNode->next;
    }

    stack[++(*stackIndex)] = vertex;
}

// Function to perform Topological Sorting
void topologicalSort(Graph* graph) {
    bool visited[MAX_VERTICES] = { false };
    int stack[MAX_VERTICES];
    int stackIndex = -1;

    for (int i = 0; i < graph->numVertices; ++i) {
        if (!visited[i])
            topologicalSortUtil(graph, i, visited, stack, &stackIndex);
    }

    // Print the topological order
    printf("Topological Sorting: ");
    while (stackIndex >= 0)
        printf("%d ", stack[stackIndex--]);
}

int main() {
    Graph* graph = createGraph(MAX_VERTICES);

    // Pre-define edges for demonstration
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    int choice;

    printf("Choose a technique to demonstrate:\n");
    printf("1. DFS\n2. BFS\n3. Topological Sort\n4. Exit\n");

    while (1) {
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("DFS Traversal: ");
                DFS(graph, 0, (bool[MAX_VERTICES]){ false });
                printf("\n");
                break;
            case 2:
                printf("BFS Traversal: ");
                BFS(graph, 0);
                printf("\n");
                break;
            case 3:
                topologicalSort(graph);
                printf("\n");
                break;
            case 4:
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

