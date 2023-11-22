//kruskals algorithm
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct {
    int parent, rank;
} Subset;

typedef struct {
    int numVertices, numEdges;
    Edge edges[MAX_VERTICES * MAX_VERTICES];
} Graph;

Graph* createGraph(int numVertices, int numEdges) {
    if (numVertices <= 0 || numVertices > MAX_VERTICES || numEdges <= 0 || numEdges > MAX_VERTICES * MAX_VERTICES) {
        printf("Invalid number of vertices or edges. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;

    return graph;
}

void addEdge(Graph* graph, int index, int src, int dest, int weight) {
    if (index >= 0 && index < graph->numEdges && src >= 0 && src < graph->numVertices &&
        dest >= 0 && dest < graph->numVertices) {
        graph->edges[index].src = src;
        graph->edges[index].dest = dest;
        graph->edges[index].weight = weight;
    } else {
        printf("Invalid edge information. Exiting...\n");
        exit(EXIT_FAILURE);
    }
}

int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void kruskalMST(Graph* graph) {
    Edge result[graph->numVertices];
    int e = 0;
    int i = 0;

    qsort(graph->edges, graph->numEdges, sizeof(graph->edges[0]), compareEdges);

    Subset subsets[graph->numVertices];
    for (i = 0; i < graph->numVertices; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    i = 0;
    while (e < graph->numVertices - 1 && i < graph->numEdges) {
        Edge nextEdge = graph->edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    printf("Minimum Cost Spanning Tree (Kruskal's Algorithm):\n");
    for (i = 0; i < e; ++i)
        printf("Edge: %d - %d, Weight: %d\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    Graph* graph = createGraph(4, 5);

    // Define edges for demonstration
    addEdge(graph, 0, 0, 1, 10);
    addEdge(graph, 1, 0, 2, 6);
    addEdge(graph, 2, 0, 3, 5);
    addEdge(graph, 3, 1, 3, 15);
    addEdge(graph, 4, 2, 3, 4);

    kruskalMST(graph);

    return 0;
}
