#include <stdio.h>
#include <stdlib.h>

// Cấu trúc node và hàng đợi
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Tạo node mới từ người dùng nhập
Node* createNode() {
    int value;
    printf("Nhập số nguyên để thêm vào queue: ");
    scanf("%d", &value);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Thêm phần tử vào hàng đợi
void enqueue(Queue* q) {
    Node* newNode = createNode();
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// In hàng đợi
void printQueue(Queue* q) {
    printf("queue = {\n");
    printf("front->");
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    if (q->rear)
        printf("rear->%d->NULL\n", q->rear->data);
    else
        printf("rear->NULL\n");
    printf("}\n\n");
}

// Xem phần tử đầu (có trả về giá trị)
int peekFrontValue(Queue* q) {
    if (q->front == NULL) {
        printf("empty queue\n\n");
        return -1;
    }
    return q->front->data;
}

// Chương trình chính
int main() {
    Queue q;
    q.front = NULL;
    q.rear = NULL;

    // Trường hợp hàng đợi trống
    printQueue(&q);
    peekFrontValue(&q);  // sẽ in "empty queue"

    // Thêm phần tử
    enqueue(&q); // nhập 1
    enqueue(&q); // nhập 2
    enqueue(&q); // nhập 5

    printQueue(&q);

    int frontVal = peekFrontValue(&q);
    if (frontVal != -1) {
        printf("Phần tử đầu hàng đợi là: %d\n", frontVal);
    }

    return 0;
}
