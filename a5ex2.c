#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 1000

/* structure to represent a node in the adjacency list */
typedef struct node {
    int dest;
    int weight;
    struct node* next;
} Node;

/* structure to represent the adjacency list */
typedef struct adj_list {
    Node* head;
} AdjList;

/* structure to represent the graph */
typedef struct graph {
    int num_vertices;
    AdjList* array;
} Graph;

/* function to create a new adjacency list node */
Node* createNode(int dest, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

/* function to create a graph with n vertices */
Graph* createGraph(int num_vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->array = (AdjList*)malloc(num_vertices * sizeof(AdjList));
    int i;
    for (i = 0; i < num_vertices; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

/* function to add an edge to the graph */
void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

/* function to free the memory allocated for the graph */
void freeGraph(Graph* graph) {
    int i;
    for (i = 0; i < graph->num_vertices; i++) {
        Node* current = graph->array[i].head;
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->array);
    free(graph);
}

/* function to find the shortest path using Dijkstra's algorithm */
void shortestPath(Graph* graph, int src, int dest) {
    int dist[MAX_VERTICES];     /* array to store the distances */
    bool visited[MAX_VERTICES]; /* array to store whether a vertex has been visited */
    int path[MAX_VERTICES];     /* array to store the path from the source vertex to each vertex */

    /* initialize the arrays */
    int i;
    for (i = 0; i < graph->num_vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        path[i] = -1;
    }

    /* the distance to the source vertex is 0 */
    dist[src] = 0;

    /* loop through all the vertices */
    for (i = 0; i < graph->num_vertices - 1; i++) {
        /* find the vertex with the minimum distance */
        int minDist = INT_MAX;
        int minVertex;
        int j;
        for (j = 0; j < graph->num_vertices; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                minVertex = j;
            }
        }

        /* mark the vertex as visited */
        visited[minVertex] = true;

        /* update the distances of the adjacent vertices */
        Node* current = graph->array[minVertex].head;
        while (current != NULL) {
            int weight = current->weight;
            int destVertex =
