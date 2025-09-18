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

struct node* deleteatend(struct node* head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }

    // Only one node
    if (head->next == head) {
        free(head);
        return NULL;
    }

    struct node* temp = head;
    struct node* prev = NULL;

    // Traverse to last node (where temp->next == head)
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    // 'temp' is last node, 'prev' is second last
    prev->next = head;
    free(temp);

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
    int n, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertatend(head, value);
    }

    printf("Original list:\n");
    printlist(head);

    head = deleteatend(head);

    printf("After deleting the last node:\n");
    printlist(head);

    return 0;
}
