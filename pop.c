#include<stdio.h>
#define MAX 100
int top=-1;
int stack[MAX],n,value,data,p;
void push(int value){
    if(top==MAX-1)
    {
        printf("Stack overflow");

    }else{
        top++;
        stack[top]=value;
        printf("%d is added to the top",value);
    }}

void pop(){
    if(top==-1){
        printf("Stack Underflow");
    }
    else{
        data=stack[top];
        top--;
        printf("\n%d removed from the stack",data);
        
    }

}void display(){
            for(int i=top;i>=0;i--){
                printf("\n%d",stack[i]);}}
int main(){
    int n,value;
        printf("Enter number of elements:");
        scanf("%d",&n);
        printf("Enter elements to stack");
        for(int i=0;i<n;i++){
            scanf("%d",&value);
            push(value);

        }
    
        pop();
    
    display();
    return 0;
}
