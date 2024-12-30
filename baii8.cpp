#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define V 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[V];
bool visited[V];
int distance[V];

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

void BFS(int start, int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    int queue[V], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = true;
    distance[start] = 0;
    while (front < rear) {
        int current = queue[front++];
        Node* temp = adjList[current];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                distance[adjVertex] = distance[current] + 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, edges, u, v, start;
    printf("Nhap vao so dinh: ");
    scanf("%d", &n);
    printf("Nhap vao so canh: ");
    scanf("%d", &edges);
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
        visited[i] = false;
    }
    printf("Nhap vao danh sach canh (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    printf("Nhap vao dinh nguon: ");
    scanf("%d", &start);
    BFS(start, n);
    printf("Khoang cach tu dinh %d:\n", start);
    for (int i = 0; i < n; i++) {
        if (distance[i] == INT_MAX) {
            printf("Khong the toi dinh %d\n", i);
        } else {
            printf("Khoang cach den dinh %d: %d\n", i, distance[i]);
        }
    }
    return 0;
}
