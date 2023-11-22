
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 999999

typedef struct {
    int parent;
    int key;
    bool inMST;
} Vertex;

typedef struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERT//prims algorithm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 999999

typedef struct {
    int parent;
    int key;
    bool inMST;
} Vertex;

typedef struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    Vertex vertices[MAX_VERTICES];
} Graph;

Graph* createGraph(int numVertices) {
    if (numVertices <= 0 || numVertices > MAX_VERTICES) {
        printf("Invalid number of vertices. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; ++i) {
        graph->vertices[i].parent = -1;
        graph->vertices[i].key = INF;
        graph->vertices[i].inMST = false;

        for (int j = 0; j < numVertices; ++j)
            graph->adjacencyMatrix[i][j] = INF;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
        graph->adjacencyMatrix[src][dest] = weight;
        graph->adjacencyMatrix[dest][src] = weight;
    } else {
        printf("Invalid source or destination vertex. Ignoring edge...\n");
    }
}

int findMinKeyVertex(Graph* graph) {
    int minKey = INF;
    int minIndex = -1;

    for (int i = 0; i < graph->numVertices; ++i) {
        if (!graph->vertices[i].inMST && graph->vertices[i].key < minKey) {
            minKey = graph->vertices[i].key;
            minIndex = i;
        }
    }

    return minIndex;
}

void primMST(Graph* graph) {
    graph->vertices[0].key = 0;

    for (int count = 0; count < graph->numVertices - 1; ++count) {
        int u = findMinKeyVertex(graph);
        graph->vertices[u].inMST = true;

        for (int v = 0; v < graph->numVertices; ++v) {
            if (graph->adjacencyMatrix[u][v] != INF && !graph->vertices[v].inMST &&
                graph->adjacencyMatrix[u][v] < graph->vertices[v].key) {
                graph->vertices[v].key = graph->adjacencyMatrix[u][v];
                graph->vertices[v].parent = u;
            }
        }
    }

    printf("Minimum Cost Spanning Tree (Prim's Algorithm):\n");
    for (int i = 1; i < graph->numVertices; ++i)
        printf("Edge: %d - %d, Weight: %d\n", graph->vertices[i].parent, i, graph->vertices[i].key);
}

int main() {
    Graph* graph = createGraph(5);

    // Define edges for demonstration
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);

    primMST(graph);

    return 0;
}ICES][MAX_VERTICES];
    Vertex vertices[MAX_VERTICES];
} Graph;

Graph* createGraph(int numVertices) {
    if (numVertices <= 0 || numVertices > MAX_VERTICES) {
        printf("Invalid number of vertices. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; ++i) {
        graph->vertices[i].parent = -1;
        graph->vertices[i].key = INF;
        graph->vertices[i].inMST = false;

        for (int j = 0; j < numVertices; ++j)
            graph->adjacencyMatrix[i][j] = INF;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
        graph->adjacencyMatrix[src][dest] = weight;
        graph->adjacencyMatrix[dest][src] = weight;
    } else {
        printf("Invalid source or destination vertex. Ignoring edge...\n");
    }
}

int findMinKeyVertex(Graph* graph) {
    int minKey = INF;
    int minIndex = -1;

    for (int i = 0; i < graph->numVertices; ++i) {
        if (!graph->vertices[i].inMST && graph->vertices[i].key < minKey) {
            minKey = graph->vertices[i].key;
            minIndex = i;
        }
    }

    return minIndex;
}

void primMST(Graph* graph) {
    graph->vertices[0].key = 0;

    for (int count = 0; count < graph->numVertices - 1; ++count) {
        int u = findMinKeyVertex(graph);
        graph->vertices[u].inMST = true;

        for (int v = 0; v < graph->numVertices; ++v) {
            if (graph->adjacencyMatrix[u][v] != INF && !graph->vertices[v].inMST &&
                graph->adjacencyMatrix[u][v] < graph->vertices[v].key) {
                graph->vertices[v].key = graph->adjacencyMatrix[u][v];
                graph->vertices[v].parent = u;
            }
        }
    }

    printf("Minimum Cost Spanning Tree (Prim's Algorithm):\n");
    for (int i = 1; i < graph->numVertices; ++i)
        printf("Edge: %d - %d, Weight: %d\n", graph->vertices[i].parent, i, graph->vertices[i].key);
}

int main() {
    Graph* graph = createGraph(5);

    // Define edges for demonstration
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);

    primMST(graph);

    return 0;
}

