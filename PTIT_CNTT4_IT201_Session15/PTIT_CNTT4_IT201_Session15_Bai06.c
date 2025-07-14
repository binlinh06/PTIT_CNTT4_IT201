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
    q.front = 0;
    q.rear = -1;
    q.capacity = capacity;
    return q;
}

void enqueue(Queue* q, int value) {
    if (q->rear == q->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = value;
}

int dequeue(Queue* q) {
    if (q->front > q->rear) {
        return -1; // Queue empty
    }
    int val = q->data[q->front];
    q->front++;
    return val;
}

int isIncreasingByOne(Queue* q) {
    while (q->front < q->rear) {
        int current = dequeue(q);
        int next = q->data[q->front]; // xem phần tử tiếp theo
        if (next != current + 1) {
            return 0; // False
        }
    }
    return 1; // True
}

int main() {
    int n;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);

    Queue q = createQueue(n);

    printf("Nhập %d số nguyên dương:\n", n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(&q, val);
    }

    if (isIncreasingByOne(&q)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    free(q.data);
    return 0;
}
