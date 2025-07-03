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

void printList(Node* head) {
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void append(Node** headRef, int data) {
    Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    Node* current = *headRef;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

int main() {
    Node* head = createNode(5);
    append(&head, 4);
    append(&head, 3);
    append(&head, 2);
    append(&head, 1);

    printList(head);

    int x;
    printf("\n");
    scanf("%d", &x);
    append(&head, x);

    printList(head);

    return 0;
}
