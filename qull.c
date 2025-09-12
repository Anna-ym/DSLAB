#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};


struct node* front = NULL;
struct node* rear = NULL;


int isEmpty() {
    return front == NULL;
}

void enqueue(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (rear == NULL) {
        
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("Enqueued %d\n", value);
}


void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    struct node* temp = front;
    printf("Dequeued %d\n", temp->data);
    front = front->next;

    if (front == NULL) {
       
        rear = NULL;
    }
    free(temp);
}




void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    struct node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                 scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
