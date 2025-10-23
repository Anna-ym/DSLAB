#include<stdio.h>
#include<stdlib.h>

struct node{            //creating the structure of a node
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int value){                         //creating a newnode
    struct node* newnode=(struct node*)malloc(struct node(size));
    newnode->data=value;
    newnode->left=newnode->right=NULL;
    return newnode;
}

struct node* insert(struct node* root,int value){
    if(root==NULL){
        
    }
}