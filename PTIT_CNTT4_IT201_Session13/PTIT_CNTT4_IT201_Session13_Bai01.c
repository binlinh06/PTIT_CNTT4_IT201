#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

Stack createStack(int maxSize) {
    Stack s;
    s.data = (int*)malloc(sizeof(int) * maxSize);
    if (s.data == NULL) {
        printf("Lỗi cấp phát bộ nhớ!\n");
        exit(1);
    }
    s.top = -1;
    s.capacity = maxSize;
    return s;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == s->capacity - 1;
}

void printStack(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack rỗng\n");
        return;
    }
    printf("Stack từ đáy đến đỉnh: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    Stack s = createStack(5);
    printStack(&s);
    free(s.data);
    return 0;
}
