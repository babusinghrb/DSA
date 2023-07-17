#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to find the minimum value node in a BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Function to delete a node from BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node to be deleted found

        // Case 1: Node with no child or only one child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node with two children
        struct Node* minValue = minValueNode(root->right);
        root->data = minValue->data;
        root->right = deleteNode(root->right, minValue->data);
    }

    return root;
}

// Function to perform inorder traversal of BST
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to free memory allocated for the tree
void freeMemory(struct Node* root) {
    if (root == NULL) {
        return;
    }

    freeMemory(root->left);
    freeMemory(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Inorder traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("Enter the value to delete: ");
                                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                // Free memory and exit the program
                freeMemory(root);
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}


