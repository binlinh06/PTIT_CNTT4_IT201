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

int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Ngăn xếp trống\n");
        return -1;
    }

    Node* temp = s->top;
    int value = temp->data;
    s->top = temp->next;
    free(temp);
    return value;
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

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);

    printStack(&s);

    int poppedValue = pop(&s);
    if (poppedValue != -1) {
        printf("Đã lấy phần tử: %d\n", poppedValue);
    }
    printStack(&s);

    while (pop(&s) != -1); // xóa hết

    printStack(&s);

    int test = pop(&s); // thử lấy nữa khi rỗng
    return 0;
}
