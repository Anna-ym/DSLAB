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
    struct node* deleteatmid(struct node* head,int pos){
        int data;
        struct node* temp=head;
        for(int i=1;i<pos-1&&temp!=NULL;i++){
            temp=temp->next;
        }
        struct node* temp1=temp->next;
            data=temp1->data;
            temp->next=temp1->next;
            free(temp1);
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
    {   int pos;

        struct node* head=createnode(10);
        head->next=createnode(20);
        head->next->next=createnode(30);
        printlist(head);
       printf("\nEnter the position:");
        scanf("%d",&pos);
       /* printf("\nEnter the element:");
      
          scanf("%d",&value);*/
          //head=insertatmid(head,value,pos);

        
        head=deleteatmid(head,pos);
        printf("\nAfter entering the data:");
        printlist(head);
        
        return 0;
    }
    

