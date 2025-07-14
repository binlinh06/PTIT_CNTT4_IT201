#include <stdio.h>
#include <stdlib.h>

// Cấu trúc node và queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Hàm tạo node từ input
Node* createNode() {
    int value;
    printf("Nhập số nguyên để thêm vào queue: ");
    scanf("%d", &value);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Hàm enqueue
void enqueue(Queue* q) {
    Node* newNode = createNode();

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Hàm in queue
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

// Hàm xem phần tử đầu
void peekFront(Queue* q) {
    if (q->front == NULL) {
        printf("queue is empty\n\n");
    } else {
        printf("Front element: %d\n\n", q->front->data);
    }
}

// Main
int main() {
    Queue q;
    q.front = NULL;
    q.rear = NULL;

    // Trường hợp 1: Hàng đợi rỗng
    printQueue(&q);
    peekFront(&q);

    // Trường hợp 2: Có phần tử
    enqueue(&q);  // Nhập 1
    enqueue(&q);  // Nhập 2
    enqueue(&q);  // Nhập 5
    printQueue(&q);
    peekFront(&q);  // In phần tử đầu

    return 0;
}
