#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 100
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
Node* adjList[MAX_VERTICES];
bool visited[MAX_VERTICES];
int stack[MAX_VERTICES];
int top = -1;
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
}
void topologicalSortUtil(int v) {
    visited[v] = true;
    Node* temp = adjList[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            topologicalSortUtil(temp->vertex);
        }
        temp = temp->next;
    }
    stack[++top] = v;
}
void topologicalSort(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i);
        }
    }
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}
int main() {
    int V = 6;
    int edges[][2] = {
        {2, 3}, {3, 1}, {4, 0}, {4, 1}, {5, 0}, {5, 2}
    };
    int E = sizeof(edges) / sizeof(edges[0]);
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = false;
    }
    for (int i = 0; i < E; i++) {
        addEdge(edges[i][0], edges[i][1]);
    }
    topologicalSort(V);
    return 0;
}

#output
text
5 4 2 3 1 0

