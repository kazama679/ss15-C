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

typedef struct Queue {
    int items[V];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == V - 1) {
        printf("Hang doi day!\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

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

void BFS(int startVertex) {
    Queue* q = createQueue();
    visited[startVertex] = true;
    enqueue(q, startVertex);

    printf("Thu tu duyet BFS: ");
    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        Node* temp = adjList[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
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
    printf("Nhap vao dinh bat dau duyet: ");
    scanf("%d", &start);
    BFS(start);
    return 0;
}
