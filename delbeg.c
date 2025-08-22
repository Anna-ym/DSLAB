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
     struct node* deleteatbeg(struct node* head){
        int data;
        struct node* temp=head;
        data=temp->next->data;
        head=head->next->next;
        free(temp->next);
        printf("\n%d removed from list",data);
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
        printlist(head);
       
       
         
          head=insertatbeg(head,value);
        head=deleteatbeg(head);
        
        printf("\nAfter deleting the data:");
        printlist(head);
        
        return 0;
    }
    

