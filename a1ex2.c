#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main()
{
    // create a linked list with three nodes
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    scanf("%d",&head->data);
    head->next = (struct Node*) malloc(sizeof(struct Node));
    scanf("%d",&head->next->data);
    head->next->next = (struct Node*) malloc(sizeof(struct Node));
    scanf("%d",&head->next->next->data);
    head->next->next->next = NULL;

    // traverse the linked list and print its contents
    printf("Linked List: ");
    printList(head);

    return 0;
}
void printList(struct Node* head)
{
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}
