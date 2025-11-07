#include <stdio.h>
#define INF 9999999  
#define MAX 10       

int main() {
    int n;  // number of vertices
    int cost[MAX][MAX]; // adjacency matrix
    int visited[MAX] = {0}; // to keep track of visited vertices
    int edges = 0; // number of edges in MST
    int min, a, b;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF; // replace 0 with infinity (no connection)
        }
    }

    // start from the first vertex
    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        min = INF;
        a = -1;
        b = -1;

        // Find the smallest edge connecting visited and unvisited vertex
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (a != -1 && b != -1) {
            printf("%d -> %d  (Cost: %d)\n", a, b, min);
            totalCost += min;
            visited[b] = 1;
            edges++;
        }
    }

    printf("\nTotal cost of Minimum Spanning Tree = %d\n", totalCost);

    return 0;
}
