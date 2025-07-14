#include <stdio.h>
#include <stdlib.h>

// Cấu trúc phần tử trong DSLK
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Cấu trúc hàng đợi
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Hàm khởi tạo hàng đợi rỗng
Queue createQueue() {
    Queue q;
    q.front = NULL;
    q.rear = NULL;
    return q;
}

// Hàm in hàng đợi (nếu có)
void printQueue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty (front = NULL, rear = NULL)\n");
        return;
    }

    Node* temp = q->front;
    printf("Queue = ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Chương trình chính
int main() {
    Queue myQueue = createQueue();
    printQueue(&myQueue);  // In hàng đợi rỗng

    return 0;
}
