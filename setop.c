#include <stdio.h>

int findIndex(int element, int Uset[], int size) {
    for (int i = 0; i < size; i++) {
        if (Uset[i] == element)
            return i;
    }
    return -1;                                                                                                                
}                                                                     
                                                                  
int main() {                                                    
    int Uset[100]; 
    int Fset[50], Sset[50];
    int bitFset[100] = {0}; 
    int bitSset[100] = {0}; 
    int Uoset[200] = {0};
    int Ioset[200] = {0};
    int Doset[200] = {0};
    int Soset[200] = {0};
    int C1oset[200] = {0};
    int C2oset[200] = {0};
    int i, j, m, n, p;

  
    printf("Enter the number of elements in the Universal set: ");
    scanf("%d", &m);
    if (m > 100 || m < 1) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d unique elements:\n", m);
    for (i = 0; i < m; i++) {
        scanf("%d", &Uset[i]);
    }

    
    printf("Enter the number of elements in the first subset: ");
    scanf("%d", &n);
    if (n > 50 || n < 1) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d unique elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &Fset[i]);
    }


    printf("Enter the number of elements in the second subset: ");
    scanf("%d", &p);
    if (p > 50 || p < 1) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d unique elements:\n", p);
    for (i = 0; i < p; i++) {
        scanf("%d", &Sset[i]);
    }


    for (i = 0; i < n; i++) {
        int index = findIndex(Fset[i], Uset, m);
        if (index != -1) {
            bitFset[index] = 1;
        }
    }

    
    for (i = 0; i < p; i++) {
        int index = findIndex(Sset[i], Uset, m);
        if (index != -1) {
            bitSset[index] = 1;
        }
    }

  
    printf("\nUniversal Set: { ");
    for (i = 0; i < m; i++)
        printf("%d ", Uset[i]);
    printf("}\n");

    printf("First Subset: { ");
    for (i = 0; i < n; i++)
        printf("%d ", Fset[i]);
    printf("}\n");

    printf("Second Subset: { ");
    for (i = 0; i < p; i++)
        printf("%d ", Sset[i]);
    printf("}\n");

    printf("\nBit String of First Subset: ");
    for (i = 0; i < m; i++)
        printf("%d", bitFset[i]);
    printf("\n");

    printf("Bit String of Second Subset: ");
    for (i = 0; i < m; i++)
        printf("%d", bitSset[i]);
    printf("\n");

    for (i = 0; i < m; i++) 
        Uoset[i] = bitFset[i] | bitSset[i];
    for(i=0;i<m;i++)
        Ioset[i] = bitFset[i] & bitSset[i];
    for (i = 0; i < m; i++) 
        Doset[i] = bitFset[i] & (!bitSset[i]);
    for (i = 0; i < m; i++) 
        Soset[i] = (bitFset[i] & (!bitSset[i])) | (!bitFset[i] & (bitSset[i]));
    for (i = 0; i < m; i++) 
        C1oset[i] = !(bitFset[i]) ;
    for (i = 0; i < m; i++) 
        C2oset[i] = !(bitSset[i]) ;

    printf("Union Operation: ");
    for(i = 0; i < m; i++)
        printf("%d", Uoset[i]);
    printf("\n");

    printf("Intersection Operation: ");
    for(i = 0; i < m; i++)
        printf("%d", Ioset[i]);
    printf("\n");

    printf("Relative difference Operation: ");
    for(i = 0; i < m; i++)
        printf("%d", Doset[i]);
    printf("\n");

    printf("Symmetric difference Operation: ");
    for(i = 0; i < m; i++)
        printf("%d", Soset[i]);
    printf("\n");

    printf("Complement Operation on First Set: ");
    for(i = 0; i < m; i++)
        printf("%d", C1oset[i]);
    printf("\n");

    printf("Complement Operation on Second Set: ");
    for(i = 0; i < m; i++)
        printf("%d", C2oset[i]);
    printf("\n");

    return 0;
}
