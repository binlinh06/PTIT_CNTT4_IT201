#include <stdio.h>
#include <stdlib.h>

// Node và Queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Tạo node từ input
Node* createNode() {
    int value;
    printf("Nhập số nguyên để thêm vào queue: ");
    scanf("%d", &value);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Thêm node vào queue
void enqueue(Queue* q) {
    Node* newNode = createNode();

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// In queue
void printQueue(Queue* q) {
    printf("queue = {\n");

    printf("  front->");
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL,\n");

    if (q->rear)
        printf("  rear->%d->NULL\n", q->rear->data);
    else
        printf("  rear->NULL\n");

    printf("},\n\n");
}

// Main
int main() {
    Queue q;
    q.front = NULL;
    q.rear = NULL;

    printQueue(&q);  // ban đầu trống

    // Thêm 1 phần tử
    enqueue(&q);
    printQueue(&q);

    // Thêm nhiều phần tử
    enqueue(&q);
    enqueue(&q);
    enqueue(&q);
    printQueue(&q);

    return 0;
}
