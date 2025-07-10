#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Stack createStack() {
    Stack s;
    s.top = NULL;
    return s;
}

void push(Stack* s, int value) {
    Node* newNode = createNode(value);
    newNode->next = s->top;
    s->top = newNode;
}

int peek(Stack* s) {
    if (s->top == NULL) {
        printf("Ngăn xếp trống\n");
        return -1;
    }
    return s->top->data;
}

void printStack(Stack* s) {
    printf("stack = {\n   ");
    Node* temp = s->top;
    if (temp == NULL) {
        printf("NULL\n");
    } else {
        while (temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    printf("}\n\n");
}

int main() {
    Stack s = createStack();

    // Trường hợp stack rỗng
    printStack(&s);
    int topValue = peek(&s);
    if (topValue != -1) {
        printf("%d\n", topValue);
    }

    // Thêm dữ liệu vào stack
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);

    printStack(&s);

    // Xem phần tử đầu
    int result = peek(&s);
    if (result != -1) {
        printf("%d\n", result);
    }

    return 0;
}
