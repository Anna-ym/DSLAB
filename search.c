#include<stdio.h>
int main(){
    int x,n,i,a[100];
    int flag=1;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\nEnter the element to search:");
    scanf("%d",&x);
    for(i=0;i<n;i++){
    if(a[i]==x){
        flag=1;
        printf("Element found at %d",i);
    }if(!flag){
        printf("Element not found");
    }}

    return 0;
}