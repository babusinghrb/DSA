//Merge Sort

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertAtEnd(struct node** head, int data)
{
    struct node* temp = *head;
    if (*head == NULL)
    {
        *head = newNode(data);
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode(data);
}

void printList(struct node* head)
{
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node* getMiddle(struct node* head)
{
    struct node* slow = head;
    struct node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct node* binarySearch(struct node* head, int key)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct node* middle = getMiddle(head);
    if (middle->data == key)
    {
        return middle;
    }
    else if (middle->data > key)
    {
        return binarySearch(head, key);
    }
    else {
        return binarySearch(middle->next, key);
    }
}

int main()
{
    int n, key;
    struct node* head = NULL;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &key);
    struct node* result = binarySearch(head, key);
    if (result == NULL) {
        printf("Element not found\n");
    }
    else {
        printf("Element found at index %d\n", result->data);
    }
    return 0;
}
