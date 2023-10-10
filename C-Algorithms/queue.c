// crude operation in queue
//enqueue, dequeue, and traverse the data in queue
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int data);
int dequeue();
void traverse();
int isFull();
int isEmpty();

int main() {
    int choice, data;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
      
  //switch case to choose the choice
        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Queue is full. Cannot enqueue.\n");
                } else {
                    printf("Enter data to enqueue: ");
                    scanf("%d", &data);
                    enqueue(data);
                }
                break;
            case 2:
                if (isEmpty()) {
                    printf("Queue is empty. Cannot dequeue.\n");
                } else {
                    data = dequeue();
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:
                traverse();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
//to enqueue the data  
void enqueue(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = data;
        printf("Enqueued %d\n", data);
    }
}
//to dequeue the data
int dequeue() {
    int data = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return data;
}
//to traverse the data 
void traverse() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
//to check if the queue is full
int isFull() {
    return (rear == MAX_SIZE - 1);
}
//to check the queue is empty
int isEmpty() {
    return (front == -1);
}
