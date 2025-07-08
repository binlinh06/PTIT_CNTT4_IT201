#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

Stack createStack(int capacity) {
    Stack s;
    s.data = (int*)malloc(sizeof(int) * capacity);
    if (s.data == NULL) {
        printf("Lỗi cấp phát bộ nhớ\n");
        exit(1);
    }
    s.top = -1;
    s.capacity = capacity;
    return s;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (s->top < s->capacity - 1) {
        s->top++;
        s->data[s->top] = value;
    }
}

int pop(Stack* s) {
    if (isEmpty(s)) return 0;
    int value = s->data[s->top];
    s->top--;
    return value;
}

int evaluatePostfix(char* expr) {
    int len = strlen(expr);
    Stack s = createStack(len);

    for (int i = 0; i < len; i++) {
        char c = expr[i];

        if (isdigit(c)) {
            push(&s, c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int right = pop(&s);
            int left = pop(&s);
            int result = 0;
            if (c == '+') result = left + right;
            if (c == '-') result = left - right;
            if (c == '*') result = left * right;
            if (c == '/') result = left / right;
            push(&s, result);
        }
    }

    int finalResult = pop(&s);
    free(s.data);
    return finalResult;
}

int main() {
    char expr[1000];
    printf("Nhập biểu thức hậu tố: ");
    fgets(expr, sizeof(expr), stdin);
    int len = strlen(expr);
    if (expr[len - 1] == '\n') expr[len - 1] = '\0';

    printf("Input:\n\"%s\"\n", expr);

    int result = evaluatePostfix(expr);
    printf("%d\n", result);

    return 0;
}
