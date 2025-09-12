#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;


int isFull() {
    return (front == (rear + 1) % MAX);
}


int isEmpty() {
    return (front == -1);
}


void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow!\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("%d enqueued.\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("%d dequeued.\n", queue[front]);
    if (front == rear) {
        
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}


void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
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
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
