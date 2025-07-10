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

void push(Stack* s, int value) {
    Node* newNode = createNode(value);
    newNode->next = s->top;
    s->top = newNode;
}

int main() {
    Stack s = createStack();

    printStack(&s);

    int value;

    printf("Nhập số nguyên dương: ");
    scanf("%d", &value);

    push(&s, value);

    printStack(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);

    printStack(&s);

    return 0;
}
