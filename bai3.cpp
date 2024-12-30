#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define V 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
Node* adjList[V];

bool visited[V];

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = u;
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void DFS(int vertex) {
    visited[vertex] = true;
    Node* temp = adjList[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(adjVertex);
        }
        temp = temp->next;
    }
}

bool isConnected(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    DFS(0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, edges, u, v;
    printf("Nhap vao so dinh: ");
    scanf("%d", &n);
    printf("Nhap vao so canh: ");
    scanf("%d", &edges);
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
        visited[i] = false;
    }
    printf("Nhap vao danh sach canh (u v):");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    if (isConnected(n)) {
        printf("Do thi lien thong\n");
    } else {
        printf("Do thi khong lien thong\n");
    }
    return 0;
}
