#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Node with data %d inserted at the beginning.\n", data);
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    printf("Node with data %d inserted at the end.\n", data);
}

// Function to delete a node with a given value
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with data %d not found. Cannot delete.\n", data);
        return;
    }
    if (prev == NULL) {
        *head = current->next;
        if (current->next != NULL) {
            current->next->prev = NULL;
        }
    } else {
        prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = prev;
        }
    }
    free(current);
    printf("Node with data %d deleted.\n", data);
}

// Function to search for a node with a given value
void searchNode(struct Node* head, int data) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            printf("Node with data %d found.\n", data);
            return;
        }
        current = current->next;
    }
    printf("Node with data %d not found.\n", data);
}

// Function to traverse and print the list in both directions
void traverseList(struct Node* head) {
    struct Node* current = head;
    printf("Doubly Linked List (Forward): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    printf("Doubly Linked List (Backward): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);

    traverseList(head);

    searchNode(head, 20);

    deleteNode(&head, 20);

    traverseList(head);

    return 0;
}
