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

// Hàm tạo node từ người dùng
Node* createNode() {
    int value;
    printf("Nhập số nguyên để thêm vào queue: ");
    scanf("%d", &value);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm vào queue
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
    printf("NULL\n");

    if (q->rear)
        printf("  rear->%d->NULL\n", q->rear->data);
    else
        printf("  rear->NULL\n");
    printf("}\n\n");
}

// Hàm lấy phần tử ra khỏi queue
void dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("queue is empty\n\n");
        return;
    }

    Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

// Main
int main() {
    Queue q;
    q.front = NULL;
    q.rear = NULL;

    // Trường hợp 1: queue trống
    printQueue(&q);
    dequeue(&q); // in "queue is empty"

    // Thêm phần tử
    enqueue(&q); // nhập 1
    enqueue(&q); // nhập 2
    enqueue(&q); // nhập 5
    printQueue(&q);

    // Xoá 1 phần tử
    dequeue(&q);
    printQueue(&q);

    return 0;
}
