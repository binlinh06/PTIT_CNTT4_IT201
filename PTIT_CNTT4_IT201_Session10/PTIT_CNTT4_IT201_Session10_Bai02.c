#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printArrowList(Node* head) {
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void printEachData(Node* head) {
    while (head != NULL) {
        printf("data: %d\n", head->data);
        head = head->next;
    }
}

int main() {
    Node* head = createNode(5);
    head->next = createNode(4);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    printArrowList(head);
    printEachData(head);

    return 0;
}
