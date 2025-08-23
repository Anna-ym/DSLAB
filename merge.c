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
        newnode->next=head;
        head=newnode;
        return newnode;
    }
    struct node* mergelist(struct node* head, struct node* head1)
    {
       struct node* temp=head;
     while(temp->next!=NULL)
     {
        temp=temp->next;
     }
        temp->next=head1; 
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
    {   int n,value;

        struct node* head=createnode(10);
        head->next=createnode(20);
        head->next->next=createnode(30);

        struct node* head1=createnode(40);
        head1->next=createnode(50);
        head1->next->next=createnode(60);

       // head=insertatbeg(head,value);
        printf("\nfirst list");
        printlist(head);

       // head1=insertatbeg(head1,value);
        printf("\nsecond list");
        printlist(head1);
        head=mergelist(head,head1);
        printf("\nafter merging");
        printlist(head);
        return 0;
    }
    

