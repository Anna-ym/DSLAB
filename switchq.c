#include<stdio.h>
#define MAX 100
int queue[MAX],n,value,front=-1,rear=-1,data;
void enqueue(value){
    if(rear==MAX-1){
        printf("Stack overflow");
    }else{
        rear++;
        queue[rear]=value;
        printf("%d is added to queue",value);
    }
    


}
void display(){
    for(int i=front+1;i<=rear;i++){
        printf("\n%d",queue[i]);
    }
}
void dequeue(){
    if((front==-1)&&(rear==-1)){
        printf("Queue underflow");
    }else{
        front++;
        data=queue[front];
        
        printf("\n%d removed from queue",data);
       
    }
}
int main(){
    int ch;
    do{
printf("CHOICES \n 1.ENQUEUE \n 2.DEQUEUE \n 3.DISPLAY \n 4.EXIT");
printf("Enter your choice:");
scanf("%d",&ch);

switch(ch){
    case 1:int n,value;
        printf("Enter number of elements:");
        scanf("%d",&n);
         printf("Enter the elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        enqueue(value);

    }
        break;
    case 2:dequeue();
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
