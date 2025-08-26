#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
        /* data */
    };struct node* head=NULL;
    
    struct node* createnode(int value){
        struct node* new=(struct node*)malloc(sizeof(struct node));
        {
            new->data=value;
            new->next=NULL;
            return new;/* data */
        }
    }
    struct node* insertatend(struct node* head,int value){
        struct node* newnode=createnode(value);
        struct node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;}

            temp->next=newnode;
           
    
        return head;
    }
    struct node* deleteatend(struct node* head){
        int data;
        if (head == NULL) {
        printf("\nList is empty, nothing to remove");
        return head;
    }
    if (head->next == NULL) {
        data = head->data;
        free(head);
        printf("\n%d removed from the list", data);
        return NULL;  // Now list is empty
    }
        struct node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        struct node* temp1=temp->next;
        data=temp1->data;
        printf("Last node data before deletion: %d\n", temp->next->data);
        free(temp1);
        temp->next=NULL;
        printf("\n%d removed from the list",data);
        
        return head;
    }
   
    void printlist(struct node* head)
    {
     struct node* temp=head;
     while(temp!=NULL)
     {
        printf("\n%d", temp->data);
        temp=temp->next;
     }
     
    }
    int main()
    {   int n;

        struct node* head=createnode(10);
        head->next=createnode(20);
        head->next->next=createnode(30);
        printlist(head);
       
          //head=insertatend(head,value);

        head=deleteatend(head);
        printf("\nAfter removing the data:");
        printlist(head);
        
        return 0;
    }
    

