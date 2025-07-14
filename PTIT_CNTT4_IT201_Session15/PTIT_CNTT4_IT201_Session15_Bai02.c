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

void printQueue(Queue* q) {
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
    printf("},\n\n");
}

void enqueue(Queue* q, int value) {
    if (q->rear == q->capacity - 1) {
        printf("queue is full\n\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = value;
}

int main() {
    int cap;
    printf("Nhập sức chứa hàng đợi: ");
    scanf("%d", &cap);

    Queue q = createQueue(cap);
    printQueue(&q);

    int value;
    for (int i = 0; i < 5; i++) {
        printf("Nhập số nguyên để thêm vào queue: ");
        scanf("%d", &value);
        enqueue(&q, value);
        printQueue(&q);
    }

    free(q.data);
    return 0;
}
