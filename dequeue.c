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
     int n,value;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        enqueue(value);

    }
    display();
    dequeue();
    display();
return 0;
}