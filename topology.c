#include <stdio.h>
#include <stdlib.h>

void topologicalSort(int **graph, int V) {
    int *indegree = (int *)calloc(V, sizeof(int)); 
    int *queue = (int *)malloc(V * sizeof(int));
    int front = 0, rear = -1;
    int *sorted_order = (int *)malloc(V * sizeof(int));
    int count = 0;

  
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 1) {
                
                indegree[j]++;
            }
        }
    }

    
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[++rear] = i; 
        }
    }

    
    while (front <= rear) {
        int u = queue[front++];
        sorted_order[count++] = u;

      
        for (int v = 0; v < V; v++) {
            if (graph[u][v] == 1) {
              
                indegree[v]--;

               
                if (indegree[v] == 0) {
                    queue[++rear] = v;
                }
            }
        }
    }

   
    if (count != V) {
        printf("\nGraph has a cycle. Topological sort is not possible.\n");
    } else {
        printf("\nTopological Order:\n");
        for (int i = 0; i < V; i++) {
            printf("%d ", sorted_order[i]);
        }
        printf("\n");
    }

   
    free(indegree);
    free(queue);
    free(sorted_order);
}

int main() {
    int V, E, u, v;

    printf("Enter number of vertices: ");
    if (scanf("%d", &V) != 1 || V <= 0) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter number of edges: ");
    if (scanf("%d", &E) != 1 || E < 0) {
        printf("Invalid number of edges.\n");
        return 1;
    }

    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)calloc(V, sizeof(int)); 
    }

    printf("Enter the edges (u v) where u is the start and v is the end vertex (0 to %d):\n", V - 1);
    for (int i = 0; i < E; i++) {
        if (scanf("%d %d", &u, &v) != 2 || u < 0 || u >= V || v < 0 || v >= V) {
            printf("Invalid vertex number encountered. Exiting.\n");
           
            for (int j = 0; j < V; j++) {
                free(graph[j]);
            }
            free(graph);
            return 1;
        }
        
       
        graph[u][v] = 1;
    }

  
    topologicalSort(graph, V);
    

    
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}