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
bool recStack[V];

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

bool isCyclicUtil(int vertex) {
    if (!visited[vertex]) {
        visited[vertex] = true;
        recStack[vertex] = true;
        Node* temp = adjList[vertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex] && isCyclicUtil(adjVertex)) {
                return true;
            } else if (recStack[adjVertex]) {
                return true;
            }
            temp = temp->next;
        }
    }
    recStack[vertex] = false;
    return false;
}

bool isCyclic(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        recStack[i] = false;
    }
    for (int i = 0; i < n; i++) {
        if (isCyclicUtil(i)) {
            return true;
        }
    }
    return false;
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
        recStack[i] = false;
    }
    printf("Nhap vao danh sach canh (u v):");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    if (isCyclic(n)) {
        printf("Do thi co chu trinh\n");
    } else {
        printf("Do thi khong co chu trinh\n");
    }
    return 0;
}
