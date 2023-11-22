//single source shortest path
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTICES 5
#define MAX_DISTANCE 50  // Adjust this based on the expected maximum distance between nodes

typedef struct {
    int vertex, distance;
} Node;

typedef struct {
    Node* heap;
    int capacity, size;
} MinHeap;

typedef struct {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph* createGraph(int numVertices) {
    if (numVertices <= 0 || numVertices > MAX_VERTICES) {
        printf("Invalid number of vertices. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (i == j) {
                graph->adjacencyMatrix[i][j] = 0; // Distance from a vertex to itself is 0
            } else {
                graph->adjacencyMatrix[i][j] = rand() % MAX_DISTANCE + 1; // Random distance between 1 and MAX_DISTANCE
            }
        }
    }

    return graph;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->heap = (Node*)malloc(capacity * sizeof(Node));
    return heap;
}

void swap(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->heap[left].distance < heap->heap[smallest].distance)
        smallest = left;

    if (right < heap->size && heap->heap[right].distance < heap->heap[smallest].distance)
        smallest = right;

    if (smallest != idx) {
        swap(&heap->heap[idx], &heap->heap[smallest]);
        minHeapify(heap, smallest);
    }
}

bool isEmpty(MinHeap* heap) {
    return heap->size == 0;
}

Node extractMin(MinHeap* heap) {
    if (isEmpty(heap))
        exit(EXIT_FAILURE);

    Node root = heap->heap[0];
    heap->heap[0] = heap->heap[heap->size - 1];
    heap->size--;

    minHeapify(heap, 0);

    return root;
}

void decreaseKey(MinHeap* heap, int vertex, int distance) {
    int i;
    for (i = 0; i < heap->size; ++i) {
        if (heap->heap[i].vertex == vertex) {
            heap->heap[i].distance = distance;
            break;
        }
    }

    while (i != 0 && heap->heap[i].distance < heap->heap[(i - 1) / 2].distance) {
        swap(&heap->heap[i], &heap->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void dijkstra(Graph* graph, int src, int dest) {
    MinHeap* heap = createMinHeap(graph->numVertices);
    Node* result = (Node*)malloc(graph->numVertices * sizeof(Node));

    for (int i = 0; i < graph->numVertices; ++i) {
        heap->heap[i].vertex = i;
        heap->heap[i].distance = MAX_DISTANCE * graph->numVertices + 1; // A value larger than the sum of all possible distances
        result[i].vertex = -1;
        result[i].distance = MAX_DISTANCE * graph->numVertices + 1;
    }

    heap->heap[src].distance = 0;
    result[src].distance = 0;

    clock_t start_time = clock();

    while (!isEmpty(heap)) {
        Node current = extractMin(heap);
        int u = current.vertex;

        for (int v = 0; v < graph->numVertices; ++v) {
            if (graph->adjacencyMatrix[u][v] != 0) { // Consider only non-zero distances
                int alt = result[u].distance + graph->adjacencyMatrix[u][v];
                if (alt < result[v].distance) {
                    result[v].distance = alt;
                    result[v].vertex = u;
                    decreaseKey(heap, v, alt);
                }
            }
        }
    }

    clock_t end_time = clock();
    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Paths from source %d to destination %d:\n", src, dest);
    printf("Shortest Distance: %d\n", result[dest].distance);
    printf("Execution Time: %f seconds\n", execution_time);
    printf("Path: ");

    int temp = dest;
    while (temp != -1) {
        printf("%d ", temp);
        temp = result[temp].vertex;
    }
    printf("\n");

    printf("All Paths Traversed:\n");
    for (int i = 0; i < graph->numVertices; ++i) {
        if (i == src) continue;
        printf("To vertex %d: Distance = %d, Path = ", i, result[i].distance);
        temp = i;
        while (temp != -1) {
            printf("%d ", temp);
            temp = result[temp].vertex;
        }
        printf("\n");
    }

    free(heap->heap);
    free(heap);
    free(result);
}

int main() {
    srand(time(NULL));

    Graph* graph = createGraph(5);

    printf("Random Distance Matrix:\n");
    for (int i = 0; i < graph->numVertices; ++i) {
        for (int j = 0; j < graph->numVertices; ++j) {
            printf("%2d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    int sourceVertex, destVertex;
    printf("\nEnter source vertex (0-%d): ", graph->numVertices - 1);
    scanf("%d", &sourceVertex);

    printf("Enter destination vertex (0-%d): ", graph->numVertices - 1);
    scanf("%d", &destVertex);

    if (sourceVertex < 0 || sourceVertex >= graph->numVertices ||
        destVertex < 0 || destVertex >= graph->numVertices) {
        printf("Invalid source or destination vertex. Exiting...\n");
        return EXIT_FAILURE;
    }

    dijkstra(graph, sourceVertex, destVertex);

    free(graph);

    return 0;
}
