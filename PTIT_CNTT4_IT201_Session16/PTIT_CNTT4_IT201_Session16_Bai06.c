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

// Tạo node từ input người dùng
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

// Hàm in cấu trúc hàng đợi
void printQueueStructure(Queue* q) {
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

// Hàm xem toàn bộ phần tử
void viewQueue(Queue* q) {
    if (q->front == NULL) {
        printf("queue is empty\n\n");
        return;
    }

    Node* temp = q->front;
    printf("Các phần tử trong queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

// Main
int main() {
    Queue q;
    q.front = NULL;
    q.rear = NULL;

    // Trường hợp queue rỗng
    printQueueStructure(&q);
    viewQueue(&q);

    // Thêm phần tử vào hàng đợi
    enqueue(&q); 
    enqueue(&q);
    enqueue(&q);

    printQueueStructure(&q);
    viewQueue(&q);

    return 0;
}
