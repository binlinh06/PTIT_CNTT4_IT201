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
    if (isFull(s)) return;
    s->top++;
    s->data[s->top] = value;
}

int pop(Stack* s) {
    if (isEmpty(s)) return -1;
    int value = s->data[s->top];
    s->top--;
    return value;
}

void reverseArray(int* arr, int n) {
    Stack s = createStack(n);
    for (int i = 0; i < n; i++) {
        push(&s, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = pop(&s);
    }
    free(s.data);
}

void printArray(int* arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int n;
    printf("Nhập số phần tử: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(sizeof(int) * n);
    if (arr == NULL) {
        printf("Lỗi cấp phát bộ nhớ mảng\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhập phần tử thứ %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Mảng ban đầu:\n");
    printArray(arr, n);

    reverseArray(arr, n);

    printf("Mảng sau khi đảo:\n");
    printArray(arr, n);

    free(arr);
    return 0;
}
