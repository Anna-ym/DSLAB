#include<stdio.h>
 #define MAX 100
int top=-1;
int stack[MAX],n,value,data;
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
int n,value,ch;
do{
printf("CHOICES \n 1.PUSH \n 2.POP \n 3.DISPLAY \n 4.EXIT");
printf("Enter your choice:");
scanf("%d",&ch);

switch(ch){
    case 1:int n,value;
        printf("Enter number of elements:");
        scanf("%d",&n);
        printf("Enter elements to stack");
        for(int i=0;i<n;i++){
            scanf("%d",&value);
            push(value);

        }
        break;
    case 2:pop();
    break;
    case 3:display();
    break;
    case 4:
    break;
    default:printf("Invalid choice");
    break;
           
}
}while(ch<=4);
return 0;
}