#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Stack data structure
struct Stack {
    int items[MAX_VERTICES];
    int top;
};

// Graph data structure
struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
};

// Initialize the graph
void initGraph(struct Graph* graph, int numVertices) {
    graph->numVertices = numVertices;

    int i, j;
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// Push an item onto the stack
void push(struct Stack* stack, int item) {
    stack->top++;
    stack->items[stack->top] = item;
}

// Pop an item from the stack
int pop(struct Stack* stack) {
    int item = stack->items[stack->top];
    stack->top--;
    return item;
}

// Check if the stack is empty
bool isStackEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Depth-First Search algorithm
void dfs(struct Graph* graph, int startVertex) {
    // Initialize visited array
    bool visited[MAX_VERTICES];
    int i;
    for (i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }

    // Create a stack
    struct Stack stack;
    stack.top = -1;

    // Push the start vertex onto the stack
    push(&stack, startVertex);

    printf("DFS traversal: ");

    while (!isStackEmpty(&stack)) {
        // Pop a vertex from the stack
        int currentVertex = pop(&stack);

        // Skip if the vertex has already been visited
        if (visited[currentVertex])
            continue;

        // Mark the current vertex as visited
        visited[currentVertex] = true;
        printf("%d ", currentVertex);

        // Push unvisited adjacent vertices onto the stack
        for (i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                push(&stack, i);
            }
        }
    }

    printf("\n");
}

// Display the graph visually
void displayGraph(struct Graph* graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjMatrix[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Display the adjacency matrix of the graph
void displayAdjacencyMatrix(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Graph graph;
    int numVertices, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    initGraph(&graph, numVertices);

    // Add edges between vertices
    printf("Enter the edges (vertex pairs) (e.g., 0 1): (-1 -1 to stop)\n");
    while (true) {
        scanf("%d %d", &i, &j);
        if (i == -1 && j == -1)
            break;
        addEdge(&graph, i, j);
    }

    // Display the graph
    displayGraph(&graph);

    // Display the adjacency matrix
    displayAdjacencyMatrix(&graph);

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    dfs(&graph, startVertex);

    return 0;
}
