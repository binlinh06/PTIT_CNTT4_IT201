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
    if (s->top == NULL) {
        printf("Stack rỗng\n");
        return;
    }
    printf("Stack từ đỉnh xuống đáy: ");
    Node* temp = s->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack myStack = createStack();
    printStack(&myStack);
    return 0;
}
