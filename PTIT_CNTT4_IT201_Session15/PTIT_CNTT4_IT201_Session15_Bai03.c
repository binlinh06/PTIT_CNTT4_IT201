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
    printf("}\n\n");
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

int main() {
    Queue q = createQueue(5);

    // Kiểm tra hàng đợi trống ban đầu
    printQueue(&q);
    if (isEmpty(&q)) {
        printf("true\n\n");
    } else {
        printf("false\n\n");
    }

    // Thêm phần tử vào hàng đợi
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 5);

    // Kiểm tra lại
    printQueue(&q);
    if (isEmpty(&q)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    free(q.data);
    return 0;
}
