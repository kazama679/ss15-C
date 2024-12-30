#include <stdio.h>
#include <stdbool.h>
#define V 100

int adjMatrix[V][V];
bool visited[V];

void DFS(int vertex, int n) {
    visited[vertex] = true;
    for (int i = 0; i < n; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i, n);
        }
    }
}

bool isConnected(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    DFS(0, n);
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
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
        visited[i] = false;
    }
    printf("Nhap vao ma tran ke (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    if (isConnected(n)) {
        printf("Do thi lien thong\n");
    } else {
        printf("Do thi khong lien thong\n");
    }
    return 0;
}
