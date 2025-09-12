#include <stdio.h>

int main() {
    int n, arr[100], val, i, pos;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to delete: ");
    scanf("%d", &val);

 
    for(i = 0; i < n; i++) {
        if(arr[i] == val) {
            pos = i;
            printf("Deletion done at %d\n",pos);
            break;
        }
    }

    if(pos == -1) {
        printf("Value %d not found in the array.\n", val);
    } else {
        
        for(i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--; 

        printf("Array after deletion:\n");
        for(i = 0; i < n; i++) {
            printf("%d\n", arr[i]);
        }
    }

    return 0;
}
