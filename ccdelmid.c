#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int value) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = value;
    new->next = NULL;
    return new;
}

struct node* insertatend(struct node* head, int value) {
    struct node* newnode = createnode(value);
    if (head == NULL) {
        newnode->next = newnode; // Point to itself
        return newnode;
    }
    struct node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    return head;
}

struct node* deleteatpos(struct node* head, int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    // Count nodes
    int count = 1;
    struct node* temp = head;
    while (temp->next != head) {
        count++;
        temp = temp->next;
    }

    if (pos < 1 || pos > count) {
        printf("Invalid position.\n");
        return head;
    }

    // Deleting the first node (position 1)
    if (pos == 1) {
        // If only one node
        if (head->next == head) {
            free(head);
            return NULL;
        }
        // More than one node
        struct node* last = head;
        while (last->next != head)
            last = last->next;
        struct node* todelete = head;
        head = head->next;
        last->next = head;
        free(todelete);
        return head;
    }

    // Delete node other than first
    struct node* current = head;
    struct node* prev = NULL;
    for (int i = 1; i < pos; i++) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);

    return head;
}

void printlist(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int n, value, pos;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertatend(head, value);
    }

    printf("Original list:\n");
    printlist(head);

    printf("Enter position to delete: ");
    scanf("%d", &pos);
    head = deleteatpos(head, pos);

    printf("After deleting node at position %d:\n", pos);
    printlist(head);

    return 0;
}
