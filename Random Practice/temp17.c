#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the adjacency list for each vertex
struct AdjList {
    struct Node* head;
};

// Structure to represent the graph
struct Graph {
    int V; // Number of vertices
    struct AdjList* array; // Array of adjacency lists
};

// Function to create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists of size V
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is directed, add an edge from dest to src as well
    // newNode = createNode(src);
    // newNode->next = graph->array[dest].head;
    // graph->array[dest].head = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; ++i) {
        struct Node* temp = graph->array[i].head;
        printf("Adjacency list of vertex %d\n", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Driver program to test the above functions
int main() {
    int V, E; // Number of vertices and edges
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    // Create the graph
    struct Graph* graph = createGraph(V);

    // Add edges
    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < E; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // Print the adjacency list representation of the graph
    printGraph(graph);

    return 0;
}
