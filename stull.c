#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};


struct node* top = NULL;


void push(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    
    
    newnode->data = value;
    newnode->next = top;
    top = newnode;
    printf("Pushed %d\n", value);
}


void pop() {
   
    struct node* temp = top;
    printf("Popped %d\n", temp->data);
    top = top->next;
    free(temp);
}


void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int choice, value;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
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

