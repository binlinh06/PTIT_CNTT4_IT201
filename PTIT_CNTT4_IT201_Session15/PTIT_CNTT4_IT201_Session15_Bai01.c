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
    printf("Queue = {\n");
    printf("  front: %d\n", q->front);
    printf("  rear: %d\n", q->rear);
    printf("  data: [");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d", q->data[i]);
        if (i < q->rear) printf(", ");
    }
    printf("]\n}\n");
}

int main() {
    int size;
    printf("Nhập sức chứa hàng đợi: ");
    scanf("%d", &size);

    Queue myQueue = createQueue(size);

    printQueue(&myQueue);

    free(myQueue.data);
    return 0;
}
