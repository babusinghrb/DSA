//Maximum Clique Problem

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct node {
    int vertex;
    struct node* next;
} Node;

typedef struct graph {
    Node* edges[MAX_VERTICES];
    int num_vertices;
    int num_edges;
} Graph;

int add_vertex(Graph* g) {
    if (g->num_vertices < MAX_VERTICES) {
        g->edges[g->num_vertices] = NULL;
        g->num_vertices++;
        return 1;
    }
    return 0;
}

void add_edge(Graph* g, int src, int dest) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->vertex = dest;
    new_node->next = g->edges[src];
    g->edges[src] = new_node;
    g->num_edges++;
}

void print_graph(Graph* g) {
    printf("Graph with %d vertices and %d edges:\n", g->num_vertices, g->num_edges);
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d:", i);
        Node* curr = g->edges[i];
        while (curr != NULL) {
            printf(" %d", curr->vertex);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    g.num_vertices = 0;
    g.num_edges = 0;

    printf("Enter the number of vertices in the graph (maximum %d): ", MAX_VERTICES);
    int num_vertices;
    scanf("%d", &num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        if (!add_vertex(&g)) {
            printf("Maximum number of vertices reached.\n");
            return 0;
        }
    }

    printf("Enter the number of edges in the graph: ");
    int num_edges;
    scanf("%d", &num_edges);

    for (int i = 0; i < num_edges; i++) {
        printf("Enter the source and destination vertices for edge %d: ", i + 1);
        int src, dest;
        scanf("%d %d", &src, &dest);
        if (src >= num_vertices || dest >= num_vertices) {
            printf("Invalid vertex number. Edge not added.\n");
        } else {
            add_edge(&g, src, dest);
            add_edge(&g, dest, src);
        }
    }

    print_graph(&g);

    return 0;
}
