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

void printRawStack(Stack* s) {
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

void traverseStack(Stack* s) {
    if (s->top == NULL) {
        printf("Ngăn xếp trống\n");
        return;
    }

    Node* temp = s->top;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    Stack s = createStack();

    printRawStack(&s);

    int value;
    printf("Nhập số nguyên dương: ");
    scanf("%d", &value);

    push(&s, value);

    traverseStack(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);

    printRawStack(&s);

    traverseStack(&s);

    return 0;
}
