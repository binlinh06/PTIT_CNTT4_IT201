#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int front;
    int rear;
    int capacity;
} Queue;

Queue createQueue(int capacity) {
    Queue q;
    q.data = (int*)malloc(sizeof(int) * capacity);
    if (q.data == NULL) {
        printf("Lỗi cấp phát bộ nhớ!\n");
        exit(1);
    }
    q.front = 0;
    q.rear = -1;
    q.capacity = capacity;
    return q;
}

void enqueue(Queue* q, int value) {
    if (q->rear == q->capacity - 1) {
        printf("queue is full\n\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = value;
}

int isEmpty(Queue* q) {
    return q->rear < q->front;
}

void printQueueStruct(Queue* q) {
    printf("queue = {\n");
    printf("   array = [");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d", q->data[i]);
        if (i < q->rear) printf(", ");
    }
    printf("],\n");
    printf("   front = %d,\n", q->front);
    printf("   rear = %d,\n", q->rear);
    printf("   capacity = %d\n", q->capacity);
    printf("}\n\n");
}

void printElements(Queue* q) {
    if (isEmpty(q)) {
        printf("queue is empty\n\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n\n");
}

int main() {
    Queue q = createQueue(5);

    // Trường hợp 1: hàng đợi rỗng
    printQueueStruct(&q);
    printElements(&q);  // in thông báo rỗng

    // Trường hợp 2: có phần tử
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 5);

    printQueueStruct(&q);
    printElements(&q);  // in phần tử FIFO

    free(q.data);
    return 0;
}
