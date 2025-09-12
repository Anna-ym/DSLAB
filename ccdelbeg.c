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
    struct node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    return head;
}


struct node* deleteatbeg(struct node* head) {
    
    struct node* temp = head;
    struct node* ptr = head;


    while (ptr->next != head) {
        ptr = ptr->next;
    }

    head = head->next;
    ptr->next = head;
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
    for (int i=0; i<n; i++) {
        scanf("%d", &value);}
        head = insertatend(head, value);
    printlist(head);

    head = deleteatbeg(head);

    printf("After deleting the first node:\n");
    printlist(head);

    return 0;
}
