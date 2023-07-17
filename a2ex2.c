#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

// Structure for a heap node
typedef struct heap_node {
    int data;
} HeapNode;

// Structure for a heap
typedef struct heap {
    HeapNode* nodes[MAX_HEAP_SIZE];
    int count;
} Heap;

// Function to create a new heap node
HeapNode* create_heap_node(int data) {
    HeapNode* node = (HeapNode*) malloc(sizeof(HeapNode));
    node->data = data;
    return node;
}

// Function to swap two heap nodes
void swap_heap_nodes(HeapNode** a, HeapNode** b) {
    HeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive function to maintain the heap property after inserting a new node
void heapify_up(Heap* heap, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && heap->nodes[index]->data > heap->nodes[parent]->data) {
        swap_heap_nodes(&heap->nodes[index], &heap->nodes[parent]);
        heapify_up(heap, parent);
    }
}

// Recursive function to maintain the heap property after removing the root node
void heapify_down(Heap* heap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;
    if (left < heap->count && heap->nodes[left]->data > heap->nodes[largest]->data) {
        largest = left;
    }
    if (right < heap->count && heap->nodes[right]->data > heap->nodes[largest]->data) {
        largest = right;
    }
    if (largest != index) {
        swap_heap_nodes(&heap->nodes[index], &heap->nodes[largest]);
        heapify_down(heap, largest);
    }
}

// Function to insert a new node into the heap
void insert_heap_node(Heap* heap, int data) {
    if (heap->count < MAX_HEAP_SIZE) {
        HeapNode* node = create_heap_node(data);
        heap->nodes[heap->count++] = node;
        heapify_up(heap, heap->count - 1);
    }
}

// Function to remove the root node from the heap
void remove_root_node(Heap* heap) {
    if (heap->count > 0) {
        heap->nodes[0] = heap->nodes[--heap->count];
        heapify_down(heap, 0);
    }
}

// Function to print the heap
void print_heap(Heap* heap, int index, int level) {
    if (index < heap->count) {
        print_heap(heap, 2 * index + 2, level + 1);
        for (int i = 0; i < level; i++) {
            printf("  ");
        }
        printf("%d\n", heap->nodes[index]->data);
        print_heap(heap, 2 * index + 1, level + 1);
    }
}

int main() {
    Heap heap = {0};
    int num_nodes;
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &num_nodes);
    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < num_nodes; i++) {
        int data;
        scanf("%d", &data);
        insert_heap_node(&heap, data);
    }
    printf("The final heap is:\n");
    print_heap(&heap, 0, 0);
    return 0;
}
