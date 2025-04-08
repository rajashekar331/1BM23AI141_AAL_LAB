#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#define V 5  
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, minIndex;
    
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(int graph[V][V]) {
    int parent[V]; 
    int key[V];     
    int mstSet[V]; 
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[0] = 0;  
    parent[0] = -1;  
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet processed
        int u = minKey(key, mstSet);

        // Include the picked vertex in the MST
        mstSet[u] = 1;

        // Update the key and parent values of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update the key value if graph[u][v] is smaller and vertex v is not included in MST
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    printf("\nMinimum Spanning Tree (MST) Edges:\n");
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%c - %c \t%d\n", parent[i] + 'A', i + 'A', graph[i][parent[i]]);
    }
    printf("\nGraphical Representation of MST:\n");
    printf("\n       2\n");
    printf("   A -------- B\n");
    if (parent[1] == 0) {
        printf("   | \n  3| \n   | \n");
    }
    if (parent[3] == 0) {
        printf("   D -------- C\n");
    }
    if (parent[4] == 3) {
        printf("       5     |\n");
        printf("              |\n");
        printf("              E\n");
    }
    if (parent[2] == 3) {
        printf("       4     |\n");
    }
}
int main() {
    int graph[V][V] = {
        {0, 2, 0, 3, 0},
        {2, 0, 7, 0, 0},
        {0, 7, 0, 4, 5},
        {3, 0, 4, 0, 0},
        {0, 0, 5, 0, 0}
    };
    primMST(graph);  
    return 0;
}


