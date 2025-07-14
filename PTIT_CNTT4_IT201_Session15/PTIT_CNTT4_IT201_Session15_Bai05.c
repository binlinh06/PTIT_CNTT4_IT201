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
    for (int i = 0; i <= q->rear; i++) {
        printf("%d", q->data[i]);
        if (i < q->rear) printf(", ");
    }
    printf("],\n");
    printf("   front = %d,\n", q->front);
    printf("   rear = %d,\n", q->rear);
    printf("   capacity = %d\n", q->capacity);
    printf("}\n\n");
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("queue is empty\n\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front++;
    return value;
}

int main() {
    Queue q = createQueue(5);

    // Trường hợp 1: hàng đợi trống
    printQueueStruct(&q);
    int result1 = dequeue(&q);  // sẽ in "queue is empty"

    // Trường hợp 2: thêm phần tử và lấy ra
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 5);

    printQueueStruct(&q);
    int value = dequeue(&q);
    if (value != -1) {
        printf("return value = %d;\n\n", value);
    }
    printQueueStruct(&q);

    free(q.data);
    return 0;
}
