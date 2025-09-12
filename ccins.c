#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
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
    struct node* insertatbeg(struct node* head,int value){
        struct node* newnode=createnode(value);
        struct node* ptr=head;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        newnode->next=head;
        ptr->next=newnode;
        head=newnode;
        return head;
    }
   
    void printlist(struct node* head)
    {
     struct node* temp=head;
     do
     {
        printf("\n%d", temp->data);
        temp=temp->next;
     }while(temp!=head);
     
    }
    int main()
    {   int n,value;

        struct node* head=createnode(10);
        struct node* first=createnode(20);
        struct node* second=createnode(30);
        head->next=first;
        first->next=second;
        second->next=head;
        printlist(head);
       printf("\nEnter the number of elements:");
        scanf("%d",&n);
        printf("\nEnter the elements:");
        for(int i=0;i<n;i++){
          scanf("%d",&value);
          head=insertatbeg(head,value);

        }
        
        printf("\nAfter entering the data:");
        printlist(head);
        
        return 0;
    }
    

