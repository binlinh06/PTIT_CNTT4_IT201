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

void deleteLast(Node** headRef) {
    if (*headRef == NULL) return;

    if ((*headRef)->next == NULL) {
        free(*headRef);
        *headRef = NULL;
        return;
    }

    Node* current = *headRef;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

int main() {
    Node* head = createNode(5);
    head->next = createNode(4);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    printList(head);
    deleteLast(&head);
    printList(head);

    return 0;
}
