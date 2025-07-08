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

int isFull(Stack* s) {
    return s->top == s->capacity - 1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack đầy, không thể thêm %d\n", value);
        return;
    }
    s->top++;
    s->data[s->top] = value;
}

void printStackDetails(Stack* s) {
    printf("stack={\n");
    printf("    elements: [");
    for (int i = 0; i <= s->top; i++) {
        printf("%d", s->data[i]);
        if (i < s->top) printf(", ");
    }
    printf("],\n");
    printf("    top: %d,\n", s->top);
    printf("    cap: %d\n", s->capacity);
    printf("}\n");
}

int main() {
    Stack s = createStack(5);
    int value;

    printf("Nhập các phần tử:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &value);
        push(&s, value);
    }

    printStackDetails(&s);
    free(s.data);
    return 0;
}
