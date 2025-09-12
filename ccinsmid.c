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
    struct node* insertatmid(struct node* head,int value,int pos){
        struct node* newnode=createnode(value);
        struct node* temp=head;
        for(int i=1;i<pos-1&&temp!=NULL;i++){
            temp=temp->next;}
            newnode->next=temp->next;
            temp->next=newnode;
            
           
    
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
    {   int pos,value;

        struct node* head=createnode(10);
        struct node* first=createnode(20);
        struct node* second=createnode(30);
        head->next=first;
        first->next=second;
        second->next=head;
        printlist(head);
       printf("\nEnter the position:");
        scanf("%d",&pos);
        printf("\nEnter the element:");
      
          scanf("%d",&value);
          head=insertatmid(head,value,pos);

        
        
        printf("\nAfter entering the data:");
        printlist(head);
        
        return 0;
    }
    

