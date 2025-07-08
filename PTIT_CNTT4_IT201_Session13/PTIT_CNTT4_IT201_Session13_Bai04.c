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

void push(Stack* s, int value) {
    if (isFull(s)) {
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

void viewAll(Stack* s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->data[i]);
    }
}

int main() {
    Stack s = createStack(5);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);

    printStackDetails(&s);
    viewAll(&s);

    free(s.data);
    return 0;
}
