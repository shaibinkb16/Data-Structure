
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjList[MAX_VERTICES];
    Node* revAdjList[MAX_VERTICES];
    int numVertices;
} Graph;

Graph* createGraph(int numVertices) {
    if (numVertices <= 0 || numVertices > MAX_VERTICES) {
        printf("Invalid number of vertices. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; ++i) {
        graph->adjList[i] = NULL;
        graph->revAdjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    if (src < 0 || src >= graph->numVertices || dest < 0 || dest >= graph->numVertices) {
        printf("Invalid source or destination vertex. Ignoring edge...\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Reverse graph for Kosaraju's algorithm
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->revAdjList[dest];
    graph->revAdjList[dest] = newNode;
}

void DFSUtil(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    Node* adjNode = graph->adjList[vertex];
    while (adjNode != NULL) {
        int adjVertex = adjNode->vertex;
        if (!visited[adjVertex])
            DFSUtil(graph, adjVertex, visited);
        adjNode = adjNode->next;
    }
}

void fillOrder(Graph* graph, int vertex, bool visited[], int stack[], int* stackIndex) {
    visited[vertex] = true;

    Node* adjNode = graph->revAdjList[vertex];
    while (adjNode != NULL) {
        int adjVertex = adjNode->vertex;
        if (!visited[adjVertex])
            fillOrder(graph, adjVertex, visited, stack, stackIndex);
        adjNode = adjNode->next;
    }

    stack[++(*stackIndex)] = vertex;
}

Graph* getTranspose(Graph* graph) {
    Graph* transposedGraph = createGraph(graph->numVertices);

    for (int i = 0; i < graph->numVertices; ++i) {
        Node* current = graph->adjList[i];
        while (current != NULL) {
            addEdge(transposedGraph, current->vertex, i);
            current = current->next;
        }
    }

    return transposedGraph;
}

void printSCCs(Graph* graph) {
    int stack[MAX_VERTICES];
    int stackIndex = -1;

    bool visited[MAX_VERTICES] = { false };
    for (int i = 0; i < graph->numVertices; ++i) {
        if (!visited[i])
            fillOrder(graph, i, visited, stack, &stackIndex);
    }

    Graph* transposedGraph = getTranspose(graph);

    for (int i = 0; i < graph->numVertices; ++i)
        visited[i] = false;

    while (stackIndex >= 0) {
        int vertex = stack[stackIndex--];
        if (!visited[vertex]) {
            DFSUtil(transposedGraph, vertex, visited);
            printf("\n");
        }
    }

    free(transposedGraph);
}

int main() {
    Graph* graph = createGraph(8);

    // Define edges for demonstration
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 3);
    addEdge(graph, 6, 5);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 6);

    printf("Strongly Connected Components:\n");
    printSCCs(graph);

    return 0;
}

