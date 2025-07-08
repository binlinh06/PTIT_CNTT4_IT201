#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* data;
    int top;
    int capacity;
} Stack;

Stack createStack(int maxSize) {
    Stack s;
    s.data = (char*)malloc(sizeof(char) * maxSize);
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

void push(Stack* s, char c) {
    if (s->top < s->capacity - 1) {
        s->top++;
        s->data[s->top] = c;
    }
}

char pop(Stack* s) {
    if (isEmpty(s)) return '\0';
    char c = s->data[s->top];
    s->top--;
    return c;
}

char peek(Stack* s) {
    if (isEmpty(s)) return '\0';
    return s->data[s->top];
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int isValidBrackets(char* expr) {
    int len = strlen(expr);
    Stack s = createStack(len);

    for (int i = 0; i < len; i++) {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&s, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(&s) || !isMatching(peek(&s), c)) {
                free(s.data);
                return 0;
            }
            pop(&s);
        }
    }

    int valid = isEmpty(&s);
    free(s.data);
    return valid;
}

int main() {
    char expr[1000];
    printf("Nhập biểu thức: ");
    fgets(expr, sizeof(expr), stdin);
    int len = strlen(expr);
    if (expr[len - 1] == '\n') expr[len - 1] = '\0';

    printf("Input:\n\"%s\"\n", expr);

    if (isValidBrackets(expr)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
