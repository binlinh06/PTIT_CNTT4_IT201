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

int isFull(Stack* s) {
    return s->top == s->capacity - 1;
}

void push(Stack* s, char value) {
    if (isFull(s)) return;
    s->top++;
    s->data[s->top] = value;
}

char pop(Stack* s) {
    if (isEmpty(s)) return '\0';
    char value = s->data[s->top];
    s->top--;
    return value;
}

int isPalindrome(char* str) {
    int len = strlen(str);
    Stack s = createStack(len);

    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&s)) {
            free(s.data);
            return 0;
        }
    }

    free(s.data);
    return 1;
}

int main() {
    char input[1000];
    printf("Nhập chuỗi: ");
    fgets(input, sizeof(input), stdin);

    int len = strlen(input);
    if (input[len - 1] == '\n') input[len - 1] = '\0';

    printf("Input:\n\"%s\"\n", input);

    if (isPalindrome(input)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
